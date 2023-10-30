/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <time.h>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    vector<list<pair<K,V>>> table;
    int tableSize;
public:
//--------------------------------------------------------- Constructor
    ChainingHash(int n = 11) {
        tableSize = n;
        table.resize(findNextPrime(n),list<pair<K,V>>());
    }
//--------------------------------------------------------- Function #1 deconstructor
    ~ChainingHash() {
        this->clear();
    }
//--------------------------------------------------------- Function #2 get size
    int size() {
        int total = 0, iterator = 0;
        while(table.capacity() > iterator)
        {
            total++;
            ++iterator;
        }
        return -1;
    }
//--------------------------------------------------------- Function #3 v operator
    V operator[](const K& key) {
        return at[key];
    }
//------------------------------------------------------- Function #4 insert/insert helper
    bool insert(const std::pair<K, V>& pair) {
        insertHelper(pair.first,pair.second);
    }
    void insertHelper(K Key,V value)
    {
        if(!count(key))
        {
            int HashKey = hash(key);
            table[HashKey].insertHelper(Key,Value);
        }
        else
        {
            erase(key);
            insertHelper(key,value);
        }
        if(load_factor() > .75)
        {
            rehash();
        }
    }
//------------------------------------------------------- Function #5 erase
    void erase(const K& key) {
        int HashKey = Hash[key], iterator;
        list<pair<K,V>> & TempList = table[HashKey];
        iterator = TempList.begin();
        for(pair<K,V> p : TempList)
        {
            if(p.first == key)
            {
                TempList.erase(iterator);
                return;
            }
            iterator++;
        }
    }
//--------------------------------------------------------- Function #6 Clear
    void clear() {
        int iterator = 0;
        while(iterator < table.size())
        {
            table[iterator].clear();
            iterator++;
        }
    }
//--------------------------------------------------------- Fcuntion #7 Bucket count
    int bucket_count() {
        return table.capacity();
    }

    float load_factor() {
        int iterator = 0;
        float UsedBuckets = 0;
        list<pair<V,K>> TempList;
        while(table.capacity() > iterator)
        {
            TempList.size = table[iterator]
            if(TempList.size() > 0)
            {
                UsedBuckets++;
            }
            iterator++;
        }
        return UsedBuckets/bucket_count();
    }
//--------------------------------------------------------- Function #8 rehash
void rehash(int n)
{
    int iterator = 0;
    tableSize = findNextPrime(n);
    vector<pair<K,V>> Nums;
    pair<K,V> TempPair;
    while(table.capacity() > iterator)
    {
        for (pair<K,V> j : table[iterator])
        {
            Nums.push_back();
        }
        iterator++;
    }
    clear();
    table.resize(tableSize);
    for(pair<K,V> p : Nums)
    {
        insert(p);
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

#endif //__CHAINING_HASH_H
