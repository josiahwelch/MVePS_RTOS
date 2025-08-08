//
#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <string>
#include <vector>

#ifndef MVEPSRTLOOP_H
#define MVEPSRTLOOP_H

namespace std {

	class MVePSRtLoop {
		private:
			map<int, function<void()>> m_functions;
			int m_current = 0; // Pointer to the last index written in m_functions/m_stack
			map<int, pair<unsigned long, int>> m_stack; // A bit convoluted, but basically <function id, <interval, priority>>
			unsigned long m_initial_millisecond;
			bool running = false;

			static void m_organizeStack(map<unsigned long, map<int, vector<int>>> &organized_stack, const map<int, pair<unsigned long, int>> &unorganized_stack) {
				for (auto const& element : unorganized_stack) {
					int funct_id = element.first;
					unsigned long interval = element.second.first;
					int priority = element.second.second;
					if (organized_stack.count(interval) != 0) {
						if (organized_stack[interval].count(priority) != 0) {
							organized_stack[interval][priority].push_back(funct_id);
						} else {
							organized_stack[interval][priority] = vector<int>({funct_id});
						}
					} else {
						organized_stack[interval] = map<int, vector<int>>({priority, {funct_id}});
					}
				}
			}

		public:
			void addToStack(function<void()> func, int priority, unsigned long interval) {
				m_functions[m_current] = func;
				m_stack[m_current] = {interval, priority};
				++m_current;
			}

			void start() {
				m_initial_millisecond = millis();
			}

			void run() {
				map<unsigned long, map<int, vector<int>>> organized_m_stack;
				if(running) {
					m_organizeStack(organized_m_stack, m_stack);
					for(auto const& element : organized_m_stack) {
							if(millis() % element.first == 0) {
								for(auto const& element : element.second) {

	};
}

#endif //MVEPSRTLOOP_H
