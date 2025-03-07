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




/*
 * Given a paginated api, write a streaming library that abstracts the pagination from the user.
 * 
 * The third party api looks as follows
 * http status code
 * body
 * 	next page id
 *  list of post
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
 
    Implement the following method
    vector<string> nextPosts(int n)
    
    It shout return the next n posts.
    
    Retry:
    	max attempts
      accepted codes: success
      permafail codes: failure
      backoff: exponential backoff
      backoff exponent: 2
      jitter: small random offset
    
    We know the api is flaky because of excesive load. 
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
  
  vector<string> nextPosts (int n) {
    vector<string> nPosts;
    for (int i = 0; i < n; i++) {
    	string post = nextPost(); 
      if (post == "") return nPosts;
      nPosts.push(post);
    }
    return nPosts;
  }
  
};
