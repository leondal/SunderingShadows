//Updated desc as provided by Gregor - Cythera 6/05\\

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/d/common/obj/weapon/dagger.c";

int chips;
void create(){
  ::create();
  	set_name("stone dagger");
  	set_id(({"stone dagger","dagger","Dagger","Stone dagger","obsidian dagger"}));
  	set_short("%^BOLD%^%^BLACK%^Obsidian Dagger%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^An obsidian dagger%^RESET%^");
  	set_long("%^BOLD%^%^BLACK%^This small dagger is has been "+
		"crudely fashioned out of a shard of obsidian with a "+
		"%^BOLD%^%^WHITE%^bone%^BLACK%^ handle. The obsidian has"+
		" a %^RESET%^%^BLUE%^dark %^BOLD%^%^BLACK%^%^gl%^WHITE%^oss"+
		"%^BLACK%^y %^WHITE%^sheen%^BLACK%^ to it, having been "+
		"%^RED%^h%^RESET%^%^RED%^ea%^BOLD%^t%^RESET%^%^RED%^e%^BOLD%^d"+
		"%^BOLD%^%^BLACK%^ before fashioned into the blade of the "+
		"dagger, and has been hewn to an extremely sharp edge. "+
		"It has been attached to a bone handle, uniquely carved to "+
		"fit perfectly into your hand offering a strong grip.");
	set_lore("Crafted from cooled lava, the obsidian dagger is just one "+
		"of the tools the natives of Tonnera use to protect themselves"+
		" from the dangers of the forest.  The natives whisper that the"+
		" dagger is more than just a simple blade, that their enchantress"+
		" imbues the spirit of island into each dagger, to aid the natives."+
		"  Every male on the island at the age of 15 undergoes a series of "+
		"rites and quests before they are allowed to be called a man.  The "+
		"dagger is given only to those who have earned the right to be called"+
		" a man. - Five Years in Tonerra: Observations of the Natives - Timmon Bigspy");
	set_property("lore",13);
	//set_type("piercing");
  	set_wc(1,5);
  	set_large_wc(1,6);
  	set_hit((:TO,"hit_me":));
  	//set_size(1);
  	set_weight(5);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
  	set_property("enchantment",3);
  	set_value(100);
}
int wieldme(){
		tell_object(ETO,"%^BOLD%^%^BLACK%^You grasp the bone"+
			" hilt of the dagger, the light reflecting off "+
			"the dark surface of the blade.");
		return 1;
}
int removeme(){
		tell_object(ETO,"%^BOLD%^%^BLACK%^You ungrasp the bone hilt of the dagger.");
		return 1;
}

int hit_me(object targ){
  int i;
  object ob;
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;
        if((random(100) < 2 && !interactive(ETO)) || random(100) < 2){
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you plunge the stone"+
		" dagger into "+targ->QCN+" a small chip breaks off "+
		"and embeds itself into "+targ->QP+" flesh.");
	tell_object(targ,"%^BOLD%^%^RED%^As "+ETO->QCN+" plunges "+
		"the stone dagger into you a small chip breaks off and embeds "+
		"itself into your flesh.");
    		targ->do_damage("torso",roll_dice(2,3));
    		ob = new(OBJ+"stonechip");
 		ob->move(targ);
                if(objectp(ob) && objectp(targ)) { ob->hurt(targ); }
  }
  return 0;
}
