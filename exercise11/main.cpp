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
		return Point2D(x - other.x , y - other.y);
	}
	
	bool operator < (const Point2D &other) const{
		return y < other.y || (y == other.y && x < other.x);
	}
};

template<typename T>
int sign(T t){
	if(t > 0) return 1;
	if(t  == 0) return 0;
	return -1;
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



int prev(int i,int n){
	return (i - 1 + n)%n;
}
int next(int i, int n){
	return (i+1)%n;
}

template<typename T>
T area_handle_overflow(vector<Point2D<T>> &P){
    int n = sz(P);
    T d = 0;
    T iz = 0;
    for(int i = 0 ; i < n ; i++){
        //cout<<P[i].x<<"  "<<P[i].y<<endl;
        d += P[i].x * P[next(i,n)].y;
        iz += P[i].y * P[next(i,n)].x;
    }
    //cout<<d<<endl;
    //cout<<iz<<endl;
    return abs(d-iz);
}

template <typename T>
double area(vector<vector<T>> const& vertices){
    if constexpr (is_same<T,int>::value){
        vector<Point2D<ll>> vert(sz(vertices));
        for(int i = 0 ; i < sz(vertices) ; i++) vert[i] = Point2D<ll>((ll) vertices[i][0], (ll) vertices[i][1]);
        double ans = (double )area_handle_overflow(vert);
        return ans/2.0;
    }
    else{
        vector<Point2D<ld>> vert(sz(vertices));
        for(int i = 0 ; i < sz(vertices) ; i++) vert[i] = Point2D<ld>((ld) vertices[i][0], (ld)vertices[i][1]);
        double ans = (double) area_handle_overflow(vert);
        return ans/2.0;
    }
}

void test1(){
    vector<vector<int>> tc[TC] = {
        { {2,2} ,{1,6} , {5,8} , {7,6} , {10,6} , {7,3} },
        { {2,2} ,{1,6} , {5,8} , {7,6} , {10,6} , {7,3} }
    };
    for(int i = 0 ; i < TC ; i++){
        cout<<area(tc[i])<<endl;
    }
}

void test_virtual_judge(){
    int n; cin>>n;
    vector<Point2D<ll>> P(n);
    for(int i  = 0 ; i < n ; i++){
        ll x,y; cin>>x>>y;
        P[i] = {x,y};
    }
    ll ans = area_handle_overflow(P);
    cout<<ans<<"\n";
}

int main(){
    //test1();
    //test_virtual_judge();
    return 0;
}
