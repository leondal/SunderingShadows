/* To change the waystations for finding the jail if needed....
 * eval return "daemon/destinations_d.c"->query_waystations("/d/darkwood/tabor/room/jail")
 * eval return "/daemon/destinations_d.c"->clear_waystations("/d/darkwood/tabor/room/jail")
 * eval return "/daemon/destinations_d.c"->generate_waystations("/d/darkwood/tabor/room/jail", 5, 2)
 */

// Adapted from Shadow guards by Ares to use his new guardsman inherit, finished by Styx
/*
   monster_party(int) set in CROOM

   fix monster.c to have a setting for if we want them to try to open doors and then add move_around to either ignore with doors or try to open....
   add alarm sounding support to guardsman?
 */

#include <std.h>
#include <daemons.h>
#include "/d/common/common.h"

#define GUARDNAMES "/d/common/defines/guards.lst"

inherit "/std/guardsman.c";

int horn; // used to keep the horn from spamming

void set_guard_stuff();
void setupName(string type);
string do_name();
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
    set_nogo(({ "/d/shadow/room/forest/road58", "/d/darkwood/tabor/road/road3", "/d/koenig/streams/path18", "/d/shadow/room/forest/road56", "/d/darkwood/tabor/include/arch1" }));
    set_name("PsyKnight Reinforcement");
    set_id(({ "PsyKnight Reinforcement", "psyknight", "human", "knight" }));
    set_short("An exotically armored human");
    set_gender(random(2) ? "male" : "female");
    hairColor();
    eyeColor();
    doHeight();
    doWeight();
    setupName("watch");
    set_race("human");
    set_hd(25 + random(20), 1);
    set_class("mage");
	set_class("fighter");
	set_mlevel("mage", query_hd());
    set_mlevel("fighter", query_hd());
    set_guild_level("fighter", query_hd());
    add_search_path("/cmds/fighter");
    set_fighter_style("soldier");
    set_property("full attacks", 1);
    set_mob_magic_resistance("average");
    set_spell_chance(99);
	set_spells(({"dispel magic"}));
	set_property("add kits", 50);
    set_skill("rope use", 45);
    rank = set_ranks(([
                          28 : "rookie",
                          30 : "sergeant",
                          34 : "lieutenant",
                          38 : "captain",
                          40 : "Commander",
                      ]));
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
    set_func_chance(40);
    set_ac(5 - random(20));
    set_detecting_invis(random(1));
    set_exp(1);
    set_long("This knight is a " + query("height") + " foot, "
             + query("weight") + " pound " + query_gender() +
             " reinforcement to the Tabor watch.  " + capitalize(QP) + " current rank is " + rank + ".  " +
             "Wearing standard equipment of the fabled Psyknights, " + QS + " patrols the streets " +
             "of Tabor to enforce the law and protect citizens and officials.  The "
             "knights are made up of loyal, hand-picked psions tasked to support the King of "
             "Tabor.  They are well-known in the region for their fighting skills and "
             "their ability to keep the peace."
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
        RANDGEAR->arm_me(TO, "edgedm", 30, 2, 75);
        RANDGEAR->arm_me(TO, "edgeds", 30, 2, 75);
        break;

    case 1:
        RANDGEAR->arm_me(TO, "edgedl", 30, 2, 75);
        break;

    case 2:
        RANDGEAR->arm_me(TO, "bluntm", 30, 2, 75);
        RANDGEAR->arm_me(TO, "blunts", 30, 2, 75);
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
    set_jail_location("/d/darkwood/tabor/room/jail");
    set_guarding("Tabor");
    set_bad_races(({ "drow", "half-drow", "goblin", "hobgoblin", "kobold", "ogre", "orc", "gnoll", "bugbear", "minotaur", "yuan-ti", "ratkin", "wererat" }));
    set_race_action("capture");
    set_race_messages(([
                           "drow"      : "Arg, its a drow, sound the horn, stop it before it starts killing children.",
                           "half-drow" : "Stop the bastard half-drow, any drow blood is bad.",
                           "goblin"    : "Stop that miserable little goblin, and look around for more.",
                           "hobgoblin" : "Careful folks, it's a hobgoblin, I'll take care of it.",
                           "kobold"    : "Dog faced rat!  Get that kobold!!",
                           "ogre"      : "Gods help us, its an ogre, how did it get past the gate?",
                           "ratkin"    : "Sound the alarms! Underworld invasion! May the gods help us!",
                           "gnoll"     : "It's a gnoll fellas, get it!",
                           "half-ogre" : "Half-ogres are just smaller ogres, can't allow them in here.",
                           "half-orc"  : "It's not human fellas, get that half-orc.",
                           "bugbear"   : "A bugbear - it's gonna be mean but let's get it.",
                           "orc"       : "Don't let the orc escape!  You know it's spying for an invasion.",
                       ]));
    ARREST_MSG = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG = "%^BOLD%^You are under arrest you criminal!";
    RACE_CAPTURE_MSG = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG = "%^BOLD%^Off with you scum, don't set foot in shadow again!";
    KILL_MSG = "%^BOLD%^For the crime of invading the city, you die now!";
    JAIL_MSG = "%^BOLD%^Off to jail you go for your crimes!";
    return;
}

void do_special_combat_actions()
{
    blow_horn(TO);
}

void setupName(string type)
{
    string name;
    name = do_name();
//    set_name(name);  need the name to remain Tabor Guard for killers list, etc.
    set_short(capitalize(name) + ", " + article(query("hair")) + " " + query("hair") + " haired, " + query("eye") + " eyed " + query_gender() + " human");
    add_id(capitalize(name));
    add_id(lower_case(name));
}

string do_name()
{
    string names, name, * names2 = ({});
    int i;

    if (!names2 || names2 == ({})) {
        names = read_file(GUARDNAMES);

        names2 = explode(names, ", ");
    }
    name = names2[random(sizeof(names2))];
    names2 -= ({ name });
    return name;
}

void hairColor()
{
    switch (random(6)) {
    case 0:        set("hair", "blonde");        break;

    case 1:        set("hair", "red");           break;

    case 2:        set("hair", "auburn");        break;

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
    set("weight", (120 + random(100)));
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

/*
   int kill_ob(object ob, int i) {
    int hold;
    hold = ::kill_ob(ob,i);
    if(!ob->is_player()) return hold;

    if(!AREALISTS_D->is_jailer(ob->query_name(),query_guarding(), TO))
    {
        if(hold)
        {
            if(!AREALISTS_D->is_wanted(ob,query_guarding(),TO))
            {
                AREALISTS_D->add_wanted(ob,query_guarding(),TO);
            }
        }
        blow_horn(TO);
        force_me("rush "+ob->query_name());
    }
    return hold;
   }
 */

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
    broadcast_area("/d/darkwood/tabor/room", "%^BOLD%^%^YELLOW%^The warning horn blows alerting the city guards.");
    tell_room("/realms/styx/workroom", "The Tabor horn is blowing.");
    horn = 1;
}

void heart_beat()
{
//    int horn=0;
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
