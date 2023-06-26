 /**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int xmin = bottomLeft[0], ymin=bottomLeft[1], xmax=topRight[0], ymax=topRight[1];
        if (xmin>=xmax && ymin>=ymax) {
            return sea.hasShips({xmax, ymax}, {xmin, ymin});
        }
        
        int xmid = (xmin+xmax)/2;
        int ymid = (ymin+ymax)/2;
        int rst = 0;

        if (sea.hasShips({xmid, ymid}, {xmin, ymin})) {
            rst += countShips(sea, {xmid, ymid}, {xmin, ymin});
        }
        if (xmax>xmid && sea.hasShips({xmax, ymid}, {xmid+1, ymin})) {
            rst += countShips(sea, {xmax, ymid}, {xmid+1, ymin});
        }
        if (xmax>xmid && ymax>ymid && sea.hasShips({xmax, ymax},{xmid+1, ymid+1})) {
            rst += countShips(sea, {xmax, ymax}, {xmid+1, ymid+1});
        }
        if (ymax>ymid && sea.hasShips({xmid, ymax},{xmin, ymid+1})) {
            rst += countShips(sea, {xmid, ymax},{xmin, ymid+1});
        }

        return rst;
    }
};
