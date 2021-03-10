// Azha Townsman
// Thorn@ShadowGate
// 4/13/96
// Town of Azha
// townsman.c

// Updated to look like players
// 27 July 2001
// - Thorn

#include <std.h>

#define RACES ({ "human", "half-elf", "elf", "elf", "human", \
                 "human", "half-elf", "elf", "human", "human", \
                 "human", "human", "human", "human", "human", \
                 "human", "human", "human", "dwarf", "halfling" })

#define ADJ ({ "muscular", "average", "svelte", "scrawny", \
               "average", "average", "plump", "massive", "rotund", \
               "heavy", "frail", "gaunt", "average", "average" })                 

inherit "/d/azha/std/wander";

void create() {
	int i;
	string short;
	string gender;
    ::create();
	i = sizeof(RACES);
	i = random(i);
	set_id( ({ "townsman", RACES[i] }) );
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
	set_level(1);
	set_body_type("human");
	set_class("fighter");
	set("aggressive", 0);
	set_alignment(1);
	set_size(2);
	set_stats("intelligence",6);
	set_stats("wisdom",4);
	set_stats("strength",13);
	set_stats("charisma",3);
	set_stats("dexterity",12);
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
}
