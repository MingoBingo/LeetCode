/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) 
{
    char **result = malloc(sizeof(char *) * (n * 2));
    *returnSize = 0;

    int targetIndex = 0;
    int currentNumber = 1;

    while(targetIndex < targetSize)
    {
        if(currentNumber == target[targetIndex])
        {
            result[(*returnSize)] = malloc(sizeof(char) * 5);
            strcpy(result[(*returnSize)], "Push");
            (*returnSize)++;
            currentNumber++;
            targetIndex++;
        }
        else
        {
            result[(*returnSize)] = malloc(sizeof(char) * 5);
            strcpy(result[(*returnSize)], "Push");
            (*returnSize)++;
            result[(*returnSize)] = malloc(sizeof(char) * 4);
            strcpy(result[(*returnSize)], "Pop");
            (*returnSize)++;
            currentNumber++;
        }
    }
    return result;
}