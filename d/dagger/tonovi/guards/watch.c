#include <std.h>
#include "/d/common/common.h"

#define CITYLAW "tonovi law"

inherit "/std/guardsman.c";

int horn; // used to keep the horn from spamming

void set_guard_stuff();
void hairColor();
void eyeColor();
void doHeight();
void doWeight();
void blow_horn(object watchman);

void create()
{
    string rank;
    ::create();
    will_open_doors(1);
    set_nogo(({ "/d/dagger/tonovi/road2", }));
    set_name("Tonovi Guard");
    set_id(({ "Tonovi Guard", "tonovi guard", "guard", CITYLAW }));
    set_short("A tall human");
    set_gender(random(2) ? "male" : "female");
    hairColor();
    eyeColor();
    set_race("guard");
    set_hd(60 + random(10), 1);
    set_hp(TO->query_max_hp());
    set_new_exp(20, "normal");
    set_class("fighter");
    add_search_path("/cmds/fighter");
    set_fighter_style("soldier");
    set_speed(30);
    add_attack_bonus(15);
    add_damage_bonus(10);
    set_property("add kits", 50);
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
    set_property("magic resistance", random(60) + 10);
    rank = set_ranks(([
                          18 : "rookie",
                          20 : "sergeant",
                          24 : "lieutenant",
                          28 : "captain",
                          30 : "commander",
                      ]));
    add_id(rank);
    add_id(capitalize(rank));
    set_short("%^RESET%^%^RED%^A " + query("hair") + " haired, " + query("eye") + " eyed"
              " " + query_gender() + " " + query_race() + " in a %^WHITE%^Tonovi guard uniform");
    set_ac(2 - random(10));
    set_detecting_invis(random(2));
    set_exp(1);
    set_long("This " + query_gender() + " guard wears the standard uniform of "
             "the Tonovi Guard, with an insignia indicating a rank of " + rank + ".  "
             "Vigilant in " + QP + " duties, " + QS + " patrols the streets "
             "of Tonovi to enforce the law and protect citizens and officials.  "
             "The Tonovi Guard is made up of both citizens and hired mercenaries.  "
             "The citizens may lack the battle experience of the mercenaries "
             "but they are determined to defend their city and uphold the laws."
             );

    if (rank == "sergeant" || rank == "lieutenant") {
        set_property("add kits", 10);
        RANDGEAR->armor_me(TO, "armornp", 20, 2, 75);
    }
    if (rank == "Commander" || rank == "captain") {
        set_property("add kits", 15);
        RANDGEAR->armor_me(TO, "armorpl", 20, 1, 75);
    } else {
        RANDGEAR->armor_me(TO, "armornp", 20, 2, 75);
    }
    new("/d/common/obj/armour/coif")->move(TO);
    command("wear coif");
    switch (random(4)) {
    case 0:
        RANDGEAR->arm_me(TO, "edgedm", 30, 3, 75);
        RANDGEAR->arm_me(TO, "edgeds", 30, 3, 75);
        break;

    case 1:
        RANDGEAR->arm_me(TO, "edgedl", 30, 3, 75);
        break;

    case 2:
        RANDGEAR->arm_me(TO, "bluntm", 30, 3, 75);
        RANDGEAR->arm_me(TO, "blunts", 30, 3, 75);
        break;

    case 3:
        RANDGEAR->armor_me(TO, "shield", 30, 1, 75);
        RANDGEAR->arm_me(TO, "tool", 30, 2, 75);
        break;
    }
    set_guard_stuff();
}

void set_guard_stuff()
{
    set_jail_location("/d/dagger/tonovi/town/jail_main");
    set_guarding("Tonovi");
    set_bad_races(({ "elf", "half-elf", "hobgoblin", "goblin", "hobgoblin", "kobold", "ogre", "orc", "gnoll", "bugbear", "minotaur", "dragon", "ratkin", "wererat", "undead", "troll" }));
    set_race_action("capture");
    set_race_messages(([
                           "elf"       : "Stop that elf and put it back in chains!",
                           "half-elf"  : "Grab that half-elf and put it back in chains",
                           "goblin"    : "Stop that miserable little goblin, and look around for more.",
                           "hobgoblin" : "Careful folks, it's a hobgoblin, I'll take care of it.",
                           "kobold"    : "Dog faced rat!  Get that kobold!!",
                           "ogre"      : "Gods help us, its an ogre, how did it get past the gate?",
                           "gnoll"     : "It's a gnoll fellas, get it!",
                           "bugbear"   : "A bugbear - it's gonna be mean but let's get it.",
                           "orc"       : "Don't let the orc escape!  You know it's spying for an invasion.",
                           "undead"    : "Fell undead, destroy it!",
                           "minotaur"  : "Pray to your gods, a minotaur got past the gate!",
                           "troll "    : "To arm!  Burn the troll!",
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

void hairColor()
{
    switch (random(6)) {
    case 0:        set("hair", "blonde");        break;

    case 1:        set("hair", "red");           break;

    case 2:        set("hair", "sandy");        break;

    case 3:        set("hair", "black");         break;

    case 4:        set("hair", "gray");          break;

    case 5:        set("hair", "brown");         break;
    }
}

void eyeColor()
{
    switch (random(5)) {
    case 0:        set("eye", "blue");         break;

    case 1:        set("eye", "gray");         break;

    case 2:        set("eye", "green");        break;

    case 3:        set("eye", "brown");        break;

    case 4:        set("eye", "azure");        break;
    }
}

void doHeight()
{
    int feet, halves;
    int height = 63 + random(20);
    feet = height / 12;
    halves = "";
    if (height % 12) {
        halves = (height % 12 < 4) ? "" : ((height % 12 < 9) ? " and a half" : "");
        if (height % 12 > 8) {
            height++;
        }
    }
    set("height", "" + feet + halves);
}

void doWeight()
{
    set("weight", (140 + random(140)));
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
    broadcast_area("/d/tonovi/town", "%^BOLD%^%^RED%^The warning horn blows, alerting the city guards!");
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
