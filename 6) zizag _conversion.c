char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s))
    {
        return s;
    }

    char** rows = (char**)malloc(numRows * sizeof(char*));

    for (int i = 0; i < numRows; i++)
    {
        rows[i] = (char*)malloc((strlen(s) + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int currentRow = 0;
    int goingDown = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        strncat(rows[currentRow], &s[i], 1);

        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }

        currentRow += goingDown ? 1 : -1;
    }

    char* result = (char*)malloc((strlen(s) + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++)
    {
        strcat(result, rows[i]);
        free(rows[i]);
    }

    free(rows);

    return result;
}
