#include <std.h>
#include "../theater.h"
inherit WEAPONLESS;
   
  	void create(){
      object obj; 
      ::create();
	set_name("cloaker");
	set_id(({"cloaker", "monster", "theater_mon"}));
	set_short("A cloaker");
	set_long("%^GREEN%^With its cloak-like appearance, it's"
		" easy to see how these creatures earned their name.  "+
		"This cloaker's %^BLUE%^dark blue%^GREEN%^ back vaguely"+
		" has the look of supple leather.  The front of the creature "+
		"contrasts greatly with its unassuming appearance.  Its "+
		"%^BOLD%^%^WHITE%^stark white%^RESET%^%^GREEN%^ underbody "+
		"highlights the creature's %^BOLD%^%^RED%^blood vessels%^RESET%^"+
		"%^GREEN%^.  A pair of %^RED%^red%^GREEN%^ pupilless eyes look"+
		" menacing.  Though its three inch long %^RESET%^fangs%^GREEN%^"+
		" might help carry that menacing look, just a little.  Its "+
		"snake-like tongue runs across the fangs.  Looking like a "+
		"floating cloak, the cloaker moves as if flying.  On either "+
		"of its folds a seven inches long %^BOLD%^%^WHITE%^claw%^RESET%^%^GREEN%^"+
		" slices through the air.  A thicker claw in the same %^BOLD%^%^WHITE%^"+
		"stark white%^RESET%^%^GREEN%^ shade is attached to it's whip "+
		"like tail, slicing through the air with a mixture of strength"+
		" and speed.%^RESET%^");
	set_race("cloaker");
	set_gender("neuter");
	set_body_type("snake");
	set_overall_ac(-2);
	set_hd(20,4);
	set_class("fighter");
	set_class("cleric");
	set_mlevel("fighter",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_guild_level("cleric",20);
	set_guild_level("fighter",20);
	set_size(2);
	set_max_level(15);
	set_stats("strength",19);
	set_stats("intelligence",10);
	set_stats("dexterity",16);
	set_stats("charisma",12);
	set_stats("constitution",18);
	set_stats("wisdom",18);
	set_alignment(8);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	add_search_path("/cmds/cleric");
	remove_limb("left foot");
    remove_limb("right foot");
    add_limb("left fold","torso",0,0,0);
    add_limb("right fold","torso",0,0,0);
    add_money("electrum",random(200)+800);
	set_attack_limbs(({"tail"}));
	set_attacks_num(2);
	set_max_hp(random(50)+300);
    set_hp(query_max_hp());
    set_property("swarm",1);
    set("aggressive",18);
	set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(2,4);
	set_funcs(({"moan1","moan2"}));
	set_func_chance(50);
	set_spells(({ "fear","hold person","shout" }));
	set_spell_chance(30);
    set_exp(random(500)+4000);
	set_languages( ({ "common" }) );
	set_achats(10,({"%^BLUE%^The cloaker tries to wrap itself around you!" }));
	force_me("message in hovers in the air");
    force_me("message hovers $D");
}

void moan1(object targ)
{
    int i,j;
	object *inven;
	inven = all_living(ETO);
      inven -= ({TO});
      j = sizeof(inven);
		tell_room(ETO,"%^BLUE%^The cloaker begins to moan in a low "+
			"creepy voice.");
    		for(i=0;i<j;i++) {
              	if(!objectp(inven[i])) continue;
              	if(inven[i] == TO) continue;
              	//if(!"daemon/saving_d"->saving_throw(inven[i],"paralyzation_poison_death",-2)) {
				if(!"/daemon/saving_throw_d.c"->will_save(inven[i],-15)){
                        tell_object(inven[i],"%^BLUE%^Your are left"+
					" feeling uneasy and numb after the cloaker moans.");
                        		inven[i]->add_attack_bonus(-2);
                        			return 1;
			}
else {
  	tell_object(inven[i],"%^BLUE%^You are left feeling "+
		"slightly uneasy after the cloaker moans.");
              	return 1;
}
}
}
void moan2(object targ)
{
if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15)){
//if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
    	tell_object(targ,"%^BOLD%^%^BLUE%^The cloaker shrieks in a high "+
		"pitched creepy voice, leaving your ears ringing.");
      tell_room(ETO,"%^BOLD%^%^BLUE%^The cloaker opens it's fanged mouth"+
		" to release a high pitched shriek in a creepy voice. "+targ->QCN+" "+
		"winces from the pain of the high pitched noise.",targ);

	  targ->cause_typed_damage(targ, "torso", roll_dice(1, 5) + 6, "sonic");
        			return 1;
}
else {
    	tell_object(targ,"%^BOLD%^%^BLUE%^The cloaker shrieks in a high pitched"+
		" creepy voice, leaving your ears ringing for just a moment.");
     	tell_room(ETO,"%^BOLD%^%^BLUE%^The cloaker opens it's fanged mouth to "+
		"release a high pitched shriek in a creepy voice.  "+targ->QCN+" winces"+
		" from the pain of the high pitched noise.",targ);
		targ->cause_typed_damage(targ, "torso", roll_dice(1, 5) + 2, "sonic");
    				return 1;
}
}
void die(object obj) {
	switch(random(50)){
default:    
	obj = new("/d/antioch/valley/obj/jewelry.c")->move(TO);
break;
case 10..19:
	obj = new(OBJ"frogsuit")->move(TO);
break;
case 20..29:
	obj = new(OBJ"squirrelsuit")->move(TO);
break;
case 30..39:
	obj = new(OBJ"tabbycatsuit")->move(TO);
break;
case 40..49:
	new(OBJ"r_shoes")->move(TO);
break;
	}
	tell_room(ETO,"%^BOLD%^%^BLUE%^Knocking over a rack of "+
		"costumes as it dies, the cloaker falls to the floor.\n\n"+
		"%^MAGENTA%^The costumes are scattered into the air before"+
		" they settle onto the floor.");
    	::die(obj);
}
