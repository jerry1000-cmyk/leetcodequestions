#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
       int n ;
       string j;
       vector<string> hexjer;
    
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>j;
        hexjer.push_back(j);
    }
    int hxj = 1;
    for(auto num : hexjer){
        
        string hex = num;
        int s = hex.size();
        int power = 0;
        int decans = 0;
        for(int i = (s-1) ; i>=0 ; i--){
            
            char ch = hex[i];
            int val = 0;
            if (ch >= '0' && ch <= '9'){
                val = ch - '0';
            }
            else if (ch >= 'A' && ch <= 'F'){
                val = ch - 55;
            }
            decans += val*(int)pow(16 , power);
            power++;   
        }
        int temp = decans;
            string oct = "";
            while(temp>0){
                int rem = temp % 8;
                oct = char(rem + '0') + oct;
                temp = temp/8;

            }
            if (oct == "") oct = "0";
            int octans = stoi(oct);
            
            if(octans<=10){
               cout << "Player " << hxj << ": Hex = " << num << ", Octal = " << oct << ", Status = Rookie Player" << endl;
               hxj++;
 
            }
            else if(octans>=11 && octans<=30){
            cout << "Player " << hxj << ": Hex = " << num << ", Octal = " << oct << ", Status = Regular Player" << endl;
            hxj++;

            }
            else{
            cout << "Player " << hxj << ": Hex = " << num << ", Octal = " << oct << ", Status = Star Player" << endl;
            hxj++;

            }
        
    }
    system("pause");
    return 0;
}