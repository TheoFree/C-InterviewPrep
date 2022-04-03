#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;


bool canSum(int target, vector<int> nums, map<int,bool> memo = {}){
	if(memo.find(target) != memo.end()) return memo[target];
	if(target == 0 ) return true;
	if(target > 0 ){
		for(auto num : nums){
			//cout<< target << ' ' << num << "\n";
			if (canSum(target - num, nums, memo)){
				memo[target] = true;       
				return true;
			}
		}
	}
	memo[target] = false;
	return false;


};

vector<int> howSum2(int target, vector<int> nums){ // My Solution
	for(auto num : nums){
		if(target - num == 0) return {num};
	}
	vector<int> ret = {};
	for(auto num : nums){
		if(target - num > 0){
			ret = howSum2(target -num,nums);
			ret.push_back(num);
			return ret;
		}
	}
	
	return {};
};

vector<int> howSum(int target, vector<int> nums, map<int,vector<int>> memo = {}){ // solution from dynamic programming lecture
	if(memo.find(target) != memo.end()) return memo[target];
	if(target == 0){
		memo[target] = {0};
		return {} ;
	}
	if(target < 0){
		return {-1};
	}
	int res = 0;
	vector<int> ret;
	for(auto num : nums){
		res = target - num;
		ret = howSum(res, nums, memo);
		if(ret.empty()||ret[0]!=-1){ 
			ret.push_back(num);
			return ret;
		}
	}
	return ret;
};


vector<int> bestSum(int target, vector<int> nums){ // My Solution
	/* 
		Base case: target = zero;
		Work: 
			Go through nums, subtract from target. If result < 0 skip, if result == 0 store, if result > 0 recurse. 

			After going through all nums, will have a collection of combinations that sum to current target, of which select the combination with the least elements.

		Work scales from full problem down to trivial problems.
	 */
	if( target == 0) return {};
	vector<vector<int>> temp = {};
	for( auto num : nums){
		if ( target - num == 0) temp.push_back({num});
		if ( target - num > 0) temp.push_back(bestSum(target-num, nums));
	}
	// get shortest length solution from temp
	vector<int> best = {};
	for( auto sol : temp) if (sol.size() < best.max_size()) best = sol;
	return best;
}