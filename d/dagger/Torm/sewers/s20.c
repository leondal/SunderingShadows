#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s19.c",
  "east":SEW+"s21.c",
  ]));
}
