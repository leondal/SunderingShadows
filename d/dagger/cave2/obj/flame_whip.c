#include <std.h>

inherit "/d/common/obj/weapon/whip.c";

void create(){
 	::create();
	set_name("whip of flames");
   	set_short("%^RESET%^%^RED%^Whip of the %^BOLD%^%^RED%^F%^RESET%^%^RED%^"+
                "l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e%^RESET%^"+
                "%^RED%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A ruby handle flame whip%^RESET%^");
   	set_long("%^BOLD%^%^RED%^The whip consists of a solid base of %^RESET%^%^RED%^%^ruby"+
		"%^BOLD%^%^RED%^.  Within the ruby base %^BOLD%^%^WHITE%^s%^YELLOW%^p%^BOLD%^"+
                "%^WHITE%^a%^YELLOW%^r%^BOLD%^%^WHITE%^k%^YELLOW%^s%^BOLD%^%^RED%^ can be "+
                "seen flaring to life and winking out."+
   		" Extending from the base is a swirling mass of %^RESET%^%^RED%^f"+
		"%^ORANGE%^l%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^m%^RED%^es%^BOLD%^"+
		"%^RED%^ that seems to be barely contained into the shape of a"+
                " whip by an invisible force.%^RESET%^\n");
	set_lore("The Whip of Flames carries some conflicting and contradictory stories "+
            "with it.  Some claim that the whip is forged in the unholy fires of evil "+
            "planes inhabited by demons and devils, which they use on to torment mortals "+
            "with.  Some claim that the whip is actually forged in the dying fires of the "+
            "phoenix, before the mythical bird is reborn.  Still others claim the whip is "+
            "a testament of the raw power of fire and the damage that can be done with it.  "+
            "With so many stories in circulation, its nearly impossible to know the truth.");
   	set_property("lore difficulty",16);
     	set_value(1000);
      set_type("lash");
     	set_property("enchantment",3);
   	set_wield((:TO,"wieldme":));
   	set_unwield((:TO,"removeme":));
   	set_hit((:TO,"hit_func":));
}

int wieldme()
{
   	if((string)ETO->query_diety() == "istishia" || (string)ETO->query_diety() == "auril") {
		tell_object(ETO,"%^RED%^Wielding a whip such as this"+
			" would most certainly offend your Goddess.");
      return 0;
   	}
   	if(((string)ETO->query_diety() == "kossuth") || ((string)ETO->query_diety() == "sune") || ((string)ETO->query_diety() == "loviatar")) {
      	tell_object(ETO,"%^RED%^The heat of the whip feels comforting to you.");
		tell_room(environment(ETO),"%^RED%^"+ETO->QCN+""+
			"grasps the whip with ease.",ETO);
	return 1;
	}
   else{
   	tell_object(ETO,"%^BOLD%^%^RED%^The whip is hot in your grasp but you"+
   		" can feel the blazing power it contains.");
   	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+""+
   		" seems barely able to contain the power of the whip.",ETO);
   	return 1;
	}
}


int hit_func(object targ) 
{
   	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    if(random(1000) < 200)
    {    
        switch(random(65))
        {

        default:
            tell_object(ETO,"%^RED%^The raging flames within your whip lashes out"+
                " at "+targ->QCN+"!");
            tell_object(targ,"%^RED%^"+ETO->QCN+"'s whip strikes"+
                " you with the power of a blazing inferno!");
            tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" strikes"+
                " "+targ->QCN+" with "+ETO->QP+""+
                " whip.",({ETO,targ}));
            set_property("magic",1);
            targ->do_damage("torso",random(6)+4);
            remove_property("magic");
            break;
            
        case 30..49:
            tell_object(ETO,"%^BOLD%^%^RED%^Your whip snakes around "+targ->QCN+"'s"+
                " arm, burning "+targ->QO+"!");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+"'s whip"+
                " snakes around your arm, burning you!");
            tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+"'s"+
                " whip snakes around "+targ->QCN+"'s arm, burning"+
                " "+targ->QO+"!",({targ,ETO}));
            set_property("magic",1);
            targ->set_tripped(1,"You are still reeling in pain from the flames.");
            targ->do_damage("torso",random(5)+6);
            remove_property("magic");
            break;
            
        case 50..64:
            tell_object(ETO,"%^BOLD%^%^WHITE%^Your whip blasts "+targ->QCN+""+
                " with an intense white hot flame.");
            tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s whip"+
                " strikes you, burning you with an intense white hot flame!");
            tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->QCN+""+
                " strikes "+targ->QCN+" with "+ETO->QP+""+
                " whip, burning "+targ->QCN+" with an intense white hot flame!"+
                "",({ETO,targ}));
            set_property("magic",1);
            targ->do_damage("torso",random(7)+10);
            remove_property("magic");
            break;
        }
           
   	return 1;
	}
}

int removeme()
{
	if(((string)ETO->query_diety() == "kossuth") || ((string)ETO->query_diety() == "sune") || ((string)ETO->query_diety() == "loviatar")) {
  		tell_object(ETO,"%^RED%^The fading warmth of the whip leaves"+
			" you with a slight chill, after you release your hold"+
			" of it.");
      	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+""+
			" release the whip with a soft sigh.",ETO);
      return 1;
	}else{
   		tell_object(ETO,"%^BOLD%^%^RED%^You release the whip and "+
			"immediately feel relief, you didn't realize the "+
			"strain that containing such power caused.");
   		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" seems"+
   			" to fight with the whip as "+ETO->QS+" unwields it.",ETO);
   	return 1;
	}
}
