//~Circe~ 10/27/07
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^WHITE%^white","%^BOLD%^%^MAGENTA%^pale pink","%^BOLD%^%^CYAN%^sky blue","%^RESET%^%^ORANGE%^tan","%^CYAN%^s%^GREEN%^e%^CYAN%^a%^GREEN%^-%^CYAN%^g%^GREEN%^r%^CYAN%^e%^GREEN%^e%^CYAN%^n","%^YELLOW%^pale yellow","%^BOLD%^%^BLACK%^dusky gray"})

void create(){
   string COLOR;
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   set_name("cowry shell necklace");
   set_id(({"necklace","cowry necklace","shell necklace","cowry shell necklace"}));
   set_short("a "+COLOR+" cowry shell necklace%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Woven of hemp, this necklace joins "+
      ""+COLOR+" cowry shells %^RESET%^%^ORANGE%^end-to-end to "+
      "form a choker that lies close to the neck.  The "+COLOR+" "+
      "shells %^RESET%^%^ORANGE%^are measured to go most of the way "+
      "around the neck, leaving tails of hemp with which to tie the "+
      "necklace on.%^RESET%^");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(45+random(11));
}