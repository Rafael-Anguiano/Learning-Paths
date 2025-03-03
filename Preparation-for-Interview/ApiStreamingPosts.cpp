/*
 * Given a paginated api, write a streaming library that abstracts the pagination from the user.
 * 
 * The third party api looks as follows
 * 
 * pair<int, vector<string>> fetch(int pageId){}
 * 
 * It returns a pair with:
 * 	- an int representing next page id. First page id is 0. Next page id is -1 when there is no more pages
 *  - a vector of strings, where each string is a post. You don't know the size of the batch 
 * 
 * Your taks is to implement a class with a method
 * 
 * string nextPost() {}
 * 
 * Every time this function is called, you should return the next post string.
 * 
 * 
 * Example:
 * s = StreamingAPI()
 * s.nextPost() -> "post1"
 * s.nextPost() -> ""
       *
 0 -> [1,2,3]
      [4]
         *
 x -> [1,2,3]
 x -> [1,2,3,4]
 */

class StreamingAPI {
  vector<string> posts;
  int idToNext = 0;
  int pointer = 0;
  
  string nextPost () {
  	if (this->pointer >= this->posts.size()) {
      if (this->idToNext == -1) return "";
      pair<int, vector<string>> page = fetch(this->idToNext);
      this->idToNext = page.first;
      this->posts = page.second;
      this->pointer = 0;
    }
    return this->posts[this->pointer++];
  }
};







