import json
class User:
    def __init__(self, username, password, employeeId, firstName = None, lastName = None, isAdmin = False):
        self.username = username
        self.password = password
        self.firstName = firstName
        self.lastName = lastName
        self.employeeId = employeeId
        self.isAdmin = isAdmin

    def __hash__(self):
        return hash(self.employeeId)

    def to_json(self, auth = None):
        user_dict = dict(self.__dict__)
        user_dict.pop('password', None)
        if auth is not None:
            user_dict['authKey'] = auth
        return json.dumps(user_dict)

class Users:

    def __init__(self):
        self.users = set()

    def add_user(self, user) -> bool:
        isUsernameInUsers = user.username in set([curr_user.username for curr_user in self.users])
        if not isUsernameInUsers:
            self.users.add(user)
            return True
        return False

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