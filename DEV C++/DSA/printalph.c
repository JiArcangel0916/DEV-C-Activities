#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NUM_PRODUCTS 5
#define VAT_RATE 0.12

typedef struct {
    int product_no;
    char product_name[50];
    float unit_price;
    int quantity;
    float total_price;
} Product;

typedef struct Node {
    Product product;
    struct Node *next;
    struct Node *prev;
} Node;

// Function to compute the total price for a product
void compute_total_price(Product *p) {
    p->total_price = p->unit_price * p->quantity;
}

// Function to compute the total price including VAT for array implementation
float compute_total_with_vat_array(Product products[], int size) {
    float total = 0.0;
    int i;
    for (i = 0; i < size; i++) {
        total += products[i].total_price;
    }
    return total + (total * VAT_RATE);
}

// Function to display products in an array
void display_products_array(Product products[], int size) {
	int i;
    printf("%-10s%-15s%-12s%-10s%-12s\n", "Product No.", "Product Name", "Unit Price", "Quantity", "Total Price");
    for (i = 0; i < size; i++) {
        printf("%-10d%-15s%-12.2f%-10d%-12.2f\n", products[i].product_no, products[i].product_name, products[i].unit_price, products[i].quantity, products[i].total_price);
    }
}

// Function to add a product to the doubly linked list
void append_product(Node **head, Node **tail, int product_no, char *product_name, float unit_price, int quantity) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->product.product_no = product_no;
    strcpy(new_node->product.product_name, product_name);
    new_node->product.unit_price = unit_price;
    new_node->product.quantity = quantity;
    compute_total_price(&new_node->product);
    new_node->next = NULL;
    new_node->prev = *tail;

    if (*tail) {
        (*tail)->next = new_node;
    } else {
        *head = new_node;
    }

    *tail = new_node;
}

// Function to compute the total price including VAT for doubly linked list implementation
float compute_total_with_vat_dll(Node *head) {
    float total = 0.0;
    Node *current = head;
    while (current) {
        total += current->product.total_price;
        current = current->next;
    }
    return total + (total * VAT_RATE);
}

// Function to display products in a doubly linked list
void display_products_dll(Node *head) {
    printf("%-10s%-15s%-12s%-10s%-12s\n", "Product No.", "Product Name", "Unit Price", "Quantity", "Total Price");
    Node *current = head;
    while (current) {
        printf("%-10d%-15s%-12.2f%-10d%-12.2f\n", current->product.product_no, current->product.product_name, current->product.unit_price, current->product.quantity, current->product.total_price);
        current = current->next;
    }
}

// Function to free the memory allocated for the doubly linked list
void free_list(Node *head) {
    Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Function to simulate gotoxy using spaces and new lines
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

// Function for array-based implementation
void array_based_implementation() {
    Product products[NUM_PRODUCTS] = {
        {1, "Coke", 15.00, 0, 0.0},
        {2, "Sprite", 20.00, 0, 0.0},
        {3, "Pepsi", 18.00, 0, 0.0},
        {4, "Fanta", 22.00, 0, 0.0},
        {5, "Mountain Dew", 25.00, 0, 0.0}
    };

    int selected_product, i;
    for (i = 0; i < NUM_PRODUCTS; i++) {
        printf("%d. %s\n", i + 1, products[i].product_name);
    }

    for (i = 0; i < NUM_PRODUCTS; i++) {
        printf("Select a product (1-5) and enter quantity: ");
        scanf("%d", &selected_product);
        if (selected_product < 1 || selected_product > NUM_PRODUCTS) {
            printf("Invalid selection\n");
            i--;
            continue;
        }
        printf("Enter quantity for %s: ", products[selected_product - 1].product_name);
        scanf("%d", &products[selected_product - 1].quantity);
        compute_total_price(&products[selected_product - 1]);
    }

    printf("Array-based Implementation:\n");
    display_products_array(products, NUM_PRODUCTS);
    float total_with_vat_array = compute_total_with_vat_array(products, NUM_PRODUCTS);
    printf("Total price including 12%% VAT: %.2f\n", total_with_vat_array);
}

// Function for doubly linked list-based implementation
void dll_based_implementation() {
    Node *head = NULL;
    Node *tail = NULL;
    int selected_product, i;
    int quantities[NUM_PRODUCTS] = {0};

    Product products[NUM_PRODUCTS] = {
        {1, "Coke", 15.00, 0, 0.0},
        {2, "Sprite", 20.00, 0, 0.0},
        {3, "Pepsi", 18.00, 0, 0.0},
        {4, "Fanta", 22.00, 0, 0.0},
        {5, "Mountain Dew", 25.00, 0, 0.0}
    };

    for (i = 0; i < NUM_PRODUCTS; i++) {
        printf("%d. %s\n", i + 1, products[i].product_name);
    }

    for (i = 0; i < NUM_PRODUCTS; i++) {
        printf("Select a product (1-5) and enter quantity: ");
        scanf("%d", &selected_product < 1 || selected_product > NUM_PRODUCTS); 
            printf("Invalid selection\n");
            i--;
            continue;
        }
        printf("Enter quantity for %s: ", products[selected_product - 1].product_name);
        scanf("%d", &quantities[selected_product - 1]);
        append_product(&head, &tail, products[selected_product - 1].product_no, products[selected_product - 1].product_name, products[selected_product - 1].unit_price, quantities[selected_product - 1]);
    }

    printf("Doubly Linked List Implementation:\n");
    display_products_dll(head);
    float total_with_vat_dll = compute_total_with_vat_dll(head);
    printf("Total price including 12%% VAT: %.2f\n", total_with_vat_dll);

    free_list(head);
}

int main() {
    int choice;
    printf("Select implementation:\n");
    printf("1. Array-based implementation\n");
    printf("2. Doubly linked list implementation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            array_based_implementation();
            break;
        case 2:
            dll_based_implementation();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

