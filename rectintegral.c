#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float f(float x){
	 return log(x)-1;
 }
float df(float x){
	 return 1/x;
}
void dichotomie(){
		double a=2.0;
		double b=5.0;
		double c=0.0;
		double d=2.0;
		double fa,fb,fc;
		float eps = 0.0000001;
		
		while(fabs(b-a)>eps){
			c=(b+a)/d;
			fa=log(a)-1;
			fb=log(b)-1;
			fc=log(c)-1;
			if(fc*fa<0){
				b=c;
			}
			if(fb*fc<0){
				a=c;
			}
		}
		printf("dicho = %lf\n",c);
	}
void calcul_daire(float a,float b,float d){
	  float aire=0.0;
	  float s=0.0;
	  while((a+d)<b){
		  //aire de rectangle
		  s+=f(a)*d;
		//aire de trapeze
		  
		  aire+=((f(a)+f(a+d))*(d)/2); 
		  
		   a+=d;
	  }
	  printf(" rectangle = %f and trapeze = %f\n",s,aire);
 }
 void meth_tang(float a,float b, float d){
	float x=2;
	while(fabs(f(x))>=d){
		x=(x-(f(x)/df(x)));
	}
	printf("tangente = %f\n",x);
 }
 
 void meth_secante (float a,float b, float d){
	 float xn=0.0;
	 float x1 = b,x0 = a;
	 while(fabs(f(x0)-f(x1)) > d){
		xn = x1 -((x1-x0)*f(x1))/(f(x1) - f(x0));
		x0 = x1;
		x1 = xn;
	 }
	 printf("secante = %f\n",xn); 
 }
 
int main(){
	
	 int N=10000;
	 float a=1;
	 float b=10; 
	 float d=(b+a)/N;
	 
	 dichotomie();
	 meth_tang( a, b, d);	
	 meth_secante(a,b,d);
	 calcul_daire(a, b, d);
	 
	 return 0;
}
