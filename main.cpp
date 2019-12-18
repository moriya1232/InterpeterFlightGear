#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
vector<string> lexer (string str);
int main(int argc,char* argv[]) {
    vector<string> data = lexer(argv[1]);
    return 0;
}
vector<string> lexer (string filename) {//123
    ifstream fp;
    string str;
    vector<string> arr;
    fp.open(filename);
    if (fp.fail()) {
        throw("file not open");
    }
    while(getline(fp,str)) {
        int found = 0;
        int last = 0;
        int i=0;
        int j=0;
        string temp;

        found = str.find_first_of(" (),=\t", found);

        while (found >= 0) {
            temp = str.substr(last, found - last);
            if (found != last) {
                arr.push_back(temp);
            }
            if((found!=-1)&&(str.at(found)=='=')) {
                if((str.at(found-1)=='<')||(str.at(found-1)=='>')) {
                    arr.pop_back();
                    arr.push_back(str.substr(found-1,2));
                    found = str.find_first_of(" (),=\t", found);
                }
                else {
                    j = str.length() - found;
                    arr.push_back(str.substr(found + 2, j));
                    found = (str.length()) - 1;
                }
            }
            if((found!=-1)&&(str.at(found)=='(')) {
                i=str.find_first_of(")");
                /*if((found<str.length())&&((str.at(found+1)=='/')||(str.at(found+1)=='*')
                ||(str.at(found+1)=='+')||(str.at(found+1)=='-'))) {
                    arr.push_back(str.substr(found+1))
                }*/
                i=i-found;
                arr.push_back(str.substr(found+1,i-1));
                found=str.find_first_of(")", found+1);
            }
            last = found + 1;
            found++;
            found = str.find_first_of(" (),=", found);

        }
        if(last!=str.length()) {
            arr.push_back(str.substr(last,str.length()));
        }
    }
    fp.close();
}
