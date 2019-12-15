#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main(int argc,char* argv[]) {

    ifstream fp ;
    fp.open(argv[1]);

    return 0;
}
vector<string> lexer (string str,vector<string> *arr) {
    using namespace std;
    vector<string> arr;
    int found = 0;
    int last = 0;
    string temp;

    found = str.find_first_of(" ()", found);
    while (found >=0) {
        temp = str.substr(last, found - last);
        if (found != last) {
            arr.push_back(temp);
        }
        arr.push_back(str.substr(found, 1));
        last = found + 1;
        found++;
        found = str.find_first_of("+-*()/", found);
    }
}
