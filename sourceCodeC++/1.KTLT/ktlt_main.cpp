#include <bits/stdc++.h>
#define MAX 100
using namespace std;
/*--------------khai báo các struct để lưu thông tin sinh viên--------------------*/

struct SinhVien
{
    string id;
    char hoTen[25];
    char maLop[10];
    char gioiTinh[5];
    char diaChi[15];
    string NgaySinh;
    int tuoi;
    string sdt;
    float diemMon1;
    float diemMon2;
    float diemMon3;
    float diemTrungBinh;
    char xepLoai[10];
};
typedef SinhVien SV; // định nghĩa kiểu SinhVien là SV

/*---------------Khai báo nguyên mẫu hàm--------------------*/
void nhapSinhVien(SV &sv);
void inSinhVien(SV sv);
void tinhDiemTrungBinh(SV *sv);
void xepLoai(SV &sv);
void capNhatSinhVien(SV &sv);
void nhapDanhSachSinhVien(SV ArrSV[], int &soLuongSinhVien);
void xuatDanhSachSinhVien(SV ArrSV[], int soLuongSinhVien);
float tim_MaxDTB(SV ArrSV[], int soLuongSinhVien);
void xuatDanhSachSinhVienXepLoai(SV ArrSV[], int soLuongSinhVien, char xepLoai[30]);
void xuatDanhSachSinhVienTheoLop(SV ArrSV[], int soLuongSinhVien, char maLop[]);
int timSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien, char ten[]);
void xoaSinhVienTheoID(SV ArrSV[], int &soLuongSinhVien, string maXoaID);
void sapXepSinhVienTheoDTB(SV ArrSV[], int soLuongSinhVien);
void sapXepSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien);
void ghiDuLieuSV(SV ArrSV[], int soLuongSinhVien);
void docDuLieuSV(SV (&ArrSV)[MAX], int &N);
void ghiSVmoi(SV ArrSV[], int soLuongSinhVien);
void nhanPhim();

