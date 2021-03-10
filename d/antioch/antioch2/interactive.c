#include <std.h>
#include <daemons.h>
#include "antioch.h"
inherit "/std/vendor";

int summon_guards;
int should_interact;
int CALL;

void create()
{
	::create();
   CALL = 0;
}

void heart_beat()
{
	object ob, *atkrs;
	int x, CALL;
	if(!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if(atkrs != ({ }) && CALL != 1) {
		call_out("summon_guards",5);
		force_me("yell Help, I'm being attacked! Someone call the guards!");
      CALL = 1;
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO,"%^BOLD%^Several guards burst into the room.");
	new(MONS+"guard")->move(ETO);
	if(sizeof(TO->query_attackers()) > 1) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 2) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 3) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 4) {
		new(MONS+"guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 5) {
		new(MONS+"guard")->move(ETO);
	}
	return 1;
}

int should_interact(object ob)
{
//   if(!::should_interact(ob)) return 0;
   if(!interactive(ob)) return 0;

	if(ob->query_hidden()) {
		force_me("say We're not too fond of thieves around here, if you want"+
		" some service at least have the decency to come out of the shadows.");
		return 0;
	}
      if((string)ob->query_name() == "vethor" || (string)ob->query_name() == "spungold" || (string)ob->query_name() == "zasaks" || (string)ob->query_name() == "vezior" || (string)ob->query_name() == "destiny") {
         force_me("say "+ob->query_cap_name()+" you are not welcome in this city and I will not serve you!");
         return 0;
      }
      if(!objectp(TP->query_property("shapeshifted"))) {
        if((string)ob->query_race() == "drow" || (string)ob->query_race() == "ogre" || (string)ob->query_race() == "half-ogre" || (string)ob->query_race() == "goblin" || (string)ob->query_race() == "orc" || (string)ob->query_race() == "half-orc" || (string)ob->query_race() ==  "hobgoblin" || (string)ob->query_race() == "ogre-mage" || (string)ob->query_race() == "gnoll" || (string)ob->query_race() == "half-drow" || (string)ob->query_race() == "kobold" || (string)ob->query_race() == "bugbear") {
		force_me("say Sorry, but we don't serve your kind here.");
		return 0;
        }
	}
	if(ob->is_class("antipaladin")) {
		force_me("say We do not serve antipaladins here!");
		return 0;
	}
	if(member_array(ob->query_name(),KILLING_D->query_evil_bounties()) != -1) {
		force_me("say Evil scum! Get out of my shop before I summon the guards!");
		return 0;
	}
	if(member_array(ob->query_name(),KILLING_D->query_bounties()) != -1) {
		force_me("say We do not serve law breakers in this city, begone before"+
		" I summon the guards!");
		return 0;
	}
   return 1;
}
