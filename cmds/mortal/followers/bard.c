// plot follower granted to Sadhara, Jan 2018 - N.
#include <std.h>
#include <daemons.h>
inherit "/cmds/mortal/followers/follower.c";

int skins;

void create(){
        object ob;
        int i,j,k,num;
        ::create();
        set_class("bard");
        set_id(({"follower", "retainer"}));
        set_race("human");
        set_exp(2000);
        set_body_type(query_race());
        set_gender("female");
        set_long("This young bard follows her hero in hopes of somehow providing assistance.");
        set_guild_level("bard",query_hd());
        set_spells(({"resonating word","resonating word","daze","hold person","blindness","forgotten melody"}));
        set_spell_chance(98);
        ob = new("/d/common/obj/potion/healing");
        ob->move(TO);
        ob->set_uses(random(25)+25);
        set_money("gold",random(3000));
        set_mob_magic_resistance("average");
}

equip_me(){
        object ob;

        set_overall_ac(-5);
        ob = new("/d/common/obj/clothing/magerobe");
        ob->move(TO);
        ob->set_property("monsterweapon",1);
}
