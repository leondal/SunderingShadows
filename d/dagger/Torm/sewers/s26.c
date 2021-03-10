#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s25.c",
  "east":SEW+"s27.c",
  ]));
}
