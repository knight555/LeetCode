import java.util.*;

/**
题目要求，反转链表的一部分，如反转表长为5，（1,2,3,4,5）的表的2-4的位置
输入为
5
1
2
3
4
5
2
4
结果为：
1 4 3 2 5

PS：难点是边界处理，且反转部分包括head的话要处理（加dummy结点）
**/

class ListNode<T> {
    public T data;
    public ListNode next;
}

class Solution {

    /* Write Code Here */
    public ListNode<Integer> reverseBetween(ListNode<Integer> head, int left, int right) {
        //分段处理，把要反转的列表部分提出来，分成外部和内部列表，外部不变，内部反转
        int pos = 0;
        ListNode<Integer> dummy = new ListNode<>();
        dummy.next = head;
        ListNode p_front, p;
        p_front = dummy;
        /**
         * in_left 表示在内部的左边界，out_left表示外部的左边界，以此类推
         * x1, x2, ..., out_left, in_left, .....in_right, out_right,....
         */
        ListNode out_left, out_right, in_left, in_right;
        while(pos < left-1){
            p_front = p_front.next;
            ++pos;
        }
        out_left = p_front;
        p = out_left;
        for(int j=pos;j<right;j++){
            p = p.next;
        }
        in_right = p;
        out_right = in_right.next;
        in_left = out_left.next;

        in_right.next = null;
        out_left.next = null;


        ListNode<Integer> reversed_list = reverseList(in_left);
        System.out.println("反转部分的链表结果：");
        show(reversed_list);
        p = reversed_list;
        while(p.next != null){
            p = p.next;
        }
        out_left.next = reversed_list;
        p.next = out_right;
        return dummy.next;

    }
    public ListNode<Integer> reverseList(ListNode<Integer> head){
        ListNode<Integer> p_front, p_back, p;
        p_front = null;
        p = head;
        while(p != null){
            p_back = p.next;
            p.next = p_front;
            p_front = p;
            p = p_back;
        }
        return p_front;
    }

    public void show(ListNode<Integer> head){
        ListNode<Integer> p = head;
        while (p != null){
            System.out.print(p.data + " ");
            p = p.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        ListNode<Integer> res = null;

        int head_size = 0;
        head_size = in.nextInt();
        ListNode<Integer> head = null, head_curr = null;
        for(int head_i = 0; head_i < head_size; head_i++) {
            int head_item = in.nextInt();
            ListNode<Integer> head_temp = new ListNode<Integer>();
            head_temp.data = head_item;
            head_temp.next = null;

            if (head == null) {
                head = head_curr = head_temp;
            } else {
                head_curr.next = head_temp;
                head_curr = head_temp;
            }
        }

        if(in.hasNextLine()) {
            in.nextLine();
        }

        int left;
        left = Integer.parseInt(in.nextLine().trim());

        int right;
        right = Integer.parseInt(in.nextLine().trim());

        res = new Solution().reverseBetween(head, left, right);
        System.out.println("最终：");
        while (res != null) {
            System.out.print(String.valueOf(res.data) + " ");
            res = res.next;
        }
        System.out.println();

    }
}
