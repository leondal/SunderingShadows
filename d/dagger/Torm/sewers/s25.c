#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s16.c",
  "east":SEW+"s26.c",
  "south":SEW+"s31.c",
  ]));
}
