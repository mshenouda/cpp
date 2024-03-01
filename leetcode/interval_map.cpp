#include <map>
#include <iostream>
#include <stdlib.h>

using namespace std;


template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
// INSERT YOUR SOLUTION HERE

		//exit if first key val == m_valBegin
		if(m_map.empty() && m_valBegin == val) return;

		const char* name = typeid(K).name();
		//check if typeid is integer or character;
		if (*name == 'i' || *name == 'c')
		{
			if (keyEnd <= keyBegin) return;
			if(m_map.empty()) {
				for(K i = keyBegin; i<keyEnd; i++)
					m_map[i] = val;
				return;
			}
			//adjust keyBegin and KeyEnd
			auto itBegin = m_map.find(keyBegin);
			auto itEnd = m_map.find(keyEnd);	
			while(itEnd != m_map.end() && itEnd != itBegin && itEnd->second == val) {
				--itEnd;
			};

			if (itEnd == itBegin) return;

			while(itBegin != m_map.end() && itEnd != itBegin && itBegin->second == val) {
				++itBegin;
			};
		    //default case value in keyBegin to keyEnd are canonical
			for(auto it = itBegin; it != itEnd; ++it)
				it->second = val;
			return;
		}
		// generic case keys are strings, floats, or pairs, so no increment operation for keys allowed
		if(m_map.empty()) {
			m_map[keyBegin] = val;
			return;
		}
		// map is not empty and it may have the key or not
		auto itBegin = m_map.find(keyBegin);
		if((--itBegin)->second == val) return;
		
		itBegin = m_map.find(keyBegin);
		auto itEnd = m_map.find(keyEnd);

		while(itEnd != m_map.end() && itEnd != itBegin && itEnd->second == val) {
			--itEnd;
		};
		if (itEnd == itBegin) return;
		while(itBegin != m_map.end() && itEnd != itBegin && itBegin->second == val) {
			++itBegin;
		};
	    //default case value in keyBegin to keyEnd are canonical
		for(auto it = itBegin; it != itEnd; it)
			it->second = val;

		//default case
		m_map[keyBegin] = val;
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	void print() {
		for(const auto& item: m_map)
			cout<<item.first<<" "<<item.second<<endl;
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.


int main() {
	cout<<"Hello World"<<endl;
	//typedef pair<float, char> pic;
	interval_map<int, int> myMap(12);
	myMap.assign(2, 5, 13);
	myMap.assign(6, 8, 12);
	myMap.assign(8, 10, 13);
	myMap.assign(3, 6, 7);
	myMap.print();
	int v = myMap[2];
	//int value = myMap[4];

	return 0;
}