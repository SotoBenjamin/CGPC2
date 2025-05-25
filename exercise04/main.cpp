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
bool insise_polygon_handle_overflow(const vector<Point2D<T>> &vertices,const Point2D <T> &p){
    int n = sz(vertices);
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        auto p1 = vertices[i];
        auto p2 = vertices[next(i,n)];
        if (p1.y == p2.y) continue;
        if( p.y >= min(p1.y,p2.y) && p.y < max(p1.y,p2.y)){
            Point2D<T> pmin = min(p1,p2),pmax = max(p1,p2);
            if (orientation(pmin,pmax,p) == 0 && is_in(pm1,pmax,p) ){
				return true; // in the boundary
			}
            if( orientation(pmin,pmax,p) >= 0){
                cnt++;
            }
        } 
    }
    return cnt % 2 == 1;
}


template <typename T>
bool insise_polygon(vector<vector<T>> const& vertices, T px, T py){
    if constexpr (is_same<T,int>::value){
        Point2D<ll> p( (ll) px, (ll) py);
        vector<Point2D<ll>> vert(sz(vertices));
        for(int i = 0 ; i < sz(vertices) ; i++) vert[i] = Point2D<ll>((ll) vertices[i][0], (ll) vertices[i][1]);
        return insise_polygon_handle_overflow(vert , p);
    }
    else{
        Point2D<ld> p( (ld) px, (ld) py);
        vector<Point2D<ld>> vert(sz(vertices));
        for(int i = 0 ; i < sz(vertices) ; i++) vert[i] = Point2D<ld>((ld) vertices[i][0], (ld)vertices[i][1]);
        return insise_polygon_handle_overflow(vert , p);
    }
}



template <typename T>
bool insise_triangle(vector<vector<T>> const& vertices, T px, T py){
    return insise_polygon(vertices,px,py);
}

int main(){
    

    return 0;
}


