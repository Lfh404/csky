#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int maxsum = -1;
vector<int> factor, dfsnum, res, temp;
bool flag = true;

void dfs(int n, int k, int sum) {
	if(n<0 || k<0) return;
	if(n==0 && k==0) {
		if(flag) {
			res=temp;
			flag = false;
		} else {
			if(maxsum < sum) {
				maxsum = sum;
				res = temp;
			} 
//			else if(maxsum == sum) {
//				for(int i=temp.size()-1; i>=0; i--) {
//					if(temp[i]>res[i]) {
//						res = temp;kllll
//					}
//					if(temp[i]<res[i]) return;
//				}
//			}
		}
	}
	int s = temp.size();
	for(int i=0; i<factor.size(); i++) {
		if(s!=0 && temp[s-1]<factor[i]) continue;
		temp.push_back(factor[i]);
		dfs(n-dfsnum[i], k-1, sum+factor[i]);
		temp.pop_back();
	}
}

int main() {
	freopen("a.in", "r", stdin);
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);
	for(int i=1; pow(i, p)<=n; i++) {
		factor.push_back(i);
		dfsnum.push_back(pow(i, p));
	}
	dfs(n, k, 0);
	printf("%d =", n);
	for(int i=0; i<res.size(); i++) {
		if(i) printf(" +");
		printf(" %d^%d", res[i],p);
	}
	printf("\n%d\n", maxsum);
	return 0;
}