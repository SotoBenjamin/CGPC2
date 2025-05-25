#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define ld long double
using namespace std;

vector <ld> cross_product(ld Ax,ld Ay, ld Az , ld  Bx, ld By,ld Bz){
    vector<ld>  ans(3);
    ans[0] = Ay*Bz - By*Az;
    ans[1] = Bx*Az - Ax*Bz;
    ans[2] = Ax*By - Bx*Ay;
    return ans;   
}


ld distance(ld l1x,ld l1y,ld l1z,ld dx,ld dy,ld dz,ld px,ld py,ld pz){
    vector<ld> a = cross_product(px-l1x,py-l1y,pz-l1z,dx,dy,dz);
    return sqrtf(a[0]*a[0] + a[1]*a[1] + a[2]*a[2])/sqrtf(dx*dx + dy*dy + dz*dz);
}

double distance_point_to_line_3D( double p1x, double p1y, double p1z,  // punto P1
    double dx, double dy, double dz, // direccion
    double px, double py, double pz ){
    ld ans = distance(p1x,p1y,p1z,dx,dy,dz,px,py,pz);
    return (double) ans;
}


int main(){
    cout << fixed << setprecision(6);

    cout << "Test  1: " << distance_point_to_line_3D(0,0,0, 1,0,0, 0,1,0)
         << " (esperado: 1.000000)" << endl;
    cout << "Test  2: " << distance_point_to_line_3D(0,0,0, 1,0,0, 0,0,2)
         << " (esperado: 2.000000)" << endl;
    cout << "Test  3: " << distance_point_to_line_3D(0,0,0, 1,0,0, 5,3,4)
         << " (esperado: 5.000000)" << endl;
    cout << "Test  4: " << distance_point_to_line_3D(1,2,3, 0,1,0, 1,5,3)
         << " (esperado: 0.000000)" << endl;
    cout << "Test  5: " << distance_point_to_line_3D(1,2,3, 0,1,0, 2,5,6)
         << " (esperado: 3.162278)" << endl;
    cout << "Test  6: " << distance_point_to_line_3D(0,0,0, 2,0,0, 0,3,4)
         << " (esperado: 5.000000)" << endl;
    cout << "Test  7: " << distance_point_to_line_3D(0,0,0, 1,1,0, 1,-1,0)
         << " (esperado: 1.414214)" << endl;
    cout << "Test  8: " << distance_point_to_line_3D(0,0,0, 0,0,1, 2,3,0)
         << " (esperado: 3.605551)" << endl;
    cout << "Test  9: " << distance_point_to_line_3D(0,0,0, 0,0,1, -1,5,0)
         << " (esperado: 5.099020)" << endl;
    cout << "Test 10: " << distance_point_to_line_3D(0,0,0, 1,1,1, 1,0,0)
         << " (esperado: 0.816497)" << endl;
    cout << "Test 11: " << distance_point_to_line_3D(1,1,1, 1,2,3, 4,5,6)
         << " (esperado: 1.309307)" << endl;
    cout << "Test 12: " << distance_point_to_line_3D(2,2,2, -1,0,0, 0,2,2)
         << " (esperado: 0.000000)" << endl;
    cout << "Test 13: " << distance_point_to_line_3D(2,2,2, 0,-1,0, 2,0,2)
         << " (esperado: 0.000000)" << endl;
    cout << "Test 14: " << distance_point_to_line_3D(2,2,2, 0,0,-1, 2,2,1)
         << " (esperado: 0.000000)" << endl;
    cout << "Test 15: " << distance_point_to_line_3D(0,0,0, 1,2,2, 2,0,0)
         << " (esperado: 1.885618)" << endl;
    cout << "Test 16: " << distance_point_to_line_3D(0,0,0, 2,2,2, 1,1,3)
         << " (esperado: 1.632993)" << endl;
    cout << "Test 17: " << distance_point_to_line_3D(5,5,5, 3,0,4, 6,5,1)
         << " (esperado: 3.200000)" << endl;
    cout << "Test 18: " << distance_point_to_line_3D(-1,-1,-1, 1,1,1, 0,0,0)
         << " (esperado: 0.000000)" << endl;
    cout << "Test 19: " << distance_point_to_line_3D(0,0,0, 1,1,0, 1,1,0)
         << " (esperado: 0.000000)" << endl;
    cout << "Test 20: " << distance_point_to_line_3D(0,0,0, 0,1,1, 1,0,1)
         << " (esperado: 1.224745)" << endl;
    return 0;
}
