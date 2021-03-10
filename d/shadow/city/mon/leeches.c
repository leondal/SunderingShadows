#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create() {
    ::create();
    set_name("swarm of leeches");
    set_id(({"swarm","leeches","swarm of leeches"}));
    set_short("%^BOLD%^%^BLACK%^swarm of leeches%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This is a wriggling, repulsive %^GREEN%^swarm%^BOLD%^%^BLACK%^ of slimy black leeches. "+
	"These little monsters are driven by their desire for %^RED%^blood%^BOLD%^%^BLACK%^. In this case, "+ 
	"your blood. They squirm all over the place, fighting each other for a chance to fill their horrible "+ 
	"%^RESET%^ring-shaped mouths%^BOLD%^%^BLACK%^ with your delicious "+ 
	"%^RESET%^%^ORANGE%^flesh%^BOLD%^%^BLACK%^.");  
	set_hd(12,2);
    set_hp(75 + random(25));
    set_max_hp(query_hp());
    set_body_type("worm");
    set_damage(1,4);
    set_attacks_num(2);
	add_limb("mouth");
    set_attack_limbs(({"mouth", "tail"}));
    set_base_damage_type("piercing");
    set_gender("neuter");
    set_race("worm");
    set_new_exp(10, "high");
    set_alignment(5);
    set_overall_ac(-7);
    set("aggressive", 30);
    set_stats("strength", 15);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 15);
    set_stats("dexterity", 15);
    set_stats("charisma", 6);
    set_property("full attacks", 1);
    set_moving(1);
    set_speed(55);
    new("/realms/titania/shadowcity/sewers/obj/leechteeth.c")->move(TO);
    command("wield teeth");
    add_money("silver",random(10));
    add_money("copper",random(20));
	set_emotes(15, ("%^RESET%^%^RED%^The swarm wriggles and writhes, trying to latch onto you.%^RESET%^"));
}

