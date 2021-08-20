#include <std.h>
inherit PARMOUR;

void create(){
	::create();
     set_name("robe of nightmares");
     set_id(({"robe","robe of nightmares","inky black robe"}));
     set_short("%^BOLD%^%^BLACK%^Robe of N%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^"+
       "gh%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^ma%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^es%^RESET%^");
     set_obvious_short("%^BOLD%^%^BLACK%^An inky black slender robe%^RESET%^");
     set_long("%^BOLD%^%^BLACK%^Seeped in an inky darkness, these slender "+
	"robes are made from a mysterious fabric that seems to %^BLUE%^soak%^BLACK%^"+
      " in the surrounding light.  The robes are made without any sleeves or collar."+
      "  Instead the body of the robe is made to cling to the torso in a seamless "+
      "fashion.  From there the inky dark fabric drops straight to the floor, with"+
      " the edges looking a little tattered and frayed.  Staring into the inky cloth"+
      ", faint images of %^RESET%^%^CYAN%^faces%^BOLD%^%^BLACK%^ move across the "+
      "fabric, each one silently %^RESET%^%^MAGENTA%^screaming %^BOLD%^%^BLACK%^or"+ 
      " %^RESET%^%^BLUE%^weeping%^BOLD%^%^BLACK%^ in sheer terror. %^RESET%^\n");
	set_value(0);
	set_lore("The Robe of Nightmares was made by a Sharran wizard of the "+
         "name Ajaha Velisurm, a half-elven magess.  Ajaha discovered a way "+
         "to enter the dreams of others - where she delighted in twisting "+
         "them into nightmares.  The cruel and hard woman was widely feared,"+
         " for many of her opponents mysterious died in their sleep after "+
         "speaking against her.  Calling herself the Queen of Dreams, Ajaha"+
         " set off to bind a rare dragon under her control, one that would "+
         "give her even greater power over the dreams and nightmares of others.");
	set_property("lore difficulty",16);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
      set_item_bonus("sight bonus",2);
	set_ac(0);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_size(-1);
    set_max_internal_encumbrance(21);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wear_func(){
 if((int)ETO->query_highest_level() < 10) {
    tell_object(ETO,"The refuses to be worn by one as weak as you.");
        return 0;
   }
if((string)ETO->query_diety() == "shar") {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^Sliding into"+
			" the inky robes, you feel oddly soothed.");
      	tell_room(environment(ETO),"%^MAGENTA%^"+ETO->query_cap_name()+""+
      		" slides into "+ETO->QP+" inky black robes.  Faces "+
                  "move across the surface of the robe, screaming out"+
                  " silently in sheer terror.",ETO);
      return 1;
   	}else{
		tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" slips in"+
			" a inky black robe.",ETO);
		tell_object(ETO,"%^MAGENTA%^You slip on the inky black"+
			" robe, you can almost feel the terror that is woven into the cloth.%^RESET%^");
	return 1;
	}
}
int remove_func(){
	if((string)ETO->query_diety() == "shar") {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^Sliding out of"+
			" the inky black robes, the faces twist in terror"+
                  " before fading away into the darkness.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
      		" slides out of "+ETO->QP+" inky black robes.  The images of"+
			" the %^MAGENTA%^faces%^RESET%^ on "+ETO->QP+" robes "+
			"fade away into the darkness.",ETO);
	return 1;
	}
	else{
		tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" slips "+
			"out of the inky black robe.",ETO);
		tell_object(ETO,"%^MAGENTA%^You slip out of the inky black robe.");
	return 1;
	}
}
int strike_func(int damage, object what, object who){
	if(!random(10)){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A face fights"+
         " to escape from "+ETOQCN+"'s robe, clawing at  "+
         ""+who->QCN+" for aid!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^One of the faces woven into the "+
        "robe tries to escape, clawing at "+who->QCN+" for aid.");
	tell_object(who,"%^BOLD%^%^BLACK%^A face fights to escape from"+
        " "+ETOQCN+"'s robe, clawing at you for aid.");
    who->cause_typed_damage(who, "torso", roll_dice(1, 4)+5, "untyped");
	}
    return damage;
}