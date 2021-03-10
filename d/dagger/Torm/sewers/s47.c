#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s41.c",
  "east":SEW+"s48.c",
  "west":SEW+"s46.c",
  "south":SEW+"s53.c",
  ]));
}
