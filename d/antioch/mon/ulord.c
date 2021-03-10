#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
  ::create();
  set_name("the undead lord");
  set_id(({"lord","undead","undead lord"}));
  set_short("The undead lord");
  set_long("This creature is the new Lord of Antioch's castle.  He does not look very happy about having been disturbed by you.");
  set("aggressive",10);
  set_alignment(9);
  set_body_type("human");
  set_gender("male");
  set_hd(12,1);
  set_size(2);
  set_max_hp(400);
  set_hp(query_max_hp());
  set_sp(query_max_sp());
  set("race","undead");
  set_class("mage");
  set_guild_level("mage",10);
  set_exp(8000);
  set_money("gold",random(100));
  set_money("electrum",random(50));
  set_money("platinum",random(20));
  set_money("silver",random(500));
  set_spell_chance(75);
  set_spells(({
    "magic missile",
    "cone of cold",
    "hideous laughter",
    "fireball",
    "dispel magic",
    "chain lightning"
  }));
  new("/d/antioch/obj/undead")->move(this_object());
  new("/d/deku/weapons/dagger2")->move(this_object());
  command ("wield dagger");
}
void reset(){
   object ob;
	::reset();
   if(!present("scroll")){
	  ob= new("/d/magic/scroll");
          ob->set_spell(5);
  ob->move(this_object());
   }
}
