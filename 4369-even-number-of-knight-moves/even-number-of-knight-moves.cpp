class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        bool p1 = (start[0] + start[1])%2 ; // true => in white 
        bool p2 = (target[0] + target[1])%2; // true => in white ; falase => black

        return p1==p2;

    }
};