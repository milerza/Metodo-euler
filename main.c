#include <stdio.h>
#include <conio.h>
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
    clrscr();
    printf("Condições iniciais\n");
    printf("t_0 = ");
    scanf("%d", &t_0);
    printf("gama_0 = ");
    scanf("%d", &gama_0);
    printf("Digite o tempo final t_n = ");
    scanf("%d", &t_n);
    printf("Quantidade de iteracoes: ");
    scanf("%i", &n);

    /* Calculating step size (h) */
    dt = (t_n-t_0)/n;

    /* Euler's Method */
    printf("\nt_0\tgama_0\tdt\tgama_n\tu\n");
    printf("------------------------------\n");
    for(i=0; i < n; i++){
        c = C(gama_0);
        gama_n = gama_0 + c * dt;
        psi = gama_n * exp(-2*t_n);
        u = U0(psi);
        printf("%.4f\t%.4f\t%0.4f\t%.4f\t%.4f\n",t_0,gama_0,dt,gama_n, u);
        gama_0 = gama_n;
        t_0 = t_0 + c;
    }

    /* Displaying result */
    printf("\nValue of gama at t = %0.2f is %0.3f",t_n, gama_n);

    getch();
    return 0;
}