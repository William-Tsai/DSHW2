#include <iostream>
#include <string>

using namespace std;

typedef struct optstack {
    char opts[100];
    int top;
};

typedef struct numstack {
    float nums[100];
    int top;
};

void optinit(optstack *st)
{

}

void optpush(optstack *st,char input)
{

}

char optpop(optstack *st)
{
    return 'a';
}

void numinit(numstack *st)
{

}

void numpush(numstack *st,float input)
{

}
float numpop(numstack *st)
{
    return 0;
}

string infixtopostfix(string s,optstack *st)
{
    return s;
}

float calculate(string s,numstack *st,float *value)
{
    return 0;
}

int main()
{
    float a[5];
    for(int i=0; i<5; i++) {
        cin >> a[i];
    }
    for(int i=0; i<5; i++) {
        char c='A';
        c=c+i;
        cout << c << " = " << a[i] << endl;
    }
    while(true) {
        string s="";
        optstack *popt=new optstack;
        numstack *pnum=new numstack;
        cin >> s;
        s= infixtopostfix(s,popt);
        cout << s << " = " << calculate(s,pnum,a) << endl;
        delete popt;
        delete pnum;
    }
    return 0;
}
