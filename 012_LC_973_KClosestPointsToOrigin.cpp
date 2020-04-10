//
// Created by Zeno on 2020/4/10.
//

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        return kClosest(points, 0, points.size() - 1, K);
    }
private:
    int partition(vector<vector<int>> &points, int left, int right)
    {
        int key = getDistance(points[left]);
        vector<int> tmp_key = points[left];
        while (left < right)
        {
            while (left < right && getDistance(points[right]) >= key)
            {
                right--;
            }
            if (left < right)
            {
                points[left++] = points[right];
            }

            while (left < right && getDistance(points[left]) < key)
            {
                left++;
            }
            if (left < right)
            {
                points[right--] = points[left];
            }
        }

        points[left] = tmp_key;
        return left;
    }

    int getDistance(vector<int> point)
    {
        return (pow(point[0], 2) + pow(point[1], 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int left, int right, int K)
    {
        if (left >= right)
        {
            vector<vector<int>> res;
            for (int i = 0; i < K; i++)
            {
                res.push_back(points[i]);
            }
            return res;
        }

        int pos = partition(points, left, right);

        if (pos == K - 1)
        {
            vector<vector<int>> res;
            for (int i = 0; i < K; i++)
            {
                res.push_back(points[i]);
            }
            return res;
        }
        else if (pos < K - 1)
        {
            return kClosest(points, pos + 1, right, K);
        }
        else
        {
            return kClosest(points, left, pos - 1, K);
        }
    }
};