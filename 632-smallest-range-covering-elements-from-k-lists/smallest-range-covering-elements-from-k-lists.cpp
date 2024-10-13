class Solution {
public:
    class node{
        public:
        int data;
        int row;
        int col;

        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
    };
    class compare{
        public:
        bool operator()(node* a, node* b){
            return a->data>b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> minHeap;
        for(int i = 0; i< nums.size(); i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            minHeap.push(new node(element, i, 0));
        }

        int s = mini, e = maxi;
        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;

            if(maxi-mini < e-s){
                s = mini;
                e = maxi;
            }
            if(temp->col+1 < nums[temp->row].size()){
                maxi = max(maxi, nums[temp->row][temp->col+1]);
                minHeap.push(new node(nums[temp->row][temp->col+1], temp->row, temp->col+1));

            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(s);
        ans.push_back(e);
        return ans;
    }
};