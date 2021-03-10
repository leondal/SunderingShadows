//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit "/std/monster.c";

void block_all_priests();

int is_raising;
int ignoring;
nosave int BEAT, heartcount;

void create()
{
    string gender_poss, gender_Subj, gender_subj, gender_obj;
    object guider, ob;
    ::create();
    is_raising = 0;
    ignoring = 0;
    set_name("Ghostly priest");
    set_id(({ "ghost", "tecqumin", "priest", "tecqumin priest", "monster",
              "ghostly priest", "ghost priest", }));
    set_short("%^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^WHITE%^stly"
              + " %^RESET%^%^CYAN%^Tecqumin %^ORANGE%^priest%^RESET%^");
    set_race("ghost");
    set_body_type("humanoid");
    set_wielding_limbs(({ "right hand", "left hand" }));
    if (random(2)) {
        set_gender("male");
        gender_poss = "his";
        gender_Subj = "He";
        gender_subj = "he";
        gender_obj = "him";
    } else {
        set_gender("female");
        gender_poss = "her";
        gender_Subj = "She";
        gender_subj = "she";
        gender_obj = "her";
    }
    set_funcs(({ "summon_help" }));
    set_func_chance(30);
    set_long("%^RESET%^A long dead %^ORANGE%^priest%^RESET%^ of the"
             + " Tecqumin. In life, " + gender_poss + " skin and hair were"
             + " smeared in %^BOLD%^%^BLACK%^soot%^RESET%^, making "
             + gender_poss + " whole visage that of a shadow, save for the"
             + " whites of " + gender_poss + " eyes and the gleaming of "
             + gender_poss + " teeth. H"
             + gender_poss[1..2] + " spirit now appears as a flickering,"
             + " %^CYAN%^tr%^RESET%^a%^CYAN%^nsl%^RESET%^u%^CYAN%^cent"
             + " %^RESET%^human figure. When at its most visible, you can"
             + " make out the %^BOLD%^%^BLACK%^soot stained%^RESET%^ skin"
             + " stretched tight across a well-fed, slightly pudgy body. "
             + gender_Subj + " is dressed in a plain white kilt, a poncho"
             + " and a torc around " + gender_poss + " neck. "
             + "\nAt different times, though it %^CYAN%^fl"
             + "%^RESET%^i%^CYAN%^ck%^RESET%^e%^CYAN%^rs%^RESET%^ and"
             + " becomes almost completely invisible, with %^BOLD%^"
             + "%^GREEN%^horrific%^RESET%^ flashes of uncovered"
             + " %^MAGENTA%^m%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^scle"
             + "%^RESET%^, %^BOLD%^%^RED%^f%^MAGENTA%^l%^RESET%^"
             + "%^MAGENTA%^e%^BOLD%^%^MAGENTA%^sh%^RESET%^ and %^BOLD%^"
             + "%^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^ne%^RESET%^ striking"
             + " your eyes as different layers of " + gender_poss
             + " body fade in and out of vision.");
    set_hd(50, 12);
    set_size(2);
    set("aggressive", "aggfunc");
    set_class("cleric");
    set_mlevel("cleric", 50);
    set_level(50);
    set_guild_level("cleric", 50);
    set_hp(900 + random(500));
    set_speed(0);

    set_max_level(50);
    set_property("swarm", 1);
    set_overall_ac(-50);
    add_attack_bonus(65);
    set_stats("strength", 18);
    set_stats("dexterity", 18);
    set_new_exp(38, "normal");
    set_alignment(4);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm", 1);
    add_money("gold", random(2000) + 2000);
    add_money("platinum", random(4000) + 1000);
    add_money("electrum", random(1000) + 2050);
    add_search_path("/cmds/priest");
    set_spells(({ "flame strike", "flame strike",
                  "cause serious wounds", "cause serious wounds",
                  "cause serious wounds", "hold person", "hold person", "sticks into snakes" }));
    set_emotes(2, ({
        "The %^BOLD%^%^BLACK%^gh%^RESET%^o%^BOLD%^%^BLACK%^stly"
        + " %^RESET%^priest %^CYAN%^flickers%^RESET%^ in and out of"
        + " sight",
    }), 0);
    set_emotes(4, ({
        "The %^BOLD%^%^BLACK%^gh%^RESET%^o%^BOLD%^%^BLACK%^stly"
        + " %^RESET%^priest %^ORANGE%^mutters%^RESET%^ a chant under"
        + TO->QP + "  breath",

        "The %^BOLD%^%^BLACK%^gh%^RESET%^o%^BOLD%^%^BLACK%^st%^RESET%^"
        + " of the %^CYAN%^tecqumin%^RESET%^ priest moves around a little"
        + " unsteadily",

        "The %^BOLD%^%^BLACK%^gh%^RESET%^o%^BOLD%^%^BLACK%^stly%^RESET%^"
        + " %^CYAN%^tecqumin%^RESET%^ priest's eyes glaze over slighly as "
        + TO->QS + " focusses far off into the distance",

        "The %^BOLD%^%^BLACK%^gh%^RESET%^o%^BOLD%^%^BLACK%^stly%^RESET%^"
        + " %^CYAN%^tecqumin%^RESET%^ priest's eyes glaze over slighly as "
        + TO->QS + " focusses far off into the distance",
    }), 1);
    set_spell_chance(40);
    ob = new(OBJ + "ether_knife");
    ob->move(TO);
    if (random(10)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wield knife");
    ob = new(OBJ + "torc_lesser");
    ob->move(TO);
    if (random(20)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wear torc");
    ob = new(OBJ + "kilt");
    ob->move(TO);
    if (random(20)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wear kilt");
    ob = new(OBJ + "poncho");
    ob->move(TO);
    if (random(20)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wear poncho");
    will_open = 1;
    set_property("untrackable", 1);
    set_property("no random treasure", 1);
    heartcount = 0;
    BEAT = 0;
    check_my_heart();
    set_property("no random treasure", 1);
    set_property("knock unconscious", 1);
    set_no_clean(1);
}

void init()
{
    ::init();
//  force_me("wield knife");
}

int count_players()
{
    object* critters;
    int count, i, res;
    if (!objectp(ETO)) {
        return 0;
    }
    critters = all_living(ETO);
    count = sizeof(critters);
    if (count < 1) {
        return 0;
    }
    res = 0;
    for (i = 0; i < count; i++) {
        if (userp(critters[i]) && !critters[i]->query_true_invis()) {
            res++;
        }
    }
    return res;
}

int count_ghosts()
{
    object* critters;
    int count, i, res;
    if (!objectp(ETO)) {
        return 0;
    }
    critters = all_living(ETO);
    count = sizeof(critters);
    if (count < 1) {
        return 0;
    }
    res = 0;
    for (i = 0; i < count; i++) {
        if (critters[i]->id("tecqumin") || critters[i]->id("ghost")) {
            res++;
        }
    }
    return res;
}

void summon_help()
{
    object* rooms, * critters, * all_critters, * new_rooms, room, all_rooms;
    mapping waystations;
    string* destinations, * exits;
    int i, j, k, count, count2;
    if (!objectp(ETO)) {
        return;
    }
    if (count_players() < count_ghosts() * 3 || count_ghosts() > 10) {
        return;
    }
    force_me("emote casts " + TO->QP + " %^BOLD%^%^WHITE%^gaze%^RESET%^ upwards, briefly closing " + TO->QP + " eyes as if in %^CYAN%^mute supplication");
    all_rooms = ({});
    new_rooms = ({ ETO });
    for (i = 0; i < 4; i++) {
        all_rooms += new_rooms;
        rooms = new_rooms;
        new_rooms = ({});
        count = sizeof(rooms);
        if (count < 1) {
            break;
        }
        for (j = 0; j < count; j++) {
            exits = rooms[j]->query_exits();
            count2 = sizeof(exits);
//      tell_room(ETO, "There are " + count2 + " exits in " + base_name(rooms[j]));
            if (count2 < 1) {
                continue;
            }
            for (k = 0; k < count2; k++) {
//        tell_room(ETO, "Checking " + exits[k] + " exit.");
                room = find_object_or_load(rooms[j]->query_exit(exits[k]));
                if (objectp(room) && member_array(room, all_rooms) == -1) {
//          tell_room(ETO, "Room found at : " + base_name(room));
                    new_rooms += ({ room });
                } else {
//          tell_room(ETO, "No room found at " + rooms[j]->query_exit(exits[k]));
                }
            }
        }
    }
    count = sizeof(all_rooms);
    all_critters = ({});
//  tell_room(ETO, "Found " + count + " rooms in range. Now checking for critters");
    if (count > 0) {
        for (i = 0; i < count; i++) {
            critters = all_living(all_rooms[i]);
            count2 = sizeof(critters);
            if (count2 < 1) {
//        tell_room(ETO, "No critters in " + base_name(all_rooms[i]));
                continue;
            }
            for (j = 0; j < count2; j++) {
                if (critters[j]->id("tecqumin") || critters[j]->id("ghost")) {
                    if (critters[j] == TO) {
//            tell_room(ETO, "Not adding original ghost to list");
                        continue;
                    }
                    all_critters += ({ critters[j] });
                } else {
//          tell_room(ETO, base_name(critters[j]) + " is not a tecqumin or a ghost");
                }
            }
        }
    }
    count = sizeof(all_critters);
//  tell_room(ETO, "Found " + count + " Tecqumin and ghosts in range. Summoning them all.");
    if (count > 0) {
        waystations = "/daemon/destinations_d.c"->query_waystations(base_name(ETO));
        if (sizeof(waystations) < 1) {
            "/daemon/destinations_d.c"->generate_waystations(base_name(ETO), 2, 3);
        }
        for (i = 0; i < count; i++) {
//      tell_room(ETO, base_name(all_critters[i]) + " starting walking towards " + base_name(ETO));
            all_critters[i]->start_walking(base_name(ETO));
        }
    }
}

void heart_beat()
{
    if (objectp(ETO) && present("player", ETO)) {
        heartcount = 0;
    }
    ::heart_beat();
}

void check_my_heart()
{
    if (heartcount > 300) {
        return;
    }
    if (BEAT > 7) {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart", 1);
        return;
    }
    BEAT++;
    call_out("check_my_heart", 1);
    return;
}

void catch_tell(string str)
{
    str = lower_case(str);
    if (interact("ghost warrior drops dead", str)) {
        call_out("raise_warrior", 2);
    }
    if (interact("epithon drops dead", str)) {
        call_out("raise_prince", 2);
    }
}

void raise_warrior()
{
    if (is_raising == 1) {
        return;
    }
    if (ignoring == 1) {
        force_me("say I am ignoring that");
        ignoring = 0;
        return;
    }
    force_me("emote %^RESET%^%^CYAN%^turns as " + TO->QS + " sees the ghost"
             + " warrior fall, and begins a solemn chant over the body.");
    is_raising = 1;
    call_out("raise_warrior2", 5);
    block_all_priests();
    set_paralyzed(30, "You are busy raising stuff");
}

void raise_warrior2()
{
    object corpse;
    set_paralyzed(0, "you're still stuffed");
    if (!objectp(ETO)) {
        is_raising = 0;
        return;
    }
    tell_room(ETO, query_short() + " %^RESET%^%^CYAN%^completes " + TO->QP
              + " chant, returning the ghost warrior to"
              + " life.%^RESET%^\n Err, well, to unlife, at least");
    corpse = present("corpse of ghost warrior", ETO);
    if (objectp(corpse)) {
        corpse->remove();
    }
    new(MOB + "ghost_warrior2.c")->move(ETO);
    is_raising = 0;
}

void raise_prince()
{
    if (!objectp(ETO) || is_raising == 1) {
        return;
    }
    if (ignoring == 1) {
        force_me("say I am ignoring that");
        ignoring = 0;
        return;
    }
    force_me("emote %^RESET%^%^CYAN%^turns as " + TO->QS + " sees Epithon"
             + " fall, and begins a solemn chant over the body.");
    is_raising = 1;
    call_out("raise_prince2", 5);
    block_all_priests();
    set_paralyzed(30, "You are busy raising stuff");
}

void block_all_priests()
{
    object* critters, priest;
    int i;
    critters = all_living(ETO);
    for (i = 0; i < sizeof(critters); i++) {
        priest = critters[i];
        if (priest->id("tecqumin priest") && priest != TO) {
            priest->ignore();
        }
    }
}

void ignore()
{
    ignoring = 1;
//  force_me("emote ignores everything for a moment");
}

void raise_prince2()
{
    object corpse;
    set_paralyzed(0, "you're still stuffed");
    if (!objectp(ETO)) {
        is_raising = 0;
        return;
    }
    tell_room(ETO, query_short() + " %^RESET%^%^CYAN%^completes " + TO->QP
              + " chant, returning %^BOLD%^%^RED%^Epithon%^RESET%^ to"
              + " life.%^RESET%^\n Err, well, to unlife, at least");
    corpse = present("corpse of epithon", ETO);
    if (objectp(corpse)) {
        corpse->remove();
    }
    new(MOB + "epithon.c")->move(ETO);
    is_raising = 0;
}

int drag_me(object who)
{
    if (!objectp(who)) {
//    force_me("say Hah! I can't drag that, it doesn't exist!");
        return -1;
    }
    force_me("drag " + who->query_name());
    return 1;
}

object query_draggee()
{
    object* inv;
    int i;

    inv = all_inventory(TO);
    if (sizeof(inv) < 1) {
        return 0;
    }
    for (i = 0; i < sizeof(inv); i++) {
        if (living(inv[i])) {
            return inv[i];
        }
    }
    return 0;
}

void reach_destination()
{
    object draggee;
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }

    draggee = query_draggee();
    if (!objectp(draggee)) {
        return;
    }
    if (ETO->query_sacrificing()) {
        return;
    }
    force_me("say Let all rejoice in the gifts of the %^BOLD%^%^YELLOW%^S"
             + "%^WHITE%^u%^YELLOW%^nl%^WHITE%^o%^YELLOW%^rd%^RESET%^! The"
             + " mighty warriors of the %^ORANGE%^Tecqumin%^RESET%^ bring Him"
             + " another gift of %^RED%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^febl"
             + "%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^RESET%^!");
    force_me("drop " + draggee->query_race());
    ETO->begin_sacrifice(draggee);
}

int aggfunc()
{
    if (!objectp(TO) || !objectp(ETO)) {
        return 0;
    }
    if (TP->query_true_invis()) {
        return 0;
    }

    kill_ob(TP, 1);
    call_out("spell_effect", 0);
    force_me("kill " + TPQN + "");
    return 1;
}

int spell_effect()
{
    if (!objectp(TO) || !objectp(ETO)) {
        return 0;
    }
    force_me("watch");
}
