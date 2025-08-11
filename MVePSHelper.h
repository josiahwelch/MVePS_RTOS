//
// Created by jwelch11 on 8/11/2025.
//

#ifndef MVEPSHELPER_H
#define MVEPSHELPER_H
#include <functional>
#include <vector>

class mPair {
    public:
    mPair(unsigned long interval, int priority) {
        m_interval = interval;
        m_priority = priority;
    }

    unsigned long getInterval() {
        return m_interval;
    }

    int getPriority() {
        return m_priority;
    }

    private:
    unsigned long m_interval;
    int m_priority;
};

class PriorityFunctionIDPairs {
    public:
    PriorityFunctionIDPairs() {}

    vector<int> getFunctionIDs() {
        return m_functionIDs;
    }



    private:
    vector<int> m_functionIDs;
};

class PrelimDict {
    public:
    PrelimDict() = default;

    mPair get(int index) {
        return m_value_pairs[index];
    }

    void addToDict(mPair pair) {
        m_value_pairs.push_back(pair);
    }

    vector<mPair> getVector() {
        return m_value_pairs;
    }

    int getIndex(mPair pair) {
        return m_value_pairs[pair.getInterval()].first;
    }

    private:
    vector<mPair> m_value_pairs;
};

class OrgDict {
    public:
    OrgDict() = default;

};

#endif //MVEPSHELPER_H
