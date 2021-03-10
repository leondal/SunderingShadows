#include <std.h>
inherit "/d/common/obj/weapon/handaxe.c";


void create() 
{
    ::create();
    set_name("flaming axe");
    set_id(({"axe", "handaxe", "hand axe", 
    "flaming axe", "flame axe"}));
	
    set_obvious_short("A flaming axe");
		
    set_short("%^BOLD%^%^RED%^G%^BOLD%^%^YELLOW%^ob%^BOLD%^%^RED%^"+
    "l%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^n F%^BOLD%^%^YELLOW%^"+
    "i%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^e A%^BOLD%^%^RED%^"+
    "x%^BOLD%^%^YELLOW%^e%^RESET%^");
	
    set_long("%^BOLD%^%^RED%^This short axe has been forged "+
    "from a dull %^BOLD%^%^BLACK%^black%^BOLD%^%^RED%^ material. "+
    "The head of this axe has edges on both sides that have been "+
    "honed down to a %^BOLD%^%^YELLOW%^razor%^BOLD%^%^RED%^ "+
    "sharp point. A liquid coating has been applied to both "+
    "edges that makes them burn faintly. Strangely the %^BOLD%^"+
    "%^YELLOW%^flame %^BOLD%^%^RED%^"+
    "is not hot at all and does not burn the flesh of one who "+
    "touches it. The handle of this axe flows out from the "+
    "head, making the axe one solid piece. The handle is rough, "+
    "persumably to offer a better grip to whoever happens "+
    "to be wielding it.%^RESET%^");

    set_value(200);
    set_property("lore difficulty", 15);

    set_lore("%^RED%^This axe was, at one time, a common "+
    "weapon. This particular axe was honed down, almost "+
    "obsessively, to a razor fine point and then coated "+
    "with a magical oil that provides the fiery appearance "+
    "and makes it much more deadly in combat. This axe was "+
    "one of many created by the Goblin Sorceress "+
    "Ashilla, The Mad, to help her soldiers fight off "+
    "the neverending hordes of spiders.%^RESET%^");

    set_property("enchantment",2);

    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
    set_item_bonus("attack bonus", 2);
}

int wield_me()
{
    tell_object(ETO, "%^BOLD%^%^RED%^You feel "+	
    "knowledge flow into you from the axe, as if it is "+
    "trying to show you how to better hit your foes!%^RESET%^");
    return 1;
}

int unwield_me()
{
    tell_object(ETO, "%^BOLD%^%^RED%^You feel a slight "+
    "emptiness as the knowledge provided by the axe leaves you.%^RESET%^");
    return 1;
}

int special(object targ) 
{
    string tlim;
    int dam;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(100) < 75) return 0;
    tlim = targ->return_target_limb();

    tell_object(ETO, "%^BOLD%^%^WHITE%^A "+
    "%^BOLD%^%^RED%^f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
    "e%^BOLD%^%^YELLOW%^r%^BOLD%^%^RED%^y %^BOLD%^%^WHITE%^"+
    "tendril lashes out from the head of your axe "+
    "and strikes "+targ->QCN+"%^BOLD%^%^WHITE%^ "+tlim+"!%^RESET%^");
    
    tell_object(targ, "%^BOLD%^%^WHITE%^A "+
    "%^BOLD%^%^RED%^f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
    "e%^BOLD%^%^YELLOW%^r%^BOLD%^%^RED%^y %^BOLD%^%^WHITE%^"+
    "tendril lashes out from the head of "+ETOQCN+
    "%^BOLD%^%^WHITE%^'s axe and strikes your "+
    tlim+"!%^RESET%^");

    tell_room(EETO, "%^BOLD%^%^WHITE%^A "+
    "%^BOLD%^%^RED%^f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
    "e%^BOLD%^%^YELLOW%^r%^BOLD%^%^RED%^y %^BOLD%^%^WHITE%^"+
    "tendril lashes out from the head of "+ETOQCN+
    "%^BOLD%^%^WHITE%^'s axe and strikes "+targ->QCN+
    "%^BOLD%^%^WHITE%^'s "+tlim+"!%^RESET%^", ({targ, ETO}));
	
    targ->cause_typed_damage(targ,tlim,roll_dice(1,6),"fire");
    return 1;
}
