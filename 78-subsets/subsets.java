class Solution {
    public void generateSubsets(int i,int n,List<List<Integer>> ans,List<Integer> subsets,int[] nums)
    {
        if(i==n)
        {
            ans.add(new ArrayList(subsets));
            return;
        }
        subsets.add(nums[i]);
        generateSubsets(i+1,n,ans,subsets,nums);
        subsets.remove(subsets.size() - 1);
        generateSubsets(i+1,n,ans,subsets,nums);
    }
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> ans= new ArrayList<>();    
        List<Integer> subsets=new ArrayList<>();

        generateSubsets(0,nums.length,ans,subsets,nums);
        return ans;
    }
}