#include <stdio.h>
#include "matils.h"
#include <stdlib.h>

int main()
{
        double x[10] = {1,2,3,4,5,6,7,8,9,10};
        double y[10] = {3,5,7,9,11,13,15,17,19,21};
        //double _x;
       // memcpy(_x, x, 10*sizeof(double));
        
        int size = sizeof(x)/sizeof(x[0]);
        double x_test[10] = {11,12,13,14,15,16,17,18,19,20};
        double p[2] = {0,0};
        double* preds;
        fit_model(x, y, size, p);
        printf("%f, %f\n", p[0],p[1]);
        predict(x_test, p, size, preds);
        
        printf("x_test | pred\n");
        for (int i=0; i < size; i++)
        {
          printf("%.2f   |  %.2f\n", x_test[i], preds[i]);
        }
}
