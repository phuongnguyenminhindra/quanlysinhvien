#include<stdio.h>
#include<math.h>

int main(){
    float a1,b1,c1,a2,b2,c2;
    float D,Dx,Dy;
    printf("Nhap ");
    scanf("%f %f %f %f %f %f", &a1,&b1,&c1,&a2,&b2,&c2);
    D = a1*b2-a2*b1;
    Dx = c1*b2-c2*b1;
    Dy = a1*c2-a2*c1;
    if(D != 0){
        printf("Nghiệm của hệ phương trình là x = %f, y = %f " ,Dx/D,Dy/D);

    }else{
        if(Dx == 0 && Dy == 0){
            printf("Hệ phương trình có vô số nghiệm ");
        }else{
            printf("Hệ phương trình vô nghiệm ");
        }
    }

    
}