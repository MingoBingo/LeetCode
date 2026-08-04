bool isPalindrome(int x) 
{
    long y = x, t=0;
    while(y)
    {
        t = t*10 + y%10;
        y/=10;
    }
    if(t == x && x>-1)
    return true;
    
    return false;
}