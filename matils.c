#include "matils.h"
#include <stdlib.h>

double sum_array(double arr[],int size)
{
        double x=0.0;
        for (int i=0; i < size; i++)
        {
                 x = x + arr[i];
        }
        return x;
}

double mean(double arr[],int size)
{
        double sum = sum_array(arr, size);
       // printf("arr_len= %d", size);
        return sum /(double) size;
}

double* mean_dev(double arr[], int size)
{
        double m = mean(arr, size);
        double* dev_arr = (double*)malloc(size * sizeof(double));
        for (int i = 0; i < size; i++)
        {
                dev_arr[i] = arr[i] - m;
         }
         return dev_arr;
}

double* squared_dev(double* arr, int size)
{
        double* m_arr = mean_dev(arr,size);
        double* sqrd_arr = (double*)malloc(size * sizeof(double));
        for (int i = 0; i < size; i++)
        {
          sqrd_arr[i] = m_arr[i] * m_arr[i];
        }
        return sqrd_arr;
}

double variance(double* arr, int size)
{
  int divider = size - 1;
  double* sq_dev = squared_dev(arr,size);
  double sum = sum_array(sq_dev, size);
  return sum / divider;
}

double* array_mul(double* x, double* y, int size)
{
 double* res = (double*)malloc(size * sizeof(double));
  for (int i = 0; i < size; i++)
  {
    res[i] = x[i] * y[i];
  }
  return res;
}

double covariance(double* x, double* y, int size)
{
  int DIVIDER;
  if (size > 500){
    DIVIDER = size;
  } else {
    DIVIDER = size - 1;
  }
  double* dev_x = mean_dev(x, size);
  double* dev_y = mean_dev(y, size);
  double* z = array_mul(dev_x, dev_y, size);
  double sum = sum_array(z, size);
  return sum/DIVIDER;
}

double slope(double* x, double* y, int size)
{
  return covariance(x, y,size)/variance(x, size);
}

double intercept(double* x, double*y, int size)
{
  double mean_x = mean(x, size);
  double mean_y = mean(y,size);
  double itcpt = mean_y - ( slope(x, y,size) * mean_x);
  return itcpt;
}

double* fit_model(double* x, double* y, int size, double* params)
{
  double b = intercept(x, y, size);
  double m = slope(x, y, size);
  params[0]=m;
  params[1] = b;
  return params;
}

double* predict(double* x, double* params, int size, double* p_arr)
{
  double m = params[0];
  double b = params[1];
 // double* p_arr = (double*)malloc(size * sizeof(double));
  for (int i=0; i < size; i++)
  {
    p_arr[i] = (m * x[i]) + b;
  }
  return p_arr;
}


