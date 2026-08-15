class LFUCache {

    // frequency -> list of {key, value}
    // Front = least recently used
    // Back  = most recently used
    unordered_map<int, list<pair<int,int>>> freqList;

    // key -> {value, frequency, iterator inside freqList[frequency]}
    struct Node {
        int value;
        int freq;
        list<pair<int,int>>::iterator it;
    };

    unordered_map<int, Node> mpp;

    // Smallest frequency currently present
    int minFreq;

    int capacity;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {

        // key does not exist
        if (mpp.find(key) == mpp.end())
            return -1;

        // Get current information
        int value = mpp[key].value;
        int freq = mpp[key].freq;

        // Remove key from old frequency list
        freqList[freq].erase(mpp[key].it);

        // If old frequency list becomes empty
        // and it was the minimum frequency,
        // increase minFreq
        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        // Move key to frequency + 1
        freq++;

        // Insert at back
        // because it is now most recently used
        freqList[freq].push_back({key, value});

        // Store new iterator
        mpp[key].freq = freq;
        mpp[key].it = --freqList[freq].end();

        return value;
    }

    void put(int key, int value) {

        // Capacity 0
        if (capacity == 0)
            return;

        // Key already exists
        if (mpp.find(key) != mpp.end()) {

            int freq = mpp[key].freq;

            // Remove old position
            freqList[freq].erase(mpp[key].it);

            // If frequency list becomes empty
            if (freqList[freq].empty()) {
                freqList.erase(freq);

                if (minFreq == freq)
                    minFreq++;
            }

            // Updated key starts from frequency 1 higher
            freq++;

            freqList[freq].push_back({key, value});

            mpp[key].value = value;
            mpp[key].freq = freq;
            mpp[key].it = --freqList[freq].end();

            return;
        }

        // Cache is full
        if (mpp.size() == capacity) {

            // Least frequently used list
            auto &lst = freqList[minFreq];

            // Front = least recently used
            int keyToRemove = lst.front().first;

            lst.pop_front();

            // Remove from map
            mpp.erase(keyToRemove);

            // Remove empty frequency list
            if (lst.empty())
                freqList.erase(minFreq);
        }

        // New key always starts with frequency 1
        minFreq = 1;

        freqList[1].push_back({key, value});

        // Iterator to newly inserted node
        auto it = --freqList[1].end();

        mpp[key] = {value, 1, it};
    }
};