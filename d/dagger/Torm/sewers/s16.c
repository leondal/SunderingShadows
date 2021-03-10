#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
    ::create();
    set_exits(([
	"north":SEW+"s7.c",
	"south":SEW+"s25.c",
	"east":SEW+"s17.c",
      ]));
#include "../tormdefs.h"
}
