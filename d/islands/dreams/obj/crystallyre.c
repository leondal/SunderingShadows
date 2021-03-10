#include <std.h>

inherit WEAPON;

void create()
{
 	::create();
	set_name("crystal lyre");
   	set_short("%^BOLD%^%^BLUE%^S%^RESET%^%^CYAN%^t%^MAGENTA%^a%^BOLD%^"+
		"%^WHITE%^r%^BLUE%^s%^RESET%^%^CYAN%^i%^MAGENTA%^n%^BOLD%^"+
		"%^WHITE%^g%^BLUE%^e%^RESET%^%^CYAN%^r%^MAGENTA%^'"+
		"%^BOLD%^%^WHITE%^s%^CYAN%^ Lyre%^RESET%^");
   	set_obvious_short("%^BOLD%^%^WHITE%^A crystal lyre%^RESET%^");
   	set_id(({"lyre","crystal lyre","starsinger's lyre"}));
   	set_long("%^BOLD%^%^BLUE%^Shaped from %^RESET%^%^BLUE%^dark"+
		" blue%^BOLD%^ crystal, the base of this elegant lyre"+
		" curves gracefully inwards, in almost a crescent moon"+
		" like shape.  Within the %^RESET%^%^BLUE%^blue "+
		"%^BOLD%^crystal wisps of %^MAGENTA%^p%^RESET%^"+
		"%^MAGENTA%^l%^BOLD%^u%^RESET%^%^MAGENTA%^m%^BOLD%^"+
		"%^BLUE%^ colored lights can be seen, flaring to life "+
		"before they fade out.  The crossbar of the lyre is made"+
		" from similar crystal, only this time %^WHITE%^clear"+
		"%^BLUE%^.  The cross bar sweeps downwards at an angle,"+
		" as to house the strings.  Strung with seven "+
		"%^WHITE%^i%^CYAN%^r%^MAGENTA%^i%^BLUE%^d%^CYAN%^e"+
		"%^MAGENTA%^s%^BLUE%^c%^WHITE%^e%^CYAN%^n%^MAGENTA%^t"+
		"%^BLUE%^ strings, the lyre comes ready to play.  The"+
		" strings glisten in the light, creating miniature "+
		"%^RESET%^%^RED%^p%^BOLD%^r%^RESET%^%^ORANGE%^i"+
		"%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a%^BLUE%^t"+
		"%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLUE%^"+
		" twinkles as they reflect the light.  It would be nearly"+
		" impossible to find a lyre as well crafted or as beautiful"+
		" as this.\n");
	set_lore("Miiriam Starsinger was said to have been 'the woman "+
		"with a silvery voice'.  Her music and voice enchanted "+
		"many as she traveled across the lands.  With her trusty"+
		" lyre in hand and always a song ready on her lips, many"+
		" were charmed by the graces and songs of Miiriam.  She "+
		"once aided the faith of Selune the Moonmaiden in locating"+
		" one of the Silverstar Rings.  In gratitude for her aid to"+
		" the faith in locating this holy relic, the faith presented"+
		" Miiriam with a crystal lyre.  The lyre was enchanted to "+
		"use Miiriam's skill of song in battle, letting her create"+
		" waves of sound to protect herself.  This famous lyre even"+
		" took her name, Starsinger's Lyre.  When Miiriam grew tired"+
		" of traveling the lands and longed for new crowds to spread"+
		" her music to, it is said she gave her famous lyre away to "+
		"her prized pupil before departing. - Following the Silvery"+
		" Voice : The Life of Miiram Starginger - Bradicus Pitthem");
   	set_property("lore difficulty",20);
   	set_weight(5);
   	set_value(1000);
   	set_type("bludgeoning");
   	set_wc(2,6);
   	set_large_wc(2,6);
	set_size(3);
   	set_property("enchantment",3);
	set_item_bonus("attack bonus",2);
   	set_wield((:TO,"wieldme":));
   	set_unwield((:TO,"removeme":));
   	set_hit((:TO,"hit_func":));
   	set_prof_type("instrument");
   	set_weapon_speed(6);
}

