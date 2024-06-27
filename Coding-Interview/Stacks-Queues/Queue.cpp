/**
* Queue implementation
*/

public class Queue <T> {
  private static class QueueNode <T> {
    private T data;
    private QueueNode<T> next;

    public QueueNode (T data) {
      this.data = data;
    }
  }

  private QueueNode<T> first;
  private QueueNode<T> last;

  public void add (T item) {
    QueueNode<T> t = new QueueNode<T>(item);
    if (last != NULL) {
      last.next = t;
    }
    last = t;
    if(first == NULL) {
      first = last;
    }
  }

  public T remove () {
    if(first == NULL) throw new NoSuchElementException();
    T data = first.data;
    first = first.next;
    if(first == NULL) {
      last = NULL;
    }
    return data;
  }

  public T peek () {
    if (first == NULL) throw new NoSuchElementException();
    return first.data;
  }

  public bool isEmpty () {
    return first == NULL;
  }
};
