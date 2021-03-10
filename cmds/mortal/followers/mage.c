// test mage monster

#include <std.h>
#include <daemons.h>
inherit "/cmds/mortal/followers/follower.c";


int skins;

void create(){
        object ob;
        int i,j,k,num;
        ::create();
        set_class("mage");
        set_id(({"follower", "retainer"}));
        set_race("human");
        set_exp(2000);
        set_body_type(query_race());
        switch(random(2)) {
        case 0:
                set_gender("male");
                break;
        case 1:
                set_gender("female");
                break;
        }
        set_long("This scholarly mage follows his liege lord in hopes of providing insight and knowledge."
                 );
        set_guild_level("mage",query_hd());
        set_spells(({"magic missile", "lightning bolt", "cone of cold", "fireball", "vampiric touch","powerword stun"}));
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
        ob = new("/d/tharis/obj/white_robes");
        ob->set_property("enchantment",query_level()/8);
        ob->move(TO);
        ob->set_property("monsterweapon",1);
}
