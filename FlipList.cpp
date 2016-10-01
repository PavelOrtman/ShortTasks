#include <QDebug>

class MyList
{
    int value;
    MyList *next;

public:
    explicit MyList(int v){
        value = v;
        next = NULL;
    }
    void append(int v){
        MyList *last = this;
        while(last->next != NULL){
            last = last->next;
        }

        MyList *ml = new MyList(v);
        last->next = ml;
    }

    void print(){
        MyList *last = this;
        while(last->next != NULL){
            qDebug() << last << last->value;
            last = last->next;
        }
        qDebug() << last << last->value;
        qDebug() << "-----";
    }

    MyList* flip(){
        MyList *last = this;
        MyList *lastVisited = this;
        MyList *tail = NULL;
        MyList *newHead = NULL;
        while(last->next != NULL){
            lastVisited = last;
            last = last->next;
        }
        last->next = lastVisited;
        tail = last;
        newHead = last;

        last = this;
        while(true){
            if(last->next == tail){
                last->next = lastVisited;
                tail = last;
                last = this;
            }

            if(tail == this) break;

            lastVisited = last;
            last = last->next;
        }

        this->next = NULL;
        return newHead;
    }
};

int main(int argc, char *argv[])
{

    MyList *ml = new MyList(0);
    for(int i = 1 ; i <= 10; ++i) ml->append(i);
    ml->print();

    ml = ml->flip();
    ml->print();

    return 0;
}
