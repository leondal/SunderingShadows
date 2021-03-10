//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//added max_level - Styx 7/20/01

#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/std/monster";
int xx;
int FLAG;
#define PLACE1 "/d/darkwood/tabor/road/road1";
#define PLACE2 "/d/darkwood/tabor/road/road1";
#define PLACE3 "/d/darkwood/tabor/road/road2";
#define PLACE5 "/d/darkwood/tabor/road/road3";

void create()
{
    ::create();
    set_name("goblin king");
    set_id(({ "goblin", "king", "goblin king" }));
    set_short("Goblin king");
    set("aggressive", 5);
    set_hd(10, 4);
    set_long("The Goblin before you is the Royal King of the "
             "Goblin Army of Shadow. He is a hero within the Goblin ranks and "
             "rules through tyranny and an iron fist. He also looks incredibly "
             "battle worthy and ruthless. It is rumoured he made a pact with "
             "a sorceror of the black arts for extra inner power."
             );
    set_level(8);
    set_class("fighter");
    set_body_type("humanoid");
    set_alignment(9);
    set_race("goblin");
    set_gender("male");
//    set_exp(800);
    set_new_exp(8, "boss");
    set_max_level(11);
    set_ac(4);
    set_wielding_limbs(({ "left hand", "right hand" }));
    set_stats("dexterity", 15);
    set_stats("wisdom", 18);
    set_stats("intelligence", 18);
    set_stats("strength", 17);
    set_max_hp(95);
    set_hp(95);
    set_emotes(3, ({
        "Goblin king chuckles to himself.",
        "%^CYAN%^Goblin king says: %^RESET%^Bow before me you worthless silly scum!",
        "Goblin king looks you over with distaste.",
        "Goblin king examines his sceptre.",
        "%^CYAN%^Goblin king says: %^RESET%^Where's that worthless assassin?",
        "%^CYAN%^Goblin king says: %^RESET%^That rogue better not be stealin' MY gold!",
        "Goblin king glances to the north and whispers to a guard.",
    }), 0);
    TO->add_money("gold", random(200) + 50);
    TO->add_money("silver", random(1200) + 150);
    TO->add_money("copper", random(11500) + 500);
    new(OPATH "sceptre.c")->move(TO);
    command("wield sceptre");
    new(OPATH "cloak.c")->move(TO);
    command("wear cloak");
    new(OPATH "crown.c")->move(TO);
    command("wear crown");
    set_property("swarm", 1);
/* special isn't really a spell and isn't going to work this way, so commenting it out for now while tuning them back down to level 6-8ish levels *Styx*  3/20/05
    set_spell_chance(20);
    set_spells( ({"special"}) );
    add_action( "special_spell","special" );
 */
    set_monster_feats(({
        "blade block",
        "sweepingblow",
        "impale",
        "light weapon",
        "strength of arm"
    }));
    set_funcs(({
        "sweepit",
        "impaleit"
    }));
    set_func_chance(30);
}

int special_spell()
{
    object me = TO;
    object vic = me->query_current_attacker();
    xx = random(2) + 1;
    switch (xx) {
    case 1:
        me->force_me("say Now you DIE!!");
        me->force_me("rush " + vic->query_name());
        return 1;

    case 2:
        if ((int)me->query_hp() < 20) {
            return 1;
        }
        me->force_me("say This should slow you down!");
        tell_room(ETO,
                  "%^BOLD%^%^MAGENTA%^The Goblin King unleashes a mind bolt at "
                  + vic->query_cap_name() + "!%^RESET%", ({ TO, vic }));
        tell_object(vic,
                    "%^BOLD%^%^MAGENTA%^The Goblin King unleashes a mind bolt at "
                    "you!%^RESET%^"
                    );
        vic->add_hp(-(random(10) + 8));
        vic->do_damage("torso", 0);
        vic->set_paralyzed(random(10), "You are regaining your senses!");
        me->add_hp(-2);
        me->set_magic_round();
        me->set_disable();
        return 1;
    }
}

void reset()
{
    ::reset();
    if (!random(3)) {
        FLAG = 0;
    }
    if (!random(60) && FLAG == 0) {
        call_out("invasion", 1);
    }
}

void invasion()
{
    object ob1, ob2, ob3, ob4, ob5;
    write("%^ORANGE%^The king strikes the gong with a solid blow from his "
          "sceptre.\n%^YELLOW%^The gong rings out and flashes briefly with a "
          "%^RED%^red%^YELLOW%^ glow.%^RESET%^");
    message("invasion",
            "%^BOLD%^%^GREEN%^A strange gong rings out across the lands.\n"
            "%^ORANGE%^Goblin raiders have received orders to depart for invasion!"
            "%^RESET%^", users());
    ob1 = PLACE1;
    new(MPATH "raider.c")->move(ob1);
    new(MPATH "raider.c")->move(ob1);
    new(MPATH "raider.c")->move(ob1);
    new(MPATH "raider.c")->move(ob1);
    ob2 = PLACE2;
    new(MPATH "raider.c")->move(ob2);
    new(MPATH "raider.c")->move(ob2);
    new(MPATH "raider.c")->move(ob2);
    ob3 = PLACE3;
    if (!random(2)) {
        new(MPATH "raider.c")->move(ob3);
    }
    new(MPATH "raider.c")->move(ob3);
    new(MPATH "raider.c")->move(ob3);
    new(MPATH "raider.c")->move(ob3);
    new(MPATH "raider.c")->move(ob3);
    ob5 = PLACE5;
    new(MPATH "raider.c")->move(ob5);
    new(MPATH "raider.c")->move(ob5);
    new(MPATH "raider.c")->move(ob5);
    new(MPATH "raider.c")->move(ob5);
    FLAG = 1;
    return 1;
}

void impaleit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("impale " + targ->query_name());
}

void sweepit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("sweepingblow " + targ->query_name());
}
