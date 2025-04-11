#include <bits/stdc++.h>
using namespace std;
int main(){
    long double a,b,c,d,e, vi,vf;
    cin >> a >> b >> c >> d >> e >> vi >> vf;

    a*=12;
    b*=6;
    c*=2;

    long double x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    long double x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

    if(a<0.0 && x1>=vi && x1<=vf && x2>=vi && x2<=vf){
        cout << fixed << setprecision(7) << x1 << endl;
        cout << fixed << setprecision(7) << x2 << endl;
    }
    else{
        cout << "PARAMETROS FALHOS\n";
    }


    return 0;
}
