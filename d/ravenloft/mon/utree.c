// Coded by Bane
// utree.c
#include <std.h>
inherit WEAPONLESS;
void make_me();
void create(){
    ::create();
    set_name("old tree");
    set_id(({"tree","old","old tree","undead","undead tree"}));
    set_short("An old withered tree");
    set_long(
	"Here stands an old decaying tree.  Its trunk is rotted in many places, "+
	"its bark is all torn off and dead leaves lay near its base.  Near "+
	"the center of the tree is the strangest resemblance of a face..."
    );
    set_overall_ac(0);
    set_race("tree");
    add_limb("trunk","trunk",0,0,0);
    add_limb("right limb","trunk",0,0,0);
    add_limb("foliage","trunk",0,0,0);
    add_limb("roots","trunk",0,0,0);
    add_limb("left limb","trunk",0,0,0);
    make_me();
    set_stats("strength",19);
    set_attack_limbs(({"right limb","left limb"}));
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_alignment(9);
}
void make_me(){
    int i;
    i = random(15);
    set_hd(i + 10,8);
    set_exp(2000 + 600 * i);
    set_hp(query_hd()*8);
    switch(query_hd()){
	case 10..11:
	    set_damage(2,8);
	    break;
	case 12..13:
	    set_damage(3,6);
	    break;
	case 14..15:
	    set_damage(4,6);
	    break;
	case 16..25:
	    set_damage(5,6);
	    break;
    }
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
    if(!interactive(TP)) return 1;
    if(query_invis()) set_invis();
    kill_ob(TP,1);
}
void heart_beat(){
    ::heart_beat();
    if((string *)TO->query_attackers() == ({})){
	if(!query_invis()){
	    set_invis();
	}
    }
    return 1;
}
