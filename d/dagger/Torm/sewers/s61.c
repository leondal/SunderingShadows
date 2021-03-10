#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s54.c",
  "east":SEW+"s62.c",
  "west":SEW+"s60.c",
  ]));
}
