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
			map<int, pair<unsigned long, int>> m_stack; // A bit convoluted, but basically <function id, <interval, priority>>
			unsigned long m_initial_millisecond;
			bool running = false;

			static void m_organizeStack(map<unsigned long, map<int, vector<int>>> *organized_stack, map<int, pair<unsigned long, int>> unorganized_stack) {
				int funct_id;
				unsigned long interval;
				int priority;
				for (auto const& element : unorganized_stack) {
					funct_id = element.first;
					interval = element.second.first;
					priority = element.second.second;
					if (organized_stack->count(interval) != 0) {
						if (organized_stack[interval].count(priority) != 0) {
							
						}
					}
					organized_stack[interval] = make_pair(funct_id, priority);
				}
			}

		public:
			void addToStack(function<void()> func, int priority, unsigned long interval) {
				m_stack[func] = pair<unsigned long, int>(interval, priority);
			}

			void start() {
				m_initial_millisecond = millis();
			}

			void run() {
				map<unsigned long, map<int, vector<function>>> organized_m_stack;
				if(running) {

					for(auto const& element : organized_m_stack) {
							std::cout << element.first  // string (key)
							  << ':'
							  << element.second // string's value
							  << std::endl;

							if(millis() % element.first == 0) {
								for(auto const& element : element.second) {

	};
}

#endif //MVEPSRTLOOP_H
