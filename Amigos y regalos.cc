#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
ulli solve(ulli c1,ulli c2, ulli x, ulli y){
ulli left = 1,right = 18446744073709551615,middle;
while(left<right){
	middle = left + (right-left)/2;
	if((c1 <= middle - (middle/x)) && (c2 <= middle-(middle/y)) && ((c1+c2) <= middle-(middle/(x*y)))) 
        right = middle;
	else left = middle+1;
	}
return right;
}
int main(){
fastio();
	pair<ulli,ulli> a,b;

	ulli c1,c2,x,y;
	cin >> c1 >> c2 >> x >> y;
	auto ans = solve(c1,c2,x,y);
	cout << ans << endl;

return 0;
}
