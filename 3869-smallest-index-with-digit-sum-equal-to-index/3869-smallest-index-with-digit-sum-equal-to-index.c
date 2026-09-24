int digitSum(int number)
{
    int sum = 0;
    while(number)
    {
        sum+=number%10;
        number/=10;
    }
    return sum;
}

int smallestIndex(int* nums, int numsSize) 
{
    int idx = -1;

    for(int i = 0; i < numsSize; ++i)
    {
        if(digitSum(nums[i]) == i)
        {
            return i;
        }
    }
    return -1;
}