#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s9.c",
  "south":SEW+"s27.c",
  ]));
}
