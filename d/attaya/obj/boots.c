//updated by Circe 6/13/04 to current code, new desc, etc.
#include <std.h>;

inherit ARMOUR;

void create(){
    ::create();
    set_name("satokai");
    set_id(({"satokai","boots","boot","steel tip","satokai boots"}));
    set_obvious_short("%^RESET%^%^CYAN%^steel plated boots%^RESET%^");
    set_short("%^RESET%^%^CYAN%^S%^RESET%^a%^CYAN%^t%^RESET%^o"+
       "%^CYAN%^k%^RESET%^a%^CYAN%^i Boots%^RESET%^");
    set_long("%^BLUE%^These highly protective boots are made of %^CYAN%^steel plates "+
       "%^BLUE%^reticulated to provide ease of movement.  The plates begin "+
       "midway up the calf and end in a %^RED%^vicious-looking%^BLUE%^ tapered point "+
       "in front of the toes.  The soles of the boots are made of "+
       "thick cured %^ORANGE%^leather%^BLUE%^, and it looks as though these boots would "+
       "provide ample protection, so long as one does not mind "+
       "sacrificing stealth.%^RESET%^");
    set_lore("The steel-plated satokai boots were made on the "+
       "island of Attaya by the first of the tribal bands to "+
       "advance beyond simple arms and armor.  They are a sign "+
       "of progress - a sign that is not always positive.  As "+
       "such, many of the tribes rebelled against such things, "+
       "and it is true that this type of progress probably "+
       "heralded the end for the tribes' way of life.");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(10);
    set_property("enchantment",5);
   set_item_bonus("constitution",2);
   set_value(2500);
}
