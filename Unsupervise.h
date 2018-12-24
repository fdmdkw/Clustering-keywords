#ifndef UNSUPERVISE_H
#define UNSUPERVISE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define ROUND 1
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
extern int FILES;  // define files range, default as 1001(index 1~1000)

const std::string Train_folder("./training/training文件/");
const std::string Train_class_folder("./training/training文件種類/");
const std::string Train_classify_folder("./training/unsupervise_classify/");
const std::string Test_folder("./training/training文件/");
const std::string Test_classify_folder("./training/test_classify/");

void create_dic(bool test_file);  // true -> create dictionary of test files, false -> training files
void create_means();
void print_file_dic();
void print_term_dic();
//void sort_dic();
void k_mean();
long long dist(int Class, Means &meansClass, Means &means);
void classify(bool test_file);  // true -> classify model using test files, false -> classify model using training files
#endif