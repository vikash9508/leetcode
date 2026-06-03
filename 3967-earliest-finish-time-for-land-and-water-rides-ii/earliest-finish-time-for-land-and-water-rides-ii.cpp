class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long ans = LLONG_MAX;

        
        vector<pair<int,int>> water(m);
        for (int i = 0; i < m; i++) {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(water.begin(), water.end());

        vector<long long> prefMinDur(m);
        vector<long long> suffMinOpenPlusDur(m);

        prefMinDur[0] = water[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1],
                                (long long)water[i].second);
        }

        suffMinOpenPlusDur[m - 1] =
            (long long)water[m - 1].first + water[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffMinOpenPlusDur[i] =
                min(suffMinOpenPlusDur[i + 1],
                    (long long)water[i].first + water[i].second);
        }

        vector<int> waterStarts(m);
        for (int i = 0; i < m; i++) waterStarts[i] = water[i].first;

        for (int i = 0; i < n; i++) {
            long long A = (long long)landStartTime[i] + landDuration[i];

            int pos = upper_bound(waterStarts.begin(),
                                  waterStarts.end(), A)
                      - waterStarts.begin() - 1;

            long long best = LLONG_MAX;

            if (pos >= 0)
                best = min(best, A + prefMinDur[pos]);

            if (pos + 1 < m)
                best = min(best, suffMinOpenPlusDur[pos + 1]);

            ans = min(ans, best);
        }

        
        vector<pair<int,int>> land(n);
        for (int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        sort(land.begin(), land.end());

        vector<long long> prefMinDurLand(n);
        vector<long long> suffMinOpenPlusDurLand(n);

        prefMinDurLand[0] = land[0].second;
        for (int i = 1; i < n; i++) {
            prefMinDurLand[i] =
                min(prefMinDurLand[i - 1],
                    (long long)land[i].second);
        }

        suffMinOpenPlusDurLand[n - 1] =
            (long long)land[n - 1].first + land[n - 1].second;

        for (int i = n - 2; i >= 0; i--) {
            suffMinOpenPlusDurLand[i] =
                min(suffMinOpenPlusDurLand[i + 1],
                    (long long)land[i].first + land[i].second);
        }

        vector<int> landStarts(n);
        for (int i = 0; i < n; i++) landStarts[i] = land[i].first;

        for (int j = 0; j < m; j++) {
            long long B = (long long)waterStartTime[j] + waterDuration[j];

            int pos = upper_bound(landStarts.begin(),
                                  landStarts.end(), B)
                      - landStarts.begin() - 1;

            long long best = LLONG_MAX;

            if (pos >= 0)
                best = min(best, B + prefMinDurLand[pos]);

            if (pos + 1 < n)
                best = min(best, suffMinOpenPlusDurLand[pos + 1]);

            ans = min(ans, best);
        }

        return (int)ans;
    }
};