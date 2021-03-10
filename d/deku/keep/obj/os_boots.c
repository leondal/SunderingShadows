// updated str bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;
int flag, effect;

void create()
{
    ::create();
    set_name("Ogre-Skinned Boots");
    set_id(({ "boots", "boot", "ogre-skin boots", "ogre-skin boot", 
    "Ogre-Skin Boots", "Ogre-Skin boot", "ogre skin boots", 
    "Ogre Skin Boots", "ogre skin boot", "Ogre Skin Boot" }));
    set_short("%^RED%^Ogre skin boots%^RESET%^");
    set_obvious_short("%^YELLOW%^Wart covered leather boots%^RESET%^");
    set_long("These boots are made from the %^YELLOW%^dried, "+
    "stretched hide%^RESET%^ of some "+
    "type of creature, possibly an ogre.  Their outside "+
    "is covered in leathery %^YELLOW%^warts"+
    "%^RESET%^ and their inside is padded with a thick, "+
    "coarse %^MAGENTA%^hair%^RESET%^.  They "+
    "extend to slightly above the shins of the wearer "+
    "and because of their thickness provide an "+
    "amazing amount of protection.  The soles of the "+
    "boots are made from a much thicker piece of "+
    "%^YELLOW%^hide%^RESET%^ that has been stripped of its %^YELLOW%^warts%^RESET%^.");
    set_lore("Not much is known about these boots, except that they are crafted of Ogre Skin."+
    "One thing is for certain, whomever had these crafted is quite a sick individual or"+
    "someone with a great hatred for Ogres and doesn't mind wearing them everyday.");
    set_weight(2);
    set_value(100);
    set_type("clothing");
    set_limbs(({ "left foot", "right foot" }));
    set_size(-1);
    set_property("enchantment",3);
    set_item_bonus("strength", 2);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    effect = random(2);
}

int wear_func()
{
    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+" timidly wears the wart "+
        "covered boots%^YELLOW%^!%^RESET%^",ETO);
    }
    tell_object(ETO,"%^YELLOW%^You wear the wart covered boots and feel yourself strangely "+
    "empowered.%^RESET%^");
    return 1;
}

int remove_func()
{
    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+" decides to "+
        "remove the wart covered boots%^YELLOW%^!%^RESET%^",ETO);
    }
    tell_object(ETO,"%^YELLOW%^You decide to remove the "+
    "wart covered boots and feel yourself "+
    "return to normal.%^RESET%^");
    return 1;
}

int isMagic()
{
    int y;
    y = ::isMagic();
    y = y + 1;
    return y;
}
	
