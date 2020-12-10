#include "Sudoku.h"

//======Định nghĩa các hàm liên quan đến giao diện========
void GiaoDienBangChonChinh(){
	cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
	cout << "========================Menu Chinh========================" << endl;
	cout << "1. Nguoi choi" << endl;
	cout << "2. May choi" << endl;
	cout << "3. Thoat game" << endl;
	cout << "===============HCMUS-2016. All right reserved=============" << endl;
}

void GiaoDienNguoiChoi(){
	cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
	cout << "========================Nguoi Choi========================" << endl;
	cout << "1. Luat choi" << endl;
	cout << "2. Tiep tuc choi" << endl;
	cout << "3. Do kho" << endl;
	cout << "4. Quay lai menu chinh" << endl;
	cout << "===============HCMUS-2016. All right reserved=============" << endl;
}


void GiaoDienChucNangNguoiChoi(int MATRAN[Max][Max], int MATRANDE[Max][Max]){
	int slkt = 0;
	for (int i = 0; i < Max; i++){
		for (int j = 0; j < Max; j++){
			if (MATRAN[i][j] == 0){
				slkt++;
			}
		}
	}
	if (slkt != 81){
		int mangSudoku[81];
		int gr = 0;
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				mangSudoku[gr] = MATRAN[i][j];
				gr++;
			}
		}

		int mangSudokuDe[81];
		int n = 0;
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				mangSudokuDe[n] = MATRANDE[i][j];
				n++;
			}
		}

		cout << "  A B C D E F G H I" << endl;//hàng 2-12, cột 3-19; bước nhảy 2 cho cột, nhảy 1 cho hàng, khác 0 thì đổi màu,
		cout << "1      |     |     " << endl;
		cout << "2      |     |     " << endl;
		cout << "3      |     |     " << endl;
		cout << "  -----------------" << endl;
		cout << "4      |     |     " << endl;
		cout << "5      |     |     " << endl;
		cout << "6      |     |     " << endl;
		cout << "  -----------------" << endl;
		cout << "7      |     |     " << endl;
		cout << "8      |     |     " << endl;
		cout << "9      |     |     " << endl;
		int f = 0;
		for (int i = 2; i <= 12; i++){
			for (int j = 3; j <= 19; j += 2){
				if (i != 5 && i != 9){
					gotoXY(j - 1, i - 1);
					if (mangSudoku[f] != 0 && mangSudoku[f] == mangSudokuDe[f]){
						TextColor(9);
						cout << mangSudoku[f];
					}
					else
					{
						TextColor(7);
						cout << mangSudoku[f];
					}
					f++;
				}
			}
		}
		cout << endl;
		TextColor(7);


		int k = 0;
		for (int i = 0; i < 16; i++)
		{
			gotoXY(22, k);
			cout << "|" << endl;
			k++;
		}

		int m = 0;
		for (int t = 0; t < 11; t ++)
		{
			gotoXY(25, m);

			if (t == 0)
				cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
			if (t == 1)
				cout << "==============Menu Nguoi Choi=============" << endl;
			if (t == 2)
				cout << "1. Luat choi" << endl;
			if (t == 3)
				cout << "2. Tao moi mot bang sudoku" << endl;
			if (t == 4)
				cout << "3. Goi y 1 o sudoku" << endl;
			if (t == 5)
				cout << "4. Tim vi tri sai" << endl;
			if (t == 6)
				cout << "5. Hoan thien sudoku dang giai" << endl;
			if (t == 7)
				cout << "6. Luu ket qua cua luoi hien tai" << endl;
			if (t == 8)
				cout << "7. Quay lai menu chinh" << endl;
			if (t == 9)
				cout << "======HCMUS-2016. All right reserved======" << endl;
			if (t == 10)
				cout << "Nhap toa do de choi hoac nhap cac phim tuy chon" << endl;
			m++;
		}

		gotoXY(1, 20);
	}
	else{
		cout << "Khong ton tai sudoku" << endl;
	}
}


