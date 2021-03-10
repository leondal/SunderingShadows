// Azha Crook
// Thorn@ShadowGate
// 4/9/96
// Town of Azha
// thief.c

#include <std.h>

inherit "/d/azha/std/wander";

#define RACES ({ "goblin", "half-elf", "half-elf", "elf", "human", \
                 "human", "half-elf", "half-drow", "human", "human", \
                 "human", "human", "human", "human", "human", \
                 "human", "human", "human", "halfling", "halfling" })

#define ADJ ({ "muscular", "average", "svelte", "scrawny", \
               "average", "average", "plump", "massive", "rotund", \
               "heavy", "frail", "gaunt", "average", "average" })                 

void create() {
	int i;
	string short;
	string gender;
    ::create();
	i = sizeof(RACES);
	i = random(i);
	set_id( ({ "townsman", "thiefx", RACES[i] }) );
	set("race", RACES[i]);
	if(random(3)) gender = "male";
	else gender = "female";
	set_gender(gender);
	short = RACES[i];
	i = sizeof(ADJ);
	i = random(i);
	short = ADJ[i]+" "+gender+" "+short;
	set("short", "A "+short);
	set_name("A "+short);
	set_long("A "+short+" looks rather nondescript and wears the "+
	         "traditional garb of the northern provinces of the "+
	         "Empire of Tsarven.");
	set_level(random(10)+1);
	set_body_type("human");
	set_class("thief");
	set("aggressive", 0);
	set_alignment(5);
	set_size(2);
	set_stats("intelligence",6);
	set_stats("wisdom",4);
	set_stats("strength",13);
	set_stats("charisma",3);
	set_stats("dexterity",8);
	set_stats("constitution",7);
	set_max_mp(0);
	set_mp(query_max_mp());
	set_hd(1, 1);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
	set_thief_skill("pick pockets", 50+random(20));
	toggle_steal();
}
