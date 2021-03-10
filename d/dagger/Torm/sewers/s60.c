#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s53.c",
  "east":SEW+"s61.c",
  "west":SEW+"s59.c",
  ]));
}
