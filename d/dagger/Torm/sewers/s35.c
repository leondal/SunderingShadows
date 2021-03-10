#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "east":SEW+"s36.c",
  "west":SEW+"s34.c",
  ]));
}
