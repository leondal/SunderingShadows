#include <std.h>
#include "../ruins.h"
inherit MONSTER;

void create()
{
    object obj;

    ::create();
    set_name("grimlock");
    set_short("A scaly grimlock");
    set_id(({ "grimlock", "scaly grimlock", "monster" }));
    set_long(
        "The grimlock is a disgusting creature. He is covered in thick, scaly" +
        " green skin and has filthy black hair that looks more like a mane. His" +
        " teeth are very white, however, and very, very sharp. His eyes are milky" +
        " white and completely blind, but grimlocks have adapted their other senses" +
        " so that they are at no disadvantgage. His ears are large and pointed," +
        " able to hear things quite well, and his big nose is good for smelling" +
        " people - especially humans, which they love to eat. He is large and" +
        " quite muscular. A green-gray leather hide covers his torso, and some" +
        " boots cover his feet. In his hands is a very large battle axe that he" +
        " holds with obvious proficiency."
        );
    set_gender("male");
    set_race("grimlock");
    set_body_type("humanoid");
    set_hd(20, 4);
    set_max_hp(125 + random(40));
    set_hp(query_max_hp());
    set_alignment(6);
    set_overall_ac(-10);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_level(20);
    set_property("full attacks", 1);
    set_max_level(29);
    set_exp(7000);
    set_stats("strength", 20);
    set_property("swarm", 1);
    set("aggressive", 25);
    set_mob_magic_resistance("average");
    add_money("gold", 50 + random(200));
    add_money("silver", 20 + random(100));
    add_money("copper", 100 + random(500));
    if (!random(20)) {
        new(OBJ + "bloodlust")->move(TO);
    }else {
        new(OBJ + "battle_axe")->move(TO);
    }
    command("wield axe");
    if (!random(4)) {
        new(OBJ + "jerkin")->move(TO);
        command("wear jerkin");
    }
    if (!random(10)) {
        new(OBJ + "leather")->move(TO);
        command("wear hide");
    }
    if (!present("hide")) {
        obj = new("/d/common/obj/armour/hide");
        obj->move(TO);
        obj->set_property("monster weapon", 1);
        command("wear hide");
    }
}
