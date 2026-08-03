/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) 
{
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int *v_freq = calloc(sizeof(int),numsSize);


    for(int i=0; i<numsSize; ++i)
    {
        v_freq[nums[i]-1]++;
    }
    for(int i=0; i<numsSize; ++i)
    {
        if(v_freq[i] == 2)
        ans[0] = i+1;
        if(v_freq[i] == 0)
        {
            ans[1] = i+1;
        }
    }
    return ans;
}