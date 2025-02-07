/**
* Given a String, return the first repeated character in it.
* If there are no repeated characters, return '_'.
*
* Example
* s = "abcdba"
* The first repeated character is 'b'
*/


char firstRepeatedCharacter ( string str ) {
  char alphabet[26] = {0};
  for (char character : str) {
    if (alphabet[character - 'a'] == 1) {
      return character;
    }
    alphabet[character - 'a']++;
  }
  return '_';
}
