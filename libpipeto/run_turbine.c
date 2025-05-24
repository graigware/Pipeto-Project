/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** run_turbine
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void run_turbine(void)

{
  int iVar1;
  size_t sVar2;
  char local_98 [136];
  uint local_10;
  uint local_c;
  
  local_c = 0;
  printf("Enter the number of rotation that the turbine will do (b etween 0 and 15): ");
  fgets(local_98,0x80,_stdin);
  sVar2 = strcspn(local_98,"\n");
  local_98[sVar2] = '\0';
  local_10 = atoi(local_98);
  if ((local_10 == 0) || ((int)local_10 < 0x10)) {
    for (; local_c != local_10; local_c = local_c + 1) {
      if (0xf < local_c) {
        puts("{ERR0R TURB1NE CAN\'T ST0P}");
      }
      printf("Turbine is running... %d/%d\n",(ulong)(local_c + 1),( ulong)local_10);
      iVar1 = rand();
      sleep(iVar1 % 3 + 1);
    }
    puts("Turbine has stopped.");
  }
  else {
    puts("Invalid number of rotations.");
  }
  return;
}
