class Solution {
public:
    int numTrees(int n) {
		double num = 1;
		for (int k = 2; k <= n; k++)
			num = num * (n + k) / k;

		return (int) round(num);
}
};