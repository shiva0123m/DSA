class Solution 
{
    public void findTotalSubsets(int index,int[] nums,int n,List<List<Integer>>ans,List<Integer>subset,int target)
    {
        if(target==0)
        {
            ans.add(new ArrayList<>(subset));
            return;
        }
        if(index==n || target<0)
        {   
            return;
        }
        subset.add(nums[index]);
        findTotalSubsets(index,nums,n,ans,subset,target-nums[index]);
        subset.remove(subset.size()-1);
        findTotalSubsets(index+1,nums,n,ans,subset,target);
        
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
    {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> subset= new ArrayList<>();

        findTotalSubsets(0,candidates,candidates.length,ans,subset,target);
        return ans;
    }
}