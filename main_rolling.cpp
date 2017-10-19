//#define WT
//#define ori
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "head.h"
#include "func.h"
#include <sys/stat.h>
using namespace std;
#define K0 1    //7.3
#define K1 6.31 //8.1
#define K2 10   //8.3
#define T 5000
#ifndef ori
int topolo[7][7]={  0,  0,  0,  1,  1,  0,  1,
                    0,  0,  0,  1,  0,  0,  1,
                    0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0, -1,  0,  0,
                    0,  0,  0,  0,  0,  2,  0,
                    0,  0,  0,  0,  0,  0, -1,
                    0,  0,  0, -1,  0,  0,  0
                    };
#else
int topolo[7][7]={  0,  0,  0,  1,  1,  0,  1,
                    0,  0,  0,  0,  0,  0,  1,
                    0,  0,  0, -1,  0,  0, -1,
                    0,  0,  0,  0, -1,  0,  0,
                    0,  0,  0, -1,  1,  2,  0,
                    0,  0,  0,  0,  0,  0, -1,
                    0,  0,  0,  0,  0, -1,  0
                    };
#endif
double k[7][7]={    K0, K0, K0, K0, K0, K0, K0,
                    K0, K0, K0, K0, K0, K0, K0,
                    K0, K0, K0, K0, K0, K0, K0,
                    K0, K0, K0, K0, K0, K0, K0,
                    K0, K0, K0, K0, K0, K0, K0,
                    K0, K0, K0, K0, K0, K0, K0,
                    K0, K0, K0, K0, K0, K0, K0
                    };
double C=3.31;  //0.52;
double alpha[7]={0,0,0,5,5,5,5};//0.13;  //2.9;
double beta=0.13;
int n=4;
double D=0.65;  //0.18;
double dx=0.1;
double dt=0.0005;
double d=D*dt/(dx*dx);
int main()
{
	int i,j;
#ifndef WT
#ifndef ori
    for(i=0;i<7;i++)
    {
//        topolo[1][i]=0;
        topolo[2][i]=0;
    }
#endif
#endif
    FILE *fp;
    mkdir("output",0777);
    char kni[20]="output/kni.txt";
    char hb[20]="output/hb.txt";
    char kr[20]="output/kr.txt";
    char gt[20]="output/gt.txt";
    char fi[20]="output//final.txt";
    fp=fopen(kni,"w");
    fclose(fp);
    fp=fopen(hb,"w");
    fclose(fp);
    fp=fopen(kr,"w");
    fclose(fp);
    fp=fopen(gt,"w");
    fclose(fp);
    fp=fopen(fi,"w");
    fclose(fp);
    pgene Gene[7];
    double tmp[Nx];
    fp=fopen("Bcd.txt","r");
    for(i=0;i<Nx;i++)
        fscanf(fp,"%lf\t",&tmp[i]);
    Gene[0]=new gene(tmp);
    fclose(fp);    
//    fp=fopen("Nos.txt","r");
    for(i=0;i<Nx;i++)
//        fscanf(fp,"%lf\t",&tmp[i]);
        tmp[i]=1-Gene[0]->c0[i];
    Gene[1]=new gene(tmp);
//    fclose(fp);
    fp=fopen("Tll.txt","r");
    for(i=0;i<Nx;i++)
        fscanf(fp,"%lf\t",&tmp[i]);
    Gene[2]=new gene(tmp);
    fclose(fp);
    Gene[3]=new gene();
    fp=fopen("M_hb2.txt","r");
    for(i=0;i<100;i++)
        fscanf(fp,"%lf\t",&tmp[i]);
    Gene[4]=new gene();
    fclose(fp);
    Gene[5]=new gene();
    Gene[6]=new gene();
    for(i=0;i<T;i++)
    {
        if(i%(T/50)==0)
        {   
            Gene[3]->print(kni);
            Gene[4]->print(hb);
            Gene[5]->print(kr);
            Gene[6]->print(gt);
        }    
        nextstep(Gene);
        for(j=3;j<7;j++)
        {
            Gene[j]->next();
        }
    }
    Gene[3]->print(fi);
    Gene[4]->print(fi);
    Gene[5]->print(fi);
    Gene[6]->print(fi);
    return 0;

}
