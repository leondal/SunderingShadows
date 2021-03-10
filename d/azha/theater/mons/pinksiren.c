#include <std.h>
#include "../theater.h"

inherit "std/monster";
      void create(){
      object obj; 
      ::create();
	set_name("cacophony sirine");
	set_id(({"sirine", "cacophony sirine" , "theater_mon"}));
	set_short("%^BOLD%^%^BLUE%^A blue skinned "+
		"%^MAGENTA%^pink%^BLUE%^ haired sirine%^RESET%^");
	set_long("%^CYAN%^This exotic woman is a sirine.  Thou"+
		"gh unlike her aquatic counterpart this sirine has some"+
		" distinct differences.  Her smooth soft skin is a rich"+
		" %^BOLD%^%^BLUE%^ cobalt blue%^RESET%^%^CYAN%^ color, "+
		"which offsets her %^BOLD%^%^WHITE%^white pupilless "+
		"%^RESET%^%^CYAN%^eyes.  Vibrant shades of%^BOLD%^%^GREEN%^"+
		" green%^RESET%^%^CYAN%^, %^BOLD%^%^MAGENTA%^pink%^RESET%^"+
		"%^CYAN%^, and %^YELLOW%^gold%^RESET%^%^CYAN%^ covers"+
		" her eyelids and drop down her cheeks; adding to her "+
		"exotic beauty.  Her short %^BOLD%^%^MAGENTA%^intense pink"+
		"%^RESET%^%^CYAN%^ hair is teased wild locks that seem to"+
		" have a life of their own.  A %^YELLOW%^gold headdress"+
		"%^RESET%^%^CYAN%^ curls out of the wild mass of her hair,"+
		" the dangling charms on it swaying with her every "+
		"movement.  Her lithe slender figure is further accentuated"+
		" by the %^YELLOW%^gold metal top%^RESET%^ "+
		"%^CYAN%^she wears and the colorful silk leggings.  "+
		"%^ORANGE%^Golden%^CYAN%^ metal pointed caps top each of her fingers"+
		", giving a dangerous look to her exotic comeliness.  %^RESET%^");
	set_race("sirine");
	set_gender("female");
	set_body_type("human");
	set_hd(18,4);
	set_overall_ac(6);
	set_size(2);
	set_class("mage");
	set_mlevel("mage",18);
	set_class("fighter");
	set_mlevel("fighter",18);
	set_level(20);
	set_guild_level("mage",18);
	set_guild_level("fighter",18);
	set_stats("strength",17);
	set_stats("intelligence",15);
	set_stats("dexterity",18);
	set_stats("charisma",23);
	set_stats("constitution",16);
	set_stats("wisdom",12);
	set_alignment(6);
	set_mob_magic_resistance("average");
	set_spell_chance(40);
	set_spells( ({"sonic orb", "shout","vampiric touch"}) );
	set_property("full attacks",1);
	add_search_path("/cmds/mage");
	obj = new("/d/laerad/obj/bracers3");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	obj=new(OBJ"songblade");
if(random(6))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"goldtop");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"goldheaddress");
if(random(3))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj = new("/d/islands/pirates/weapon/longdagger.c");
	obj->set_property("monsterweapon",1);
	obj->set_property("enchantment",2);
	obj->move(TO);
	new("/d/darkwood/tabor/obj/c_leggings.c")->move(TO);
	command("wield rapier");
	command("wield dagger");
	force_me("wearall");
	add_money("electrum",random(75)+150);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(55)+270);
      set_hp(query_max_hp());
	set_speed(30);
	set_nogo(({ ROOMDIR"theater1",
			ROOMDIR"cat1",
			ROOMDIR"nest",
			ROOMDIR"prop3",
			ROOMDIR"backstage",
			ROOMDIR"cost5",
			ROOMDIR"calim8",
     	}));
      set_property("swarm",1);
      set("aggressive",16);
	set_exp(random(500)+2500);
	set_max_level(15);
	set_funcs( ({ "sing"}) );
	set_func_chance(20);
	set_languages( ({ "common" }) );
	set_emotes(2, ({"%^BOLD%^%^MAGENTA%^%^The cacophony siren"+
	" begins to sing a haunting wordless melody."}), 0);
	set_monster_feats(({"parry"}));
}
  void sing(object targ)
{
	if(!"/daemon/saving_throw_d.c"->will_save(targ,-15)){
	//if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon")) {
        	tell_object(targ,"%^MAGENTA%^The siren begins to "+
			"sing a cacophony of melodies, causing you"+
			" to wince in pain.");
        	tell_room(ETO,"%^MAGENTA%^The cacophony siren beg"+
			"ins to sing a cacophony of melodies directed "+
        		" at "+targ->query_cap_name()+", who winces in"+
			" pain at the sonic attack.",targ);
        	targ->cause_typed_damage(targ, "torso", roll_dice(1, 10) + 9, "sonic");
        	return 1;
	}
else {
    	tell_object(targ,"%^MAGENTA%^The siren begins "+
		" to sing a cacophony melodies, though you able to resist"+
		" most of the chaotic tune..");
     	tell_room(ETO,"%^MAGENTA%^The cacophony siren begins"+
		" to sing a cacophony of melodies at"+
       	 " "+targ->query_cap_name()+", who seems to shrug most"+
		" of it off",targ);
		targ->cause_typed_damage(targ, "torso", (roll_dice(1, 10) + 9)/2, "sonic");
     	return 1;
}
}