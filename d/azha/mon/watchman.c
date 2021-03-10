// Azha Watchman (swarm)
// Thorn@ShadowGate
// 960923
// Town of Azha
// watchman.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit MONSTER;

#define PLATOON 2
#define MAX_CALL 3

#define RACES ({ "half-elf", "half-elf", "elf", "human", \
                 "human", "human", "human", "human", "human" })

#define ADJ ({ "A muscular", "An average", "A svelte", \
               "An average", "An average", "A massive", "A rotund", \
               "A heavy", "An average" })                 

int rushOK;
int callOK;
int platNum, maxNearby;
object *atkrs;



create() {
	int level;
	object ob;
	int i;
	string short;
	string gender;
	
	::create();
	i = sizeof(RACES);
	i = random(i);
	set_id( ({ "militiax", RACES[i] }) );
	set("race", RACES[i]);
	gender = "male";
	set_gender(gender);
	short = RACES[i];
	i = sizeof(ADJ);
	i = random(i);
	short = "%^RESET%^"+ADJ[i]+" "+gender+" "+short+" in %^BOLD%^%^BLUE%^blue %^RESET%^and %^YELLOW%^yellow %^BLUE%^s%^YELLOW%^t%^BLUE%^r%^YELLOW%^i%^BLUE%^p%^YELLOW%^e%^BLUE%^d %^YELLOW%^a%^BLUE%^r%^YELLOW%^m%^BLUE%^o%^YELLOW%^r%^RESET%^";
	set("short", short);
	set_name(short);
        set_long(
@TSARVEN
This is an Azha town watchman.  The town watch is a group of local men
who keep the peace in this turbulent town, backed up by the irregular
militia, and in special cases, the Imperial Garrison.  They mostly
keep watch for drunken merchant guards, or petty thieves, but they
have dealt with quite a bit in their time.
TSARVEN
        );
	set_body_type("human");
	set_class("fighter");
	set_property("full attacks", 1);
	level = random(5)+10;
	set_guild_level("fighter", level);
	set_hd(level, 10);
	set_exp(2000);
	set_max_hp(100+random(75));
	set_hp(query_max_hp());
	set_overall_ac(1);
	set_property("swarm",1);
	set_alignment(1);
	set_size(2);
	set_stats("strength", random(4)+10);
	set_stats("constitution", random(9)+8);
	set_stats("wisdom", random(8)+9);
	set_stats("charisma", random(5)+9);
	set_stats("intelligence", random(7)+9);
	set_stats("dexterity", random(8)+9);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(AEQUIPDIR+"wsword")->move(TO);
	force_me("wield sword in right hand");
	new(AEQUIPDIR+"warmor.c")->move(TO);
	force_me("wear armor");
	rushOK = 1;
	platNum = 0;
	maxNearby = random(MAX_CALL)+1;
	add_search_path("/cmds/fighter");
	callOK = 1;
}

heart_beat() {
        object ob;
        int x;
        ::heart_beat();
   if(!objectp(TO)) return;
        atkrs = TO->query_attackers();
	if(rushOK && (atkrs != ({ })))
		TO->force_me("rush "+atkrs[0]->query_name());
        if((atkrs != ({ })) && (callOK == 1) && (platNum <= maxNearby)) {
                callOK = 0;
                call_out("OkToCall", 60);
                tell_room(environment(atkrs[0]), capitalize(TO->query_name())+" calls for help!");
                for(x=0;x<PLATOON;x++) {
                ob = new(AMONDIR+"militia");
                ob->move(environment(TO));
                ob->kill_ob(atkrs[(sizeof(atkrs))-1]);
            		}
                platNum++;
                tell_room(environment(atkrs[(sizeof(atkrs))-1]),
                "%^BOLD%^A squad of watchmen%^BOLD%^ arrives at the call of the "+
                TO->query_name()+"!!%^RESET%^");
        }
}

int doRush() {
        string atkrnames;
        int x;

        if(!rushOK) return 0;
        if(!(sizeof(atkrs))) return 1;
	TO->force_me("rush "+atkrs[0]->query_name());
//        for(x=0;x<sizeof(atkrs);x++) {
//                force_me("rush "+atkrs[x]->query_name());
//        }
        rushOK = 0;
        call_out("OkToRush", 60);
}

int OkToRush() {
        rushOK = 1;
        return rushOK;
}

int OkToCall() {
        callOK = 1;
        return callOK;
}


