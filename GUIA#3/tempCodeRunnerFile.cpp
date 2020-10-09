int main() {
    Stack bookStack;
    initialize(&bookStack);

    push(&bookStack, "Libro 1", 250);
    push(&bookStack, "Libro 2", 150);
    push(&bookStack, "Libro 3", 175);
    push(&bookStack, "Libro 4", 200);

    string title;
    cout << "Ingrese el titulo del libro: " << endl;
    getline(cin, title);

    findBookPages(&bookStack, title);

}