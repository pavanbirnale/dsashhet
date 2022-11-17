// Print all the permutations of the given string

#include<bits/stdc++.h>
using namespace std;

class solution
{
	private:
	void permute(string str ,int begin,vector<string>& ans ){
	    if(begin==str.length()){
	        ans.push_back(str);
	        return;
	    }
	        for(int i=begin;i<str.length();i++){
	        swap(str[begin],str[i]);
	        permute(str,begin+1,ans);
	        swap(str[begin],str[i]);    	        
	    }
	}
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    permute(S,0,ans);
		    return ans;
		}
};
           


void next_per(string S){
	sort(S.begin(),S.end());
	cout<<S<<"\n";
	while(next_permutation(S.begin(),S.end())){
		cout<<S<<"\n";
	}
}
int main(){
    solution s1;
    vector<string> arr = s1.find_permutation("AAA");
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<"\n";
	}
    // next_per("ab");
  return 0;
}