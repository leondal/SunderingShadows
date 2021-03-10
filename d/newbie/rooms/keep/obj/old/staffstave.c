#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("runed stave");
   set_id(({"stave","runed stave","staff-part-3"}));
   set_short("%^RESET%^%^ORANGE%^a runed stave%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This stave has been cut from dark wood, and "
"polished to a deep shine.  Arcane symbols trace its length, etched in "
"flowing script.  Three indendations, one in the middle and one at each "
"end, seem as though they once held something more.  It seems incomplete, "
"as if it were only part of a whole.  You could %^BOLD%^%^WHITE%^assemble"
"%^RESET%^%^ORANGE%^ it if you could find the other pieces.%^RESET%^");
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
   if(present("staff-part-1",TP) || present("staff-part-2",TP)) return 0;
   if(present("staff-part-4")) {
     tell_object(TP,"%^YELLOW%^You examine the stave, but realise you do "
"not have enough other parts to assemble it with.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^YELLOW%^You examine the stave, but realise you have no "
"other parts to assemble it with.%^RESET%^");
   return 1;
}
