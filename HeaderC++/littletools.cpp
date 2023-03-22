#include "littletools.h"

using namespace std;

int RandomInt(int L, int R)
{
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(L, R);
    return dis(gen);
}

float RandomFloat(double L, double R)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(L, R);
    return dis(gen);
}
