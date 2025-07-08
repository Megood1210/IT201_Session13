#include <stdio.h>
#include <string.h>
#define MAX 100

// Khai báo cấu trúc Stack
typedef struct Stack {
    int data[MAX]; // Mảng chứa các phân tử của Stack
    int top; // Chỉ số phần tử đỉnh
} Stack;

// Khởi tạo Stack
void initialStack(Stack *s){
    s->top = -1; // Ban đầu stack rỗng
}
// Hàm kiểm tra xem Stack đã đầy hay chưa?
int isFull(Stack *s){
    return s->top == MAX - 1;
}
// Kiểm tra Stack có bị rỗng?
int isEmpty(Stack *s){
    return s->top == -1;
}
// // Đẩy phần tử vào stack
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

// Lấy phần tử ra khỏi stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; // nếu rỗng
}

// Hàm kiểm tra chuỗi đối xứng
int isPalindrome(char str[]) {
    Stack s;
    initialStack(&s);

    int len = strlen(str);

    // Đẩy nửa đầu chuỗi vào stack
    for (int i = 0; i < len / 2; i++) {
        push(&s, str[i]);
    }

    // Nếu chuỗi lẻ, bỏ qua ký tự giữa
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    // So sánh với nửa sau
    for (int i = start; i < len; i++) {
        if (pop(&s) != str[i]) {
            return 0; // false
        }
    }
    return 1; // true
}

// Hàm chính
int main() {
    char str[MAX];
    // Nhập chuỗi
    printf("Nhap chuoi: ");
    fgets(str, MAX, stdin);
    // Xóa ký tự '\n'
    str[strcspn(str, "\n")] = '\0';
    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false \n");
    }

    return 0;
}


