#include <std.h>
#include "../../inherit/keep.h"
inherit OBJ2+"quest_staff";
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
   set_mypart("stave");
}
