#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s10.c",
  "south":SEW+"s28.c",
  "east":SEW+"s20.c",
  ]));
}
