#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    
private:
	int size;
	int cur_size;
	int minFrequency;
	unordered_map<int, list<pair<int,int>>> cache;
	unordered_map<int, pair<int, list<pair<int,int>>::iterator>> it;
    
	void updateFreq(int key) {
		int freq = it[key].first;
		auto iter = it[key].second;
		int val = iter->second;
		it[key].first++;
		cache[freq].erase(iter);
		cache[freq + 1].push_back({key, val});
		it[key].second = --cache[freq + 1].end();
        
		if(cache[minFrequency].empty()) {
            minFrequency++;
        }
	}
    
public:
	LFUCache(int capacity) {
		size = capacity;
		cur_size = 0;
		minFrequency = 0;
	}

	int get(int key) {
		if (it.find(key) == it.end()) {
			return -1;
		}
        
		updateFreq(key);
		return it[key].second->second;
	}

	void put(int key, int value) {
		if (size == 0) {
            return;
        }
        
		if (it.find(key) != it.end()) {
			it[key].second->second = value;
			updateFreq(key);
		} else {
			if (cur_size == size) {
				int keyToRemove = cache[minFrequency].front().first;
				cache[minFrequency].pop_front();
				it.erase(keyToRemove);
			} else {
                cur_size++;
            }
            
			cache[1].push_back({key, value});
			it[key] = make_pair(1, --cache[1].end());
			minFrequency = 1;
		}
	}
};
