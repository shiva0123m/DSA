class Solution {
    public void swap(int[] nums,int i,int index)
    {
        int temp=nums[i];
        nums[i]=nums[index];
        nums[index]=temp;
    }
    public void findTotalSubsets(int index,int[]  nums,int n,List<List<Integer>>ans)
    {
        if(index==n)
        {
            ans.add(Arrays.stream(nums)
                                   .boxed()
                                   .collect(Collectors.toList()));
            return;
        }
        Set<Integer> visited = new HashSet<>();
        for(int i=index;i<nums.length;i++)
        {
            if(visited.contains(nums[i]))continue;

            visited.add(nums[i]);
            swap(nums,i,index);
            findTotalSubsets(index+1,nums,nums.length,ans);
            swap(nums,i,index);
        }
        
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> subset= new ArrayList<>();

        findTotalSubsets(0,nums,nums.length,ans);
        return ans;
    }
}