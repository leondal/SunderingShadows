#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s49.c",
  "west":SEW+"s54.c",
  "south":SEW+"s62.c",
  ]));
}
