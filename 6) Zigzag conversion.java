class Solution {
    public static void main(String[] args)
    {
        Solution s = new Solution();
        s.convert("PAYPALISHIRING", 4);
    }

    public String convert(String s, int numRows)
    {
        char[][] mat = new char[numRows][s.length()];
        int len = s.length();
        int traverse = 0;
        int colCounter = 0;

        while(traverse < len)
        {
            for (int i = 0; i < numRows; i++)
            {
                if (traverse >= len) break;

                mat[i][colCounter] = s.charAt(traverse);
                System.out.println("row -> " + i + " col -> " + colCounter + " for -> " + mat[i][colCounter] + " in first loop");
                traverse++;
            }

            colCounter++;

            for (int i = numRows - 2; i >= 1; i--)
            {
                if (traverse >= len) break;

                mat[i][colCounter] = s.charAt(traverse);
                System.out.println("row -> " + i + " col -> " + colCounter + " for -> " + mat[i][colCounter] + " in  loop");
                colCounter++;
                traverse++;
            }
        }

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < len; j++)
            {
                System.out.print(mat[i][j] + " ");
            }

            System.out.println();
        }

        return "Hello world";
    }
}