bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int ok = 0, k=0;
    while(!ok)
    {
        ok = 1;
        k++;
        for(int i=0; i<arrSize-k; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                int aux;
                aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                ok = 0;
            }
        }
    }
    int dif = arr[1] - arr[0];
    for(int i=1; i<arrSize-1; ++i)
    {
        if(arr[i+1] - arr[i]!=dif)
        return false;
    }
    return true;
}