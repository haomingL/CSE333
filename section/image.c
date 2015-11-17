#include <stdio.h>

int main(int args, char* argv[]) {
	FILE* fp;
	FILE* fp2;
	int ch;

	fp = fopen("img1.ppm", "r");
	fp2 = fopen("img2.ppm", "w");

	while(1) {
      ch = fgetc(fp);
      if(feof(fp))
      { 
         break ;
      }
      prinf("%d", ch);
      fputc(ch, fp2);
   }
   fclose(fp);
   fclose(fp2);
}