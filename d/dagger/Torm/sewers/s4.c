#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "west":SEW+"s3.c",
  "east":SEW+"s5.c",
  ]));
}
