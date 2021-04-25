# soal-shift-sisop-modul-2-D10-2021

## **Soal 1**

Konsep pada soal 1 yaitu dengan membuat child setiap melakukan exec, agar tidak berhenti setelah melakukan exec.

### **a. Membuat folder Fylm, Pyoto, dan Musyik**

C memiliki fungsi mkdir() untuk membuat folder, tetapi kita menggunakan exec dan menggunakan shell untuk membuat folder

gambar

Agar program tidak berhenti saat sudah melakukan exec, maka kita membuat child lagi sehingga dapat melakukan exec lagi, berlaku juga untuk cara seterusnya.

### **b. Download zip dari link yang ada**

Untuk mendownload di google drive, kita dapat menggunakan exec wget dengan format yang sudah disediakan pada modul. Terdapat 3 file yang perlu didwonload, yang berarti perlu 3 child untuk setiap download tersebut.

gambar

### **c. Extract zip**

Pada setiap hasil download, kita perlu mengunzip satu-satu setiap filenya. Isi dari zip tersebut merupakan folder, sehingga ketika diunzip akan menghasilkan 3 folder total. Sama seperti sebelumnya, kita perlu membuat 3 child untuk setiap kali unzip.

gambar

Hasil dari unzip terdapat pada directory tersebut

### **d. Memindahkan pada dir yang telah dibuat**

Memindahkan file isi dari unzip ke dalam dir yang tadi telah dibuat sesuai ketentuan (musik ke Musyik, dll.) dapat menggunakan mv. Syaratnya adalah dir harus kosong, karena itulah tadi perlu diunzip di luar dir tujuan

gambar

### **e. membuat program berjalan otomatis pada waktu yang ditentukan**

Program yang dibuat harus berjalan otomatis di latar belakang dan bekerja pada pukul yang telah ditentukan. Untuk mengecek waktunya, kita membuat sebuah array of char sebagai karakter waktu sekarang dan membandingkan dengan waktu yang diinginkan dalam while loop. Jika masih tidak sesuai, maka program akan terus berulang sampai sesuai.

gambar

### **f. zip dan delete file pada waktu yang ditentukan**

Menggunakan cara yang sama dengan e untuk masalah waktu. zip semua dir menjadi satu dengan format Lopyu_Stevany.zip, kemudian menghapus sisanya.

gambar

Kendala
- Sering terjadi error saat multiple child
- Access denied, meskipun sudah diubah ke umum semua
- Mencari bagaimana membandingkan waktu
- Kesulitan karena program sempat tidak berjalan ketika digunakan daemon






