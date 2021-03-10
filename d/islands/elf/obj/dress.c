#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create(){
::create();

set_name("tattered dress");
set_id(({"tattered","tattered dress","dress"}));
set_short("%^RESET%^Tattered Dress%^RESET%^");
set_obvious_short("%^RESET%^A ruined dress.%^RESET%^");
set_long("This once was a dress of a"+
" long forgotten style.  It is torn"+
" and frayed.  Several bits of green"+
" seaweed are caught in it.   The whole "+
"dress seems go give off a dark evil aura.  %^RESET%^");

set_lore("Scholars claim that this style of"+
" dress was in use hundreds of years ago in"+
" a long forgotten empire of humans that "+
"suddenly sank into the sea because of a natural calamaty..");
set_property("lore difficulty",34);
set_value(500);
set_size(2);
set_property("enchantment",4+random(3));
set_item_bonus("spellcraft",4);
set_item_bonus("charisma",-1);
set_item_bonus("divine resistance",10);
set_wear((:TO,"wear_fun":));
set_remove((:TO,"remove_fun":));
}

int wear_fun(){
tell_object(ETO,"%^BOLD%^You wear the dress and feel like a refugee.%^RESET%^");
return 1;
}

int remove_fun(){
tell_room(EETO,"%^BOLD%^"+ETO->QCN+" removes the "+
"tattered dress and oddly it doesn't fall apart.%^RESET%^",ETO);
tell_object(ETO,"%^BOLD%^You remove the tattered dress and feel much better..%^RESET%^");
}
