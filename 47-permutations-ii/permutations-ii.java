class Solution 
{
    private void swap(int[] nums, int i, int j) 
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void findAllPermutations(int index,List<List<Integer>> ans,int[] nums)
    {
         if(index==nums.length)
        {
            ans.add(
                Arrays.stream(nums)
                    .boxed()
                    .collect(Collectors.toList())
            );
            return;
        }

        Set<Integer> visited= new HashSet<>();
        for(int i=index;i<nums.length;i++)
        {
            if(visited.contains(nums[i]))continue;

            visited.add(nums[i]);
            swap(nums,i,index);
            findAllPermutations(index+1,ans,nums);
            swap(nums,i,index);
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) 
    {
        List<List<Integer>>ans=new ArrayList<>();
        findAllPermutations(0,ans,nums);
        return ans;
    }
}