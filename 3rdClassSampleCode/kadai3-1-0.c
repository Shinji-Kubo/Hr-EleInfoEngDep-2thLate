#include<stdio.h>

int krypto(int, int, int, int, int, int);

main(void) {
	int i, j;
	int cnt = 0;
	int n[10];
	
	int len = 46;
	int arr[len]; // 11 -> +, 12 -> -, 13 -> *, 14 -> /
	int a, b, c, d, e, f, g, h, k, l;
	
	for (i=1; i<15; i++) {
		if (i < 11) {
			for (j=0; j<3; j++) {
				arr[cnt] = i;
				cnt++;
			}
		} else {
			for (j=0; j<4; j++) {
				arr[cnt] = i;
				cnt++;
			}
		}
	}

	for (n[0]=0; n[0]<len; n[0]++) {
		a = arr[n[0]];

		if (a > 10) {break;}

		for (n[1]=0; n[1]<len; n[1]++) {
			b = arr[n[1]];
			while (n[0] == n[1]) {
				n[1]++;
				b = arr[n[1]];
			}
			if (n[1] >= len || b > 10) {break;}

			for (n[2]=0; n[2]<len; n[2]++) {
				c = arr[n[2]];
			 	while (n[0] == n[2] || n[1] == n[2]) {
			 		n[2]++;
			 		c = arr[n[2]];
			 	}
			 	if (n[2] >= len) {break;}

			 	for (n[3]=0; n[3]<len; n[3]++) {
					d = arr[n[3]];
					while (n[0] == n[3] || n[1] == n[3] || n[2] == n[3]) {
						n[3]++;
						d = arr[n[3]];
					}
					if (n[3] >= len) {break;}

					for (n[4]=0; n[4]<len; n[4]++) {
						e = arr[n[4]];
						while (n[0] == n[4] || n[1] == n[4] || n[2] == n[4] || n[3] == n[4]) {
							n[4]++;
							e = arr[n[4]];
						}
						if (n[4] >= len) {break;}

						for (n[5]=0; n[5]<len; n[5]++) {
						 	f = arr[n[5]];
						 	while (n[0] == n[5] || n[1] == n[5] || n[2] == n[5] || n[3] == n[5] || n[4] == n[5]) {
						 		n[5]++;
						 		f = arr[n[5]];
						 	}
						 	if (n[5] >= len) {break;}

						 	for (n[6]=0; n[6]<len; n[6]++) {
						 		g = arr[n[6]];
						 		while (n[0] == n[6] || n[1] == n[6] || n[2] == n[6] || n[3] == n[6] || n[4] == n[6] || n[5] == n[6]) {
						 			n[6]++;
						 			g = arr[n[6]];
						 		}
						 		if (n[6] >= len) {break;}

						 		for (n[7]=0; n[7]<len; n[7]++) {
						 			h = arr[n[7]];
						 			while (n[0] == n[7] || n[1] == n[7] || n[2] == n[7] || n[3] == n[7] || n[4] == n[7] || n[5] == n[7] || n[6] == n[7]) {
						 				n[7]++;
						 				h = arr[n[7]];
						 			}
						 			if (n[7] >= len) {break;}

						 			for (n[8]=0; n[8]<len; n[8]++) {
						 				k = arr[n[8]];
						 				while (n[0] == n[8] || n[1] == n[8] || n[2] == n[8] || n[3] == n[8] || n[4] == n[8] || n[5] == n[8] || n[6] == n[8] || n[7] == n[8]) {
						 					n[8]++;
						 					k = arr[n[8]];
						 				}
						 				if (n[8] >= len) {break;}

						 				for (n[9]=0; n[9]<len; n[9]++) {
						 					l = arr[n[9]];
											if (l < 11) {break;}
						 					while (n[0] == n[9] || n[1] == n[9] || n[2] == n[9] || n[3] == n[9] || n[4] == n[9] || n[5] == n[9] || n[6] == n[9] || n[7] == n[9] || n[8] == n[9]) {
						 						n[9]++;
						 						l = arr[n[9]];
						 					}
						 					if (n[9] >= len) {break;}
						 				}
						 			}
						 		}
						 	}	

						}

					}
				}
			 }			
		}	
	}
	

	return 0;
}

int krypto(int a, int b, int c, int d, int e, int f) {
	int i, j;
	int cnt = 0;
	int n[4];
	
	int len = 16;
	int arr[16]; // 1 -> +, 2 -> -, 3 -> *, 4 -> /
	int Ca, Cb, Cc, Cd;

	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			arr[cnt] = i;
			cnt++;
		}
	}

	for (n[0]=0; n[0]<len; n[0]++) {
		Ca = arr[n[0]];
		
		for (n[1]=0; n[1]<len; n[1]++) {
			Cb = arr[n[1]];
			while (n[0] == n[1]) {
				n[1]++;
				Cb = arr[n[1]];
			}
			if (n[1] >= len) {
				break;
			}

			for (n[2]=0; n[2]<len; n[2]++) {
				Cc = arr[n[2]];
				while (n[0] == n[2] || n[1] == n[2]) {
					n[2]++;
					Cc = arr[n[2]];
				}
				if (n[2] >= len) {
					break;
				}

				for (n[3]=0; n[3]<len; n[3]++) {
					Cd = arr[n[3]];
					while (n[0] == n[3] || n[1] == n[3] || n[2] == n[3]) {
						n[3]++;
						Cd = arr[n[3]];
					}
					if (n[3] >= len) {
						break;
					}
				}
			}
		}		
	}

	return 0;
}
