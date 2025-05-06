#include <iostream>
#include <string>

using namespace std;

// Node class for LinkedList and Queue
class Node {
public:
    string nama;
    string nomorTelepon;
    Node* next;

    Node(string n, string no) {
        nama = n;
        nomorTelepon = no;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahKontak(string nama, string nomorTelepon) {
        Node* nodeBaru = new Node(nama, nomorTelepon);
        if (head == nullptr) {
            head = nodeBaru;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nodeBaru;
        }
        cout << "Kontak berhasil ditambahkan ke LinkedList.\n";
    }

    void lihatKontak() {
        if (head == nullptr) {
            cout << "Daftar kontak kosong.\n";
            return;
        }
        Node* temp = head;
        int nomor = 1;
        cout << "Daftar Kontak (LinkedList):\n";
        while (temp != nullptr) {
            cout << nomor << ". Nama: " << temp->nama << ", Nomor Telepon: " << temp->nomorTelepon << endl;
            temp = temp->next;
            nomor++;
        }
    }

    void hapusKontak(string nama) {
        if (head == nullptr) {
            cout << "Daftar kontak kosong, tidak ada yang dihapus.\n";
            return;
        }

        if (head->nama == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Kontak dengan nama \"" << nama << "\" berhasil dihapus dari LinkedList.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->nama != nama) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Kontak dengan nama \"" << nama << "\" tidak ditemukan di LinkedList.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Kontak dengan nama \"" << nama << "\" berhasil dihapus dari LinkedList.\n";
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string nama, string nomorTelepon) {
        Node* nodeBaru = new Node(nama, nomorTelepon);
        if (rear == nullptr) {
            front = rear = nodeBaru;
        } else {
            rear->next = nodeBaru;
            rear = nodeBaru;
        }
        cout << "Kontak berhasil dimasukkan ke antrian.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Antrian kosong, tidak ada yang dihapus.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Kontak dengan nama \"" << temp->nama << "\" dikeluarkan dari antrian.\n";
        delete temp;
    }

    void lihatAntrian() {
        if (front == nullptr) {
            cout << "Antrian kosong.\n";
            return;
        }
        Node* temp = front;
        int nomor = 1;
        cout << "Daftar Antrian Kontak:\n";
        while (temp != nullptr) {
            cout << nomor << ". Nama: " << temp->nama << ", Nomor Telepon: " << temp->nomorTelepon << endl;
            temp = temp->next;
            nomor++;
        }
    }
};

// TreeNode and Tree class for Binary Search Tree
class TreeNode {
public:
    string nama;
    string nomorTelepon;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string n, string no) {
        nama = n;
        nomorTelepon = no;
        left = right = nullptr;
    }
};

class Tree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, string nama, string nomorTelepon) {
        if (node == nullptr) {
            return new TreeNode(nama, nomorTelepon);
        }
        if (nama < node->nama) {
            node->left = insert(node->left, nama, nomorTelepon);
        } else if (nama > node->nama) {
            node->right = insert(node->right, nama, nomorTelepon);
        } else {
            cout << "Kontak dengan nama \"" << nama << "\" sudah ada di Tree.\n";
        }
        return node;
    }

    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << "Nama: " << node->nama << ", Nomor Telepon: " << node->nomorTelepon << endl;
            inorder(node->right);
        }
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, string nama) {
        if (root == nullptr) {
            cout << "Kontak dengan nama \"" << nama << "\" tidak ditemukan di Tree.\n";
            return root;
        }
        if (nama < root->nama) {
            root->left = deleteNode(root->left, nama);
        } else if (nama > root->nama) {
            root->right = deleteNode(root->right, nama);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                cout << "Kontak dengan nama \"" << nama << "\" berhasil dihapus dari Tree.\n";
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                cout << "Kontak dengan nama \"" << nama << "\" berhasil dihapus dari Tree.\n";
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->nama = temp->nama;
            root->nomorTelepon = temp->nomorTelepon;
            root->right = deleteNode(root->right, temp->nama);
        }
        return root;
    }

