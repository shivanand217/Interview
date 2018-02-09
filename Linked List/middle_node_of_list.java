public class middle_node_of_list {
    public static class LinkedList {
        static node head;

        public class node {
            int data;
            node next;
            node(int data) {
                this.data = data;
                this.next = null;
            }
        }
        public static void print_middle() {
            if(head == null)
                return;
            node one = head;
            node two = head;
            while(two != null && two.next != null) {
                one = one.next;
                two = two.next.next;
            }
            System.out.println("middle element is "+ one.data);
        }
        public void insert_front(int data) {
            node tmp = new node(data);
            tmp.next = head;
            head = tmp;
        }
        public void insert_back(int data) {
            if(head == null) {
                node tmp = new node(data);
                head = tmp;
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
        public static void printlist() {
            node Node = head;
            while(Node != null) {
                if(Node.next != null)
                    System.out.print(Node.data+"->");
                else
                    System.out.print(Node.data);
                Node=Node.next;
            }
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

        list.printlist();
    }
}
