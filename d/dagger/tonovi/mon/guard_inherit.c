#include "/d/dagger/tonovi/town/short.h"
#include "/d/common/common.h"
#include <daemons.h>

inherit GUARDSMAN;

int horn; // used to keep the horn from spamming

void blow_horn(object watchman);
void set_guard_stuff();

void create()
{
    ::create();
    will_open_doors(1);
    set_nogo(({ "/d/dagger/tonovi/road2" }));
    if (!random(3)) {
        set_detecting_invis(1);
    }
    set_name("Tonovi Guard");
    set_id(({ "guard", "tonovi guard", "town guard", "Gtonovimon" }));
    set_short("Tonovi Guard");
    set_long(
"
This is one of the trained guards of Tonovi, a soldier that showed promise and was given the prestigious task of protecting his homeland.Wearing just leather armor, you suspect he is one of the newer recruits.
"
        );
    set_gender("male");
    set_race("human");
    add_attack_bonus(7);
    add_damage_bonus(7);
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
        "rush",
        "damage resistance",
        "improved damage resistance",
        "improved toughness",
        "regeneration",
        "toughness",
        "expertise",
        "knockdown"
    }));
    set_funcs(({
        "rushit",
        "flashit",
        "shatterit",
        "sunderit",
        "rushit",
        "kdit",
        "kdit"
    }));
    set_func_chance(35);
    set_property("full attacks", 1);
    set_mob_magic_resistance("average");
    set_guard_stuff();
}

void set_guard_stuff()
{
    set_jail_location("/d/dagger/tonovi/town/jail1");
    set_guarding("Tonovi");
    set_bad_races(({ "elf", "fey'ri", "half-elf" }));
    set_race_action("capture");
    set_race_messages(([
                           "elf"      : "%^BOLD%^Elves, only good for slaves, grab it!",
                       ]));
    ARREST_MSG = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG = "%^BOLD%^You are under arrest you criminal!";
    RACE_CAPTURE_MSG = "%^BOLD%^Another one for the slave auction since you dared enter the city!";
    EXPEL_MSG = "%^BOLD%^Off with you scum, don't set foot in the city again!";
    KILL_MSG = "%^BOLD%^For the crime of invading the city, you die now!";
    JAIL_MSG = "%^BOLD%^Off to jail until your fate is decided.";
    return;
}

void do_special_combat_actions()
{
    blow_horn(TO);
}

void check_caught(object tp, object targ, int roll)
{
    if (AREALISTS_D->is_jailer(tp, query_guarding(), TO)) {
        return;
    }
    force_me("say I see you " + TPQCN);
    force_me("yell STOP THIEF!");
    force_me("point " + TPQN);
    force_me("rush " + TPQN);
    kill_ob(TP, 1);
}

int isMagic()
{
    return ::isMagic() + detecting_invis();
}

void blow_horn(object ob)
{
    if (!objectp(ob)) {
        return;
    }
    if (horn) {
        return;
    }
    broadcast_area("/d/dagger/tonovi/town", "%^BOLD%^%^YELLOW%^The warning horn blows alerting the city guards.");
    broadcast_area("/d/player_houses/lusell/rooms", "%^BOLD%^%^YELLOW%^You hear the warning from Tonovi.");
    horn = 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!sizeof(query_attackers())) {
        horn = 0; return;
    }
}

void kdit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("knockdown " + targ->query_name());
}

void flashit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("flash " + targ->query_name());
}

void rushit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("rush " + targ->query_name());
}

void sunderit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("sunder " + targ->query_name());
}

void shatterit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("shatter " + targ->query_name());
}
