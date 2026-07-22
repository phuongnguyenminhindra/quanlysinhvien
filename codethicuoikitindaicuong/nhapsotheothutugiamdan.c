#include <stdio.h>
main()
{int i=0,a[7];
 printf("Nhap vao 7 so nguyen theo thu tu giam dan:");
 printf("\n");
 while(i<7)        
 {printf("Nhap so thu %d: ",i+1);
  scanf("%d",&a[i]);
  if(i>0&&a[i]>=a[i-1]) 
        {printf("Ban phai nhap gia tri sau be hon gia tri truoc.(Hay nhap lai)");
         continue;}
  i++;}
 printf("\nDay so vua nhap la:\n");
 for(i=0;i<7;i++) printf("%d,",a[i]);
 
}
	
