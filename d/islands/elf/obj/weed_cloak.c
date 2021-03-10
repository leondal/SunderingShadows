#include <std.h>
inherit "/d/common/obj/clothing/cloak.c";

void create(){
::create();

set_name("cloak");
set_id(({"cloak","seaweed cloak","weed"}));
set_short("Seaweed Cloak");
set_obvious_short("%^RESET%^%^GREEN%^Seaweed covered cloak");
set_long("This cloak looks like it washed up "+
"from a shipwreck.  Most of the cloth is destroyed. "+
"  Bits of rope and kept are somehow stuck together"+
" in the rags.  Are there barnicles growing in there too?");

set_lore("This looks like some long forgotten "+
"clothing style.  It likely was made hundreds "+
"of years ago and is a wonder that it hasn't"+
" completely turned to dust.   Some magic seems "+
"to keep this as a wearable object.");
set_property("lore difficulty",34);
set_value(500);
set_size(2);
set_property("enchantment",4+random(2));
set_item_bonus("stealth",2);
set_item_bonus("cold resistance",-5);
set_item_bonus("fire resistance",5);
set_item_bonus("charisma",-1);
set_wear((:TO,"wear_fun":));
set_remove((:TO,"remove_fun":));
}

int wear_fun(){
tell_object(ETO,"%^CYAN%^%You throw the cloak "+
"around you and feel cold and wet.%^RESET%^");
return 1;
}

int remove_fun(){
tell_room(EETO,"%^CYAN%^"+ETO->QCN+" removes the "+
"looks glad to be out of the %^GREEN%^seaweed cloak.%^RESET%^",ETO);
tell_object(ETO,"%^CYAN%^You remove the seaweed cloak and feel less cold.%^RESET%^");
}