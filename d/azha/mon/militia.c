// Azha Militia (swarm)
// Thorn@ShadowGate
// 960923
// Town of Azha
// militia.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

#define RACES ({ "half-elf", "half-elf", "elf", "human", \
                 "human", "human", "human", "human", "human" })

#define ADJ ({ "A muscular", "An average", "A svelte", \
               "An average", "An average", "A massive", "A rotund", \
               "A heavy", "An average" })       

inherit MONSTER;               

int rushOK;
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
	if(random(10)) gender = "male";
	else gender = "female";
	set_gender(gender);
	short = RACES[i];
	i = sizeof(ADJ);
	i = random(i);
	short = ADJ[i]+" "+gender+" "+short+" in %^BOLD%^%^GREEN%^g%^WHITE%^r%^GREEN%^e%^WHITE%^e%^GREEN%^n %^WHITE%^s%^GREEN%^t%^WHITE%^r%^GREEN%^i%^WHITE%^p%^GREEN%^e%^WHITE%^d %^GREEN%^a%^WHITE%^r%^GREEN%^m%^WHITE%^o%^GREEN%^r%^RESET%^";
	set("short", short);
	set_name(short);
	set_long(
@TSARVEN
This is an Azha militia soldier.  The town militia is made up of male 
citizens of Azha, who work for an allotted period.  They wear a striped 
green tabard and carry basic weapons, but they carry them with the care 
of the unskilled user.
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("fighter");
	level = random(5)+7;
	set_guild_level("fighter", level);
	set_hd(level, 10);
	set_exp(200);
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
	ob = new("/d/common/obj/armour/leather");
	ob->set_short("a suit of leather armor with %^GREEN%^g%^WHITE%^r%^GREEN%^e%^WHITE%^e%^GREEN%^n %^WHITE%^s%^GREEN%^t%^WHITE%^r%^GREEN%^i%^WHITE%^p%^GREEN%^e%^WHITE%^s");
	ob->set_long(
@ARMOR
This is an old and well-broken in set of leather armor decorated with 
green diagonal striping.  On the upper left of the armor, over the 
heart, is a metallic crescent moon, the Imperial symbol of Tsarven. 
Since no Imperial soldier would be found with such mediocre equipment, 
you assume that this belonged to a town policeman or watchman.
ARMOR
	);	
	ob->move(TO);
	force_me("wear armor");
	rushOK = 1;
}

heart_beat() {
        object ob;
        int x;
        ::heart_beat();
   if(!objectp(TO)) return;
        atkrs = TO->query_attackers();
        if(rushOK) doRush();
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
