#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("peryton heart");
   set_short("%^BOLD%^%^RED%^A heart%^RESET%^");
   set_id(({"heart","a heart","Heart","peryton heart"}));
   set_long(
      "%^BOLD%^%^RED%^A heart, still dripping with blood.  It "+
      "seems to be about the size of an adult human fist, and "+
      "appears to be preserved somehow.  It might decay over time, "+
      "but you are not quite sure.  Perhaps you should ask the "+
      "advice of someone who might know from which beast this came."
   );
   set_lore("This is a heart taken from the dread perytons.  These "+
      "strange creatures are not of this plane, and they live only "+
      "to kill mortals.  They eat the hearts of mortals, believing it "+
      "may release them from this place, though - strangely - they "+
      "prefer not to eat the hearts of elves.  This heart is said "+
      "to contain the essence of the beast, if someone can be "+
      "found who knows how to harness it.");
   set_property("lore difficulty",7);
   set_weight(8);
   set_value(0);
}
