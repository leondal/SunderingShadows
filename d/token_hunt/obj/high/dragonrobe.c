//Modified and added to high vendor - Octothorpe 4/28/10
//for Selune.  Fixed slightly by Circe 8/3/04
#include <std.h>

inherit "/d/common/obj/clothing/magerobe";

object ARMO;

void create(){
     ::create();
     set_heart_beat(1);
     set_name("dragonrobes");
     set_id(({"robe","robes","dragonrobe","dragonrobes","scaled stormrobes"}));
     set_obvious_short("%^GREEN%^an unusual scaled robe%^RESET%^");
     set_short("%^RESET%^%^CYAN%^Scaled Dragonrobes%^RESET%^");
     set_long("%^CYAN%^This unusual robe is made of shiny scales "+
	    "that have a fine, %^BOLD%^glossy %^RESET%^%^CYAN%^look to "+
		"them.  Each scale is small and perfectly shaped, looking "+
		"almost like a tiny shield.  Still, the robe is soft and "+
		"supple to the touch and seems to enhance the form of the "+
		"wearer, no matter his normal shape.  Strangely, the robe "+
		"seems to shift in %^BOLD%^%^RED%^c%^YELLOW%^o%^GREEN%^l"+
		"%^CYAN%^o%^BLUE%^r%^RESET%^%^CYAN%^, taking on all hues "+
		"from a %^BOLD%^%^BLACK%^deep black %^RESET%^%^CYAN%^to a "+
		"%^BOLD%^%^WHITE%^brilliant white%^RESET%^%^CYAN%^, f%^BOLD%^"+
		"l%^RESET%^%^CYAN%^i%^BOLD%^t%^RESET%^%^CYAN%^t%^BOLD%^i"+
		"%^RESET%^%^CYAN%^n%^BOLD%^g %^RESET%^%^CYAN%^through all "+
		"the %^BOLD%^%^RED%^s%^RESET%^%^ORANGE%^h%^YELLOW%^a%^GREEN%^"+
		"d%^CYAN%^e%^BLUE%^s %^RESET%^%^CYAN%^in between.  The unusual "+
		"construction and %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^"+
		"m%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g %^CYAN%^colors "+
		"%^RESET%^%^CYAN%^make it a wonder to behold.%^RESET%^");
     set_lore("This unusual robe is actually not a robe at all!  "+
        "You realize it is a pseudodragon in disguise, allowing "+
        "itself to be worn as a robe by its master.  How strange that "+
        "someone could tame such a creature so much that it would "+
        "bond so wholly with the wearer.  Looking closely, you "+
        "see that the pseudodragon drapes its iridescent wings "+
        "around the wearer, giving it the illusion of a robe.");
     set_ac(0);
     set_weight(10);
   set_value(0);
	 set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("magic resistance",2);
      set_item_bonus("sight bonus",2);
     set_type("clothing");
     set_limbs(({"torso"}));
     set_max_internal_encumbrance(21);
     set_wear((:TO,"wear_it":));
     set_remove((:TO,"remove_it":));
     set_struck((:TO,"struck":));
	set_overallStatus(220);
    set_property("no disenchant",1);
}

int wear_it(){
	if((int)ETO->query_highest_level() < 30){
	    tell_object(ETO,"%^CYAN%^The robe sniggers at one so puny "+
             "trying to wear it.");
       tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s robes seem to mock "+
             ""+ETO->QO+" with a flap of a fold and the faint "+
             "sounds of sniggering coming from somewhere within.",ETO);
	    return 0;
	}
      tell_room(EETO,"%^BOLD%^%^RED%^M%^RESET%^%^ORANGE%^u%^YELLOW%^l"+
         "%^GREEN%^t%^CYAN%^i%^BLUE%^-%^WHITE%^c%^BLUE%^o%^CYAN%^l"+
         "%^GREEN%^o%^YELLOW%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^d "+
         "%^CYAN%^lights %^BLUE%^dance across the scales as "+ETOQCN+" "+
         "wears the robe.",ETO);
      tell_object(ETO,"%^BOLD%^%^RED%^M%^RESET%^%^ORANGE%^u%^YELLOW%^l"+
         "%^GREEN%^t%^CYAN%^i%^BLUE%^-%^WHITE%^c%^BLUE%^o%^CYAN%^l"+
         "%^GREEN%^o%^YELLOW%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^d "+
         "%^CYAN%^lights %^BLUE%^dance across the scales as you "+
         "wear the robe.\n%^WHITE%^You hear a soft purr from inside.");
	set_heart_beat(1);
	return 1;
}

