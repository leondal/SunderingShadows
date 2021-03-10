#include <std.h>
#include "../../inherit/keep.h"
inherit OBJ2+"quest_staff";

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
   set_mypart("bands");
}
