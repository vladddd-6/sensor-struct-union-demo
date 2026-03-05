#include <stdio.h>
#include <stdlib.h>

typedef union
{
    int temperature;
    float pressure;
    char alert[10];
} SensorValue;

typedef struct
{
    char id[5];
    int data_type;
    SensorValue data;
} Sensor;

int main()
{
    Sensor s;

    printf("Sensor ID: ");
    scanf("%s", s.id);

    printf("What reading do we have?\n");
    printf("(1 = temperature) (2 = pressure) (3 = alert) \n");
    scanf("%d", &s.data_type);

    if (s.data_type==1)
    {
        printf("Enter temperature: ");
        scanf("%d", &s.data.temperature);
    }
    else if (s.data_type==2)
    {
        printf("Enter pressure: ");
        scanf("%f", &s.data.pressure);
    }
    else
    {
        printf("Enter alert message: ");
        scanf("%s", s.data.alert);
    }

    printf("\n--- SENSOR DATA %s ---\n", s.id);

    if (s.data_type==1)
        printf("Temperature: %d C\n", s.data.temperature);
    else if (s.data_type==2)
        printf("Pressure: %f atm\n", s.data.pressure);
    else
        printf("Alert: %s\n", s.data.alert);

    return 0;
}
