#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;
int heads;


void create() {
    string *limbs;
    int x;
    ::create();
	set_race("hydra");
    set_name("draldorian");
    set_id(({"hydra","draldorian","forest hydra","guardian"}));
    set_short("Draldorian, Guardian of Shadowlord Forest");
    
    set_long("");
    heads = 8 + random(5);
    set_hd(heads * 2,1);
    set_body_type("dragon");
    set_size(4);
    set_hp(query_hd() * 20 + random(31));
    set_exp(query_max_hp() * 40);
    set_stats("strength",19);
    set_stats("intelligence",15);
    set_stats("wisdom",15);
    set_stats("charisma",9);
    set_stats("constitution",20);
    set_stats("dexterity",12);
    set_alignment(9);
    set("aggressive",27);
    set_property("full attacks",1); 
    set_func_chance(15);
    set_funcs(({"bite"}));
    set_max_level(23);
    set_overall_ac(-2 - random(6));
    for(x = 0;x < heads;x++) {
        add_limb("head "+(x+1), "torso", 0, 0, 0);
        if(sizeof(limbs) < 1) { 
            limbs = ({"head "+(x+1)});
            continue;
        }
        limbs += ({"head "+(x+1)});
    }
    set_attacks_num(heads);
    set_attack_limbs(limbs);
    set_damage(1,4);

}

