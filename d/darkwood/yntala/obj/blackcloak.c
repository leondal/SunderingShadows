//black cloak
// removed the 1AC - the equivalent of a +3 cloak in an area possible to do at L10. Nienne, 02/07
#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("%^BOLD%^%^BLACK%^Cloak of Midnight%^RESET%^");
    set_id(({"armor","cape","shadow cloak","cloak of midnight","Cloak of Midnight","Midnight Cloak","aura","shade","shadows","shadow","cloak","shadow cloak"}));
    set_short("%^BOLD%^%^BLACK%^Cloak of Midnight%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^A long black cloak%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This long black cloak has been made from a very heavy material, and would provide"
" excellent protection from the elements.  It has thick, slightly stiff collar rather than a hood, and would"
" hang down to about the wearers midcalf.  It is held in place by two small black strings that tie around the wearers"
" neck and are decorated at the ends with two tiny %^RESET%^s%^BOLD%^i%^RESET%^lv%^RESET%^e%^BOLD%^r"
" %^RESET%^da%^BOLD%^gg%^RESET%^er charms.  %^BOLD%^%^BLACK%^Flirting about the edges of the cape are strange"
" dark symbols.%^RESET%^");
   set_lore("%^BOLD%^%^BLACK%^You recognize this as one of the many cloaks the Yuan-ti brought through when"
" they were summoned from their plane of existance.  Little else is known about them, as they are not of this world.");
   set_weight(3);
   set_size(2);
   set_type("clothing");
   set_limbs(({"neck",}));
   set_property("enchantment",random(2)+1);
   set_value(1000);
   set_wear((:TO,"wear_it":));
}

int wear_it(string str){
    tell_object(ETO,"%^BOLD%^%^BLACK%^You wear the cloak and somehow feel a bit darker inside.%^RESET%^");
    tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" grins darkly as "+ETO->query_subjective()+" confidently wraps the cloak around "+ETO->query_possessive()+" shoulders.%^RESET%^",ETO);

return 1;
}
