#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s40.c",
  "east":SEW+"s46.c",
  "south":SEW+"s52.c",
  "west":SEW+"s44.c",
  ]));
}
