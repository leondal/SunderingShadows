#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
  ::create();
  set_exits(([
  "north":SEW+"s31.c",
  "south":SEW+"s42.c",
  "west":SEW+"s37.c",
  "ladder":TCITY+"c47.c",
  ]));
}
