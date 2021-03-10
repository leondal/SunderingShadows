#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s30.c",
  "east":SEW+"s37.c",
  "south":SEW+"s41.c",
  "west":SEW+"s35.c",
  ]));
}
