class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){
            return a[1]<b[1];
        });
        priority_queue<int> pq;

        int time = 0;
        for (vector<int> course: courses) {
            if (time + course[0] <= course[1]) {
                pq.push(course[0]);
                time += course[0];
            }
            else if (!pq.empty() && pq.top() > course[0]) {
                time += (course[0] - pq.top());
                pq.pop();
                pq.push(course[0]);
            }
        }

        return pq.size();
    }
};