/*-----------------------Hàm main xử lí chính----------------------*/
int main()
{
    SV ArrSV[MAX];
    int soLuongSinhVien, N;
    int luaChonSV;

    do
    { 
        system("cls");
        cout << ("\n------------------MENU SINH VIEN------------------");
        cout << ("\n(1). Them Danh Sach Sinh Vien");
        cout << ("\n(2). Xuat Danh Sach Sinh Vien");
        cout << ("\n(3). Tim Diem Trung Binh Lon Nhat");
        cout << ("\n(4). Xuat Danh Sach Sinh Vien Theo Xep Loai");
        cout << ("\n(5). Xuat Danh Sach Sinh Vien Theo Lop");
        cout << ("\n(6). Tim Sinh Vien Theo Ten");
        cout << ("\n(7). Xoa Sinh Vien Theo ID");
        cout << ("\n(8). Sap Xep Sinh Vien Theo DTB");
        cout << ("\n(9). Sap Xep Sinh Vien Theo Ten");
        cout << ("\n(10). Ghi Du Lieu Sinh Vien Vao File");
        cout << ("\n(11). Doc Du Lieu Sinh Vien Tu File");
        cout << ("\n(12). Ghi Du Lieu Sinh Vien Moi Nhap Vao File");
        cout << ("\n(0). Thoat");
        cout << ("\n--------------------------------------------------");

        cout << ("\nNhap Lua Chon Cua Ban : ");
        cin >> luaChonSV;

        switch (luaChonSV)
        {
        case 0:
        {
            cout << ("\nBan Da Thoat Khoi Chuong Trinh !");
            exit(0);
            break;
        }
        case 1:
        {
            nhapDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 2:
        {
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 3:
        {
            cout << "\nDiem trung binh lon nhat la: Max DTB = " << tim_MaxDTB(ArrSV, soLuongSinhVien);
            break;
        }
        case 4:
        {
            char xepLoai[30];
            cout << ("\nNhap xep loai muon xuat ra man hinh : ");
            cin.ignore();
            cin.getline(xepLoai, sizeof(xepLoai));
            xuatDanhSachSinhVienXepLoai(ArrSV, soLuongSinhVien, xepLoai);
            break;
        }
        case 5:
        {
            char maLop[30];
            cout << "\nNhap lop can xuat danh sach sinh vien : ";
            cin.ignore();
            cin.getline(maLop, sizeof(maLop));
            xuatDanhSachSinhVienTheoLop(ArrSV, soLuongSinhVien, maLop);
            break;
        }
        case 6:
        {
            char ten[50];
            cout << "Nhap ten sinh vien muon tim : ";
            cin.ignore();
            cin.getline(ten, sizeof(ten));
            if (timSinhVienTheoTen(ArrSV, soLuongSinhVien, ten))
            {
                cout << "\nTim thay sinh vien";
            }
            else
            {
                cout << "\nKhong tim thay sinh vien";
            }
            break;
        }
        case 7:
        {
            string maXoaID;
            cout << "\nNhap vao id can xoa : ";
            cin >> maXoaID;
            xoaSinhVienTheoID(ArrSV, soLuongSinhVien, maXoaID);
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }

        case 8:
        {
            cout << ("\nSau khi sap xep theo DTB !\n");
            sapXepSinhVienTheoDTB(ArrSV, soLuongSinhVien);
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 9:
        {
            cout << ("\nSau khi sap xep theo ten !");
            sapXepSinhVienTheoTen(ArrSV, soLuongSinhVien);
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 10:
        {
            ghiDuLieuSV(ArrSV, soLuongSinhVien);
            break;
        }
        case 11:
        {
            docDuLieuSV(ArrSV, soLuongSinhVien);

            break;
        }
        case 12:
        {
            ghiSVmoi(ArrSV, soLuongSinhVien);
            break;
        }
        }
        cout << ("\n");
        nhanPhim();
    } while (luaChonSV != 0);
    return 0;
}

/*hàm dừng màn hình lại cho người dùng nhấn phím rồi tiếp tục chạy*/
void nhanPhim()
{
    cout << ("\nNhan phim bat ki de tiep tuc :");
    system("pause");
}
/*hàm nhập sinh viên*/
void nhapSinhVien(SV &sv)
{
    cout << ("\nNhap ID : ");
    cin >> sv.id;
    cin.ignore();

    cout << "\nNhap ten : ";
    cin.getline(sv.hoTen, sizeof(sv.hoTen) / sizeof(sv.hoTen[0]));

    cout << "\nNhap ma lop : ";
    cin.getline(sv.maLop, sizeof(sv.maLop) / sizeof(sv.maLop[0]));

    cout << "\nNhap gioi tinh : ";
    cin.getline(sv.gioiTinh, sizeof(sv.gioiTinh) / sizeof(sv.gioiTinh[0]));

    cout << "\nNhap dia chi : ";
    cin.getline(sv.diaChi, sizeof(sv.diaChi) / sizeof(sv.diaChi[0]));

    cout << "\nNhap ngay sinh : ";
    cin >> sv.NgaySinh;
    cin.ignore();

    cout << "\nNhap sdt : ";
    cin >> sv.sdt;
    cin.ignore();

    cout << "\nNhap diem mon 1 : ";
    cin >> sv.diemMon1;
    cout << "\nNhap diem mon 2 : ";
    cin >> sv.diemMon2;
    cout << "\nNhap diem mon 3 : ";
    cin >> sv.diemMon3;
}
/*hàm in thông tin 1 sinh viên */
void inSinhVien(SV sv)
{
    cout << left << setw(10) << sv.id << "\t";
    cout << left << setw(20) << sv.hoTen << "\t";
    cout << left << setw(10) << sv.maLop << "\t";
    cout << left << setw(5) << sv.gioiTinh << "\t";
    cout << left << setw(15) << sv.diaChi << "\t";
    cout << left << setw(10) << sv.NgaySinh << "\t";
    cout << left << setw(12) << sv.sdt << "\t";
    cout << left << setw(5) << fixed << setprecision(1) << sv.diemMon1 << "\t";
    cout << left << setw(5) << fixed << setprecision(1) << sv.diemMon2 << "\t";
    cout << left << setw(5) << fixed << setprecision(1) << sv.diemMon3 << "\t";
    cout << left << setw(5) << fixed << setprecision(1) << sv.diemTrungBinh << "\t";
    cout << left << setw(10) << sv.xepLoai << endl;
}

/*hàm có chức năng tính điểm trung bình của sinh viên */
void tinhDiemTrungBinh(SV *sv)
{
    sv->diemTrungBinh = (sv->diemMon1 + sv->diemMon2 + sv->diemMon3) / 3;
}

/*hàm xếp loại sinh viên theo điểm trung bình*/
void xepLoai(SV &sv)
{
    if (sv.diemTrungBinh > 8)
    {
        strcpy(sv.xepLoai, "GIOI");
    }
    else if (sv.diemTrungBinh > 7)
    {
        strcpy(sv.xepLoai, "KHA");
    }
    else if (sv.diemTrungBinh >= 5)
    {
        strcpy(sv.xepLoai, "TB");
    }
    else if (sv.diemTrungBinh < 5)
    {
        strcpy(sv.xepLoai, "YEU");
    }
    else
    {
        strcpy(sv.xepLoai, "invalid");
    }
}

/*hàm cập nhật sinh viên*/
void capNhatSinhVien(SV &sv)
{
    nhapSinhVien(sv);
    tinhDiemTrungBinh(&sv);
    xepLoai(sv);
}

/*hàm nhập danh sách sinh viên lưu vào 1 mảng*/
void nhapDanhSachSinhVien(SV ArrSV[], int &soLuongSinhVien)
{
    do
    {
        cout << "Nhap so luong sinh vien : ";
        cin >> soLuongSinhVien;
    } while (soLuongSinhVien <= 0 || soLuongSinhVien > MAX);
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        cout << ("\n");
        cout << "Nhap sinh vien thu [" << i + 1 << "]\n";
        capNhatSinhVien(ArrSV[i]);
    }
}

/*hàm xuất danh sách sinh viên*/
void xuatDanhSachSinhVien(SV ArrSV[], int soLuongSinhVien)
{
    cout << left << setw(10) << "ID"
         << "\t" << left << setw(20) << "Ho Ten"
         << "\t" << left << setw(10) << "Lop"
         << "\t" << left << setw(5) << "GT"
         << "\t" << left << setw(15) << "DC"
         << "\t" << left << setw(10) << "Ngaysinh"
         << "\t" << left << setw(12) << "SDT"
         << "\t" << left << setw(5) << "Diem 1"
         << "\t" << left << setw(5) << "Diem 2"
         << "\t" << left << setw(5) << "Diem 3"
         << "\t" << left << setw(5) << "DTB"
         << "\t" << left << setw(10) << "Xep Loai" << endl;
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        inSinhVien(ArrSV[i]);
        cout << endl;
    }
}
/*hàm tìm ra điểm trung bình lớn nhất*/
float tim_MaxDTB(SV ArrSV[], int soLuongSinhVien)
{
    float maxDTB = ArrSV[0].diemTrungBinh;
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (ArrSV[i].diemTrungBinh > maxDTB)
        {
            maxDTB = ArrSV[i].diemTrungBinh;
        }
    };
    return maxDTB;
}

/*hàm xuất danh sách sinh viên theo xếp loại*/
void xuatDanhSachSinhVienXepLoai(SV ArrSV[], int soLuongSinhVien, char xepLoai[30])
{
    cout << left << setw(10) << "ID"
         << "\t" << left << setw(20) << "Ho Ten"
         << "\t" << left << setw(10) << "Lop"
         << "\t" << left << setw(5) << "GT"
         << "\t" << left << setw(15) << "DC"
         << "\t" << left << setw(10) << "Ngaysinh"
         << "\t" << left << setw(12) << "SDT"
         << "\t" << left << setw(5) << "Diem 1"
         << "\t" << left << setw(5) << "Diem 2"
         << "\t" << left << setw(5) << "Diem 3"
         << "\t" << left << setw(5) << "DTB"
         << "\t" << left << setw(10) << "Xep Loai" << endl;
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (strcmp(strupr(ArrSV[i].xepLoai), strupr(xepLoai)) == 0)
        {
            inSinhVien(ArrSV[i]);
        }
    }
}

