
#include <vector>
#include <stdexcept>
 

using std::vector;
using std::pair;

#include "Hash.h"

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};



template<typename K, typename V>
class ProbingHash : public Hash<K, V> {
private:
    vector<pair<K, V>> table;
    vector<EntryState> state;
    int count = 0;

public:
    ProbingHash(int n = 101): table(n), state(n,EMPTY), count(0) {
        
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return count;
    }

    V operator[](const K& key) {
        int index = hash(key);


        while (state[index] != EMPTY)
        {
            if (state[index] == VALID && table[index].first == key)
            {
                return table[index].second;
            }
            index = (index + 1) % table.size();

        }
        return 0;

    }

    bool insert(const pair<K, V>& pair) {

        if (load_factor() >= 0.75) {
            rehash();
        }

        int bucket = hash(pair.first);


        while (state[bucket] == VALID)
        {
            if (table[bucket].first == pair.first)
            {
                table[bucket].second = pair.second;
                return false;
            }
            bucket = (bucket + 1) % table.size();
        }

        return true;
    }

    void erase(const K& key) {


        auto index = hash(key);

        while (state[index] != EMPTY)
        {
            if (state[index] == VALID && table[index].first == key)
            {
                state[index] = DELETED;
                count--;
                return;
            }
            index = (index + 1) % table.size();
        }



    }

    void clear() {
        table.clear();
        count = 0;
    }

    int bucket_count() {
        return table.size();
    }

    float load_factor() {
        return static_cast<float>(count) / table.size();
    }

private:
    int findNextPrime(int n) {
        while (!isPrime(n)) {
            n++;
        }
        return n;
    }

    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    int hash(const K& key) {
        return std::hash<K>{}(key) % table.size();
    }

    void rehash() {
        int new_size = findNextPrime(table.size() * 2);
        new_size = findNextPrime(new_size);
        vector<pair<K, V>> temp_t = table;
        vector<EntryState> temp_state = state;


        table.clear();
        table.resize(new_size);
        state.clear();
        state.resize(new_size, EMPTY);
        count = 0;

        for (int i = 0; i < temp_t.size(); i++)
        {
            if (temp_state[i] == VALID)
            {
                insert(temp_t[i]);
            }
        }


    }

   
};
