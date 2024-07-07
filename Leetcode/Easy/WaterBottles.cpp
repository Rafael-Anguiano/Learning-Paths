/**
* 1518. Water Bottles
* Given numBottles full water bottles, you can exchange numExchange empty water bottles for one full water bottle.
* There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
*
* The operation of drinking a full water bottle turns it into an empty bottle.
* Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int carry = 0;
        while (numBottles >= numExchange) {
            carry = numBottles % numExchange;
            numBottles = (numBottles/numExchange);
            result += numBottles;
            numBottles += carry;
        }
        return result;
    }
};
