##
class MyList():
    def __init__(self):
        self._myList = []

    def __str__(self):
        s = ''
        for item in self._myList:
            s += str(item)
        return s

    def __iter__(self):
        for item in self._myList:
            yield item

    def add(self, rec):
        self._myList.append(rec)
##
class Record():
    def __init__(self, seq, label):
        self._seq = seq
        self._label = label

    def __str__(self):
        s = '%5d %s\n' % (self._seq, self._label)
        return s
##
myList = MyList()

for i in range(0, 5):
    rec = Record(i*10+1, 'dummy')
    myList.add(rec)

print(myList)

for item in myList:
    print(item)
    
