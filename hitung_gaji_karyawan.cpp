#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


string formatRupiah(float angka) {
    stringstream ss;
    ss << fixed << setprecision(2) << angka;
    string hasil = ss.str();
    int posisi = hasil.find('.') - 3;

    while (posisi > 0) {
        hasil.insert(posisi, ",");
        posisi -= 3;
    }

    return hasil;
}

int main() {
    float persenPajak = 0.15, persenTunjangan = 0.2;
    string nama;
    float gajiPokok, gajiBersih, tunjangan, pajak;

    cout << "\n\tMenghitung Gaji Karyawan\n\n";
    cout << "Nama Karyawan : ";
    cin >> nama;

    cout << "Gaji pokoknya : Rp. ";
    cin >> gajiPokok;

    tunjangan = persenTunjangan * gajiPokok;
    pajak = persenPajak * (gajiPokok + tunjangan);
    gajiBersih = gajiPokok + tunjangan - pajak;

    cout << "\nTunjangannya sebesar : Rp. " << formatRupiah(tunjangan);
    cout << "\nPajaknya sebesar     : Rp. " << formatRupiah(pajak);
    cout << "\n\nGaji bersih karyawan : Rp. " << formatRupiah(gajiBersih) << endl;

    return 0;
}
