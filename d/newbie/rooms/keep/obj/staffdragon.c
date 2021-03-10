#include <std.h>
#include "../../inherit/keep.h"
inherit OBJ2+"quest_staff";

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
   set_mypart("carving");
}
