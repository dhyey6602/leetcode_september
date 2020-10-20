class Solution {
public:
    bool isRobotBounded(string instructions) {
        char direction='N';
        unordered_map<char,char> left{{'N','W'},{'S','E'},{'W','S'},{'E','N'}};
        unordered_map<char,char> right{{'N','E'},{'S','W'},{'W','N'},{'E','S'}};
        map<char,vector<int>> move{{'N',{0,1}},{'S',{0,-1}},{'E',{1,0}},{'W',{-1,0}}};
        int x=0,y=0;
        for(char i:instructions)
        {
            if(i=='L')
                direction=left[direction];
            else if(i=='R')
                direction=right[direction];
            else
            {
                x+=move[direction][0];
                y+=move[direction][1];
            }
        }
        return((x==0 && y==0) || direction!='N');
    }
};
