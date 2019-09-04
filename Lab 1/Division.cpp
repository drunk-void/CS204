#include <bits/stdc++.h> 
using namespace std; 
   
  
void div(string n1, long long m1) 
{  
    vector<int> a; 
    long long mod = 0; 
  for (int i = 0; i < n1.size(); i++) 
    {   int d= n1[i] - '0'; 
        mod = mod * 10 + d; 
         int q= mod / m1; 
        a.push_back(q);  
        mod = mod % m1;         
    } 
    cout <<endl<<"Remainder :"<< mod <<endl; 
    cout << "Quotient :";
    int x = 0; 
    for (int i = 0; i <a.size(); i++) 
       { if (a[i] == 0 && x == 0) 
         continue; 
        x = 1; 
        cout << a[i]; 
       } 
  
    return; 
} 
  
int main() 
{ int ca;
  cout<<"Enter  number of cases: ";
  cin>>ca;
 for(int i=0;i<cas;i++)
  {
    string num; 
    long long t;
 cout<<"Enter the larger number then smaller number :"; 
cin>>num>>t;
   div(num, t);
   } 
    return 0; 
} 