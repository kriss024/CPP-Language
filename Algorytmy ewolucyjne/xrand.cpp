#include "xrand.h"

// Inicjujemy rejestry generatora.
double XRand::a = 17997.0;
double XRand::b = 25925.0;
double XRand::c = 11557.0;

void XRand::Randomize()
{
    srand((unsigned)time(NULL));
    a = rand();
    b = rand();
    c = rand();
}

void XRand::Randomize(const int& r1, const int& r2, const int& r3)
{
    a = r1;
    b = r2;
    c = r3;
}

double XRand::Uniform()
{
    double x;

    x = (a+b+c)*8192;
    x = fmod( x, 4294967291.0);

    a = b;
    b = c;
    c= x;
    if (x < (float)2147483648.0)
        x = (int)x;
    else x = (int)(x - 4294967296.0);

    return (x*2.3283064365e-10)+0.5;
}

double XRand::Uniform(const double& min, const double& max)
{
    return Uniform()*(max-min)+min;
}

int XRand::Uniform(const int& min, const int& max)
{
    return (int)floor(Uniform()*(max-min)+min);
}

double XRand::Normal()
{
    double U, V, X, X2;
    bool accept=false;
    do
    {
        U=Uniform();
        V=(Uniform()-0.5)*1.71552777;
        X=V/U;
        X2=X*X;
        if (X2 <= 2*(3-U*(4+U)))
            accept=true;
        else
            if (X2 <= 2/U - 2*U)
                if (X2<=(-4)*log(U))
                    accept=true;
    }
    while (!accept);
    return X;
}

double XRand::Normal(const double& avg, const double& dev)
{
    return Normal()*dev+avg;
}

int XRand::Geometric(const double& p)
{
    return (int)floor(log(Uniform())/log(p));
}

int XRand::Binominal(int n, const double& p)
{
    int succ=0;
    for ( ; n>0 ; n--)
        if (Uniform()<=p) succ++;
    return succ;
}

bool XRand::Binary()
{
    if (Uniform() > 0.5) return false;
    else return true;
}

bool XRand::Binary(const double& p)
{
    if (p<0 || p>1) exit(-1);
    if (Uniform() > p) return false;
    else return true;
}