void GiaoDienDoKho(){
	cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
	cout << "==========================Muc Do==========================" << endl;
	cout << "1. De" << endl;
	cout << "2. Thuong" << endl;
	cout << "3. Kho" << endl;
	cout << "4. Quay lai" << endl;
	cout << "5. Quay lai menu chinh" << endl;
	cout << "===============HCMUS-2016. All right reserved=============" << endl;
}

void TextColor(int maMau){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,maMau);
}

void gotoXY(int cot, int hang){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {cot, hang};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,Cursor_an_Pos);
}

void GiaoDienBangChonRobot(){
	cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
	cout << "=======================Bang chon Robot====================" << endl;
	cout << "1. Nhap de can giai" << endl;
	cout << "2. Giai duong xuyen" << endl;
	cout << "3. Quay lai menu chinh" <<endl;
	cout << "==============HCMUS-2016. All righet reserved=============" << endl;
}

void GiaoDienRobotThuong(int MATRAN[Max][Max], int MATRANDENHAP[Max][Max]){
	int mangSudoku[81];
	int mt = 0;
	for(int i = 0; i < Max; i++){
		for(int j = 0; j < Max; j++){
			mangSudoku[mt] = MATRAN[i][j];
			mt++;
		}
	}

	int mangDe[81];
	int md = 0;
	for(int i = 0; i < Max; i++){
		for(int j = 0; j < Max; j++){
			mangDe[md] = MATRANDENHAP[i][j];
			md++;
		}
	}

	cout << "  A B C D E F G H I" << endl;//hàng 2-12, cột 3-19; bước nhảy 2 cho cột, nhảy 1 cho hàng, khác 0 thì đổi màu,
	cout << "1      |     |     " << endl;
	cout << "2      |     |     " << endl;
	cout << "3      |     |     " << endl;
	cout << "  -----------------" << endl;
	cout << "4      |     |     " << endl;
	cout << "5      |     |     " << endl;
	cout << "6      |     |     " << endl;
	cout << "  -----------------" << endl;
	cout << "7      |     |     " << endl;
	cout << "8      |     |     " << endl;
	cout << "9      |     |     " << endl;

	int r = 0;
	for (int i = 1; i <= 11; i++){
		for(int j = 2; j <= 18; j+=2){
			if(i != 4 && i != 8){
				gotoXY(j, i);
				if(mangDe[r] != 0){
					TextColor(9);
					cout << mangDe[r];
				}
				else{
					TextColor(7);
					cout << mangDe[r];
				}
				r++;
			}
		}
	}
	
	TextColor(7);

	int k = 0;
	for(int i = 1; i <= 11; i++){
		for(int j = 2; j <= 18; j+=2){
			if(i != 4 && i != 8){
				gotoXY(j, i);
				if(mangSudoku[k] != mangDe[k] && mangDe[k] == 0){
					TextColor(7);
					cout << mangSudoku[k];
				}
				else if(mangDe[k] != 0 && mangSudoku[k] == mangDe[k]){
					TextColor(9);
					cout << mangSudoku[k];
				}
				k++;
			}
		}
	}

	cout << endl;
	TextColor(7);

	int l = 0;
	for (int i = 0; i < 16; i++)
	{
		gotoXY(20, l);
		cout << "|" << endl;
		l++;
	}

	int m = 0;
	for (int t = 0; t < 7; t++)
	{
		gotoXY(22, m);

		if (t == 0)
			cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
		if (t == 1)
			cout << "==============Menu Chuc Nang==============" << endl;
		if (t == 2)
			cout << "1. Giai de" << endl;
		if (t == 3)
			cout << "2. " << endl;
		if (t == 4)
			cout << "3. Quay lai menu chinh" << endl;
		if (t == 5)
			cout << "======HCMUS-2016. All right reserved======" << endl;
		if (t == 6)
			cout << "Nhap toa do de choi hoac nhap cac phim tuy chon" << endl;
		m++;
	}
	gotoXY(1,25);
}

