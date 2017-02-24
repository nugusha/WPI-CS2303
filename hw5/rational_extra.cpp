/*
 * Rational.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
#include <iomanip>
#include <map>
#include "Rational.h"

using namespace std;


ifstream in;


Rational normalize(long long TOP,long long BOT){
	if(BOT<0)TOP*=-1,BOT*=-1;	//multiplies numerator by -1 if denom is negative

	long long gc=__gcd(abs(TOP),abs(BOT));	   //  __gcd(x,y)  is a built-in function in #include<algorithm>
									// which finds greatest common divisor of x and y using euclid algorithm

	TOP/=gc;
	BOT/=gc;

	return Rational(TOP,BOT);
}// end normalize

Rational::~Rational() {

}// end destructor

Rational::Rational() {
	top = 0;
	bot = 1;
}// end default constructor

Rational::Rational(const int num, const int denom) {
	top = num;bot = denom;
	if(bot<0)top*=-1,bot*=-1;//multiplies numerator by -1 if denom is negative
	int gc=__gcd(abs(top),abs(bot));
	top/=gc;bot/=gc;
}// end Rational(const int num, const int denom)

Rational::Rational(const int wholeNumber) {
	top = wholeNumber;
	bot = 1;
}// end Rational(const int wholeNumber)

Rational::Rational(const Rational &a) {
	top = a.top;
	bot = a.bot;
} // end Rational(const Rational &a)

ostream& operator<<(ostream& out, const Rational& rat) {
	out << rat.top << '/' << rat.bot;
	return out;
}// end ostream
int k=0;
istream& operator>>(istream& in,Rational& rat) {
	string s;

	in>>s;

	int ind=s.find('/');

	if(ind==-1){                // if ind==-1 then there is not / in rational number
		rat.top=atoi(s.c_str());// so we assign the given number to the top
		rat.bot=1; 				// and 1 to the bot
		return in;
	}

	int TOP=0,BOT=0;

	int sign=1;
	if(s[0]=='-'){sign=-1;s[0]='0';} // checks for the negative sign and stores in sign
									// s[0]='0' because "037" will still be converted to 37

	for(int i=0;i<ind;i++){
		TOP=TOP*10+s[i]-'0';     // gets the numerator from the string of numbers
	}


	if(ind+1<int(s.size()) && s[ind+1]=='-'){sign*=-1;s[ind+1]='0';}
								// checks for the negative sign and stores in sign

	for(int i=ind+1;i<int(s.size());i++){
		BOT=BOT*10+s[i]-'0';    // gets the denominator from the string of numbers
	}
	Rational et=normalize(TOP,BOT);
	rat=et;

	rat.top*=sign;

	return in;
}// end istream

Rational Rational::operator+(const Rational &rat){
	long long TOP=bot*rat.top+top*rat.bot;
	long long BOT=bot*rat.bot;

	return normalize(TOP,BOT);
}// end +
Rational Rational::operator-(const Rational &rat){

	Rational x(-rat.top,rat.bot);
	return (*this+x);
}// end -
Rational Rational::operator*(const Rational &rat) {
	long long TOP = top * rat.top;
	long long BOT = bot * rat.bot;

	return normalize(TOP, BOT);
}// end *
Rational Rational::operator/(const Rational &rat){
	long long TOP = top * rat.bot;
	long long BOT = bot * rat.top;

	return normalize(TOP, BOT);
}// end /
int Rational::operator==(const Rational &rat) {
	return (top == rat.top && bot == rat.bot);
}// end ==
int Rational::operator!=(const Rational &rat) {
	return (top != rat.top || bot != rat.bot);
}// end !=
int Rational::operator>(const Rational &rat) {
	return (top*rat.bot > bot*rat.top);
}// end >
int Rational::operator<(const Rational &rat) {
	return (top*rat.bot < bot*rat.top);
}// end <
int Rational::operator>=(const Rational &rat) {
	return ((*this==rat) || (*this>rat));
}// end >=
int Rational::operator<=(const Rational &rat) {
	return ((*this==rat) || (*this<rat));
}// end <=
Rational Rational::operator=(Rational &rat){
	top=rat.top;
	bot=rat.bot;
	return *this;
}// end =

// extra credit functions

Rational Rational::operator+=(Rational &rat){
	Rational x=(*this)+rat;

	top=x.top;
	bot=x.bot;

	return (*this);
}// end +=
Rational Rational::operator-=(Rational &rat){
	Rational x=(*this)-rat;

	top=x.top;
	bot=x.bot;

	return (*this);
}// end -=
Rational Rational::operator/=(Rational &rat){
	Rational x=(*this)/rat;

	top=x.top;
	bot=x.bot;

	return (*this);
}// end /=
Rational Rational::operator*=(Rational &rat){
	Rational x=(*this)*rat;

	top=x.top;
	bot=x.bot;

	return (*this);
}// end *=

// end extra credit functions

double toDouble(const Rational &rat) {
	return (double)(rat.top)/(double)(rat.bot);
}// end toDouble




map<string,Rational>mp;
/*
 *  map is a built in data structure and is implemented by red-black trees.
 *  It works like a hash-table. Takes any string and returns rational assigned to that string
 *  It's complexity for adding, changing or retrieving data is o(log(n)) (n being number of strings already in it)
 */

