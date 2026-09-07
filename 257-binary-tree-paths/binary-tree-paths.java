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
class Solution 
{
    public void findAllTreePaths(TreeNode root,StringBuilder str,List<String> ans)
    {
        if(root==null)return;

        int orginalLength=str.length();
        if(orginalLength>0)
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
            findAllTreePaths(root.left,str,ans);
            findAllTreePaths(root.right,str,ans);
        }
        str.setLength(orginalLength);
    }
    public List<String> binaryTreePaths(TreeNode root) 
    {
        List<String>ans=new ArrayList();
        StringBuilder str=new StringBuilder();
        findAllTreePaths(root,str,ans);
        return ans;  
    }
}