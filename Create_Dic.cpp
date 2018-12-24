#include "Create_Dic.h"
#include <fstream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;
const string File_folder("./training/training文件/");
const string File_class_folder("./training/training文件種類/");
const string File_classify_folder("./training/unsupervise_classify/");

map<string, Term_dic> term_dic;
vector<vector<string>> class_dic(5);
vector<File_dic> file_dic(FILES);
vector<Means> means(FILES);
int TERMS;
Means meansA;
Means meansB;
Means meansC;
Means meansD;

void Create_Dic()
{
    for(int files = 1; files < FILES; files++){
        const string file_name = File_folder + to_string(files) + ".txt";
        const string file_class_name = File_class_folder + to_string(files) + "a.txt";
        ifstream if_name(file_name, ifstream::in);
        ifstream if_class_name(file_class_name, ifstream::in);
        string str;
        int Class;
        while(if_name >> str){
            if_class_name >> Class;
            file_dic[files].file_Class = Class;
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
        if_class_name.close();
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
    //cout << D << endl;
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
    meansA = means[13];
    meansB = means[4];
    meansC = means[1];
    meansD = means[3];
    
    for(int round; round < ROUND; round++){
        for(int i = 1; i < FILES; i++){
            int Class = A;
            long long min = dist(A, meansA, means[i]);
            long long d = dist(B, meansB, means[i]);
            if(d < min){
                Class = B;
                min = d;
            }
            d = dist(C, meansC, means[i]);
            if(d < min){
                Class = C;
                min = d;
            }
            d = dist(D, meansD, means[i]);
            if(d < min){
                Class = D;
                min = d;
            }
            means[i].Class = Class;
        }
        for(int j = 0; j < TERMS; j++){
            meansA.vec[j] = 0;
            meansB.vec[j] = 0;
            meansC.vec[j] = 0;
            meansD.vec[j] = 0;
        }
        for(int i = 1; i < FILES; i++){
            for(int j = 0; j < TERMS; j++){
                if(means[i].Class == A){
                    meansA.vec[j] += means[i].vec[j];
                    meansA.number++;
                }
                if(means[i].Class == B){
                    meansB.vec[j] += means[i].vec[j];
                    meansB.number++;
                }
                if(means[i].Class == C){
                    meansC.vec[j] += means[i].vec[j];
                    meansC.number++;
                }
                if(means[i].Class == D){
                    meansD.vec[j] += means[i].vec[j];
                    meansD.number++;
                }
            }
        }
        for(int i = 0; i < TERMS; i++){
            meansA.vec[i] /= meansA.number;
            meansB.vec[i] /= meansB.number;
            meansC.vec[i] /= meansC.number;
            meansD.vec[i] /= meansD.number;
        }
    }
}
long long dist(int Class, Means &meansClass, Means &means)
{
    long long d = 0;
    for(int i = 0; i < TERMS; i++){
        d += (long long)pow(means.vec[i] - meansClass.vec[i], 2);
    }
    return d;
}
void classify()
{
    float correct = 0;
    for(int i = 1; i < FILES; i++){
        int Class = A;
        long long min = dist(A, meansA, means[i]);
        long long d = dist(B, meansB, means[i]);
        if(d < min){
            Class = B;
            min = d;
        }
        d = dist(C, meansC, means[i]);
        if(d < min){
            Class = C;
            min = d;
        }
        d = dist(D, meansD, means[i]);
        if(d < min){
            Class = D;
            min = d;
        }
        if(Class == file_dic[i].file_Class){
            correct++;

        }
        const string file_classify_name = File_classify_folder + to_string(i) + "b.txt";
        ofstream of_class_name(file_classify_name, ofstream::out);
        of_class_name << Class;
        of_class_name.close();
    }
    correct /= (FILES - 1);
    cout << "Correctness: " << correct << endl;
    const string file_classify_name = File_classify_folder + "correctness.txt";
    ofstream of_class_name(file_classify_name, ofstream::out);
    of_class_name << correct;
    of_class_name.close();
}