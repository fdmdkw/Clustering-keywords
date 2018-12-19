#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define FILES 1000
using namespace std;

enum CLASS{
    Others, A, B, C, D
};

typedef struct _term_dic_{
    vector<int> file_list;
    int freq;
    int Class = Others;
}Term_dic;

typedef struct _file_dic_{
    map<string, Term_dic> term_dic;
    int term_number;
    int file_Class;
}File_dic;

map<string, Term_dic> term_dic;
vector<vector<string>> class_dic(5);
vector<File_dic> file_dic(1000);

void parser(bool supervise); // true -> supervise, false -> unsupervise

#endif