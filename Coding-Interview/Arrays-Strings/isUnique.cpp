/**
 * Implement an algorithm to determine if a string has all unique characters.
 *
 *
 * What if you cannot use additional data structures?
 */

// Using HashTable
bool isUnique (String s) {
	set<int>h;
	for(int i=0; i<s.length(); i++) {
		if(h.count(s)) return false;
		h.insert(s);
	}
	return true;
}

// Using Array of all ASCII values
bool isUnique (String s) {
	vector<bool> alphabet[128]; // This can also be higher
	for(char c : s ) {
		if(alphabet[c]) return false;
		alphabet[c] = true;
	}
	return true;
}
// You can argue that this is also O(1) complexity due that the space is fixed to the number of characters.
// Or in other case O(k) where k is the number of characters contempled



// There is still other solution using bit operators and bit manipulation.
