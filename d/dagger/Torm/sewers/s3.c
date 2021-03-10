#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s2.c",
  "east":SEW+"s4.c",
  "south":SEW+"s12.c",
  ]));
}
