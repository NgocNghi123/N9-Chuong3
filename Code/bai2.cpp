#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXSIZE 100
void nhap_Chuoi(char a[])
{
	printf("Nhap chuoi:");
	gets(a);
}

void xuat_Chuoi(char a[])
{
	printf("Chuoi vua nhap la:%s", a);
}

void demKhoangTrang(char a[])
{
	int dem=0;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i]==' ')
		{
			dem++;
		}
	}

	printf("So luong khoang trang trong chuoi la: %d", dem);
}

void xoaPhanTu(char a[], int vitri)
{
	for (int i = vitri; i < strlen(a); i++)
	{
		a[i]=a[i+1];
	}
}

void xoa_KhoangTrangDau(char a[])
{
	xoaPhanTu(a,0);
}
void xoa_KhoangTrangCuoi(char a[])
{
	int n = strlen(a)-1;
	xoaPhanTu(a,n);
}

void xoa_KhoangTrangThua(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i]==' ')
		{
			while (a[i+1]==' ')
			{
				xoaPhanTu(a,i);
			}
		}
	}

	if (a[0]==' ')
	{
		xoa_KhoangTrangDau(a);
	}
	int n = strlen(a)-1;
	if (a[n]==' ')
	{
		xoa_KhoangTrangCuoi(a);
	}
}

void chuyenDoi_Chuoi(char a[])
{
	if (a[0] >=97 && a[0] <= 122)
	{
		a[0]-=32;
	}

	for (int i = 1; i < strlen(a); i++)
	{
		if (a[i-1]==' ')
		{
			if (a[i]>=97 && a[i] <= 122)
			{
				a[i]-=32;
			}
		}
		else if (a[i] >= 65 && a[i] <= 90)
		{
			a[i]+=32;
		}
	}
}

void timKiemChuoi(char a[])
{
	char b[MAXSIZE];
	printf("Nhap chuoi can tim:");
	gets(b);
	if (strstr(a,b)==NULL)
	{
		printf("Khong tim thay chuoi '%s' trong chuoi '%s'", b, a);
	}
	else printf("Da tim thay chuoi '%s' trong chuoi '%s'", b, a);
}

void cat_Chuoi(char a[])
{
	char str1[MAXSIZE];
	int j=0;
	for (int i = strlen(a)-1; i > 0; i--)
	{
		if (a[i] != ' ')
		{
			str1[j]=a[i];
			xoaPhanTu(a,i);
			j++;
		}
		else break;
	}
	str1[j]= '\0';

	printf("Chuoi ho lot:%s\n", a);
	printf("Chuoi ten:%s", strrev(str1));
}

int main()
{
	char a[MAXSIZE];
	nhap_Chuoi(a);
	xuat_Chuoi(a);
	printf("\n---------------------------------------\n");
	demKhoangTrang(a);
	printf("\n---------------------------------------\n");
	xoa_KhoangTrangThua(a);
	xuat_Chuoi(a);
	printf("\n---------------------------------------\n");
	chuyenDoi_Chuoi(a);
	xuat_Chuoi(a);
	printf("\n---------------------------------------\n");
	timKiemChuoi(a);
	printf("\n---------------------------------------\n");
	cat_Chuoi(a);
	getch();
	return 0;
}