class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(), deck.end());

        int n = deck.size();

        queue<int> q;

        for(int i=0;i<n;i++)
            q.push(i);

        vector<int> ans(n);

        for(int card : deck)
        {
            int idx = q.front();
            q.pop();

            ans[idx] = card;

            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};