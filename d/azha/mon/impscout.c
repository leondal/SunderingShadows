// Imperial Scout of Tsarven (swarm)
// Thorn@ShadowGate
// 960923
// Tsarvani Imperial Army
// impscout.c

#include <std.h>
#define PLATOON 4

inherit "/d/azha/std/wander";

int rushOK;
int callOK;
int platNum, maxNearby;
object *atkrs;

int theCavalry();


create() {
        int level;
        object ob;

        ::create();
        set_name("scout");
        set_id(({ "scout", "soldier", "tsarvani", "impscout" }));
        set_short("Imperial Scout");
        set_long(
@TSARVEN
This is a member of the Tsarvani Imperial Army.  Scouts of the
Imperial Army are well-trained, well-equipped and numerous.  They
range ahead of their units, locating enemy forces and harassing
bandits and such on the frontier.
TSARVEN
        );
        set_body_type("human");
        set_race("human");
        set_gender("male");
        set_class("fighter");
        level = random(5)+10;
        set_guild_level("fighter", level);
        set_hd(level, 10);
        set_exp(50);
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
	set_property("full attacks", 1);
	add_search_path("/cmds/fighter");
        new("/d/azha/equip/iscimitar.c")->move(TO);
        force_me("wield sword in right hand");
        new("/d/azha/equip/iarmor.c")->move(TO);
        force_me("wear armor");
        new("/d/azha/equip/ihelm.c")->move(TO);
        force_me("wear helm");
        rushOK = 1;
	platNum = 0;
	maxNearby = random(5)+1;
	call_out("goHome", 120);
        callOK = 1;
}

heart_beat() {
	object ob;
	int x;
        ::heart_beat();
   if(!objectp(TO)) return;
        atkrs = TO->query_attackers();
        if(rushOK) doRush();
        if((atkrs != ({ })) && (callOK == 1) && (platNum <= maxNearby)) {
	        callOK = 0;
	        call_out("OkToCall", 60);
        	tell_room(environment(atkrs[0]), "The scout frantically blows a horn!");
        	for(x=0;x<PLATOON;x++) {
            	ob = new("/d/azha/mon/s-impsoldier");
		ob->set_self_destruct();
            	ob->move(environment(TO));
            	ob->kill_ob(atkrs[(sizeof(atkrs))-1]);
            }
		platNum++;
        	tell_room(environment(atkrs[(sizeof(atkrs))-1]), "%^BOLD%^A platoon of Imperial Troops"+
        	"%^BOLD%^ arrives at the call of the scout!!%^RESET%^");
        }
}

int doRush() {
        string atkrnames;
        int x;

        if(!rushOK) return 0;
        if(!(sizeof(atkrs))) return 1;
        for(x=0;x<sizeof(atkrs);x++) {
                force_me("rush "+atkrs[x]->query_name());
        }
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
int goHome() {
        tell_room(environment(TO),
		"%^BOLD%^A horn sounds in the distance, recalling the scout.",
		({ }));
	TO->move("/d/shadowgate/void");
	if(!TO->remove()) destruct(TO);
	return 1;
}
