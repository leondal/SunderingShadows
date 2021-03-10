#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s29.c",
  "south":SEW+"s40.c",
  "east":SEW+"s35.c",
  "west":SEW+"s33.c",
  "ladder":TCITY+"c43.c",
  ]));
}
