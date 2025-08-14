//
// Created by jwelch11 on 8/14/2025.
//
#pragma once

#define LEN(a) (sizeof(a)/sizeof(a[0]))

#ifndef RTFUNCTION_H
#define RTFUNCTION_H


class RTFunction {
public:
    RTFunction(char *function, const int priority, const unsigned long interval) {
        m_function = function;
        m_priority = priority;
        m_interval = interval;
    }

    char *getFunction() const {
        return m_function;
    }

    int getPriority() const {
        return m_priority;
    }

    unsigned long getInterval() const {
        return m_interval;
    }

private:
    char *m_function;
    int m_priority;
    unsigned long m_interval;
};


#endif //RTFUNCTION_H
