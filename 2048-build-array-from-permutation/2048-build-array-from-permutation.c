/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize; 
    int *v = (int *) malloc(sizeof(int) * numsSize);

    for(int i=0; i < numsSize; ++i)
    {
        v[i] = nums[nums[i]];
    }
    return v;
}