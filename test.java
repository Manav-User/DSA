import java.util.*;
import java.io.*;
public class test {
    public static void main(String[] args) {
        Jlinkedlist<Integer> list = new Jlinkedlist<Integer>();
        list.insertend(300);
        list.printLL();
        list.insertfront(100);
        list.printLL(); 
        list.insertend(400);
        list.printLL();
        list.insertkey(200,100);
        list.printLL();
        list.insertkey(500,0);
        list.printLL();
        list.insertkey(350,300);
        list.printLL();
        list.insertend(500);
        list.printLL();
    }
}
class Jlinkedlist<T>{
    Node head;
    class Node{
        T data;
        Node next;
        Node()
        {
            data=null;
            next=null;
        }
        Node(T d)
        {
            data=d;
            next=null;
        }
    }
    Jlinkedlist()
    {
        head=new Node();
    }
    public void insertfront(T data){
        Node newnode = new Node(data);
        newnode.next=this.head.next;
        this.head.next=newnode;
    }
    public void insertend(T data){
        Node newnode = new Node(data);
        newnode.next=null;
        Node ptr=this.head;
        while(ptr.next!=null)
        {
            ptr=ptr.next;
        }
        ptr.next=newnode;
    }
    public void insertkey(T data,T key){
        Node newnode = new Node(data);
        newnode.next=null;
        Node ptr=this.head;
        while(ptr!=null)
        {
            if(ptr.data==key)
            {
                newnode.next=ptr.next;
                ptr.next=newnode;
                break;
            }
            ptr=ptr.next;
        }
    }
    public void printLL(){
        Node ptr=this.head.next;
        while(ptr!=null)
        {
            System.out.print(ptr.data+" ");
            ptr=ptr.next;
        }
        System.out.println();
    }
    public T deletefront(){
        T x=null;
        Node ptr=this.head.next;
        Node preptr=null;
        while(ptr!=null)
        {
            x=ptr.data;
            this.head.next=ptr.next;
            System.out.print("Element deleted");
        }
        return x;
    }
    public T deleteend(){
        T x=null;
        Node ptr=this.head.next;
        Node preptr=null;
        if(ptr!=null)
        {
            while(ptr!=null)
            {
                preptr=ptr;
                ptr=ptr.next;
            }
            x=ptr.data;
            preptr.next=null;   
        }
        return x;
    }
    public void deletekey(T key){
        Node ptr=this.head.next;
        Node preptr=null;
        while(ptr!=null)
        {
            if(ptr.data==key)
            {
                preptr.next=ptr.next;
                System.out.println(key+" position element delelted");
                break;
            }
            else{
                 preptr=ptr;
                 ptr=ptr.next;
            }
        }
        
    }
}
