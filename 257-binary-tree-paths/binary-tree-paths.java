/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void findAllPaths(TreeNode root,StringBuilder sb,List<String>ans)
    {
        if(root==null)
        {
            return;
        }

        int originalLength=sb.length();

        if(originalLength>0)
        {
            sb.append("->");
        }
        sb.append(root.val);

        if(root.left==null && root.right==null)
        {
            ans.add(String.valueOf(sb));
        }
        else
        {
            findAllPaths(root.left,sb,ans);
            findAllPaths(root.right,sb,ans);
        }
        sb.setLength(originalLength);
    }
    public List<String> binaryTreePaths(TreeNode root) 
    {
        List<String> ans=new ArrayList<>();

        StringBuilder sb= new StringBuilder();

        findAllPaths(root,sb,ans);
        return ans;
    }
}