#include<iostream>
#include<cmath>

using namespace std;

struct vectr{
	long double x, y;
	vectr(long double x_, long double y_){
		x = x_;
		y = y_;
	}
};

void print(vectr A){
	cout << A.x << " " << A.y << "\n";
}

vectr operator + (vectr A, vectr B){
	vectr C(A.x + B.x, A.y + B.y);
	return C;
}

vectr operator - (vectr A, vectr B){
	vectr C(A.x - B.x, A.y - B.y);
	return C;
}

long double operator * (vectr A, vectr B){
	return A.x*B.x + A.y*B.y;
}

long double operator % (vectr A, vectr B){
	return A.x*B.y - A.y*B.x;
}

vectr operator * (vectr A, long double k){
	vectr B(A.x*k, A.x*k);
	return B;
}

long double lenght(vectr A){
	return sqrt(A.x*A.x + A.y*A.y);
}

vectr norm(vectr A){
	vectr B(A.x/lenght(A), A.y/lenght(A));
	return B;
}
vectr rotate(vectr A, long double alpha){
	vectr B(A.x*cos(alpha) - A.y*sin(alpha), A.x*sin(alpha) + A.y*cos(alpha));
	return B;
}