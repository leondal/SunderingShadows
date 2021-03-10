#include <std.h>
#include "../spriggan.h"
inherit OBJECT;

void create(){
   ::create();
   "/d/islands/spriggans/obj/m_seashell.c"->create_shell(TO);
}
