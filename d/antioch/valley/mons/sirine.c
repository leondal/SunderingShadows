//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit SM_WANDER;

int SING = 0;

void create()
{
    int type;

    switch (random(2)) {
    case 0:
        type = "%^GREEN%^green%^CYAN%^";
        break;

    case 1:
        type = "%^WHITE%^silver%^CYAN%^";
        break;
    }
    ::create();
    set_name("sirine");
    set_id(({ "sirine", "monster", "female" }));
    set_short("A beautiful sirine");
    set_long(
        "This gorgeous woman is what is known as a sirine. Normally" +
        " found underwater, they are sometimes known to roam shores." +
        " Her " + type + " hair is thick and long, flowing down her back." +
        " Her skin is smooth and beautiful, a %^BOLD%^pale blue%^RESET%^%^CYAN%^ color. Her" +
        " figure is shown off quite well by her scanty clothes. A" +
        " %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^ sea shell bikini top covers her chest and a long" +
        " %^MAGENTA%^purple%^CYAN%^ skirt with slits up both sides" +
        " serves to highlight her tiny waist. She carries a short" +
        " sword for protection."
        );
    set_gender("female");
    set_race("sirine");
    set_body_type("humanoid");
    set_hd(20, 4);
    set_max_level(23);
    set_size(2);
    set_overall_ac(3);
    set_alignment(4);
    set_mob_magic_resistance("average");
    set_max_hp(random(50) + 150);
    set_hp(query_max_hp());
//	set_exp(8000);
    set_new_exp(20, "normal");
    set_property("swarm", 1);
    set("aggressive", 10);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_class("mage");
    set_mlevel("mage", 15);
    set_stats("charisma", 25);
    set_stats("dexterity", 18);
    set_funcs(({ "song", "touch" }));
    set_func_chance(90);
    new(OBJ + "skirt")->move(TO);
    new(OBJ + "bikini")->move(TO);
    new(OBJ + "sirine_sword")->move(TO);
    if (!random(6)) {
        new(OBJ + "coral_ring")->move(TO);
    }
    command("wearall");
    command("wield sword");
    add_money("electrum", random(600));
    set_wimpy(30);
    set_monster_feats(({ "indomitable" }));
}

//invis\\

void run_away()
{
    tell_room(ETO, "%^BOLD%^%^BLUE%^The sirine" +
              " decides it's time to make a hasty retreat.");
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

void song(object targ)
{
    int i, j;
    object* inven;

    inven = all_living(ETO);
    j = sizeof(inven);

    if (SING == 0) {
        tell_room(ETO, "%^BOLD%^The sirine begins to sing a" +
                  " heart-breakingly beautiful song.");
        for (i = 0; i < j; i++) {
            if (!objectp(inven[i])) {
                continue;
            }
            if (inven[i] == TO) {
                continue;
            }
            if (!"/daemon/saving_throw_d.c"->will_save(inven[i], -14)) {
                tell_object(inven[i], "%^BOLD%^%^CYAN%^The sirine's song" +
                            " touches your heart and you can only think of pleasing" +
                            " this beautiful creature.");
                if (sizeof(query_attackers()) > 1) {
                    inven[i]->cease_all_attacks();
                    remove_attacker(targ);
                    inven[i]->set_attackers(TO->query_attackers());
                    inven[i]->force_me("protect sirine");
                }else {
                    tell_object(inven[i], "%^BOLD%^You stand helplessly" +
                                " before the wrath of this beautiful creature that" +
                                " you can't believe you once sought to kill!");
                    inven[i]->force_me("drop all");
                    inven[i]->set_paralyzed(random(50) + 75, "You will only do what" +
                                            " the sirine commands!");
                }
            }else {
                tell_object(inven[i], "%^CYAN%^You manage to resist the" +
                            " charms of the sirine.");
            }
            SING = 1;
            return 1;
        }
    }
    return 1;
}

void touch(object targ)
{
    int x, y;

    x = targ->query_stats("intelligence");
    y = x - 2;

    tell_object(targ, "%^BOLD%^%^GREEN%^The sirine reaches out" +
                " and touches you.");
    tell_room(ETO, "%^BOLD%^%^GREEN%^The sirine reaches out and" +
              " touches " + targ->query_cap_name() + ".", targ);
    if (!"/daemon/saving_throw_d.c"->will_save(targ, -15)) {
        tell_object(targ, "%^BOLD%^%^GREEN%^Poison burns through" +
                    " your body and you feel strangely light headed.");
        tell_room(ETO, "%^BOLD%^%^GREEN%^" + targ->query_cap_name() + "" +
                  " looks sick and shakes " + targ->query_possessive() + "" +
                  " head groggily.", targ);
        targ->add_poisoning(35);
        targ->add_stat_bonus("intelligence", -(y));
    }else {
        tell_object(targ, "%^GREEN%^You manage to resist the" +
                    " deadly touch of the sirine.");
        tell_room(ETO, "%^GREEN%^" + targ->query_cap_name() + " holds" +
                  " " + targ->query_possessive() + " ground against the sirine's" +
                  " touch.", targ);
    }
}

void reset()
{
    ::reset();
    SING = 0;
    if (!present("gem")) {
        if (!random(2)) {
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
}
