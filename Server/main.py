from flask import Flask, make_response, jsonify, request
from users import Users, User
from request_auth import RequestAuth
from datetime import datetime

app = Flask(__name__)
adminUser = User('admin', 'password', 1, firstName='Sysadmin', lastName='Sysadmin')
app_users = Users()
sessions: dict[str: datetime] = {}
app_users.add_user(adminUser)

def auth_verification(authKey: str):
    # If auth key is not set, is set but not in sessions, or is set and in sessions but ttl is expired
    if authKey is None or authKey not in sessions or int(sessions[authKey].timestamp()) < int(datetime.now().timestamp()):
        return False
    # renew expiration date
    new_exp = RequestAuth.renew_expiration()
    sessions[authKey] = new_exp
    return True

@app.route('/api/login', methods=['POST'])
def login():
    status = 404
    if request.is_json:
        json_data = request.get_json()
        username = json_data.get('username')
        password = json_data.get('password')
        matched_user = app_users.check_login(username, password)
        response_content = jsonify({'error': 'user not found'})
        if matched_user is not None:
            # Make session
            request_sesh = RequestAuth()
            sessions[request_sesh.authKey] = request_sesh.expiration
            # End Make session
            response_content = matched_user.to_json(request_sesh.authKey)
            status = 200
        response = make_response(response_content, status)
        response.headers['Content-Type'] = 'application/json'
        return response
    return 'error', 500

@app.route('/api/test', methods=['GET'])
def test():
    print('Started')
    if 'auth' not in request.headers:
        return 'Invalid Session', 500
    token = request.headers['auth']
    if not auth_verification(token):
        return 'Not Authorized', 401
    return 'Ok', 200

if __name__ == '__main__':
    app.run(debug=True)
