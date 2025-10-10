#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
    // Hitung ukuran dua bagian array
    int ukuran_kiri = mid - left + 1;    // Ukuran bagian kiri
    int ukuran_kanan = right - mid;      // Ukuran bagian kanan

    // Buat array sementara untuk menampung data
    vector<int> bagian_kiri(ukuran_kiri), bagian_kanan(ukuran_kanan);

    // Salin data ke array bagian kiri
    for (int i = 0; i < ukuran_kiri; i++)
        bagian_kiri[i] = arr[left + i];
    
    // Salin data ke array bagian kanan
    for (int j = 0; j < ukuran_kanan; j++)
        bagian_kanan[j] = arr[mid + 1 + j];

    // Gabungkan kedua bagian dengan membandingkan elemen satu per satu
    int i = 0;      // Penunjuk bagian kiri
    int j = 0;      // Penunjuk bagian kanan
    int k = left;   // Penunjuk posisi penggabungan

    // Bandingkan elemen dari kedua bagian dan masukkan yang lebih kecil
    while (i < ukuran_kiri && j < ukuran_kanan) {
        if (bagian_kiri[i] <= bagian_kanan[j]) {
            arr[k] = bagian_kiri[i];  // Ambil dari kiri jika lebih kecil
            i++;
        } else {
            arr[k] = bagian_kanan[j]; // Ambil dari kanan jika lebih kecil
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari bagian kiri (jika ada)
    while (i < ukuran_kiri) {
        arr[k] = bagian_kiri[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari bagian kanan (jika ada)
    while (j < ukuran_kanan) {
        arr[k] = bagian_kanan[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk mengurutkan dengan metode divide and conquer
void mergeSort(vector<int>& arr, int left, int right) {
    // Kondisi berhenti: jika bagian hanya memiliki 0 atau 1 elemen
    if (left >= right)
        return;

    // Cari titik tengah untuk membagi array
    int mid = left + (right - left) / 2;

    // Urutkan bagian kiri (dari kiri sampai tengah)
    mergeSort(arr, left, mid);
    
    // Urutkan bagian kanan (dari tengah+1 sampai kanan)
    mergeSort(arr, mid + 1, right);
    
    // Gabungkan kedua bagian yang sudah terurut
    merge(arr, left, mid, right);
}

// Fungsi untuk menampilkan isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Program utama
int main() {
    int jumlah_elemen;
    cout << "Masukkan jumlah elemen data: ";
    cin >> jumlah_elemen;
    
    // Buat array dengan ukuran yang dimasukkan user
    vector<int> data(jumlah_elemen);
    
    cout << "Masukkan elemen-elemen data: ";
    // Baca setiap elemen dari input user
    for (int i = 0; i < jumlah_elemen; i++) {
        cin >> data[i];
    }
    
    // Tampilkan data sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);
    
    // Panggil fungsi merge sort untuk mengurutkan data
    mergeSort(data, 0, jumlah_elemen - 1);
    
    // Tampilkan hasil setelah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);
    
    return 0;
}



