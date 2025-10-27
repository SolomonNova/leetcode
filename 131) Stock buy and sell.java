class Solution
{
    public int maxProfit(int[] prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 0; i < prices.length; i++)
        {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }

        return maxProfit;
    }

    public static void main(String[] args)
    {
        int[] prices = {7, 6, 4, 3, 1, 100};

        Solution sol = new Solution();

        int maxProfit = sol.maxProfit(prices);

        System.out.println("Maximum Profit is: " + maxProfit);
    }
}