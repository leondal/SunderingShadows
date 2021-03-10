#include <std.h>
#include "../antioch.h"
#include <daemons.h>
inherit TOWNSMAN;

void create()
{
	::create();
	set_name("Cealith");
	set_short("King Cealith, ruler of Antioch");
	set_id(({"cealith","Cealith","king","king cealith","ruler","monarch"}));
	set_long(
	"Cealith Elurion, King of Antioch stands before you. He is a regal monarch"+
	" who rules his citizens with a gentle hand. It is said that he is wise"+
	" beyond his years, being barely three decades old. His advisors surround"+
	" him, helping him to rule the kingdom. He is dressed in the finest of"+
	" raiments. A white silk tunic with golden embroidery covers his chest,"+
	" the sleeves are long and run down to his wrists where they flare out."+
	" A golden belt is clasped around his waist, holding the tunic close."+
	" Dark blue pants cover his legs, and boots made of a strange ebony black"+
	" hide cover his feet. A golden crown adorns his head, taming his wild"+
	" red hair. His purple cloak has been draped over the throne for now. He"+
	" stands almost six feet in height, and has a confident aura about him."+
	" Rumor has it that he has been blessed by Ignatius with intelligence and"+
	" wisdom, and that Jarmila helps him know of dangers in advance."
	);
	set_gender("male");
	set_race("human");
	set_hd(50,9);
	set_alignment(1);
	set_property("alignment adjustment",-10);  // was 20 (which was also the wrong direction)
	set_overall_ac(-20);
	set_max_hp(540+random(50));
	set_hp(query_max_hp());
	set_class("cavalier");
	set_mlevel("cavalier",30);
	set_class("mage");
	set_mlevel("mage",30);
	set_level(30);
	set_stats("intelligence",19);
	set_stats("strength",18);
	set_stats("constitution",16);
	set_stats("dexterity",15);
	set_stats("charisma",20);
	set_stats("wisdom",20);
	set_emotes(5,({
	"The king glances around the throne room.",
	"Cealith frowns in thought.",
	"Cealith nods to his advisors.",
	"Cealith commands a scribe to write something down.",
	"Cealith taps his fingers on the throne.",
	"Cealith shifts in his chair.",
	}),0);
	set_spells(({
	"meteor swarm",
	"monster summoning vii",
	"chain lightning",
	}));
	set_spell_chance(100);
	set_exp(100);
	set("aggressive",0);
	set_property("swarm",1);
}

void heart_beat()
{
	::heart_beat();
    if(!objectp(TO)) { return; }
	if((mixed *)TO->query_attackers() != ({ }) && !present("palace guard")) {
		call_out("summon_guards",1,TO);
		return;
	}
}

void init()
{
	::init();
	if(TP->id("horse") && !userp(TP)) {
		force_me("frown");
		force_me("say Horses and other such animals belong in the stables, not in the"+
		" throne room.");
		return;
	}
	else if(!interactive(TP)) return;
	if(member_array(TP->query_name(),KILLING_D->query_bounties()) != -1) {
		force_me("say You are a law breaker, you have no business before this court!");
		force_me("say Guards, remove this fiend.");
		tell_object(TP,"The guards drag you back out into the hallway.");
		tell_room(ETP,"The guards drag "+TPQN+" out into the hallway.",TP);
		TP->move("/d/antioch/antioch2/rooms/pal8.c");
		return 1;
	}
	else if(member_array("Antioch Quest",TP->query_quests()) != -1) {
		force_me("smile "+TPQN);
		force_me("say We see that you are one of those who helped to save our proud"+
		" city from the clutches of evil.");
		force_me("say As you can see, we have rebuilt our fair city, with stronger"+
		" walls and better defenses and we shall not allow such a disaster to occur"+
		" again.");
		force_me("say On behalf of all of Antioch, we express our gratitude to you.");
		return 1;
	}
	return;
}

int summon_guards()
{
	object ob;
    if(!objectp(TO)) { return 0; }

	tell_room(ETO,"%^BOLD%^Several guards magically appear in the room to defend their king.");
	ob = new(MONS+"palace_guard");
 	  ob->move(ETO);
	  ob->force_me("protect king");
	ob = new(MONS+"palace_guard");  // added by *Styx*
// added these extra new(guard)s - I think she meant to get multiple guards and overlooked creating the extra objects
	  ob->move(ETO);
	  ob->force_me("protect king");
	ob = new(MONS+"palace_guard");  // added by *Styx*
	  ob->move(ETO);
	  ob->force_me("protect king");
	ob = new(MONS+"palace_guard");  // added by *Styx*
	ob->move(ETO);
	ob->force_me("protect king");
//	ob->move(ETO);  // surely the extra three are enough, gets awfully spammy
//	ob->force_me("protect king");
	return 1;
}

void die(object ob)
{
	tell_room(ETO,"%^BOLD%^%^CYAN%^A blue mist arises around the king.");
	tell_room(ETO,"%^BOLD%^As the mist clears, you notice the king has vanished.");
	TO->move("/d/shadowgate/void");
	::die(ob);
}
