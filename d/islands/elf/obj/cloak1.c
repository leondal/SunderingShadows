#include <std.h>
inherit "/d/common/obj/clothing/cloak.c";

void create(){
::create();

set_name("cloak");
set_id(({"cloak","silvery cloak","rathai cloak"}));
set_short("%^RESET%^%^BOLD%^As%^RESET%^hta'%^BOLD%^R%^RESET%^a%^BOLD%^thai C%^RESET%^l%^BOLD%^oak%^RESET%^");
set_obvious_short("%^RESET%^%^BOLD%^a thick silvery cloak%^RESET%^");
set_long("%^RESET%^%^CYAN%^This cloak is crafted out of brilliant %^RESET%^%^BOLD%^silver dyed"+
" %^RESET%^%^CYAN%^cloth.  It has a reflective %^BOLD%^%^WHITE%^shimmer%^RESET%^%^CYAN%^ to it.  This shimmer "+
"causes it to %^WHITE%^%^BOLD%^sparkle in light%^RESET%^%^CYAN%^.  The cloak is lined with a "+
"pelt.  %^WHITE%^White fir%^CYAN%^ lines the pelt.  Whoever made this was "+
"thinking of %^WHITE%^cold%^CYAN%^ conditions.  %^RESET%^");

set_lore("The craftsmanship of this piece of clothing seems "+
"elven.  It exemplifies a style log forgotten used by the "+
"Selu'havessthyr.  It looks more of an style from the past"+
" than something contemporary elven make.");
set_property("lore difficulty",34);
set_value(500);
set_size(2);
set_property("enchantment",4);
set_item_bonus("influence",2);
set_wear((:TO,"wear_fun":));
set_remove((:TO,"remove_fun":));
}

int wear_fun(){
tell_object(ETO,"%^BOLD%^%You throw the cloak "+
"around you and feel warm and noble.%^RESET%^");
return 1;
}

int remove_fun(){
tell_room(EETO,"%^BOLD%^"+ETO->QCN+" removes the "+
"regal cloak.%^RESET%^",ETO);
tell_object(ETO,"%^BOLD%^You remove the regal cloak.%^RESET%^");
}
