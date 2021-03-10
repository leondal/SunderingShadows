#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "east":SEW+"s55.c",
  "south":SEW+"s61.c",
  ]));
}
