//Coded by Lujke

#include <std.h>
#include "../tunnel.h"

inherit LRESIST_MOB;
#define MAGE_LVL 21

int danced;

int aggfunc();
void leave_peacefully(object ob);
void leave_peacefully2(object ob);
void dest_effect();
void dance(object ob, int end_time);
void end_dance();
int spell_effect();
void spell_effect2();
void spell_effect3();


create()
{
    object obj;
    ::create();
    danced = 0;
    set_name("devilkin");
    set_id(({ "devil", "devilkin", "tun mon" }));
    set_short("%^RESET%^%^RED%^imp%^BOLD%^%^RED%^i"
              + "%^RESET%^%^RED%^sh %^BOLD%^%^BLACK%^d%^RED%^e%^BOLD%^"
              + "%^BLACK%^v%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^lk%^RED%^i"
              + "%^BOLD%^%^BLACK%^n");
    set_long("%^BOLD%^%^BLACK%^This short, stout humanoid figure has black"
             + " skin, t%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^nged with"
             + " %^RESET%^%^RED%^red%^BOLD%^%^BLACK%^ at places. Its chest"
             + " is bare, but it wears ragged black trousers and"
             + " hobna%^RESET%^i%^BOLD%^%^BLACK%^led"
             + " b%^RED%^oo%^BOLD%^%^BLACK%^ts. A pair of leathery, batlike"
             + " wings protrude from between its shoulder blades, flapping"
             + " occasionally to assist it with balance. Two short, stubby"
             + " %^BOLD%^%^WHITE%^h%^RESET%^o%^BOLD%^%^WHITE%^rns"
             + " %^BOLD%^%^BLACK%^adorn its forehead.");
    set_race("devil");
    set_gender("male");
    set_body_type("human");
    set_hd(20, 4);
    set_class("mage");
    set_mlevel("mage", MAGE_LVL);
    set_level(21);
    set_guild_level("mage", MAGE_LVL);
    set_overall_ac(-4);
    set_size(2);
    set_stats("strength", 15);
    set_stats("intelligence", 16);
    set_stats("dexterity", 18);
    set_stats("charisma", 18);
    set_stats("constitution", 14);
    set_stats("wisdom", 12);
    set_alignment(3);
    set_nogo(({ TUNNELS + "tun15", TUNNELS + "lair", TUNNELS + "tun14" }));
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    add_search_path("/cmds/mage");
    set_spell_chance(25);
    set("aggressive", "aggfunc");
    set_spells(({ "scorcher", "ray of enfeeblement", "fireball",
                  "hold person",
                  "hideous laughter", "scorcher" }));
}

int aggfunc()
{
    int i, j;
    object* things;
    if (TP->query_true_invis()) {
        return 0;
    }
    j = 0;
    things = all_living(ETO);
    for (i = 0; i < sizeof(things); i++) {
        if (things[i]->query_property("hummed") > j
            && things[i]->query_true_invis() == 0) {
            j = things[i]->query_property("hummed");
        }

        if (danced == 1) {
            j = j - 1;
        }
        switch (j) {
        case 1:
            danced = 1;
            call_out("leave_peacefully", random(5), things[i]);
            return 0;

            break;

        case 2:
            danced = 1;
            call_out("dance", 2, things[i], random(100) + 20);
            return 0;

            break;

        default:
        }
    }

    kill_ob(TP, 1);
    call_out("spell_effect", 0);
    force_me("kill " + TPQN + "");
    return 1;
}

void leave_peacefully(object ob)
{
    if (!objectp(ob)) {
        return;
    }
    call_out("leave_peacefully2", random(5), ob);
}

void leave_peacefully2(object ob)
{
    if (!objectp(ob)) {
        return;
    }
    tell_object(ob, TO->query_cap_name() + " looks at you and"
                + " flaps its wings a few times uncertainly, then"
                + " flutters off.");
    tell_room(ETO, TO->query_cap_name() + " looks at "
              + ob->query_cap_name() + " and"
              + " flaps its wings a few times uncertainly, then"
              + " flutters off.", ob);
    dest_effect();
}

