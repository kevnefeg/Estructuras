struct Client {
    string name;
    int payment;
    struct Client *next;
};
typedef struct Client client;

struct Queue {
    client *front;
    client *back;
};
typedef struct Queue queue;

void initialize(queue *q) {
    q->front = NULL;
    q->back = NULL;
}

bool empty(queue *q) {
    if(q->front == NULL) {
        return true;
    }else {
        return false;
    }
}

void push(queue *q, string name, int payment) {
    client *newClient = new client;
    newClient->name = name;
    newClient->payment = payment;
    newClient->next = NULL;

    if(q->back == NULL) {
        q->front = newClient;
        q->back = newClient;
    }else {
        (q->back)->next = newClient;
        q->back = newClient;
    }
}

void pop(queue *q) {
    if(empty(q)) {
        cout << "Underflow" << endl;
        return;
    }
    client *newClient = q->front;
    q->front = q->front->next;

    if(q->front == NULL) {
        q->back = NULL;
    }

    delete(newClient);
}
