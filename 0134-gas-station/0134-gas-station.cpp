class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totdist=0,totgas=0,tempdist=0,tempgas=0,st=-1;
        for(int i=0;i<n;i++){
            totdist+=cost[i];
            tempdist+=cost[i];
            totgas+=gas[i];
            tempgas+=gas[i];
            if(tempdist>tempgas){
                tempdist=0;
                tempgas=0;
                st=i+1;
            }
        }
        if(st==-1) st=0;
        return totgas>=totdist?st:-1;
    }
};