//========Định nghĩa các hàm liên quan đến xử lý sudoku========
void GiaiSudoku(int k, int MATRAN[Max][Max]){//hàm giải
	int i, j, x;
	while (MATRAN[k / Max][k % Max] != 0){ // bỏ qua các ô đã có trong đề bài
		k++;
	}

	i = k / Max; 
	j = k % Max;

	int lastK=TimViTriDungDeQuy(MATRAN);
	for (x = 1; x <= Max; x++)
	{
		if (KiemTraOSudoku(i, j, x,MATRAN))
		{
			MATRAN[i][j] = x;
			if (k == lastK)		// nếu giá trị thử ở cuối ma trận
			{
				GhiTep(MATRAN,"sudoku_dagiai.txt");
			}
			else				// nếu sai thì tiếp tục thử
				GiaiSudoku(k + 1,MATRAN);
			MATRAN[i][j] = 0;
		}
	}
}


int KiemTraOSudoku(int hang, int cot, int giaTri, int MATRAN[Max][Max]){//hỗ trợ hàm GiaiSudoku
	int k, t;
	int tmpX, tmpY;
	//kiểm tra hàng thứ i xem có giá trị nào trùng không
	for (k = 0; k < Max; k++)
		if (MATRAN[hang][k] == giaTri)
			return 0;

	//kiểm tra cột thứ j xem có giá trị nào trùng không
	for (k = 0; k < Max; k++)
		if (MATRAN[k][cot] == giaTri)
			return 0;

	//kiểm tra vùng 3 x 3
	tmpX = hang % 3; 
	tmpY = cot % 3;

	for (k = hang - tmpX; k <= hang - tmpX + 2; k++)
		for (t = cot - tmpY; t <= cot - tmpY + 2; t++)
			if (MATRAN[k][t] == giaTri)
				return 0;
	return 1;
}

int KiemTraToaDoDung(string toaDo){//hàm kiểm tra 1 tọa độ có đúng hay sai
	if(toaDo.length() != 2){
		return 0;
	}
	if(tolower(toaDo[0]) < 'a' || tolower(toaDo[0]) > 'i'){
		return 0;
	}
	if(toaDo[1] < '1' || toaDo[1] > '9'){
		return 0;
	}
	return 1;
}
int KiemTraLaOTrong(int MATRAN[Max][Max], string toaDo){//hàm kiểm tra 1 tọa độ có phải là ô trống hay không
	int soHang = 0, soCot = 0;

	if(tolower(toaDo[0]) == 'a'){
		soCot = 0;
	} 
	else if(tolower(toaDo[0]) == 'b'){
		soCot = 1;
	}
	else if(tolower(toaDo[0]) == 'c'){
		soCot = 2;
	}
	else if(tolower(toaDo[0]) == 'd'){
		soCot = 3;
	}
	else if(tolower(toaDo[0]) == 'e'){
		soCot = 4;
	}
	else if(tolower(toaDo[0]) == 'f'){
		soCot = 5;
	}
	else if(tolower(toaDo[0]) == 'g'){
		soCot = 6;
	}
	else if(tolower(toaDo[0]) == 'h'){
		soCot = 7;
	}
	else if(tolower(toaDo[0] == 'i')){
		soCot = 8;
	}
	soHang = toaDo[1] - '0' - 1;
	if(MATRAN[soHang][soCot] != 0){//kiểm tra ô trống
		//nếu là ô có giá trị
		return 0;//trả về không là ô trống
	}
	//đúng
	return 1;//trả về đúng là ô trống
}

int KiemTraSudokuHoanThien(int MATRAN[Max][Max]){//hàm kiểm tra sudoku đã hoàn chỉnh hay chưa
	//kiểm tra các hàng
	for(int i = 0; i < Max; i++){
		if(KiemTraMotHang(MATRAN, i) == 0){
			return 0;
		}
	}

	//kiểm tra các cột
	for(int j = 0; j < Max; j++){
		if(KiemTraMotCot(MATRAN, j) == 0){
			return 0;
		}
	}

	//kiểm tra các vùng
	for(int i = 0; i < Max; i+=3){
		for(int j = 0; j< Max; j+=3){
			if(KiemTraMotVung(MATRAN,j,i) == 0){
				return 0;
			}
		}
	}
	return 1;
}

