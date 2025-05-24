/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** turbine_temperature
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void turbine_temperature(void)
{
  size_t sVar1;
  longlong lVar2;
  char local_98 [140];
  int local_c;
  
  printf("Enter the number of degrees you want to increase or d ecrease the turbine temperature : ");
  fgets(local_98,0x80,_stdin);
  sVar1 = strcspn(local_98,"\n");
  local_98[sVar1] = '\0';
  lVar2 = strtoll(local_98,(char **)0x0,10);
  local_c = (int)lVar2;
  if ((local_c != 0x7ffffffe) && (local_c != -0x7fffffff)) {
    printf("Turbine temperature is %d degrees.\n",0x14);
    if (local_c < 0) {
      printf("Turbine temperature is decreasing : %d\n",(ulong)(l ocal_c + 0x14));
    }
    else if (0 < local_c) {
      printf("Turbine temperature is increasing : %d\n",(ulong)(lo cal_c + 0x14));
    }
    return;
  }
  puts("Turbine temperature is too unstable.");
  puts("{ERR0R TURBINE WILL EXPLODE}");
                    /* WARNING: Subroutine does not return */
  exit(1);
}
