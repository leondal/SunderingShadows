#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
 "west":SEW+"s4.c",
  "east":SEW+"s6.c",
  ]));
}
