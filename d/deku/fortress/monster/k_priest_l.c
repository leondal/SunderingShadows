#include <std.h>
#include "/d/deku/inherits/graveyard.h";
inherit "/d/deku/fortress/monster/k_priest.c";

void create() 
{
  ::create();
  set_speed(50);
  set_moving(1);
  set_nogo(({NO,NO2,NO3,NO4,NO5,NO6,NO7,NO8}));
}
