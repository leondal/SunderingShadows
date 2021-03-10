#include <std.h>
#include "../valley.h"
inherit VM_WANDER;

void add_stuff();

void create()
{
    ::create();
    set_name("pixie");
    set_id(({ "pixie", "fairy", "fairie", "monster" }));
    set_short("A cute little pixie");
    set_long(
        "The pixie is about two and a half feet tall with beautiful" +
        " silver wings. He is dressed in brightly colored clothing" +
        " with an odd hat and some shoes with curled toes that" +
        " simply do not match his outfit. He is carrying a gaudy" +
        " looking scabbard with a tiny longsword in it. Strange," +
        " you didn't think they made orange scabbards, only a pixie" +
        " would wear one."
        );
    set_size(1);
    set_race("pixie");
    set_gender("male");
    set_body_type("kender");
    set_hd(15, 4);
    set_max_level(20);
    set_alignment(5);
    set_overall_ac(5);
    set_max_hp(random(25) + 50);
    set_hp(query_max_hp());
    set_property("swarm", 1);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_level(15);
    set_stats("intelligence", 16);
    set_stats("dexterity", 20);
    new(OBJ + "tlongsword")->move(TO);
    command("wield sword");
    new(OBJ + "sshield")->move(TO);
    new(OBJ + "pshoes")->move(TO);
    new(OBJ + "phat")->move(TO);
    command("wearall");
    add_money("gold", random(500));
    set_mob_magic_resistance("average");
    set_exp(1550);
    set_wimpy(20);
    add_stuff();
}

void run_away()
{
    tell_room(environment(ETO), "%^GREEN%^The pixie makes a hasty" +
              " retreat.");
    TO->set_invis();
    ::run_away();
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

void add_stuff()
{
    object ob;

    //::reset();
    if (!random(3)) {     // chg to 1/3 from 2 while fixing cases *Styx* 11/23/03
        if (!present("scroll")) {
            ob = new("/d/magic/scroll");
            ob->set_spell(4);
            ob->move(this_object());
        }
    }
    if (!present("gem") && !random(3)) {     // chg. to 1/3 chances *Styx* 11/23/03
        //if(!random(2)) {
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

        case 376..399:                          // was 400, outside switch *Styx*
            new(OBJ + "gem")->move(TO);
            new(OBJ + "gem")->move(TO);
            new(OBJ + "gem")->move(TO);
            new(OBJ + "gem")->move(TO);
            break;
        }
        //}
    }
    if (!present("jewelry")) {
        if (!random(3)) {
            switch (random(200)) {
            case 0..100:
                new(OBJ + "jewelry")->move(TO);
                break;

            case 101..175:
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;

            case 176..199:                      // was 200 outside switch *Styx* 11/23
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;
            }
        }
    }
}
