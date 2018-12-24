#include "Unsupervise.h"
using namespace std;

int main()
{
    create_dic(false);
    TERMS = term_dic.size() - 1;
    k_mean();
    classify(false);
    // classify model using test files
    /*FILES = 101;
    create_dic(true);
    create_means();
    classify(true);*/
    //print_file_dic();
    //print_term_dic();
    char c;
    cin >> c;
    return 0;
}