int TimViTriDungDeQuy(int MATRAN[Max][Max]){//hàm tìm vị trí cần điền cuối cùng để dừng đệ quy trong hàm GiaiSudoku
	int i, j;
	for (i = Max - 1; i >= 0; i--)
	{
		for (j = Max - 1; j >= 0; j--)
		{
			if (MATRAN[i][j] == 0)
			{
				return (i*Max + j);
			}
		}
	}
}

int KiemTraMotCot(int MATRAN[Max][Max], int cotKT){//hàm kiểm tra một cột
	int gt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sl[9] = {0};
 	for(int i = 0; i < Max; i++){
		for(int n = 0; n < 9; n++){
			if(MATRAN[i][cotKT] == gt[n]){
				sl[n]++;
			}
		}
	}

	for(int n = 0; n < 9; n++){
		if(sl[n] != 1){
			return 0;
		}
	}
	return 1;
}
int KiemTraMotHang(int MATRAN[Max][Max], int hangKT){//hàm kiểm tra một hàng
	int gt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sl[9] = {0};
	for(int j = 0; j < Max; j++){
		for(int n = 0; n < 9; n++){
			if(MATRAN[hangKT][j] == gt[n]){
				sl[n]++;
			}
		}
	}

	for(int n = 0; n < 9; n++){
		if(sl[n] != 1){
			return 0;
		}
	}
	return 1;
}
int KiemTraMotVung(int MATRAN[Max][Max], int cotKT, int hangKT){//hàm kiểm tra một vùng
	int gt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sl[9] = {0};
	for(int i = hangKT; i < hangKT + 3; i++){
		for(int j = cotKT; j < cotKT + 3; j++){
			for(int n = 0; n < 9; n++){
				if(MATRAN[i][j] == gt[n]){
					sl[n]++;
				}
			}
		}
	}

	for(int n = 0; n < 9; n++){
		if(sl[n] != 1){
			return 0;
		}
	}
	return 1;
}

int KiemTraSudokuRong(int MATRAN[Max][Max]){//hàm kiểm tra sudoku rỗng hay không
	int slkt=0;
	for(int i = 0; i < Max; i++){
		for(int j = 0; j < Max; j++){
			if(MATRAN[i][j] == 0){
				slkt++;
			}
		}
	}
	if(slkt == 81){
		return 1;
	}
	else{
		return 0;
	}
}


//=========Định nghĩa các hàm liên quan đến tính năng tạo đề========
void ChuyenViHaiCot(int MATRAN[Max][Max], int cotMoc, int cotDich){//hàm xáo 2 cột chỉ định
	for(int i = 0; i < Max; i++){
		int temp = MATRAN[i][cotMoc];
		MATRAN[i][cotMoc] = MATRAN[i][cotDich];
		MATRAN[i][cotDich] = temp;
	}
}
void ChuyenViHaiHang(int MATRAN[Max][Max], int hangMoc, int hangDich){//hàm xáo 2 hàng chỉ định
	for(int j = 0; j < Max; j++){
		int temp = MATRAN[hangMoc][j];
		MATRAN[hangMoc][j] = MATRAN[hangDich][j];
		MATRAN[hangDich][j] = temp;
	}
}

void ChuyenViHangNhomI(int MATRAN[Max][Max]){//hàm xáo các hàng trong nhóm hàng I
	int solanchuyenvi = 1 + rand() % 3;//1-3
	int hangMoc, hangDich;
	while (solanchuyenvi >= 0){
		hangMoc = rand() % 3;//0-2
		do{
			hangDich = rand() % 3;//0-2
		} while (hangDich == hangMoc);
		ChuyenViHaiHang(MATRAN, hangMoc, hangDich);
		solanchuyenvi--;
	}
}

void ChuyenViHangNhomII(int MATRAN[Max][Max]){//hàm xáo các hàng trong nhóm hàng II
	srand((unsigned)time(NULL));
	int solanchuyenvi = 1 + rand() % 3;//1-3
	int hangMoc, hangDich;
	while (solanchuyenvi >= 0){
		hangMoc = 3 + rand() % 3;//3-5
		do{
			hangDich = 3 + rand() % 3;//3-5 a+rand()%(b-a+1) [a,b]
		} while (hangDich == hangMoc);
		ChuyenViHaiHang(MATRAN, hangMoc, hangDich);
		solanchuyenvi--;
	}
}

