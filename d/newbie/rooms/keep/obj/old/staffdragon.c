#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("dragon carving");
   set_id(({"carving","dragon carving","dragon","staff-part-2"}));
   set_short("%^RESET%^%^RED%^a dragon carving%^RESET%^");
   set_long("%^RESET%^%^RED%^A coiling reptilian form has been shaped from "
"dark wood.  Wings flare to either side as its claws and tail curl forward, "
"as though it were trying to clutch something that was no longer present.  "
"A socket lies upon its underside.  It seems incomplete, as if it were only "
"part of a whole.  You could %^BOLD%^%^WHITE%^assemble%^RESET%^%^RED%^ it "
"if you could find the other pieces.%^RESET%^");
   set_weight(1);
   set_value(0);
}

void init() {
   ::init();
   add_action("assemble_fun","assemble");
}

int assemble_fun(string str) {
   if(TP != ETO) return 0;
   if(str) return notify_fail("Just <assemble> it.\n");
   if(present("staff-part-1",TP)) return 0;
   if(present("staff-part-3") || present("staff-part-4")) {
     tell_object(TP,"%^YELLOW%^You examine the carving, but realise you do "
"not have enough other parts to assemble it with.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^YELLOW%^You examine the carving, but realise you have "
"no other parts to assemble it with.%^RESET%^");
   return 1;
}
