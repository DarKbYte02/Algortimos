#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli FMCS(vector<lli>& a,lli low,lli mid,lli high){
	lli ls = -9223372036854775807,sum=0;
	// cout << "low: " << low << endl << "mid: " << mid << endl << "high: " << high << endl;
	for(auto i = mid;i>=low;i--){
		sum += a[i];
		if(sum>ls) ls = sum;
		}
	sum = 0;
	lli rs=-9223372036854775807;
	for(auto j = mid+1;j<=high;j++){
		sum += a[j];
			if(sum>rs) rs = sum;
		}
	sum = 0;
	// cout << "suma ls + rs: " << ls+rs << endl;
	return (ls+rs);
}

lli FMS(vector<lli>& a, lli low, lli high){
	lli t1;
	lli t2;
	lli t3;
	if(high == low){
 		return a[low];
	}
	else{
		lli mid = (low+high)/2;
		// cout << "mid FMS : " << mid << endl;
		t1 = FMS(a,low,mid);
		t2 = FMS(a,mid+1,high);
		t3 = FMCS(a,low,mid,high);
	}
	//auto ans = max(t1,max(t2,t3));
	// cout << "t1,t2 y t3: " << t1 << " " << t2 << " " << t3 << endl;
	if((t1 >= t2) && (t1 >= t3)) return t1;
	else if((t2 >= t1) && (t2 >= t3)) return t2;
	else return t3;
// return ans;
}

int main(){
	cin.tie(nullptr); cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	auto x = 0,y = 0;
	vector<lli> a;
	cin >> x;
	for(auto j = 0; j<x;j++){
		cin >> y;
		a.push_back(y);
	}
	lli answer = FMS(a,0,a.size()-1);
	cout << answer << '\n';
return 0;
}
