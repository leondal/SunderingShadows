#include <std.h>
#include "../arctic.h"
inherit CREATURE;

void create() {
   object ob;
    ::create();
    set_name("Cryohydra");
    set_id(({"cryohydra", "hydra","arcticmon"}));
    set_race("hydra");
    set_body_type("dragon");
    set_gender((random(2)?"male":"female"));
    set_size(5);
    set_short("%^RESET%^white%^RED%^ hydra");
    set_long("%^BOLD%^This massive dragon like creature has "
             "numerous heads that sway in a serpentine dance "
             "atop long necks.  The thick scales of the creature "
             "are a clear white color along its back, and a dull "
             "gray running down the bottom of each neck and to "
             "its stomach.  It has very light, almost translucent "
             "blue eyes in each of its heads, and long yellowish "
             "white teeth that seem to have seen a great deal of "
             "use.%^RESET%^");    
    set_hd(30, 1);
    set_level(30);
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_hp(750);
    set_exp(20000);
    set_property("swarm", 1);
    set_overall_ac(-10);
    set_stats("strength",22);
    set_stats("dexterity",10);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("constitution",19);
    set_stats("charisma",9);
    set_attacks_num(5);
    set_damage(1,12);
    set_mob_magic_resistance("average");
    set_base_damage_type("piercing");
    add_limb("one of its heads", "head", 0, 0, 0);
    set_attack_limbs(({"one of its heads"}));    
    set("aggressive", 20);
    set_funcs(({"breath"}));
    set_func_chance(25);
    set_speed(50);
    nogo("NOGO1");
    add_money("gold",random(5000)+1000);
    add_money("silver",random(1000)+1000);
    add_money("electrum",random(500)+500);
    add_money("platinum",random(250)+50);
    if(!random(10)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("breath of winter");
      ob->move(TO);
    }
    set_resistance("cold",15);
    set_resistance("fire",-15);
}


void breath()
{
    object *live;
    object *fodder;
    object targ;
    int i = 0;
    int x;
 
    live = all_inventory(ETO);
    fodder = live;

    fodder = filter_array(fodder, "is_fodder",CREATURE);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);
    live += fodder;

    for(i=0;i<sizeof(live);i++)
    {
        targ = live[i];
        if(!objectp(targ)) continue;

        if(!ROLLSAVE(targ, BW ))
        {
            tell_object(targ,"%^CYAN%^A massive cloud of "
                "icy vapor billows forth from one of the heads "
                "of the hydra and slams into you!%^RESET%^");
            tell_room(ETO,"%^CYAN%^"+targ->QCN+" "
                "is hit by the icy breath of the hydra "
                "and frozen to the ground!%^RESET%^",targ);
            TO->set_property("magic", 1);
            targ->do_damage("torso", roll_dice(10,10));
            targ->set_paralyzed((random(15)+10),"%^CYAN%^You are frozen to the ground!.");
            TO->set_property("magic", -1);
            continue;
        }

        tell_object(targ,"%^CYAN%^A massive cloud of "
            "icy vapor billows forth from one of the heads "
            "of the hydra but you dive aside!%^RESET%^");
        tell_room(ETO,"%^CYAN%^"+targ->QCN+" "
            "dives aside at the last moment as a "
            "billowing cloud of cold air from the "
            "mouth of the hydra rushes past!%^RESET%^",targ);
        TO->set_property("magic", 1);
        targ->do_damage("torso", roll_dice(10,10)/2);
        TO->set_property("magic", -1);


        if(i > 1000) { tell_room(ETO,"loop error breath() "
            "in "+MON+"cryohydra.c"); break; } 

    }

}
