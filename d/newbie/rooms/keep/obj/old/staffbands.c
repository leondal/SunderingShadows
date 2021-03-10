#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("golden bands");
   set_id(({"bands","golden bands","staff-part-4"}));
   set_short("%^YELLOW%^two golden bands%^RESET%^");
   set_long("%^YELLOW%^Twin hoops of metal have been shaped from polished "
"gold.  They shine brightly when light catches upon their surface.  Each "
"seems marred upon the underside, as though they once were bound around "
"something.  They seem incomplete, as if they were only part of a whole.  "
"You could %^WHITE%^assemble%^YELLOW%^ them if you could find the other "
"pieces.%^RESET%^");
   set_weight(0);
   set_value(0);
}

void init() {
   ::init();
   add_action("assemble_fun","assemble");
}

int assemble_fun(string str) {
   if(TP != ETO) return 0;
   if(str) return notify_fail("Just <assemble> it.\n");
   if(present("staff-part-1",TP) || present("staff-part-2",TP) || present("staff-part-3",TP)) return 0;
   tell_object(TP,"%^YELLOW%^You examine the bands, but realise you have no "
"other parts to assemble them with.%^RESET%^");
   return 1;
}
