#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
    public:
    string color;
    int num_tyres;
};
class scooter:public Vehicle{
    string color=

 

 
};

class car : public Vehicle
{
    
};
int main()
{
    Vehicle *v = new Vehicle();
    v->num_tyres=4;
    Vehicle s;
    s.num_tyres=2;
    cout<<v->num_tyres<<endl;
    cout<<s.num_tyres<<endl;
    return 0;
}