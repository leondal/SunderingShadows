#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s6.c",
  "east":SEW+"s8.c",
  "south":SEW+"s16.c",
  ]));
}
