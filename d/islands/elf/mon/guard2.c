//mirror warrior reflects attacks
//5/11/11 for new Ashta'Rathai
//1/6/14 updated new races

#include <std.h>
#include "/d/common/common.h"
#include "../elf.h"

#define CITYLAW "Ashta'Rathai law"

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
    int droll;
    ::create();
    will_open_doors(1);
    set_nogo(({ ROOMS "gate" }));
    set_name("Mirror Warrior");
    set_id(({ "Ashta'Rathai Guard", "Ashta'Rathai guard",
              "elf", "warrior", "guard", "mirror warrior", CITYLAW }));
    set_short("An elven mirror warrior");
    set_gender(random(2) ? "male" : "female");
    hairColor();
    eyeColor();
    set_race("elf");
    set_hd(20 + random(10), 1);
    set_hp(roll_dice(query_hd(), 17) + 90);
    set_class("fighter");
    set_fighter_style("dervish");
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
    rank = set_ranks(([
                          18 : "rookie",
                          20 : "lieutenant",
                          24 : "sergeant",
                          28 : "captain",
                          30 : "Commander",
                      ]));
    droll = (20 + random(13));
    set_guild_level("fighter", droll);
    set_mlevel("fighter", droll);
    add_id(rank);
    add_id(capitalize(rank));
    set_short("A " + query("hair") + " haired, " + query("eye") + " eyed"
              " " + query_gender() + " mirror warrior ");
    set_ac(2 - random(10));
    set_detecting_invis(random(2));
    set_mob_magic_resistance("very high");
    set_long("%^RESET%^%^CYAN%^Dressed in the %^YELLOW%^gold-trimmed %^RESET%^" +
             "%^CYAN%^garb of the %^CYAN%^Ashta'Rathai watch%^RESET%^" +
             "%^CYAN%^, this " + query_gender() + " guard wears an insignia " +
             "indicating a rank of %^BOLD%^" + rank + "%^RESET%^%^CYAN%^" +
             " on " + query_possessive() + " left shoulder.  On the " +
             "right shoulder is a an embroidered %^YELLOW%^dragon%^RESET%^ " +
             "%^CYAN%^in flight, the symbol of the " +
             "%^BOLD%^Ashta'Rathai Guard%^RESET%^. %^CYAN%^ The mirror warrior brigade was" +
             " formed after the onslaught of non-elves" +
             " in Ashta'Rathai.  They augment the normal " +
             "watch with their special abilities. ");
    if (rank == "Commander" || rank == "captain") {
        new(OBJ "tspear")->move(TO);
        command("wield spear");
        new(OBJ "chain")->move(TO);
        new(OBJ "cloak1")->move(TO);
    } else {
        RANDGEAR->armor_me(TO, "armorlt", 20, 3, 75);
        RANDGEAR->arm_me(TO, "edgeds", 80, 3, 75);
        RANDGEAR->armor_me(TO, "shield", 20, 3, 75);
        command("wear shield");
    }
    new("/d/common/obj/rand/r_shoes")->move(TO);
    command("wearall");

    set_monster_feats(({ "damage resistance",
                         "improved damage resistance", "improved toughness",
                         "regeneration", "toughness",
                         "increased resistance", "improved resistance", "resistance",
                         "spell reflection", }));
    add_attack_bonus(9);
    set_guard_stuff();
    set_new_exp(30, "normal");
    set_max_level(30);
}

void set_guard_stuff()
{
    set_jail_location(ROOMS "guard1");
    set_guarding("Ashta'Rathai");
    set_bad_races(RACIST);
    set_race_action("capture"); // might as well, capture is meh
    set_race_messages(([
                           "undead"      : "A zombie! destroy it!.",
                           "human"       : "The humans have come back, to arms!",
                           "drow"        : "Drow abomination, how dare you show yourself here!",
                       ]));
    ARREST_MSG = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG = "%^BOLD%^You are under arrest, criminal!";
    RACE_CAPTURE_MSG = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG = "%^BOLD%^Begone! Do not return to Ashta'Rathai!";
    KILL_MSG = "%^BOLD%^I will protect our people!";
    JAIL_MSG = "%^BOLD%^To the cage, the elders will decide your fate!";
    return;
}

int is_bad_race(object live)  // added N's fix for subraces
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
    if ((string)live->query_visual_race() != "elf") {
        return 0;
    }
}

void do_special_combat_actions()
{
    blow_horn(TO);
}

void hairColor()
{
    switch (random(6)) {
    case 0:        set("hair", "gold");        break;

    case 1:        set("hair", "white");           break;

    case 2:        set("hair", "pale");        break;

    case 3:        set("hair", "gray");         break;

    case 4:        set("hair", "silver");          break;

    case 5:        set("hair", "platinum");         break;
    }
}

void eyeColor()
{
    switch (random(5)) {
    case 0:        set("eye", "blue");         break;

    case 1:        set("eye", "gold");         break;

    case 2:        set("eye", "silver");        break;

    case 3:        set("eye", "white");        break;

    case 4:        set("eye", "gray");        break;
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
    set("weight", (75 + random(50)));
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
    broadcast_area(ROOMIE, "%^BOLD%^%^RED%^The warning horn blows, alerting the city
guards!");
    horn = 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!sizeof(query_attackers())) {
        horn = 0; round = 0; return;
    }

    if (random(3) == 0) {
        TO->force_me("flash");
    }
}

int isWatch()
{
    return 1;
}

void struck(int damage, object weapon, object attacker, string limb)
{
    int x;
    if (damage > 0) {
        if (random(2) == 0) {
            tell_room(ETO, "%^BOLD%^" +
                      "" + TOQCN + "'s armor " +
                      "flashes as " +
                      "" + attacker->QCN + " strikes it, and the attack is reflected
back!", ({ ETO, attacker }));
            tell_object(TO, "%^BOLD%^Your armor " +
                        "flashes as " +
                        "" + attacker->QCN + " strikes it, and the attack is reflected back
at them.");
            tell_object(attacker, "%^BOLD%^" + TOQCN + "'s armor " +
                        "flashes as " +
                        "you strike them, and the attack comes out of the mirror back
out at you!");
            attacker->do_damage(limb, damage / 2); //toned it down a bit
            return;
        }else {
            x = do_damage(limb, damage);
        }
    }else {
        x = 0;
    }
    if (objectp(attacker)) {
        attacker->send_messages(0, weapon, limb, x, TO);
    }
}
