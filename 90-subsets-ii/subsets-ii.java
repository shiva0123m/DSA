class Solution {
    public void generateSubsets(int index,int n,List<List<Integer>> ans,List<Integer> subsets,int[] nums)
    {
        ans.add(new ArrayList(subsets));
        for(int i=index;i<n;i++)
        {
            if(index<i && nums[i]==nums[i-1])continue;
            subsets.add(nums[i]);
            generateSubsets(i+1,n,ans,subsets,nums);
            subsets.remove(subsets.size() - 1);
        }
        
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) 
    {
        List<List<Integer>> ans= new ArrayList<>();    
        List<Integer> subsets=new ArrayList<>();
        Arrays.sort(nums);
        generateSubsets(0,nums.length,ans,subsets,nums);
        return ans;
    }
}