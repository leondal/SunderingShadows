#include <std.h>
#include "../../defs.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_id(({ "cat", "large cat", "large feline", "feline", "black cat", "black feline" }));
    set_name("black cat");
    set_short("%^BOLD%^%^BLACK%^A large black feline%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^This large cat-like creature crouches low to the %^RESET%^%^ORANGE%^g"
             "%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^ou%^WHITE%^n%^ORANGE%^d%^BOLD%^%^BLACK%^, its mangy fur almost quivering "
             "in anticipation. Its lean body is bristling with muscles, yet it obviously has the swiftness of the fastest "
             "wind. As you look closer at the cat, you realize why it seems so fast. It %^RESET%^%^WHITE%^phases %^BOLD%^"
             "%^BLACK%^quickly into and out of reality, dancing in and out of your perception like a dream. Only its bright "
             "%^RESET%^%^RED%^re%^BOLD%^d%^RESET%^%^RED%^ ey%^BOLD%^e%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^and %^WHITE%^gl"
             "%^YELLOW%^e%^WHITE%^am%^RESET%^%^WHITE%^i%^BOLD%^ng fa%^YELLOW%^n%^WHITE%^gs%^BLACK%^ seem to stick in your "
             "mind.%^RESET%^");
    set_race("cat");
    set_body_type("quadruped");
    if (random(2)) {
        set_gender("male");
    }else {
        set_gender("female");
    }
    set_alignment(5);
    set_nogo(({ MID + "tunnel09", "/d/dagger/kinaro/mines/lower2q" }));
    set_speed(30);
    set_moving(1);
    set_class("fighter");
    set_class("thief");
    set_hd(32, 8);
    set_guild_level("fighter", 32);
    set_mlevel("fighter", 32);
    set_guild_level("thief", 32);
    set_mlevel("thief", 32);
    set_max_hp(450);
    set_hp(450);
    set_property("swarm", 1);
    set_stats("strength", 16);
    set_stats("dexterity", 18);
    set_exp(7500);
    set_overall_ac(-19);
    set("aggressive", "agg_fun");
    set_attack_limbs(({ "left foreclaw", "right foreclaw" }));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(2, 6);
    set_funcs(({ "pounce_me" }));
    set_func_chance(20);
    set_scrambling(1);
    set_hidden(1);
    set_property("magic", 1);
    set_mob_magic_resistance("average");
    force_me("message in slinks in.");
    force_me("message out slinks $D.");
    new(OBJ "catpelt")->move(TO);
}

int agg_fun()
{
    if (sizeof(TO->query_attackers()) < 1) {
        tell_room(ETO, "%^BOLD%^%^BLACK%^A low growl comes from the shadows nearby, and suddenly a black outline "
                  "leaps from the darkness at you!%^RESET%^");
    }
    force_me("kill " + TP->query_name());
    if (TO->query_hidden()) {
        TO->set_hidden(0);
    }
}

void pounce_me(object targ)
{
    int i, freeze;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    tell_object(targ, "%^BOLD%^%^BLACK%^The cat crouches, sh%^RESET%^%^WHITE%^im%^BOLD%^%^BLACK%^m%^WHITE%^e"
                "%^BLACK%^rs, then in a %^WHITE%^fl%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^sh %^BLACK%^is gone... and you fall "
                "backwards under its weight as it appears with its jaws already around your neck!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^BLACK%^The cat crouches, sh%^RESET%^%^WHITE%^im%^BOLD%^%^BLACK%^m%^WHITE%^e"
              "%^BLACK%^rs, then in a %^WHITE%^fl%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^sh %^BLACK%^is gone... and " + targ->QCN +
              " falls backwards as it suddenly appears wrapped around " + targ->QO + " with its jaws already around " + targ->QP +
              " neck!%^RESET%^", targ);
    targ->set_paralyzed(15, "%^BOLD%^%^BLACK%^You're still trying to get back on your feet!%^RESET%^");
    TO->execute_attack();
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (sizeof(TO->query_attackers())) {
        if (TO->query_hidden()) {
            TO->set_hidden(0);
        }
    }else {
        if (!TO->query_hidden()) {
            TO->set_hidden(1);
        }
    }
}
