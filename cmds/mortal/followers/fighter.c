//Modded to add basic fighter feats - Octothorpe 7/29/10
// test ranger monster

#include <std.h>
#include <daemons.h>
inherit "/cmds/mortal/followers/follower.c";



void create(){
        object ob;
        ::create();
        set_class("fighter");
        set_id(({"follower", "retainer"}));
        set_race("human");
        set_exp(2000);
        set_body_type(query_race());
        set_gender("male");
        set_long("This stout fellow is well equiped. He follows his leige lord with dedication and devotion."
                 );
        ob = new("/d/common/obj/potion/healing");
        ob->move(TO);
        ob->set_uses(random(25)+50);
        set_money("gold",random(3000));
        set_mob_magic_resistance("none");
        set_property("full attacks",1);
        add_search_path("/cmds/fighter");
        switch((int)TO->query_level())
        {
        case 1..6:
                TO->set_monster_feats(({"parry"}));
                break;
        case 7..12:
                TO->set_monster_feats(({"parry","powerattack"}));
                break;
        case 13..18:
                TO->set_monster_feats(({"parry","powerattack","shatter"}));
                break;
        case 19..24:
                TO->set_monster_feats(({"parry","powerattack","shatter","sunder"}));
                break;
        default:
                TO->set_monster_feats(({"parry","powerattack","shatter","sunder","rush"}));
                break;
        }
}



equip_me(){
        object ob;
        ob = new("/d/common/obj/weapon/longsword");
        ob->set_property("enchantment",query_level()/8);
        ob->move(TO);
        ob->set_property("monsterweapon",1);
        ob->set_size(query_size());

        set_overall_ac(-5);
        ob = new("/d/common/obj/armour/fullplate");
        ob->set_property("enchantment",query_level()/8);
        ob->move(TO);
        ob->set_property("monsterweapon",1);

        ob = new("/d/common/obj/armour/shield");
        ob->set_property("enchantment",query_level()/8);
        ob->move(TO);
        ob->set_property("monsterweapon",1);
}
