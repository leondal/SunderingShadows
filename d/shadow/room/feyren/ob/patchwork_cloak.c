#include <std.h>
inherit ARMOUR;

void create()
{
    ::create();
    set_name("patchwork cloak");
    set_id(({ "cloak", "patchwork cloak"}));
	
    set_short("%^BOLD%^%^MAGENTA%^Patchwork cloak of lesser resistance%^RESET%^");	

    set_obvious_short("%^RESET%^%^MAGENTA%^A patchwork cloak%^RESET%^");

    set_long("%^MAGENTA%^This garment has been tailored from "+
    "at least a dozen different fabrics. There are some "+
    "%^RESET%^%^BLUE%^deep blues%^RESET%^%^MAGENTA%^, "+
    "%^BOLD%^%^YELLOW%^brilliant yellows%^RESET%^%^MAGENTA%^ "+
    "%^BOLD%^%^RED%^shiny reds%^RESET%^%^MAGENTA%^, "+
    "%^BOLD%^%^BLACK%^dull blacks%^RESET%^%^MAGENTA%^, and even "+
    "%^BOLD%^%^WHITE%^pale whites%^RESET%^%^MAGENTA%^ with "+
    "many smaller patches of other colors. "+
    "The seams that hold the patches together have been "+
    "sewn using a thick %^BOLD%^%^GREEN%^emerald green%^RESET%^"+
    "%^MAGENTA%^ that manages to clash, almost violently, "+
    "with the material of the cloak. However, the seams "+
    "give off a very faint %^CYAN%^glow%^RESET%^%^MAGENTA%^"+
    " which bathes the rest of the cloak in an "+
    "%^BOLD%^%^GREEN%^emerald%^RESET%^%^MAGENTA%^ light. "+
    "What looks to be a simple %^BOLD%^%^BLUE%^treasure "+
    "chest%^RESET%^%^MAGENTA%^ has been embroidered "+
    "into the bottom front edge of the garment. A "+
    "%^RESET%^%^RED%^dull red%^RESET%^%^MAGENTA%^ "+
    "has been added to the cloak.%^RESET%^");

    
    set_weight(5);
    set_value(1000);
	
    set_lore("The original tailor of this cloak has "+
    "long been forgotten. What is known suggests that "+
    "its power lie in the thread from which the seams "+
    "are sewn. The thread manages to offer the wearer "+
    "some protection from magic. The fabric involved "+
    "with the cloak is "+
    "quite mundane and aside from somehow repealing "+
    "most dirt and keeping fleas at bay has "+
    "no extraordinary properties.");

    set_property("lore difficulty",15);

    set_type("clothing");
    set_limbs(({ "neck" }));
    set_size(2);
    set_property("enchantment",2);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_item_bonus("magic resistance", 1);
}

int wear_func() 
{
    tell_object(ETO, "%^BOLD%^%^MAGENTA%^You fasten the "+
    "dull red clasp and feel a %^CYAN%^faint"+
    "%^BOLD%^%^MAGENTA%^ aura of protection envelope "+
    "you.%^RESET%^");    
    return 1;
}

int remove_func() 
{
    tell_object(ETO,"%^BOLD%^%^MAGENTA%^You unfasten the "+
    "dull red clasp and feel the %^CYAN%^faint"+
    "%^BOLD%^%^MAGENTA%^ aura leave you.%^RESET%^");
    return 1;
}
