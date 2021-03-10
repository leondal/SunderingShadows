#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/mbottom.c";
void create(){
  ::create();
  set_exits(([
  "south":SEW+"s36.c",
  ]));
}
