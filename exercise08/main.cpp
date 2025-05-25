#include <bits/stdc++.h>


#define ll long long int
#define ld long double

#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()


using namespace std;

template <typename T>
struct Point2D{
	T x,y;
	int id;
	int id_ord;
	Point2D(){}
	Point2D(T _x,T _y, int _id , int _id_ord = -1){
		x = _x;
		y = _y;
		id = _id;
		id_ord = _id_ord;
	}
	bool operator < (const Point2D<T> &other)const {
		return x < other.x || ( x == other.x && y < other.y);
	}
};

template <typename T>
bool comp_y(const Point2D<T> &A ,const Point2D<T>& B){
	return A.y < B.y || (A.y == B.y && A.x < B.x);
}

template <typename T>
T distance(const Point2D<T> &A ,const Point2D<T>& B){
	T dx = B.x - A.x;
	T dy = B.y - A.y;
	return dx*dx + dy*dy;
}


template <typename T>
struct Answer{
	Point2D<T> p1,p2;
	T d;
	Answer(){}
	Answer(Point2D<T> _p1 , Point2D<T> _p2 , T _d){
		p1 = _p1;
		p2 = _p2;
		d = _d;
	}
	bool operator < (const Answer<T> &o) const{
		return d < o.d || (d == o.d && p1.id < o.p1.id);
	}
};




template <typename T>
Answer<T> closest_points_r(int l , int r , const vector<Point2D<T>>& X , const vector<Point2D<T>> &Y){
	T inf  = numeric_limits<T>::max();
	
	if ( r - l + 1 <= 3){
		Answer ans = { Point2D<T>(0,0,INT_MAX) , Point2D<T>(0,0,INT_MAX) , inf};
		for(int i = l ; i <= r ; i++){
			for(int j = i+1; j <= r ; j++)
				ans = min(ans, {X[i] , X[j] , distance(X[i],X[j]) });
		}
		return ans;
	}
	
	int m = l + (r-l)/2;
	vector<Point2D<T>> yleft , yright;
	for(int i = 0 ; i < sz(Y) ; i++){
		if( Y[i].id_ord <= m ) yleft.push_back(Y[i]);
		else yright.push_back(Y[i]);
	}
	
	auto ans1 = closest_points_r(l,m,X,yleft);
	auto ans2 = closest_points_r(m+1,r,X,yright);
	auto ans = min(ans1,ans2);
	T delta = ans.d;
	vector<Point2D<T>> yp;
	for(int i = 0 ; i < sz(Y) ; i++){
		if( abs(Y[i].x - X[m].x) * abs(Y[i].x - X[m].x) <= delta){
				yp.push_back(Y[i]);
		}
	}
	
	for(int i = 0 ; i < sz(yp) ; i++){
		auto p = yp[i];
		for(int j = i+1; j < sz(yp) ; j++){
			if ( abs(yp[j].y - p.y) * abs(yp[j].y - p.y) <= delta )
				ans = min(ans , {yp[i] , yp[j] , distance(yp[i],yp[j])});
			else break;
		}
	}
	return ans;
}

template <typename T>
vector<int> closest_points_handle_overflow(vector<Point2D<T>> &points){
	int n = sz(points);
	auto x = points;
	sort(all(x));
	for(int i = 0 ; i < n ; i++) x[i].id_ord = i;
	auto y = x;
	sort(all(y) , comp_y<T>);
	auto ans = closest_points_r(0,n-1,x,y);
	int i = min(ans.p1.id , ans.p2.id);
	int j = max(ans.p1.id , ans.p2.id);
	return {i,j};
}

template <typename T>
vector<int> closest_points(vector<vector<T>> const& points){
	int n = sz(points);
	if constexpr ( is_same<T,int>::value ){
		vector<Point2D<ll>> pnts;
		pnts.reserve(n);
		for(int i = 0 ; i < n ; i++) pnts.push_back({ (ll) points[i][0] , (ll) points[i][1] , i});
		return closest_points_handle_overflow(pnts);
	}
	else{
		vector<Point2D<ld>> pnts;
		pnts.reserve(n);
		for(int i = 0 ; i < n ; i++) pnts.push_back({ (ld) points[i][0] , (ld) points[i][1] , i});
		return closest_points_handle_overflow(pnts);
	}
}

void test_virtual_judge(){
    int n; cin>>n;
	vector<vector<ll>> points(n , vector<ll>(2));
	for(int i  = 0 ; i < n ; i++){
		ll x,y; cin>>x>>y;
	    points[i][0] = x;
        points[i][1] = y;
	}
	auto ind = closest_points(points);
	Point2D<ll> p1 = { points[ind[0]][0] , points[ind[0]][1] , ind[0] , -1};
    Point2D<ll> p2 = { points[ind[1]][0] , points[ind[1]][1] , ind[1] , -1};

    ll ans = distance(p1,p2);
	cout<<ans<<"\n";
}

int main(){
	//test_virtual_judge();
    return 0;
}


