#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s39.c",
  "south":SEW+"s50.c",
  "east":SEW+"s44.c",
  ]));
}
