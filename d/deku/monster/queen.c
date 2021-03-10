//Modified by saide - uses spells more often and uses darkbolt 
//now - more powerful and more exp
#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("Darkelf Queen");
  set_id(({"queen","darkelf","darkelf queen"}));
   set_race("drow");
  set_gender("female");
  set_short("%^BOLD%^%^BLACK%^A female drow with %^BOLD%^%^WHITE%^"+
  "silver hair%^RESET%^");
  set_long("This jet black skinned female drow clearly commands attention "
	"in this room.  Her silver hair flows about her body, ending about mid "
	"thigh.  She is dressed in an open weave silver bodysuit that has been "
	"fashioned to look like spider webbing.  Jewelled spiders hang from "
	"mithril chains from the bodysuit.  An evil grin crosses her lips as "
	"she looks down from her throne at you.  She is the matron of the "
	"matrons and clearly not to be trifled with.");
  set_class("cleric");
  set_guild_level("cleric",15 + random(6));
  set_mlevel("cleric",query_guild_level("cleric"));
  set("aggressive",20);
  set_alignment(9);
  set_size(2);
  set_hp(query_guild_level("cleric") * 10 + random(31));
  set_exp(query_max_hp() * 35);
  set_stats("dexterity",19);
  set_stats("strength", 16);
  set_stats("constitution", 13);
  set_stats("wisdom", 19);
  set_stats("intelligence", 18);
  set_stats("charisma",17);
  new("/d/deku/weapons/whip2")->move(TO);
  command("wield whip");
  new("/d/deku/armours/ring")->move(TO);
  command("wear ring");
 // new("/d/deku/armours/cloak1")->move(TO);
  //command("wear cloak");
  new("/d/common/obj/armour/chain")->move(TO);
  command("wear chain");
  new("/d/deku/misc/hstone")->move(TO);
  add_money("gold",250);
  set_funcs(({"crack","rub"}));
  set_func_chance(30);
  set_spell_chance(70);
  set_spells(({"hold person","darkbolt","flame strike",
  "cause critical wounds"}));
  set_overall_ac(1);
  set_mob_magic_resistance("average");
}

void crack(object vic){
  if(present(vic,ETO)){
    force_me("crack "+vic->query_name());
  }
  else {
  vic->do_damage("torso",random(20)+1);
  tell_object(vic,"Darkelf Queen hits you.");
  }
}

void rub() {
  force_me("rub stone");
}
