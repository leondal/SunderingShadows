#include <std.h>
#include "../argabbr.h"
inherit "/d/common/obj/weapon/dagger.c";

void create(){
        ::create();
        set_name("%^ORANGE%^Gre%^GREEN%^e%^ORANGE%^n T%^GREEN%^i%^ORANGE%^de%^RESET%^");
        set_id(({ "dagger", "blade", "weapon", "green tide", "tide" }));
        set_short("%^ORANGE%^Gre%^GREEN%^e%^ORANGE%^n T%^GREEN%^i%^ORANGE%^de%^RESET%^");
        set_obvious_short("%^ORANGE%^A slime encrusted dagger%^RESET%^");
        set_long("%^ORANGE%^This dagger glistens slightly %^YELLOW%^yellow.  "+
		"%^RESET%^%^ORANGE%^It is covered in some kind of foul smelling"+
		" slime that is putrid to the nose.  "+
		"One could not wield it without getting "+
		"their hand covered in the %^RED%^stuff%^ORANGE%^.  The "+
		"blade itself looks rusted and dull.  "+
		"Surprisingly it is sharp, the off orange "+
		"just makes the  edge more %^RED%^serrated and "+
		"dangerous%^ORANGE%^.  There is a large %^RED%^red gem%^ORANGE%^ at "+
		"the pommel with a black marking causing "+
		"it to seem like an %^RED%^angry serpent's eye.%^RESET%^");



        set_value(5000);
        set_lore(
@AVATAR
'Forged from the soul of a dozen slain goblins, this dagger
seethes for revenge against all. 
AVATAR
        );
        set_property("lore",30);
        set_property("enchantment",4+random(2)); 
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
}
int wield_func(){
        tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" grabs the dagger "+
                "looks disgusted.",TP);
        tell_object(ETO,"%^GREEN%^You grab the dagger and"+
		" get your hand covered in slime.");
		ETO->set_property("evil item",1);
        return 1;
}
int unwield_func(){
        tell_room(EETO,"%^GREEN%^"+ETO->QCN+" releases the dagger and "+
                "wipes off their hand",TP);
        tell_object(ETO,"%^GREEN%^You release the"+
		" dagger and wipe the slime off your hand.");
		ETO->set_property("evil item",-1);
        return 1;
}
int hit_func(object targ){
 object swarm;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(member_array(ETO->query_race(),({"bugbear","gnoll","goblin","kobold","orc","hobgoblin" })) == -1) 
        return 1;
		
   if(random(1000) < 300){
        switch(random(8)){
        case 0..4:

                tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" "+
                        "stabs the slimey dagger sloppily into "+ETO->QP+" victim.",({ETO,targ}));
                tell_object(ETO,"%^RED%^You stab the dagger sloppily into"+
                        " your victim.");
                tell_object(targ,"%^RED%^"+ETO->QCN+" stabs the dagger sloppily"+
                        " into you leaving a slime covered wound.");
				targ->add_poisoning(20);
                                return roll_dice(2,8)+2;
        break;
        case 5..7:
               if(present("swarm",EETO))
			           return 1;
			   swarm = new(OBJ+"gobstorm");
			   swarm->move(EETO);
			   swarm->start_obj();
        break;
           }
        return 1;
      }
}
