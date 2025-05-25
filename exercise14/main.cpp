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
T area(const Point2D<T> & A ,const Point2D<T>& B ,const Point2D<T> & C){
	auto v1 = B - A;
	auto v2 = C - A;
	// v1.x v1.y
	// v2.x v2.y
	return  abs(v1.x*v2.y - v1.y*v2.x); 
}






int pe(int i,int n){
	return (i - 1 + n)%n;
}
int ne(int i, int n){
	return (i+1)%n;
}



template<typename T>
struct Node{
    T A;
    int id;
    int version;
    Node(){}
    Node(T _A,int _id,int _version){
        A = _A;
        id = _id;
        version = _version;
    }

    bool operator > (const Node& o) const {
        return A > o.A || (A == o.A && id > o.id);
    }
};

template <typename T>
vector<bool> triangles_based_simplification_handle_overflow(vector<Point2D<T>> &P, int N){
    int n = sz(P);
    vector<int> prev(n);
    vector<int> next(n);
    prev[0] = n-1 , next[n-1] = 0;
    for(int i = 1 ; i < n  ; i++)   prev[i] = i-1;
    for(int i = 0 ; i < n - 1; i++) next[i] = i+1;
    priority_queue<Node<T> , vector<Node<T>> , greater<> > pq;
    for(int i = 0 ; i < n ; i++){
        T A = area(P[prev[i]],P[i],P[next[i]]);
        pq.push({A,i,1});
    }
    vector<int> ver(n,1);
    vector<bool> remove(n,false);
    int cnt = 0;
    int max_remove = n - N;
    while(cnt < max_remove && !pq.empty()){
        Node<T> curr = pq.top();
        pq.pop();
        int i = curr.id;
        T A = curr.A;
        int v = curr.version;
        if( ver[i] != v || remove[i]) continue;
        remove[i] = true;
        int j = prev[i];
        int k = next[i];
        next[j] = k;
        prev[k] = j;
        Node<T> n1 = { area( P[prev[j]] , P[j] , P[next[j]] ), j , ver[j] + 1};
        ver[j] ++;
        Node<T> n2 = {area ( P[prev[k]] , P[k] , P[next[k]] ) , k , ver[k] + 1};
        ver[k]++;
        cnt++;
        pq.push(n1);
        pq.push(n2);
    }
    return remove;
}


template <typename T>
vector<vector<T>> triangles_based_simplification(vector<vector<T>> const& vertices, int N){
    if constexpr(std::is_same<T,int>::value){
        int n = sz(vertices);
        vector<Point2D<ll>> p(n);
        for(int i = 0 ; i < n ; i++){
            p[i] = { (ll) vertices[i][0] , (ll) vertices[i][1] };
        }
        vector<vector<int>> ans;
        vector<bool> re = triangles_based_simplification_handle_overflow(p, N);
        for(int i = 0 ; i < n ; i++){
            if(!re[i])  ans.push_back({ (ll) p[i].x , (ll) p[i].y});
        }
        return ans;
    }
    else{
        int n = sz(vertices);
        vector<Point2D<ld>> p(n);
        for(int i = 0 ; i < n ; i++){
            p[i] = { (ld) vertices[i][0] , (ld) vertices[i][1] };
        }
        vector<vector<double>> ans;
        vector<bool> re = triangles_based_simplification_handle_overflow(p, N);
        for(int i = 0 ; i < n ; i++){
            if(!re[i])  ans.push_back({ (ld) p[i].x ,(ld) p[i].y });
        }
        return ans;
    }
}


void test1(){
    vector<vector<int>> polygon = {
        {0,0}, {1,0}, {2,0}, {3,0},
        {3,1}, {3,2},
        {2,2}, {1,2}, {0,2},
        {0,1}
    };
    int N = 4;  

    auto simplified = triangles_based_simplification<int>(polygon, N);

    cout << "Resultado simplificado (" << simplified.size() << " vértices):\n";
    for (auto &pt : simplified) {
        cout << "(" << pt[0] << ", " << pt[1] << ")\n";
    }
}


int main(){
    
    return 0;
}
