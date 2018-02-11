import org.jetbrains.annotations.Contract;

public class identical_linked_list {

    public static class LinkedList {
        static node head1;
        static node head2;
        static boolean flag = false;

        public static class node {
            int data;
            node next;
            node(int data) {
                this.data=data;
                this.next=null;
            }
        }
        public static void insert_at_back(int data, int flag) {
            if (flag == 1) {
                if (head1 == null) {
                    head1 = new node(data);
                    return;
                }
                node tmp = head1;
                while (tmp.next != null) {
                    tmp = tmp.next;
                }
                tmp.next = new node(data);
                tmp = tmp.next;
                tmp.next = null;
                return;
            }
            else if (flag == 2) {
                if (head2 == null) {
                    head2 = new node(data);
                    return;
                }
                node tmp = head2;
                while (tmp.next != null) {
                    tmp = tmp.next;
                }
                tmp.next = new node(data);
                tmp = tmp.next;
                tmp.next = null;
                return;
            }
        }
        public static void insert_at_front(int data, int flag) {
            if(flag == 1) {
                if (head1 == null) {
                    head1 = new node(data);
                    return;
                }
                node tmp = new node(data);
                tmp.next = head1;
                head1 = tmp;
                return;
            } else if(flag == 2){
                if (head2 == null) {
                    head2 = new node(data);
                    return;
                }
                node tmp = new node(data);
                tmp.next = head2;
                head2 = tmp;
                return;
            }
        }
        public static void delete_front(int flag) {
            if(flag == 1) {
                if (head1 == null) {
                    return;
                }
                node tmp = head1;
                if (tmp.next == null) {
                    head1 = null;
                    return;
                }
                head1 = tmp.next;
            } else if(flag == 2){
                if (head2 == null) {
                    return;
                }
                node tmp = head2;
                if (tmp.next == null) {
                    head2 = null;
                    return;
                }
                head2 = tmp.next;
            }
        }
        public static void delete_back(int flag) {
            if(flag == 1) {
                if (head1 == null) {
                    System.out.println("list is empty");
                    return;
                }
                if(head1.next == null){
                    head1=null;
                    return;
                }
                node tmp = head1;
                node prev = head1;
                while (tmp.next != null) {
                    prev = tmp;
                    tmp = tmp.next;
                }
                prev.next = null;
            } else if(flag == 2) {
                if (head2 == null) {
                    System.out.println("list is empty");
                    return;
                }
                if(head1.next == null){
                    head1=null;
                    return;
                }
                node tmp = head2;
                node prev = head2;
                while (tmp.next != null) {
                    prev = tmp;
                    tmp = tmp.next;
                }
                prev.next = null;
            }
        }
        public static boolean is_identical() {
            if(head1 == null && head2 != null)
                return false;
            if(head1 != null && head2 == null)
                return false;
            if(head1 == null && head2 == null)
                return true;

            node tmp1 = head1;
            node tmp2 = head2;

            while(tmp1 != null && tmp2 != null) {
                if(tmp1.data != tmp2.data) {
                    return false;
                }
                tmp1=tmp1.next;
                tmp2=tmp2.next;
            }

            if(tmp1 == null && tmp2 == null)
                return true;
            return false;
        }
        public static void display(int flag) {
            if(flag == 1) {
                if (head1 == null) {
                    System.out.println("list is empty");
                    return;
                }
                node tmp = head1;
                while (tmp != null) {
                    System.out.print(tmp.data + " ");
                    tmp = tmp.next;
                }
                System.out.println();
            } else if(flag == 2) {
                if (head2 == null) {
                    System.out.println("list is empty");
                    return;
                }
                node tmp = head2;
                while (tmp != null) {
                    System.out.print(tmp.data + " ");
                    tmp = tmp.next;
                }
                System.out.println();
            }
        }
    }
    public static void main(String args[]) {
        LinkedList list = new LinkedList();

        list.insert_at_back(11,1);
        list.insert_at_back(12,1);
        list.insert_at_back(13,1);
        list.insert_at_back(14,1);
        list.insert_at_back(15,1);
        list.insert_at_back(56,1);

        list.insert_at_front(99,1);
        list.insert_at_front(89,1);
        list.insert_at_front(67,1);

        list.display(1);

        list.insert_at_back(11,2);
        list.insert_at_back(12,2);
        list.insert_at_back(13,2);
        list.insert_at_back(14,2);
        list.insert_at_back(15,2);
        list.insert_at_back(56,2);

        list.insert_at_front(99,2);
        list.insert_at_front(89,2);
        list.insert_at_front(67,2);

        list.display(2);

        if(list.is_identical()) {
            System.out.println("lists are identical");
        } else {
            System.out.println("lists are not identical");
        }
    }
}
