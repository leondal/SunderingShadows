#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s52.c",
  "east":SEW+"s59.c",
  "west":SEW+"s57.c",
  ]));
}
