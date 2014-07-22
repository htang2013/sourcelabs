class Rabbit(object):
     
    def __init__(self, name):
        self._name = name
     
    @staticmethod
    def newRabbit(name):
        return Rabbit(name)
     
    @classmethod
    def newRabbit2(cls):
        return Rabbit('')
     
    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self,name):
        self._name = name


r = Rabbit("rib")

print r.newRabbit("tu").name
print r.name

