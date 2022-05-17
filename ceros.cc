#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
vector<int> dp;
int ceros(const int n){
if(dp[n] != -1) return dp[n];
if(n == 0) return 0; // si es de longitud cero la cadena regresa 0
if(n == 1) return 2; // si es de longitud uno regresa 2 
if(n == 2) return 4; // si es de longitud dos regresa 4
if(n == 3) return 7; // si es de longitud tres regresa 7
return dp[n] = ceros(n-1)+ceros(n-2)+ceros(n-3);
}
//Las cadenas que van a tener solo un cero van a ser las que acababan en uno b(n+1) = a(n) -> b(n) = a(n-1)
//Las que van a tener dos ceros van a ser las que terminaban en cero c(n+1) = b(n) -> c(n) = b(n-1) -> b(n-1) = a(n-2)
//Las validas nuevas van a ser la suma de las validas anteriores más las que salgan de agregar un uno y un cero al final a(n+1) = a(n) + b(n+1) + c(n+1) 
//Al final tenemos -> a(n+1) = a(n) + a(n-1) + a(n-2)
//Usamos DP para ahorrar calcular valores ya calculados
int main(){
fastio();
	int n=0; cin >> n;
	dp.resize(n+10,-1);
	dp[0] = 0; dp[1] = 2; dp[2] = 4; dp[3] = 7;
	cout << ceros(n) << endl;
return 0;
}
