// plot follower granted to Eoin, Dec 2015 - N. Experiment in adding off-class followers!
#include <std.h>
#include <daemons.h>
inherit "/cmds/mortal/followers/follower.c";

int skins;

void create(){
        object ob;
        int i,j,k,num;
        ::create();
        set_class("psion");
        set_id(({"follower", "retainer"}));
        set_race("human");
        set_exp(2000);
        set_body_type(query_race());
        set_gender("female");
        set_long("This young psion follows her hero in hopes of somehow providing assistance.");
        set_guild_level("psion",query_hd());
        set_spells(({"mind thrust", "swarm of crystals", "energy bolt", "power leech", "breath of the black dragon"}));
        set_spell_chance(98);
        ob = new("/d/common/obj/potion/healing");
        ob->move(TO);
        ob->set_uses(random(25)+25);
        set_money("gold",random(3000));
        set_mob_magic_resistance("high");
}

equip_me(){
        object ob;
        set_overall_ac(-5);
        ob = new("/d/common/obj/clothing/magerobe");
        ob->move(TO);
        ob->set_property("monsterweapon",1);
}
