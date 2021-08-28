#include<iostream>
#include<string>
using namespace std;
int count[1010];
bool stucked[400], exclude[400], printed[400];

int main() {
// 	freopen("a.in", "r", stdin);
	int k;
	string s;
	scanf("%d\n", &k);
	getline(cin, s);
	int stt = 0, cnt = 1, i;
	char pre = s[0];
	for(i=1; i<s.size(); i++) {
		if(s[i]==pre) cnt++;
		else {
			while(stt<i) {
				count[stt++] = cnt;
			}
			cnt = 1;
			pre = s[i];
		}
	}
	while(stt<i) count[stt++] = cnt;
	for(int i=0; i<s.size(); i++) {
		if(count[i]%k==0 && !exclude[s[i]]) stucked[s[i]] = true;
		if(count[i] % k) exclude[s[i]] =  true;
	}
	for(int i=0; i<s.size(); i++) {
		if(stucked[s[i]] && !exclude[s[i]] && !printed[s[i]]) {
			printf("%c", s[i]);
			printed[s[i]] = true;
		}
	}
	printf("\n");
	for(int i=0; i<s.size(); i++) {
		printf("%c", s[i]);
		if(stucked[s[i]] && i+2<s.size() && s[i+2]==s[i] && !exclude[s[i]]) i+=k-1;
	}
	return 0;
}