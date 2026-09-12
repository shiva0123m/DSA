class Solution {
    public void findTotalSubsets(int index,int[]  nums,int n,List<List<Integer>>ans,List<Integer>subset,int target)
    {
        if(target==0)
        {
            ans.add(new ArrayList<>(subset));
            return;
        }
        if(target<0)
        {   
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(index<i && nums[i]==nums[i-1])continue;
            subset.add(nums[i]);
            findTotalSubsets(i+1,nums,n,ans,subset,target-nums[i]);
            subset.remove(subset.size()-1);
        }
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) 
    {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> subset= new ArrayList<>();
        Arrays.sort(candidates);
        findTotalSubsets(0,candidates,candidates.length,ans,subset,target);
        return ans;
    }
}