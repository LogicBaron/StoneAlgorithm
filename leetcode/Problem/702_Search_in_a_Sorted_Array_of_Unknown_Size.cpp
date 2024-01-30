class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = 9999;

        while (l<=r) {
            int mid = (l+r)>>1;

            int k = reader.get(mid);

            if (k==INT_MAX) r = mid-1;

            else if (k==target) return mid;

            else if (k<target) l = mid+1;

            else r = mid-1;
        }

        return -1;
    }
};
