#include "/d/islands/dinosaur/lake/lake.h"
#include <std.h>

inherit MONSTER;

void create(){
    ::create();
    set_property("swims", 1);
    set_property("water breather", 1);
    set_name("Merman");
    set_id( ({"merman", "fish person", "man", "fish", "mermaid"}) );
    set_short("Merman");
    set_long(
      "This strange creature looks to be a powerful man from the waist up, but from the waist down his body has been replaced with that of a fish.  You can see a deep pain in his eyes, and you get the feeling that this was not his original slot in life, that there was somthing that made him this way."
    );
    set_race("merman");
    set_gender("male");
    set_body_type("merperson");
    set_hd(20, 9);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_property("full attacks", 1);
    set_overall_ac(0);
    set_stats("strength", 18);
    set_stats("constitution", 16);
    set_stats("dexterity", 19);
    set("aggressive", 10);
    set_alignment(5);
    set_hp(150+random(100));
    new(OPATH "trident.c")->move(TO);
    command("wield trident");
}