public:
    Tree() {
        root = nullptr;
    }

    void tambahKontak(string nama, string nomorTelepon) {
        root = insert(root, nama, nomorTelepon);
    }

    void lihatKontak() {
        if (root == nullptr) {
            cout << "Daftar kontak kosong.\n";
            return;
        }
        cout << "Daftar Kontak (Tree Inorder):\n";
        inorder(root);
    }

    void hapusKontak(string nama) {
        root = deleteNode(root, nama);
    }
};

int main() {
    LinkedList daftarLinkedList;
    Queue daftarQueue;
    Tree daftarTree;

    int pilihanUtama;
    do {
        cout << "\n=== Pilih Struktur Data ===\n";
        cout << "1. Linked List\n";
        cout << "2. Queue\n";
        cout << "3. Tree\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihanUtama;
        cin.ignore();

        if (pilihanUtama == 4) {
            cout << "Terima kasih telah menggunakan aplikasi.\n";
            break;
        }

        int pilihanSub;
        string nama, nomorTelepon;

        switch (pilihanUtama) {
        case 1:
            do {
                cout << "\n--- Linked List ---\n";
                cout << "1. Tambah Kontak\n";
                cout << "2. Lihat Daftar Kontak\n";
                cout << "3. Hapus Kontak\n";
                cout << "4. Kembali ke menu utama\n";
                cout << "Pilih: ";
                cin >> pilihanSub;
                cin.ignore();

                switch (pilihanSub) {
                case 1:
                    cout << "Masukkan nama: ";
                    getline(cin, nama);
                    cout << "Masukkan nomor telepon: ";
                    getline(cin, nomorTelepon);
                    daftarLinkedList.tambahKontak(nama, nomorTelepon);
                    break;
                case 2:
                    daftarLinkedList.lihatKontak();
                    break;
                case 3:
                    cout << "Masukkan nama kontak yang ingin dihapus: ";
                    getline(cin, nama);
                    daftarLinkedList.hapusKontak(nama);
                    break;
                case 4:
                    break;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi.\n";
                }
            } while (pilihanSub != 4);
            break;

        case 2:
            do {
                cout << "\n--- Queue ---\n";
                cout << "1. Tambah Kontak (Enqueue)\n";
                cout << "2. Hapus Kontak (Dequeue)\n";
                cout << "3. Lihat Antrian Kontak\n";
                cout << "4. Kembali ke menu utama\n";
                cout << "Pilih: ";
                cin >> pilihanSub;
                cin.ignore();

                switch (pilihanSub) {
                case 1:
                    cout << "Masukkan nama: ";
                    getline(cin, nama);
                    cout << "Masukkan nomor telepon: ";
                    getline(cin, nomorTelepon);
                    daftarQueue.enqueue(nama, nomorTelepon);
                    break;
                case 2:
                    daftarQueue.dequeue();
                    break;
                case 3:
                    daftarQueue.lihatAntrian();
                    break;
                case 4:
                    break;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi.\n";
                }
            } while (pilihanSub != 4);
            break;

        case 3:
            do {
                cout << "\n--- Tree ---\n";
                cout << "1. Tambah Kontak\n";
                cout << "2. Lihat Daftar Kontak\n";
                cout << "3. Hapus Kontak\n";
                cout << "4. Kembali ke menu utama\n";
                cout << "Pilih: ";
                cin >> pilihanSub;
                cin.ignore();

                switch (pilihanSub) {
                case 1:
                    cout << "Masukkan nama: ";
                    getline(cin, nama);
                    cout << "Masukkan nomor telepon: ";
                    getline(cin, nomorTelepon);
                    daftarTree.tambahKontak(nama, nomorTelepon);
                    break;
                case 2:
                    daftarTree.lihatKontak();
                    break;
                case 3:
                    cout << "Masukkan nama kontak yang ingin dihapus: ";
                    getline(cin, nama);
                    daftarTree.hapusKontak(nama);
                    break;
                case 4:
                    break;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi.\n";
                }
            } while (pilihanSub != 4);
            break;

        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (true);

    return 0;
}