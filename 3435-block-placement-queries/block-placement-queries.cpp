class Solution {
public:
    vector<int> seg;
    int MX = 50000;

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int L, int R, int node, int l, int r) {
        if (R < l || r < L)
            return 0;

        if (L <= l && r <= R)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(L, R, 2 * node, l, mid),
            query(L, R, 2 * node + 1, mid + 1, r)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MX);

        vector<int> present(MX + 1, 0);

        for (auto &q : queries) {
            if (q[0] == 1) {
                present[q[1]] = 1;
                obstacles.insert(q[1]);
            }
        }

        seg.assign(4 * (MX + 1), 0);

        int previousPos = -1;

        for (int pos : obstacles) {
            if (previousPos != -1) {
                update(pos, pos - previousPos, 1, 0, MX);
            }
            previousPos = pos;
        }

        vector<bool> ans;

        reverse(queries.begin(), queries.end());

        for (auto &q : queries) {

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int right = *it;

                --it;
                int left = *it;

                int best = query(0, left, 1, 0, MX);

                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
            else {

                int x = q[1];

                auto it = obstacles.find(x);

                auto prv = std::prev(it);
                auto nxt = std::next(it);

                update(*nxt, *nxt - *prv, 1, 0, MX);

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};