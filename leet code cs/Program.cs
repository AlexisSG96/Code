using System;

class TwoSumSolution
{
    static public List<int> TwoSum(List<int> nums, int target)
    {
        for (int i = 0; i < nums.Count() - 1; i++)
        {
            for (int j = i + 1; j < nums.Count(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return new List<int> { i, j };
            }
        }
        return new List<int>();
    }
}

class AddTwoNumbersSolution
{
    public struct ListNode
    {
        public int val;
        public ListNode? next;
        public ListNode(int value)
        {
            this.val = value;
            this.next = null;
        }

        public ListNode(int value, ListNode? next)
        {
            this.val = value;
            this.next = next;
        }
    }

    static void PrintList(ListNode node)
    {
        ListNode? current = node;
        while (current != null)
        {
            Console.WriteLine(current.Value.val);
            if(current.Value.next == null)
            {
                Console.WriteLine(" -> ");
            }
            current = current.Value.next;
        }
        Console.WriteLine("");
    }
}

class Program
{
    static void Main()
    {

    }

    static void TwoSum()
    {
        var result = TwoSumSolution.TwoSum(new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 10);
        if (result.Count != 0)
            Console.WriteLine($"Indicies {result[0]}, {result[1]}");
    }
}