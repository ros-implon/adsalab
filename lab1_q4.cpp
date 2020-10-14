#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

int equalise(string &s1, string &s2, int n1,int n2){
    
    if(n1<n2) { 
        for (int i=0; i<n2-n1; i++) 
            s1 = '0' + s1; 
        return n2; 
    }else{ 
        for (int i=0; i<n1-n2; i++) 
            s2 = '0' + s2; 
        return n1;
    } 
}

string sub(string s1, string s2){
    
    string s = "";
    int carry = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    int n;

    if(len1!=len2){
        if(len1<len2){
            swap(s1,s2);
            n = equalise(s1,s2,len2,len1);
        }else{
            n = equalise(s1,s2,len1,len2);
        }     
        
    }else{
        n = len2;
    }     
    
    for(int i=n-1; i>=0; i--){
        int dif = (s1[i] - '0') - (s2[i] - '0') - carry; 
        if(dif < 0){ 
            dif = dif+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        s.push_back(dif + '0');
    }

    reverse(s.begin(), s.end());

    int it = n-1;
    for(int i=0; i<n; i++){
        if(s[i]!='0'){
            it = i;
            break;
        }      
    }

    return s.erase(0, it);
}

string add(string s1, string s2){

    string s = "";
    int carry = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    int n;

    if(len1!=len2){
        n = equalise(s1,s2,len1,len2);
    }else{
        n = len1;
    }   
    
    for(int i=n-1; i>=0; i--){
        int sum = (s1[i] - '0') + (s2[i] - '0') + carry; 
        s.push_back(sum%10 + '0'); 
        carry = sum/10;
    }

    if (carry) 
        s.push_back(carry+'0');

    reverse(s.begin(), s.end());
    
    int it = n-1;
    for(int i=0; i<n; i++){
        if(s[i]!='0'){
            it = i;
            break;
        }      
    }

    return s.erase(0, it);
}

string multiply(string s1, string s2){

    int n1 = s1.length();
    int n2 = s2.length();
    int n;

    if(n1!=n2){
        n = equalise(s1,s2,n1,n2);
    }else{
        n = n1;
    }

    if(n==1){
        return to_string((s1[0]-'0')*(s2[0]-'0'));
    }

    string xl = s1.substr(0, n/2);
    string xr = s1.substr((n/2), n-(n/2));
    string yl = s2.substr(0, n/2);
    string yr = s2.substr((n/2), n-(n/2));
    
    string z1 = multiply(xl, yl);
    string z2 = multiply(xr, yr);
    string z3 = multiply(add(xl, xr), add(yl, yr));
    string z4 = sub(z3, add(z1, z2));
    
    for(int i=0; i<2*(n-(n/2)); i++){
        z1 = z1 + '0';
    }

    for(int i=0; i<n-(n/2); i++){
        z4 = z4 + '0';
    }

    return add(z1, add(z2, z4));

}

int main() {
    
    int t;
    cin >> t;

    while (t--){
        string n1, n2;
        cin >> n1;
        cin >> n2;
        cout << multiply(n1, n2) << "\n";
    }
    

    return 0;
}