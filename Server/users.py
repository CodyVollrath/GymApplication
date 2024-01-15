import json
class User:
    def __init__(self, username, password, employeeId, firstName = None, lastName = None):
        self.username = username
        self.password = password
        self.firstName = firstName
        self.lastName = lastName
        self.employeeId = employeeId

    def to_json(self, auth = None):
        user_dict = dict(self.__dict__)
        user_dict.pop('password', None)
        if auth is not None:
            user_dict['authKey'] = auth
        return json.dumps(user_dict)

class Users:

    def __init__(self):
        self.users = []

    def add_user(self, user):
        if self.check_login(user.username, user.password) is None:
            self.users.append(user)

    def check_login(self, username, password):
        '''
        Gets the user information based on username and password
        :param username: the username for the user
        :param password: the password for the user
        :return: the user if user.username == username and user.password == password else None
        '''
        for user in self.users:
            if user.username == username and user.password == password:
                return user

        return None