void dest_effect()
{
    if (!objectp(TO)) {
        return;
    }
    TO->move("/d/shadowgate/void");
    remove();
}

void dance(object ob, int end_time)
{
    if (end_time) {
        call_out("end_dance", end_time);
    }
    set_emotes(25, ({ "%^MAGENTA%^The %^BOLD%^%^BLACK%^%^d%^RESET%^%^RED%^e"
                      + "%^BOLD%^%^BLACK%^vilk%^BOLD%^%^RED%^i%^BOLD%^"
                      + "%^BLACK%^n %^RESET%^%^MAGENTA%^capers gleefully to"
                      + " the music"

                      , "The %^BOLD%^%^BLACK%^%^d%^RESET%^%^RED%^e%^BOLD%^"
                      + "%^BLACK%^vilk%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^n"
                      + " %^CYAN%^pirouettes %^RESET%^gracefully"

                      , "With a quick shuffle, a %^BOLD%^%^BLACK%^%^d%^RESET%^"
                      + "%^RED%^e%^BOLD%^%^BLACK%^vilk%^BOLD%^%^RED%^i%^BOLD%^"
                      + "%^BLACK%^n %^RESET%^spins right the way round to the"
                      + " beat"

                      , "A %^BOLD%^%^BLACK%^%^d%^RESET%^%^RED%^e%^BOLD%^"
                      + "%^BLACK%^vilk%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^n hops"
                      + " rhythmically from one foot to another", "an %^BOLD%^"
                      + "%^RED%^impish %^BOLD%^%^BLACK%^%^d%^RESET%^%^RED%^e"
                      + "%^BOLD%^%^BLACK%^vilk%^BOLD%^%^RED%^i%^BOLD%^"
                      + "%^BLACK%^n %^RESET%^%^MAGENTA%^spins %^RESET%^and"
                      + " %^BOLD%^%^CYAN%^whirls%^RESET%^ to the music"

                      , TO->query_cap_name() + " claps his hands and %^BOLD%^"
                      + "%^GREEN%^skips%^RESET%^ to the %^MAGENTA%^beat"
                      + "%^RESET%^."

                      , TO->query_cap_name() + "'s body %^MAGENTA%^sways"
                      + "%^RESET%^ to the %^MAGENTA%^rhythm%^RESET%^."

                      , TO->query_cap_name() + " does some %^BOLD%^%^BLUE%^f"
                      + "%^CYAN%^a%^BLUE%^ncy f%^CYAN%^o%^BLUE%^ot w%^WHITE%^o"
                      + "%^BLUE%^rk%^RESET%^ in his %^BOLD%^%^BLACK%^hobn"
                      + "%^RESET%^a%^BOLD%^%^BLACK%^iled b%^BOLD%^%^RED%^oo"
                      + "%^BOLD%^%^BLACK%^ts%^RESET%^.", })
               , 0);
}

void end_dance()
{
    tell_room(ETO, TO->query_cap_name() + " seems to lose interest and"
              + " stops dancing.");
    danced = 1;
    set_emotes(0, ({ "" }), 0);
}

int spell_effect()
{
    force_me("watch");
    new("/cmds/spells/b/_blink.c")->use_spell(TO, TO, MAGE_LVL, 100, "mage");
//   set_paralyzed(2, "You are busy casting spells");
    call_out("spell_effect2", 3);
}

void spell_effect2()
{
//   remove_paralyzed();
    if (!objectp(TO)) {
        return;
    }
    new("/cmds/spells/s/_stoneskin.c")->use_spell(TO, TO, MAGE_LVL, 100, "mage");
    call_out("spell_effect3", 3);
    //  set_paralyzed(2, "You are busy casting spells");
    //casting = 0;
}

void spell_effect3()
{
//   remove_paralyzed();
    if (!objectp(TO)) {
        return;
    }
    new("/cmds/spells/m/_monster_summoning_ii.c")->use_spell(TO, TO, MAGE_LVL, 100, "mage");
}
