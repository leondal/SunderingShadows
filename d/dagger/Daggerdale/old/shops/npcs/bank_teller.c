#include <std.h>
inherit NPC;

void create()
{
	::create();
	set_name("Jendar");
	set_short("Jendar, the bank teller");
	set_id(({"Jendar","bank teller","teller","jendar","clerk"}));
	set_long(
   "Jendar is a rather bored looking clerk who apparently gets"+
   " paid quite well judging from his expensive clothing. He has"+
   " neatly trimmed sandy blonde hair and brown eyes that seem"+
   " to count everything very swiftly. His long, slender fingers"+
   " attest to the fact he has never done much, if any, hard"+
   " labor in his life. The worst he suffers from are a few ink"+
   " stains on his right hand. He does seem competent and good"+
   " with the money, however, and more than willing to help you"+
   " with your account...for the normal fees of course.");
	set_gender("male");
	set_race("human");
	set_hd(10,5);
	set_max_hp(100+random(25));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(-10);
	set_level(10);
	set_stats("intelligence",18);
	set_stats("charisma",16);
	set_stats("wisdom",14);
	set_stats("strength",8);
	set_stats("dexterity",10);
	set_stats("constitution",12);
	set_exp(100);
	set_property("swarm",1);
   set_property("no bow",1);
   add_dbs(({"teller"}));
   add_random_act_dbs(({"tellerrandom"}));
   remove_std_db();
	set("aggressive",0);
}
