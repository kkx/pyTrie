A c++ Trie implementation 'inspired' from this [blog](http://login2win.blogspot.com.es/2011/06/c-tries.html):

g++ -o test test.cpp trie.h

A boost+python binding example is shown here also. There are 3 files involved:

trieClasses.C, Makefile, testTrieClasses.py

In Makefile the python version should be ajusted properly.

make && python testTrieClasses.py

Chinese words(3 bytes) are treated byte to byte to accelerate the search speed.

doc.txt:  a test text

dictionary.txt: dictionary of word to be included in the Trie for future fast search
