class Solution {
public:
    void backtrack(vector<int>& candidates, int index, int target,
                   vector<int>& combination,
                   vector<vector<int>>& combinations) {
        if (target < 0 || index == candidates.size()) return;

        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
    
        backtrack(candidates, index + 1, target, combination, combinations);
        combination.push_back(candidates[index]);
        backtrack(candidates, index, target - candidates[index],
                  combination, combinations);
        combination.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        backtrack(candidates, 0, target, combination, combinations);
        return combinations;
    }
};