/*hàm xuất danh sách sinh viên theo lớp do người dùng nhập*/
void xuatDanhSachSinhVienTheoLop(SV ArrSV[], int soLuongSinhVien, char maLop[])
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (strcmp(strupr(ArrSV[i].maLop), strupr(maLop)) == 0)
        {
            inSinhVien(ArrSV[i]);
        }
    }
}

/*hàm tìm sinh viên theo tên*/
int timSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien, char ten[])
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (strstr(strupr(ArrSV[i].hoTen), strupr(ten)))
        {
            return 1;
            break;
        }
    }
    return 0;
}

/*hàm xóa sinh viên the id*/
void xoaSinhVienTheoID(SV ArrSV[], int &soLuongSinhVien, string maXoaID)
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (ArrSV[i].id == maXoaID)
        {
            for (int j = i; j < soLuongSinhVien; j++)
            {
                ArrSV[j] = ArrSV[j + 1];
            }
            soLuongSinhVien--;
        }
    }
}

/*hàm sắp xếp sinh viên theo điểm trung bình*/
void sapXepSinhVienTheoDTB(SV ArrSV[], int soLuongSinhVien)
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        for (int j = i + 1; j < soLuongSinhVien; j++)
        {
            if (ArrSV[i].diemTrungBinh < ArrSV[j].diemTrungBinh)
            {
                SV temp = ArrSV[i];
                ArrSV[i] = ArrSV[j];
                ArrSV[j] = temp;
            }
        }
    }
}

/*hàm sắp xếp sinh viên theo tên*/
void sapXepSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien)
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        for (int j = i + 1; j < soLuongSinhVien; j++)
        {
            if (strcmp(ArrSV[i].hoTen, ArrSV[j].hoTen) > 0)
            {
                SV temp = ArrSV[i];
                ArrSV[i] = ArrSV[j];
                ArrSV[j] = temp;
            }
        }
    }
}

