//cut exp. from 7850 to 3500 and added random(25) hp - it is a key cycler point,
//has 1/2 the hp of Feywing and less AC, even less than Jarrow
//also set max_level(15)  *Styx* 7/22/01
//updated to make exp somewhat more random and dependant on hps 
//Saide 01/01/04

#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("giant");
  set_id( ({"giant", "cloud", "cloud giant"}) );
  set_race("giant");
  set_gender("male");
  set_short("Cloud giant");
  set_long("This giant is a creature of nature unknown to you.\n");
  set_ac(3);
  set("aggressive",16);
  set_size(3);
  set_alignment(8);
  set_hd(15,2);
  set_stats("strength",23);
  set_stats("dexterity",15);
  set_stats("intelligence",14);
  set_stats("wisdom",12);
  set_stats("constitution",19);
  set_stats("charisma",12);
  set_class("mage");
  set_mlevel("mage",15);
  set_guild_level("mage",15);
  set_spell_chance(50);
  set_spells( ({"chill touch", "lightning bolt"}) );
  new("/d/deku/weapons/cloud")->move(TO);
  command("wield sword in right hand");
  add_money("gold", random(500));
  set_hp(145 + random(25));
  set_exp(query_max_hp() * 25);
	set_new_exp(15, "low");
}


init(){
   ::init();
   force_me("block down");
}
