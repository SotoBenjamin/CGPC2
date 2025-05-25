#include <bits/stdc++.h>

#define ll long long int

#define MOD 1000000007

using namespace std;


ll catalan(int n){
    if (n <= 0) return 0;
    vector<ll> dp(n+1);
    dp[0] = 1;
    // C[i] = (4i - 2)*C[i-1]/(i+1)
    // devemos calcular los inversos en modulo MOD hasta (i+1) (denominador)
    vector<ll> inv(n+2);
    inv[1] = 1;
    for(int i = 2 ; i <= n+1 ; i++){
        inv[i] = MOD - (MOD/i)*inv[MOD % i] % MOD;
    }

    //recurrencia de catalan
    for(int i = 1 ; i <= n ; i++){
        ll factor = (4*i -2) % MOD;
        dp[i] = dp[i-1] * factor % MOD * inv[i+1] % MOD; 
    }
    return dp[n];
}

int num_of_triangularions(int n){
    int ans = catalan(n-2);
    return ans;
}

void test() {
    assert(num_of_triangularions(1)  == 0);
    assert(num_of_triangularions(2)  == 0);
    assert(num_of_triangularions(3)  == 1);
    assert(num_of_triangularions(4)  == 2);
    assert(num_of_triangularions(5)  == 5);
    assert(num_of_triangularions(6)  == 14);
    assert(num_of_triangularions(7)  == 42);
    assert(num_of_triangularions(8)  == 132);
    assert(num_of_triangularions(10)  == 1430);
    assert(num_of_triangularions(20)  == 477638700);
    assert(num_of_triangularions(1000) == 76856686);
}


int main(){
    //tests();
    return 0;
}