//Modded to add basic fighter feats - Octothorpe 7/29/10
// test ranger monster

#include <std.h>
#include <daemons.h>
inherit "/cmds/mortal/followers/follower.c";



void create(){
        object ob;
        ::create();
        set_class("monk");
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
   
        switch((int)TO->query_level())
        {
        case 1..6:
                TO->set_monster_feats(({"unarmored defense"}));
                break;
        case 7..12:
                TO->set_monster_feats(({"unarmored defense","evasion"}));
                break;
        case 13..18:
                TO->set_monster_feats(({"unarmored defense","evasion","dodge"}));
                break;
        case 19..24:
                TO->set_monster_feats(({"unarmored defense","evasion","dodge","diamond soul"}));
                break;
        default:
                TO->set_monster_feats(({"unarmored defense","evasion","dodge","diamond soul","perfect self"}));
                break;
        }
}



equip_me(){
        object ob;


        set_overall_ac(-5);
        ob = new("/d/common/obj/armour/padded");
        ob->set_property("enchantment",query_level()/8);
        ob->move(TO);
        ob->set_property("monsterweapon",1);

        ob = new("/d/common/obj/armour/bracers");
        ob->set_property("enchantment",query_level()/8);
        ob->move(TO);
        ob->set_property("monsterweapon",1);
}
