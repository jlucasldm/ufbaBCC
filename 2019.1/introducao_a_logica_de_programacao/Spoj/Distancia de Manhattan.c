#include <stdio.h>
int main (){

  int Xm;
  int Ym;
  int Xr;
  int Yr;

  scanf("%d%d%d%d",&Xm, &Ym, &Xr, &Yr);
  
  if(Xm>Xr && Ym>Yr){
  printf("%d\n", Xm-Xr+Ym-Yr);}

  if(Xm<=Xr && Ym>Yr){
  printf("%d\n", Xr-Xm+Ym-Yr);}
  
  if(Xm<=Xr && Yr>=Ym){
  printf("%d\n", Xr-Xm+Yr-Ym);}
  
  if(Xm>Xr && Yr>=Ym){
  printf("%d\n", Xm-Xr+Yr-Ym);}

return 0;
}
