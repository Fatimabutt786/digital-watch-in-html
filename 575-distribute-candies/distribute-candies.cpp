class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        for(int candy:candyType){
            types.insert(candy);
        }
        int max_allowed=candyType.size()/2;
        return min((int)types.size(),max_allowed);
    }
};