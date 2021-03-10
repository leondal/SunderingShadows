#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("peryton horn");
   set_short("%^BOLD%^%^BLACK%^A black antler%^RESET%^");
   set_id(({"antler","black antler","horn"}));
   set_long(
      "This wicked, twisting antler is black as the abyss.   Its edges "+
      "are quite sharp, and it seems to be a fantastic natural weapon, "+
      "though you cannot find a way to grip it without hurting yourself. "+
      "Perhaps if someone knew the secret of working with these antlers, "+
      "a fantastic weapon could be forged."
   );
   set_lore("This is an antler taken from the dread perytons.  These "+
      "strange creatures are not of this plane, and they live only "+
      "to kill mortals.  They eat the hearts of mortals, believing it "+
      "may release them from this place, though - strangely - they "+
      "prefer not to eat the hearts of elves.  This antler can "+
      "sometimes be fashioned into a deadly weapon.");
   set_property("lore difficulty",5);
   set_weight(5);
   set_value(85);
}
