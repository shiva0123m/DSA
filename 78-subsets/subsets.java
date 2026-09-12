class Solution {
    public void findTotalSubsets(int index,int[]  nums,int n,List<List<Integer>>ans,List<Integer>subset)
    {
        if(index==n)
        {
            ans.add(new ArrayList<>(subset));
            return;
        }
        subset.add(nums[index]);
        findTotalSubsets(index+1,nums,n,ans,subset);
        subset.remove(subset.size()-1);
        findTotalSubsets(index+1,nums,n,ans,subset);
        
    }
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> subset= new ArrayList<>();

        findTotalSubsets(0,nums,nums.length,ans,subset);
        return ans;
    }
}