//I've updated this and the armor - /d/deku/armours/eviscerators_exoskeleton.c
//to be base +3 and then +4 when used together - since I've been told
//a lot of the stuff on deku now is +3/+4 - and since these 
//work together and I think they are quite rarely ever used
//together - it should be good - if anyone has a problem 
//or notices one - please let me know, Saide - March 2nd, 2011

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/longsword";

int activated;
object bro, wielder;

void do_activate(object ob)
{
    if(!objectp(ETO)) return;
	
    bro = ob;
    if((int)TO->query_property("enchantment") < 2)
    {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 2);
    }
    TO->set_property("enchantment", 1);
    tell_object(ETO, "%^BOLD%^%^RED%^A voice whispers to you:  %^RESET%^"+
    "I'm ready to serve you now... "+capitalize(ETO->query_name())+"%^RESET%^");
    activated = 1;
}

void do_normal()
{
    if(!objectp(ETO)) return;
    TO->set_property("enchantment", -1);
    tell_object(ETO, "%^BOLD%^%^RED%^A voice whispers to you:  %^RESET%^"+
    "you ignorant fool, I'll no longer serve you...%^RESET%^");
    bro = 0;
    activated = 0;
}

void create(){
	::create();
    set_name("a dull gray longsword");
    set_id(({ "longsword", "sword", "gray longsword", "dull longsword", 
    "gray sword", "dull sword", "dull gray sword", "dull gray longsword", 
    "evisc_sword_wielded"}));

    set_short("%^BOLD%^%^BLUE%^The %^BOLD%^%^RED%^Br%^BOLD%^%^GREEN%^"+
    "u%^BOLD%^%^RED%^t%^BOLD%^%^GREEN%^a%^BOLD%^%^RED%^l %^BOLD%^%^BLUE%^"+
	"%^BOLD%^%^GREEN%^E%^BOLD%^%^BLUE%^v%^BOLD%^%^GREEN%^i%^BOLD%^%^BLUE%^"+
	"sc%^BOLD%^%^GREEN%^e%^BOLD%^%^BLUE%^r%^BOLD%^%^GREEN%^a%^BOLD%^%^BLUE%^"+
	"t%^BOLD%^%^GREEN%^o%^BOLD%^%^BLUE%^r%^RESET%^");

	set_obvious_short("A dull gray longsword");
	
	set_long("%^BOLD%^%^BLACK%^This strange longsword spans nearly "+
	"three feet in length.  Its dull bl%^YELLOW%^a%^BOLD%^%^BLACK%^d%^YELLOW%^"+
	"%^YELLOW%^e%^BOLD%^%^BLACK%^ is etched with r%^BOLD%^%^RED%^u"+
	"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^s that seems "+
	"to pulsate constantly.  The hilt of this sword is in the shape "+
	"of a small, twisted skull, locked in an %^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^"+
	"t%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^rn%^BOLD%^%^RED%^a%^BOLD%^%^BLACK%^"+
	"l agonizing scream.  The pommel beneath the hilt is made from "+
	"an oval %^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^m%^BOLD%^%^GREEN%^e"+
	"%^BOLD%^%^BLACK%^r%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^ld that appears "+
	"to have been rudely attached at the last minute, almost as an "+
	"afterthought.%^RESET%^");

	set_value(2500);

	set_lore("This strange sword was forged some decades ago, by an "+
	"unknown or long forgotten blacksmith of some legendary skill.  "+
	"It was believed to be part of a set, its magic somehow tied into "+
	"the other part, which was believed to be a suit of full plate armor.  "+
	"It is said that with both pieces of the set and only then "+
	"will the magic of this sword be unlocked.");

	set_property("lore difficulty",20);

	set("no curse", 1);
    set_property("enchantment",2);
    set_item_bonus("caster level", 1);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
}

int wield_func()
{
    object *armors, arm;
    int x;
    tell_object(ETO, "%^BOLD%^%^BLUE%^An uneasy feeling flows over "+
    "you...%^RESET%^");
    if((int)ETO->query_highest_level() < 21)
    {
		
        tell_object(ETO, "%^RED%^A voice screams at you:  %^RESET%^I will "+
        "not serve you!!!%^RESET%^");
        if(!ETO->query_invis())
        {
            tell_room(EETO, ETOQCN+"%^BOLD%^%^BLUE%^ looks shaken as "+
            ETO->QS +"%^BOLD%^%^BLUE%^ goes to grab "+ETO->QP+"%^BOLD%^%^BLUE%^"+
            " sword and suddenly stops!%^RESET%^", ({ETO}));
        }
        return 0;
    }	
    if(!ETO->query_invis()) 
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^BLUE%^ looks shaken as "+
        ETO->QS + "%^BOLD%^%^BLUE%^ takes ahold of "+ETO->QP+       
        "%^BOLD%^%^BLUE%^ sword!%^RESET%^", ({ETO}));
    }
    armors = ETO->query_armour("torso");
    for(x = 0;x < sizeof(armors);x++)
    {
        if(!objectp(armors[x])) continue;
        if(armors[x]->id("evisc_armor_worn"))
        {	
            if((object)armors[x]->query_worn() == ETO)
            {
                armors[x]->do_activate(TO);
                do_activate(armors[x]);
            }
        }
    }
    return 1;
}

