class Solution {
    public void findTotalSubsets(int index,int k,List<List<Integer>>ans,List<Integer>subset,int target)
    {
        if(subset.size()==k && target==0)
        {
            ans.add(new ArrayList<>(subset));
            return;
        }
        if(target<index)
        {   
            return;
        }
        for(int i=index;i<=9;i++)
        {
            subset.add(i);
            findTotalSubsets(i+1,k,ans,subset,target-i);
            subset.remove(subset.size()-1);
        }
        
    }
    public List<List<Integer>> combinationSum3(int k, int n) 
    {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> subset= new ArrayList<>();
        findTotalSubsets(1,k,ans,subset,n);
        return ans;
    }
}