#include "/d/dagger/aketon/short.h";

inherit MONSTER;

void create() {
   ::create();
   set_name("security guard");
   set_id( ({"guard","security"}) );
   set("race","elf");
   set_gender("male");
   set_short("Security guard");
   set_long("An Elite mercenary assigned to guard the shops.\n");
   set_level(30);
   set_body_type("human");
   set_class("ranger");
   set("aggressive",0);
   set_alignment(7);
   set_hd(30,8);
   set_hp(320);
   set_max_hp(query_hp());
   set_size(2);
   set_stats("intelligence",15);
   set_stats("wisdom",18);
   set_stats("strength",22);
   set_stats("charisma",10);
   set_stats("dexterity",20);
   set_stats("constitution",14);
   set_property("no death",1);
   set_property("no rush",1);
   set_property("no steal",1);
   set_property("swarm",1);
   set_property("full attacks",1);
   set_property("weapon resistance",2);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(ARMORPATH+"chain")->move(TO);
   command("wear chain");
   add_money( "electrum",random(100) );
   add_money( "silver",random(100) );
   add_money( "gold",random(100) );
   add_money( "copper",random(200) );
}
