#include <std.h>
#include <security.h>
#include "../antioch.h"
inherit MONSTER;

void create()
{
	::create();
	set_name("guard");
	set_short("A guardsman of Antioch");
	set_id(({"guard","guardsman","antioch guard","guardsman of Antioch","guardsman of antioch","Antioch guard"}));
	set_long(
	"This is one of the common guards of the city of Antioch. They are all"+
	" well trained and veterans of many years, dedicated to protecting the"+
	" city at all costs. He is wearing the uniform of the guards, silver robe"+
	" and belt, with matching shield and helm. A suit of chain mail covers"+
	" his body, and a silver longsword is in his hand. He looks alert and"+
	" ready for trouble."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(20,8);
	set_max_hp(175+random(50));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(-10);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_stats("strength",19);
	set_stats("constitution",17);
	set_stats("dexterity",16);
	set_stats("charisma",12);
	set_stats("wisdom",15);
	set_stats("intelligence",14);
	set_emotes(3,({
	"The guard paces back and forth.",
	"The guard looks around for any signs of trouble.",
	"The guard sharpens his sword.",
	"The guard listens carefully for any sounds of danger.",
	"The guard tightens the laces of his boots.",
	}),0);
	set_emotes(10,({
	"The guard lunges at you with a furious slash.",
	"The guard calls for aide from his comrades.",
	"The guard spits in your face.",
	"The guard bashes you with his shield.",
	}),1);
	set_exp(100);
	set_property("swarm",1);
	set_property("full attacks",1);
	set("aggressive",0);
	new(OBJ+"silver_robe")->move(TO);
	new(OBJ+"silver_belt")->move(TO);
	new(OBJ+"silver_shield")->move(TO);
	new(OBJ+"silvered_helm")->move(TO);
	new(OBJ+"light_chain")->move(TO);
	new(OBJ+"silver_sword")->move(TO);
	command("wield silver sword");
	command("wearall");
}
//void die(object obj)
//{
//       seteuid(UID_LOG);
//    if (objectp(TO->query_current_attacker()))
//       log_file("/d/antioch/antioch2/logs/guard_deaths",TO->query_current_attacker()+" killed guard on "+ctime(time())+"\n");
//       seteuid(geteuid(previous_object()));
//   ::die(obj);
//}
