#coding:utf-8

import trieClasses

t=trieClasses.Trie()
f = open("./dictionary.txt","r")
words = f.readlines()

for w in words:
    #t.addWord(w.split()[0].rstrip(u'市'))
    t.addWord(w.split()[0].decode('utf8').rstrip(u'市省').encode('utf8'))

f.close()


f = open("./doc.txt","r")
data = f.read()
y = "东区"
print t.searchPrefix(y,0)
print t.searchWord(y)
d= t.searchWordsInText(data)

for i in d:
    print i
