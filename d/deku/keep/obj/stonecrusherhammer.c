#include <std.h>
inherit "/d/common/obj/weapon/hammer_sm.c";

void create() 
{
    ::create();
    set_id(({ "small hammer","hammer","heavy iron hammer",
    "iron hammer","stonecrusher","stonecrusher hammer"}));
    set_name("small hammer");
    set_obvious_short("A small iron hammer");
    set_short("%^BOLD%^%^WHITE%^Stonecrusher%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This small hammer is made "+
    "from a solid, heavy %^RESET%^iron%^BOLD%^%^WHITE%^ "+
    "that has several barely legible words inscribed "+
    "into the %^RESET%^%^BLUE%^handle%^BOLD%^%^WHITE%^ "+
    "of it.  The single head of this hammer is almost "+
    "completely flat and is backed "+
    "with a nearly foot long %^BOLD%^%^BLACK%^"+
    "blackened%^BOLD%^%^WHITE%^ spike.  The end "+
    "of the handle of this weapon is wrapped with a "+
    "%^RED%^soiled%^BOLD%^%^WHITE%^ cloth, "+
    "as if to provide a grip for holding the weapon.  "+
    "Several dirty handprints remain "+
    "on the cloth.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^Clan Stonecrusher of Deku helped forge these "+
    "hammers centuries before the darkness of the Shadowlord began to encroach "+
    "upon the island. The dwarves have all, but vanished, many suggesting that they "+
    "are part of the werewolves or graveyard forces. The truth isn't know, but a few "+
    "of their majestic weapons are still in circulation on the island. They seemed to be "+
    "quite effective at smashing through stone.");
    set_language("dwarvish");
    set_read("Me hammer smashes stone!");
    set_property("enchantment",3);
    set_item_bonus("damage bonus",3);
    set_item_bonus("endurance",2);
    set_value(4000);
    set_wield((:TO,"wield_me":));
    set_unwield("%^BOLD%^%^WHITE%^You release your hold on "+
    "the iron hammer.%^RESET%^");
    set_hit((:TO,"special":));
}

int special(object targ) 
{
    if(random(30) > 11) 
    {
        ETO->set_property("magic",1);
        tell_object(ETO,"%^BOLD%^%^GREEN%^You strike " +
        targ->QCN + "%^BOLD%^%^GREEN%^ with "+
        "%^RED%^tremendous%^BOLD%^%^GREEN%^ force!%^RESET%^");
	
        tell_object(targ,ETO->QCN + "%^BOLD%^%^GREEN%^ strikes you with "+
        "%^RED%^tremendous%^BOLD%^%^GREEN%^ force!%^RESET%^");
		
        tell_room(environment(ETO),ETO->QCN + "%^BOLD%^%^GREEN%^%^ "+
        "strikes " +
        targ->QCN + "%^BOLD%^%^GREEN%^ with %^RED%^"+
        "tremendous%^BOLD%^%^GREEN%^ force!%^RESET%^",({targ,ETO}));
        targ->do_damage(targ->return_target_limb(),roll_dice(1,12));
        ETO->set_property("magic",-1);
    }
    return 0;
}

int wield_me() 
{
    tell_object(ETO,"%^BOLD%^%^WHITE%^You ready the iron hammer.%^RESET%^");
    return 1;	
}
