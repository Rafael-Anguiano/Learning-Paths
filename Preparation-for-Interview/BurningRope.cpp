/*
 * Your task is to develop a program that keeps track of the status of a rope
 * 
 * Such rope will have length N. People will burn pieces of this rope of length 1, by using 
 * the function Rope.burn(place).
 * 
 * You will also have to implement a method to check if the rope is completely burned. 
 * 
 * 
 * r = Rope(5)
 * r.burn(0.5) 0.5-1.5 element is burnt
 * r.burn(1)
 * r.burn(2)
 * r.burn(3)
 * r.isBurnt() -> false
 * r.isBurnt(4)
 * r.isBurnt() -> true
 * 
 * 
 * vector<int> n (size, 0);
 * 
 * burnedPieces = 5;
 * 
 * 
 * 
 * 2.5
 * 2.5 -> 3.5
 * 
 * --**------
 * --***-*---
 * 
 * vector<float> places (size, 0);
 * 
 * r.burn(0.5)
 * r.burn(0.5)
 * 
 
 *   0.5 First / End
 *   0 - 0.5 First
 *   0.5 - 1 End
 * 
 *   <1, 0>
 * 
 * { 0.2 End, 0.5 fist, 1, 1, 1 }
 *  0.5
 * 	0.2 0.2 - 0.5 
 *  
 *  r.burn(0.5) -> 
 * 	floor:0  
 * 	ceiling: 1
 * 	pieces[floor] = 0 , 0.5 min
 * 	pieces[ceiling] = 0.5, 1 max
 * 
 *  r.burn(0.2)
 * 	floor:0  
 * 	ceiling: 1
 * 	pieces[floor] = 0, 0.2 min
 * 	pieces[ceiling] = 0.5, 1 max
 * 
 * float remaining = 5;
 * 
 * r.burn(1) 
 * floor: 1  
 * ceiling: 1
 * 
 * { <0, 0.5>, <1, 1>, <0, 1>, <0, 1>, <0, 1> }
 */

class Rope {
  vector<pair<float,float>> pieces;
  int burnedPieces = 0;
  
public:
	Rope(int size) {
    this->pieces = vector<pair<float, float>>(size, pair<float, float>(0, 1));
  }
  
  void burnPiece(int index, float offset, bool isTop){
    if (index >= this->pieces.size())
      return
    if (this->pieces[index].first >= this->pieces[index].second)
      return 
    if (isTop){
      this->pieces[index].first = max(this->pieces[index].first, offset)
    } else {
      this->pieces[index].second = min(this->pieces[index].second, offset)
    }
    if (this->pieces[index].first >= this->pieces[index].second)
      this->burnedPieces++;
  }
  
  void burn(float place) {
    int bottom = floor(place);
    int top = ceil(place);
    
    this->burnPieces(bottom, place-bottom, false)
    this->burnPieces(top, place-bottom, true)
    return;
	}
  
  bool isBurnt(){
    return this->burnedPieces == this->pieces.size();
  }

}

