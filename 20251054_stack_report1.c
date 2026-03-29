int main() {
    Stack s;
    char storage[MAX] = { 0, };
    int i = 0;
    initStack(&s);

    printf("문자열을 입력하세요: ");
    gets(storage);

    while (storage[i] != NULL) {
        push(&s, storage[i]);
        i++;
    }
    i = 0;
    printf("거꾸로 출력된 문자열: ");
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
        i++;
    }
    return 0;
}