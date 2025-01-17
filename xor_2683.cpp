class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xo=0;
        for(int i:derived){
            xo^=i;
        }
        return xo==0;
    }
};