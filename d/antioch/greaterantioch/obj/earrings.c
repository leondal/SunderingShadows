//water_earrings.c - New object for Koenig.  Circe 11/22/03
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("dreamcatcher earring");
   set_short("%^RESET%^%^ORANGE%^A pair of decorative, %^RESET%^%^RED%^be%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^ed %^RESET%^%^ORANGE%^dream-ca%^BOLD%^%^CYAN%^t%^RESET%^%^ORANGE%^cher earrings%^RESET%^");
   set_id(({"earrings","beaded earrings","dreamcatchers"}));
   set_long("%^RESET%^%^ORANGE%^These decorative %^RESET%^%^GREEN%^dream-catcher earrings %^RESET%^%^ORANGE%^are made out of thick leather."+
            " The circular piece of hardened leather has many thin pieces of string criss-crossing across it"+
            " and has a few small %^RESET%^%^RED%^beads %^RESET%^%^ORANGE%^which are placed carefully in the middle.");
   set_lore("Worn by tribal cultures throughout the world "+
      "these items are made by simple means, through only the "+
      "use of materials that can be found in nature.%^RESET%^");
   set_property("lore difficulty",8);
   set_weight(1);
   set_type("ring");
   set_limbs(({"head"}));
   set_value(150);
   set_wear("You wear the earrings and can feel them dangle slightly.");
   set_remove("You carefully remove the decorative earrings.");
}
