 #include <stdio.h>

typedef struct Vehicle
{
  void (*accelerate)(struct Vehicle *v);
  void (*brake)(struct Vehicle *v);
  void (*startEngine)(struct Vehicle *v);
} Vehicle;

void accelerate(Vehicle *v)
{
  printf("Car : Pressing gas pedal...\n");
}

void brake(Vehicle *v)
{
  printf("Car : Applying brakes...\n");
}

void startEngine(Vehicle* v)
{
  printf("Car : Engine started!\n");
}

int main()
{
  Vehicle myCar = {accelerate,brake,startEngine};
  Vehicle janesCar = {accelerate,brake,startEngine};
  Vehicle jacksCar = {accelerate,brake,startEngine};
  myCar.startEngine(&myCar);
  myCar.accelerate(&myCar);
  myCar.brake(&myCar);
  janesCar.brake(&myCar);
  jacksCar.startEngine(&myCar);
  janesCar.accelerate(&myCar);
  return 0;
}
