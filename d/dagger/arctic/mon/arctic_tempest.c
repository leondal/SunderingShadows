#include <std.h>
#include "../arctic.h"
inherit CREATURE;

void create() {
   object ob;
    ::create();
    set_name("Arctic Tempest");
    set_id(({"face","watery face","tempest","arctic tempest","arcticmon"}));
    set_race("tempest");
    set_body_type("human");
    set_gender("neuter");
    set_size(3);
    set_short("a huge watery face in the waterfall");
    set_long("This massive disembodied face appears to be the "
        "manifestation of some energy or force that guards the "
        "waterfall from those who seek passage.  It is over fifty "
        "feet tall and has roughly human features.  A pair of "
        "enormous hand-like appendages made from the water thrash "
        "about trying to hit anything near the waterfall.");
    set_hd(25,1);
    set_class("mage");
    set_mlevel("mage", 25);
    set_guild_level("mage", 25);
    add_search_path("/cmds/wizard");
    set_hp(500);
    set_exp(5000);
    set_property("swarm", 1);
    set_overall_ac(0);
    set_stats("strength",15);
    set_stats("dexterity",16);
    set_stats("intelligence",19);
    set_stats("wisdom",17);
    set_stats("constitution",16);
    set_stats("charisma",9);
    set("aggressive", 20);
    set_attacks_num(2);
    set_damage(3,10);
    set_base_damage_type("bludgeoning");
    add_limb("hand-like torrent of water", "head", 0, 0, 0);
    set_attack_limbs(({"hand-like torrent of water"}));    
    set_spells(({"chill touch",
                 "cone of cold", 
                 "lightning bolt",
                 "ice storm"}));
    set_spell_chance(75);
    add_money("gold",random(2000)+1000);
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("breath of winter");
      ob->move(TO);
    set_resistance("cold",15);
    set_resistance("fire",-15);
}

void init()
{
    object *live;
    int i;

    ::init();

    live = all_inventory(ETO);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);

    for(i=0;i<sizeof(live);i++)
    {
        if(!objectp(live[i])) continue;
        kill_ob(live[i],1);
        if(i>100) {tell_room(ETO,"loop error in init() in arctic_tempest"); break;}
    }
}
