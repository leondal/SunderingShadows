#include <std.h>

inherit "/d/dagger/cave2/mon/wonder.c";

void create() {
    ::create();
    set_name("ogre major");
    set_id( ({"ogre", "warrior", "major", "ogre major", "cavemon"}) );
    set_short("Ogre major");
    set_long(
      "This is a large and ugly ogre warrior.  He is hefting what looks like a large tree on his shoulder, yet he is able to swing it with ease.  As you look into his eyes you see a deep hatred, a hatred for all life."
    );
    set_gender("male");
    set("race", "ogre");
    set_body_type("human");
    set_overall_ac(3);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 19);
    set_hd(19,5);
    set_exp(2900);
    set_stats("strength", 18);
    set_stats("dexterity", 8);
    set_stats("constitution", 18);
    set_stats("intelligence", 3);
    set_stats("wisdom", 5);
    set_stats("charisma", 3);
    set("aggressive", 20);
    set_alignment(9);
    set_size(3);
    set_max_hp(175+random(50));
    set_hp(query_max_hp());
    set_property("full attacks", 1);
    add_money("silver", random(500));
    add_money("gold", random(150));
    new("/d/dagger/cave2/obj/treetrunk")->move(TO);
    command("wield club");
}
