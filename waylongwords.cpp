#include <iostream>

using namespace std;
void waytomanylines(string s){
    int n = s.length();
    if(n<=10){
        cout << s << endl;
    }
    else{
        cout << s[0] << (n-2) <<s[n-1]<<endl;
    }
}

int main(){
    int n;
    cin >> n; // number of words

    while (n--) {
        string s;
        cin >> s;

        waytomanylines(s);
    }
    
   

}