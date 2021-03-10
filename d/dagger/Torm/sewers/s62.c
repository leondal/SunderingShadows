#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s55.c",
  "west":SEW+"s61.c",
  ]));
}
