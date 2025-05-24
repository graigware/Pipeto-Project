/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** init_steam_turbine
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void init_steam_turbine(void)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  srand((unsigned int)tVar1);
  puts("Start of the steam turbine initialized");
  sleep(1);
  puts("Steam turbine status: OK");
  sleep(2);
  puts("Steam valves status: OPEN");
  sleep(1);
  puts("Pressurized water tank: OK");
  sleep(1);
  puts("Pressurized water valves: READY");
  sleep(1);
  puts("Steam turbine rotor status: OK");
  sleep(2);
  puts("Starting steam turbine rotor...");
  sleep(1);
  puts("Steam turbine rotor status: OK");
  sleep(1);
  puts("Steam turbine rotor current speed: 1000 r/min");
  sleep(1);
  puts("Reactor initialization complete.");
  sleep(1);
  return;
}
