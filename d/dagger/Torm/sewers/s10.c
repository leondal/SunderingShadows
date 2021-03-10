#include "../tormdefs.h"
inherit "/d/dagger/Torm/sewers/sewer.c";
void create(){
    ::create();
    set_exits(([
	"north":SEW+"s1.c",
	"south":SEW+"s19.c",
      ]));
}
