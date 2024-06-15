class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
                // Min-heap to store projects by capital requirements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;
        // Max-heap to store profits of the projects we can afford
        priority_queue<int> maxProfitHeap;

        int n = profits.size();

        // Insert all projects into the min-heap
        for (int i = 0; i < n; i++) {
            minCapitalHeap.push({capital[i], profits[i]});
        }

        // Iterate at most k times
        for (int i = 0; i < k; i++) {
            // Transfer all projects we can afford to the max-heap
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= w) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            // If the max-heap is empty, no more projects can be afforded
            if (maxProfitHeap.empty()) {
                break;
            }

            // Add the most profitable project's profit to the current capital
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
    
};