/*hàm có chức năng ghi thông tin vào file*/
void ghiDuLieuSV(SV ArrSV[], int soLuongSinhVien)
{
    string tenFile;
    cout << "Nhap vao ten cua file can ghi: ";
    cin >> tenFile;

    ofstream fout(tenFile, ios::out);

    if (!fout)
    { // kiểm tra nếu không mở được file
        cout << "Khong the mo file !";
        exit(0);
    }

    for (int i = 0; i < soLuongSinhVien; i++)
    {
        fout << left << setw(10) << ArrSV[i].id
             << "\t" << left << setw(20) << ArrSV[i].hoTen
             << "\t" << left << setw(10) << ArrSV[i].maLop
             << "\t" << left << setw(5) << ArrSV[i].gioiTinh
             << "\t" << left << setw(15) << ArrSV[i].diaChi
             << "\t" << left << setw(10) << ArrSV[i].NgaySinh
             << "\t" << left << setw(12) << ArrSV[i].sdt
             << "\t" << left << setw(5) << ArrSV[i].diemMon1
             << "\t" << left << setw(5) << ArrSV[i].diemMon2
             << "\t" << left << setw(5) << ArrSV[i].diemMon3
             << "\t" << left << setw(5) << ArrSV[i].diemTrungBinh
             << "\t" << left << setw(10) << ArrSV[i].xepLoai << endl;
    }
    fout.close(); // đóng file
}

/*hàm có chức năng đọc thông tin từ file*/
void docDuLieuSV(SV (&ArrSV)[MAX], int &N)

{

    string tenFile;
    cout << "Nhap vao ten cua file can doc: ";
    cin >> tenFile;

    ifstream fin(tenFile, ios::in);

    if (!fin)
    { // kiểm tra nếu không mở được file
        cout << "Khong the mo file !";
        exit(0);
    }

    cout << "So luong sinh vien can doc tu file la: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        fin >> ArrSV[i].id;
        fin >> ArrSV[i].hoTen;
        fin >> ArrSV[i].maLop;
        fin >> ArrSV[i].gioiTinh;
        fin >> ArrSV[i].diaChi;
        fin >> ArrSV[i].NgaySinh;
        fin >> ArrSV[i].sdt;
        fin >> ArrSV[i].diemMon1;
        fin >> ArrSV[i].diemMon2;
        fin >> ArrSV[i].diemMon3;
        fin >> ArrSV[i].diemTrungBinh;
        fin >> ArrSV[i].xepLoai;
    }

    for (int i = 0; i < N; i++)
    {
        cout << left << setw(10) << ArrSV[i].id
             << "\t" << left << setw(20) << ArrSV[i].hoTen
             << "\t" << left << setw(10) << ArrSV[i].maLop
             << "\t" << left << setw(5) << ArrSV[i].gioiTinh
             << "\t" << left << setw(15) << ArrSV[i].diaChi
             << "\t" << left << setw(10) << ArrSV[i].NgaySinh
             << "\t" << left << setw(12) << ArrSV[i].sdt
             << "\t" << left << setw(5) << ArrSV[i].diemMon1
             << "\t" << left << setw(5) << ArrSV[i].diemMon2
             << "\t" << left << setw(5) << ArrSV[i].diemMon3
             << "\t" << left << setw(5) << ArrSV[i].diemTrungBinh
             << "\t" << left << setw(10) << ArrSV[i].xepLoai;
        cout << endl;
    }

    fin.close();
}

/*hàm có chức năng ghi thông tin sinh vien moi vào file*/
void ghiSVmoi(SV ArrSV[], int soLuongSinhVien){
    string tenFile;
    cout << "Nhap vao ten cua file can ghi: ";
    cin >> tenFile;

    ofstream fout(tenFile, ios::app);

    if (!fout)
    { // kiểm tra nếu không mở được file
        cout << "Khong the mo file !";
        exit(0);
    }

    for (int i = 0; i < soLuongSinhVien; i++)
    {
        fout << '\n' << left << setw(10) << ArrSV[i].id
             << "\t" << left << setw(20) << ArrSV[i].hoTen
             << "\t" << left << setw(10) << ArrSV[i].maLop
             << "\t" << left << setw(5) << ArrSV[i].gioiTinh
             << "\t" << left << setw(15) << ArrSV[i].diaChi
             << "\t" << left << setw(10) << ArrSV[i].NgaySinh
             << "\t" << left << setw(12) << ArrSV[i].sdt
             << "\t" << left << setw(5) << ArrSV[i].diemMon1
             << "\t" << left << setw(5) << ArrSV[i].diemMon2
             << "\t" << left << setw(5) << ArrSV[i].diemMon3
             << "\t" << left << setw(5) << ArrSV[i].diemTrungBinh
             << "\t" << left << setw(10) << ArrSV[i].xepLoai << endl;
    }
    fout.close(); // đóng file
}
