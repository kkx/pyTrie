/*
 * =====================================================================================
 *
 *       Filename:  trie.h
 *
 *    Description:  trie functions declarations
 *
 *        Version:  1.0
 *        Created:  03/03/2012 12:36:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *
 * =====================================================================================
 */
#ifndef _TRIE_H_
#define _TRIE_H_
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>


using namespace std;
vector<string> load_key_words_file(string filename);

class Node {
     private:
        unsigned char mContent;
        bool folder;
        map<unsigned char,Node*> mChildren;

    public:
        Node() {
            folder = false;
        }
        ~Node(){
            map < unsigned char, Node* >::iterator it;
            for ( it = mChildren.begin() ; it != mChildren.end() ; it++ ) {
               delete((*it).second);
            }
        }
        unsigned char getContent() {
            return mContent;
        }
        void setContent(unsigned char c) {
            mContent = c;
        }
        bool isFolder() {
            return folder;
        }
        void setFolder() {
            folder = true;
        }

        Node* findChild(unsigned char c)
        {
            map <unsigned char,Node*> ::iterator it = mChildren.find(c);
            if (it!=mChildren.end()){
                return (*it).second;
            }
            else{
                return NULL;
            }
        }


        void addChild(Node* child) {
            mChildren.insert(pair<unsigned char,Node*>(child->mContent, child));
        }

        map <unsigned char ,Node*> children() {
            return mChildren;
        }

};

class Trie {
    public:
        Trie();
        ~Trie();
        void addWord(string s);
        bool searchWord(string s);
        //void deleteWord(string s); //not implemented
        unsigned int searchPrefix(const string& s, unsigned int init_pos);
        vector< pair<unsigned int, unsigned int> >searchWordsInText(const string&  text);
    private:
        Node* root;
};


vector<string> load_key_words_file(string filename)
{
    FILE *f;
    string line;
    vector<string> diccionary;
    ifstream myfile (filename.c_str());


    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            diccionary.push_back(line);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
        diccionary.resize(0);
        return diccionary;
    }
    //for (vector<string>::iterator it = diccionary.begin(); it!=diccionary.end(); ++it)
    //cout<<*it<<endl;
    return diccionary;
}


Trie::Trie()
{
        root = new Node();
}

Trie::~Trie()
{
        delete(root);
}

void Trie::addWord(string s)
{
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setFolder(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->addChild(tmp);
            current = tmp;
        }
        if ( i == s.length() -1)
            current->setFolder();
    }

}
unsigned int Trie::searchPrefix(const string& s, unsigned int init_pos)
{
    Node* current = root;
    unsigned int fin_pos = init_pos;
    for ( int i = init_pos; i < s.length(); i++ )
    {
        Node* tmp = current->findChild(s[i]);
        if ( tmp == NULL )
            return fin_pos;
        current = tmp;
        if (current->isFolder()){
            fin_pos = i;
        }
    }

    return fin_pos;
}

bool Trie::searchWord(string s)
{
    Node* current = root;
    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current->isFolder())
            return true;
        else
            return false;
    }
    return false;
}
vector< pair<unsigned int, unsigned int> > Trie::searchWordsInText(const string&  text){
    unsigned int f ;
    vector <pair<unsigned int, unsigned int> > matched_words_positions;
    for (int i = 0;i<text.length();){
        f=searchPrefix(text, i);
        if (i!=f){
            cout<<i<<" "<<f<<" "<<text.substr(i,f-i+1)<<endl;
            i = f+1;
        }
        else
            i++;
    }
    return matched_words_positions;
}
#endif
