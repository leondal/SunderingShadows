#include <std.h>
inherit "/d/common/obj/armour/pcleatherbarding";

void create() {
   ::create();
   set_name("leather flanchards");
   set_id(({"flanchards","leather flanchards","barrier","plainstrider barrier"}));
   set_obvious_short("%^RESET%^%^ORANGE%^leather flanchards%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Plainstrider's Barrier%^RESET%^");
   set_long("%^ORANGE%^Likely designed as a defensive measure for a combat mount, "
"this armor is formed of overlapping plates of cuirboilli armor.  Each leather "
"piece has been boiled and moulded into shape, to create a barrier across both flanks "
"of a quadruped steed.  Harder than standard leather, the cuirboilli armor would serve "
"well to deflect arrows and lesser blades.  Straps serve to hold the plates balanced "
"across the creature's back, where a saddle could easily be placed and secured for a "
"rider.%^RESET%^\n");
   set_lore("This kind of armor is commonly worn by trained war-steeds, and produced "
"specifically for defense from lesser blows.  It is often preferred over metal armor "
"for its lighter weight while maintaining a solid defense, though knights still tend "
"to defer to metalworked versions.  Lighter and faster, such armor is more common among "
"the Tsarven kingdoms such as Morinnen and Lirremar, where mobility is often a necessity "
"against swift or ranged aggressors upon the plains.");
   set_property("lore difficulty",10);
   set_value(150);
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
   set_overallStatus(220);
   set_property("no disenchant",1);
}
