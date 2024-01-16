from request_auth import RequestAuth
from users import User


class Session:
    def __init__(self, user, req_auth: RequestAuth):
        self.user: User = user
        self.req_auth = req_auth


class Sessions:

    def __init__(self):
        self.sessions: dict[str: Session] = {}


    def add(self, user: User, requestAuth: RequestAuth = None):
        req_auth = RequestAuth() if requestAuth is None else requestAuth
        self.sessions[req_auth.authKey] = Session(user, req_auth)
        return req_auth.authKey

    def check_auth(self, authKey: str):
        '''

        :param authKey: The auth key as a string that was passed in by the auth header
        :precondition: None
        :postcondition: If expired, auth is attempted but expired, it will pop off session
        :return: true if authorized, false otherwise
        '''
        # If auth key is not set, is set but not in sessions
        if authKey is None or authKey not in self.sessions:
            return False

        # Check if ttl is expired
        if self.sessions[authKey].req_auth.is_expired():
            self.sessions.pop(authKey)
            return False

        # renew expiration date
        self.sessions[authKey].req_auth.renew()
        return True
