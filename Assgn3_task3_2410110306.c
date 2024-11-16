#include <stdio.h>
#include <math.h>
int main(){
        float population=10000;
        float decline=10;
        float final;

        final=population*pow((1-decline/100),5);
        printf("Population %f is reduced to : %f \n", population, final);
}
