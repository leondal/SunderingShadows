//updated by Circe 6/12/04 with new desc, lore, etc.
#include <std.h>
inherit "/d/common/obj/armour/fullplate";

string OWNER;

void init() {
    ::init();
    if(interactive(TP) && TP==ETO && !OWNER) OWNER = TPQN;
}


void create() {
    ::create();
    set_name("armor of the citadel of storms");
    set_id( ({"armor of the citadel of storms", "armor", "armour", "plate", "citadel", "storms", "citadel of storms","fullplate"}) );
    set_obvious_short("burnished steel fullplate");
    set_short("%^BLUE%^Armor of the Citadel of Storms%^RESET%^");
    set_long("%^MAGENTA%^This impressive armor is made from a burnished "+
       "%^RESET%^steel alloy %^MAGENTA%^fitted with %^BOLD%^%^BLACK%^"+
       "darker bands %^RESET%^%^MAGENTA%^across the chest, waist, "+
       "and knee and elbow joints.  These bands help provide mobility "+
       "as well as added protection to the more vulnerable parts.  "+
       "The most eye-catching piece of this armor is the breastplate "+
       "made with a %^BOLD%^%^WHITE%^shiny finish %^RESET%^%^MAGENTA%^"+
       "high up near the shoulders that fades through to deep violet "+
       "near the bottom.  A raised design of a %^BOLD%^%^WHITE%^"+
       "fanged skull %^RESET%^%^MAGENTA%^has been molded into the "+
       "center of the breastplate.%^RESET%^");
    set_lore("This is one of the original armor designs employed by "+
       "the elite warriors of the Cartahena Empire.  The subtle "+
       "variations in color reflect rank within this order.  The "+
       "larger the deep violet section, the lower ranking the "+
       "individual.  It is speculated that the leader of these "+
       "forces must wear a highly polished suit of armor, so "+
       "light as to be reflective.  The strange fanged skull "+
       "molding has long been a decoration on these warriors, but "+
       "you have not yet discovered what it might mean.");
    set_value(75000);
    set_property("enchantment",4);
    set_item_bonus("constitution",2);
    set_wear((:TO, "extra_wear":));
    set_remove("%^BOLD%^%^BLUE%^You remove the powerful armor.");
}

int extra_wear() {
    if((int)TP->query_level() < 25) {
	tell_object(ETO,"You are not ready for this armor.");
	return 0;
    }

    if( ((string)TP->query_name() != OWNER) && ((string)TP->query_name() != "Shadowy Implementor")) {
	tell_object(ETO,"%^RED%^The armor shreeks then explodes into a "+
         "million billion itty bitty pieces as a voice whispers in "+
         "your head, %^RESET%^You are not worthy!");
	TO->remove();
	return 0;
    }

    tell_object(ETO,"%^BOLD%^%^BLUE%^You slip into the powerful "+
       "Armor of the Citadel of Storms and feel very protected.");
    return 1;
}
