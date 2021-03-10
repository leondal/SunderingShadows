#include <std.h>

inherit "/d/dagger/cave2/mon/wonder.c";

void create() {
    ::create();
    set_name("ogre colonel");
    set_id( ({"ogre", "warrior", "colonel", "ogre colonel", "cavemon"}) );
    set_short("Ogre colonel");
    set_long(
      "This is a large and ugly ogre warrior.  He is hefting what looks like a large tree on his shoulder, yet he is able to swing it with ease.  As you look into his eyes you see a deep hatred, a hatred for all life."
    );
    set_gender("male");
    set("race", "ogre");
    set_body_type("human");
    set_overall_ac(1);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 23);
    set_hd(23,5);
    set_exp(3500);
    set_stats("strength", 18);
    set_stats("dexterity", 8);
    set_stats("constitution", 18);
    set_stats("intelligence", 3);
    set_stats("wisdom", 5);
    set_stats("charisma", 3);
    set("aggressive", 20);
    set_alignment(9);
    set_size(3);
    set_max_hp(200+random(50));
    set_hp(query_max_hp());
    set_property("full attacks", 1);
    add_money("silver", random(500));
    add_money("gold", random(150));
    new("/d/dagger/cave2/obj/treetrunk")->move(TO);
    command("wield club");
}
