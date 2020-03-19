	/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define LL long long
#define N 100000
#define MOD 1000000007
#define dd double

// typedef pair<int, int> pairs; 

int main()
{
	// pair<pair<int,int>,int> p;

	// p.first = make_pair(1,2);
	// p.second = 3;

	// cout << p.first.second;

	vector<pair<pair<int,int>,int>> v(5);

	for(int i=0;i<5;++i)
	{	
		v[i].first = make_pair(i+1,i+2);
		v[i].second = i+3;
	}

	


	sort(v.begin(), v.end(),[](auto const &a, auto const &b) { return a.second > b.second;});


	for(int i=0;i<5;++i)
	{
		cout <<"("<< v[i].first.first<<","<<v[i].first.second<<"),"<<v[i].second<<endl;
	}
	
	// sort(v.begin(), v.end(),
	// 	[](auto const &a, auto const &b) { return a > b; });

	// for(int i=0;i<v.size();++i)
	// 	cout << v[i]<<" ";

}

