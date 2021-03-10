//Updated Desc, Code, Lore, and Added in the 
//heartbeat function so people notice how
// icky it is - Cythera 8/05
// updated cha bonus from the new system. Nienne, 09/07.
// also fixed AC bonus moved to enchant... musta missed this one.
#include <std.h>
#include "/realms/grendel/grendel.h"
inherit "/std/armour";

create() {
    ::create();
    set_name("%^RED%^sanguine red robe%^RESET%^");
    set_id(({"robe", "bloodrobe", "red robe","robe of the blood","blood robe"}));
    set_short("%^RESET%^%^RED%^Robe of the %^BOLD%^%^RED%^B%^RESET%^"+
        "%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^A sanguine red robe%^RESET%^");
    set_long("%^RED%^This moist and damp robe has a warmth to it.  "+
	"The sanguine red cloth almost seems to move on its own.  The"+
	" deep red cloth has been shaped into a simple robe, with long"+
	" sleeves and loose fit.  The hem of the robe brushes against "+
	"the ground, but it never seems to tatter or rip.  In fact you "+
	"can't find any stitches or seams on this robe.  It's almost as "+
	"if it had been magically shaped...from blood!%^RESET%^\n");
    set_lore("The Robe of the Blood has been a garment used by many "+
	"sinister and violent folk down through the ages.  Followers of"+
	" Malar and Loviatar particularly favor the robes for its look "+
	"and the terror it causes others.  One ranger of Malar named "+
	"Garlam provided one of the more infamous stories about these "+
	"garments.  Garlam was rumored to be inflicted with lycanthrope,"+
	" bitten by a werewolf.  Instead of seeking a cure or thinking "+
	"himself cursed as any sane person would, Garlam saw it as a "+
	"blessing from Malar.  In his werewolf and human forms Garlam's"+
	" favorite thing was to feast on the blood of his prey, claiming"+
	" the warm life fluid provided him with strength and vigor.  "+
	"Undertaking an unholy quest in the name of Malar, Garlam hunted"+
	" and preyed on unicorns, dryads, and followers of Mielikki.  For"+
	" as much bloodthirsty havok he caused to the Unicorn Goddess, "+
	"Malar was said to have blessed him with a robe made from the blood"+
	" of his prey.  Garlam though met his end at the hand of a lycanthrope"+
	" slayer of Selune.");
    set_weight(4);
    set_value(50);
    set_type("clothing");
    set_limbs(({"torso"}));
//    set_ac(1);
    set_property("enchantment",3);
    set_wear((:this_object(), "extra_wear":));
    set_remove((:TO,"removeme":));
    set("chabonus",-1);
}

int extra_wear(){
    if(is_good(ETO)){
      tell_object(ETO, "%^BOLD%^You get all squeemish at the thought of wearing "+
		"the blood of innocently slain beasts.");
      return 0;
    }
    if((int)ETO->query_highest_level()<20){
	tell_object(TP, "%^BOLD%^%^RED%^The robe sucks the blood from your body as you"+
		" wrap it around yourself!!\n");
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" howls in pain as the "+
		"sanguine robe leeches blood from "+ETO->QO+".",ETO);
			ETO->do_damage("torso", roll_dice(5,5));
	if(!random(3)){
	    tell_object(ETO, "%^BOLD%^%^RED%^The bloodrobe denies you!");
	    TO->remove();
	return 0;
	}
    		TP->add_attacker(TO);
    		TP->continue_attack();
    		TP->remove_attacker(TO);
    	}else{
	tell_object(TP, "%^BOLD%^%^RED%^You wrap the robe around you, "+
		"feeling it pulse in rhythm to your heart.");
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" wrap "+ETO->QO+"self "+
		"inside the sanguine red robe.  The robe seems to pulse and"+
		" flow about "+ETO->QO+".",ETO);

   		ETO->set_property("evil item",1);
                TO->set_heart_beat(1);
    	return 1;
        }
}

int removeme() {
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" pulls off"+
		" the sanguine red robe with a sickening squishing sound.",ETO);
      tell_object(ETO,"%^RED%^The robe makes a sickening squishing "+
		"sound as you pull it off.");
			ETO->set_property("evil item",-1);
                        TO->set_heart_beat(0);
   	return 1;
}
void heart_beat(){
   object owner,env;
   int i,xx,yy;
  env= ETO;
   if(!objectp(ETO))return ;
   if(objectp(env) && ETO->is_player()){
      owner=env;
      env=environment(owner);
   }
   if((!(TO->query_worn())) || (ETO->query_invis())){
      return;
   }
   else
   {
   xx=random(500);
   yy=random(4);
   if((xx>495)){
   if(yy==0){
	tell_object(owner,"\n%^RED%^Drops of blood fall from the"+
        " robe onto the ground.");
	tell_room(env,"%^RED%^Drops of blood fall from"+
		" "+owner->QCN+"'s robe onto the ground.",owner);
   }
   if(yy==1){
   tell_object(owner,"\n%^RED%^The hem of your robe drags "+
		"along the ground creating a trail of blood.\n");
	tell_room(env,"%^RED%^The hem of "+owner->QCN+"'s robe"+
		" drags along the ground creating a trail of blood.",owner);
   }
   if(yy==2){
   tell_object(owner,"\n%^RED%^A pool of blood collects at your feet.\n");
	tell_room(env,"%^RED%^A pool of blood collects at"+
		" "+owner->QCN+"'s feet, dripping off of "+owner->QP+" robe.",owner);
   }
   if(yy==3){
   tell_object(owner,"\n%^RED%^A coppery metallic scent rises off of the robe.\n");
	tell_room(env,"%^RED%^The coppery metallic scent of fresh blood rises off of"+
		" "+owner->QCN+"'s robe.",owner);
   }
      return;
  }
  }
}