int wieldme(){
	if(!ETO->is_class("bard")){
   		tell_object(ETO,"%^CYAN%^You wouldn't even begin to know how to use that.");
      		return 0;
        }
        if((int)ETO->query_lowest_level() < 20) {
      	tell_object(ETO,"%^BOLD%^%^CYAN%^You just don't have the skill to play"+
		" that yet.%^RESET%^");
      		return 0;
	}
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" strums the crystal strings of"+
		" the lyre with skill and mastery.",ETO);
      tell_object(ETO,"%^BOLD%^%^BLUE%^%^You strum the strings of the lyre with "+
		"skill, feeling the power houses within this lyre.%^RESET%^");
			return 1;
	}

int hit_func(object targ) {
   	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" attacks"+
		" "+targ->QCN+" with the sonic melodies of "+ETO->QP+""+
		" lyre.",({ETO,targ}));
     	tell_object(ETO,"%^BOLD%^%^CYAN%^You use the lyre attack "+
		""+targ->QCN+" sonically.");
     	tell_object(targ,"%^BOLD%^%^CYAN%^You are assulted by the"+
		" sonic melodies that
		"+ETOQCN+" creates on "+ETO->QP+" lyre.");
			if(random(1000) < 200)
            {
                switch(random(65))
                {

                    case 35..49:
                        tell_object(ETO,"%^BOLD%^%^WHITE%^You play a captivating tune on the"+
                        " lyre, holding "+targ->QCN+" enthralled in the melody!");
                        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+"enthralling"+
                        " melody holds you captivated for a moment!");
                        tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->QCN+" plays a captivating"+
                        " melody on "+ETO->QP+" lyre.  The melody holds "+targ->QCN+""+
                        " entranced.",({targ,ETO}));
                        targ->set_paralyzed(random(10)+5,"%^BOLD%^%^WHITE%^You are "+
                        "entranced by the music.");      		
                        break;  
                    case 50..64:
                        tell_object(ETO,"%^MAGENTA%^Your fingers dance across the strings"+
                        " of the lyre to weave a melody together. Hit full force by"+
                        " the power of your song "+targ->QCN+" is knocked "+
                        "off "+targ->QP+" feet.");
                        tell_object(targ,"%^MAGENTA%^"+ETO->QCN+"'s fingers dance across the"+
                        " strings of "+ETO->QP+" lyre. Hit by the full force of the "+
                        "song, you are knocked off your feet!");
                        tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+"'s fingers dance"+
                        " across the strings of "+ETO->QP+" lyre, weaving together a"+
                        " song.  "+targ->QCN+" is hit full force by the power "+
                        "of "+ETOQCN+"'s song and knocked off "+targ->QP+" feet.",({ETO,targ}));
                        set_property("magic",1);
                        targ->do_damage("torso",random(7)+10);
                        targ->set_tripped(3,"%^MAGENTA%^You are still trying"+
                        " to get back on your feet.");
                        remove_property("magic");
                        break;
                    default:
                        tell_object(ETO,"%^BOLD%^%^BLUE%^You play a rapid melody on the lyre"+
                        " that sends a wave of sound crashing into "+targ->QCN+"!");
                        tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" plays a rapid melody"+
                        " on the lyre that sends a wave of sound crashing into you!");
                        tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+" play a "+
                        "rapid melody on the lyre that sends a wave of sound "+
                        "crashing into "+targ->QCN+"!",({ETO,targ}));
                        set_property("magic",1);
                        targ->do_damage("torso",random(6)+4);
                        remove_property("magic");
                        break;
                }
           }
   	return 1;	
}
int removeme()
{
   	tell_object(ETO,"%^BOLD%^%^BLUE%^%^You give the strings one final"+
		" strum before setting it away.");
   	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+" strums "+
		"the strings of the crystal lyre before setting it away.",ETO);
	return 1;
}
int is_instrument(){return 1;}
