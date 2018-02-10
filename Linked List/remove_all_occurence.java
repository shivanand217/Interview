public class remove_all_occurence {
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
        public static void remove_all() {
            if(head == null)
                return;
            node tmp = head;
            int val;
            node prev = null;
            node rem = null;
            while(tmp.next != null) {
                if(tmp.data == tmp.next.data) {
                    val = tmp.data;
                    while(tmp.data == val) {
                        if(head.data == val) {
                            head=head.next;
                            tmp=tmp.next;
                        } else {
                            tmp=tmp.next;
                        }
                        if(head == null) {
                            return;
                        }
                    }
                    if(prev != null) {
                        prev.next=tmp;
                    }
                } else {
                    prev = tmp;
                    tmp = tmp.next;
                }
            }
        }
        public static void printlist() {
            if( head == null ) {
                System.out.println("list is empty");
                return;
            }
            node tmp = head;
            while(tmp != null) {
                System.out.print(tmp.data+" ");
                tmp=tmp.next;
            }
            System.out.println();
        }
    }
    public static void main(String args[]) {
        LinkedList list = new LinkedList();

        list.insert_at_back(11);
        list.insert_at_back(12);
        list.insert_at_back(12);
        list.insert_at_back(12);
        list.insert_at_back(14);
        list.insert_at_back(14);
        list.insert_at_back(14);
        list.insert_at_back(16);
        list.insert_at_back(17);
        list.insert_at_back(18);
        list.insert_at_back(18);
        list.insert_at_back(44);
        list.insert_at_back(48);

        list.printlist();
        list.remove_all();

        list.printlist();
    }
}
