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
// Hàm đảo ngược mảng
void reverse(int arr[], int n)
{
    Stack s;
    initialStack(&s);
    // Đưa các phần tử vào stack
    for (int i = 0; i < n; i++){
        push(&s, arr[i]);
    }
    // Lấy các phần tử từ stack ra để đảo ngược
    for (int i = 0; i < n; i++){
        arr[i] = pop(&s);
    }

}
// Hàm in mảng
void printArray(int arr[], int n){
    // Duyệt qua mảng
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
        if (i < n - 1){
            printf(",");
        }
    }
    printf("]");
}
int main() {
    int n, arr[MAX];
    // Nhập số phần tử trong mảng
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    // Nhập giá trị từng phần tử trong 1 mảng
    for (int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Đảo ngược mảng
    reverse(arr, n);
    // In kết quả
    printArray(arr, n);
    return 0;
}