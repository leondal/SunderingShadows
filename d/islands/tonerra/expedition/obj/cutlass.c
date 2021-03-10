/*
  cutlass.c
  
  Basic cutlass that is being carried by the treasure-
  hunting expedition.
  
  -- Tlaloc - 11/2019
*/
  
#include <std.h>

inherit WEAPON;

void create(){
  ::create();
  set_name("cutlass");
  set_id( ({ "cutlass","sword" }) );
  set_short("pirate's cutlass");
  set_long("\
  This is a vicious-looking cutlass, often used by seafaring sailors or
  pirates. It has a curved blade, perfect for slashing, with a leather-bound
  handle and steel handguard.\n");
  
  set_type("slashing");
  set_wc(1, 6);
  set_size(1);
  set_weight(5);
}
