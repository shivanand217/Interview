public class alternating_split_linked_list {
    public static class LinkedList {

        static node head1;
        static node head2;

        public static class node {
            int data;
            node next;
            node(int data) {
                this.data = data;
                this.next = null;
            }
        }

        public static void insert_at_back(int data) {
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

        public static void insert_at_front(int data) {
            if (head1 == null) {
                head1 = new node(data);
                return;
            }
            node tmp = new node(data);
            tmp.next = head1;
            head1 = tmp;
            return;
        }

        public static void delete_front() {
            if (head1 == null) {
                return;
            }
            node tmp = head1;
            if (tmp.next == null) {
                head1 = null;
                return;
            }
            head1 = tmp.next;
        }

        public static void delete_back() {
            if (head1 == null) {
                System.out.println("list is empty");
                return;
            }
            if(head1.next == null) {
                head1 = null;
                return;
            }
            node tmp = head1;
            node prev = head1;
            while (tmp.next != null) {
                prev = tmp;
                tmp = tmp.next;
            }
            prev.next = null;
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

        public static void alternating_split() {
            if(head1 == null || head1.next == null)
                return;

            node tmp1 = head1;
            head2 = head1.next;
            node tmp2 = head2;

            while(tmp1 != null || tmp2 != null) {
                if(tmp1 != null){
                    if(tmp1.next == null) {
                        /** do nothing **/
                    } else if(tmp1.next.next == null){
                        tmp1.next = null;
                    } else {
                        tmp1.next = tmp1.next.next;
                    }
                    tmp1=tmp1.next;
                }
                if(tmp2 != null) {
                    if(tmp2.next == null) {
                        /** do nothing **/
                    } else if(tmp2.next.next == null){
                        tmp2.next = null;
                    } else {
                        tmp2.next = tmp2.next.next;
                    }
                    tmp2=tmp2.next;
                }
            }
        }
    }
    public static void main(String args[]) {
        LinkedList list = new LinkedList();

        list.insert_at_back(1);
        list.insert_at_back(0);
        list.insert_at_back(1);
        list.insert_at_back(0);
        list.insert_at_back(1);
        list.insert_at_back(0);
        list.insert_at_back(1);
        list.insert_at_back(0);

        list.display(1);
        list.alternating_split();

        list.display(1);
        list.display(2);
    }
}
