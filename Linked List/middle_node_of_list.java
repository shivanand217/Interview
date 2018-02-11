public class middle_node_of_list {
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
        public static void print_middle(int n) {
            if( head == null )
                return;
            node one = head;
            node two = head;
            node prev = head;
            while(two != null && two.next != null) {
                prev=one;
                one = one.next;
                two = two.next.next;
            }
            if(n % 2 == 1) {
                System.out.println("middle element is " + one.data);
            } else {
                System.out.println("Two middle elements "+ prev.data+ " and "+one.data);
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
            tmp.next = new node(data);
            tmp = tmp.next;
            tmp.next = null;
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
        public static void printlist() {
            if(head == null) {
                System.out.println("list is empty");
            }
            node Node = head;
            while(Node != null) {
                if(Node.next != null)
                    System.out.print(Node.data+"->");
                else
                    System.out.print(Node.data);
                Node=Node.next;
            }
            System.out.println();
        }
        public static int nodes() {
            if(head == null) {
                System.out.println("list is empty");
                return;
            }
            node tmp = head;
            int cnt=0;
            while(tmp != null) {
                cnt++;
                tmp=tmp.next;
            }
            return cnt;
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
        list.insert_front(25);
        list.insert_front(30);

        list.printlist();
        int count = list.nodes();
        System.out.println(count);

        list.print_middle(count);
    }
}
