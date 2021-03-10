#include <std.h>
inherit "/d/common/obj/weapon/whip_dagger.c";

void create(){
	::create();
   	set_name("%^RESET%^%^ORANGE%^G%^BOLD%^o%^RESET%^%^ORANGE%^l"+
		"%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n %^WHITE%^C"+
		"%^YELLOW%^r%^WHITE%^e%^YELLOW%^s%^WHITE%^c%^YELLOW%^"+
		"e%^WHITE%^n%^YELLOW%^t Whip%^RESET%^");
   	set_obvious_short("%^YELLOW%^A golden whip with a crescent blade%^RESET%^");
	set_short("%^RESET%^%^ORANGE%^G%^BOLD%^o%^RESET%^%^ORANGE%^l"+
		"%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n %^WHITE%^C"+
		"%^YELLOW%^r%^WHITE%^e%^YELLOW%^s%^WHITE%^c%^YELLOW%^"+
		"e%^WHITE%^n%^YELLOW%^t Whip%^RESET%^");
   	set_id(({"whip","golden whip","gold whip","whip dagger","golden crescent whip","crescent whip"}));
   	set_long("%^BOLD%^%^WHITE%^This is an excellently crafted "+
		"whip made of fine white silk strands that are intertwined "+
		"with threads of %^YELLOW%^gold%^WHITE%^. A crescent shaped blade is "+
		"attached to the end of the lash, shaped out of a mixture of"+
		" white and %^YELLOW%^yellow %^WHITE%^g%^YELLOW%^o%^WHITE%^"+
		"l%^YELLOW%^d%^WHITE%^.  The outside of the "+
		"%^YELLOW%^g%^WHITE%^o%^YELLOW%^l%^WHITE%^d blade has a keen"+
		" sharp edge, suitable for slashing.  Brilliant cut "+
		"%^YELLOW%^canary diamond%^BOLD%^%^WHITE%^ are inlaid into "+
		"the gold, adding to the bright luster of this whip-dagger.  "+
   		" The handle is made of %^RESET%^%^ORANGE%^hazelwood"+
		"%^BOLD%^%^WHITE%^ that has been wrapped in"+
   		" cool %^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^"+
		"l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n%^WHITE%^ "+
		"silk.%^RESET%^");
	set_lore("First created and used by the elves of Selu'havessthor, these"+
		" formitable whips were crafted to help defend their Tsarven "+
		"forest kingdom from invaders.  The bladed whip was favored "+
		"by some of the elven rogues for their ability to deal a "+
		"crippling strike from a safe distance.  Following the purge, "+
            "the fey'ri fled their homeland, bringing many such treasured "+
            "weapons with them.");
	set_property("lore",12);
   	set_wield((:TO,"wieldme":));
   	set_unwield((:TO,"removeme":));
   	set_hit((:TO,"hitme":));
   	set_property("enchantment",4);
   	set_value(2000);
}

int wieldme(){
     if((int)ETO->query_lowest_level() < 30) {
      	tell_object(ETO,"%^YELLOW%^The whip refuses you!");
     	return 0;
	}
   	tell_object(ETO,"%^YELLOW%^You instantly realize that this weapon"+
   		" is quite formidable, and not just a pretty decoration.");
   	return 1;
}

int removeme(){
   	tell_object(ETO,"%^YELLOW%^You release the whip, but keep it close.");
   	return 1;
}

int hitme(object targ)
{
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	
    if(random(1000) < 250)
    {
        switch(random(36))
        {
        case 0..22:
            tell_object(ETO,"%^ORANGE%^You flick your wrist, sending the"+
                " golden crescent blade of your whip spiraling into"+
                " "+targ->QCN+"!");
            tell_object(targ,"%^ORANGE%^"+ETO->QCN+" flicks "+ETO->QP+" wrist"+
                " sending the crescent blade of "+ETO->QP+" whip spiraling"+
                " into you!");
            tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+""+
                " flicks "+ETO->QP+" wrist, sending the golden crescent blade"+
                " of "+ETO->QP+" whip spiraling into "+targ->QCN+"!",({ETO,targ}));
            targ->do_damage("torso",random(6)+3);
            break;
            
        case 23..32:
            tell_object(ETO,"%^BOLD%^Your whip circles "+targ->QCN+"'s"+
                " neck for a moment, cutting off "+targ->QP+" air!");
            tell_object(targ,"%^BOLD%^"+ETO->QCN+" circles"+
                " "+ETO->QP+" whip around your neck for a moment,"+
                " briefly choking you!");
            tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
                " circles "+ETO->QP+" whip around "+targ->QCN+"'s"+
                " neck for a moment, cutting off "+targ->QP+" "+
                "air!",({ETO,targ}));
            targ->do_damage("torso",random(8)+4);
            targ->set_paralyzed(random(3)+2,"%^YELLOW%^Air.. Must.. Get.. Air!");
            break;
            
        case 33..35:
            tell_object(ETO,"%^YELLOW%^You manage to loop the whip around"+
                " "+targ->QCN+"'s ankles and pull "+targ->QO+""+
                " off "+targ->QP+" feet!");
            tell_object(targ,"%^YELLOW%^"+ETO->QCN+" loops"+
                " "+ETO->QP+" whip about your ankles, then yanks"+
                " you off your feet!");
            tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+""+
                " loops "+ETO->QP+" whip about "+targ->QCN+"'s"+
                " ankles, then yanks "+targ->QO+" off "+targ->QP+" "+
                "feet!",({ETO,targ}));
            targ->do_damage("torso",random(10)+6);
            targ->set_tripped(2,"You're trying to recover from being laid flat!");

            break;
        
        default:  
            tell_object(ETO,"Well now you've done it! :) Please bug"+
                " this and include what you were doing/fighting when you got"+
                " this message.");
            break;  
		}
    
    return 1;
	}
}
