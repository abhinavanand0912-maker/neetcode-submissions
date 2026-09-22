class CountSquares {
public:
    CountSquares() {
        
    }
    unordered_map<int,unordered_map<int,int>> rows;
    void add(vector<int> point) {
        int x=point[0];
        int y=point[1];
        rows[y][x]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        for(auto &p : rows[y]){
            int x2=p.first;
            if(x2==x) continue;
            int side=abs(x2-x);
            int y1 = y + side;
            ans += rows[y][x2] * rows[y1][x] * rows[y1][x2];
            int y2 = y - side;
            ans += rows[y][x2] * rows[y2][x] * rows[y2][x2];
        }
        return ans;
    }
};
