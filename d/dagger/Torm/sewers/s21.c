#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s12.c",
  "south":SEW+"s29.c",
  "west":SEW+"s20.c",
  ]));
}
