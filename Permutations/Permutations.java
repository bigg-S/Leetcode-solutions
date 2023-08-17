import java.util.ArrayList;
import java.util.List;

class Permutations
{
    static void backtrack(int[] nums, int[] checked, List<Integer> current, List<List<Integer>> result)
    {
        if(current.size() == nums.length)
        {
            result.add(new ArrayList<>(current));
            return;
        }

        for(int i = 0;i < nums.length;i++)
        {
            if(checked[i] == 1)
                continue;

            checked[i] = 1;
            current.add(nums[i]);
            backtrack(nums, checked, current, result);
            current.remove(current.size() - 1);
            checked[i] = 0;
        }
    }

    static List<List<Integer>> permute(int[] nums)
    {
        List<List<Integer>> result = new ArrayList<>(0);
        List<Integer> current = new ArrayList<>();
        int[] checked = new int[nums.length];

        backtrack(nums, checked, current, result);

        return result;
    }
    public static void main(String[] args) 
    {
        int[] nums = {1, 2};
        List<List<Integer>> result = permute(nums);
        for(List<Integer> list : result)
        {
            for(int j : list)
            {
                System.out.print(j + ",");
            }
            System.out.println();
        }
        return;
    }
}