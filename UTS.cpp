#include <iostream>
#include <string>

using namespace std;


        //membuat function bernama hitung honor lembur yang menerima input angka (int jamKerja)
        // dan akan mengembalikan hasil berupa angka juga (int)
int HitungHonorLembur(int jamKerja) {
    
/*point c :ketentuan lembir dihitung dari kelebihan jam kerja pegawai tersebut. jam kerja normal
pegawai sebanyak 8 jam.*/
    //menyiapkan variable lokal. batas kerja normal adalah 8 jam, dan tarif
    int jamNormal = 8;
    int honorLemburPerJam = 10000;
    if (jamKerja > jamNormal) {
        //jika misal jam kerja nya adalah 9 , maka dikurangi 8 , dan menghasilkan 1
        int kelebihanJam = jamKerja - jamNormal;
        //kemudian mengambil hasil dari penghitungan dari variable kelebihan jam kerja dikali honor lembur , yaitu 10000
        //jadii hasil akhirnya adalah 1 dikali 10000 = 10000
        return kelebihanJam * honorLemburPerJam;
    }else {
        return 0; //jika tidak ada kelebihan jam kerja
    }
}

int main (){ //awal dari fungsi utama program
    int banyakData ;//variable untuk menyimpan jumlah pegawai
    int honorharian = 80000;//menetapkan honor harian sebesar 80.000

//point a : masukkan banyak data yang diinginkan
    cout<<"masukkan banyak data pegawai : ";//untuk input banyaknya pegawai
    cin>>banyakData;//mengambil input jumlah pegawai dari user

    //deklarasi array dasar untuk menyimpa  data pegawai
    string namaPegawai[banyakData];//array untuk menyimpan nama nama pegawai
    int jamKerjaPegawai[banyakData];//array untuk menyimpan jam kerja tiap pegawai
    int honorlembur[banyakData];//array untuk menyimpan nilai honor lembur pegawai
    int totalHonor[banyakData];//array untuk menyimpan nilai total honor yang diterima pegawai


    //input dtaa pegawai menggunakan perulangan basic
    for (int i=0;i<banyakData; i++){//perulangan untuk memproses data pegawai satu2 dari indeks 0
        cout <<"\n data pegawai ke-"  <<(i+1)<<endl;//menampilkan nomor urut data pegawai yang di inputkan
        cout<<"masukkan nama pegawai : ";//menampilkan intruksi input nama pegawai
        cin.ignore();//membersihkan sisa karakter 'enter' di memori agar input nama tidak terlewati
        getline(cin, namaPegawai[i]);//mengambil input nama lengkap (termasuk spasi) dalam array
        cout<<"masukkan jam kerja : ";//menampilkan intruksi input jam kerja
        cin>> jamKerjaPegawai[i];//mengambil input angka jam kerja pegawai ke dalam array

        //loop untuk menambahkan batas gajipekerja dalam satu hari
        while (jamKerjaPegawai[i] <0 || jamKerjaPegawai[i]>24){//validasi jika jam kerja kurang dari 0 ata lebih dari 24
            cout<<"input tidak valid! jam kerja dalam satu hari harus antara 0-24 jam.\n";//menampilkan peringatan jika slaah input jam
            cout<<"masukkan kembali jam kerja : ";//meminta user untuk memasukkan ulang jam kerja vang benar
            cin>>jamKerjaPegawai[i];//mengambil kembali input jam kerja yang baru dari user
        }

//point b : memanggil function unutk menghitung honor lembur
        honorlembur[i] = HitungHonorLembur(jamKerjaPegawai[i]);//panggil function hitung lembur pegawai ke- i 

//point d & e :menghitung total honor (honor harian + honor lembur)
        totalHonor[i]= honorharian + honorlembur[i]; //hitung total honor (honor harian + honor lembur) 
    
    }
    //menampilkan output hasil pemrosesan data
    cout<<"\n============================================"<<endl;
    cout<<"|          LAPORAN HONOR PEGAWAI            |"<<endl;
    cout<<"\n============================================"<<endl;

    for (int i=0;i<banyakData; i++){
        cout <<"|nama pegawai    \t: "  <<namaPegawai[i]<<endl;//cetak nam lengkap pegawai ke- i
        cout <<"|jam kerja        \t: " <<jamKerjaPegawai[i]<< " jam "<<endl;//cetak durasi jam kerja pegawai ke- i
        cout <<"|honor harian    \t: Rp. "  <<honorharian<<endl;//cetak standar honor harian
        cout <<"|honor lembur    \t: Rp. "  <<honorlembur[i]<<endl;//cetak hasil perhitungan honor lembur pegawai ke- i
        cout <<"|total terima    \t: Rp. "  <<totalHonor[i]<<endl;//cetak total pendapatan bersih pegawai ke- i
        cout<<"____________________________________________"<<endl;//cetak garis bawah sebagai pemisak antar pegawai
}
return 0;//mengembalikan nilai 0 ke sistem untuk menandakan program sukses tanpa error
}