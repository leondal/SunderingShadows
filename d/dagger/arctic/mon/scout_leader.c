#include <std.h>
#include "../arctic.h"
inherit CREATURE;

void attack();

void create() 
{
        
    ::create();
    set_name("Frost Giant Scout Leader");
    set_id(({"giant","frost giant","scout leader","arcticmon"}));
    set_race("frost giant");
    set_body_type("human");
    set_gender("male");
    set_size(3);
    set_short("A towering frost giant");
    set_long("%^RESET%^%^BOLD%^This towering frost giant stands close to twenty "
        "five feet tall.  His massive arms and chest are rippling with iron like "
        "muscles and his legs are larger than full grown ogres.  He is covered by "
        "a suit of hide armor that appears to have been made from a wooly mammoth, "
        "and in his left hand he wields a two handed sword that is covered with "
        "frost.%^RESET%^");
    set_hd(32,1);
    set_level(32);
    set_class("fighter");
    set_mlevel("fighter", 32);
    add_search_path("/cmds/fighter");
    set_hp(1000);
    set_exp(25000);
    set_property("swarm", 1);
    set_overall_ac(-10);
    set_stats("strength",23);
    set_stats("dexterity",15);
    set_stats("intelligence",13);
    set_stats("wisdom",14);
    set_stats("constitution",20);
    set_stats("charisma",11);
    set_property("full attacks", 1);
    set("aggressive", 20);
    set_funcs( ({"attack"}) );
    set_func_chance(100);
    new(OBJ"winterstouch.c")->move(TO);
    force_me("wield sword");
    new(CARMOR"hide.c")->move(TO);
    force_me("wear hide");
    add_money("gold",random(1000)+500);

}


void attack()
{

    object *live;
    object *fodder;
    object targ;
    int i;

    live = all_inventory(ETO);
    fodder = live;
    fodder = filter_array(fodder, "is_fodder",CREATURE);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);
    live += fodder;

    for(i=0;i<sizeof(live);i++)
    {
        targ = live[i];
        if(!objectp(targ)) continue;
        TO->force_me("rush "+targ->query_name());
        
        if(i > 1000) { tell_room(ETO,"loop error attack() "
            "in "+MON+"scout_leader.c"); break; } 

    }
    set("aggressive", 20);
    TO->force_me("parry");
    set_func_chance(0);
    return;
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) { return; }
    if(!random(10)) { set_func_chance(100); return; }
}