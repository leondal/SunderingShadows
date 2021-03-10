#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_long(
  "  You stand on the main floor of the bathhouse in the city of Torm."
  "  A curtain blocks a small room to the west while marble stairs lead south down into the bath itself."
  );
  set_exits(([
  "south":TCITY+"c118",
  "east":TCITY+"c114",
  "west":TCITY+"c116",
  ]));
  set_door("curtain",TCITY+"c116","west","Torm masterkey");
}
