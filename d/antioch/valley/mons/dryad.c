//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit VM_WANDER;

string color;
void seduce_man(object targ);

void create()
{
    ::create();
    set_name("dryad");
    set_id(({ "monster", "dryad", "tree sprite", "sprite" }));
    set_short("A lovely dryad");
    switch (random(2)) {
    case 0:
        color = "amber";
        break;

    case 1:
        color = "violet";
        break;

    case 2:
        color = "dark green";
        break;
    }
    set_long(
        "A stunning dryad stands before you. You can tell it's summer here" +
        " by her appearance. Her skin is slightly tanned and her hair" +
        " is a deep green. Her features are elven with her chiseled" +
        " face and pointed ears. She blends in to her surroundings" +
        " perfectly, her dress is a mixture of brown and green hues." +
        " Her lovely " + color + " eyes stare back at you, watching your" +
        " every move carefully."
        );
    set_size(2);
    set_body_type("human");
    set_gender("female");
    set_race("dryad");
    set_hd(15, 4);
    set_max_level(20);
    set_overall_ac(3);
    set_mob_magic_resistance("high");
//	set_exp(9750);
    set_new_exp(15, "normal");
    set_max_hp(random(50) + 75);
    set_hp(query_max_hp());
    set_level(15);
    set_max_level(20);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_alignment(7);
    set_stats("charisma", 20);
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_property("swarm", 1);
    add_money("electrum", random(800));
    set_funcs(({ "charm" }));
    set_func_chance(10);
    set_property("swarm", 1);
    set_emotes(8, ({
        "The dryad tosses her hair over her shoulder.",
        "The dryad reaches out and caresses you softly.",
        "The dryad runs her fingers through your hair.",
        "The dryad giggles and winks at you.",
        "The dryad motions you closer.",
        "The dryad smiles at you and stares into your eyes.",
    }), 0);
    new(OBJ + "dknife")->move(TO);
    command("wield kama");
    if (!random(8)) {
        new(OBJ + "buckler")->move(TO);
        command("wear buckler");
    }
}

void charm(object targ)
{
    if ((string)targ->query_gender() == "male") {
        if (!"/daemon/saving_throw_d.c"->will_save(targ, -14)) {
            tell_object(targ, "%^BOLD%^%^RED%^You are charmed" +
                        " by the lovely dryad.");
            tell_room(ETO, "%^BOLD%^%^RED%^" + targ->query_cap_name() + "" +
                      " gets a goofy grin on his face and smiles at the dryad.", targ);
            targ->set_attackers(TO->query_attackers());
            targ->force_me("drop all");
            targ->set_paralyzed(75, "You're charmed by the dryad!");
            return 1;
        }else {
            tell_object(targ, "%^RED%^Luckily you see through the" +
                        " dryad's charms and do not fall for her ruse.");
            return 1;
        }
    }
}

void init()
{
    ::init();
    if (interactive(TP) && (string)TP->query_gender() == "male") {
        seduce_man(TP);
    }
}

void seduce_man(object targ)
{
    if ((mixed*)TO->query_attackers() != ({ })) {
        return;
    }

    if (targ->query_stats("charisma") < 16) {
        return;
    }

    if (targ->query_invis()) {
        return;
    }

    tell_object(targ, "The dryad winks at you and moves closer" +
                " towards you, putting her hand on your arm and staring" +
                " longingly into your eyes.");
    tell_room(ETO, "The dryad winks at " + targ->query_cap_name() + "" +
              " and moves closer to him, putting her hand on his arm and" +
              " staring longingly in his eyes.", targ);
    if (!"daemon/saving_d"->saving_throw(targ, "spell")) {
        tell_object(targ, "The dryad reaches up and brushes her" +
                    " lips against yours, sending shivers down your spine.");
        tell_room(ETO, "The dryad kisses " + targ->query_cap_name() + "" +
                  " softly on the lips.", targ);
        targ->force_me("drop all");
        TO->force_me("get all");
        tell_object(targ, "%^YELLOW%^You give everything you own to the dryad" +
                    " so that she might be happy.");
        targ->set_paralyzed(10, "You're too enchanted with the" +
                            " dryad to do that.");
        return 1;
    }else {
        tell_object(targ, "The dryad reaches up to kiss you and" +
                    " looks hurt as you pull back.");
        tell_room(ETO, "The dryad tries to kiss " + targ->query_cap_name() + "," +
                  " but he pulls away from her.", targ);
        return 1;
    }
}

void reset()
{
    ::reset();
    if (random(2)) {
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
}
