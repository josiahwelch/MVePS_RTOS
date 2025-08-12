//
// Created by jwelch11 on 8/11/2025.
//

// Necessary Arduino libraries
#include <ArxContainer.h>
#include <ArduinoSTL.h>

#ifndef MVEPSHELPER_H
#define MVEPSHELPER_H

// To find length of an array (assuming it is negative when pseudo NULL)
static unsigned int length(const int *array) {
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        if (array[i] == -1) {return i;}
    }
    return 0;
}

class mPair {
    public:
    mPair(const unsigned long interval, int priority) {
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

class PriorityIndex {
    public:
    PriorityIndex() = default;

    vector<int> getFunctionIDs() {
        return m_functionIDs;
    }

    int getFunctionID(int priority) {
        return m_functionIDs[priority];
    }

    private:
    int m_functionIDs[64];
};

class PrelimDict {
    public:
    PrelimDict() {
        for (int i = 0; i < 64; i++) {
            m_function_IDs[i] = -1;
        }
    }

    mPair get(int index) {
        return m_value_pairs[index];
    }

    void addToDict(int function_id, mPair pair) {
        m_function_IDs[length(m_function_IDs)] = function_id;
        m_value_pairs[-1] = pair;
    }

    vector<mPair> getVector() {
        return m_value_pairs;
    }

    int getIndex(mPair pair) {
        return m_value_pairs[pair.getInterval()].first;
    }

    private:
    int m_function_IDs[64];
    mPair m_value_pairs[64];
};

class OrgDict {
    public:
    OrgDict() = default;



private:
    unsigned long m_intervals[64];
    PriorityIndex m_priority_indexes[64];
};

#endif //MVEPSHELPER_H
