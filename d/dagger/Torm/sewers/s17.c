#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/mbottom.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s16.c",
  ]));
}
