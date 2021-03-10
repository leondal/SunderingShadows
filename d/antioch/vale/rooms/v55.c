#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(::query_long()+"%^GREEN%^To the southwest you see one of the "+
   "%^ORANGE%^huts%^GREEN%^ that are scattered about the vale,"+
   " there appears to be an entrance into it just south of here.\n"
   );
   set("night long",query("night long")+"%^BLUE%^To the southwest you see one of the "+
   "%^ORANGE%^huts%^BLUE%^ that are scattered about the vale,"+
   " there appears to be an entrance into it just south of here.\n"
   );
   set_exits(([
   "west" : ROOMS+"v56",
   "east" : ROOMS+"v54",
   "northwest" : FPATH+"f45",
   "south" : ROOMS+"c44",
   ]));
}
