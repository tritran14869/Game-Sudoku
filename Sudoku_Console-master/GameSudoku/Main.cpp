#include "Sudoku.h"

int main(){
	mciSendStringA("play music.mp3 repeat", NULL, 0, NULL);

	int MATRAN[Max][Max] = {0};
	int MATRANDE[Max][Max] = {0};
	int MATRANDAPAN[Max][Max] = {0};
MenuChinh:
	system("cls");
	GiaoDienBangChonChinh();//mở menu
	char dieuHuong;
	cout << "> ";
	cin >> dieuHuong;//nhập lệnh

	switch (dieuHuong){
		case '1': {//người chơi
			MenuNguoiChoi:
					system("cls");
					GiaoDienNguoiChoi();//mở giao diện người chơi
					char dieuHuongNguoiChoi;
					cout << "> ";
					cin >> dieuHuongNguoiChoi;

					switch (dieuHuongNguoiChoi){
						case '1': {//luật chơi
									system("cls");
									LuatChoi();
									char quayLai;
									do 
									{
										cout << "Nhan B de quay lai...";
										cin >> quayLai;
									} while (tolower(quayLai) != 'b');
									goto MenuNguoiChoi;
								  } break;

						case '2': {//tiếp tục
									system("cls");
									DocTep(MATRAN, "sudoku_danggiai.txt");
									if(KiemTraSudokuRong(MATRAN) == 1){
										cout << "Loading";
										for(int i = 0; i <= 3; i++){
											Sleep(500);
											cout << ".";
										}
										cout << endl;
										cout << "Khong co du lieu" << endl;
										cout << "Doi 2 giay de quay lai";
										for(int i = 1; i <= 4; i++){
											Sleep(500);
											cout << ".";
										}
										goto MenuNguoiChoi;
									}
									else{
										cout << "Loading";
										for(int i = 0; i <= 3; i++){
											Sleep(500);
											cout << ".";
										}
									MenuDangChoiTT:
										system("cls");
										DocTep(MATRANDE, "sudoku_dedanggiai.txt");
										GiaoDienChucNangNguoiChoi(MATRAN,MATRANDE);
									Menunhap1:
										gotoXY(0,15);
										string lenhDieuHuongChoiGame;
										char lenhDHCG;
										cout << "> ";
										cin >> lenhDieuHuongChoiGame;
										if(lenhDieuHuongChoiGame.length() == 1){
											lenhDHCG = lenhDieuHuongChoiGame[0];
										}
										else if(lenhDieuHuongChoiGame.length() == 2){
											if(KiemTraToaDoDung(lenhDieuHuongChoiGame) == 1){
												int giaTri;
												cout << "Gia tri cua " << lenhDieuHuongChoiGame << " ";
												cin >> giaTri;
												DienOSudoku(MATRAN,lenhDieuHuongChoiGame,giaTri);
												goto MenuDangChoiTT;
											}
											else{
												goto MenuDangChoiTT;
											}
										}
										else if(lenhDieuHuongChoiGame.length() > 2){
											goto MenuDangChoiTT;
										}

										switch (lenhDHCG){
											case '1': {//luật chơi
														system("cls");
														LuatChoi();
														char quayLai;
														do 
														{
															cout << "Nhan B de quay lai...";
															cin >> quayLai;
														} while (tolower(quayLai) != 'b');
														goto MenuDangChoiTT;
											} break;

											case '2': {//tạo mới 1 bản sudoku
														goto MenuDoKho;
											} break;

											case '3': {//gợi ý 1 ô sudoku
														string toaDoGoiY;
														cout << "Nhap toa do can goi y ";
														do{
															cin >> toaDoGoiY;
														} while(KiemTraToaDoDung(toaDoGoiY) == 0);
														GoiYMotOSudoku(MATRAN,toaDoGoiY);
														goto MenuDangChoiTT;
											} break;

											case '4': {//Tìm vị trí sai
														system("cls");
														GiaiSudoku(0, MATRAN);
														DocTep(MATRANDAPAN, "sudoku_dagiai.txt");
														TimViTriSai(MATRAN,MATRANDAPAN,MATRANDE);
														goto Menunhap1;
											} break;

											case '5': {//Hoàn thành sudoku đang giải

														GiaiSudoku(0,MATRAN);
														DocTep(MATRAN, "sudoku_dagiai.txt");

														goto MenuDangChoiTT;
											} break;

											case '6': {//lưu kết quả đang chơi
														GhiTep(MATRAN, "sudoku_danggiai.txt");
														GhiTep(MATRANDE, "sudoku_dedanggiai.txt");
														goto MenuDangChoiTT;
											} break;

											case '7': {//quay lai menu chính
														goto MenuChinh;
											} break;

											default: {//lệnh sai
														goto MenuDangChoiTT;
											} break;
										}//của switch
									}//của else
								  } break;//của case lớn

						case '3': {//Chơi mới 
							MenuDoKho:
									system("cls");
									GiaoDienDoKho();
									char lenhDieuHuongDoKho;
									int doKho;
									cout << "> ";
									cin >> lenhDieuHuongDoKho;
									switch (lenhDieuHuongDoKho){
										case '1': {//dễ
													doKho = 40;
												  } break;

										case '2': {//trung bình
													doKho = 41;
												  } break;

										case '3': {//khó
													doKho = 42;
												  } break;

										case '4': {//quay lai
													goto MenuNguoiChoi;
												  } break;

										case '5': {//quay lại menu chính
													goto MenuChinh;
												  } break;
										default: {//lệnh sai
													goto MenuDoKho;
												 } break;
									}
									TaoDe(MATRAN, doKho);
									DocTep(MATRANDE,"sudoku_de.txt");
									MenuDangChoiMoi:
									system("cls");
									GiaoDienChucNangNguoiChoi(MATRAN, MATRANDE);
									Menunhap:
									gotoXY(0,15);
									string lenhDieuHuongChoiGame;
									char lenhDHCG;
									cout << "> ";
									cin >> lenhDieuHuongChoiGame;
									if(lenhDieuHuongChoiGame.length() == 1){
										lenhDHCG = lenhDieuHuongChoiGame[0];
										switch (lenhDHCG){
										case '1': {//luật chơi
											system("cls");
											LuatChoi();
											char quayLai;
											do 
											{
												cout << "Nhan B de quay lai...";
												cin >> quayLai;
											} while (tolower(quayLai) != 'b');
											goto MenuDangChoiMoi;
												  } break;

										case '2': {//tạo mới 1 bản sudoku
											goto MenuDoKho;
												  } break;

										case '3': {//gợi ý 1 ô sudoku
											string toaDoGoiY;
											cout << "Nhap toa do can goi y ";
											do{
												cin >> toaDoGoiY;
											} while(KiemTraToaDoDung(toaDoGoiY) == 0);
											GoiYMotOSudoku(MATRAN,toaDoGoiY);
											goto MenuDangChoiMoi;
												  } break;

										case '4': {//Tìm vị trí sai
											system("cls");
											DocTep(MATRANDAPAN, "sudoku_dapan.txt");
											TimViTriSai(MATRAN,MATRANDAPAN,MATRANDE);
											goto Menunhap;
												  } break;

										case '5': {//Hoàn thành sudoku đang giải
											DocTep(MATRAN, "sudoku_dapan.txt");
											goto MenuDangChoiMoi;
												  } break;

										case '6': {//lưu kết quả đang chơi
											GhiTep(MATRAN, "sudoku_danggiai.txt");
											GhiTep(MATRANDE, "sudoku_dedanggiai.txt");
											goto MenuDangChoiMoi;
												  } break;

										case '7': {//quay lai menu chính
											goto MenuChinh;
												  } break;

										default: {//lệnh sai
											goto MenuDangChoiMoi;
												 } break;
										}
									}
									else if(lenhDieuHuongChoiGame.length() == 2){
										if(KiemTraToaDoDung(lenhDieuHuongChoiGame) == 1){
											int giaTri;
											cout << "Gia tri cua " << lenhDieuHuongChoiGame << " ";
											cin >> giaTri;
											DienOSudoku(MATRAN,lenhDieuHuongChoiGame,giaTri);
											if(KiemTraSudokuHoanThien(MATRAN) == 1){
												cout << "THANH CONG" << endl;
												Sleep(2000);
											}
											goto MenuDangChoiMoi;
										}
										else{
											goto MenuDangChoiMoi;
										}
									}
									else if(lenhDieuHuongChoiGame.length() > 2){
										goto MenuDangChoiMoi;
									}
								  } break;

						case '4': {//quay lại menu chính
									goto MenuChinh;
								  } break;

						default: {
							goto MenuNguoiChoi;
						} break;
					}
		} break;

		case '2': {// Máy chơi
			Menurobot:
					system("cls");
					GiaoDienBangChonRobot();
					char lenhDieuHuongGDRB;
					cout << "> ";
					cin >> lenhDieuHuongGDRB;

					switch (lenhDieuHuongGDRB){
						case '1': {
							
							int MATRANROBOT[Max][Max] = {0};
							int MATRANDEROBOT[Max][Max] = {0};
							menurobotthuong:
							system("cls");
							GiaoDienRobotThuong(MATRANROBOT,MATRANDEROBOT);
							gotoXY(0,16);
							string lenhDieuHuongRobot;
							char DHRB;
							cout << "> ";
							cin >> lenhDieuHuongRobot;
							if (lenhDieuHuongRobot.length() == 1){
								DHRB = lenhDieuHuongRobot[0];
								switch (DHRB)
								{
									case '1': {//giải đề
												// dùng int giải sudoku của thức làm GiaiSudoku(0, MATRANDEROBOT);
												DocTep(MATRANROBOT, "sudoku_dapan.txt");
												goto menurobotthuong;
									} break;

									case '2': {//quay lại
												goto Menurobot;
									} break;

									case '3': {//quay lại menu chính
												goto MenuChinh;
									} break;

									default : {
												goto menurobotthuong;
									} break;
								}
							}
							else if(lenhDieuHuongRobot.length() > 2){
								goto menurobotthuong;
							}
							else if(lenhDieuHuongRobot.length() == 2){
								if(KiemTraToaDoDung(lenhDieuHuongRobot) == 1){
									int giaTriRb;
									cout << "Gia tri cua o " << lenhDieuHuongRobot << " la: ";
									cin >> giaTriRb;
									DienOSudoku(MATRANDEROBOT, lenhDieuHuongRobot, giaTriRb);
									goto menurobotthuong;
								}
							}
						} break;

						case '2': {//đường xuyên
									
						} break;

						case '3': {
									goto MenuChinh;
						} break;

						default : {
									goto Menurobot;
						} break;
					}	
		} break;

		case '3': {//thoát
					system("cls");
					GhiTep(MATRAN, "sudoku_danggiai.txt");
					cout << "Dang luu..." << endl;
					Sleep(1000);
					cout << "Luu thanh cong" << endl;
					Sleep(1500);
					exit(0);
		} break;

		default: {//lệnh sai
			goto MenuChinh;
		} break;
	}
	return 0;
}