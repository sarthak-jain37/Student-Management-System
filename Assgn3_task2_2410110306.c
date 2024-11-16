#include <stdio.h>
#include <math.h>

	int main(){
		int h,r;
		float l, sa;

		printf("Enter the height of the cylinder: ");
		scanf("%d", &h);
		printf("Enter the radius of the cylinder: ");
                scanf("%d", &r);

	        l=sqrt((pow(h,2)+pow(r,2)));
	        sa=22*(r*(r+l))/7;

	        printf("The surface area of the maximum size cone that can be inscribed in the cylinder is: %f \n",sa);

	}
