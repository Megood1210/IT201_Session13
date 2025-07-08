#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

// Thêm phần tử vào Stack
void push(Stack *s, int value){
    // Trước khi push thì cần kiểm tra xem stack có đủ bọ nhớ không
    if(isFull(s)){
        printf("Stack da bi day");
        return;
    }

    // Nếu Stack còn bộ nhớ thì tiến hành thêm vào
    s->data[++s->top] = value;
}
// Lấy phần tử trên cùng
int pop(Stack *s){
    // Kiểm tra xem Stack có bị rỗng không?
    if (isEmpty(s)){
        printf("Stack đang rỗng!");
        return -1;
    }

    return s->data[s->top--];
}
// Hàm kiểm tra cặp dấu ngoặc
int isMatching(char open, char close) {
    char opens[] = "({["; // Khai báo ngoặc mở
    char closes[] = ")}]"; // Khai báo ngoặc đóng
    // Duyệt qua từng cặp dấu ngoặc
    for (int i = 0; i < 3; i++) {
        // Kiểm tra ngoặc mở khớp với phần tử
        if (open == opens[i]) {
            return close == closes[i]; // Kiểm tra xem dấu ngoặc đóng khớp với phần tử
        }
    }
    return 0;
}
// Hàm kiểm tra tính hợp lệ của dấu ngoặc trong một biểu thức
int isValidBracket(char *bracket)
{
    Stack s; // Khởi tạo Stack để lưu
    initialStack(&s); // Khởi tạo Stack rỗng
    // Duyệt từng ký tự trong biểu thức
    for (int i = 0; i < strlen(bracket); i++) {
        char ch = bracket[i]; // // Lấy từng ký tự trong chuỗi
        // Nếu là dấu ngoặc mở thì đẩy vào stack
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
            // Kiểm dấu ngoặc đóng
        } else if (ch == ')' || ch == ']' || ch == '}') {
            // Kiểm tra Stack rỗng hoặc cặp ngoặc không khớp
            if (isEmpty(&s) || !isMatching(pop(&s), ch)) {
                return 0;
            }
        }
    }
    return isEmpty(&s); // Trả về true (1) nếu hợp lệ, false (0) nếu không
}
int main() {
    char expr[MAX];
    // Nhập biểu thức bất kỳ
    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Xóa ký tự newline
    // Kiểm tra dấu ngoặc của biểu thức đã nhập
    if (isValidBracket(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}

