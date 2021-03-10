#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "east":SEW+"s49.c",
  "west":SEW+"s47.c",
  ]));
}
