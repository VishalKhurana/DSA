#include<bits/stdc++.h>
using namespace std;
class Parent
{

    int a=5;
    public:
    int p=6;
    void role()
    {
        cout<<"I am Parent"<<endl;
    }
};
class Student : public Parent{
public:
void role()
{
    cout<<"I am Student"<<endl;
}
int s=7;

};
int main()
{
    Parent* st= new Student();
    st->p; 

}