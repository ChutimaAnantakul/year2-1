package linkedlist;
import java.util.LinkedList;
import java.util.Scanner;
public class demolinklist {
	public static void main(String[] args ) {
	LinkedList<Integer>  linkedlist = new LinkedList<Integer>();
	Scanner Sc = new Scanner(System.in);
	int  position, n,data,choice;
	choice = 0;
	n = 0;
	while (choice != 9)  {
	   System.out.println("[1] : insert at first ");
	   System.out.println("[2] : insert at betaween");
	   System.out.println("[3] : insert at end ");
	   System.out.println("[4] : delete at first ");
	   System.out.println("[5] : delete at betaween");
	   System.out.println("[6] : delete at end ");
	   System.out.println("[7] : search linked list ");
	   System.out.println("[8] : print linked list");
	   System.out.println("[9] : stop prgogram");
	   System.out.println("Your choice  ");
	   choice =  Sc.nextInt();
	   if (choice == 1){
		   System.out.println("Enter integer for insert==> ");
		   data =  Sc.nextInt();
		   linkedlist = insertfirst(linkedlist,data);
	       n = n+1;
	    }
	      else if (choice == 2){
	    	 System.out.println("Enter position for insert ===> ");
	    	 position =  Sc.nextInt();
	         System.out.println("Enter integer for insert==> ");
	         data =  Sc.nextInt();
	         while (position > n) {
	        	 System.out.println("Invalid position\n");
	        	 System.out.println("Enter new position for insert ===> ");
	        	 position =  Sc.nextInt();
	        }
	         linkedlist = insertbetween(linkedlist,data,position-1);
	         n = n+1;
	      }
	      else if (choice == 3) {
	    	  System.out.println("Enter integer for insert==> ");
	    	  data =  Sc.nextInt();
	    	  linkedlist = insertatend(linkedlist,data,n);
	          n = n+1;
	      }
	      else if (choice == 4) {
	    	  if (linkedlist.size() > 0) {
	    	     linkedlist = deletefirst(linkedlist);
	             n = n-1;
	    	  }
	    	  else
	    		  System.out.println("No node for delete\n");
	      }
	       else if (choice == 5) {
	    	   System.out.println("Enter position for delete ===> ");
	    	   position =  Sc.nextInt();
	           while ((position >= linkedlist.size()) || (position <= 1)) {
	        	  System.out.println("Invalid position\n");
	        	  System.out.println("Enter new position for delete ===> ");
	        	  position =  Sc.nextInt();
	        }
	        linkedlist = deletebetween(linkedlist,position,n);
	        n = n-1;
	      }
	       else if (choice == 6) {
	    	       if (linkedlist.size() > 0) {
	    	           linkedlist = deleteatend(linkedlist);
	                   n = n-1;
	    	       } 
	    	       else
	 	    		  System.out.println("No node for delete\n");
	      }
	       else if (choice == 7) {
	    	   System.out.println("Enter integer for search ==> ");
	    	   data =  Sc.nextInt();
	           searchlinkedlist(linkedlist,data);
	      }
	    else  if (choice == 8)
	        printlinkedlist(linkedlist);
	    }

	}

	public static LinkedList<Integer>  insertfirst(LinkedList<Integer>  head,int  data)  {
		 head.add(0,data);
	     return(head);
	}

	public static LinkedList<Integer>   insertatend(LinkedList<Integer>   head,int  data,int n)  {
	   if (n == 0) {
		   head.add(data);
	       return(head);
	   }
	   else {
		   head.add(n,data);
	       return(head);
	   }
	}

	public static LinkedList<Integer>  insertbetween(LinkedList<Integer>  head,int  data,int position)  {
		 head.add(position,data);
	     return(head);
	}

	public static LinkedList<Integer>  deletefirst(LinkedList<Integer>  head)  {
	      head.removeFirst();
	      return(head);
	}

	public static LinkedList<Integer>  deleteatend(LinkedList<Integer>  head)  {
	      head.removeLast();
	      return(head);
	}
	  
	public static LinkedList<Integer>  deletebetween(LinkedList<Integer>  head,int position,int n)  {
		if ( n != 0) {
	       head.remove(position-1);
	       return(head);
	   }
	   else {
		   System.out.println("No node for delete\n");
		   return(head);
	   }
	}

	public static void  searchlinkedlist(LinkedList<Integer>  head,int  data)  {
		int position;
		if (head.contains(data)) {
		   position = head.indexOf(data)+1;	
		   System.out.println("FOUND !! at position " + position);
		}   
		else 
		   System.out.println("Not Found \n");
	}

	public static void printlinkedlist(LinkedList<Integer>  head)  {
		System.out.println("data = "+head.toString());
	}

}
