#include "Create_Dic.h"
#include <fstream>
#include <algorithm>
#include <math.h>
#include <float.h>
using namespace std;
const string File_folder("./training/training文件/");
const string File_class_folder("./training/training文件種類/");

map<string, Term_dic> term_dic;
vector<vector<string>> class_dic(5);
vector<File_dic> file_dic(FILES);

void Create_Dic(bool supervise)
{
    for(int files = 1; files < FILES; files++){
        const string file_name = File_folder + to_string(files) + ".txt";
        const string file_class_name = File_class_folder + to_string(files) + "a.txt";
        ifstream if_name(file_name, ifstream::in);
        //ifstream if_name(file_class_name, ifstream::in);
        string str;
        while(if_name >> str){
            if(str.compare(",") == 0)
                continue;
            // add term into term_dic
            auto it = term_dic.find(str);
            if(it != term_dic.end()){    // found the term
                it->second.freq++;
                if(it->second.file_list.find(files) != it->second.file_list.end()){  // the term has appeared in this time
                    it->second.file_list[files]++;
                }  
                else{   // the term apear first time in this file
                    it->second.file_list[files] = 1;
                }
            }
            else{
                Term_dic term;
                term.file_list[files] = 1;
                term.freq++;
                term_dic[str] = term;
            }
            // add term into file_dic
            file_dic[files].total_freq++;
            auto file_it = file_dic[files].term_dic.find(str);
            if(file_it != file_dic[files].term_dic.end()){ // found the term
                file_it->second.freq++;
            }
            else{
                Term_dic term;
                term.freq++;
                file_dic[files].term_dic[str] = term;
            }
        }
        if_name.close();
    }
}
void print_file_dic()
{
    for(int files = 1; files < FILES; files++){
        cout << "File: " << files << "\nTotal term numbers: " 
        << file_dic[files].total_freq << "\nClass: " << file_dic[files].file_Class << endl;

        auto it = file_dic[files].term_dic;
        for(auto terms = it.begin(); terms != it.end(); terms++){
            cout << "Term: " << terms->first << "\nTerm freq: " << terms->second.freq
            << "  Term class: " << terms->second.Class << endl;
        }
    }
}
void print_term_dic()
{
    for(auto terms = term_dic.begin(); terms != term_dic.end(); terms++){
        cout << "Term: " << terms->first << "\nTerm freq: " << terms->second.freq
            << "  Term class: " << terms->second.Class << endl;
        auto list_it = terms->second.file_list;
        for(auto it = list_it.begin(); it != list_it.end(); it++){
            cout << "File: " << it->first << "  Total term freq: " << it->second << endl;
        }
    }
}
void sort_dic()
{

}
void k_mean()
{
    const int TERMS = term_dic.size();
    //cout << D << endl;
    vector<Means> means(FILES);
    for(int i = 1; i < FILES; i++){
        for(auto it = term_dic.begin(); it != term_dic.end(); it++){
            if(file_dic[i].term_dic.find(it->first) != file_dic[i].term_dic.end()){  // found the term
                float term_freq = file_dic[i].term_dic[it->first].freq;
                means[i].vec.push_back(term_freq);
            }
            else{
                means[i].vec.push_back(0);
            }
        }
    }
    // test means
    /*for(int i = 1; i < FILES; i++){
        int count = 0;
        for(int j = 0; j < TERMS; j++){
            count += means[i].vec[j];
        }
        if(count != file_dic[i].total_freq)
            cout << "File" << i << endl;
    }*/
    Means meansA = means[1];
    Means meansB = means[2];
    Means meansC = means[3];
    Means meansD = means[4];
    
    double Min = DBL_MAX;
    for(int round; round < ROUND; round++){
        for(int i = 1; i < FILES; i++){
            double a = 0;
            double b = 0;
            double c = 0;
            double d = 0;
            
            int Class = A;
            double min = dist(TERMS, A, &meansA, &means);
            Class = dist(TERMS, B, &meansB, &means) < min ? B : Class;
            Class = dist(TERMS, C, &meansC, &means) < min ? C : Class;
            Class = dist(TERMS, D, &meansD, &means) < min ? D : Class;
        }
    }
}
double dist(int terms, int Class, vector<Means> &meansClass, vector<Means> &means)
{
    for(int j = 1; j < FILES; j++){
        for(int i = 0; i < terms; i++){
            means[i].
        }
    }
}