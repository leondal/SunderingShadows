// Chernobog (11/11/20)
// Thief Gloves - reward for Thief Tutorial

#include <std.h>
inherit "/d/common/obj/clothing/gloves";

void create(){
    ::create();
    set_name("thief gloves");
    set_id(({"gloves","thief gloves","leather gloves"}));
    set_short("%^RESET%^%^CYAN%^a pair of %^BOLD%^%^BLACK%^leat%^RESET%^h%^BOLD%^%^BLACK%^er glo%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
    set_long("%^CYAN%^These sleek %^ORANGE%^leather %^BOLD%^%^BLACK%^gloves %^RESET%^"+
        "%^CYAN%^are dyed a %^BOLD%^%^BLACK%^de%^RESET%^e%^BOLD%^%^BLACK%^p bla%^RESET%^"+
        "c%^BOLD%^%^BLACK%^k%^RESET%^%^CYAN%^. They are supple to the touch, and feel "+
        "like a second skin when worn.%^WHITE%^");
    set_weight(4);
    set_value(250);
    set_type("clothing");
    set_limbs(({"left arm","right arm"}));
    set_ac(0);
    set_item_bonus("thievery",1);
    set_item_bonus("dungeoneering",1);
    set_wear("%^BOLD%^%^BLACK%^Your fingers feel a bit more nimble as you slip on the "+
        "supple leather gloves.%^RESET%^");
    set_remove("%^BOLD%^%^BLACK%^Your hands are stiff and sore for a moment when you "+
        "remove the gloves.%^RESET%^");
}

