#include <stdio.h>
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
        printf("Stack đã bị đầy!");
        return;
    }

    // Nếu Stack còn bộ nhớ thì tiến hành thêm vào
    s->data[++s->top] = value;
}
// Hàm in danh sách
void printElements(Stack *s){
    // Kiểm tra Stack rỗng
    if (s->top == -1){
        printf("Stack dang rong!");
        return;
    }
    // In danh sách
    for (int i =0; i <= s->top; i++) {
        printf("%d \n", s->data[i]);
    }

}
int main() {
    Stack s;
    initialStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    // Nhập và thêm 5 phần
    int value;
    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < 5; i++){
        printf("");
        scanf("%d", &value);
        push(&s, value);
    }
    // In kết quả
    printElements(&s);

    return 0;
}