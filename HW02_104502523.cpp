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
    st->top = 0;
}

void optpush(optstack *st,char input)
{
    //prevent overflow
    if(st->top < 99) st->opts[st->top++] = input;
    //cout << "push: " << input << " num: " << st->top << endl;
}

char optpop(optstack *st)
{
    // prevent underflow
    if(st->top){
	//cout << "pop: " << st->opts[st->top - 1] << " num: " << st->top << endl;
	return st->opts[--(st->top)];
    }
    else return 0;
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

// use to determine the priority of the operators
int priorityNumber(char a){
    if(a == '(' || a == ')') return 0; // '(' should be determined as a new expression
    if(a == '*' || a == '/') return 2;
    else return 1;
}

string infixtopostfix(string s,optstack *st)
{
    string temp;
    optinit(st);
    // parse the operator
    for(int i = 0; i < s.length(); i++){
	// parse '(' first to prevent error
	if(s[i] == '(') optpush(st, s[i]);
	else if(s[i] == ')'){
	    for(char t = optpop(st); t != '('; t = optpop(st)) temp += t;
	}else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
	    while(st->top && priorityNumber(st->opts[st->top - 1]) > priorityNumber(s[i])){
		temp += optpop(st);
	    }
	    optpush(st, s[i]);
	}else{
	    temp += s[i];
	    //cout << "cat: " << s[i] << endl;
	}
    }
    while(st->top) temp += optpop(st);
    s = temp;
    //cout << s << endl;
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
