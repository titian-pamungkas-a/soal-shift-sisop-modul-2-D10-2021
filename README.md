# soal-shift-sisop-modul-2-D10-2021

## **Soal 1**

Konsep pada soal 1 yaitu dengan membuat child setiap melakukan exec, agar tidak berhenti setelah melakukan exec.

### **a. Membuat folder Fylm, Pyoto, dan Musyik**

C memiliki fungsi mkdir() untuk membuat folder, tetapi kita menggunakan exec dan menggunakan shell untuk membuat folder

![WhatsApp Image 2021-04-25 at 16 12 33](https://user-images.githubusercontent.com/77373958/115996801-009be580-a60b-11eb-8074-bb8d5cf15eab.jpeg)
![WhatsApp Image 2021-04-25 at 16 11 48](https://user-images.githubusercontent.com/77373958/115996803-01cd1280-a60b-11eb-83e8-59ecf6c6ee6d.jpeg)
![WhatsApp Image 2021-04-25 at 16 11 06](https://user-images.githubusercontent.com/77373958/115996805-0265a900-a60b-11eb-9ea8-a3b77cc1f2c8.jpeg)
![WhatsApp Image 2021-04-25 at 16 10 41](https://user-images.githubusercontent.com/77373958/115996807-0396d600-a60b-11eb-83a1-4bdae7ed245b.jpeg)
![WhatsApp Image 2021-04-25 at 16 10 10](https://user-images.githubusercontent.com/77373958/115996808-0396d600-a60b-11eb-8fd9-e9a5b00ac938.jpeg)
![WhatsApp Image 2021-04-25 at 16 09 25](https://user-images.githubusercontent.com/77373958/115996809-042f6c80-a60b-11eb-9148-e7bd77d5c7c9.jpeg)
![WhatsApp Image 2021-04-25 at 16 08 01](https://user-images.githubusercontent.com/77373958/115996810-04c80300-a60b-11eb-8c60-f2afd7a2fb86.jpeg)

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



## **Soal 2**

### **a. Membuat dir dengan path tertera dan unzip ke dir tersebut**

Sebelumnya, kita perlu mendownload pets.zip yang ada pada drive. Hasil download akan ada pada dir /home/tito/download, tetapi kita perlu zip ke dir /home/tito/modul2/petshop. Sebelum dizip ke dir tersebut, kita perlu membuat dir tersebut terlebih dahulu. Diperintahkan untuk menghapus folder yang ada di dalam zip, tetapi dapat dilakukan dengan cara lain, yaitu tidak perlu zip folder, hanya file.



Kendala
- Kesulitan mengerjakan 2b. .......
- Terdapat anggota kelompok yang tidak berkontribusi




