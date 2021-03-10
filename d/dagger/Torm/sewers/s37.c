#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "east":SEW+"s38.c",
  "west":SEW+"s36.c",
  ]));
}
