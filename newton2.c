#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416f
void f1(double, double, double);
void f2(double, double, double, double);
void f3(double, double, double, double);
void f4(double, double, double, double);
void f5(double, double, double, double);
void main()
{
    double m,n,p,c,x,a,b;
    int ch;
    while(1)
    {
        printf("To solve using Newton Ralphson Method \n");
        printf("1: Find n^p , 2: (sin x)^n + (cos x)^m = c\n");
        printf("3: a sin x + b cos x = c , 4: sin ax + cos bx = c \n");
        printf("5: e^(ax) * sin bx = c , 6: exit  \n");
        printf("Enter the choice \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("Enter n and p \n");
            scanf("%lf %lf", &n, &p);
            printf("Enter the initial root \n");
            scanf("%lf", &x);
            f1(n,p,x);
            break;
            
            case 2:
            printf("Enter n, m, c \n");
            scanf("%lf %lf %lf", &n, &m, &c);
            printf("Enter the initial root \n");
            scanf("%lf", &x);
            f2(n,m,c,x);
            break;
            
            case 3:
            printf("Enter the value of a, b, c \n");
            scanf("%lf %lf %lf", &a, &b, &c);
            printf("Enter the initial root \n");
            scanf("%lf", &x);
            f3(a,b,c,x);
            break;
            
            case 4:
            printf("Enter the value of a, b, c \n");
            scanf("%lf %lf %lf", &a, &b, &c);
            printf("Enter the initial root \n");
            scanf("%lf", &x);
            f4(a,b,c,x);
            break;
            
            case 5:
            printf("Enter the value of a, b, c \n");
            scanf("%lf %lf %lf", &a, &b, &c);
            printf("Enter the initial root \n");
            scanf("%lf", &x);
            f5(a,b,c,x);
            break;
            
            case 6:
            exit(0);
            
            default:
            printf("Invalid input \n");
        }
    }
}
void f1(double n, double p, double x)
{
    int i, flag = 0;
    double root, nr, dr;
    for (i = 1; i < 30; i++)  
    {
        nr = pow(x, (1/p)) - n;
        dr = (1/p)*pow(x, (1/p - 1));
        if (dr!= 0)
        {
            root = x - (nr/dr);
            x = root;
        }
        else
        {
            flag = 1;
            printf("This method fails or there is no solution \n");
            break;
        }
    }
    if(flag == 0)
        printf("Result of %.3f^%.3f = %g \n",n,p, root);
}
void f2(double n, double m, double c, double x)
{
    int i, flag = 0;
    double root, nr, dr;
    for (i = 1; i < 30; i++)  
    {
        if (n == 2 && m == 2 && c == 1)
        {
            flag = 1;
            printf("(sin x)^2 + (cos x)^2 = 1 is an idenity \n");
            break;
        }
        nr = pow(sin(x), n) + pow(cos(x), m) - c;
        dr = (n)*(pow(sin(x), n-1)*cos(x)) - (m)*(pow(cos(x),m-1)*sin(x));
        if (dr!= 0)
        {
            root = x - (nr/dr);
            x = root;
            if (i == 29 && fabs((pow(sin(x), n) + pow(cos(x), m) - c))>0.05)
            {
                flag = 1;
                printf("This method fails or there is no solution \n");
                break;
            }
        }
        else
        {
            flag = 1;
            printf("This method fails or there is no solution \n");
            break;
        }
    }
    if(flag == 0)
        printf("The value of x in the equation (sin x)^%.3f + (cos x)^%.3f = %.3f is %g degrees \n",n,m,c, fmod((root*180)/PI,360.0));
}
void f3(double a, double b, double c, double x)
{
    int i, flag = 0;
    double root, nr, dr;
    for (i = 1; i < 30; i++)  
    {
        nr = a*sin(x) + b*cos(x) - c;
        dr = a*cos(x) - b*sin(x);
        if (dr!= 0)
        {
            root = x - (nr/dr);
            x = root;
            if(i == 29 && fabs(a*sin(x) + b*cos(x) - c)>0.05)
            {
                flag = 1;
                printf("This method fails or there is no solution \n");
                break;
            }
        }
        else
        {
            flag = 1;
            printf("This method fails or there is no solution \n");
            break;
        }
    }
    if(flag == 0)
        printf("The value of x in the equation %.3f*sin x + (%.3f)*cos x = %.3f is %g degrees \n",a,b,c, fmod((root*180)/PI,360.0));
}
void f4(double a, double b, double c, double x)
{
    int i, flag = 0;
    double root, nr, dr;
    for (i = 1; i < 30; i++) 
    {
        nr = sin(a*x) + cos(b*x) - c;
        dr = a*cos(a*x) - b*sin(b*x);
        if (dr!= 0)
        {
            root = x - (nr/dr);
            x = root;
            if(i == 29 && fabs(sin(a*x) + cos(b*x) - c)>0.05)
            {
                flag = 1;
                printf("This method fails or there is no solution \n");
                break;
            }
        }
        else
        {
            flag = 1;
            printf("This method fails or there is no solution \n");
            break;
        }
    }
    if(flag == 0)
        printf("The value of x in the equation sin (%.3f*x) + cos(%.3f*x) = %.3f = %g degrees \n",a,b,c,fmod((root*180)/PI,360.0));
}
void f5(double a, double b, double c, double x)
{
    int i, flag = 0;
    double root, nr, dr;
    for (i = 1; i < 30; i++) 
    {
        nr = pow(2.7182, a*x)*sin(b*x) - c;
        dr = b*pow(2.7182, a*x)*cos(b*x) + a*pow(2.7182, a*x)*sin(b*x);
        if (dr!= 0)
        {
            root = x - (nr/dr);
            x = root;
            if (i == 29 && fabs(pow(2.7182, a*x)*sin(b*x) - c)>0.05)
            {
                flag = 1;
                printf("This method fails or there is no solution \n");
                break;
            }
        }
        else
        {
            flag = 1;
            printf("This method fails or there is no solution \n");
            break;
        }
    }
    if(flag == 0)
        printf("The root in the equation e^(%.3f*x) * sin(%.3f*x) = %.3f is %g (radians) \n",a,b,c, root);
}