/*
 * Rational.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include "Rational.h"

using namespace std;

Rational normalize(long long TOP,long long BOT){
	long long gc=__gcd(TOP,BOT);	   //  __gcd(x,y)  is a built-in function in #include<algorithm>
	TOP/=gc;					// which find greatest common divisor of x and y using euclid algorithm
	BOT/=gc;
	if(BOT<0)TOP*=-1,BOT*=-1;

	return Rational(TOP,BOT);
}

Rational::~Rational() {

}

Rational::Rational() {
	top = 0;
	bot = 1;
}

Rational::Rational(const int num, const int denom) {
	top = num;bot = denom;
	if(bot==0){
		cout<<"ERROR"<<endl;
		top=bot=0;
		return;
	}
	int gc=__gcd(top,bot);
	top/=gc;bot/=gc;
	if(bot<0)top*=-1,bot*=-1;
}

Rational::Rational(const int wholeNumber) {
	top = wholeNumber;
	bot = 1;
}

Rational::Rational(const Rational &a) {
	top = a.top;
	bot = a.bot;
}

ostream& operator<<(ostream& out, const Rational& rat) {
	out << rat.top << '/' << rat.bot;
	return out;
}
int k=0;
istream& operator>>(istream& in,Rational& rat) {
	string s;

	in>>s;

	int ind=s.find('/');

	if(ind==-1){
		rat.top=atoi(s.c_str());
		rat.bot=1;
		return in;
	}

	int TOP=0,BOT=0;


	for(int i=0;i<ind;i++){
		TOP=TOP*10+s[i]-'0';
	}
	for(int i=ind+1;i<int(s.size());i++){
		BOT=BOT*10+s[i]-'0';
	}
	Rational et=normalize(TOP,BOT);
	rat=et;


	return in;
}

Rational Rational::operator+(const Rational &rat){
	int TOP=bot*rat.top+top*rat.bot;
	int BOT=bot*rat.bot;

	return normalize(TOP,BOT);
}
Rational Rational::operator-(const Rational &rat){

	Rational x(-rat.top,rat.bot);
	return (*this+x);
}
Rational Rational::operator*(const Rational &rat) {
	long long TOP = top * rat.top;
	long long BOT = bot * rat.bot;

	return normalize(TOP, BOT);
}
Rational Rational::operator/(const Rational &rat){
	long long TOP = top * rat.bot;
	long long BOT = bot * rat.top;

	return normalize(TOP, BOT);
}
int Rational::operator==(const Rational &rat) {
	return (top == rat.top && bot == rat.bot);
}
int Rational::operator!=(const Rational &rat) {
	return (top != rat.top || bot != rat.bot);
}
int Rational::operator>(const Rational &rat) {
	return (top*rat.bot > bot*rat.top);
}
int Rational::operator<(const Rational &rat) {
	return (top*rat.bot < bot*rat.top);
}
int Rational::operator>=(const Rational &rat) {
	return ((*this==rat) || (*this>rat));
}
int Rational::operator<=(const Rational &rat) {
	return ((*this==rat) || (*this<rat));
}
void Rational::operator=(Rational &rat){
	top=rat.top;
	bot=rat.bot;
}
Rational Rational::operator+=(Rational &rat){
	Rational x=(*this)+rat;
	top=x.top;
	bot=x.bot;

	return (*this);
}
double Rational::toDouble(const Rational &rat) {
	return (double)(rat.top)/(double)(rat.bot);
}
int main(){

	Rational v=Rational(3,5),vv;
	Rational j=Rational(2,3);
	Rational jj=Rational(9,3);

/*
			cout<<jj<<" !"<<endl;
	cout<<v<<" =   "<<j<<"  -  "<<((j)!=(v))<<" <---"<<endl;

	cout<<"!"<<endl;*/
	cin>>vv;
	cout<<"!"<<endl;
	vv+=v;
	cout<<vv<<endl;


	return 0;
}
