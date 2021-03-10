#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s45.c",
  "west":SEW+"s51.c",
  "south":SEW+"s58.c",
  ]));
}
