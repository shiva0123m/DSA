class Solution {
    public void generateSubsets(int i,int n,List<List<Integer>> ans,List<Integer> subsets,int[] candidates, int target)
    {
        if (target == 0) {
            ans.add(new ArrayList<>(subsets));
            return; 
        }
        
        if (i == n || target < 0) {
            return;
        }
        
        subsets.add(candidates[i]);
        generateSubsets(i,n,ans,subsets,candidates,target-candidates[i]);
        subsets.remove(subsets.size() - 1);
        generateSubsets(i+1,n,ans,subsets,candidates,target);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
    {
        List<List<Integer>> ans= new ArrayList<>();    
        List<Integer> subsets=new ArrayList<>();

        generateSubsets(0,candidates.length,ans,subsets,candidates,target);
        return ans;
    }
}