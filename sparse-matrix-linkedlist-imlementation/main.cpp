#include <iostream>
using namespace std;

class MatrixNode {
public:
    int rowPos;
    int colPos;
    int value;
    MatrixNode *next;
};

void createMatrixNode(MatrixNode **head, int rowPos, int colPos, int value) {
    MatrixNode *newNode = new MatrixNode();
    newNode->rowPos = rowPos;
    newNode->colPos = colPos;
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        MatrixNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printSparseMatrix(MatrixNode *head) {
    MatrixNode *temp = head;
    cout << "Row positions: ";
    while (temp != NULL) {
        cout << temp->rowPos << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    cout << "Column positions: ";
    while (temp != NULL) {
        cout << temp->colPos << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    cout << "Values: ";
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid matrix dimensions!" << endl;
        return 1;
    }

    int **sparseMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        sparseMatrix[i] = new int[cols];
    }

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> sparseMatrix[i][j];
        }
    }

    MatrixNode *head = NULL;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                createMatrixNode(&head, i, j, sparseMatrix[i][j]);
            }
        }
    }

    printSparseMatrix(head);

    for (int i = 0; i < rows; i++) {
        delete[] sparseMatrix[i];
    }
    delete[] sparseMatrix;

    MatrixNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
