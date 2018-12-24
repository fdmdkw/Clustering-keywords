#include "Unsupervise.h"
using namespace std;

int main()
{
    Create_Dic();
    TERMS = term_dic.size() - 1;
    k_mean();
    classify();
    //print_file_dic();
    //print_term_dic();
    char c;
    cin >> c;
    return 0;
}