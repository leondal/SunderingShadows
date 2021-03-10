#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s42.c",
  "west":SEW+"s48.c",
  "south":SEW+"s55.c",
  ]));
}
