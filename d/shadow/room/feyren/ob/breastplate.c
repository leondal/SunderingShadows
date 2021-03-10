#include <std.h>
inherit "/d/common/obj/armour/breastplate";

void create()
{
    ::create();
    set_name("deep red breastplate");

    set_id(({ "plate", "breastplate", "armor", 
    "armour", "deep red plate", "deep red armor", 
    "deep red breastplate", "guardian plate", 
    "guardian armor", "guardian breastplate"}));
	
    set_obvious_short("A deep red breastplate");

    set_short("%^RESET%^%^RED%^G%^BOLD%^%^WHITE%^"+
    "ua%^RESET%^%^RED%^rd%^BOLD%^%^WHITE%^ia%^RESET%^"+
    "%^RED%^n Br%^BOLD%^%^WHITE%^ea%^RESET%^%^RED%^st"+
    "pl%^BOLD%^%^WHITE%^a%^RESET%^%^RED%^t%^BOLD%^%^WHITE%^"+
    "e%^RESET%^");
	
    set_long("%^RESET%^%^RED%^This deep red breastplate is "+
    "magnificient. The entirity of it almost glows with a "+
    "dull %^BOLD%^sheen%^RESET%^%^RED%^. Inscribed into the "+
    "center of it, in much %^BOLD%^brighter%^RESET%^%^RED%^ "+
    "color, is an intricate %^BOLD%^%^CYAN%^shield%^RESET%^%^RED%^,"+
    " with an axe crossing a hammer and a sword lain "+
    "across the middle of them, inlaid on top of it. Speckles "+
    "of more vibrant hues of %^BOLD%^red%^RESET%^%^RED%^ "+
    "are visible throughout the remainder of the armor, "+
    "clashing %^BOLD%^%^YELLOW%^brilliantly %^RESET%^"+
    "%^RED%^with the darker metal.%^RESET%^");

    set_property("lore difficulty", 15);

    set_lore("This magnificent breastplate was forged "+
    "by a dedicated follower of Torm many years ago. It was "+
    "given to the once proud Feyren for his long devoted "+
    "service to Torm. It was blessed by priests and magically "+
    "imbued to offer some protection against any weapon "+
    "that might be used against Feyren in melee combat.");
         	
    set_value(3000);
    set_size(2);
    set_property("enchantment",2);
    set_item_bonus("bludgeoning resistance", 2);
    set_item_bonus("piercing resistance", 2);
    set_item_bonus("slashing resistance", 2);

    set_wear("%^BOLD%^%^RED%^You carefully fasten the "+
    "breastplate into place and feel a magical protection "+
    "surround you!%^RESET%^");
    set_remove("%^BOLD%^%^RED%^You feel the magical protection "+
    "leave you as you remove the breastplate.%^RESET%^");
}


