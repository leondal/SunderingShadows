#include <std.h>
inherit "/d/deku/armours/cloak_inh.c";
 
create() {
  ::create();
    set_name("cloak");
    set_id(( {"cloak", "black cloak","veil","nights veil"}));
    set_short("%^BOLD%^%^BLACK%^Night's veil%^RESET%^");
    set_obvious_short("A black leather cloak");
    set_long("%^BOLD%^%^BLACK%^This cloak is pitch black.  "+
    "It flows down to the floor and has a hood that can be "+
    "pulled over the head to further conceal the wearer.  "+
    "It is made from soft, supple leather that looks like it "+
    "would probably provide some protection.  Even the clasp "+
    "is made of a %^BOLD%^%^WHITE%^dull%^BOLD%^%^BLACK%^ "+
    "black metal so as not to give the wearer away. %^RESET%^");
    
    set_lore("These cloaks were sewn and enchanted by a "+
    "rogue who was limited in the art of magic.  He made them "+
    "as a shield and block against the light that so often "+
    "proved his biggest hindrance.  The shadows around the "+
    "wearer are said to draw near to him, becoming more familiar "+
    "and even the least amount of light is darkened by the magic "+
    "in these cloak.");

    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_property("enchantment",2);
	set_item_bonus("sight bonus", -1);
    set_item_bonus("stealth",1);    
}

int wearme() {
    if(ETO->query_lowest_level() < 15) {
        write("The magic of the cloak rejects you!");
        return 0;
    }
    write("%^BOLD%^%^BLACK%^The shadows draw "+
        "closer to you.%^RESET%^");
    return 1;
}

int removeme() {
    write("%^BOLD%^%^BLACK%^The shadows step back "+
        "from your presence.%^RESET%^");
    return 1;
}
