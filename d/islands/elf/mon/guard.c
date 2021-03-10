//adapted from seneca psion
//5/11/11 for new Ashta'Rathai

#include <std.h>
#include "/d/common/common.h"
#include "../elf.h"

#define CITYLAW "Ashta'Rathai law"
#define ELFIES "/realms/hades/elf"

inherit "/std/guardsman.c";

int horn; // used to keep the horn from spamming
int round = 0; //fer spells


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
    set_name("Ashta Rathai guard");
    set_id(({ "Ashta'Rathai Guard", "ashta rathai guard",
              "elf", "guard", "mage guard", CITYLAW }));
    set_gender(random(2) ? "male" : "female");
    hairColor();
    eyeColor();
    set_race("elf");
    set_hd(18 + random(13), 1);
    set_hp(roll_dice(query_hd(), 16));
    set_class("mage");
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
    set_mob_magic_resistance("average");
    rank = set_ranks(([
                          18 : "rookie",
                          20 : "lieutenant",
                          24 : "sergeant",
                          28 : "captain",
                          29 : "Commander",
                      ]));
    droll = (10 + random(21));
    //lowering as it was kinda nuts
    set_guild_level("mage", droll);
    set_mlevel("mage", droll);
    set_stats("strength", 16);
    set_stats("intelligence", 21);
    set_stats("dexterity", 17);
    set_stats("charisma", 16);
    set_stats("wisdom", 10);
    set_stats("constitution", 14);
    add_id(rank);
    add_id(capitalize(rank));
    set_short("A " + query("hair") + " haired, " + query("eye") + " eyed"
              " " + query_gender() + " Ashta Rathai guard");
    set_ac(2 - random(10));
    set_detecting_invis(random(2));
    set_long("%^RESET%^%^CYAN%^Dressed in the %^YELLOW%^gold-trimmed %^RESET%^" +
             "%^CYAN%^garb of the %^CYAN%^Ashta'Rathai watch%^RESET%^" +
             "%^CYAN%^, this " + query_gender() + " guard wears an insignia " +
             "indicating a rank of %^BOLD%^" + rank + "%^RESET%^%^CYAN%^" +
             " on " + query_possessive() + " left shoulder.  On the " +
             "right shoulder is a an embroidered %^YELLOW%^dragon%^RESET%^ " +
             "%^CYAN%^in flight, the symbol of the " +
             "%^BOLD%^Ashta'Rathai Guard%^RESET%^.");
    if (rank == "Commander" || rank == "captain") {
        new(OBJ "robe1")->move(TO);
    } else {
        RANDGEAR->armor_me(TO, "armorcl", 20, 3, 75);
    }
    new("/d/laerad/obj/bracers")->move(TO);
    new("/d/common/obj/rand/r_shoes")->move(TO);
    command("wearall");
    RANDGEAR->arm_me(TO, "edgeds", 80, 3, 75);
    set_guard_stuff();
    set_monster_feats(({ "damage resistance",
                         "improved damage resistance", "improved toughness",
                         "regeneration", "toughness",
                         "spell focus", "spell penetration", "perfect caster",
                         "greater spell penetration", "spell power",
                         "improved spell power", "greater spell power" }));
    set_spells(({
        "powerword stun",
        "prismatic spray",
        "greater shout",
        "disintegrate",
        "ball lightning",
        "lightning bolt",
        "gust of wind",
    }));
    set_spell_chance(100);
    set_new_exp(30, "normal");
    set_max_level(35);
}

void set_guard_stuff()
{
    set_jail_location(ROOMS "guard1");
    set_guarding("Ashta'Rathai");
    set_bad_races(RACIST);
    set_race_action("capture");  //might as well :D
    set_race_messages(([
                           "undead"      : "A zombie! destroy it!.",
                           "drow"        : "Drow!  Kill the trator!",
                           "fey'ri"      : "Fey'ri!  They've come to kidnap us!",
                       ]));
    ARREST_MSG = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG = "%^BOLD%^To the cage with you, rabid beast!";
    RACE_CAPTURE_MSG = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG = "%^BOLD%^Begone! Do not return to Ashta'Rathai!";
    KILL_MSG = "%^BOLD%^For your crimes, you now die!";
    JAIL_MSG = "%^BOLD%^Off to jail you go for your crimes!";
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

void do_laws(object live)
{
    ::do_laws();
    if (sizeof(live->query_wielded())) {
        force_me("say please unhand your weapon");
    }
}

void hairColor()
{
    switch (random(6)) {
    case 0:        set("hair", "gold");        break;

    case 1:        set("hair", "red");           break;

    case 2:        set("hair", "sandy");        break;

    case 3:        set("hair", "black");         break;

    case 4:        set("hair", "silver");          break;

    case 5:        set("hair", "copper");         break;
    }
}

void eyeColor()
{
    switch (random(5)) {
    case 0:        set("eye", "blue");         break;

    case 1:        set("eye", "gold");         break;

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
    set("weight", (100 + random(50)));
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
    broadcast_area(ROOMIE, "%^BOLD%^%^RED%^The warning horn" +
                   " blows, alerting the guards!");
    horn = 1;
}

int query_blinking()
{
    return 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!sizeof(query_attackers())) {
        horn = 0; round = 0; return;
    }
    if (round != 1) {
        new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO, TO->query_level(), 100, "mage");
        round = 1;
    }
    if (random(3) == 0) {
        TO->force_me("flash");
    }
}

int isWatch()
{
    return 1;
}

void die(object ob)
{
    //ppl that kill guards get marked
    if (!objectp(ob) && objectp(TO->query_current_attacker())) {
        ob = TO->query_current_attacker();
    }else {
        ::die(TO); return;
    }
    log_file("elftown.log", ob->query_race() +
             " killed a guard on " + hour(time()) + ":" +
             (minutes(time()) > 9 ? minutes(time()) : "0" + minutes(time())) +
             " " + day(time()) + ", " + date(time()) +
             " " + month(time()) + ", " + year(time()) + " SG" + "\n");
    tell_room(ETO, ob->query_name() + " likes to kill guards.");
    if (!present("feeling1", ob)) {
        new(OBJ "target2")->move(ob);
    }
    ::die(TO);
}
