// adapted to Nilith and upgraded. N, 12/18.
#include <std.h>;
inherit "/d/common/obj/armour/greaves.c";

void create(){
    ::create();
    set_name("obsidion greaves");
    set_id(({"greaves","obsidion greaves","Greaves","armor"}));
    set_obvious_short("%^BLACK%^%^BOLD%^obsidion greaves%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Re%^RESET%^%^MAGENTA%^b%^RESET%^"+
"%^BOLD%^%^BLACK%^elli%^RESET%^%^MAGENTA%^o%^RESET%^%^BOLD%^%^BLACK%^n's "+
"%^RESET%^%^MAGENTA%^S%^RESET%^%^BOLD%^%^BLACK%^tep%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^These greaves have been formed "+
"from solid %^RESET%^%^WHITE%^obsidion%^RESET%^%^BOLD%^%^BLACK%^, harde"+
"ned through some magic until it is as hard as %^RESET%^%^WHITE%^steel"+
"%^RESET%^%^BOLD%^%^BLACK%^. The front is decorated with an inlay of "+
"%^RESET%^%^RED%^re%^RESET%^%^BOLD%^%^RED%^d%^RESET%^%^RED%^ agate "+
"%^RESET%^%^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^p%^RESET%^%^YELLOW%^"+
"y%^RESET%^%^ORANGE%^rite %^RESET%^%^BOLD%^%^BLACK%^into a design of a"+
" twisting storm. The workmanship of the design is perfect, and even "+
"though the greaves seem used, there isnt a scratch on them. They buckle"+
" with a series of %^RESET%^%^ORANGE%^leather straps %^RESET%^%^BOLD%^"+
"%^BLACK%^that tie behind the leg.\n%^RESET%^");
     set_lore("%^RESET%^%^MAGENTA%^A favorite of Templars of Nilith, the"+
" greaves named Rebellion's Step are not unique, but rather a name given"+
" to a series of greaves usually made for favored commanders of the Lady of Bones'"+
" armies. There is still a measure of power in the greaves though, for"+
" any other that dare lay claim to them.%^RESET%^.");
    set_property("lore",15);
    set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_value(3000);
}

int wear_func(){
    if((int)TP->query_lowest_level() < 20) {
        tell_object(TP,"%^RESET%^%^ORANGE%^The magic in the greaves overwhelms you and you cannot put them on.%^RESET%^");
    return 0;
    }
    tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ buckles on the greaves slowly.%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You buckle on the greaves.%^RESET%^");
    return 1;
}

int remove_func(){
        tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+" %^BLACK%^%^BOLD%^pulls off the greaves.%^RESET%^",ETO);
        tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the greaves.%^RESET%^");
        return 1;
}