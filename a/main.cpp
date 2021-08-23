#include<iostream>
#include<cstring>
using namespace std;
int m, n, l, t, G[65][1300][130], cnt;
int volume=0;
int xi[6] = {0, 0, 1,-1, 0, 0};
int yi[6] = {0, 0, 0, 0, 1,-1};
int zi[6] = {1,-1, 0, 0, 0, 0};
bool vis[65][1300][130];

void dfs(int a, int b, int c) {
	if(a<0||a>=l || b<0||b>=m || c<0||c>=n) return ;
	vis[a][b][c] = true;
	cnt++;
	for(int i=0;  i<3; i++) {
		int x=a+xi[i], y=b+yi[i], z=c+zi[i];
		if(!vis[x][y][z] && G[x][y][z]) {
			dfs(x, y, z);
		}
	}
}

int main() {
	freopen("a.in", "r", stdin);
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int i=0; i<l; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<n; k++) {
				scanf("%d", &G[i][j][k]);
			}
		}
	}
	memset(vis[0][0], 0, 65*1300*130);
	for(int i=0; i<l; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<n; k++) {
				if(!vis[i][j][k] && G[i][j][k]) {
					cnt=0;
					dfs(i,j,k);
					printf("%d\n", cnt);
					if(cnt >= t) volume += cnt;
				}
			}
		}
	}
	printf("%d", volume);
	return 0;
}
