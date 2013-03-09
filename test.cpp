/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  test file
 *
 *        Version:  1.0
 *        Created:  03/03/2012 12:44:27
 *       Revision:  none
 *       Compiler:  g++
 *
 * =====================================================================================
 */

#include"trie.h"
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;

int main (int argc, char* argv[]) {
    string filename = "dictionary.txt";
    vector<string> diccionary;
    Trie tree;

    diccionary = load_key_words_file(filename);
    for (int i =0 ;i<diccionary.size();i++)
        tree.addWord(diccionary[i]);

    FILE *f;
    string line;
    string text;
    ifstream myfile ("doc.txt");
    while ( myfile.good() )
    {
        getline (myfile,line);
        text.append(line);
    }
    myfile.close();

    tree.searchWordsInText(text);

}
