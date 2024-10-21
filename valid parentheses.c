bool isValid(char* s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
            {
                free(stack);
                return false;
            }

            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '['))
            {
                free(stack);
                return false;
            }
        }
    }

    bool isValid = (top == -1);
    free(stack);
    return isValid;
}
