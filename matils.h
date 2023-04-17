double product(double x, double y);

double power(double x, int y);
double division(double x, double);

double  sum_array(double arr[], int size);
double  mean(double arr[], int size);
double* mean_dev(double arr[], int size);

double* squared_dev(double* arr, int size);
double variance(double* arr, int size);
double* array_mul(double* x, double* y, int size);
double covariance(double* x, double* y, int size);
double intercept(double* x, double* y, int size);
double* fit_model(double* x, double* y, int size, double* params);
double slope(double* x, double* y, int size);
double* predict(double* x, double* params, int size, double* p_arr);
