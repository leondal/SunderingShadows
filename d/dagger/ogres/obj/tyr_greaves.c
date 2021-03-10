// adapted to Kreysneothosies and upgraded. N, 12/18.
#include <std.h>;
inherit "/d/common/obj/armour/greaves";

void create(){
    ::create();
    set_name("silver greaves");
    set_id(({"greaves","silver greaves","Greaves","armor"}));
    set_obvious_short("%^RESET%^%^BOLD%^silver greaves%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^WHITE%^J%^RESET%^%^WHITE%^u%^RESET%^"+
"%^BOLD%^%^WHITE%^stice's Stri%^RESET%^%^WHITE%^d%^RESET%^%^BOLD%^"+
"%^WHITE%^e%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^WHITE%^These greaves have been formed "+
"from a %^RESET%^%^WHITE%^silver alloy %^RESET%^%^BOLD%^%^WHITE%^treated "+
"and fired until solid and hard as steel. The front is decorated with an "+
"inlay of %^RESET%^%^CYAN%^b%^RESET%^%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^ue "+
"sa%^RESET%^%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^phir%^RESET%^%^BOLD%^%^BLUE%^"+
"e%^RESET%^%^CYAN%^s %^RESET%^%^BOLD%^%^WHITE%^shaping a dragon in flight. The "+
"workmanship of the design is perfect, and even though the greaves seem used, "+
"there isnt a scratch on them. They buckle with a series of %^RESET%^%^ORANGE%^"+
"leather straps %^RESET%^%^BOLD%^%^WHITE%^that tie behind the leg.%^RESET%^");
     set_lore("%^CYAN%^In the south, when a templar of Kreysneothosies takes his "+
"final oaths, he or she is presented with a set of greaves blessed by the Winged "+
"Fury. Losing their greaves would mean a very long explanation and an even"+
" longer journey to earn them again.%^RESET%^");
    set_property("lore",15);
    set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_value(3000);
}

int wear_func(){
    if((int)TP->query_lowest_level() < 20) {
        tell_object(TP,"%^RESET%^%^ORANGE%^The magic in the greaves overwhelms "+
		"you and you cannot put them on%^RESET%^");
    return 0;
    }
    tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+"%^CYAN%^%^BOLD%^ buckles"+
	" on the greaves slowly.%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You buckle on the greaves.%^RESET%^");
    return 1;
}

int remove_func(){
        tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" %^CYAN%^%^BOLD%^pulls"+
		" off the greaves.%^RESET%^",ETO);
        tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the greaves.%^RESET%^");
        return 1;
}