#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("rainbow-hued cloak");
   set_short("%^RESET%^%^GREEN%^b%^BOLD%^u%^YELLOW%^t%^RED%^t%^RESET%^%^MAGENTA%^e%^BLUE%^r%^BOLD%^f%^RESET%^%^GREEN%^l%^BOLD%^y%^YELLOW%^-%^RED%^w%^RESET%^%^MAGENTA%^i%^BLUE%^n%^BOLD%^g%^WHITE%^ cloak%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^r%^BOLD%^a%^YELLOW%^i%^RED%^n%^RESET%^%^MAGENTA%^b%^BLUE%^o%^BOLD%^w%^WHITE%^-hued cloak%^RESET%^");
   set_id(({"cloak","Cloak","butterfly wing cloak","butterflywing cloak","butterfly cloak","rainbow cloak","rainbow hued cloak"}));
   set_long("%^WHITE%^%^BOLD%^This garment is dyed every colour imaginable, from the deepest "
"%^RESET%^%^BLUE%^ocean blue%^WHITE%^%^BOLD%^ to the brightest %^YELLOW%^gold%^WHITE%^ shade, and every "
"%^RESET%^%^GREEN%^v%^BOLD%^a%^YELLOW%^r%^RED%^i%^RESET%^%^MAGENTA%^e%^BLUE%^%^BOLD%^d%^WHITE%^ hue "
"inbetween.  They travel outward from the centre of the cloak in increasing circles of colour, mimicking "
"the patterning on a bright butterfly's wings.  The image is completed with the intricately-carved "
"%^YELLOW%^gold%^WHITE%^ clasp, in the shape of a butterfly's body, complete with tiny legs and "
"eyes.%^RESET%^\n");
   set_weight(3);
   set_value(1+random(3)*720);
   set_type("clothing");
   set_size(1);
   set_lore("%^WHITE%^%^BOLD%^This item once belonged to the halfling Kaali Thistlefoot, as one of many "
"items she claimed she had 'found' during her travels.  The original owner and creator are unknown, but "
"from the skill and style of crafting, the garment is presumably of elven make.%^RESET%^\n");
   set_property("lore difficulty",15);
   set_property("enchantment",2);
   set_item_bonus("magic resistance",1);
   set_limbs(({"neck"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You swirl the beautiful cloak around your shoulders.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" swirls the beautiful cloak around "+ETO->QP+
" shoulders.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You slip off the brightly-patterned cloak.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" slips off the brightly-patterned cloak.%^RESET%^",ETO);
   return 1;
}
