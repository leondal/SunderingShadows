#include <std.h>
inherit "/d/common/obj/weapon/light_rapier.c";

void create(){
  	::create();
  	set_id(({"rapier","sword","light rapier","Black Swan","black swan"}));
  	set_name("light rapier");
  	set_short("%^BOLD%^%^BLACK%^Bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck"+
		" Sw%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^An ornamented light rapier%^RESET%^");
  	set_long("%^BOLD%^%^BLACK%^This slender rapier is fashioned out of "+
		"%^WHITE%^palladium%^BOLD%^%^BLACK%^, giving it a pale "+
		"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^"+
		"y%^BOLD%^-%^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e "+
		"%^BOLD%^%^BLACK%^hue.  The thin flexible blade is honed to a "+
		"fine point.  Merging with the basket hilt, the blade forms a "+
		"seamless bond.  Composed of a %^WHITE%^tw%^CYAN%^i%^WHITE%^ning"+
		"%^BOLD%^%^BLACK%^ pattern, the basket hilt displays an "+
		"elaborate be%^RESET%^%^BLUE%^j%^BOLD%^%^BLACK%^ew%^RESET%^"+
		"%^MAGENTA%^e%^BOLD%^%^BLACK%^led swan.  Glittering marquise "+
		"cut black diamonds are mounted onto the hilt, forming the body"+
		" of the graceful swan.  A %^RESET%^%^BLUE%^blue%^BOLD%^%^BLACK%^"+
		"-%^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^ sheen shimmers off "+
		"the surface of the diamonds, breaking up the darkness.  "+
		"Fashioned from %^BLUE%^shadowtop%^BOLD%^%^BLACK%^ wood, the grip "+
		"of the rapier is laced with filigree %^BOLD%^%^WHITE%^palladium"+
		"%^BOLD%^%^BLACK%^, mirroring the twining pattern of the hilt.  "+
		"A rounded egg shaped orb of %^BOLD%^%^WHITE%^palladium%^BLACK%^ "+
		"is attached to the end of the grip, providing a perfect "+
		"counterbalance to the blade.  Though richly ornate, the rapier "+
		"retains a dangerous and deadly feel.%^RESET%^");
	set_lore("Though many assume that the Black Swan is a rapier made for "+
		"malice and evil, nothing could be further from the truth.  "+
		"Many vile faiths seem to hold the black diamond as a sacred "+
		"stone, with the most notable being the faithful of the "+
		"Nightsinger and the Lord of Darkness.  This evil overtone"+
		"is not the case with Black Swan.  The Black Swan was fashioned"+
		" as a gift - or reward - to a human man named Olimar Vesspris."+
		"  Olimar was a dedicated protector body guard to the Regent "+
		"Princess, Yeshlana, The Rose of Antioch.  Olimar was thought by"+
		" many to be a maverick because he refused to wear the"+
		"+ cumbersome plate mail that the guards and soldiers of Antioch"+
		" favor.  Instead he favored the use of light armor and trained"+
		" in the ways of Tormish swordplay.  His twin rapier style was "+
		"tested many times in his duty as the bodyguard for the Rose of"+
		" Antioch.  The Black Swan image was created as a tribute to the"+
		" royal signet of Yeshalan, a black swan.  The rapier was"+
		" crafted for Olimar at her request, after he bravely fought back"+
		" five would-be kidnappers.  The fate of Yeshalan and Olimar, "+
		"though, is a sad tale - one best saved for another day. - With "+
		"Steel, I Protect - by Tharlon Wyvernstooth");
	set_property("lore",13);
  	set_value(4000);
     	set_property("enchantment",4);
   	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
      set_item_owner_prop("multiple_owners",1);

}
void init(){
        ::init();
        if(!interactive(ETO)) return;
        TO->add_item_owner(ETOQN);
}

int wield_func(string str) {
object *weapons;
weapons = ETO->query_wielded();
   if(sizeof(weapons)){
      if(weapons[0]->id("Black Swan")){
         	tell_object(ETO,"%^MAGENTA%^You may not wield two such "+
            	"exquisite rapiers at once!");
      return 0;
      }
   }
	tell_object(ETO,"%^BOLD%^%^BLACK%^The rapier feels balanced and "+
		"light in your hands.");
   	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Light reflects off "+
		"the bejeweled black swan on "+ETOQCN+"'s rapier.",ETO);
     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^%^BLACK%^Your hand relaxes from the grasp"+
		" of the rapier.");
   	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" relaxes "+
		""+ETO->QP+" grasp from "+ETO->QP+" rapier.",ETO);
      	if(ETO->query_property("damage resistance")){ 
          		ETO->remove_property("damage resistance");
            }
     	return 1;
}

int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   	
	if(!random(8)) {
  		tell_object(ETO,"%^BOLD%^%^BLACK%^Feining to the left, you "+
			"vere to the right and pierce "+victim->QCN+".");
      	tell_object(victim,"%^BOLD%^%^BLACK%^"+ETO->QCN+" feins to "+
			"the left before "+ETO->QS+" suddenly veres to the right"+
			", slipping past your guard.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" feins"+
			" to the left before "+ETO->QS+" suddenly veres to the right,"+
			" slipping past "+victim->QCN+"'s guard.",({ETO,victim}));
       			//victim->do_damage(victim->return_target_limb(),random(4)+2);
		return roll_dice(1, 6);	
	}
	if(!random(16)) {
        if(ETO->query_property("damage resistance")){       	
		tell_object(ETO,"%^BLUE%^You drop your defensive stance and "+
			"lunge at "+victim->QCN+", sinking the tip of your blade"+
			" deep into "+victim->QO+".");
      	tell_object(victim,"%^BLUE%^"+ETO->QCN+" drops "+ETO->QP+" "+
			"defensive stance and lunges at you!");
      	tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" drops "+
			""+ETO->QP+" defensive stance and lunges at"+
			" "+victim->QCN+"!",({ETO,victim}));
                                ETO->remove_property("damage resistance");
                        ETO->set_parrying(0);
				//victim->do_damage(victim->return_target_limb(),random(4)+4);
      	return roll_dice(1, 8);
	   }else{
           	tell_object(ETO,"%^MAGENTA%^Stepping into a defensive stance,"+
			" parrying "+victim->QCN+"'s blows.");
      	tell_object(victim,"%^MAGENTA%^"+ETO->QCN+" steps into a"+
			" defensive stance, parrying your blows!");
      	tell_room(environment(ETO),"%^MAGENTA%^"+ETO->QCN+" steps "+
			"into a defensive stance, parrying"+
			" "+victim->QCN+"'s attacks.",({ETO,victim}));
				ETO->set_property("damage resistance",10);
                        ETO->set_parrying(1);
		return 0;
	   }
	}
    return 0;
 }
