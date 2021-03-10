#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_long(
    "  You stand in a small curtained off room in Torm's bathhouse."
    "  This affords some privacy for those who don't feel the need to strip down in public."
  "  A few pegs and shelves are in this room, but most of peoples belongings are kept out in the main room where they can keep an eye on them."
  );
  set_exits(([
  "east":TCITY+"c115",
  ]));
  set_door("curtain",TCITY+"c115","east","Torm masterkey");
}
