// patrol guard, goes back and forth on the north street of seneca
//adapted from seneca guard
//11/15/09 for new Seneca

#include <std.h>
#include "/d/common/common.h"

#define CITYLAW "seneca law"

inherit "/std/guardsman.c";

int horn; // used to keep the horn from spamming
int round = 0; //fer spells
int i = 0; //to keep track of location

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
    set_nogo(({ "/d/attaya/newseneca/rooms/boardwalk3" }));
    set_name("Seneca Psion");
    set_id(({ "Seneca Guard", "seneca guard", "human", "guard", "psion", CITYLAW }));
    set_short("A robed human");
    set_gender(random(2) ? "male" : "female");
    hairColor();
    eyeColor();
    set_race("human");
    set_hd(20 + random(10), 1);
    set_hp(TO->query_max_hp());
    set_class("psion");
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
    set_mob_magic_resistance("average");
    rank = set_ranks(([
                          18 : "rookie",
                          20 : "lieutenant",
                          24 : "sergeant",
                          28 : "captain",
                          30 : "Commander",
                      ]));
    droll = (20 + random(13));
    set_guild_level("psion", droll);
    set_mlevel("psion", droll);

    add_id(rank);
    add_id(capitalize(rank));
    set_short("A " + query("hair") + " haired, " + query("eye") + " eyed"
              " " + query_gender() + " human in a Seneca psion uniform");
    set_ac(2 - random(10));
    set_detecting_invis(random(2));
    set_exp(1);
    set_long("Dressed in the %^RED%^red-trimmed %^RESET%^" +
             "robe of the %^CYAN%^Seneca psions%^RESET%^" +
             ", this " + query_gender() + " guard wears an insignia " +
             "indicating a rank of " + rank + "" +
             " on " + query_possessive() + " left shoulder.  On the " +
             "right shoulder is a an embroidered %^BOLD%^eagle%^RESET%^ " +
             "in flight, the symbol of the " +
             "%^BOLD%^Seneca Guard%^RESET%^.  The psion brigade was" +
             " formed after the onslaught of adventurers" +
             " in Seneca.  They augment the normal " +
             "watch with their mental powers. ");
    if (rank == "Commander" || rank == "captain") {
        RANDGEAR->armor_me(TO, "armorcl", 20, 2, 75);
    } else {
        RANDGEAR->armor_me(TO, "armorcl", 20, 3, 75);
    }
    new("/d/laerad/obj/bracers")->move(TO);
    new("/d/common/obj/rand/r_shoes")->move(TO);
    command("wearall");


    RANDGEAR->arm_me(TO, "edgeds", 80, 3, 75);

    set_guard_stuff();
    set_monster_feats(({ "damage resistance", "improved damage resistance", "improved toughness",
                         "regeneration", "toughness",
                         "spell focus", "spell penetration", "perfect caster",
                         "greater spell penetration", "spell power", "improved spell power", "greater spell power" }));
    set_spells(({
        "breath of the black dragon",
        "swarm of crystals",
        "mind thrust",
        "ultrablast",
        "control_object",
        "microcosm"
    }));
    set_spell_chance(100);
}

void set_guard_stuff()
{
    set_jail_location("/d/attaya/newseneca/rooms/jail_main");
    set_guarding("Seneca");
    ARREST_MSG = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG = "%^BOLD%^You are under arrest, criminal!";
    RACE_CAPTURE_MSG = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG = "%^BOLD%^Begone! Do not return to Seneca!";
    KILL_MSG = "%^BOLD%^For your crimes, you now die!";
    JAIL_MSG = "%^BOLD%^Off to jail you go for your crimes!";
    return;
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
    broadcast_area("/d/attaya/newseneca/rooms", "%^BOLD%^%^RED%^The warning horn blows,
alerting the city guards!");
    horn = 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!sizeof(query_attackers())) { //patrol north part
        horn = 0; round = 0;
        if (random(4) > 1) {
            if (i < 12) {
                force_me("east");
                i++;
            }else {
                force_me("west");
                i++;
            }
            if (i > 24) {
                i = 0;
            }
        }
        return;
    }

    if (round != 1) {
        new("/cmds/spells/i/_iron_body")->use_spell(TO, TO, TO->query_level(), 100, "psion");
        new("/cmds/spells/e/_energy_retort")->use_spell(TO, TO, TO->query_level(), 100, "psion");
        new("/cmds/spells/t/_timeless_body")->use_spell(TO, TO, TO->query_level(), 100, "psion");
        round = 1;
    }
    if (!query_property("amorpha") && !random(2)) {
        new("/cmds/spells/c/_concealing_amorpha.c")->use_spell(TO, TO, TO->query_level(), 100, "psion");
    }
    if (random(3) == 0) {
        TO->force_me("flash");
    }
}

int isWatch()
{
    return 1;
}
