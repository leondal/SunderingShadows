#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("peryton talon");
   set_short("%^BOLD%^%^RED%^A bloody %^WHITE%^talon%^RESET%^");
   set_id(({"talon","claw","bloody talon"}));
   set_long(
      "%^BOLD%^%^WHITE%^This bone white talon is about three inches "+
      "long and dangerously sharp.  It curves to a point, and it is "+
      "covered in vivid %^RED%^red blood%^WHITE%^.  Taken from the "+
      "demonic peryton, it might perhaps serve some unknown purpose "+
      "if only you knew how to use it."
   );
   set_lore("This is a talon taken from the dread perytons.  These "+
      "strange creatures are not of this plane, and they live only "+
      "to kill mortals.  They eat the hearts of mortals, believing it "+
      "may release them from this place, though - strangely - they "+
      "prefer not to eat the hearts of elves.  This talon can "+
      "sometimes be fashioned into a protective device.");
   set_property("lore difficulty",5);
   set_weight(5);
   set_value(85);
}
