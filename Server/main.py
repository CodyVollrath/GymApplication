from flask import Flask, make_response, jsonify, request
from users import Users, User
from request_auth import RequestAuth
from sessions import Sessions
from datetime import datetime

app = Flask(__name__)
adminUser = User('admin', 'password', 1, firstName='Sysadmin', lastName='Sysadmin', isAdmin=True)
app_users = Users()
sessions = Sessions()
app_users.add_user(adminUser)

def auth_verification(req):
    if 'auth' not in req.headers:
        return False
    authKey = req.headers['auth']
    return sessions.check_auth(authKey)

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
            authKey = sessions.add(matched_user)
            response_content = matched_user.to_json(authKey)
            status = 200
        response = make_response(response_content, status)
        response.headers['Content-Type'] = 'application/json'
        return response
    return 'error', 500

#Routes
@app.route('/api/createUser', methods=['POST'])
def create_user():
    status = 401
    if not request.is_json:
        return "Invalid Content Type", 500
    if not auth_verification(request):
        return "Not Authorized", 401

    json_data = request.get_json()
    confirm_password = json_data['confirmPassword']
    password = json_data['password']
    if confirm_password != password:
        return 'Passwords do not match', 200
    new_user = User(username=json_data['username'], password=json_data['password'], firstName=json_data['firstname'],
                    lastName=json_data['lastname'], employeeId=json_data['employeeId'], isAdmin=json_data['isAdmin'])
    did_Add = app_users.add_user(new_user)
    if not did_Add:
        return 'Username already exists', 200
    return 'No Content', 201


#Tes Routes
@app.route('/api/test', methods=['GET'])
def test():
    print('Started')
    if not auth_verification(request):
        return 'Not Authorized', 401
    return 'Ok', 200

if __name__ == '__main__':
    app.run(debug=True)