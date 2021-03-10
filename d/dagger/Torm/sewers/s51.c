#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/mbottom.c";
void create(){
  ::create();
  set_exits(([
  "east":SEW+"s52.c",
  ]));
}
