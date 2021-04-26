#include <std.h>
#include <daemons.h>
#include "/d/common/common.h"

#define CITYLAW "tonovi law"
#define LVL 65

inherit "/std/guardsman.c";

int horn; // used to keep the horn from spamming

void set_guard_stuff();
void blow_horn(object watchman);

void create()
{
    string rank;
    object obj;
    
    ::create();
    will_open_doors(1);
    set_nogo(({ "/d/dagger/tonovi/road2", "/d/dagger/tonovi/town/street1", "/d/dagger/tonovi/town/wall1", "/d/dagger/tonovi/town/wall3" }));
    set_name("Marvin Loeb");
    set_id(({ "marvin", "marvin loeb", "loeb", "guard", "Marvin Loeb", "Marvin", "Loeb", "champion", CITYLAW }));
    set_short("%^CYAN%^Marvin Loeb%^BLACK%^, C%^RESET%^%^CYAN%^h%^BOLD%^a%^WHITE%^m%^BLACK%^pion of the C%^RESET%^%^CYAN%^i%^BOLD%^t%^WHITE%^y %^BLACK%^G%^RESET%^%^CYAN%^u%^BOLD%^a%^WHITE%^r%^BLACK%^d%^RESET%^");
    set_gender(1);
    set_alignment(3);
    set_race("human");
    set_level(LVL);
    set_hd(LVL + random(10), 1);
    set_max_hp(LVL * 20 + 6000);
    set_hp(TO->query_max_hp());
    set_new_exp(50, "boss");
    set_class("fighter");
    set_guild_level("fighter", LVL);
    set_mlevel("fighter", LVL);
    add_search_path("/cmds/fighter");
    set_fighter_style("soldier");
    set_speed(30);
    add_attack_bonus(15);
    add_damage_bonus(10);
    set_property("add kits", 50);
    set_funcs(({ "rushit", "bashit", "smiteit", "kdit", "disarmit" }));
    set_func_chance(33);
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
        "knockdown",
        "disarm",
        "scramble",
        "dodge",
        "evasion",
        "defensive roll",
        "mobility",
        "death ward",
        "unyielding soul",
        "resistance",
        "improved resistance",
        "increased resistance",
        "spring attack",
        "counter",
        "deflection",
        "shield proficiency",
        "reflection"
    }));
    set_funcs(({
        "rushit",
        "flashit",
        "shatterit",
        "sunderit",
        "rushit",
        "kdit",
        "kdit",
        "disarmit"
    }));
    set_func_chance(35);
    set_property("full attacks", 1);
    set_property("fast healing", 5);
    set_property("magic resistance", random(60) + 10);
    set_property("no death");
    
    set_ac(-50 - random(10));
    set_detecting_invis(1);
    set_long("This " + query_gender() + " guard wears the standard uniform of "
             "the Tonovi Guard, with an insignia indicating a rank of Champion.  "
             "Vigilant in " + QP + " duties, " + QS + " patrols the streets "
             "of Tonovi to enforce the law and protect citizens and officials.  "
             "The Tonovi Guard is made up of both citizens and hired mercenaries.  "
             "The citizens may lack the battle experience of the mercenaries "
             "but they are determined to defend their city and uphold the laws."
             );


/*
    RANDGEAR->armor_me(TO, "armornp", 20, 2, 75);
    new("/d/common/obj/armour/coif")->move(TO);
    command("wear coif");
    RANDGEAR->armor_me(TO, "shield", 30, 1, 75);
    RANDGEAR->arm_me(TO, "tool", 30, 2, 75);
*/

    obj = new("/d/magic/obj/shields/the_faceless_one");
    obj->set_property("enchantment", 7);
    obj->move(this_object());
    obj->set_property("monster weapon", 1);
    force_me("wear shield");

    obj = new("/d/magic/obj/weapons/the_faceless_one");
    obj->set_property("enchantment", 7);
    obj->move(this_object());
    obj->set_property("monster weapon", 1);
    force_me("wield weapon");

    set_guard_stuff();
}

void set_guard_stuff()
{
    set_jail_location("/d/dagger/tonovi/town/jail_main");
    set_guarding("Tonovi");
    set_bad_races(({ "elf", "half-elf", "hobgoblin", "hobgoblin", "kobold", "ogre", "orc", "gnoll", "bugbear", "minotaur", "dragon", "ratkin", "wererat", "undead", "troll" }));
    set_race_action("capture");
    set_race_messages(([
                           "elf"       : "Stop that elf and put it back in chains!",
                           "half-elf"  : "Grab that half-elf and put it back in chains",
                           "hobgoblin" : "Careful folks, it's a hobgoblin, I'll take care of it.",
                           "kobold"    : "Dog faced rat!  Get that kobold!!",
                           "ogre"      : "Gods help us, its an ogre, how did it get past the gate?",
                           "gnoll"     : "It's a gnoll fellas, get it!",
                           "bugbear"   : "A bugbear - it's gonna be mean but let's get it.",
                           "orc"       : "Don't let the orc escape!  You know it's spying for an invasion.",
                           "undead"    : "Fell undead, destroy it!",
                           "minotaur"  : "Pray to your gods, a minotaur got past the gate!",
                           "troll "    : "To arms!  Burn the troll!",
                       ]));
    ARREST_MSG = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG = "%^BOLD%^You are under arrest, criminal!";
    RACE_CAPTURE_MSG = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG = "%^BOLD%^Begone! Do not return to Tonovi!";
    KILL_MSG = "%^BOLD%^For your crimes, you now die!";
    JAIL_MSG = "%^BOLD%^Off to jail you go for your crimes!";
    return;
}

int is_bad_race(object live)
{
    object myshape;
    if (!objectp(live)) {
        return 0;
    }
    if (live->query_true_invis()) {
        return 0;
    }
    if (live->query_invis() && !detecting_invis()) {
        return 0;
    }
    if (live->query_unconscious()) {
        return 0;
    }
    if (live->id("wild_world_monster")) {
        return 1;
    }
    if (query_bad_race(live)) {
        return 1;
    }
    if ((string)live->query_race() == "elf") {
        if ((string)live->query("subrace") == "fey'ri" &&
            !live->query_property("altered")) {
            return 1;
        }
    }
    if (objectp(myshape = live->query_property("shapeshifted"))) {
        if ((string)myshape->query_shape_race() == "dragon") {
            return 1;
        }else {
            return 0;
        }
    }
}

void do_special_combat_actions()
{
    blow_horn(TO);
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
    broadcast_area("/d/tonovi/city", "%^BOLD%^%^RED%^The warning horn blows, alerting the city guards!");
    horn = 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!sizeof(query_attackers())) {
        horn = 0; return;
    }
}

int isWatch()
{
    return 1;
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

void disarmit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("disarm " + targ->query_name());
}

void report()
{
    return;
}

void die(object ob)
{
    int power;//%
    power = 10 + random(5);
    WORLD_EVENTS_D->kill_event("Gates of Tonovi");
    WORLD_EVENTS_D->inject_event((["Gates of Tonovi" : (["start message" : "%^CYAN%^%^BOLD%^The Champion of Tonovi has fallen in battle!%^RESET%^

%^RESET%^%^BOLD%^The masses of the city let out a cry of dismay!%^RESET%^",
                                                             "event type" : "exp bonus", "length" : 120, "notification" : power + "% Bonus Exp",
                                                             "event name" : "Gates of Tonovi", "modifier" : power, "announce" : 1, "announce to" : "world" ]), ])
                                 );
}