void ChuyenViHangNhomIII(int MATRAN[Max][Max]){//hàm xáo các hàng trong nhóm hàng III
	int solanchuyenvi = 1 + rand() % 3;
	int hangMoc, hangDich;
	while (solanchuyenvi >= 0){
		hangMoc = 6 + rand() % 3;//6-8
		do{
			hangDich = 6 + rand() % 3;
		} while (hangDich == hangMoc);
		ChuyenViHaiHang(MATRAN, hangMoc, hangDich);
		solanchuyenvi--;
	}
}

void ChuyenViCotNhomI(int MATRAN[][Max]){//hàm xáo các cột trong nhóm cột I
	int solanchuyenvi = 1 + rand() % 3;
	int cotMoc, cotDich;
	while (solanchuyenvi >= 0){
		cotMoc = rand() % 3;//0-2
		do{
			cotDich = rand() % 3;//0-2
		} while (cotDich == cotMoc);
		ChuyenViHaiCot(MATRAN, cotMoc, cotDich);
		solanchuyenvi--;
	}
}

void ChuyenViCotNhomII(int MATRAN[][Max]){//hàm xáo các cột trong nhóm cột II
	int solanchuyenvi = 1 + rand() % 3;
	int cotMoc, cotDich;
	while (solanchuyenvi >= 0){
		cotMoc = 3 + rand() % 3;
		do{
			cotDich = 3 + rand() % 3;
		} while (cotDich == cotMoc);
		ChuyenViHaiCot(MATRAN, cotMoc, cotDich);
		solanchuyenvi--;
	}
}

void ChuyenViCotNhomIII(int MATRAN[][Max]){//hàm xáo các cột trong nhóm cột III
	int solanchuyenvi = 1 + rand() % 3;
	int cotMoc, cotDich;
	while (solanchuyenvi >= 0){
		cotMoc = 6 + rand() % 3;
		do{
			cotDich = 6 + rand() % 3;
		} while (cotDich == cotMoc);
		ChuyenViHaiCot(MATRAN, cotMoc, cotDich);
		solanchuyenvi--;
	}
}

void XaoHang(int MATRAN[Max][Max]){//hàm xáo hàng trong sudoku
	ChuyenViHangNhomI(MATRAN);
	ChuyenViHangNhomII(MATRAN);
	ChuyenViHangNhomIII(MATRAN);
}

void XaoCot(int MATRAN[Max][Max]){//hàm xáo cột trong sudoku
	ChuyenViCotNhomI(MATRAN);
	ChuyenViCotNhomII(MATRAN);
	ChuyenViCotNhomIII(MATRAN);
}

void TaoDe(int MATRAN[Max][Max], int doKho){//hàm tạo đề sudoku
	int mangKT[81] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 
		4, 5, 6, 7, 8, 9, 1, 2, 3,
		7, 8, 9, 1, 2, 3, 4, 5, 6,
		2, 3, 4, 5, 6, 7, 8, 9, 1, 
		5, 6, 7, 8, 9, 1, 2, 3, 4, 
		8, 9, 1, 2, 3, 4, 5, 6, 7, 
		3, 4, 5, 6, 7, 8, 9, 1, 2,
		6, 7, 8, 9, 1, 2, 3, 4, 5,
		9, 1, 2, 3, 4, 5, 6, 7, 8 };
	int gr = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			MATRAN[i][j] = mangKT[gr];
			gr++;
		}
	}

	XaoHang(MATRAN);
	XaoCot(MATRAN);

	GhiTep(MATRAN,"sudoku_dapan.txt");

	for(int i = 0; i < doKho; i++){
		int a = rand() % 9;//0-9
		int b = rand() %9;//0-9
		MATRAN[a][b]=0;
	}

	FILE *f = fopen("sudoku_de.txt", "wt");
	if(f != NULL){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				fprintf(f, "%d ", MATRAN[i][j]);
			}
			fprintf(f, "\n");
		}
	}
	fclose(f);
}

