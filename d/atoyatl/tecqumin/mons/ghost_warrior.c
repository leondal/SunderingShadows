//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit MONSTER;

//object dragee;
int last_beat, sacrificing;
nosave int BEAT, heartcount;

void create()
{
    string gender_poss, gender_Subj, gender_subj, gender_obj;
    object guider, ob;

    ::create();
    report("%^BOLD%^%^CYAN%^New Ghost warrior made");
    set_name("Ghost warrior");
    set_id(({ "ghost", "tecqumin", "warrior", "tecqumin warrior", "monster",
              "tecqumin ghost warrior", "ghost warrior", }));
    set_short("%^RESET%^%^ORANGE%^Tecqumin %^BOLD%^%^WHITE%^gh"
              + "%^RESET%^o%^BOLD%^%^WHITE%^st %^RESET%^"
              + "%^ORANGE%^warrior");
    set_race("ghost");
    set_body_type("humanoid");
    set_wielding_limbs(({ "right hand", "left hand" }));
    will_open_doors(1);
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
    set_long("%^RESET%^A long dead %^ORANGE%^warrior%^RESET%^ of the"
             + " Tecqumin. Once a fierce and proud fighter, "
             + gender_poss + " spirit now appears as a flickering,"
             + " %^CYAN%^tr%^RESET%^a%^CYAN%^nsl%^RESET%^u%^CYAN%^cent"
             + " %^RESET%^human figure. When at its most visible, you can"
             + " make out the deep bronzed skin stretched tight across a"
             + " lithe, well muscled body. " + gender_Subj + " is dressed"
             + " in a woven kilt, with a multi coloured"
             + " %^RED%^p%^MAGENTA%^o%^ORANGE%^n%^MAGENTA%^c%^ORANGE%^h"
             + "%^RED%^o%^RESET%^ thrown over " + gender_poss
             + " shoulders. %^YELLOW%^G%^RESET%^%^ORANGE%^ol%^YELLOW%^d"
             + "%^RESET%^%^ORANGE%^e%^YELLOW%^n br%^RESET%^%^ORANGE%^a"
             + "%^YELLOW%^c%^RESET%^%^ORANGE%^e%^YELLOW%^rs%^RESET%^"
             + " adorn " + gender_poss + " arms and " + gender_subj
             + " wears an abundance of decorative s%^BOLD%^%^WHITE%^i"
             + "%^RESET%^lv%^BOLD%^%^WHITE%^e%^RESET%^r %^BOLD%^"
             + "%^WHITE%^t%^RESET%^or%^BOLD%^%^WHITE%^c%^RESET%^s and"
             + " bangles. At different times, though it %^CYAN%^fl"
             + "%^RESET%^i%^CYAN%^ck%^RESET%^e%^CYAN%^rs%^RESET%^ and"
             + " becomes almost completely invisible, with %^BOLD%^"
             + "%^GREEN%^horrific%^RESET%^ flashes of uncovered"
             + " %^MAGENTA%^m%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^scle"
             + "%^RESET%^, %^BOLD%^%^RED%^f%^MAGENTA%^l%^RESET%^"
             + "%^MAGENTA%^e%^BOLD%^%^MAGENTA%^sh%^RESET%^ and %^BOLD%^"
             + "%^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^ne%^RESET%^ striking"
             + " your eyes as different layers of " + gender_poss
             + " body fade in and out of vision.");
    set_class("fighter");
    set_mlevel("fighter", 50);
    level = 50;
    set_guild_level("fighter", 50);
    set_hp(random(1000) + 1600 + random(400));
    set_max_level(49);
    set_property("swarm", 1);
    set_alignment(7);
    set_overall_ac(-50);
    set_size(2);
    add_attack_bonus(73);
    set_property("magic", 1);
    set_monster_feats(({
        "power attack",
        "rush",
        "damage resistance",
        "shatter",
        "sunder",
        "daze",
        "shieldbash",
        "counter",
        "deflection",
        "reflection",
        "shieldwall"
    }));
    set("aggressive", 18);
    set_stats("strength", 26);
    set_stats("intelligence", 10);
    set_stats("dexterity", 16);
    set_stats("charisma", 6);
    set_stats("wisdom", 20);
    set_alignment(4);
    set_new_exp(50, "normal");
    set_funcs(({ "shatter", "sunder", "rush", "shieldbash", "summon_help" }));
    set_func_chance(40);
    set_mob_magic_resistance("low");
    set_property("bludgeoning resistance", 20);
    set_property("slashing resistance", 10);
    set_property("piercing resistance", 10);
    set_attacks_num(8);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "left arm", "right arm" }));
    set_damage(7, 6);
    set_property("full attacks", 1);
    set_property("swarm", 1);
    set_speed(0);
    set_max_level(45);
    set_alignment(4);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_emotes(1, ({
        "The %^CYAN%^translucent%^RESET%^, %^BOLD%^%^WHITE%^g%^RESET%^"
        + "%^ORANGE%^h%^BOLD%^%^WHITE%^ost%^RESET%^%^ORANGE%^l%^BOLD%^"
        + "%^WHITE%^y%^RESET%^%^ORANGE%^ w%^BOLD%^%^WHITE%^a%^RESET%^"
        + "%^ORANGE%^rri%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^r%^RESET%^"
        + " flickers in and out of sight.",
    }), 0);
    set_emotes(10, ({
        "The ghostly warrior %^BOLD%^%^WHITE%^flashes%^RESET%^ and"
        + " disappears for a moment",

        "The ghost of the tecqumin warrior brandishes its ethereal"
        + " weapon",
    }), 1);
    ob = new(OBJ + "ether_sword");
    ob->move(TO);
    if (random(10)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wield shortsword");
    ob->set_wield_state();
    ob = new(OBJ + "torc_lesser");
    ob->move(TO);
    if (random(20)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wear torc");
    ob = new(OBJ + "poncho");
    ob->move(TO);
    if (random(20)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wear poncho");
    ob = new(OBJ + "stone_buckler.c");
    ob->move(TO);
    if (random(20)) {
        ob->set_property("monsterweapon", 1);
    }
    force_me("wield buckler");
    will_open = 1;
    BEAT = 0;
    heartcount = 0;
    check_my_heart();
    set_property("no random treasure", 1);
    set_nogo(({ JUNG_ROOM4 + "city_jung14", JUNG_ROOM6 + "ragged_road_connection", JUNG_ROOM2 + "city_entrance" }));
    set_speed(0);
    set_no_clean(1);
    set_property("not random monster", 1);
}

void report(string str)
{
//  "/daemon/reporter_d"->report("lujke", str);
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

int cause_typed_damage(object victim, string limb, int damage, string damage_type)
{
    int attack_type;
    object attacker;
    attacker = query_current_attacker();
    if (!objectp(attacker)) {
        attacker = victim;
    }
    if (!objectp(attacker)) {
        tell_room(ETO, "Error with damage processing function: attacker does not exist. Please make a bug report.");
        return;
    }
    attack_type = categorize_incoming_attack(attacker);
    if (attack_type == MELEE) {
        force_me("taking melee damage");
        if (damage > query_hp() / 1000) {
            force_me("shieldwall defensive");
        }
    }
    return ::cause_typed_damage(victim, limb, damage, damage_type);
}

varargs void do_walk(int iteration)
{
    report("%^BOLD%^%^GREEN%^starting do_walk");
    ::do_walk(iteration);
    report("%^BOLD%^%^GREEN%^finished do_walk");
}

void move_around()
{
    report("%^BOLD%^%^YELLOW%^starting move_around");
    ::move_around();
    if (objectp(ETO)) {
        ETO->set_had_players(3);
    }
    report("%^BOLD%^%^YELLOW%^finished move_around");
}

int categorize_incoming_attack(object attacker)
{
    int result, attack_type;
    object prev_ob, * weapons;
    string attacker_name, prev_ob_name;
    prev_ob = previous_object();
//  tell_room(ETO, "I was damaged by: " + file_name(prev_ob));
//  tell_room(ETO, "My attacker was: " + attacker->query_name());
//  tell_room(ETO, "Its file name is: " + file_name(attacker));
    attacker_name = attacker->query_name();
    // Work out what sort of attack it was, to determine what feat would affect the chances of targetting the attack
    attack_type = 0;
    if (!objectp(attacker)) {
        tell_room(ETO, "ERROR with attacking object. Not taking damage. Please make a bug report");
        return;
    }
    if (attacker->is_wielding("lrweapon")) {
//    tell_room(ETO, "Attack type: Ranged");
        attack_type = RANGED;
    } else {
        if (attacker->is_wielding("weapon")) {
//    tell_room(ETO, "Attack type: melee");
            attack_type = MELEE;
        }
    }
    prev_ob_name = file_name(prev_ob);
    if (interact("/cmds/spells/", prev_ob_name)) { //This would mean that the attack was a spell
        if ((string)prev_ob->get_save() == "reflex") {
//      tell_room(ETO, "Attack type: Area spell");
            attack_type = AREASPELL;
        } else {
//      tell_room(ETO, "Attack type: targetted spell");
            attack_type = TARGETSPELL;
        }
    } else {
//    tell_room(ETO, "The attack seems not to have been a spell");
    }
    return attack_type;
}

varargs int query_id_no(string id_name)
{
    int i, limit;
    if (!objectp(ETO)) {
        return 1;
    }
    if (!stringp(id_name)) {
        id_name = query_race();
    }
    limit = sizeof(all_living(ETO));
    for (i = 0; i < limit; i++) {
        if (present(id_name + " " + i) == TO) {
            return i;
        }
    }
    return 0;
}

void heart_beat()
{
    object critters, rope;
    int i, count, num;
    string race, dragname, path, roomname;
    if (objectp(ETO) && present("player", ETO)) {
        heartcount = 0;
    }
    if (time() < last_beat + 2) {
        return;
    }
    last_beat = time();
    ::heart_beat();
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    path = ETO->get_path();
    report("path: " + path);
    if (path == CITY_ROOM || path == ROOMS) {
        set_property("knock_unconscious", 1);
        report("Path is : " + path + ". Starting city room options");
        if (objectp(draggee)) {
            roomname = ETO->get_name();
            if (roomname == "broken_bridge01") {
                force_me("swing across canal");
                report("Trying to swing across the canal");
            } else {
                report("Not on the broken bridge");
                if (member_array(roomname, ({ "canalbank01", "city_jung02", "ragged_road01", "city_jung01", "canalbank03" })) != -1) {
                    report("Trying to walk to " + CITY_ROOM + "broken_bridge01");
                    start_walking(CITY_ROOM + "broken_bridge01");
                } else {
                    report("%^BOLD%^%^CYAN%^Not currently across the canal. roomname: " + roomname);
                }
            }
            report("What's going on?  Trying to get to the zenith");
            set_property("knock unconscious", 1);
            if (objectp(query_draggee())) {
                report("Trying to go to zigzenith");
                go_to_zigzenith();
            }
        }
    } else {
        report("Path is : " + path + ". Starting NON city room options");
        remove_property("knock unconscious");
        if (objectp(draggee)) {
            force_me("drop " + draggee->query_name());
            force_me("drop " + draggee->query_name());
        }
        return;
    }
    if (objectp(ETO) && base_name(ETO) != ROOMS + "zigzenith") {
        critters = all_living(ETO);
        count = sizeof(critters);
        if (count > 0) {
            for (i = 0; i < count; i++) {
                if (critters[i]->query_bound() > 100) {
                    if (critters[i]->query_gagged()) {
                        race = critters[i]->query_race();
                        num = critters[i]->query_id_no(race);
                        force_me("drag " + race + " " + num);
                        return;
                    }
                    race = critters[i]->query_race();
                    num = critters[i]->query_id_no(race);
                    force_me("gag " + race + " " + num);
                }
                if (critters[i]->query_unconscious()) {
                    race = critters[i]->query_race();
                    num = critters[i]->query_id_no(race);
                    rope = new("/d/common/obj/misc/rope");
                    rope->move(TO);
                    force_me("bind " + race + " " + num);
                    return;
                }
            }
        }
    }
    report(file_name(TO) + ": %^BOLD%^%^GREEN%^heartbeat completed");
}

void go_to_zigzenith()
{
    object room;
    string path, roomname, waystation;
    if (!objectp(ETO)) {
        return;
    }
    room = ETO;
    path = room->get_path();
    roomname = room->get_name();
    if (!stringp(path) || !stringp(roomname)) {
        return;
    }
    switch (path) {
    case ROOMS:
        report("go_to_zigzenith function: Trying to start walking to zigzenith");
        start_walking("/d/atoyatl/tecqumin/rooms/zigzenith");
        break;

    case CITY_ROOM:
        report("go_to_zigzenith function: We are in a city room");
        switch (roomname) {
        case "plaza":
            force_me("south");
            break;

        case "zig_approach":
            force_me("south");
            break;

        case "city_jung02":
        case "city_jung01":
        case "canalbank01":
        case "canalbank03":
        case "ragged_road01": //deliberately falling through
            report("go_to_zigzenith function: Trying to start walking to broken_bridge01");
            start_walking("/d/atoyatl/tecqumin/city/rooms/broken_bridge01");
            break;

        default:
            report("go_to_zigzenith function: Trying to start walking to plaza");
            start_walking(CITY_ROOM + "plaza");
            break;
        }
        break;
    }
    report("go_to_zigzenith function. End of function");
//  start_walking(ROOMS + "zigzenith");
}

int move(mixed dest)
{
    object where;
    int hold;
    where = ETO;

    hold = ::move(dest);
    if (objectp(ETO)) {
        report("%^BOLD%^%^MAGENTA%^Ghost warrior moved to: " + base_name(ETO));
    }
    if (objectp(where) && ETO != where && objectp(ETO) && base_name(ETO) != "/d/shadowgate/void") {
        tell_room(where, query_short() + " %^RESET%^%^BLUE%^leaves%^RESET%^, in silence.");
    }
    if (objectp(ETO) && ETO != where && base_name(ETO) != "/d/shadowgate/void") {
        tell_room(ETO, query_short() + " %^RESET%^%^ORANGE%^arrives%^RESET%^, bringing"
                  + " a slight %^BOLD%^%^CYAN%^ch%^WHITE%^i%^CYAN%^ll%^RESET%^ to the air.");
    }
    return hold;
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
                //       tell_room(ETO, "Checking " + exits[k] + " exit.");
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
            //     tell_room(ETO, base_name(all_critters[i]) + " starting walking towards " + base_name(ETO));
            all_critters[i]->start_walking(base_name(ETO));
        }
    }
}

void init()
{
    ::init();
//  force_me("wield knife");
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
    if (objectp(draggee)) {
        if (draggee->query_property("draggee")) {
            return draggee;
        }
    }
    return 0;
}

void sunder()
{
    object* critters;
    string who;
    critters = query_attackers();
    if (sizeof(critters) < 1) {
        return;
    }
    who = critters[random(sizeof(critters))]->query_name();
    force_me("sunder " + who);
}

void shatter()
{
    object* critters;
    string who;
    critters = query_attackers();
    if (sizeof(critters) < 1) {
        return;
    }
    who = critters[random(sizeof(critters))]->query_name();
    force_me("shatter " + who);
}

void rush()
{
    object* critters;
    string who;
    critters = query_attackers();
    if (sizeof(critters) < 1) {
        return;
    }
    who = critters[random(sizeof(critters))]->query_name();
    force_me("rush " + who);
}

void do_sacrifice()
{
    object draggee, * critters;
    int i, count;
    draggee = query_draggee();
    if (!objectp(draggee)) {
        return;
    }
    if (ETO->query_sacrificing()) {
        sacrificing = 0;
        return;
    }
    force_me("say Let all rejoice in the gifts of the %^BOLD%^%^YELLOW%^S"
             + "%^WHITE%^u%^YELLOW%^nl%^WHITE%^o%^YELLOW%^rd%^RESET%^! The"
             + " mighty warriors of the %^ORANGE%^Tecqumin%^RESET%^ bring Him"
             + " another gift of %^RED%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^febl"
             + "%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^RESET%^!");
    ETO->begin_sacrifice(draggee);
    call_out("drop_draggee", 1);
}

void drop_draggee()
{
    force_me("drop " + draggee->query_name());
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

void reach_destination()
{
    string roomname, path;
    ::reach_destination();
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    if (base_name(ETO) == ROOMS + "zigzenith") {
        call_out("do_sacrifice", 1);
    }
    roomname = ETO->get_name();
    path = ETO->get_path();
    switch (roomname) {
    case "j_link1a":
        force_me("north");
        break;

    case "city_entrance":
        force_me("east");
        break;

    case "j_link3":
        force_me("east");
        break;

    case "city_jung14":
        force_me("south");
        break;

    case "j_link4a":
        force_me("west");
        break;

    case "ragged_road_connection":
        force_me("west");
        break;

    case "j_link6a":
        force_me("north");
        break;

    case "j_link8":
        force_me("southwest");
        break;

    case "broken_bridge01":
        force_me("swing across canal");
        break;
    }
}

void die()
{
    object unf, attacker;
    if (objectp(ETO)) {
        unf = present("unfettered", ETO);
        if (objectp(unf)) {
            tell_room(ETO, "The " + query_short() + "%^RESET%^ gives out an extended,"
                      + " despairing %^BOLD%^%^WHITE%^sigh%^RESET%^, as its"
                      + " %^BOLD%^%^CYAN%^essence%^RESET%^ is drawn into the malevolent form of"
                      + " the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r"
                      + "%^MAGENTA%^e%^BLUE%^d");
            unf->enhance();
        }
    }
    attacker = query_current_attacker();
    if (objectp(attacker) && userp(attacker)) {
        EVENT_RECORDS_D->record_kill(attacker->query_name(), base_name(TO), time());
    }
    ::die();
}
