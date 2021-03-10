// Imperial Infantry Sergeant of Tsarven (swarm)
// Thorn@ShadowGate
// 961012 updated w/ call help
// Tsarvani Imperial Army
// s-impsgt.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

#define PLATOON 6
#define MAX_CALL 1

inherit MONSTER;

int rushOK;
int callOK;
int platNum, maxNearby;
object *atkrs;



create() {
	int level;
	object ob;
	
	::create();
	set_name("sergeant");
	set_property("full attacks", 1);
	set_id(({ "sergeant", "soldier", "impsgt" }));
	set_short("A Sergeant of the Imperial Infantry");
	set_long(
@TSARVEN
This is a sergeant in the Tsarvani Imperial Army.  This veteran
infantryman leads a squad of 4-6 soldiers in operations.  His men
trust his judgement and his officers rely on him for advice.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("fighter");
	level = random(2)+14;
	set_level(level);
	set_property("swarm",1);
	set_alignment(1);
	set_size(2);
	set_stats("strength", random(6)+10);
	set_stats("constitution", random(8)+10);
	set_stats("wisdom", random(8)+9);
	set_stats("charisma", random(4)+10);
	set_stats("intelligence", random(7)+9);
	set_stats("dexterity", random(7)+10);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(level,10);
	set_hp(roll_dice(level,8));
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	new(SEQUIPDIR+"ihalberd.c")->move(TO);
	force_me("wield halberd in right hand and left hand");
	new(SEQUIPDIR+"iarmor.c")->move(TO);
	force_me("wear armor");
	new(SEQUIPDIR+"ihelm.c")->move(TO);
	force_me("wear helm");
	add_search_path("/cmds/fighter");
	callOK = 1;
	rushOK = 1;
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
                tell_room(environment(atkrs[0]), capitalize(TO->query_name())+" calls for his squad!");
                for(x=0;x<PLATOON;x++) {
                ob = new(AMONDIR+"s-impsoldier");
                ob->move(environment(TO));
		ob->set_self_destruct();
                ob->kill_ob(atkrs[(sizeof(atkrs))-1]);
            		}
                platNum++;
                tell_room(environment(atkrs[(sizeof(atkrs))-1]),
                "%^BOLD%^A squad of Imperial infantry%^BOLD%^ arrives at the call of the "+
                TO->query_name()+"!!%^RESET%^");
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


	
