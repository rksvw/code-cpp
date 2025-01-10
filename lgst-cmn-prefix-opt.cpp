#include<iostream>
#include<string>
#include<vector>
using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        string f_str = strs[0];
        int n=strs.size();
        // string perstr;

        for(int i=1; i<n; i++){
            int f_str_l=f_str.length();
            string c_str = strs[i];
            int c_str_l=strs[i].length();
            if(f_str_l>c_str_l){
                f_str = f_str.substr(0,c_str_l);
            }
            else if(c_str_l>f_str_l){
                c_str = c_str.substr(0,f_str_l);
            }
            while(c_str != f_str && c_str.length() == f_str.length()){
                c_str.pop_back();
                f_str.pop_back();
            }

            if (f_str.empty()) {
                return "";
            }
        }
        return f_str;
    }

int main() {
    vector<string> str = {"flower", "flow", "flight"};

    // cout << str[1].size() << endl;
    cout << longestCommonPrefix(str) << endl;
    return 0;
}