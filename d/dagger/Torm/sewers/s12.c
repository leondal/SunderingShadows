#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s3.c",
  "south":SEW+"s21.c",
  "west":SEW+"s11.c",
  ]));
}
