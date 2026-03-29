int main() {
    Stack s;
    int i = 0;
    int isValid = 1;
    char text[MAX] = { 0, };
    initStack(&s);

    printf("문자열을 입력하세요: ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = '\0';
    while (text[i] != NULL) {
        char ch = text[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, text[i]);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatching(pop(&s), ch)) {
                isValid = 0;
                break;
            }
        }
        i++;
    }
    if (!isEmpty(&s))
        isValid = 0;
    if (isValid)
        printf("유효한 괄호\n");
    else
        printf("유효하지 않은 괄호\n");

    return 0;
}