class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        vector<int> ans;

        set<int> available_servers;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > busyServers;     //{finish time, serverID}

        vector<int> reqServed(k, 0);

        for(int i = 0; i < k; i++){
            available_servers.insert(i);
        }


        for(int i = 0; i < arrival.size(); i++){
            int time = arrival[i];

            while(!busyServers.empty() && busyServers.top().first <= time){
                int server = busyServers.top().second;
                busyServers.pop();
                available_servers.insert(server);
            }

            int target = i%k;
            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()) it = available_servers.begin();
            if(available_servers.empty()) continue;

            int targetServer = *it;
            available_servers.erase(it);
            busyServers.push({time+load[i], targetServer});

            reqServed[targetServer]++;
        }

        int maxBusyServer = *max_element(reqServed.begin(), reqServed.end());

        for(int j = 0; j < k; j++){
            if(reqServed[j] == maxBusyServer){
                ans.push_back(j);
            }
        }

        return ans;
    }
};