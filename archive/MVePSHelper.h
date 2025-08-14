//
// Created by jwelch11 on 8/11/2025.
//

// Necessary Arduino libraries
#include <ArxContainer.h>
#include <ArduinoSTL.h>

#ifndef MVEPSHELPER_H
#define MVEPSHELPER_H

// Forward declarations to not break things
class mPair;

// To find an element in an array and return its index
static int find(const int array[], const int element) {
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        if (array[i] == element) {return i;}
    }
    return -1;
}
static int find(const mPair *array[], mPair *element) {
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        if (array[i]->compare(element)) {return i;}
    }
    return -1;
}

// To find length of an array (assuming it is negative when pseudo NULL)
static unsigned int arrayLength(const int *array) {
    const int index = find(array, -1);
    return index >= 0 ? index : sizeof(array)/sizeof(array[0]);
}

class mPair {
    public:
    mPair(const unsigned long interval, int priority) {
        m_interval = interval;
        m_priority = priority;
    }

    mPair() {m_is_empty = true;}

    unsigned long getInterval() {
        return m_interval;
    }

    int getPriority() {
        return m_priority;
    }

    bool isEmpty() const {return m_is_empty;}

    bool compare(mPair *other_pair) const {
        if (isEmpty() == other_pair->isEmpty()) {
            return isEmpty() ? true : (m_interval == other_pair->getInterval() && m_priority == other_pair->getPriority());
        }
        return false;
    }

    private:
    unsigned long m_interval;
    int m_priority;
    bool m_is_empty = false;
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
        for (int & m_function_ID : m_function_IDs) {
            m_function_ID = -1;
        }
    }

    mPair get() {
        return ;
    }

    unsigned int length() {return arrayLength(m_function_IDs);}

    void addToDict(int function_id, mPair pair) {
        m_function_IDs[length()] = function_id;
        m_value_pairs[length()] = pair;
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
