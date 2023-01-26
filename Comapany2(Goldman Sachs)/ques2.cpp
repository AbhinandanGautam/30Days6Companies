class Solution {
public:
    float dis(vector<int> &x, vector<int>&y){
        int x1 = x[0];
        int y1 = x[1];
        int x2 = y[0];
        int y2 = y[1];

        float dx = x2-x1;
        float dy = y2-y1;

        return sqrt((dx*dx)+(dy*dy));
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4 ){
            return false;
        }

        float d1 = dis(p1,p2);
        float d2 = dis(p1,p3);
        float d3 = dis(p1,p4);

        if(d1!=d2 && d2!=d3 && d1!=d3){
            return false;
        }

        if(d1==d2){
            float side = d1;
            float diagnol = d3;

            float d34 = dis(p3,p4);
            float d32 = dis(p3,p2);
            float d24 = dis(p2,p4);

            if(d34==side && d24==side && d32==diagnol){
                return true;
            }
        }
        else if(d2==d3){
            float side = d2;
            float diagnol = d1;

            float d34 = dis(p3,p4);
            float d32 = dis(p3,p2);
            float d24 = dis(p2,p4);

            if(d24==side && d32==side && d34==diagnol){
                return true;
            }
        }
        else if(d1==d3){
            float side = d1;
            float diagnol = d2;

            float d34 = dis(p3,p4);
            float d32 = dis(p3,p2);
            float d24 = dis(p2,p4);

            if(d34==side && d32==side && d24==diagnol){
                return true;
            }
        }

        return false;
    }
};