//=======Định nghĩa hai báo các hàm chức năng của game sudoku=========
void LuatChoi(){
	cout << "Dien cac so tu 1-9 vao cac o con thieu trong bang sudoku 9x9 (81 o)." <<endl
		<< "Quy luat dien nhu sau: " <<endl
		<< "+ Cac o trong cung 1 hang deu phai co cac so tu 1-9, khong duoc trung nhau" <<endl
		<< "+ Cac o trong cung 1 cot deu phai co cac so tu 1-9, khong duoc trung nhau" <<endl
		<< "+ Mot luoi sudoku chia lam 9 vung 3x3, cac o trong cung 1 vung deu phai có cac so tu 1-9, khong duoc trung nhau" <<endl;
}

void GoiYMotOSudoku(int MATRAN[Max][Max], string toaDo){
	int MATRANKQ[Max][Max];
	GiaiSudoku(0,MATRAN);
	DocTep(MATRANKQ, "sudoku_dapan.txt");
	int soHang = 0, soCot = 0;

	if(tolower(toaDo[0]) == 'a'){
		soCot = 0;
	} 
	else if(tolower(toaDo[0]) == 'b'){
		soCot = 1;
	}
	else if(tolower(toaDo[0]) == 'c'){
		soCot = 2;
	}
	else if(tolower(toaDo[0]) == 'd'){
		soCot = 3;
	}
	else if(tolower(toaDo[0]) == 'e'){
		soCot = 4;
	}
	else if(tolower(toaDo[0]) == 'f'){
		soCot = 5;
	}
	else if(tolower(toaDo[0]) == 'g'){
		soCot = 6;
	}
	else if(tolower(toaDo[0]) == 'h'){
		soCot = 7;
	}
	else if(tolower(toaDo[0]) == 'i'){
		soCot = 8;
	}
	soHang = toaDo[1] - '0' - 1;
	MATRAN[soHang][soCot] = MATRANKQ[soHang][soCot];
}

void DienOSudoku(int MATRAN[Max][Max], string toaDo, int giaTri){
	int soHang = 0, soCot = 0;

	if(tolower(toaDo[0]) == 'a'){
		soCot = 0;
	} 
	else if(tolower(toaDo[0]) == 'b'){
		soCot = 1;
	}
	else if(tolower(toaDo[0]) == 'c'){
		soCot = 2;
	}
	else if(tolower(toaDo[0]) == 'd'){
		soCot = 3;
	}
	else if(tolower(toaDo[0]) == 'e'){
		soCot = 4;
	}
	else if(tolower(toaDo[0]) == 'f'){
		soCot = 5;
	}
	else if(tolower(toaDo[0]) == 'g'){
		soCot = 6;
	}
	else if(tolower(toaDo[0]) == 'h'){
		soCot = 7;
	}
	else if(tolower(toaDo[0]) == 'i'){
		soCot = 8;
	}

	soHang = toaDo[1] - '0' - 1;
	MATRAN[soHang][soCot] = giaTri;
}

