#include <bits/stdc++.h>

#define sz(x) (int) (x).size()
#define all(x) x.begin() , x.end()

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
ld area_handle_overflow(vector<Point2D<T>> &P){
    int n = sz(P);
    ld d = 0;
    ld iz = 0;
    for(int i = 0 ; i < n ; i++){
        //cout<<P[i].x<<"  "<<P[i].y<<endl;
        d += P[i].x * P[next(i,n)].y;
        iz += P[i].y * P[next(i,n)].x;
    }
    //cout<<d<<endl;
    //cout<<iz<<endl;
    return abs(d-iz)/2.0;
}


template<typename T>
vector<Point2D<ld>> intersection(vector<Point2D<T>>& P1, vector<Point2D<T>>& P2){
    /*Todo con double*/
    int n1 = sz(P1) , n2 = sz(P2);
    if (orientation(P1[0] , P1[1] , P1[2]) < 0) reverse(all(P1));

    if (orientation(P2[0] , P2[1] , P2[2]) < 0) reverse(all(P2));
    vector<Point2D<ld>> clip(n1);
    for(int i = 0 ; i < n1 ; i++) clip[i] = { (ld) P1[i].x , (ld) P1[i].y};
    vector<Point2D<ld>> out(n2);
    for(int i = 0 ; i < n2 ; i++) out[i] = {(ld) P2[i].x ,(ld) P2[i].y};

  

    for(int i = 0 ; i < n1 ; i++){
        Point2D<ld> A = clip[i];
        Point2D<ld> B = clip[next(i,n1)];
        vector<Point2D<ld>> input = move(out);
        out.clear();
        int m = sz(input);
        for(int j = 0 ; j < m ; j++){
            Point2D<ld> P = input[j];
            Point2D<ld> Q = input[next(j,m)];
            int op = orientation<ld>(A,B,P);
            int oq = orientation<ld>(A,B,Q);
            bool inp = (op >= 0);
            bool inq = (oq >= 0);
            if (inp && inq){
                //caso1 : añade Q
                out.push_back(Q);
            }
            else if(inp && !inq){
                //pq intersecta AB
                // caso 2 : se añade intersection
                ld rdx = Q.x - P.x, rdy = Q.y - P.y;
                ld sdx = B.x - A.x, sdy = B.y - A.y;
                ld den = rdx * sdy - rdy * sdx;
                ld num = (A.x - P.x) * sdy - (A.y - P.y) * sdx;
                ld t = num / den;
                out.push_back({P.x + t * rdx, P.y + t * rdy});
            }
            else if(!inp && inq){
                // caso3 : se añadirpa intersection luego Q
                ld rdx = Q.x - P.x, rdy = Q.y - P.y;
                ld sdx = B.x - A.x, sdy = B.y - A.y;
                ld den = rdx * sdy - rdy * sdx;
                ld num = (A.x - P.x) * sdy - (A.y - P.y) * sdx;
                ld t = num / den;
                out.push_back({P.x + t * rdx, P.y + t * rdy});
                out.push_back(Q);
            }
        } 
    }
    return out;
}

template <typename T>
double area_of_intersection(vector<vector<T>> const& vertices1, vector<vector<T>> const& vertices2){
    if constexpr (is_same<T,int>::value){
        vector<Point2D<ll>> P1(sz(vertices1));
        for(int i = 0 ; i < sz(vertices1) ; i++) P1[i] = Point2D<ll>((ll) vertices1[i][0], (ll) vertices1[i][1]);
        vector<Point2D<ll>> P2(sz(vertices2));
        for(int i = 0 ; i < sz(vertices2) ; i++) P2[i] = Point2D<ll>((ll) vertices2[i][0], (ll) vertices2[i][1]);
        auto inter = intersection(P1,P2);
        double ans = (double )area_handle_overflow(inter);
        return ans;
    }
    else{
        vector<Point2D<ld>> P1(sz(vertices1));
        for(int i = 0 ; i < sz(vertices1) ; i++) P1[i] = Point2D<ld>((ld) vertices1[i][0], (ld) vertices1[i][1]);
        vector<Point2D<ld>> P2(sz(vertices2));
        for(int i = 0 ; i < sz(vertices2) ; i++) P2[i] = Point2D<ld>((ld) vertices2[i][0], (ld) vertices2[i][1]);
        auto inter = intersection(P1,P2);
        double ans = (double )area_handle_overflow(inter);
        return ans;
    }
}




int main(){
    vector<vector<int>> A = {{0,0}, {5,0}, {5,5}, {0,5}};
    vector<vector<int>> B = {{2,-1}, {6,2}, {2,6}, {-1,2}};
    cout << fixed << setprecision(6) << area_of_intersection(A, B) << "\n";
    return 0;
}
