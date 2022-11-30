#include <stdio.h>
//#include <conio.h>
#include <math.h>

#define f(x, y) x + y

double C(double gama_t){
    return 2*gama_t;
} 

double U0(double psi){
    return exp(-pow(psi, 2));
}

int main(){
    double t_0, gama_0, t_n, c, gama_n, dt, u, psi;
    int i, n;
    //clrscr();
    printf("Condições iniciais\n");
    printf("t_0 = ");
    scanf("%lf", &t_0);
    printf("gama_0 = ");
    scanf("%lf", &gama_0);
    printf("Digite o tempo final t_n = ");
    scanf("%lf", &t_n);
    printf("Quantidade de iteracoes: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    dt = (t_n-t_0)/n;

    /* Euler's Method */
    printf("\nt\tgama_n\tu\tdt = %.4f \n", dt);
    printf("------------------------------\n");
    for(i=0; i < n; i++){
        c = C(gama_0);
        gama_n = gama_0 + c * dt;
        psi = gama_n * exp(-2.0*t_0);
        u = U0(psi);
        printf("%.4f\t%.4f\t%.4f\n",t_0,gama_n, u);
        gama_0 = gama_n;
        t_0 = t_0 + dt;
    }

    /* Displaying result */
    printf("\nValue of gama at t = %0.2f is %0.3f",t_n, gama_n);

    //getch();
    return 0;
}