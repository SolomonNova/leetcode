class Solution {
    public static void main(String[] args)
    {
        String firstSample = "abcabcbb";
        String secondSample = "abcabcbbaaaabbbbbcdefghi";
        String thirdSample = "abcabcbbjklmnip";

        Solution solution = new Solution();
        int len1 = solution.lengthOfLongestSubstring(firstSample);
        int len2 = solution.lengthOfLongestSubstring(secondSample);
        int len3 = solution.lengthOfLongestSubstring(thirdSample);

        System.out.println("Longest Substring without repeating characters length is -> " + len1);
        System.out.println("Longest Substring without repeating characters length is -> " + len2);
        System.out.println("Longest Substring without repeating characters length is -> " + len3);
    }
    public int lengthOfLongestSubstring(String s)
    {
        if (s.isEmpty()) return 0;

        int[] occurrence = new int[256];
        int left = 0;
        int maxLen = 1;


        for (int right = 0; right < s.length(); right++)
        {
            occurrence[s.charAt(right)]++;

            while (occurrence[s.charAt(right)] > 1)
            {
                occurrence[s.charAt(left)]--;
                left++;
            }

            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}