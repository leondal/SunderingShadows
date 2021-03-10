#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
    ::create();
    set_exits(([
	"north":SEW+"s28.c",
	"south":SEW+"s39.c",
	"east":SEW+"s33.c",
      ]));
#include "../tormdefs.h"
}
