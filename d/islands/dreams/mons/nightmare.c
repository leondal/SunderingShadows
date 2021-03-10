#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
      object ob;
	::create();
       	set_name("nightmare");
  	set_id(({"nightmare","night mare"}));
  	set_short("A snarling nightmare");
  	 set_long("%^RED%^A large, black steed lashes out in fury "+
   		"with flaming hooves.  His jet black coat looks as "+
   		"if it's stretched across the bones of his body.  A pair of "+
		"glowing red eyes can be seen through the clouds of smoke "+
		"that drift up from his nostrils with each deep breath.  "+
		"This creatures oversized head contains a mouth full of "+
		"sharp fangs.  The eyes seem to fix upon you, %^BOLD%^glowing "+
		"brightly in a rage of fury.%^RESET%^");
  	set_race("nightmare");
  	set_body_type("equine");
  	set_gender("male");
  	set_hd(30,2);
  	set_size(2);
  	set("aggressive",25);
    	set_class("fighter");
  	set_mlevel("fighter",30);
	set_max_level(37);
  	set_attack_limbs(({"right fore hoof","left fore hoof","mouth"}));
  	set_attacks_num(4);
  	set_base_damage_type("slashing");
  	set_damage(3,4);
  	set_hp(random(50)+550);
  	set_exp(10000);
  	set_overall_ac(-14);
  	set_alignment(6);
  	set_property("no hold",1);
  	set_mob_magic_resistance("average");
  	set_property("no paralyze",1);
  	set_property("no dominate",1);
	set_property("no death",1);
  	set_funcs(({"breath"}));
 	set_func_chance(40);
  	set_emotes(10,({
        	"%^BOLD%^%^BLACK%^The nightmare glares at you, furious at your interference.",
        	"%^RED%^The nightmare's hooves burn with a magical flame.",
		"%^RED%^A cloud of smoke rises up from the nightmares flaring "+
		"nostrils."
    	}),1);
    if(!random(10)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("dream fragment");
      ob->move(TO);
    }
}

void breath(object targ)
{
	int i,j;
  	object *inven;
	inven = all_living(ETO);
  	j = sizeof(inven);

  	tell_room(ETO,"%^ORANGE%^The nightmare exhales loudly, filling "+
		"the room with a thick, burning cloud of smoke!%^RESET%^");
  	for(i=0;i<j;i++)
	{
    	if(!objectp(inven[i])) continue;
    	if(inven[i] == TO) continue;

    		tell_object(inven[i],"%^BOLD%^%^BLACK%^The smoke surrounds"+
			" you, you try not to breath it in but you can't help it.");
    	if(!"daemon/saving_d"->saving_throw(inven[i],"paralyzation_poison_death",-2))
    	{
      	tell_object(inven[i],"%^BOLD%^%^BLACK%^The smoke stings your eyes and burns "+
      		"your lungs!  You try to escape but you can't stop choking "+
      		"long enough to move.");
      	inven[i]->set_blind(1);
      	inven[i]->set_paralyzed((random(7)+4),"%^ORANGE%^You are choking "+
      		"on the fumes from the nightmare's breath.");
 	}
    	else 
    	{
      	tell_object(inven[i],"%^RED%^You manage to hold your breath for a "+
		"moment...but dash out of the area to avoid breathing in "+
	  	"anymore of the fumes.");
      	inven[i]->force_me("south");
    	}
	}
}
void die(object ob)
{
	new(OBJ"gcryst")->move(TO);
	new(OBJ"hornlance")->move(TO);
	tell_room(ETO,"%^BOLD%^The unicorn trots over to the corpse of the"+
		" nightmare.  Her horn begins to glow softly as she touches it"+
		" to the corpse.  She tosses her head back and races off into "+
		"the woods, leaving a token behind.");
	::die(ob);
}
