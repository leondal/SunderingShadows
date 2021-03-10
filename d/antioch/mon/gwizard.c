#include <std.h>

inherit MONSTER;

void create() {
    ::create();
   set_name("goblin wizard");
   set_id( ({"goblin","wizard"}) );
   set_race("goblin");
   set_gender("male");
   set_short("A goblin wizard");
 set("long",
"This type of goblin is very uncommon.  He looks to be one of the "+
"high kings of Antioch, but he still worships only Ignatius."
 );
   set_level(11);
   set_class("mage");
   set_guild_level("mage",11);
   set_mlevel("mage",11);
   set_body_type("human");
   set("aggressive", 9);
set_property("swarm",1);
set_hd(11,3);
set_alignment( 4 );
   set_size( 1 );
   set_hp(60);
   set_max_hp(60);
   set_spell_chance(90);
set_spells(({
"magic missile",
"sleep"
}));
set_exp(750);
 add_money("silver",random(10));
add_money("gold",random(20));
}
