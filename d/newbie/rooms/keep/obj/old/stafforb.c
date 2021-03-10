#include <std.h>
#include "../../inherit/keep.h"
inherit OBJECT;

void create() {
   ::create();
   set_name("translucent orb");
   set_id(({"orb","translucent orb","staff-part-1"}));
   set_short("%^RESET%^%^CYAN%^a translucent orb%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This orb appears to be made of translucent "
"glass.  It is perfectly smooth and spherical, although a few marks are "
"scratched upon it in strategic places, like something once held it.  It "
"seems incomplete, as if it were only part of a whole.  You could %^BOLD%^"
"%^WHITE%^assemble%^RESET%^%^CYAN%^ it if you could find the other pieces"
".%^RESET%^");
   set_weight(1);
   set_value(0);
}

void init() {
   ::init();
   add_action("assemble_fun","assemble");
}

int assemble_fun(string str) {
   object obj1, obj2, obj3;
   if(TP != ETO) return 0;
   if(str) return notify_fail("Just <assemble> it.\n");
   if(!present("staff-part-2") && !present("staff-part-3") && !present("staff-part-4")) {
     tell_object(TP,"%^YELLOW%^You examine the orb, but realise you have "
"no other parts to assemble it with.%^RESET%^");
     return 1;
   }
   obj1 = present("staff-part-2");
   obj2 = present("staff-part-3");
   obj3 = present("staff-part-4");
   if(!objectp(obj1) || !objectp(obj2) || !objectp(obj3)) {
     tell_object(TP,"%^YELLOW%^You examine the orb, but realise you do "
"not have enough other parts to assemble it with.%^RESET%^");
     return 1;
   }
   if(base_name(obj1) != OBJ2"staffdragon") {
     tell_object(TP,"%^YELLOW%^The dragon carving does not seem to fit "
"correctly with the other pieces.%^RESET%^");
     return 1;
   }
   if(base_name(obj2) != OBJ2"staffstave") {
     tell_object(TP,"%^YELLOW%^The runed stave does not seem to fit "
"correctly with the other pieces.%^RESET%^");
     return 1;
   }
   if(base_name(obj3) != OBJ2"staffbands") {
     tell_object(TP,"%^YELLOW%^The golden bands do not seem to fit "
"correctly with the other pieces.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You pause for a moment, connecting all "
"the pieces together.  The %^RESET%^%^CYAN%^orb%^BOLD%^%^WHITE%^ sits "
"perfectly within the grasp of the %^RESET%^%^RED%^carved dragon%^BOLD%^"
"%^WHITE%^, which sockets perfectly atop the %^RESET%^%^ORANGE%^runed stave"
"%^BOLD%^%^WHITE%^.  The two %^YELLOW%^golden bands %^WHITE%^bind the other "
"indentations along its length, leaving you with an impressive looking "
"staff.%^RESET%^");
   obj1->remove();
   obj2->remove();
   obj3->remove();
   TO->move("/d/shadowgate/void");
   new(OBJ2"staff")->move(TP);
   TO->remove();
   return 1;
}
