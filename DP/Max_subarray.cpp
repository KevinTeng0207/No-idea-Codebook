/*Kadane's algorithm*/
int maxSubArray(vector<int>& nums) {
    int local_max = nums[0], global_max = nums[0];
    for(int i = 1; i < nums.size(); i++){
        local_max = max(nums[i],nums[i]+local_max);
        global_max = max(local_max,global_max);
    }
    return global_max;
}