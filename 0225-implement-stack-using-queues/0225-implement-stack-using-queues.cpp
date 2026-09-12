class MyStack {
private:
    queue<int> elements;

public:
    MyStack() {
    }

    void push(int x) {
        elements.push(x);

        int previousSize = elements.size() - 1;
        while (previousSize--) {
            elements.push(elements.front());
            elements.pop();
        }
    }

    int pop() {
        int topElement = elements.front();
        elements.pop();
        return topElement;
    }

    int top() {
        return elements.front();
    }

    bool empty() {
        return elements.empty();
    }
};