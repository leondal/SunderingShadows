#include <std.h>
#include <daemons.h>
#include "../elf.h"
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
        new(MON"guard")->move(ETO);
        if(sizeof(TO->query_attackers()) > 1) {
                new(MON"guard")->move(ETO);
        }
        if(sizeof(TO->query_attackers()) > 2) {
                new(MON"guard")->move(ETO);
        }
        if(sizeof(TO->query_attackers()) > 3) {
                new(MON"guard")->move(ETO);
        }
        if(sizeof(TO->query_attackers()) > 4) {
                new(MON"guard")->move(ETO);
        }
        if(sizeof(TO->query_attackers()) > 5) {
                new(MON"guard2")->move(ETO);
        }
        return 1;
}

int should_interact(object ob)
{
   if(!interactive(ob)) return 0;
   if(avatarp(ob)) return 1;

        if(ob->query_hidden()) {
           force_me("say We're not too fond of thieves "+
			"around here.  If you want some service, at least have "+
			"the decency to come out of the shadows.");
                return 0;
        }

        if((string)ob->query_race() != "elf" &&
           (string)ob->query_race() != "nymph" &&
           (string)ob->query_race() != "voadkyn" &&
           (string)ob->query_race() != "dryad" &&
           (string)ob->query_race() != "faery" &&
           (string)ob->query("subrace") != "szarkai") {
                force_me("say Sorry, but we don't serve your kind here.  Only fey are welcome in Ashta.");
                return 0;
        }

        
        if(member_array(ob->query_name(),KILLING_D->query_evil_bounties()) != -1)
{
                force_me("say Evil scum! Get out of my shop before I summon the guards!");
                return 0;
        }
        if(member_array(ob->query_name(),KILLING_D->query_neutral_bounties()) != -1)
{
                force_me("say I've heard of your deeds and I could get in trouble for selling to you.");
			
                return 1;
        }
        
   return 1;
}
varargs int adjust_cost(int cost, int sell){
    int mod, prof;
    int cha;

    prof = (int)TP->query_nwp("fast talking");
    cha = TP->query_stats("charisma");
    if(member_array(TP->query_name(),KILLING_D->query_neutral_bounties()) != -1)
	prof = -10;//make neutral extremists pay extra
    if(cha > 23) { cha = 23; }
    mod = 13 - cha;
    //mod += racial stuff ---- Garrett.
    mod -= prof;
    if (!sell) {
     if(mod > 0)
        cost = cost+(cost *(mod*5))/100;
     else
     cost = cost + (cost *(mod*2))/100;

    } else {
    if(mod > 0)
       cost = cost-(cost *(mod*5))/100;
     else
     cost = cost - (cost *(mod*2))/100;
    }
    return cost;
}
