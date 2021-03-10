#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s19.c",
  "south":SEW+"s32.c",
  ]));
}
