#include <std.h>
#include <security.h>
#include "../antioch.h"
inherit MONSTER;

void create()
{
	object obj;

	::create();
   set_no_clean(1);  // I don't think we want or need this *Styx* 12/25/05
	set_name("Adroenyth");
	set_short("Adroenyth, Captain of the Royal Guard");
	set_id(({"Adroenyth","adroenyth","captain","captain of the guard","royal guard","guard"}));
	set_long(
	"Adroenyth is the captain of the Royal Guard of Antioch. He is dressed"+
	" in the uniform of the royal guards. His red robe is buckled by a"+
	" golden belt and a unicorn shield is on his arm. In his hand he carries"+
	" a silver longsword, always prepared for trouble. A suit of light"+
	" chainmail covers his body, providing some protection while remaining"+
	" flexible. Some blonde hair peeks out from beneath his silvered helm"+
	" and his green eyes are constantly sweeping around the room, always"+
	" ready for danger. He looks young for his post, perhaps in his late"+
	" twenties. He stands approximately six feet tall and his figure is quite"+
	" impressive."
	);
	set_race("human");
	set_gender("male");
	set_hd(30,20);
	set_alignment(1);
	set_overall_ac(-10);
	set_max_hp(250+random(50));
	set_hp(query_max_hp());
	set_level(30);
	set_class("cavalier");
	set_mlevel("cavalier",30);
	set_stats("strength",25);
	set_stats("constitution",20);
	set_stats("wisdom",15);
	set_stats("intelligence",17);
	set_stats("dexterity",12);
	set_stats("charisma",17);
	set("aggressive",0);
	set_property("swarm",1);
	set_exp(2500);
	set_mob_magic_resistance("average");
	set_property("weapon resistance",1);
	set_property("full attacks",1);
   set_property("no dominate",1);
   set_property("no bows",1);
   set_property("no hold",1);
   set_property("no paralyze",1);
   set_property("no death",1);
	new(OBJ+"gold_belt")->move(TO);
	command("wear belt");
	new(OBJ+"unicorn_shield")->move(TO);
	command("wear shield");
	new(OBJ+"red_robe")->move(TO);
	if(!random(6)) {
		obj = present("red robes");
		obj->set_property("enchantment",1);
	}
	command("wear robes");
	new(OBJ+"silvered_helm")->move(TO);
	command("wear helm");
	new(OBJ+"silver_sword")->move(TO);
	if(!random(6)) {
		obj = present("silver sword");
		obj->set_property("enchantment",1);
	}
	command("wield sword");
	new(OBJ+"light_chain")->move(TO);
	command("wear chainmail");
	command("speech say in a commanding tone");
   set_property("alignment adjustment",-5);   // was -15
}

void init()
{
	object ob;

	::init();
	if(ALIGN->is_evil(TP) && !TP->query_invis()) {
		force_me("say Evil scum, you are trying to invade the city, begone!");
		kill_ob(TP,1);
		return 1;
	}
else if((string)TP->query_name() == "vethor" || (string)TP->query_name() == "spungold" || (string)TP->query_name() == "vezior" || (string)TP->query_name() == "zasaks" || (string)TP->query_name() == "destiny") {
      force_me("say Prepare for battle "+TPQCN+"!");
      kill_ob(TP,1);
      return 1;
   }
}

void die(object obj)
{
   object killer;
   seteuid(UID_LOG);
   if (objectp(killer=TO->query_current_attacker()))
    log_file("antioch", killer->query_name()+" killed captain on "+ctime(time())+".\n");
   seteuid(getuid(previous_object()));
   return ::die(obj);
}