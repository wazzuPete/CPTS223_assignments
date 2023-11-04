#pragma once
#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

#include <vector>
#include <list>
#include <stdexcept>
#include <cmath>

#include "Hash.h"

using std::vector;
using std::list;
using std::pair;






template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    vector<list<pair<K, V>>> table;

    int count = 0;

public:
    ChainingHash(int n = 11) {
        table.resize(n);
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return count;
    }

    V operator[](const K& key) {
        int index = hash(key);

        for (auto& item : table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }

        table[index].emplace_back(key, V{});
        count++;
        return table[index].back().second;
    }

    bool insert(const std::pair<K, V>& pair) {
        auto& bucket = table[hash(pair.first)];

        for (auto& item : bucket) {
            if (item.first == pair.first) {
                item.second = pair.second;
                return false;
            }
        }

        bucket.emplace_back(pair.first, pair.second);
        count++;

        if (load_factor() > 0.75) {
            rehash();
        }

        return true;
    }

    void erase(const K& key) {
        auto index = hash(key);
        for (auto temp = table[index].begin(); temp != table[index].end(); ++temp) {
            if (temp->first == key) {
                table[index].erase(temp);
                count--;
                return;
            }
        }
    }

    void clear() {
        table.clear();
        table.resize(11); // Reset the table to its initial size
        count = 0;
    }

    int bucket_count() {
        return table.size();
    }

    float load_factor() {
        return static_cast<float>(count) / table.size();
    }

private:
    void rehash() {
        vector<list<pair<K, V>>> oldTable = table;
        table.clear();
        table.resize(findNextPrime(oldTable.size() * 2));
        count = 0;
        for (auto& bucket : oldTable) {
            for (auto& item : bucket) {
                insert(item);
            }
        }
    }

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
};

#endif
