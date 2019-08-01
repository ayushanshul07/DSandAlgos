#include <iostream>
#include <string>

using namespace std;

int dp[100];

void f(string& s){

	if(s.size() == 0 || s.size() == 1) return;
	int len = s.size();
	for(int i = 1; i < len; i++){
		if(s[i] == '(') continue;

		if(s[i-1] == '(') dp[i] = 2 + dp[i-2];
		else {
			int tmp = (i - dp[i-1] -1);
			if(tmp >= 0){
				if(s[tmp] == '('){
					dp[i] = 2 + dp[i-1] + dp[(i-dp[i-1]-2) < 0 ? 0 : (i-dp[i-1]-2)];
				}
			}
		}
	}

}

int main(){

	string s = "(()(()(())))";

	for(int i = 0; i < s.size(); i++) dp[i] = 0;

	f(s);

	int maximum = -1;

	for(int i = 0; i < s.size(); i++) maximum = max(dp[i],maximum);

	cout << maximum << endl;

	return 0;
}
