/**
 * Given two strings, write a method to decide if one 
 * is a permutation of the other.
 */

bool checkPermutation (string s, string t) {
	if(s.length() != t.length()) return false;

	map<char, int>h;
	for(int i=0; i<s.length(); i++) {
		if(h.count(s[i])) h.insert({s[i], 0});
		h[s[i]]++;
	}
	for(char a : t) {
		if(!h.count(a)) return false;
		h[a]--;
		if(!h[a]) {
			h.erase(a);
		}
	}
	return true;
}

