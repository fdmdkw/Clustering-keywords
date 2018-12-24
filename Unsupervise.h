#ifndef UNSUPERVISE_H
#define UNSUPERVISE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define FILES 1001  // define files range 1~1000
#define ROUND 100
typedef enum _class_{
    Others, A, B, C, D
}Class;

typedef struct _term_dic_{
    std::map<int, int> file_list;
    int freq = 0;
    int Class = Others;
}Term_dic;

typedef struct _file_dic_{
    std::map<std::string, Term_dic> term_dic;
    int total_freq = 0;
    int file_Class;
}File_dic;

typedef struct _means_{
    std::vector<float> vec;
    int Class;
    int number = 0;
}Means;

extern std::map<std::string, Term_dic> term_dic;
extern std::vector<std::vector<std::string>> class_dic;
extern std::vector<File_dic> file_dic;
extern std::vector<Means> means;
extern int TERMS;
extern Means meansA;
extern Means meansB;
extern Means meansC;
extern Means meansD;

void Create_Dic();
void print_file_dic();
void print_term_dic();
void sort_dic();
void k_mean();
long long dist(int Class, Means &meansClass, Means &means);
void classify();
#endif