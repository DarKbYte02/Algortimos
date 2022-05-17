#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio() cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
double distbruta(vector<pair<double,double>>& b){
double minimum=99999999999;						//La iniciamos en infinito para poder obtener el valor mínimo
for(auto i=0;i<b.size();i++){						//A fuerza bruta calculamos la distancia mínima entre los puntos.
	for(auto j=i+1;j<b.size();j++){
		minimum = min(minimum,sqrt(pow(b[i].first-b[j].first,2)+pow(b[i].second-b[j].second,2)));	//En el vector de pares el primer valor es
		}												//la coordenada x y la segunda es la coordenada y
	}
return minimum;
	}
double deltas(vector<pair<double,double>>& a, double d){	//Esta función recibe los puntos a +- un delta de distancia, revisa si hay puntos a un
	for(auto i=0;i<a.size();i++){				//delta de altura, para esto invierte las coordenadas x e y, las ordena y revisa si hay algún par de
	swap(a[i].first,a[i].second);				//puntos más cercanos entre estos deltas de distancia en el eje x.
	}
	sort(a.begin(),a.end());				//Ordena los puntos que están al +- delta de distancia.
	auto minimum = d;
	for(auto i=0;i<a.size();i++){				//Revisa si hay puntos más cercanos en el delta de distancia.
		for(auto j=i+1;j<a.size() && ((a[j].first-a[i].first) < minimum);j++) minimum = min(minimum,sqrt(pow(a[i].first-a[j].first,2)+pow(a[i].second-a[j].second,2)));
		}
	return minimum;
	}
double closestpair(vector<pair<double,double>>& b){
auto n = b.size();					//El tamaño de mi arreglo será lo que nos dirá si estamos en el caso base o no
if(n <= 3) return distbruta(b);				// CASOS BASE PARA UNA RECURSIÓN FINITA
							// DIVIDE
	vector<pair<double,double>> mid_left;		//Dividimos el vector en la mitad, esta será la mitad izquierda
	vector<pair<double,double>> mid_right;		//Esta es la mitad derecha
	for(auto i=0;i<n/2;i++) mid_left.push_back(b[i]);	//Copialos a un vector nuevo
	for(auto i=(n/2)+1;i<n;i++) mid_right.push_back(b[i]);	//Copia la otra mitad

	auto d = min(closestpair(mid_left),closestpair(mid_right));	//El mínimo de las mitades divididas
							//COMBINA
	vector<pair<double,double>> s;			//Vector para revisar si en un delta de distancia hay puntos cercanos
	for(auto i=0;i<n;i++){				//Si está a un delta de distancia, mételo al vector
		if(abs(b[i].first-b[n/2].first)<d) s.push_back(b[i]);
	}
return min(deltas(s,d),d);				//La distancia mínima será entre si hay algún par de puntos entre la mitad o en alguna de las
	}						// mitades izquierdas o derechas.
int main(){
fastio();
	auto n=0; cin >> n;				//n es el número de puntos en el plano
	vector<pair<double,double>> b(n);		//Creamos un vector de pares (de doubles) para guardar los puntos en el plano x y
	for(auto i=0;i<n;i++){				//Leemos los datos de entrada, creamos una variable temporal para meter datos en el vector
		pair<double,double> buffer;		//Estructura auxiliar
		cin >> buffer.first;			//Leemos la coordenada x
		cin >> buffer.second;			//Leemos la coordenada y
		b[i] = buffer;				//Guardamos los datos en el vector
	}
	sort(b.begin(),b.end());			//Hacemos el preordenamiento
	double answer = closestpair(b);			//Llamamos a la función principal
	cout << fixed << setprecision(3) << answer << endl;	//Imprimimos la respuesta
	return 0;					//Fin del programa
}
