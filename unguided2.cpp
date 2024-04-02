#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertBelakang(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->namaProduk << "\t" << current->harga << endl;
            current = current->next;
        }
    }

    void deleteAll()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main()
{
    DoublyLinkedList list;
    // Menambahkan data
    list.insertBelakang("Originote", 60000);
    list.insertBelakang("Somethinc", 150000);
    list.insertBelakang("Skintific", 100000);
    list.insertBelakang("Wardah", 50000);
    list.insertBelakang("Hanasui", 30000);

    int choice;
    string namaProduk;
    int harga;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data Urutan Tertentu\n";
        cout << "5. Hapus Data Urutan Tertentu\n";
        cout << "6. Hapus Seluruh Data\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Exit\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan nama produk: ";
            cin >> namaProduk;
            cout << "Masukkan harga: ";
            cin >> harga;
            list.insertBelakang(namaProduk, harga);
            break;
        case 2:
            // Tambahkan fungsi hapus data
            break;
        case 3:
            // Tambahkan fungsi update data
            break;
        case 4:
            // Tambahkan fungsi tambah data urutan tertentu
            break;
        case 5:
            // Tambahkan fungsi hapus data urutan tertentu
            break;
        case 6:
            list.deleteAll();
            cout << "Data telah dihapus semua.\n";
            break;
        case 7:
            cout << "Nama Produk\tHarga" << endl;
            list.display();
            break;
        case 8:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}
