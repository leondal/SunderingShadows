#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("ring");
   set_id(({"ring","black ring","dark ring"}));
   set_short("%^RESET%^%^BLUE%^Dark Ring%^RESET%^");
   set_obvious_short("%^RESET%^A ring set with a %^BLACK%^%^BOLD%^black stone%^RESET%^");
   set_long("This is a %^WHITE%^%^BOLD%^platinum ring%^RESET%^ with a perfect %^BLACK%^%^BOLD%^black stone "
"%^RESET%^set in its top.  The stone has glimmers of faint light dancing through it.  It gives off a cold "
"%^BOLD%^%^BLUE%^aura%^RESET%^ that chills you to the bone.");
   set_ac(0);
   set_weight(1);
   set_type("ring");
   set_value(50);
   set_limbs(({"left hand","right hand"}));
   set_lore("%^WHITE%^%^BOLD%^Rumour and legend surround this distinct ring.  It was known to once be the "
"key to a portal to the shadow realms, though the location of the portal is long lost to recorded history, "
"and probably better that way.%^RESET%^\n");
   set_property("lore difficulty",14);
}
