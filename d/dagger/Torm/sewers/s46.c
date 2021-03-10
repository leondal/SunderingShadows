#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s45.c",
  "east":SEW+"s47.c",
  ]));
}
