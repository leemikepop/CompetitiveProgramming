#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
	string line;
    while(getline(cin, line)){
    	stringstream ss(line);
    	vector<pair<double, double>> coor = {};
    	pair<double, double> dup;	
  		for(int i = 0; i < 4; ++i){
  			pair<double, double> p;
  			ss >> p.first >> p.second;
  			vector<pair<double, double>>::iterator it = find(coor.begin(), coor.end(), p);
  			if(it != coor.end()){
  				dup = p;
  				coor.erase(it);
  			}else{
  				coor.push_back(p);
  			}	
  		}
  		pair<double, double> fourth_p;
  		fourth_p.first = coor[0].first + coor[1].first - dup.first;
  		fourth_p.second = coor[0].second + coor[1].second - dup.second;
  		cout << fixed << setprecision(3) << fourth_p.first << " " << fixed << setprecision(3) << fourth_p.second << endl;
 	 }
  	return 0;
}

/*
0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145
0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
0.000 0.000 0.000 1.000 1.000 1.000 0.000 1.000
0.000 1.000 0.000 0.000 0.000 1.000 1.000 1.000
0.000 1.000 0.000 0.000 1.000 1.000 0.000 1.000
0.000 0.000 10.000 10.000 10.000 -10.000 0.000 0.000
0.000 0.000 10.000 10.000 10.000 -9.876 0.000 0.000
11.111 22.222 33.333 44.444 11.111 22.222 -33.333 -44.444
5.384 6.284 10.333 8.777 5.384 6.284 15.111 -0.877
3.039 -777.666 -50.000 -30.000 -50.000 -30.000 -49.000 8000
3895.102 3029.999 2.212 3.343 2.212 3.343 4939.888 2016.777
1234.567 7654.321 2345.678 8765.432 -1.000 -2.090 1234.567 7654.321
-4718.901 3049.141 -4869.609 3556.058 -4718.901 3049.141 9376.260 -8396.750
-1857.015 -1618.166 -1487.384 648.181 -2660.848 -6343.281 -1857.015 -1618.166
*/