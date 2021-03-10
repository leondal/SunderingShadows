#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("leather headbad");
   set_short("%^RESET%^%^ORANGE%^A %^RESET%^%^RED%^fea%^BOLD%^%^BLACK%^th%^RESET%^%^RED%^ered %^RESET%^%^ORANGE%^headband%^RESET%^");
   set_id(({"headband","feathered headband"}));
   set_long("%^RESET%^%^ORANGE%^This decorative headband is made out of thick leather. A %^RESET%^%^RED%^red feather"+
            " %^RESET%^%^ORANGE%^hangs by a piece of leather to the side. %^BOLD%^%^BLUE%^Be%^BOLD%^%^CYAN%^a%^BOLD%^%^YELLOW%^ds"+
            " %^RESET%^%^ORANGE%^adorn the headband, giving it a very tribal appearance.%^RESET%^");
   set_lore("Worn by tribal cultures throughout the world "+
      "these items are made by simple means, through only the "+
      "use of materials that can be found in nature.");
   set_property("lore difficulty",8);
   set_weight(1);
   set_type("ring");
   set_limbs(({"head"}));
   set_value(150);
   set_wear("You wear the headband and can feel the %^RESET%^%^RED%^feather %^RESET%^hanging to the side of your face.");
   set_remove("You carefully remove the decorative headband.");
}
