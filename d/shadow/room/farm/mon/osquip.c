#include <std.h>
#include "../farm.h"

inherit WEAPONLESS;
      create(){
      object obj; 
      ::create();
	set_name("osquip");
	set_id(({"osqiup", "rodent", "farm_mon"}));
	set_short("A six legged osquip");
	set_long("%^YELLOW%^Resembling hairless rodents, "+
		"the osquip is ferocious territorial creature."+
		"  With it's six legs and yellow leathery skin "+
		"the osquip has a frightening presence.  It's "+
		"spade like teeth are so large that they poke "+
		"out of the creatures mouth.  Its brown eyes are"+
		" very small and set close together, each being "+
		"heavily protected by surrounding ridges of bone."+
		" Its jaws are unusually large, the entire bony "+
		"structure projecting several inches forward of "+
		"the flesh.%^RESET%^");
	set_race("osquip");
	set_gender("female");
	set_body_type("quadruped");
	set_overall_ac(5);
	set_hd(10,0);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_level(10);
	set_guild_level("fighter",10);
	set_size(2);
	set_max_level(15);
	set_stats("strength",18);
	set_stats("intelligence",10);
	set_stats("dexterity",15);
	set_stats("charisma",8);
	set_stats("constitution",18);
	set_stats("wisdom",10);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	set_damage(1,5);
  	set_attacks_num(2);
  	set_base_damage_type("piercing");
  	add_limb("teeth", "head", 0, 0, 0);
  	set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
     	set_funcs(({"biteit"}));
	set_func_chance(50);
	set_speed(20);
	add_money("silver",random(100)+10);
	add_money("electrum",random(30)+10);
	add_money("gold",random(20)+10);
	set_max_hp(random(30)+75);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",18);
	add_attack_bonus(2);
	set_nogo(({ ROOMDIR"work7",
			ROOMDIR"work6",
			ROOMDIR"work5",
			ROOMDIR"work4",
			ROOMDIR"work3",
			ROOMDIR"work2",
			ROOMDIR"work1",}));
	set_exp(random(100)+500);
	set_languages( ({ "common" }) );
}
void lickit(object targ)
{
    		tell_object(targ,"%^ORANGE%^The osquip "+
			"bites down on your flesh, digging in deep with its large teeth.");
     		tell_room(ETO,"%^ORANGE%^The osquip bites down on "+
			""+targ->QCN+"'s flesh.",targ);
    				targ->do_damage("neck",random(8)+2);
        	return 1;
}
void die(object obj) {
	switch(random(50)){
		case 0..13:
			new(OBJ"osquipcloak")->move(TO);
		break;
		case 14..20:
			obj = new("/d/common/obj/misc/gem.c")->move(TO);
			obj = new("/d/common/obj/misc/gem.c")->move(TO);
		break;
		case 21..49:
			obj = new("/d/common/obj/misc/gem.c")->move(TO);
		break;
		default:
		break;
}
	tell_room(ETO,"%^YELLOW%^The osquip screeches as it dies.");
    	::die(obj);
}
