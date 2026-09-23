class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MAX, n = nums.size();
        vector<int> pre(n), post(n);
        pre[0] = nums[0];
        post[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            post[i] = post[i + 1] + nums[i];
        }
        // for(auto &ele: pre) cout<<ele<<" ";
        // cout<<endl;
        // for(auto &ele: post) cout<<ele<<" ";
        // check if present or not
        int preCheck = binarySearchAsc(pre, x);
        int postCheck = binarySearchDesc(post, x);

        if(preCheck != INT_MAX) preCheck = 1 + preCheck;
        if(postCheck !=INT_MAX) postCheck = n - postCheck;

        ans = min(preCheck, postCheck);
        // cout<<endl << preCheck<<" "<<postCheck<< " "<<ans<<endl;

        //check combination
        for(int i=0;i<n;i++){
            if(pre[i]>x) break;

            int idx = binarySearchDesc(post, x - pre[i]);
            if(idx!=INT_MAX && idx!=i) ans = min(ans, (i+1) + (n-idx));
            // cout<<i<<" "<<idx<<" "<<ans<<endl;
        }
        return ans==INT_MAX ? -1 : ans;

    }

    int binarySearchAsc(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1; // Target is in the right half
            } else {
                right = mid - 1; // Target is in the left half
            }
        }
        return INT_MAX; // Element not found
    }

    int binarySearchDesc(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                right = mid - 1; // Target is in the left half (since values
                                 // decrease to the right)
            } else {
                left = mid + 1; // Target is in the right half (since values
                                // increase to the left)
            }
        }
        return INT_MAX; // Element not found
    }
};