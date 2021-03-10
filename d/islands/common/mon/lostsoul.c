#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("lost soul");
    set_id(({"lost soul","soul","lostsoul"}));
      set_short("Lost soul");
    set_long("
    In remote and desolate places, Lost souls can be seen wandering in the darkness.  Theye are forgotten spirits of men and women drowned at sea or left shipwrecked to rot on desert islands.
    It has a wispy form, barely discernable in any more than the faintest light until it comes close enough to strike.  Then it appears like a glowing skeleton of smoke.  They are quite common in the unruled armies of skeletal entities that roam Attaya.
");
    set_gender("male");
    set_hd(32,6);
    set_size(2);
    set_overall_ac(-10);
    set_class("fighter");
    set_guild_level("fighter",16);
    set_max_hp(140);
    set_hp(140);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_race("undead");
    set_property("full attacks",1);
    set_property("swarm",1);
    set_moving( 1 );
     set("aggressive", 22);
    set_speed ( 8 );
    set_property("no_bump",1);
    set_stats("dexterity",18);
    set_stats("constitution",17);
     set_stats("strength",22);
    set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(7000);
    set_emotes(5,({
        "%^BOLD%^%^CYAN%^Lost soul lets out a bone rattling scream!",
      "The wind around you seems to pick up!",
        "Lost soul moans sadly!",
        "Lost soul floats ominously around you.",
        "Lost soul seems to shudder from cold!",
        "The ground beneath you begins to feel uneasy.",
        "A shiver runs the length of your spine"
    }),0);
    set_funcs(({"desoul"}));
    set_func_chance(25);
    add_money("gold", 250 + random(250));
    add_money("platinum", 50 + random(200));
   set_resistance("negative energy",10);
   set_resistance("positive energy",-10);
}
void init(){
    if(!TP->query_true_invis()) {
        tell_room(ETO,"You feel a hush like a shadow fall upon you!");
        if(TP->query_invis()) {
            TP->set_invis();
        }
        kill_ob(TP,1);
    }
}
void die(object ob)
{
    string area;

    if(objectp(ETO)) tell_room(ETO, "Lost soul collapses.\n%^BOLD%^A brilliant light speeds upwards from the center of the entity.");

    if(objectp(ETO))
    {
        area = base_name(ETO);
        if(strsrch(area, "eldebaro") != -1)
        {
            "/d/islands/common/eldebaro/kill_tracker_d.c"->register_death(all_living(ETO));
        }
    }
    ::die(ob);
}
void desoul(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="hurts";
    } else {
	dam="poisons";
    }
    tell_object(targ,
      "%^GREEN%^Lost soul reaches out and touches you.\n""%^BOLD%^%^CYAN%^Thoughts and visions of death...  of the grave flood your mind and "+dam+" your soul!"
    );
    tell_room(environment(targ),
       "%^GREEN%^Lost soul reaches out and touches "+targ->query_cap_name()+".\n""%^BOLD%^%^GREEN%^"+capitalize(targ->query_subjective())+" suddenly looks very pale."
    ,targ);
    if(dam=="poisons") {
	targ->do_damage("torso",roll_dice(2,6));
        targ->add_poisoning(20);
	tell_object(targ,
            "%^BOLD%^%^BLUE%^You suddenly feel the pain of being eternally alone in a cold, dark, silent place!"
	);
	targ->set_paralyzed(random(30)+10,
          "%^BLUE%^Oh....  The horrors...  The terrible pain!"
	);
    } else {
	targ->do_damage("torso",roll_dice(2,6));
    }
    return 1;
}
