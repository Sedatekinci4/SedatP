#include <stdio.h>
#include <math.h>

double getDistanceFromLatLon (double latitude1, double longitude1,double latitude2, double longitude2);

int main (){
    char cityname_1[100];
    char cityname_2[100];

    double latitude_1, latitude_2, longitude_1, longitude_2, distance;

    printf("Enter the name of City 1:\t");
    fgets(cityname_1,100,stdin);
    printf("Enter the Name of City 2:\t");
    fgets(cityname_2,100,stdin);

    printf("\nPlease enter the first cities or points latitude:\t");
    scanf("%lf", &latitude_1);
    printf("\nPlease enter the first cities or points longitude:\t");
    scanf("%lf", &longitude_1);
    printf("\nPlease enter the second cities or points latitude:\t");
    scanf("%lf", &latitude_2);
    printf("\nPlease enter the second cities or points longitude:\t");
    scanf("%lf", &longitude_2);

    distance = getDistanceFromLatLon(latitude_1,longitude_1,latitude_2,longitude_2);

    printf("Distance between \n\n%s||||||||||||||\n\n%s||||||||||||||\n\n\t%lf Km", cityname_1, cityname_2, distance);

    return 0;
}

double getDistanceFromLatLon (double latitude1, double longitude1,double latitude2, double longitude2)
{
    double radiusOfEarth = 6371;
    double convertToRadians = (3.1415926536/180);
    double dx, dy, dz;
	longitude1 -= longitude2;
	longitude1 *= convertToRadians, latitude1 *= convertToRadians, latitude2 *= convertToRadians;
	dz = sin(latitude1) - sin(latitude2);
	dx = cos(longitude1) * cos(latitude1) - cos(latitude2);
	dy = sin(longitude1) * cos(latitude1);
	double result= asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * radiusOfEarth;
    return result;
}
