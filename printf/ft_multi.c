/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:35:03 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/17 12:35:06 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *del10(char *s, int k)
{
	int len;
	char *s2;
	int i;
	
	if (k >= (len = ft_strlen(s)))
	{
		k = k - len + 2;
		s2 = ft_memset(ft_strnew(k), '0', k);
		s2[1] = '.';
		return (ft_strjoin(s2, s));
	}
	s2 = ft_strnew(len + 1);
	k = len - k - 1;
	i = 1;
	while (--len >= 0)
	{
		if (len == k)
		{
			s2[len + i] = '.';
			i = 0;
		}
		s2[len + i] = s[len];
	}
	return (s2);
}
char* ft_degr2(int k)
{
	static char *d[60] = {"2", "4", "8","16", "32", "64","128", "256", "512","1024", "2048", "4096",
	 "8192", "16384", "32768","65536", "131072", "262144","524288", "1048576",
	 "2097152","4194304", "8388608", "16777216","33554432", "67108864", "134217728",
	 "268435456", "536870912", "10737418224", "2147483648", "4294967296", "8589934592",
	 "17179869184", "34359738368", "68719476736", "137438953472", "274877906944",
	 "549755813888", "1099511627776", "2199023255552", "4398046511104", "8796093022208",
	 "17592186044416", "35184372088832", "70368744177664", "140737488355328", "281474976710656",
	 "562949953421312", "1125899906842624", "2251799813685248", "4503599627370496", "9007199254740992",
	 "18014398509481984", "36028797018963968", "72057594037927936", "144115188075855872", "288230376151711744",
	 "576460752303423488", "1152921504606846976"};
	char *k2;
	
	k2 = "";
	while (k > 0)
	{
		if (k < 60)
		{
			if (!k2[0])
				return (d[k - 1]);
			return (ft_multi(d[k - 1], k2));
		}
		if (k >= 60 && !k2[0])
		{
			k2 = d[59];
			k -= 60;
		}
		else if (k >= 60 && k2[0])
		{
			k2 = ft_multi(d[59], k2);
			k -= 60;
		}
	}
	return (k2);
}

char* ft_degr5(int k)
{
	static char *d[60] = {"5", "25", "125","625", "3125", "15625","78125", "390625", "1953125",
					   "9765625", "48828125", "244140625", "1220703125", "6103515625","30517578125",
					   "152587890625", "762939453125", "3814697265625", "19073486328125","95367431640625",
			"476837158203125", "2384185791015625", "11920928955078125", "59604644775390625","298023223876953125",
			"1490116119384765625", "7450580596923828125", "37252902984619140625", "186264514923095703125",
			"931322574615478515625", "4656612873077392578125", "23283064365386962890625", "116415321826934814453125",
			"582076609134674072265625","2910383045673370361328125", "14551915228366851806640625",
			"72759576141834259033203125", "363797880709171295166015625", "1818989403545856475830078125",
			"9094947017729282379150390625", "45474735088646411895751953125", "227373675443232059478759765625",
			"1136868377216160297393798828125", "5684341886080801486968994140625","28421709430404007434844970703125",
			"142108547152020037174224853515625", "710542735760100185871124267578125",
			"3552713678800500929355621337890625", "17763568394002504646778106689453125",
			"88817841970012523233890533447265625","444089209850062616169452667236328125",
			"2220446049250313080847263336181640625", "11102230246251565404236316680908203125",
			"55511151231257827021181583404541015625", "277555756156289135105907917022705078125",
			"1387778780781445675529539585113525390625", "6938893903907228377647697925567626953125",
			"34694469519536141888238489627838134765625", "173472347597680709441192448139190673828125",
			"867361737988403547205962240695953369140625"};
	
	char *k2;
	
	k2 = "";
	while (k > 0)
	{
		if (k < 60)
		{
			if (!k2[0])
				return (d[k - 1]);
			return (ft_multi(d[k - 1], k2));
		}
		if (k >= 60 && !k2[0])
		{
			k2 = d[59];
			k -= 60;
		}
		else if (k >= 60 && k2[0])
		{
			k2 = ft_multi(d[59], k2);
			k -= 60;
		}
	}
	return (k2);
}

char *revers_s(int *s , long long int i)
{
	char *s2;
	int j;
	
	s2 = (char*)malloc(i + 1);
	s2[i] = 0;
	j = 0;
	while (--i >= 0)
		s2[j++] = s[i] + 48;
	if (s2[0] == '0')
		s2++;
	return (s2);
	
}

char* ft_multi(char *wer1, char* wer)// 1 и  2 число длина которого не превышает 9999 знаков
{
	int d;
	int r;
	int *C;
	int i;
	int k;
	int j;
	int l;
	
	if (wer[0] == 48 || wer1[0] == 48)
		return (0);
	d = ft_strlen(wer);
	r = ft_strlen(wer1);// длина А и В
	C = (int *) malloc(sizeof(int) * 99999);// создаем массив в котором будем хранить результат
	i = d - 1;
	k = 1;
	while (i > -1)// запускаем цикл, в котором умножаем короткое число
	{ //на каждый элемент массива с обратной стороны
		j = r - 1;//и сохраняем результат в массиве C, не заботясь о переносе
		l = 1;
		while (j > -1)
		{
			
			C[k + l - 2] += (wer[i] - 48) * (wer1[j] - 48);
			j--;
			l++;
		}
		i--;
		k++;
	}
	i = 0;
	while (i != d + r - 1)// пройдем по полученному массиву и сделаем переносы
	{
		C[i + 1] = C[i + 1] + (C[i] / 10);
		C[i] = C[i] % 10;
		i++;
	}
	return (revers_s(C, d + r));
}

