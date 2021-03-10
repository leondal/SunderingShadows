#include <std.h>
inherit "/d/common/obj/lrweapon/longbow.c";

void create() {
    ::create();
   set_id(({"bow","longbow","hunters bow"}));
   set_name("%^RESET%^%^ORANGE%^The hunters bow%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A sturdy longbow");
   set_short("%^RESET%^%^ORANGE%^The hunters bow%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a very well-made made, sturdy longbow.  Carved from the finest of"
" materials, its gently curving shaft has been etched with intricate designs in strange,"
" criss-cross patterns whose purpose are hard to decipher.  Two %^RED%^f%^BOLD%^e%^YELLOW%^a%^RED%^t%^RESET%^%^RED%^"
"h%^ORANGE%^e%^BOLD%^%^RED%^r%^YELLOW%^s%^RESET%^%^ORANGE%^, one %^RED%^red, %^ORANGE%^and one %^YELLOW%^yellow,"
" %^RESET%^%^ORANGE%^have been strung to the tip of the bow, offering a bit of rich decoration. %^RESET%^");
   set_lore("%^RESET%^%^ORANGE%^It is said that the inhabitants of the Barionessa Forest were a people"
" that thrived not only on art, beauty, magic, and culture, but also by hunting the surrounding forests in"
" the rough terrain of the upper reaches of the Barrionessa mountain range.  This bow is probably one of those"
" that were used on such expeditions.");
   set("value",1000);
   set_cointype("gold");
   set_property("enchantment",3);  
   set_wield((:this_object(),"wield_func":));
}
int wield_func(){
   tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" raises the bow and takes aim.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^ORANGE%^A sense of confidence eases over you as you raise the bow and take aim.%^RESET%^");
   return 1;
}
