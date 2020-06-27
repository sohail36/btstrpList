#include<bits/stdc++.h>
using namespace std;

int primes[10000];

void Prime(){
  primes[0]=primes[1]=0;
  
  for(int i=2;i<=sqrt(10000);i++){
    if(primes[i]){
      for(int j=i*i;j<=10000;j+=i)
        primes[j]=0;
      
    }
  }
  
}

int main(){
  
  int n1,n2;
  for(int i=0;i<10000;i++)
  primes[i]=1;
  cin>>n1>>n2;
  Prime();
  vector<int> v1,v2,v3;
  for(int i=n1;i<=n2;i++)
  if(primes[i])
  v1.push_back(i);
  for(vector<int>::size_type i=0;i<v1.size();i++){
	  for(vector<int>::size_type j=0;j<v1.size();j++){
	  if(v1[i]!=v1[j])
		 v2.push_back(stoi(to_string(v1[i])+to_string(v1[j])));
	  }
  }
  
  set<int> s;
  
  for(vector<int>::size_type i=0;i<v2.size();i++)
  if(primes[v2[i]])
  s.insert(v2[i]);
  
  
 
  auto it=s.begin();
  long long a=*it,c=s.size(),temp=0;
  set<int> :: reverse_iterator i;
  i=s.rbegin();
  
  long long b=*i;
  c-=2;
  while(c--){
  	temp=a+b;
  	a=b;
  	b=temp;
  }
  cout<<temp;
  
}