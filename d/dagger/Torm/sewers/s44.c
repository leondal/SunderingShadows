#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "east":SEW+"s45.c",
  "west":SEW+"s43.c",
  ]));
}
