bool search(int* nums, int numsSize, int target) {
    int start, mid, end;

    start = 0;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;

        if(nums[mid] == target)
            return true;

        if(nums[start] < nums[mid]){
            if(target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }else if(nums[start] > nums[mid]){
            if(target > nums[mid] && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }else{
            start++;
        }
    }

    return false;
}
