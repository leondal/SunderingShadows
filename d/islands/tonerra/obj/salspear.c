//Revamped - Cythera - 7/05
//salspear.c

#include <std.h>

inherit "/d/common/obj/weapon/spear_lg.c";

void create(){
   	::create();
	set_name("%^BOLD%^%^RED%^Spear of the %^RESET%^%^RED%^Et%^ORANGE%^e"+
		"%^RED%^rn%^ORANGE%^a%^RED%^l Fl%^BOLD%^a%^RESET%^%^RED%^m%^BOLD%^"+
		"e%^RESET%^%^RED%^s%^RESET%^");
   	set_id(({"salspear","spear","Spear","fire spear","Fire Spear","+
		""Fire spear","long spear","spear of the eternal flames","+
		""flame spear"}));
   	set_short("%^BOLD%^%^RED%^Spear of the %^RESET%^%^RED%^Et%^ORANGE%^e"+
		"%^RED%^rn%^ORANGE%^a%^RED%^l Fl%^BOLD%^a%^RESET%^%^RED%^m%^BOLD%^"+
		"e%^RESET%^%^RED%^s%^RESET%^");
     	set_obvious_short("%^BOLD%^%^BLACK%^A long spear with a"+
		" %^RED%^fiery%^BLACK%^ spearhead");
   	set_long("%^BOLD%^%^BLACK%^Waves of %^RED%^heat%^BLACK%^ roll"+
		" off this spear, warming the air around it.  The metal "+
		"shaft of this long spear has been tinted a %^RED%^fiery"+
		" red %^BLACK%^shade and inlaid with spheres of %^RESET%^"+
		"%^RED%^flam%^ORANGE%^e%^RED%^dance%^BOLD%^%^BLACK%^ and"+
		" %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^re o%^YELLOW%^p%^RESET%^"+
		"%^ORANGE%^a%^BOLD%^%^RED%^l%^BLACK%^ gems.  The top of the "+
		"spear has been covered with a %^RED%^ruby%^BLACK%^ cap.  "+
		"Inside the ruby gem sparks of %^RED%^flames%^BLACK%^ can "+
		"be seen, circling around.  Instead of a standard spearhead,"+
		" an enchanted magical %^RESET%^%^RED%^f%^BOLD%^la%^RESET%^"+
		"%^RED%^m%^BOLD%^e%^BLACK%^ that has been shaped into a kite "+
		"shape crows the top of the spear.  The fires blaze and flare,"+
		" though never seem to expand past the shape they have been "+
		"fashioned in.%^RESET%^");
	set_lore("Forged from fever iron, this majestic and magical spear has"+
		" been infused with the fires in the heart of the Lava Tubes.  "+
		"The enchanted sphere of flamedance and fire opal are said to "+
		"help the fuel the fires continuously.  The Spear of the Eternal"+
		" Flames is said to have been crafted by a human mage who saw the"+
		" process within a dream.  Some say Eldorando became obsessed with"+
		" the spear, spending every waking hour working on locating the right"+
		" gems, the right vein of metal before carefully shaping them.  The"+
		" process wore on Eldorando's body, as it consumed him.  For three"+
		" years he labored over the spear, rejecting friends and allies in"+
		" favor of his beloved project.  Once the spear was completed "+
		"Eldorando left a letter behind stating he was heading to the "+
		"island of Tonerra in search of the lava fields that laid under "+
		"the volcano.  That was the last anyone ever heard of Eldorando.  "+
		"A spear though was found some fifty years latter in the Lava Tubes,"+
		" one that matched the description left behind in Eldorando's journals"+
		". - Mysteries of Magic - Odelesta Peirrigrin");
	set_property("lore",19);
   	//set_wc(1,11);
   	//set_large_wc(3,6);
   	set_property("enchantment",4);
   	set_weight(10);
   	set_value(450);
   	//set_size(3);
   	set_hit((:TO,"hitem":));
   	set_wield((:TO,"burnem":));
   	//set_type("piercing");
   	//set_prof_type("large spear");
}
int hitem(object victim) {
    int dam;
    dam = random(6) + 1;
      if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(victim)) return 1;
      if(!random(7)){    	
      tell_object(ETO,"%^RED%^The flames of the spearhead blaze "+
		"outwards as you drive the tip into "+
 		""+victim->QCN+".");
      tell_object(victim,"%^RED%^The flames of "+ETO->QCN+"'s blaze "+
		"outwards as "+ETO->QS+" drives the tip into you!",);
      tell_room(environment(ETO),"%^RED%^The flames of "+ETO->QCN+"'s blaze "+
		"outwards as "+ETO->QS+" drives the tip into "+
		""+victim->QCN+"!",({ETO,victim}));
			ETO->heal(dam);
    			dam = dam + random(dam);
    			return dam;
      }
      return 0;
}

int burnem(){

   if(TP->query_property("fire resistant")) return 1;
   tell_object(TP,"%^RED%^Your hands are burned by the searing heat of this spear.");
   TP->do_damage("torso",roll_dice(2,10));
   return 1;
}
