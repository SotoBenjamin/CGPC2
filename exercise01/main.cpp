#include <bits/stdc++.h>

using namespace std;


#define ll long long int
#define ld long double


template <typename T>
struct Point2D{
	T x,y;
	Point2D(){}
	Point2D(T _x , T _y){
		x = _x;
		y = _y;
	}
	Point2D operator - (const Point2D<T>& o) const{
		return Point2D(x - o.x , y - o.y);
	} 
};

template <typename T>
int sign(T t){
	if (t < 0) return -1;
	if (t == 0) return 0;
	return 1;
}

template<typename T>
int orientation(const Point2D<T> & A ,const Point2D<T>& B ,const Point2D<T> & C){
	auto v1 = B - A;
	auto v2 = C - A;
	// v1.x v1.y
	// v2.x v2.y
	return sign(v1.x*v2.y - v1.y*v2.x); 
}

template <typename T>
T dot_product(const Point2D<T> &A , const Point2D<T> &B){
	return A.x*B.x + A.y*B.y;
}

template <typename T>
bool is_in(const Point2D<T> &A,const Point2D<T> &B,const Point2D<T> &C){
	auto u = C-A;
	auto v = C-B;
	return sign(dot_product(u,v)) <= 0;
}

template <typename T>
bool intersection_handle_overflow(Point2D<T> &p1,Point2D<T> &p2,Point2D<T> &p3,Point2D<T> &p4){
	int o1 = orientation(p1,p2,p3);
	int o2 = orientation(p1,p2,p4);
	int o3 = orientation(p3,p4,p1);
	int o4 = orientation(p3,p4,p2);
	if( o1 == 0 && o2 == 0){
		return is_in(p1,p2,p3) || is_in(p1,p2,p4) || is_in(p3,p4,p1) 
			|| is_in(p3,p4,p2);
	}
	if (o1 != o2 && o3 != o4) return true;
	return false;
}

template <typename T>
bool intersection(T xa, T ya, T xb, T yb, T xc, T yc, T xd, T yd){
    if constexpr(is_same<T,int>::value){
        Point2D<ll> p1 = {xa,ya};
        Point2D<ll> p2 = {xb,yb};
        Point2D<ll> p3 = {xc,yc};
        Point2D<ll> p4 = {xd,yd};
        return intersection_handle_overflow(p1,p2,p3,p4);
    }
    else{
		Point2D<ld> p1 = {xa,ya};
    	Point2D<ld> p2 = {xb,yb};
    	Point2D<ld> p3 = {xc,yc};
    	Point2D<ld> p4 = {xd,yd};
    	return intersection_handle_overflow(p1,p2,p3,p4);
	}

}

void slv(){
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	bool f = intersection(x1,y1,x2,y2,x3,y3,x4,y4);
	if(f) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}

void test_virtual_judge(){
	int t; cin>>t;
	while(t--) slv();
}



int main(){
	//test_virtual_judge();
	return 0;
}
