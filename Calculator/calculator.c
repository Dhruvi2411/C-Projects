#include<stdio.h>
#include<math.h>

double division(double, double);
double modulus(int, int);
void print_menu();

int main() {

  int choice;
  double first, second, result;

  while (1) {
    print_menu();
    scanf("%d", &choice);

    if(choice == 7) 
      break;
    
    if(choice < 1 || choice > 7) {
      fprintf(stderr,"Invalid menu choice:");
      continue;
    }
    
    printf("\nEnter the first number: ");
    scanf("%lf", &first);

    printf("\nEnter the second number: ");
    scanf("%lf", &second);
    
    switch (choice) {
    case 1: 
      result = first + second; 
      break;
    
    case 2: 
      result = first - second; 
      break;

    case 3: 
      result = first * second; 
      break;

    case 4: 
      result = division(first, second); 
      break;

    case 5: 
      result = modulus(first, second); 
      break;

    case 6: 
      result = pow(first, second);  
      break;

    default:
      printf("Please enter a valid choice");
      break;
    }

    printf("\nResult of operation is %.2f: ", result);
  }

  return 0;
}

void print_menu() {

  printf("\nChoose one of the follwing option:");
  printf("\n1. Add");
  printf("\n.2 Subtract");
  printf("\n3. Multiply");
  printf("\n4. Divide");
  printf("\n5. Modulus");
  printf("\n6. Power");
  printf("\n7. Exit");
  printf("\nEnter your Choice: ");
}

double division(double a, double b) {
  if(b == 0) {
    fprintf(stderr, "Invalid argument for division");
    return NAN;
  }
  else
    return a / b;
}

double modulus(int a, int b) {
  if(b == 0) {
    fprintf(stderr, "Invalid argument for modulus");
    return NAN;
  }

  else 
    return a % b;
}