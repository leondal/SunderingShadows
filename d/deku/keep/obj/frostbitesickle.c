#include <std.h>
inherit "/d/common/obj/weapon/sickle.c";

void create() 
{
    ::create();
    set_obvious_short("A sickle");
    set_short("%^BOLD%^%^BLUE%^Sickle of F%^BOLD%^%^WHITE%^r%^BLUE%^"+
    "o%^BOLD%^%^WHITE%^s%^BLUE%^"+
    "t%^BOLD%^%^WHITE%^b%^BLUE%^i%^BOLD%^%^WHITE%^t%^BLUE%^e%^RESET%^");
    set_long((:to_object(base_name(TO)), "mylong":));
    set_lore("%^BOLD%^%^BLUE%^During one of the most brutal %^WHITE%^winters%^BOLD%^%^BLUE%^ that Deku has ever seen in Winterstime, "+
	"660SG a ranger of Auril was assigned to eliminate a %^BOLD%^%^GREEN%^chosen of Silvanus%^BLUE%^. During the winter, the rangers "+
	"battled across the frozen Shadowlord forest until the Aurilite made an error in judgement, trusting werewolves to aid him in an "+
	"ambush. The drow leading the ambush wished to wield the Aurilites impressive sickle, stabbing him and taking the sickle, leaving "+
	"the dying man to face his foe alone.%^RESET%^");
    set_property("enchantment",3);
    set_value(2000);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
    set_item_bonus("sight bonus", 1);
    set_item_bonus("cold resistance", 10);
}

string mylong()
{
    string desc;
    desc = "%^BOLD%^%^BLUE%^This sickle is made from a solid "+
    "piece of ice that has been "+
    "magically enchanted to prevent melting.  The handle of "+
    "the sickle is simply a grip that "+
    "was carefully formed in the ice.  The small blade of the "+
    "weapon is curved and almost "+
    "entirely serrated.  An odd %^RED%^scene%^BOLD%^%^BLUE%^ "+
    "is engraved into one side of the "+
    "blade, it depicts a beautiful %^CYAN%^lady%^BOLD%^%^BLUE%^ "+
    "with shards of i%^BOLD%^%^WHITE%^"+
    "c%^BOLD%^%^BLUE%^e coming forth from her finger "+
    "tips and %^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^n%^RESET%^"+
    "%^BLUE%^o%^BOLD%^%^WHITE%^w%^RESET%^%^BLUE%^f%^BOLD%^"+
    "%^WHITE%^l%^RESET%^%^BLUE%^a%^BOLD%^"+
    "%^WHITE%^k%^RESET%^%^BLUE%^e%^BOLD%^%^WHITE%^s"+
    "%^BOLD%^%^BLUE%^ cas%^CYAN%^c%^BLUE%^"+
    "ading down around her.  It is a %^RED%^"+
    "paradox%^BOLD%^%^BLUE%^ in itself as the "+
    "%^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^n%^RESET%^%^BLUE%^o%^BOLD%^"+
    "%^WHITE%^w%^RESET%^%^BLUE%^f%^BOLD%^"+
    "%^WHITE%^l%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^"+
    "k%^RESET%^%^BLUE%^e%^BOLD%^%^WHITE%^s"+
    "%^BOLD%^%^BLUE%^ fall peacefully, yet the "+
    "s%^BOLD%^%^WHITE%^h%^BLUE%^a%^BOLD%^%^WHITE%^"+
    "%^RESET%^%^BLUE%^r%^BOLD%^%^WHITE%^d%^RESET%^%^BLUE%^s "+
    "%^BOLD%^%^BLUE%^burst forth with a brutal force "+
    "and an obviously deadly intent.%^RESET%^";
    if(query_wielded()) 	
    {
        desc += "  %^YELLOW%^The blade is giving off a slight aura "+
        "of light.%^RESET%^";
    }
    return desc;
}

int wield_me() 
{
    tell_object(ETO,"%^CYAN%^You take hold of your "+
    "sickle and its blade begins to "+
    "%^YELLOW%^glow%^CYAN%^!%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN + "%^CYAN%^ takes hold of "+
        ETO->QP+ "%^CYAN%^ sickle and its blade begins to %^YELLOW%^glow"+
        "%^CYAN%^!%^RESET%^",ETO);
    }
    return 1;
}

int unwield_me() 
{
    tell_object(ETO,"%^CYAN%^You release your sickle and "+
    "its blade ceases its "+
    "%^YELLOW%^glow%^CYAN%^.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),ETO->query_cap_name() + 
        "%^CYAN%^ releases " +
        ETO->query_possessive() + "%^CYAN%^ sickle and its "+
        "blade ceases its %^YELLOW%^glow"+
        "%^CYAN%^.%^RESET%^",ETO);
    }
    return 1;
}

int special(object targ) 
{
    int chance;

    chance = random(1000);
		
    if(chance > 500 && chance < 750) 
	{
			
        tell_object(ETO,"%^CYAN%^You strike " + 
        targ->query_cap_name() + "%^CYAN%^ with "+
        "your sickle and your hand aches from the sudden cold!%^RESET%^");

        ETO->do_damage("left hand",roll_dice(1,6));

        tell_room(environment(ETO),ETO->query_cap_name() + 
        "%^CYAN%^ strikes " +
        targ->query_cap_name() + "%^CYAN%^ with " +
        ETO->query_possessive() +
        "%^CYAN%^ sickle!%^RESET%^",({targ,ETO}));
		
        tell_object(targ,ETO->query_cap_name() + 
        "%^CYAN%^ strikes you with " +
        ETO->query_possessive() + "%^CYAN%^ sickle and "+
        "your body aches with pain "+
        "from the sudden cold!%^CYAN%^!%^RESET%^");
        return roll_dice(2,6);
    }		
    return 0;
}

