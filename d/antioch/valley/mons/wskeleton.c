//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//added the undead property so it would behave appropriately ~Circe~ 4/27/11

#include <std.h>
#include "../valley.h"
inherit FM_WANDER;

void create()
{
    object ob;
    ::create();
    set_name("skeleton warrior");
    set_id(({ "undead", "skeleton", "warrior", "monster", "skeleton warrior", "fighter", "undead warrior" }));
    set_short("A skeleton warrior");
    set_long(
        "A noble skeleton warrior stands here, still clad in the the" +
        " now dirty clothes he wore in life. His garb marks him as an" +
        " elite warrior. Now he is forced to wander the realms at the" +
        " mercy of whatever master wishes to control him."
        );
    set_property("weapon resistance", 1);
    set_mob_magic_resistance("average");
    set_hd(20, 4);
    set_max_level(15);
    set_overall_ac(-2);
//        set_exp(9500);
    set_new_exp(20, "normal");
    set_alignment(6);
    set_property("swarm", 1);
    set_property("undead", 1);
    set("aggressive", 15);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_stats("dexterity", 1);
    set_stats("charisma", 1);
    set_gender("male");
    set_body_type("human");
    set_race("skeleton");
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_max_hp(random(100) + 150);
    set_hp(query_max_hp());
    new(OBJ + "2hsword")->move(TO);
    command("wield sword");
    add_money("gold", random(400));
    if (!random(20)) {
        new(OBJ + "rusty_armor")->move(TO);
        command("wear armor");
    }
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("bone dust");
        ob->move(TO);
    }
    set_resistance("negative energy", 10);
    set_resistance("positive energy", -10);
}

void reset()
{
    if (random(3)) {
        if (!present("gem")) {
            switch (random(400)) {
            case 0..300:
                new(OBJ + "gem")->move(TO);
                break;

            case 301..350:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;

            case 351..375:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;

            case 376..400:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;
            }
        }
    }
    if (random(2)) {
        if (!present("jewelry")) {
            switch (random(200)) {
            case 0..100:
                new(OBJ + "jewelry")->move(TO);
                break;

            case 101..175:
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;

            case 176..200:
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;
            }
        }
    }
}
