#include <std.h>

inherit "/d/common/obj/clothing/shoes.c";


void create()
{
    ::create();
    set_name("%^RESET%^%^GREEN%^Forest boots%^RESET%^");
    
    set_id(({ "boots", "suede boots" }));
    
    set_short("%^RESET%^%^GREEN%^Woodsman's boots%^RESET%^");
    
    set_obvious_short("%^RESET%^%^GREEN%^Forest green suede boots%^RESET%^");
    
    set_long("%^RESET%^%^GREEN%^These supple suede boots are dyed a deep shade"
        " of %^BOLD%^fo%^RESET%^%^GREEN%^re%^BOLD%^st g%^RESET%^%^GREEN%^ree%^BOLD%^n%^RESET%^%^GREEN%^.  The tops have been folded"
        " over to create a four inch rim, and thick %^ORANGE%^leather laces %^GREEN%^run up the back of the boots so they may be tightly secured around the"
        " wearers lower calf for optimal fit.  A layer of %^ORANGE%^hardened leather %^GREEN%^has been sewn into the soles of the boots to protect the wearers feet, but"
        " remain pliable enough for those that need quick, quiet movement.%^RESET%^");
    
    set_lore("The footwear of the famed glory hunters are rumored to be amongst some of the best designed in the realms."
        " This is not only because of their superb craftsmanship and finest materials, but also because much care has been taken to embue them with "
        "magical qualities from master enchanters.  These particular boots especially have been rumored to be extraordinarily easy to move in, but were thought to have"
        " disappeared along with the disappearance of the hunters.\n");        

    set_value(124500);

    set_size(-1);
    
    set_property("no curse",1);
    set_property("enchantment",7);
    
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));

    set_item_bonus("survival",6);
    set_item_bonus("dexterity",6);
    set_item_bonus("constitution",6);
    
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wearme()
{
    tell_object(ETO,"%^RESET%^%^GREEN%^You slip on the comfortable boots and wonder why you've not had these before.%^RESET%^");
    return 1;
}

int removeme()
{
    tell_object(ETO,"%^RESET%^%^GREEN%^You remove the comfortable boots.%^RESET%^");
    return 1;
}


