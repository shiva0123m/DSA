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
    public void findPaths(TreeNode root,StringBuilder str,List<String>ans)
    {
        if(root==null)
        {
            return;
        }
        int originalLength=str.length();
        if(originalLength>0)
        {
            str.append("->");
        }
        str.append(root.val);

        if(root.left==null && root.right==null)
        {
            ans.add(str.toString());
        }
        else
        {
            findPaths(root.left,str,ans);
            findPaths(root.right,str,ans);
        }
        str.setLength(originalLength);
    }
    public List<String> binaryTreePaths(TreeNode root) 
    {
        List<String>ans=new ArrayList();
        StringBuilder str=new StringBuilder();

        findPaths(root,str,ans);
        return ans;
    }
}