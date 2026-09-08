class Solution {
    public void generateSubsets(int index,int n,List<List<Integer>> ans,List<Integer> subsets,int[] candidates, int target)
    {
        if (target == 0) {
            ans.add(new ArrayList<>(subsets));
            return; 
        }
        
        if (target < 0) {
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(index<i && candidates[i]==candidates[i-1])continue;
            subsets.add(candidates[i]);
            generateSubsets(i+1,n,ans,subsets,candidates,target-candidates[i]);
            subsets.remove(subsets.size() - 1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) 
    {
        List<List<Integer>> ans= new ArrayList<>();    
        List<Integer> subsets=new ArrayList<>();
        Arrays.sort(candidates);
        generateSubsets(0,candidates.length,ans,subsets,candidates,target);
        return ans;
    }
}