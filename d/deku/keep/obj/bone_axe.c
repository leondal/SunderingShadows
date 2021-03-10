#include <std.h>
inherit "/d/common/obj/weapon/battle_axe.c";
void create() 
{
    ::create();
    set_obvious_short("A bone axe");
    set_short("%^BOLD%^%^WHITE%^A Bone Axe%^RESET%^");
    set_id(({"axe","Axe","Bone Axe","bone axe","Medium Axe","medium axe",
    "A bone axe"}));
    set_name("A bone axe");
    set_long("%^BOLD%^%^WHITE%^This double bladed axe has been crafted "+
    "from a very large bone fragment.  The blades are "+
    "stained a deep %^RED%^crimson%^BOLD%^%^WHITE%^ and specks of "+
    "%^RED%^crimson%^BOLD%^%^WHITE%^ litter the handle of "+
    "the axe.  A small and perfectly "+
    "rounded %^RED%^ruby%^BOLD%^%^WHITE%^ has been set "+
    "into the end of the axe, its purpose, "+
    "if there is one, is unknown.  The coloration of it "+
    "is quite fitting though as the stains "+
    "on the weapon are an equal shade of red, "+
    "obviously the porous nature of the bone has "+
    "retained evidence of the activities the axe has engaged in.%^RESET%^");	
    set_property("enchantment",3);
    set_value(1000);
    set_wield((:TO,"wield_axe":));
    set_unwield("%^BOLD%^%^WHITE%^You release your "+
    "tight grip on your bone axe.%^RESET%^");
    set_hit((:TO,"special":));			
}

int wield_axe() 
{
    if((int)ETO->query_lowest_level() < 15) 
    { 
        write("%^BOLD%^%^WHITE%^You can't figure out how "+
        "to properly use the axe!%^RESET%^%^RED%^");
        return 0;
    }
    write("%^BOLD%^%^WHITE%^You ready your bone axe.%^RESET%^");
    return 1;
}

int special(object targ) 
{
    int chance;
    chance = random(1000);
    if(chance > 700 && chance < 950) 
    {			
        tell_object(ETO,"%^RED%^You sink your axe into "
        + targ->query_cap_name() + "!%^RESET%^");

        tell_object(targ,ETO->query_cap_name() + "%^RED%^ sinks " +
        ETO->query_possessive() + "%^RED%^ axe into your flesh!%^RESET%^");

        tell_room(environment(ETO),ETO->query_cap_name() + 
        "%^RED%^ sinks " + ETO->query_possessive() + 
        "%^RED%^ axe into " + targ->query_cap_name() + 
        "%^RED%^'s flesh!%^RESET%^",({targ,ETO}));
        return roll_dice(2,6);
    }
    return 0;
}



