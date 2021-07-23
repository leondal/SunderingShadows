#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("leather jerkin");
   set_id(({"jerkin","leather","leather jerkin","mottled jerkin","mottled leather jerkin"}));
   set_short("%^RESET%^%^ORANGE%^a mo%^BOLD%^%^BLACK%^tt%^RESET%^%^ORANGE%^led leather jerkin%^RESET%^");
   set_long("%^RESET%^Finely tanned leather forms this %^CYAN%^comfortable %^RESET%^jerkin, likely cut to fit a male "
"figure.  With open sleeves and wide shoulders, the v-neck of the garment comes down to fasten with several clasps down "
"the front, all of %^BOLD%^%^BLACK%^dulled metal %^RESET%^so as not to distract the eye with reflected light.  The "
"leather itself has been dyed a %^ORANGE%^soft brown%^RESET%^, mottled in places to %^BOLD%^%^BLACK%^darker %^RESET%^and "
"%^RED%^russet %^RESET%^shades like the play of %^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^f %^RESET%^shadows upon a forest "
"floor.  It would be long enough on a moderately sized man to come down to the mid-thigh, allowing a belt to be cinched "
"around the middle to hold the jerkin more securely in place.  Accompanying the jerkin is a %^ORANGE%^dun brown undershirt"
"%^RESET%^, of long sleeves and loose fit to allow plenty of freedom in movement.  Cords pull it tight at each wrist to "
"prevent the sleeves interfering with the wearer's hands.  The two pieces together form a rather nondescript, but "
"definitely serviceable garment for travel or work.\n");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_ac(0);
   set_size(-1);
   set_weight(5);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
   set_overallStatus(220);
   set_property("no disenchant",1);
}