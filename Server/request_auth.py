import uuid
from datetime import datetime, timedelta
class RequestAuth:
    def __init__(self, authKey: str = None):
        # Auth key generated
        self.authKey = authKey if authKey is not None else str(uuid.uuid4())

        # Set expiration of key
        self.renew()

    def renew(self, t_delta_mins = 45):
        self.expiration = datetime.now() + timedelta(minutes=t_delta_mins)

    @staticmethod
    def renew_expiration(t_delta_mins = 45):
        return datetime.now() + timedelta(minutes=t_delta_mins)
    def is_expired(self):
        return datetime.now() >= self.expiration
    def __repr__(self):
        return self.authKey

    def __str__(self):
        return str((self.authKey, self.expiration))

    def __hash__(self):
        return hash(self.authKey)