void TimViTriSai(int MATRAN[Max][Max], int MATRANDAPAN[Max][Max], int MATRANDE[Max][Max]){
	int mangSudoku[81];//đang chơi
	int gr = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			mangSudoku[gr] = MATRAN[i][j];
			gr++;
		}
	}
	int mangSudokuDe[81];//đề
	int g = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			mangSudokuDe[g] = MATRANDE[i][j];
			g++;
		}
	}

	int mangSudokuDA[81];//đap1 án
	int n = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			mangSudokuDA[n] = MATRANDAPAN[i][j];
			n++;
		}
	}

	cout << "  A B C D E F G H I" <<endl;//hàng 2-12, cột 3-19; bước nhảy 2 cho cột, nhảy 1 cho hàng, khác 0 thì đổi màu,
	cout << "1      |     |     " <<endl;
	cout << "2      |     |     " <<endl;
	cout << "3      |     |     " <<endl;
	cout << "  -----------------" <<endl;
	cout << "4      |     |     " <<endl;
	cout << "5      |     |     " <<endl;
	cout << "6      |     |     " <<endl;
	cout << "  -----------------" <<endl;
	cout << "7      |     |     " <<endl;
	cout << "8      |     |     " <<endl;
	cout << "9      |     |     " <<endl;
	int f = 0;
	for (int i = 2; i <= 12; i++){
		for (int j = 3; j <= 19; j += 2){
			if (i != 5 && i != 9){
				gotoXY(j - 1, i - 1);
				if(mangSudoku[f] != mangSudokuDA[f]){
					TextColor(12);//đỏ
					cout << mangSudoku[f];
				}
				else if(mangSudokuDe[f] != 0){
					TextColor(9);//xanh
					cout << mangSudoku[f];
				}
				else if(mangSudokuDe[f] == 0 && mangSudoku[f] == mangSudokuDA[f]){
					TextColor(7);//trắng
					cout << mangSudoku[f];
				}
				f++;
			}
		}
	}
	TextColor(7);
	cout << endl;

	int k = 0;
	for (int i = 0; i < 16; i++)
	{
		gotoXY(22, k);
		cout << "|" << endl;
		k++;
	}

	int m = 0;
	for (int t = 0; t < 11; t ++)
	{
		gotoXY(25, m);

		if (t == 0)
			cout << "SUDOKU V1.0 by TriTuan Studio" << endl;
		if (t == 1)
			cout << "==============Menu Nguoi Choi=============" << endl;
		if (t == 2)
			cout << "1. Luat choi" << endl;
		if (t == 3)
			cout << "2. Tao moi mot bang sudoku" << endl;
		if (t == 4)
			cout << "3. Goi y 1 o sudoku" << endl;
		if (t == 5)
			cout << "4. Tim vi tri sai" << endl;
		if (t == 6)
			cout << "5. Hoan thien sudoku dang giai" << endl;
		if (t == 7)
			cout << "6. Luu ket qua cua luoi hien tai" << endl;
		if (t == 8)
			cout << "7. Quay lai menu chinh" << endl;
		if (t == 9)
			cout << "======HCMUS-2016. All right reserved======" << endl;
		if (t == 10)
			cout << "Nhap toa do de choi hoac nhap cac phim tuy chon" << endl;
		m++;
	}

	gotoXY(1, 20);
}

void DienOSudokuDe(int MATRANDE[Max][Max], string toaDo, int giaTri){
	int soHang = 0, soCot = 0;

	if(tolower(toaDo[0]) == 'a'){
		soCot = 0;
	} 
	else if(tolower(toaDo[0]) == 'b'){
		soCot = 1;
	}
	else if(tolower(toaDo[0]) == 'c'){
		soCot = 2;
	}
	else if(tolower(toaDo[0]) == 'd'){
		soCot = 3;
	}
	else if(tolower(toaDo[0]) == 'e'){
		soCot = 4;
	}
	else if(tolower(toaDo[0]) == 'f'){
		soCot = 5;
	}
	else if(tolower(toaDo[0]) == 'g'){
		soCot = 6;
	}
	else if(tolower(toaDo[0]) == 'h'){
		soCot = 7;
	}
	else if(tolower(toaDo[0]) == 'i'){
		soCot = 8;
	}

	soHang = toaDo[1] - '0' - 1;
	MATRANDE[soHang][soCot] = giaTri;
}

//========Khai báo các hàm liên quan đến việc truy xuất dữ liệu từ tệp
void DocTep(int MATRAN[Max][Max], const char* duongDan){//hàm đọc dữ liệu từ 1 tệp
	FILE *fp = fopen(duongDan, "rt");
	if(fp != NULL){
		for (int i = 0; i < Max; i++)
		{
			for (int j = 0; j < Max; j++)
			{
				fscanf(fp, "%d", &MATRAN[i][j]);
			}
		}
	}
	else{
		cout << "Khong co du lieu." << endl;
	}
	fclose(fp);
}

void GhiTep(int MATRAN[Max][Max], const char* duongDan){//hàm ghi dữ liệu xuống 1 tệp
	FILE *fp = fopen(duongDan, "wt");
	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < Max; j++)
		{
			fprintf(fp, "%d ", MATRAN[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}