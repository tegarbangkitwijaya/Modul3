#include <iostream>
#include <string>
using namespace std;
// Deklarasi Struct Node
struct Node
{
    string nama;
    int usia;
    Node *next;
};
Node *head = nullptr;
// Fungsi untuk menambahkan data di depan linked list
void insertDepan(string nama, int usia)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}
// Fungsi untuk menambahkan data di belakang linked list
void insertBelakang(string nama, int usia)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Fungsi untuk menambahkan data di tengah linked list
void insertTengah(string nama, int usia, string nama_sebelumnya)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->nama == nama_sebelumnya)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}
// Fungsi untuk menampilkan seluruh data
void tampilkanData()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->nama << " " << temp->usia << endl;
        temp = temp->next;
    }
}
int main()
{
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan nama anda: ";
    getline(cin, namaAnda);
    cout << "Masukkan usia anda: ";
    cin >> usiaAnda;
    cin.ignore();
    insertDepan("Igor", 20);
    insertBelakang("Tegar", 19);
    insertBelakang("John", 19);
    insertBelakang("Futba", 18);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Reyn", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);
    cout << "Data Mahasiswa:" << endl;
    tampilkanData();
    return 0;
}