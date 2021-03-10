#include <std.h>
#include <daemons.h>
#include "../short.h"
inherit VENDOR;

int summon_guards;
int should_interact;
int CALL;

//BADDIES list will prevent vendors from interacting with people
#define BADDIES ({"testlackey"})

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
		force_me("yell These lawbreakers dare attack me!  Help!  Guards!");
      CALL = 1;
	}
}

/*%^BOLD%^The below should be changed once the new guards go in.  Reminder to me%^RESET%^*/

int summon_guards()
{
	object ob;
	tell_room(ETO,"%^BOLD%^%^GREEN%^Several guards burst into the room.");
	new(MPATH"guard1")->move(ETO);
	if(sizeof(TO->query_attackers()) > 1) {
		new(MPATH"guard1")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 2) {
		new(MPATH"guard2")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 3) {
		new(MPATH"guard2")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 4) {
		new(MPATH"guard1")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 5) {
		new(MPATH"guard2")->move(ETO);
	}
	return 1;
}

int should_interact(object ob)
{
//   if(!::should_interact(ob)) return 0;
   if(!interactive(ob)) return 0;

	if(ob->query_hidden()) {
		force_me("say You'll have to come out here where I can see you first.");
		return 0;
	}
   if(member_array(ob->query_name(), BADDIES) != -1) {
      force_me("emote nods to a nearby guard.");
      force_me("say The guards have informed me you are not welcome "+
         "in this city.  Leave now before you hurt my business.");
      return 0;
   }
// returned the race query it once had, to lock elves out as they are banned per city law. the rest have been vaped. N, 5/13.
	if((string)ob->query_race() == "elf") {
		force_me("say Get out, beast, before I call the guards on you!");
		return 0;
	}

	if(member_array(ob->query_name(),KILLING_D->query_bounties()) != -1) {
		force_me("say We do not serve those who cannot observe laws!");
		return 0;
	}
   return 1;
}
