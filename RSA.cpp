#include <iostream>
#include <cmath>
#include <vector>
#include<time.h>
#include <algorithm>
#include <numeric>
using namespace std;
int mcd(int a, int b)
{
    int temp;
    while (1)
    {
        temp = a%b;
        if (temp == 0)
          return b;
        a = b;
        b = temp;
    }
}
vector<int> extEuclid(int a, int b)
{
    vector<int> vec;
    int sup;
    if (a % b == 0)
    {
        vec = {b, 0, 1};
        return vec;
    }
    else
    {
        vec = extEuclid(b, a % b);
        sup = vec[1];
        vec[1] = vec[2];
        vec[2] = sup - ((a/b)*vec[2]);
        return vec;
    }
}
int Inversa(int a, int n)
{
    vector<int> vec = extEuclid(a, n);
    if (vec[0] == 1)
    {
        return (vec[1] % n + n) % n;
    }
    return 0;
}


int genE(int p)
{
    int e = 2;
    while (e < p)
    {
        if (mcd(e, p) == 1)
        {
            break;
        }
        e++;
    }
    return e;
}
vector<int> NAIVE_RSA_KEY_GENERATOR()
{
    int p = 3;
    int q = 11;
    int n = p*q;
    int CantInvers = (p-1)*(q-1);
    int e = genE(CantInvers);
    int d = Inversa(e, CantInvers);

    vector<int> res;
    res.push_back(n);
    res.push_back(e);
    res.push_back(d);
    return res;
}
int expmod (int a, int b, int p) 
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = int (res * 1ll * a % p);
            --b;
        }
        else
        {
            a = int (a * 1ll * a % p);
            b >>= 1;
        }
    }  
    return res;
}

int main() 
{
    vector<int> vec =NAIVE_RSA_KEY_GENERATOR();
    int i=0;
    while(i<vec[0]){
        int ac = i;
        int c = expmod(ac,vec[1], vec[0]);
        cout << "valor de c: " << c;
        cout << " valor de m: " << expmod(c,vec[2] , vec[0]) <<endl;
      i++;
    }
    cout<<i/2;
    cout<<" casos";
}
