//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit SM_WANDER;

void create()
{
    ::create();
    set_name("nixie");
    set_id(({ "nixie", "sprite", "monster","fey" }));
    set_short("An attractive nixie");
    set_long(
        "The wide %^WHITE%^silver%^CYAN%^ eyes are the most fascinating thing about" +
        " this creature, instantly capturing your attention. She is" +
        " slender and very comely with slightly elven features. Her" +
        " skin is lightly scaled and pale green, contrasting nicely with her dark" +
        " green hair. Strands of sea shells and pearls have been" +
        " entwined in her lusterous hair. Her fingers and toes are" +
        " webbed, but this doesn't diminish from her attractiveness." +
        " She wears a very tight-fitting wrap woven from colorful" +
        " seaweeds."
        );
    set_gender("female");
    set_race("sprite");
    set_body_type("kender");
    set_hd(10, 2);
    set_max_level(20);
    set_size(1);
    set_overall_ac(7);
    set_max_hp(random(20) + 40);
    set_hp(query_max_hp());
    set_property("swarm", 1);
    set_alignment(5);
    set_mob_magic_resistance("average");
    set_class("fighter");
    set_mlevel("fighter", 10);
    set_level(15);
//	set_exp(1690);
    set_new_exp(10, "normal");
    set_stats("charisma", 18);
    set_stats("dexterity", 19);
    new(OBJ + "sea_dagger")->move(TO);
    command("wield dagger");
    set_property("swarm", 1);
}

void init()
{
    object ob;

    ::init();
    if (ALIGN->is_evil(TP) && !TP->query_invis()) {
        kill_ob(TP, 1);
        return 1;
    }
}

void reset()
{
    ::reset();
    if (!present("gem")) {
        if (!random(4)) {
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
    if (!present("jewelry")) {
        if (!random(5)) {
            switch (random(200)) {
            case 0..100:
                new(OBJ + "ornaments")->move(TO);
                break;

            case 101..175:
                new(OBJ + "ornaments")->move(TO);
                new(OBJ + "ornaments")->move(TO);
                break;

            case 176..200:
                new(OBJ + "ornaments")->move(TO);
                new(OBJ + "ornaments")->move(TO);
                new(OBJ + "ornaments")->move(TO);
                break;
            }
        }
    }
}
