class Solution {
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        return is_traingle(p1,p2,p3) && is_traingle(p2,p3,p4) && is_traingle(p1,p2,p4);
    }

    bool is_traingle(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
        int d1 = pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2);
        int d2 = pow(p1[0]-p3[0],2) + pow(p1[1]-p3[1],2);
        int d3 = pow(p2[0]-p3[0],2) + pow(p2[1]-p3[1],2);
        if(d1 > d2 && d2 == d3 && d1 == 2*d2 ||
           d2 > d1 && d1 == d3 && d2 == 2*d1 ||
           d3 > d1 && d1 == d2 && d3 == 2*d1) {
            return true;
        }
        return false;
    }
};

/*
[2,2]
[2,1]
[1,2]
[1,0]
false

[2,2]
[2,1]
[1,2]
[1,0]
false
*/
