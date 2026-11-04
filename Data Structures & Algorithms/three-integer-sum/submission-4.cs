public class Solution {
    public List<List<int>> ThreeSum(int[] nums) {

        var hs = new HashSet<(int,int,int)>();
        List<List<int>> solution = new List<List<int>>();
        int sum = 0, start, end;
        Array.Sort(nums);

        for (int i = 0; i < nums.Length; i++) {
            start = i + 1;
            end = nums.Length - 1;
            
            while (start < end) {
                sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) {
                    List<int> s = new List<int>();
                    s.Add(nums[i]);
                    s.Add(nums[start]);
                    s.Add(nums[end]);
                    var triplet = (nums[i], nums[start], nums[end]);
                    if (!hs.Contains(triplet)) {
                        solution.Add(s);
                        hs.Add(triplet);
                    }
                    start++;
                    end--;
                } else if (sum < 0) {
                    start++;
                } else {
                    end--;
                }
            }
        }

        return solution;
    }
}
