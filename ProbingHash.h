#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <time.h>
#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    int tableSize;
    vector<pair<EntryState,pair<K,V>>> table;

public:
//---------------------------------------------------------
    ProbingHash(int n = 11) {
    }
//---------------------------------------------------------
    ~ProbingHash() {
        this->clear();
    }
//---------------------------------------------------------
    int size() {
        int total = 0,iterator = 0;
        while (table.size() > iterator)
        {
            if(table[iterator].first == VALID)
            {
                total++;
            }
            iterator++;
        }
    }
//---------------------------------------------------------
    V operator[](const K& key) {
        return at(key);
    }
//---------------------------------------------------------
    bool insert(const std::pair<K, V>& pair) {
        inserthelper(pair.first, pair.second);
    }
    void inserthelper(K key, V, value)
    {
        if(!count(key))
        {
            int hashKey = hash(key);
            K TempKey = key;
            while(table[hashKey].first != EMPTY)
            {
                TempKey++;
                hashKey = hash[TempKey];
            }
            table[hashKey].first = valid;
            table[hashKey].second.first = key;
            table[hashKey].second.second = value;
        }
        else
        {
            erase(key);
            insertHelper(key, value);
        }
        if(load_factor() > .75)
        {
            rehash();
        }
    }
//---------------------------------------------------------
    void erase(const K& key) {
        int hashKey = hash[key];
        K tempKey = key;
        while(table[hashKey].fisrt != EMPTY)
        {
            if(table[hashKey.second.first == key])
            {
                table[hashKey] = NULL;
                return;
            }
            tempKey++;
            hashKey = hash[tempKey];
        }
        return;
    }
//---------------------------------------------------------
    void clear() {
        int iterator = 0;
        while( table.capacity() > iterator)
        {
            table[i].first = NULL;
            iterator++;
        }
        table.clear();
    }
//---------------------------------------------------------
    int bucket_count() {
        return table.capacity();
    }
//---------------------------------------------------------
    float load_factor() {
        int iterator = 0, Num = 0;
        float load;
        while (table.capacity() > iterator)
        {
            if(table[i].first != EMPTY)
            {
                Num++;
            }
            iterator++;
        }
        load = Num/bucket_count();
    }
//---------------------------------------------------------
    void rehash(int n)
    {
        int iterator = 0;
        tableSize = findNextPrime(n);
        vector<pair<K,V>> Nums;
        while(table.capacity() > iterator)
        {
            if(table[iterator].first != EMPTY)
            {
                Nums.push_back(talbe[iterator].second);
            }
        }
        clear();
        table.resize(tableSize);
        iterator = 0;
        while(Nums != iterator)
        {
            pair<K,V> i;
            insert(i);
            iterator++;
        }
    }
//---------------------------------------------------------
private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return 0;       
    }
    
};

#endif //__PROBING_HASH_H
