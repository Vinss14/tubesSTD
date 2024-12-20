# tubesSTD
repository ini berisi tugas besar struktur data, Telkom university, Fakultas Informatika, Prodi Sains Data. Terdapat 2 versi dalam repository ini (untuk sistem operasi windows dan sistem operasi macOS/linux). Implementasi kode dalam bahasa c++.

PETUNJUK INPUT DALAM PROGRAM:
1. Run program
2. Tekan '.' untuk mengakhiri program (selesai mengetik)
3. Tekan 'BACKSPACE' untuk menghapus karakter pada ketikan anda
4. Tekan 'ENTER' untuk berpindah/membuat baris baru
5. Tekan 'ARROW LEFT' untuk memindahkan cursor ke kiri
6. Tekan 'ARROW RIGHT' untuk memindahkan cursor ke kanan
7. Tekan 'ARROW UP' untuk memindahkan cursor ke baris sebelumnya (baris atas)
8. Tekan 'ARROW DOWN' untuk memindahkan cursor ke baris setelahnya (baris bawah)
9. Tekan '<' untuk undo
10. Tekan '>' untuk redo

PANDUAN PENGGUNAAN UNTUK SISTEM OPERASI WINDOWS
   - cara 1 :
     1. pastikan codeblocks terinstall
     2. copy program secara manual, lalu pindahkan ke codeblocks anda
     3. lalu run program sesuai petunjuk input di bagian awal
    
   - cara 2 (dari cmd/terminal) :
     1. Unduh MinGW.
        Kunjungi website "MinGW-w64" untuk mengunduh installer.
        
     2. Install MinGW.
        Pastikan anda mengikut petunjuk pada website dan memilih paket GCC selama instalasi
        
     3. Tambahkan ke PATH. Tambahkan direktori MinGW (misalnya, C:\MinGW\bin) ke variabel lingkungan PATH.
        Buka Control Panel > System > Advanced system settings.
        Klik tombol Environment Variables.
        Di bagian System variables, cari variabel bernama Path, lalu klik Edit.
        Tambahkan direktori C:\MinGW\bin (atau lokasi instalasi MinGW Anda) ke daftar.
        
     4. Periksa Instalasi. Jalankan perintah di Command Prompt:
        g++ --version (jika sudah ada akan keluar versi g++)
        
     5. clone repository github ini, jalankan di cmd:
        git clone https://github.com/Vinss14/tubesSTD.git
        
     6. masuk ke folder tubesSTD, jalankan perintah:
        cd tubesSTD

     7. kompilasi file dengan mengetik perintah di cmd:
        g++ main.cpp stack.cpp list.cpp -o textEditor

     8. run program dengan perintah:
        ./textEditor
        
PANDUAN PENGGUNAAN UNTUK SISTEM OPERASI MACOS

* Untuk penggunaan pada sistem operasi MACOS disarankan untuk menggunakan cara ke 2, karena jika menggunakan cara 1 terminal pada xcode tidak mensupport library getch()

    - cara 1 :
    1. pastikan xcode terinstall
    2. copy program secara manual, lalu pindahkan ke xcode anda
    3. lalu run program sesuai petunjuk input di bagian awal
    
    - cara 2 (dari terminal) :
    1. pastikan brew terinstall pada mac anda
    2. jalankan perintah di terminal:
       brew install gcc
    3. Periksa Instalasi: Pastikan g++ sudah terinstal:
       g++ --version
    4. clone repository github ini, jalankan di terminal:
       git clone https://github.com/Vinss14/tubesSTD.git
    5. kompilasi file dengan mengetik perintah di terminal:
       g++ main.cpp stack.cpp list.cpp -o textEditor
    6. Masuk ke folder repository, dengan perintah:
       cd tubesSTD
    7. run program dengan perintah:
       ./textEditor
        
     

  
   
   
    
   
