#include <iostream>
#include<bits/stdc++.h> 
using namespace std; 

bool small(string st1, string st2) 
{ 
	int n1 = st1.length(), n2 = st2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (st1[i] < st2[i]) 
		return true; 
	else if (st1[i] > st2[i]) 
		return false; 

	return false; 
} 

string subract(string st1, string st2) 
{ 

	if (small(st1, st2)) 
		swap(st1, st2); 

	string p = ""; 

	int n1 = st1.length(), n2 = st2.length(); 

	reverse(st1.begin(), st1.end()); 
	reverse(st2.begin(), st2.end()); 
	
	int c = 0; 

	for (int i=0; i<n2; i++) 
	{ 
		
		
		int sub = ((st1[i]-'0')-(st2[i]-'0')-c); 
		
	
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			c = 1; 
		} 
		else
			c = 0; 

		p.push_back(sub + '0'); 
	} 


	for (int i=n2; i<n1; i++) 
	{ 
		int sub = ((st1[i]-'0') - c); 
		
	
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			c = 1; 
		} 
		else
			c = 0; 
			
		p.push_back(sub + '0'); 
	} 

	reverse(p.begin(), p.end()); 

	return p; 
} 

int main() 
{ 
	string st1; 
	string st2; 
	getline(cin, st1);
	getline(cin, st2);
	cout << subract(st1, st2); 
	
	return 0; 
} 