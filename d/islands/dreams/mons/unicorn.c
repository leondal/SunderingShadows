#include <std.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
      object ob;
  	::create();
  	set_name("unicorn");
  	set_id(({"unicorn","dream mon"}));
  	set_short("%^BOLD%^%^WHITE%^A regal unicorn%^RESET%^");
  	set_long("%^BOLD%^%^WHITE%^This regal looking creature is "+
		"glistening with "+
		"sweat.  She resembles a large, well groomed horse, with "+
		"a solid white coat.  Aside from her size, the only real "+
		"difference is the large, shimmering horn that spirals "+
		"from the top of the creatures head.  While she is "+
		"obviously tired after her drawn out battle with the "+
		"nightmare, she glares at you with stern determination.  "+
		"Your interference let her arch rival escape, and she seems "+
		"intent upon making you pay.%^RESET%^");
  	set_race("unicorn");
  	set_body_type("equine");
  	set_gender("female");
  	set_hd(30,2);
  	set_size(2);
  	set("aggressive",25);
  	set_class("fighter");
  	set_mlevel("fighter",30);
	set_max_level(37);
  	add_limb("horn","head",0,0,0);
  	set_attack_limbs(({"right fore hoof","left fore hoof","horn"}));
  	set_attacks_num(3);
  	set_base_damage_type("slashing");
  	set_damage(2,5);
  	set_hp(random(25)+500);
  	set_exp(10000);
  	set_overall_ac(-14);
  	set_alignment(4);
  	set_property("no hold",1);
  	set_mob_magic_resistance("average");
  	set_property("no paralyze",1);
  	set_property("no dominate",1);
	set_property("no death",1);
  	set_funcs(({"charge"}));
  	set_func_chance(65);
  	set_emotes(10,({
     		"%^BOLD%^The unicorn glares at you, furious at your interference.",
     		"%^BOLD%^The unicorn's large nostrils flare in anger.",
		"%^YELLOW%^The unicorn's golden horn seems to pulse with a mystical "+
			"light."
    	}),1);
    if(!random(10)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("dream fragment");
      ob->move(TO);
    }
}

void charge(object targ)
{
  switch(random(20)) 
  {
    case 0..4:
      tell_room(ETO,"%^YELLOW%^The unicorn takes a few steps back, and "+
        "briefly closes her eyes in concentration.  Her horn suddenly "+
	  "flares in a bright light that quickly surrounds the creature.  "+
        "As her eyes open, she looks upon you with a renewed "+
	  "vigour.%^RESET%^");
      TO->do_damage("torso",(-1)*roll_dice(10,4));
      break;
    case 5..9:
      tell_object(targ,"%^YELLOW%^The unicorn lowers her head and rushes "+
        "towards you, her golden horn leveled at your torso.\n"+
	  "As you dodge to the side, the unicorn manages to suddenly "+
	  "stop on her front legs.  With an audible grunt, she springs "+
	  "backwards, lashing her rear legs out with a tremendous "+
	  "amount of force.\n"+
	  "Her hooves slam into your chest, cracking ribs and sending "+
	  "you flipping through the air.%^RESET%^");
      tell_room(ETO,"%^CYAN%^As "+TQCN+" dodges to the side, the "+
	  "unicorn suddenly stops, spins slightly and crushes "+
	  ""+targ->query_objective()+" with a mighty blow from her "+
	  "hind legs.  "+TQCN+" flips backwards through the air, landing "+
	  "roughly several yards away.%^RESET%^",targ);
      targ->do_damage("torso",roll_dice(5,5));
      break;
    case 10..14:
      tell_object(targ,"%^BOLD%^The unicorn lowers her head and rushes "+
        "towards you, her golden horn leveled at your torso.\n"+
        "You scream in pain as the horn pierces into your shoulder.  "+
	  "You feel your self rise up off the ground as the creature "+
	  "shakes her head vigerously side to side.  With a final thrust "+
	  "of her head, the unicorn toss you to the side and you crash "+
	  "into a nearby pine tree.%^RESET%^");
      tell_room(ETO,"%^CYAN%^The unicorn lowers her head and rushes "+
	  "towards "+TQCN+", piercing "+targ->query_possesive()+" shoulder.  "+
        ""+TQCN+" is slung from side to side before the unicorn flings "+
	  ""+targ->query_objective()+" into a nearby pine tree.%^RESET%^",targ);
      targ->do_damage("torso",roll_dice(6,6));
      break; 
    case 15..19:
      tell_object(targ,"%^CYAN%^The unicorn raises up on her hind legs, "+
	  "and lashes out fiercly with her fore hooves.  The blow to "+
	  "your shoulder spins you around!%^RESET%^");
      tell_room(ETO,"%^CYAN%^The unicorn suddenly rises up on her "+
	  "hind legs, lashing out at "+TQCN+", spinning him around."+
	  "%^RESET%^",targ);
      targ->do_damage("torso",roll_dice(5,4));
      break;      
  }
}
void die(object ob)
{
	new(OBJ"gcryst")->move(TO);
	new(OBJ"nightlance")->move(TO);
	tell_room(ETO,"%^RED%^The nightmare trots over to the corpse of the"+
		" unicorn.  Raising a hoof up, he breaks off the unicorn's horn."+
		"  With a gruff snort, the nightmare releases a thick cloud of smoke"+
		" that wraps around the horn.  He tosses his head back and races"+
		" off into the woods, leaving his token behind.");
	::die(ob);
}
