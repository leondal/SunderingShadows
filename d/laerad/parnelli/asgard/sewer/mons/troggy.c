// created by Dinji to make the boots a challenge to get per numerous suggestions, Styx added the rand_gear options

#include <std.h>

inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("Troglodyte");
   set_id(({"troglodyte", "warrior", "trog"}));
   set_race("troglodyte");
   set_gender("male");
   set_short("Troglodyte warrior");
   set_long("This troglodyte stands at just under six foot tall with supreme "
	"confidence.  In its left hand it bears a battered shield"
  	" and in its right hand it holds onto an imposing looking weapon.  "
	"Its skin is green, hard, and scaly  "
      	"with small fins on the top of its head and eyes that glow red in the water."
      	"  It seems adept at moving underwater with its webbed hands and feet."
   );
   set_class("fighter");
   set_mlevel("fighter",19);
   set("aggressive",25);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_size(2);
   set_body_type("human");
   set_alignment(9);
   set_hd(20,2);
   set_overall_ac(-2);
   set_stats("intelligence",10);
   set_stats("wisdom",12);
   set_stats("dexterity",15);
   set_stats("strength",19);
   set_stats("constitution",16);
   set_stats("charisma",7);
   switch(random(4)) {
     case 0..2:
	new("/d/laerad/parnelli/asgard/sewer/weapons/hurricane")->move(TO);
	command("wield trident");
	break;
     case 3:
	"/d/common/daemon/randgear_d"->arm_me(TO,"bluntm",50,random(3)+1,0);
	break;
   }
   switch(random(6)) {
     case 0..2:
	ob=new("/d/common/obj/rand/rand_chain");
		ob->set_property("enchantment",1);
		ob->move(TO);
		command("wear chain");
	break;
     case 3..5:
	ob=new("/d/common/obj/rand/s_curiass");
   		ob->set_property("enchantment",1);
		ob->move(TO);
		command("wearall");
 	break;
   }
	switch(random(2)) {
		case 0:
	new("/d/laerad/parnelli/asgard/sewer/obj/lsboots")->move(TO);
 	break;
		case 1:
	new("/d/laerad/parnelli/asgard/sewer/obj/wcloak")->move(TO);
	break;
   }
	command("wearall");
   set_hp(235);
   set_exp(7000);
   add_money("gold",random(100)+100);
   set_mob_magic_resistance("average");
   set_property("water breather",1);
}
