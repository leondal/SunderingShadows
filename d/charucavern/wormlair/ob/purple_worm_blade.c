#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/weapon/longsword";
object ActiveWorm;
int chance;

void create(){
	::create();
	set_name("a deep purple long sword");
	set_id(({ "longsword", "long sword", "purple long sword", "purple longsword", 
    "deep purple sword", "deep purple longsword", "deep purple long sword", "sword", 
    "blade", "purple blade", "deep purple blade", "blade of the worm", 
    "blade of the purple worm"}));

	set_short("%^RESET%^%^MAGENTA%^Bl%^BOLD%^a%^RESET%^%^MAGENTA%^d"+
    "%^BOLD%^e o%^RESET%^%^MAGENTA%^f th%^BOLD%^e%^RESET%^%^MAGENTA%^ "+
    "p%^BOLD%^u%^RESET%^%^MAGENTA%^rpl%^BOLD%^e %^RESET%^%^MAGENTA%^w"+
    "%^BOLD%^o%^RESET%^%^MAGENTA%^rm%^RESET%^");

	set_obvious_short("%^RESET%^%^MAGENTA%^A deep purple long sword%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^The blade of this "+
    "long sword extends nearly three feet in length. It is made from "+
    "metal that has been dyed to a %^BOLD%^deep purple%^RESET%^%^MAGENTA%^"+
    " hue. Both sides of the blade have been honed to a fine %^BOLD%^%^YELLOW%^"+
    "edge%^RESET%^%^MAGENTA%^. There is is a strip of %^BOLD%^%^GREEN%^brilliant "+
    "green%^RESET%^%^MAGENTA%^ metal that runs down the center of the blade and "+
    "expands at the base of the blade to form the shape of a hideous, %^BOLD%^"+
    "%^WHITE%^fanged%^RESET%^%^MAGENTA%^ mouth. The hilt extends to "+
    "a very contrasting %^BOLD%^%^WHITE%^white%^RESET%^%^MAGENTA%^ that has "+
    "been chiseled from a large %^BOLD%^%^WHITE%^bone%^RESET%^%^MAGENTA%^ to allow "+
    "someone to wield it. An orb which is a much %^BOLD%^lighter%^RESET%^%^MAGENTA%^"+
    " color rests beneath the handle of the blade, it is perfectly smooth and seems "+
    "to reflect even the most miniscule light.%^RESET%^");

	set_value(4000);

	set_lore("%^RESET%^%^MAGENTA%^This blade was one of a pair that was forged "+
    "for the crazed ranger of Silvanus, known as Howne. It was rumored to be made "+
    "from metal that was bathed in the remains of purple worms for several months before "+
    "it was finally forged. Legend suggests that it was then dipped in the stomach "+
    "acid from one of the worms. The hilt was designed to mimic their hideous "+
    "fanged mouths, with the handle believed to have been forged from one of their "+
    "actual fangs. Some rumors suggest that it is uniquely linked to the worms.%^RESET%^");

	set_property("lore difficulty",14);

	set_property("enchantment",2);
    
    set_item_bonus("acid resistance", 5);
    
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
    
    chance = 25 + random(46);
    
}

int wield_func()
{
    tell_object(ETO, "%^RESET%^%^MAGENTA%^You feel an aura of protection from "+
    "%^BOLD%^%^GREEN%^acid %^RESET%^%^MAGENTA%^"+
    "settle over you as you wield the blade.%^RESET%^");
	
	return 1;
}

int unwield_func()
{
	 tell_object(ETO, "%^RESET%^%^MAGENTA%^You feel the aura of protection from "+
    "%^BOLD%^%^GREEN%^acid %^RESET%^%^MAGENTA%^"+
    "fade away as you release the blade.%^RESET%^");
    
	return 1;
}

