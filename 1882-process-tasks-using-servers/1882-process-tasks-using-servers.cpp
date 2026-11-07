
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> free;
        priority_queue<tuple<ll,int,int>,
            vector<tuple<ll,int,int>>, greater<>> busy;

        for (int i = 0; i < servers.size(); i++)
            free.push({servers[i], i});

        vector<int> ans;
        ll time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (ll)i);

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [end, w, id] = busy.top();
                busy.pop();
                free.push({w, id});
            }

            if (free.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [end, w, id] = busy.top();
                    busy.pop();
                    free.push({w, id});
                }
            }

            auto [w, id] = free.top();
            free.pop();

            ans.push_back(id);
            busy.push({time + tasks[i], w, id});
        }

        return ans;
    }
};