int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^BLUE%^You feel more at ease as you "+
    "release your grip on the sword!%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^BLUE%^ appears visibly "+
        "less shaken as "+ETO->QS+"%^BOLD%^%^BLUE%^ "+
        "releases the sword!%^RESET%^", ({ETO}));
    }
    if(activated) 
    {
        if(objectp(bro)) bro->do_normal();
        do_normal();
    }
    return 1;
}

int hit_func(object targ)
{
    int dam;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!activated) return 0;
    if(random(3)) return 0;
    tell_object(ETO, "%^BOLD%^%^RED%^A voice screams at you: %^RESET%^"+
    "that's it, hit 'em again and again!%^RESET%^");
    switch(random(20))
    {
        case 0..4:
            tell_object(ETO, "%^BOLD%^%^RED%^You slam the "+
            "%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^m%^BOLD%^%^GREEN%^e"+
            "%^BOLD%^%^BLACK%^r%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^ld %^BOLD%^%^RED%^"+
            "pommel of your sword into "+targ->QCN+"%^BOLD%^%^RED%^'s face with "+
            "sickening thud!%^RESET%^");
			
            tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^ slams "+
            "the %^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^m%^BOLD%^%^GREEN%^e"+
            "%^BOLD%^%^BLACK%^r%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^ld%^BOLD%^%^RED%^ "+
            "pommel of "+ETO->QP+"%^BOLD%^%^RED%^ sword into your face!%^RESET%^");

            tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ slams "+
            "the %^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^m%^BOLD%^%^GREEN%^e"+
            "%^BOLD%^%^BLACK%^r%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^ld%^BOLD%^%^RED%^ "+
            "pommels of "+ETO->QP+"%^BOLD%^%^RED%^ sword into "+
            targ->QCN+"%^BOLD%^%^RED%^'s face with a sickening "+
            "thud!%^RESET%^", ({targ, ETO}));

            return roll_dice(2, 6);
            break;
        case 5..8:
            tell_object(ETO, "%^BOLD%^%^GREEN%^The blade of your sword "+
            "sinks deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s flesh!%^RESET%^");
			
            tell_object(ETO, "%^BOLD%^%^RED%^A voice cackles inside your head: "+
            "%^RESET%^I LOVE the taste of "+targ->query_race() + " flesh!");	

            tell_object(targ, ETOQCN+"%^BOLD%^%^GREEN%^ sinks the blade of "+
            ETO->QP+"%^BOLD%^%^GREEN%^ sword deep into your flesh!%^RESET%^");

            tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ sinks the blade of "+
            ETO->QP+"%^BOLD%^%^GREEN%^ sword deep into "+
            targ->QCN+"%^BOLD%^%^GREEN%^'s flesh!%^RESET%^", ({targ, ETO}));

            return roll_dice(2, 6);
            break;		

		case 9..13:
            tell_object(ETO, "%^BOLD%^%^CYAN%^The r%^BOLD%^%^RED%^u"+
            "%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^s"+
            "%^BOLD%^%^CYAN%^ on the blade of your "+
            "sword pulsate faster as you strike "+
            targ->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^");
                
            tell_object(targ, "%^BOLD%^%^CYAN%^The r%^BOLD%^%^RED%^u"+
            "%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^s"+
            "%^BOLD%^%^CYAN%^ on the blade of "+ETOQCN+"%^BOLD%^%^CYAN%^'s "+
            "sword pulsate faster as "+ETO->QS+
            "%^BOLD%^%^CYAN%^ strikes you!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^CYAN%^The r%^BOLD%^%^RED%^u"+
            "%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^s"+
            "%^BOLD%^%^CYAN%^ on the blade of "+ETOQCN+
            "%^BOLD%^%^CYAN%^'s sword pulsate faster as "+ETO->QS+
            "%^BOLD%^%^CYAN%^ strikes "+targ->QCN+"%^BOLD%^%^CYAN%^!"+
            "%^RESET%^", ({targ, ETO}));
			
            return roll_dice(2, 6);
            break;
        case 14..17:
            tell_object(ETO, "%^BOLD%^%^RED%^A voice screams inside your "+
            "head:%^RESET%^ GUT "+targ->QO+" already, you fool!%^RESET%^");

            tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^ appears half "+
            "crazed as "+ETO->QS + "%^BOLD%^%^RED%^ slashes widly at "+
            "your stomach!%^RESET%^");
	
            tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ appears half "+
            "crazed as "+ETO->QS+ "%^BOLD%^%^RED%^ slashes widly at "+
            targ->QCN+"%^BOLD%^%^RED%^'s stomach!%^RESET%^", ({targ, ETO}));

            return roll_dice(2, 6);
            break;
        case 18..19:
            tell_object(ETO, "%^MAGENTA%^Your sword sinks deep into "+
            targ->QCN+"%^MAGENTA%^ and you feel part of "+targ->QP+
            "%^MAGENTA%^ lifeforce melding with yours!%^RESET%^");
			
            tell_object(targ, ETOQCN+"%^MAGENTA%^'s sword sinks deep into "+
            "you and suddenly you feel weaker, as if a foul "+  
            "magic is ebbing at your very lifeforce!%^RESET%^");
			
            tell_room(EETO, ETOQCN+"%^MAGENTA%^'s sword sinks deep "+
            "into "+targ->QCN+"%^MAGENTA%^ and "+targ->QS + "%^MAGENTA%^"+
            " appears weakened!%^RESET%^", ({ETO, targ}));
            dam = roll_dice(3, 6);
            ETO->do_damage("torso", -dam);
            return dam;
            break;
    }	

}
