#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#pragma comment(lib, "winmm")
#include "iostream"
#include "conio.h"
#include "Windows.h"
#include "string.h"
#include "ctime"
#include "string"
using namespace std;
#define Max 9

//=========Khai báo hàm===========
//=========Khai báo các hàm liên quan đến giao diện==========
void GiaoDienBangChonChinh();
void GiaoDienNguoiChoi();
void GiaoDienChucNangNguoiChoi(int MATRAN[Max][Max], int MATRANDE[Max][Max]);
void GiaoDienDoKho();
void TextColor(int maMau);
void gotoXY(int cot, int hang);
void GiaoDienBangChonRobot();
void GiaoDienRobotThuong(int MATRAN[Max][Max], int MATRANDENHAP[Max][Max]);

//========Khai báo các hàm liên quan đến xử lý sudoku=========
void GiaiSudoku(int x, int MATRAN[Max][Max]);//hàm giải
int KiemTraOSudoku(int hang, int cot, int giaTri, int MATRAN[Max][Max]);//hỗ trợ hàm GiaiSudoku
int KiemTraToaDoDung(string toaDo);//hàm kiểm tra 1 tọa độ có đúng hay sai
int KiemTraLaOTrong(int MATRAN[Max][Max], string toaDo);//hàm kiểm tra 1 tọa độ có phải là ô trống hay không
int KiemTraSudokuHoanThien(int MATRAN[Max][Max]);//hàm kiểm tra sudoku đã hoàn chỉnh hay chưa
int TimViTriDungDeQuy(int MATRAN[Max][Max]);//hàm tìm vị trí cần điền cuối cùng để dừng đệ quy trong hàm GiaiSudoku
int KiemTraMotCot(int MATRAN[Max][Max], int cotKT);//hàm kiểm tra một cột
int KiemTraMotHang(int MATRAN[Max][Max], int hangKT);//hàm kiểm tra một hàng
int KiemTraMotVung(int MATRAN[Max][Max], int cotKT, int hangKT);//hàm kiểm tra một vùng
int KiemTraSudokuRong(int MATRAN[Max][Max]);//hàm kiểm tra sudoku rỗng hay không

//========Khai báo các hàm liên quan đến tính năng tạo đề=========
void ChuyenViHaiCot(int MATRAN[Max][Max], int cotMoc, int cotDich);//hàm xáo 2 cột chỉ định
void ChuyenViHaiHang(int MATRAN[Max][Max], int hangMoc, int hangDich);//hàm xáo 2 hàng chỉ định
void ChuyenViHangNhomI(int MATRAN[Max][Max]);//hàm xáo các hàng trong nhóm hàng I
void ChuyenViHangNhomII(int MATRAN[Max][Max]);//hàm xáo các hàng trong nhóm hàng II
void ChuyenViHangNhomIII(int MATRAN[Max][Max]);//hàm xáo các hàng trong nhóm hàng III
void ChuyenViCotNhomI(int MATRAN[][Max]);//hàm xáo các cột trong nhóm cột I
void ChuyenViCotNhomII(int MATRAN[][Max]);//hàm xáo các cột trong nhóm cột II
void ChuyenViCotNhomIII(int MATRAN[][Max]);//hàm xáo các cột trong nhóm cột III
void XaoHang(int MATRAN[Max][Max]);//hàm xáo hàng trong sudoku
void XaoCot(int MATRAN[Max][Max]);//hàm xáo cột trong sudoku
void TaoDe(int MATRAN[Max][Max], int doKho);//hàm tạo đề sudoku

//=======Khai báo các hàm chức năng của game sudoku=========
void LuatChoi();
void GoiYMotOSudoku(int MATRAN[Max][Max], string toaDo);
void DienOSudoku(int MATRAN[Max][Max], string toaDo, int giaTri);
void TimViTriSai(int MATRAN[Max][Max], int MATRANDAPAN[Max][Max], int MATRANDE[Max][Max]);
void DienOSudokuDe(int MATRANDE[Max][Max], string toaDo, int giaTri);


//========Khai báo các hàm liên quan đến việc truy xuất dữ liệu từ tệp
void DocTep(int MATRAN[Max][Max], const char* duongDan);//hàm đọc dữ liệu từ 1 tệp
void GhiTep(int MATRAN[Max][Max], const char* duongDan);//hàm ghi dữ liệu xuống 1 tệp

#endif