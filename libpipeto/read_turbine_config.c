#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void read_turbine_config(void)
{
  size_t sVar1;
  char *pcVar2;
  char local_298 [256];
  char local_198 [256];
  char local_98 [136];
  FILE *local_10;
  
  printf("Enter the configuration file name: ");
  fgets(local_98,0x80,stdin);
  sVar1 = strcspn(local_98,"\n");
  local_98[sVar1] = '\0';
  pcVar2 = strstr(local_98,"..");
  if (pcVar2 == (char *)0x0) {
    snprintf(local_198,0x100,"Data/%s",local_98);
    local_10 = fopen(local_198,"r");
    if (local_10 == (FILE *)0x0) {
      printf("Error: Unable to open file: %s\n",local_198);
    }
    else {
      printf("Reading configuration file: %s\n",local_198);
      while(1) {
        pcVar2 = fgets(local_298,0x100,local_10);
        if (pcVar2 == (char *)0x0) break;
        printf("%s",local_298);
      }
      fclose(local_10);
    }
  }
  else {
    puts("Error: Invalid file name.");
  }
  return;
}