int remove_it(){
    tell_object(ETO,"%^RESET%^%^RED%^The scales lose their luster "+
       "and go dark as you remove the robe.");
    tell_room(EETO,"%^RESET%^%^RED%^The robe stops shifting and "+
       "changing colors as "+ETOQCN+" removes them.",ETO);
     return 1;
}

int struck(int damage, object what, object who){
   if(!(random(2))){
       tell_room(environment(query_worn()),"%^RESET%^%^CYAN%^"+ETOQCN+"'s "+
          "robes suddenly shift of their own accord knocking "+who->QCN+"'s "+
          "blow off balance!",({who,ETO}));
       tell_object(who,"%^RESET%^%^CYAN%^As you try to hit "+ETOQCN+", "+
          "a shadowed dragon-like figure from "+ETO->QP+" robe knocks "+
          "you off balance, making your blow less effective!");
       if(!random(4)){
          tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A "+
             "shadowed dragon's head bites at "+who->QCN+" as "+
             ""+who->QS+" touches the robe!",who);
          tell_object(who,"%^BOLD%^%^BLACK%^A shadowed dragon's head "+
             "sinks its teeth into your flesh!");
          who->cause_typed_damage(who, "torso", roll_dice(1, 25) + 24, "piercing");
       }
   return (damage*(1/2));
   }
   return damage;
}

void heart_beat(){
     object owner,env;
	 int i,xx,yy;
     env = ETO;
     if(!objectp(ETO))return ;
     if(objectp(env) && living (env)){
       owner=env;
       env=environment(owner);
     }
     if((!(TO->query_worn())) || (ETO->query_invis())){
       return;
     } else {
       xx=random(1000);
       yy=random(6)+1;
     if((xx>998)){
        tell_object(owner,"\n%^CYAN%^The robe flaps restlessly as "+
           "the %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l"+
           "%^GREEN%^o%^CYAN%^r%^BLUE%^s %^RESET%^%^CYAN%^shift "+
           "within its scales.\n");
     if(yy==1){
        tell_room(env,"%^GREEN%^"+owner->QCN+"'s robe billows out, and "+ 
           "the %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l"+
           "%^GREEN%^o%^CYAN%^r%^BLUE%^s %^RESET%^%^CYAN%^shift "+
           "within its scales.\n",owner);
     }
     if(yy==2){
       tell_room(env,"%^BOLD%^%^GREEN%^M%^CYAN%^u%^BLUE%^l%^CYAN%^t"+
          "%^GREEN%^i%^CYAN%^-%^BLUE%^c%^CYAN%^o%^GREEN%^l%^CYAN%^o"+
          "r%^BLUE%^e%^CYAN%^d %^YELLOW%^lights %^GREEN%^shimmer "+
          "across the scales that make up "+owner->QCN+"'s robe.",owner);
     }
     if(yy==3){
        tell_room(env,"%^BOLD%^%^CYAN%^One of the scales falls to "+
           "the floor and another takes its place within the robes "+
           "as that one is blown away from "+owner->QCN+"'s presence.",owner);
     }
     if(yy==4){
        tell_room(env,"%^BLUE%^"+owner->QCN+" fades temporarily "+
           "from view as the robe loses all color but comes back "+
           "into focus just as quickly as the robe begins to %^BOLD%^"+
           "s%^RESET%^%^BLUE%^h%^BOLD%^i%^RESET%^%^BLUE%^m%^BOLD%^m"+
           "%^RESET%^%^BLUE%^e%^BOLD%^r %^RESET%^%^BLUE%^once again "+
           "around "+owner->QO+"!",owner);
     }
     if(yy==5){
        tell_room(env,"%^CYAN%^As "+owner->QCN+"'s robe begins to "+
           "shift, it stops suddenly and you could swear that "+
           "something is peering back at you!",owner);
     }
     if(yy==6){
        tell_room(env,"%^BOLD%^YELLOW%^A bright flash of light from "+
           ""+ETOQCN+"'s robe momentarily blinds you, making "+
           "spots form before your eyes!",owner);
     }
     if(yy==7){
        tell_room(env,"%^GREEN%^Something screeches from within "+
           ""+owner->QCN+"'s robe sending a chill down your spine!",owner);
//I don't think yy will ever equal 7, but leaving it anyway
     }
   }
   return;
 }
}