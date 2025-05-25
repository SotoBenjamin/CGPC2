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
ld cross(const Point2D<T> & A ,const Point2D<T>& B ,const Point2D<T> & C){
	auto v1 = B - A;
	auto v2 = C - A;
	// v1.x v1.y
	// v2.x v2.y
	return (ld) v1.x*v2.y - v1.y*v2.x; 
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
ld dist(const Point2D<T>& A,const Point2D<T> &B, const Point2D<T> &P){
    ld ans = cross(A,B,P);
    auto u = B-A;
    ans = ans*ans/(u.x*u.x + u.y*u.y);
    return ans;
}


//l : start
//r: end
template<typename T> 
void douglas_peucker_r(vector<Point2D<T>>& pnts , int l ,int r ,vector<int>& keep , double epsilon){
    if (r-l < 2) return;
    auto A = pnts[l];
    auto B = pnts[r];
    int j = l;
    ld max_dist = 0;
    for(int i = l+1 ; i < r ; i++){
        auto C = pnts[i];
        ld current_d = dist(A,B,C);
        if (current_d > max_dist){
            j = i;
            max_dist = current_d;
        }
    }

    if (max_dist > epsilon*epsilon){
        keep[j] = 1;
        douglas_peucker_r(pnts,l,j,keep,epsilon);
        douglas_peucker_r(pnts,j,r,keep,epsilon);
    } 

}


// devuelve los indices de los que sobreviven
template<typename T> 
vector<int> douglas_peucker_handle_overflow(vector<Point2D<T>>& pnts , double epsilon){
    // llama al recursivo
    int n = pnts.size();
    vector<int> keep(n,0);
    keep[0] = 1 , keep[n-1] = 1;
    douglas_peucker_r(pnts,0,n-1,keep,epsilon);
    vector<int> ind;
    for(int i = 0 ; i < n ; i++) if(keep[i]) ind.push_back(i);
    return ind;
}


template <typename T>
vector<vector<T>> douglas_peucker(vector<vector<T>> const& vertices, double epsilon){
    int n = vertices.size();

    if (epsilon == 0) return vertices;

    if constexpr (is_same<T,int>::value){
        vector<Point2D<ll>> p(n);
        for(int i = 0 ; i < n ; i++) p[i] = {(ll) vertices[i][0] , (ll) vertices[i][1]};
        auto ind = douglas_peucker_handle_overflow(p,epsilon);
        vector<vector<int>> ans;
        for(auto& i : ind){
            ans.push_back(vertices[i]);
        }
        return ans;
    }
    else{
        if(epsilon == 0) return vertices;
        vector<Point2D<ld>> p(n);
        for(int i = 0 ; i < n ; i++) p[i] = {(ld) vertices[i][0] , (ld) vertices[i][1]};
        auto ind = douglas_peucker_handle_overflow(p,epsilon);
        vector<vector<double>> ans;
        for(auto& i : ind){
            ans.push_back(vertices[i]);
        }
        return ans;
    }
}


int main(){
     
    
   

    return 0;
}
