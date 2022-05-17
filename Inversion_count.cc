#include<bits/stdc++.h>
using namespace std;
 #define lli long long int
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
lli ans=0; vector<lli> f;
void Merge(vector<lli>& a, lli p, lli q, lli r){
	lli left = q - p + 1;
	lli right = r - q;
	vector<lli> la,ra;
	for(auto i=0;i<left;i++) la.push_back(a[i+p]);
	for(auto j=0;j<right;j++) ra.push_back(a[j+q+1]);
	lli i=0,j=0,k=p;
	while(i<left && j < right){
		if(la[i] <= ra[j]) a[k++] = la[i++];
		else{
		a[k++] = ra[j++];
		ans += (left-i);
			}
		}
	while(i<left){
	a[k++] = la[i++];
		}
	while(j<right){
	a[k++] = ra[j++];
	}
return;
}

void MergeSort(vector<lli>& a, long int p, long int r){
	if(p<r){
		lli q = p + (r-p)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
return;
}

void solve(){
	auto N=0; cin >> N;
	vector<lli> a(N);
	for(auto i=0;i<N;i++) cin >> a[i];
	cin.ignore();
	MergeSort(a,0,N-1);
	f.push_back(ans);
	a.clear();
	ans = 0;
	return;
}
int main(){
fastio();
	auto n=0; cin >> n;
	for(auto i=0;i<n;i++) solve();
	//cout << f.size() << endl;
	for(auto k : f) cout << k << endl;
return 0;
}
