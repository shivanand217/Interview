public class Nth_node_from_end {
    public static class LinkedList {
        static node head;
        public static class node {
            int data;
            node next;
            node(int data) {
                this.data = data;
                this.next = null;
            }
        }
        public static void insert_front(int data) {
            if(head == null) {
                head = new node(data);
                return;
            }
            node tmp = new node(data);
            tmp.next = head;
            head = tmp;
        }
        public static void insert_back(int data) {
            if(head == null) {
                head = new node(data);
                return;
            }
            node tmp = head;
            while(tmp.next != null) {
                tmp = tmp.next;
            }
            tmp.next= new node(data);
            tmp=tmp.next;
            tmp.next=null;
        }
        public static void delete_front() {
            if(head == null) {
                return;
            }
            node tmp=head;
            if(tmp.next == null) {
                head = null;
                return;
            }
            head=tmp.next;
        }
        public static void delete_back() {
            if(head == null) {
                System.out.println("list is empty");
                return;
            }
            if(head.next == null){
                head=null;
                return;
            }
            node tmp = head;
            node prev = head;
            while(tmp.next != null) {
                prev = tmp;
                tmp = tmp.next;
            }
            prev.next=null;
        }
        public static void print_list() {
            if(head == null) {
                System.out.println("List is empty");
                return;
            }
            node Node = head;
            while(Node != null) {
                if(Node.next == null) {
                    System.out.println(Node.data);
                } else {
                    System.out.print(Node.data+" - ");
                }
                Node=Node.next;
            }
            return;
        }
        public static void nth_node(int n) {
            if(head == null) {
                System.out.println("List is empty");
                return;
            }
            node one = head;
            node two = head;
            int tmp=n;
            n -= 1;
            boolean ans = true;
            while( n > 0 ) {
                if(two == null) {
                    ans=false;
                    break;
                }
                two=two.next;
                n -= 1;
            }
            if(ans == false) {
                System.out.println(tmp+ "th node from end does not exist.");
                return;
            }
            while(two.next != null) {
                two=two.next;
                one=one.next;
            }
            System.out.println(tmp+ "th node from end is "+ one.data);
        }
    }
    public static void main(String args[]) {
        LinkedList list = new LinkedList();

        list.insert_back(12);
        list.insert_back(13);
        list.insert_back(14);
        list.insert_back(15);

        list.insert_front(20);
        list.insert_front(21);
        list.insert_front(22);

        list.print_list();
        list.nth_node(4);
        list.nth_node(17);
    }
}
