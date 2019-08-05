#include<bits/stdc++.h>
using namespace std; 

string sum(string s1, string s2) 
{ 
    if (s1.length() > s2.length()) 
        swap(s1, s2); 
 
    string str = ""; 
    int n1 = s1.length(), n2 = s2.length(); 
    reverse(s1.begin(), s1.end()); 
    reverse(s2.begin(), s2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((s1[i]-'0')+(s2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((s2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string singleMultiply(string str,char ch,int l2){
	int x= ch-'0';
	int carry=0;
	for(int i=l2-1;i>=0;i--){
		int temp=(str[i]-'0')*x + carry;
		str[i]=temp%10 + '0';
		carry=temp/10;
	}
	string zero="0";
	zero[0] = carry+'0';

	if(carry==0){
		return str;
	}else{
		return zero.append(str);
	}
}

string multiply(string s1,string s2){
	long int l1=s1.length();
	long int l2=s2.length();
	string result="";
	long int k=0;
	string zero="0";
	for(long int i=l1-1;i>=0;i--){
		string str=singleMultiply(s2,s1[i],l2);
		for(long int z=0;z<k;z++){
			str.append(zero);
		}
		k++;
		result=sum(str,result);
	}
	return result;
}


int main(){
	long long int digit;
	cin>>digit;
	while(digit--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<multiply(s1,s2)<<endl;
	}
	return 0;
}