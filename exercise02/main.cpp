#include <bits/stdc++.h>

#define sz(x) (int) (x).size()



#define ll long long int

#define ld long  double

#define TC 2

using namespace std;

template <typename T>
struct Point2D{
	T x,y;

	Point2D(){};

	Point2D(T _x ,T _y){
		x = _x;
		y = _y;
	}

	Point2D operator - (const Point2D &other) const{
		return Point2D(this->x - other.x , this->y - other.y);
	}
};

template<typename T>
int sign(T t){
	if(t > 0) return 1;
	if(t  == 0) return 0;
	return -1;
}

template<typename T>
int orientation(Point2D<T> & A ,Point2D<T>& B ,Point2D<T> & C){
	auto v1 = B - A;
	auto v2 = C - A;
	// v1.x v1.y
	// v2.x v2.y
	return sign(v1.x*v2.y - v1.y*v2.x); 
}



int prev(int i,int n){
	return (i - 1 + n)%n;
}
int next(int i , int n){
	return (i+1)%n;
}


template<typename T>
bool is_convex_handle_overflow(vector<Point2D<T>> &P){
	int n = sz(P);
	int orient = -2;
	for(int i = 0 ; i < n ; i++){
		Point2D<T> p = P[prev(i,n)];
	 	Point2D<T> ne = P[next(i,n)];
		if(orient == -2){
			orient = orientation(p,P[i],ne);
			continue;
		}
		if(orientation(p,P[i],ne) != orient) return false;
	}
	return true;
}

template <typename T>
bool is_convex(vector<vector<T>> const& P){
	if constexpr (is_same<T,int>::value){
		vector<Point2D<ll>> points(sz(P));
		for(int i = 0 ; i < sz(P) ; i++){
			Point2D<ll> p((ll) P[i][0] , (ll) P[i][1]);
			points[i] = p;
		}
		return is_convex_handle_overflow(points);
	}
	else{
		vector<Point2D<ld>> points(sz(P));
		for(int i = 0 ; i < sz(P) ; i++){
			Point2D<ld> p((ld) P[i][0] , (ld) P[i][1]);
			points[i] = p;
		}
		return is_convex_handle_overflow(points);
	}
	

}


int main(){
	vector<vector<int>> tc[TC] = {
		{ {2,2} , {1,5} , {3,8} , {9,7} , {7,3}},
		{ {1,1} , {1,5} , {4,4} , {5,7} , {8,2}}
	};

	for (int i = 0 ; i < TC ; i++){
		cout<<is_convex(tc[i])<<endl;
	}

    return 0;
}
