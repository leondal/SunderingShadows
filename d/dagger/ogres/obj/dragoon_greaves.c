// upgraded. N, 12/18.
#include <std.h>
inherit "/d/common/obj/armour/greaves.c";

void create(){
    ::create();
    set_name("steel greaves");
    set_id(({"greaves","steel greaves","Greaves","armor"}));
    set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^ste%^RESET%^%^WHITE%^"+
"e%^RESET%^%^BOLD%^%^BLACK%^l gre%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^"+
"%^BLACK%^ves%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Ho%^RESET%^%^WHITE%^n%^RESET%^"+
"%^BOLD%^%^BLACK%^or's Stri%^RESET%^%^WHITE%^d%^RESET%^%^BOLD%^"+
"%^BLACK%^e%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^These greaves "+
	"have been formed from a perfect forging of "+
    "%^RESET%^%^WHITE%^steel%^RESET%^%^BOLD%^%^BLACK%^. "+
	"The front is decorated with an inlay of %^RESET%^"+
	"%^BOLD%^%^WHITE%^ivory %^RESET%^%^BOLD%^%^BLACK%^in "+
	" the design of a dragon's head in profile. The "+
	"workmanship of the design is perfect, and even "+
	"though the greaves have more %^RESET%^%^WHITE%^gashes"+
	" %^RESET%^%^BOLD%^%^BLACK%^and %^RESET%^%^RED%^nicks"+
	" %^RESET%^%^BOLD%^%^BLACK%^in them, they still "+
    "would provide protection.");
     set_lore("%^RED%^The Dragoons, legendary in their skills at war, pride
themselves in the quality of equipment, provide only the best to those in
the field. These greaves are part of the set given to officers.%^RESET%^");
    set_property("lore",15);
    set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_value(3000);
}

int wear_func(){
    if((int)ETO->query_lowest_level() < 20) {
        tell_object(ETO,"You are far too inexperienced to wear these greaves!");
    return 0;
    }
    if(!ETO->is_class("cavalier") && !ETO->is_class("paladin") && !ETO->is_class("fighter") && !ETO->is_class("cleric") && !ETO->is_class("antipaladin")) {
        tell_object(ETO,"You lack the required training to wear these greaves.");
    return 0;
   }
    tell_room(environment(ETO),"%^CYAN%^%^BOLD%^"+ETOQCN+"%^CYAN%^%^BOLD%^ buckles on the greaves slowly.%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You buckle on the greaves.%^RESET%^");
    return 1;
}

int remove_func(){
        tell_room(environment(ETO),"%^CYAN%^%^BOLD%^"+ETOQCN+" %^CYAN%^%^BOLD%^pulls off the greaves.%^RESET%^",ETO);
        tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the greaves.%^RESET%^");
        return 1;
}
