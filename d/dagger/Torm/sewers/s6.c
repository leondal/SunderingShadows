#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
 "west":SEW+"s5.c",
  "east":SEW+"s7.c",
  ]));
}