int hit_func(object targ)
{
    string lim;
	if(!objectp(ETO)) return 0;
	if(!objectp(EETO)) return 0;
	if(!objectp(targ)) return 0;
    if(random(3)) return 0;
    
    if(objectp(ActiveWorm))
    {
        if(environment(ActiveWorm) != EETO)
        {
            tell_room(environment(ActiveWorm), ActiveWorm->query_short()+"%^RESET%^%^MAGENTA%^ simply "+
            "fades away!%^RESET%^");
            ActiveWorm->move("/d/shadowgate/void");
            if(objectp(ActiveWorm)) ActiveWorm->remove();
        }
    }
    
    
    switch(random(18))
    {
        case 0..8:
            tell_object(ETO, "%^BOLD%^%^MAGENTA%^As you slice into "+targ->QCN+
            " %^BOLD%^%^GREEN%^acid%^BOLD%^%^MAGENTA%^ is pumped into the wound!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^MAGENTA%^As "+ETOQCN+"%^BOLD%^%^MAGENTA%^ slices "+
            ETO->QP+" blade into you, you feel %^BOLD%^%^GREEN%^acid%^BOLD%^%^MAGENTA%^ "+
            "being pumped into the wound!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^MAGENTA%^As "+ETOQCN+"%^BOLD%^%^MAGENTA%^ slices "+
            ETO->QP+" blade into "+targ->QCN+"%^BOLD%^%^GREEN%^ acid%^BOLD%^%^MAGENTA%^"+
            "is pumped into the wound!%^RESET%^", ({ETO, targ}));
            
            targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(4, 4), "acid");
            return 0;
            break;
        case 9..15:
            lim = targ->return_target_limb();
            tell_object(ETO, "%^BOLD%^%^MAGENTA%^You bury your blade deep into "+
            targ->QCN+"%^BOLD%^%^MAGENTA%^'s "+lim+"!%^RESET%^");
            
            tell_object(targ, ETOQCN+"%^BOLD%^%^MAGENTA%^ buries "+ETO->QP+" blade deep into "+
            "your "+lim+"!%^RESET%^");
            
            tell_room(EETO, ETOQCN+"%^BOLD%^%^MAGENTA%^ buries "+ETO->QP+" blade deep into "+
            targ->QCN+"%^BOLD%^%^MAGENTA%^'s "+lim+"!%^RESET%^", ({ETO, targ}));
            
            return roll_dice(2, 4);
            break;
        case 16..17:
            if(roll_dice(1,100) > chance) return 0;
            if(objectp(ActiveWorm)) 
            {
                ActiveWorm->swallow(targ);
                return 0;
            }
            ActiveWorm = new(WMON+"spectral_purple_worm");
            if(!objectp(ActiveWorm)) return 0;
        
            tell_object(ETO, "%^BOLD%^%^MAGENTA%^You feel a pulse of energy flow out from your "+
            "blade as "+ActiveWorm->query_short()+"%^BOLD%^%^MAGENTA%^"+
            " materializes between you and "+targ->QCN+"%^BOLD%^%^MAGENTA%^, attacking "+
            targ->QO+"!%^RESET%^");
        
            tell_object(targ, "%^BOLD%^%^MAGENTA%^As you are hit by "+ETOQCN+", "+ActiveWorm->query_short()+
            "%^BOLD%^%^MAGENTA%^ materializes between you and "+ETO->QS+" and attacks you!%^RESET%^");
        
            tell_room(EETO, "%^BOLD%^%^MAGENTA%^As "+targ->QCN+"%^BOLD%^%^MAGENTA%^ is hit by "+ETOQCN+", "+ActiveWorm->query_short()+
            "%^BOLD%^%^MAGENTA%^ materializes between them and attacks "+targ->QO+"!%^RESET%^", ({ETO, targ}));
        
            ActiveWorm->move(EETO);
            ActiveWorm->set_property("minion", ETO);
            ETO->add_follower(ActiveWorm);
            ETO->add_protector(ActiveWorm);
            ActiveWorm->force_me("kill "+targ->query_name());
            ActiveWorm->swallow(targ);
            return 0;
            break;
    }
    return 0;
}
