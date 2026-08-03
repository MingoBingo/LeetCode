bool isUgly(int n) 
{
    if(n == 1)
    return true;
    if(n == 0)
    return false;
    int ok = 0;
    while(n!=1)
    {
        ok = 0;
        if(!(n%2))
        {
            n/=2;
            ok = 1;
        }
            
        if(!(n%3))
        {
            n/=3;
            ok = 1;
        }
            
        if(!(n%5))
        {
            n/=5;
            ok = 1;
        }
            
        if(ok == 0)
            return false;
    }
    return true;
}