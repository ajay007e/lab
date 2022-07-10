public class doublyLinkedList {  
     class Node {  
        int data;  
        Node prev;  
        Node next;  
        public Node(int data) {  
            this.data = data;  
        }  
    }  
    
	Node head, tail = null;  
	
	public void addNode(int data) {  
	    Node newNode = new Node(data);  
	    if(head == null) {  
	        head = tail = newNode;  
	        head.prev = null;  
	        tail.next = null;  
	    }  
	    else {  
	        tail.next = newNode;  
	        newNode.prev = tail;  
	        tail = newNode;  
	        tail.next = null;  
	    }  
    }
    
	public void delete(int n) {  
    	if(head == null) {  
    		return;  
	    }  
	    else {  
	        Node current = head;  
	        int pos =n;  
	        for(int i = 1; i < pos; i++){  
	            current = current.next;  
	        }  
	        if(current == head) {  
	            head = current.next;  
	        }  
	        else if(current == tail) {  
	            tail = tail.prev;  
	        }  
	        else {  
	            current.prev.next = current.next;  
	            current.next.prev = current.prev;  
	        }  
	         current = null;  
	    }  
	}  
    
	void display() {  
    	Node current = head;  
    	if(head == null) {  
    		System.out.println("List is empty");  
    		return;  
    	}
    	while(current != null) {  
    		System.out.print(current.data + " ");  
        	current = current.next;  
        }  
    	System.out.println();  
    }  
    
	public static void main(String[] args) {  
		doublyLinkedList dList = new doublyLinkedList(); 
	    dList.addNode(10);  
	    dList.addNode(20);  
	    dList.addNode(30);
	    dList.addNode(40);
	    dList.addNode(50);
	    System.out.println("Initial Doubly Linked List: "); 
	    dList.display();
	    dList.delete(2);
	    dList.delete(3);
	    System.out.println("Doubly Linked List after Deletion from 2nd and 3rd Positions: "); 
	    dList.display();  
    }  
}