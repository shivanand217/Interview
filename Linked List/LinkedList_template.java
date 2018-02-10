public class LinkedList_template {
    public static class LinkedList {
        static node head;
        public static class node {
            int data;
            node next;
            node(int data) {
                this.data=data;
                this.next=null;
            }
        }
        public static void insert_at_back(int data){
            if(head == null) {
                head = new node(data);
                return;
            }
            node tmp = head;
            while(tmp.next != null) {
                tmp=tmp.next;
            }
            tmp.next = new node(data);
            tmp=tmp.next;
            tmp.next=null;
            return;
        }
        public static void insert_at_front(int data) {
            if(head == null) {
                head = new node(data);
                return;
            }
            node tmp = new node(data);
            tmp.next=head;
            head=tmp;
            return;
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
            node tmp = head;
            node prev = head;
            while(tmp.next != null) {
                prev = tmp;
                tmp = tmp.next;
            }
            prev.next=null;
        }
        public static void display() {
            if(head == null) {
                System.out.println("list is empty");
                return;
            }
            node tmp = head;
            while(tmp != null) {
                System.out.print(tmp.data+" ");
                tmp = tmp.next;
            }
            System.out.println();
        }
    }
    public static void main(String args[]) {
        LinkedList list = new LinkedList();

        list.insert_at_back(11);
        list.insert_at_back(12);
        list.insert_at_back(13);
        list.insert_at_back(14);
        list.insert_at_back(15);
        list.insert_at_back(56);

        list.insert_at_front(99);
        list.insert_at_front(89);
        list.insert_at_front(67);

        list.display();

        list.delete_front();
        list.display();

        list.delete_back();
        list.display();
    }
}
