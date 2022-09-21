#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool next=true;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            next=true;
        }
        else{
            if(next){
                if(s[i]>='a')
                    s[i]-=('a'-'A');
            next=false;
            }
            else{
                if(s[i]<'a'){
                    s[i]+=('a'-'A');
                }
            }
        }
    }
    answer=s;
    return answer;
}