int lengthOfLastWord(char* s) {
    int l;
    char *p = strtok(s," ");
    while(p!=NULL)
    {
        l = strlen(p);
        p = strtok(NULL, " ");
    }
    return l;
}