void solve(string s){



	Rational rat;
	stack<pair<string,Rational> >st;             // stack takes a pair of string and rational
	//cout<<s<<endl;


	int ind=0;
	int compare=0;



	if(s.size()==0)goto empty_line; // if empty throws an empty line error

	while(ind<int(s.size())){	// performs mathematics actions


		int n_ind=s.size();
		for(int j=ind;j<int(s.size());j++){	// checks for white space
			if(s[j]==' '){n_ind=j;break;}
		}

		string ne="";
		for(int j=ind;j<n_ind;j++){	// adds s[j] to ne
			ne+=s[j];
		}

		stringstream ss;
		ss<<ne;


		if(('A'<=ne[0] && ne[0]<='Z') ||		 // if ne[0] is letter then it is a variable
				('a'<=ne[0] && ne[0]<='z')){
				st.push(make_pair(ne,mp[ne]));

		}else
		if(('0'<=ne[0] && ne[0]<='9') ||
				(ne[0]=='-' && ne.size()>1 && ('0'<=ne[1] && ne[1]<='9'))){
			ss>>rat;

			if(rat.bot==0){
				goto err;
			}

			st.push(make_pair("No string",rat));
		}else{
			if(st.size()<2){
				goto err;
			}

			if(compare==1)goto err; // if we already have comparison it should have been the last
					// so we print error


			// if string is not "No string" it means it is an variable
			// so we get data from the map for it

			Rational a1=st.top().second;string b1=st.top().first;st.pop();
			if(b1!="No string")a1=mp[b1];

			Rational a2=st.top().second;string b2=st.top().first;st.pop();
			if(b2!="No string")a2=mp[b2];


#define PUSH(x) push(make_pair("No string",x))   //  this is a shortcut for the push(make_pair ... )

			if(s[ind]=='=' && (ind+1>=int(s.size()) || s[ind+1]!='='))st.PUSH(a2=a1),mp[b2]=a2;else
			if(s[ind]=='+' && (ind+1>=int(s.size()) || s[ind+1]!='='))st.PUSH(a1+a2);else
			if(s[ind]=='-' && (ind+1>=int(s.size()) || s[ind+1]!='='))st.PUSH(a2-a1);else
			if(s[ind]=='*' && (ind+1>=int(s.size()) || s[ind+1]!='='))st.PUSH(a1*a2);else
			if(s[ind]=='/' && a1.top!=0  && (ind+1>=int(s.size()) || s[ind+1]!='='))st.PUSH(a2/a1);else
			{
				compare++;                            	        // we count the number of comparisons

				if(ind+1<int(s.size()) || s[ind+1]=='='){      // s[ind+1]=='=' so we dont check it anymore
					if(s[ind]=='=')st.PUSH(a2==a1);else
					if(s[ind]=='>')st.PUSH(a2>=a1);else
					if(s[ind]=='<')st.PUSH(a2<=a1);else
					if(s[ind]=='!')st.PUSH(a2!=a1);else{
					if(s[ind]=='+')st.push(make_pair(b2,a2+=a1)),mp[b2]=a2,compare--;else	// a2 is changed and added back in map
					if(s[ind]=='-')st.push(make_pair(b2,a2-=a1)),mp[b2]=a2,compare--;else	// |----|
					if(s[ind]=='*')st.push(make_pair(b2,a2*=a1)),mp[b2]=a2,compare--;else	// |----|
					if(s[ind]=='/' && a1.top!=0)st.push(make_pair(b2,a2/=a1)),mp[b2]=a2,compare--;else // |----|
					goto err;
					}
				}else
				if(s[ind]=='>')st.PUSH(a2>a1);else
				if(s[ind]=='<')st.PUSH(a2<a1);else
				goto err;
			}


		}

		ind=n_ind;
		while(ind<int(s.size()) && (s[ind]==' ' || s[ind]=='\n' || s[ind]=='\0'))ind++;// increments ind every space or new line
	}// end while
	if(st.size()!=1)goto err;


	for(int i=25-int(s.size());i>=0;i--)s+=' ';// sets spacing for result
	if(compare==1){
		if(st.top().second.top==0)cout<<s<<" : false"<<endl;else
			cout<<s<<" : true"<<endl;
	}else{
		cout<<s<<" : "<<st.top().second;
		cout<<fixed<<setprecision(6)<<" (double "<<toDouble(st.top().second)<<")"<<endl;
	}


	return;


	err:
	for(int i=25-int(s.size());i>=0;i--)s+=' ';// sets spacing for result
		cout<<s<<" : error"<<endl;return;

	empty_line:
		cout<<"empty line"<<endl;return;
}// end solve

int main(int argc, char *argv[]){


	for(int i = 1; i < argc; i++) {// goes through the args
		string S;
		in.open(argv[i]);
		if(in.is_open()) {
			cout << argv[i] << " was opened successfully." <<endl;
		}
		else {
			cout << argv[i] << " was not opened successfully." <<endl;
		}
		while(getline(in,S)){// opens each given file
			solve(S);
		}
		in.close();

	}


	return 0;
}// end main
