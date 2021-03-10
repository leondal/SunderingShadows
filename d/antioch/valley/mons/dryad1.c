//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Added wear necklace when the dryads - Cythera 3/05
#include <std.h>
#include "../valley.h"
inherit MONSTER;

void seduce_man(object targ);

void create()
{
    ::create();
    set_name("dryad");
    set_id(({ "monster", "dryad", "tree sprite", "sprite" }));
    set_hd(20, 4);
    set_max_level(20);
    set_size(2);
    set_body_type("human");
    set_gender("female");
    set_race("dryad");
    set_overall_ac(-3);
//	set_exp(9500);
    set_new_exp(20, "normal");
    set_max_hp(random(50) + 130);
    set_hp(query_max_hp());
    set_mob_magic_resistance("high");
    set("aggressive", 15);
    set_property("swarm", 1);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_class("mage");
    set_mlevel("mage", 15);
    set_property("full attacks", 1);
    set_alignment(7);
    set_stats("charisma", 20);
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_property("swarm", 1);
    add_money("electrum", random(800));
    if (!random(5)) {
        new(OBJ + "dryad_staff")->move(TO);
        command("wield staff");
    }else {
        new("/d/common/obj/weapon/quarter_staff.c")->move(TO);
        command("wield staff");
    }
    if (!random(10)) {
        new(OBJ + "vine_necklace")->move(TO);
        command("wear necklace");
    }
    set_emotes(8, ({
        "The dryad tosses her hair over her shoulder.",
        "The dryad reaches out and caresses you softly.",
        "The dryad runs her fingers through your hair.",
        "The dryad giggles and winks at you.",
        "The dryad motions you closer.",
        "The dryad smiles at you and stares into your eyes.",
    }), 0);
    set_emotes(10, ({
        "The dryad screams at you!",
        "The dryad looks very angry.",
        "The dryad attempts to push you out of her tree.",
    }), 1);
}

int query_watched()
{
    return 10000000;
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
    if (!"/daemon/saving_throw_d.c"->will_save(targ, -14)) {
        tell_object(targ, "The dryad reaches up and brushes her" +
                    " lips against yours, sending shivers down your spine.");
        tell_room(ETO, "The dryad kisses " + targ->query_cap_name() + "" +
                  " softly on the lips.", targ);
        targ->force_me("drop all");
        TO->force_me("get all");
        tell_object(targ, "%^YELLOW%^You give everything you own to the dryad" +
                    " so that she might be happy.");
        targ->set_paralyzed(200, "You're too enchanted with the" +
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
