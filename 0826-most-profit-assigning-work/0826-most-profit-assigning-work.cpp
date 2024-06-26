class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        priority_queue<pair<int, int>> pq;  //max heap of pairs
        
        // O(nlogn)
        for(int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.push({prof, diff});
        }

        sort(worker.begin(), worker.end(), greater<int>());  // O(mlogm)

        int i = 0;
        int totalProfit = 0;
        // O(m*log(n))
        while(i < m && !pq.empty()) {
            if(pq.top().second > worker[i]) {
                pq.pop();
            }
            else {
                totalProfit += pq.top().first;
                i++;
            }
        }

        return totalProfit;
    }
};