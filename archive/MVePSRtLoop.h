// Josiah Welch
// August 4th, 2025
// Midwest Vehicle Positioning System Real Time Operating System

/*
#pragma once
#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <string>
#include <vector>
*/

// Arduino libraries
#include <ArxContainer.h>
#include <ArduinoSTL.h>
#include <MVePSHelper.h>

#ifndef MVEPSRTLOOP_H
#define MVEPSRTLOOP_H

namespace std {

	class MVePSRtLoop {
		private:
		vector<void (*)()> m_functions;
		// map<int, pair<unsigned long, int>> m_stack; // A bit convoluted, but basically <function index, <interval, priority>>
		PrelimDict m_stack;
		unsigned long m_initial_millisecond;
		bool running = false;

		// Static methods
		static void m_organizeStack(OrgDict &organized_stack, const PrelimDict &unorganized_stack) {
			for (auto const& element : unorganized_stack.getVector) {
				int funct_id = unorganized_stack.getIndex(element);
				unsigned long interval = element.getInterval();
				int priority = element.getPriority();
				if (organized_stack.getVector().count(interval) != 0) {
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

		static bool m_pairCmp(pair<int, vector<int>> const &left, pair<int, vector<int>> const &right) {
			return left.first < right.first;
		}
		static vector<int> m_sortFunctionPriorityPairings(vector<int> &sorted_functions, const map<int, vector<int>> &unsorted_pairs) {
			vector<int> result;
			vector<pair<int, vector<int>>> sorted_pairs;
			for (auto const& element : unsorted_pairs) {sorted_pairs.push_back(element);}
			sort(sorted_pairs.begin(), sorted_pairs.end(), m_pairCmp);
			for (auto const& element : sorted_pairs) {
				vector<int> buf = element.second;
				for (int function_id : buf) {
					result.push_back(function_id);
				}
			}
			return result;
		}

		public:
		void addToStack(int function_id, int priority, unsigned long interval) {
			m_stack.addToDict(function_id, mPair(interval, priority));
		}

		void start() {
			m_initial_millisecond = millis();
			running = true;
		}

		void run_in_loop() {
			map<unsigned long, map<int, vector<int>>> organized_m_stack;
			vector<int> sorted_functions;
			if(running) {
				m_organizeStack(organized_m_stack, m_stack);
				for(auto const& element : organized_m_stack) {
					if(millis() % element.first == 0) {
						m_sortFunctionPriorityPairings(sorted_functions, element.second);
					}
				}
				for (int function_to_exec : sorted_functions) {
					m_functions[function_to_exec]();
				}
			}
		}

		void stop() {running = false;}

		void run() {
			while(running) {run_in_loop();}
		}
	};
}

#endif //MVEPSRTLOOP_H
