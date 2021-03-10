//Moving all trap lib into this file - hoping to
//cut down on code and allow better functionality - Saide
//should be inherited by Object.c
#include <std.h>
#include <daemons.h>

//if TrapLevel is special - then let TrapType be a function
//in the object - so we can have special traps
//IE you get thrown into another room or whatever - Saide

varargs void set_trapped(string* actions, string* TrapLevels, string* TrapTypes, int PSetter, int trapDC); // added argument to allow setting trap DC in trapped rooms
void remove_trap(string str);
void disable_trap(string str, int DisableType);
void set_random_traps();
void clear_random_traps();
int is_this_trapped(string str);
varargs int execute_trap(string str, object who, int failure_possible);

//set_trapped(({"unlock oak door", "open oak door"}), ({"low", "mid"}), ({"acid", "fire"}));

//TRAP_D->get_trap("random", "random");

mapping trap_data = ([]);
//Psetter = 0 for a room trap that's always there, 1 for a player setting it
//and 2 for a trap that's placed randomly - Saide

varargs void set_trapped(string* actions, string* TrapLevels, string* TrapTypes, int PSetter, int trapDC)
{
    string MyTrapFile, MyTrapLvl, MyTrapType, MyTrapDc;
    object TrapOb;
    int x;
    string* MobKnown = ({}), * PlayerKnown = ({});
    mixed tmp;
    if (!sizeof(actions)) {
        return;
    }
    if (!sizeof(TrapLevels)) {
        return;
    }
    if (!sizeof(TrapTypes)) {
        return;
    }
    if (!mapp(trap_data)) {
        trap_data = ([]);
    }
    if (!intp(PSetter)) {
        PSetter = 0;
    }
    if (PSetter == 0 || PSetter == 2) {
        if ((tmp = TO->query_property("traps_known_to_monsters"))) {
            if (stringp(tmp)) {
                MobKnown += ({ tmp });
            }else if (pointerp(tmp)) {
                MobKnown += tmp;
            }
        }
    }
    if (PSetter == 1) {
        if ((tmp = TO->query_property("traps_known_to_players"))) {
            if (stringp(tmp)) {
                PlayerKnown += ({ tmp });
            }
            if (sizeof(tmp)) {
                PlayerKnown = tmp;
            }
        }
    }
    for (x = 0; x < sizeof(actions); x++) {
        if (x >= sizeof(TrapLevels) || x >= sizeof(TrapTypes)) {
            continue;
        }
        MyTrapLvl = TrapLevels[x];
        //tell_object(find_player("saide"), "MyTrapLvl = "+MyTrapLvl);
        MyTrapType = TrapTypes[x];
        if (MyTrapLvl != "special") {
            if (MyTrapLvl != "custom") {
                TrapOb = TRAP_D->get_trap_object(MyTrapLvl, MyTrapType);
            }
            if (MyTrapLvl == "custom") {
                if (strsrch(TrapTypes[x], ".c") == -1) {
                    TrapTypes[x] += ".c";
                }
                if (file_exists(TrapTypes[x])) {
                    TrapOb = new(TrapTypes[x]);
                }
            }
            if (!objectp(TrapOb)) {
                continue;
            }
            MyTrapDc = (int)TrapOb->query_dc();
            if (trapDC) {
                MyTrapDc = trapDC;
            }
            MyTrapFile = base_name(TrapOb);
            TrapOb->remove();
        }
        if (MyTrapLvl == "special") {
            MyTrapFile = TrapTypes[x];
            MyTrapDc = 15;
        }

        if (!trap_data[actions[x]]) {
            //trap state - 1 for set
            //0 for disarmed, -1 for recovered
            //-1 will take longer to reset in a room
            //and disarm/recover will both remove
            //the trap from an object - this is my theory anyway

            trap_data += ([actions[x] : (["trap object" : MyTrapFile,
                                          "trap state" : 1, "is room" : (int)TO->is_room(),
                                          "trap level" : MyTrapLvl, "enable time" : -1,
                                          "trap setter" : PSetter, "dc" : MyTrapDc, "failed_check" : ([]),
                                          "passed_check" : ({}), "set by" : 0, "KnownToMobs" : MobKnown,
                                          "KnownToPlayers" : PlayerKnown, "failedknow" : ([]), ]), ]);
        }
        continue;
    }
    return;
}

string get_trap_object_auto_detect(string str, object who)
{
    int MySkill, x, flag;
    string MN, * TrapKeys, ThisTrap;
    if (!objectp(TO)) {
        return str;
    }
    if (!objectp(who)) {
        return str;
    }
    if (!who->query("is_auto_detecting_traps")) {
        return str;
    }
    if (!sizeof(trap_data)) {
        return str;
    }
    if (!userp(who)) {
        return str;
    }
    MN = who->query_name();
    TrapKeys = keys(trap_data);
    MySkill = (int)who->query_skill("dungeoneering");
    for (x = 0; x < sizeof(TrapKeys); x++) {
        if (!trap_data[TrapKeys[x]]) {
            continue;
        }
        if (trap_data[TrapKeys[x]]["trap state"] != 1) {
            continue;
        }
        if (userp(who) && member_array(MN, trap_data[TrapKeys[x]]["KnownToPlayers"]) != -1) {
            flag = 2;
            break;
        }
        if (member_array(MN, keys(trap_data[TrapKeys[x]]["failed_check"])) != -1 &&
            trap_data[TrapKeys[x]]["failed_check"][MN] >= MySkill) {
            continue;
        }
        if (member_array(MN, trap_data[TrapKeys[x]]["passed_check"]) != -1 ||
            (MySkill + roll_dice(1, 20)) > trap_data[TrapKeys[x]]["dc"]) {
            TO->add_passed_check(TrapKeys[x], MN);
            flag = 1;
            break;
        }else {
            TO->add_failed_check(TrapKeys[x], MN, MySkill);
            continue;
        }
        continue;
    }
    if (flag == 2) {
        return str + " (%^BOLD%^%^GREEN%^trapped%^BOLD%^%^CYAN%^)";
    }
    if (flag == 1) {
        return str + " (%^BOLD%^%^RED%^trapped%^BOLD%^%^CYAN%^)";
    }
    return str;
}

string get_trap_room_auto_detect(string str, object who, int is_door)
{
    int MySkill, x, flag;
    string MN, * DoorChecks = ({ "open", "lock", "pick", "unlock" });
    string* TrapKeys, ThisTrap;
    if (!objectp(TO)) {
        return str;
    }
    if (!mapp(trap_data)) {
        return str;
    }
    if (!objectp(who)) {
        return str;
    }
    if (!userp(who)) {
        return str;
    }
    if (!who->query("is_auto_detecting_traps")) {
        return str;
    }
    MN = who->query_name();
    MySkill = (int)who->query_skill("dungeoneering");
    if (sizeof(who->query_armour("torso"))) {
        MySkill += (int)who->skill_armor_mod(TP->query_armour("torso"));
    }
    switch (is_door) {
    case 0:
        if (!trap_data[str]) {
            return str;
        }
        if (trap_data[str]["trap state"] != 1) {
            return str;
        }
        if (userp(who)) {
            if (member_array(MN, trap_data[str]["KnownToPlayers"]) != -1) {
                return "%^BOLD%^%^GREEN%^" + str + " (your trap)%^BOLD%^%^CYAN%^";
            }
        }
        if (member_array(MN, keys(trap_data[str]["failed_check"])) != -1) {
            if (trap_data[str]["failed_check"][MN] >= MySkill) {
                return str;
            }
        }
        if (member_array(MN, trap_data[str]["passed_check"]) != -1 ||
            (MySkill + roll_dice(1, 20)) >= trap_data[str]["dc"]) {
            TO->add_passed_check(MN);
            return "%^BOLD%^%^RED%^" + str + " (trap)%^BOLD%^%^CYAN%^";
        }
        if ((MySkill + roll_dice(1, 20)) < trap_data[str]["dc"]) {
            TO->add_failed_check(str, MN, MySkill);
            return str;
        }
        break;

    case 1:
        TrapKeys = keys(trap_data);
        for (x = 0; x < sizeof(TrapKeys); x++) {
            if (member_array(TrapKeys[x], DoorChecks) != -1) {
                if (trap_data[TrapKeys[x]]["trap state"] != 1) {
                    continue;
                }
                if (userp(who)) {
                    if (member_array(MN,
                                     trap_data[TrapKeys[x]]["KnownToPlayers"]) != -1) {
                        flag = 2;
                        break;
                    }
                }
                if (member_array(MN, keys(trap_data[TrapKeys[x]]["failed_check"]))
                    != -1) {
                    if (trap_data[TrapKeys[x]]["failed_check"][MN] >= MySkill) {
                        continue;
                    }
                }
                if (member_array(MN, trap_data[TrapKeys[x]]["passed_check"]) != -1
                    || (MySkill + roll_dice(1, 20)) >= trap_data[TrapKeys[x]]["dc"]) {
                    TO->add_passsed_check(TrapKeys[x], MN);
                    flag = 1;
                    break;
                }else {
                    TO->add_failed_check(TrapKeys[x], MN, MySkill);
                    continue;
                }
                continue;
            }
            if (strsrch(TrapKeys[x], str) == -1) {
                continue;
            }
            if (trap_data[TrapKeys[x]]["trap state"] != 1) {
                continue;
            }
            if (userp(who)) {
                if (member_array(MN, trap_data[TrapKeys[x]]["KnownToPlayers"]) != -1) {
                    flag = 2;
                    break;
                }
            }
            if (member_array(MN, keys(trap_data[TrapKeys[x]]["failed_check"])) != -1) {
                if (trap_data[TrapKeys[x]]["failed_check"][MN] >= MySkill) {
                    continue;
                }
            }
            if (member_array(MN, trap_data[TrapKeys[x]]["passed_check"]) != -1
                || (MySkill + roll_dice(1, 20)) >= trap_data[TrapKeys[x]]["dc"]) {
                TO->add_passsed_check(TrapKeys[x], MN);
                flag = 1;
                break;
            }else {
                TO->add_failed_check(TrapKeys[x], MN, MySkill);
                continue;
            }
            continue;
        }
        if (flag == 2) {
            return str + " (%^BOLD%^%^GREEN%^trapped%^CYAN%^)";
        }
        if (flag == 1) {
            return str + " (%^BOLD%^%^RED%^trapped%^CYAN%^)";
        }else {
            return str;
        }
        break;
    }
    return str;
}

int is_trapped(string str)
{
    string MyAction;
    if (!stringp(str)) {
        return 0;
    }
    if (!mapp(trap_data)) {
        return 0;
    }
    MyAction = explode(str, " ")[0];
    if (trap_data[MyAction]) {
        if (trap_data[MyAction]["trap state"] == 1) {
            return 1;
        }
    }
    if (trap_data[str]) {
        if (trap_data[str]["trap state"] == 1) {
            return 1;
        }
    }
    return 0;
}

int trapped(string str)
{
    return is_trapped(str);
}

varargs int execute_trap(string str, object who, int FPP)
{
    string MyAction, * MyArrs, mobdir, * MBN;
    mixed ThisTrap = 0;
    object TRO;
    if (!objectp(who)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }
    if (!mapp(trap_data)) {
        return 0;
    }
    if (who->query_true_invis()) {
        return 0;
    }
    if (!intp(FPP)) {
        FPP = 0;
    }
    MyArrs = explode(str, " ");
    MyAction = MyArrs[0];
    if (trap_data[MyAction]) {
        if (trap_data[MyAction]["trap state"] == 1) {
            ThisTrap = MyAction;
        }
    }
    if (!ThisTrap) {
        if (trap_data[str]) {
            if (trap_data[str]["trap state"] == 1) {
                ThisTrap = str;
            }
        }
        if (!ThisTrap) {
            return 0;
        }
    }
    //this way we can have randomly placed traps in an area with
    //defined directories of monsters that will ignore them - Saide
    if (who->is_monster() && !FPP) {
        if (sizeof(trap_data[ThisTrap]["KnownToMobs"])) {
            MBN = explode(base_name(who), "/");
            mobdir = "/" + implode(MBN[0..(sizeof(MBN) - 2)], "/") + "/";
            if (member_array(mobdir, trap_data[ThisTrap]["KnownToMobs"]) != -1) {
                return 0;
            }
        }
    }
    //you wont trigger your own trap, unless you happen to
    //fail as disarming/recovering it - Saide
    if (userp(who) && !FPP) {
        if (sizeof(trap_data[ThisTrap]["KnownToPlayers"])) {
            if (member_array(who->query_name(), trap_data[ThisTrap]["KnownToPlayers"]) != -1) {
                return 0;
            }
        }
    }
    ///tell_object(who, "Trap Level = "+trap_data[ThisTrap]["trap level"]);
    if (trap_data[ThisTrap]["trap level"] == "special") {
        if (!trap_data[ThisTrap]["is room"]) {
            tell_room(environment(who), who->QCN + "%^BOLD%^%^BLUE%^ " +
                      "has trigged a trap on " + TOQCN + "%^BOLD%^%^BLUE%^!%^RESET%^", who);

            tell_object(who, "%^BOLD%^%^BLUE%^You have trigged a trap on " +
                        TOQCN + "%^BOLD%^%^BLUE%^!%^RESET%^");
            call_other(TO, trap_data[ThisTrap]["trap object"], str);
            remove_trap(ThisTrap);
        }else {
            call_other(TO, trap_data[ThisTrap]["trap object"], str);
            disable_trap(ThisTrap, 1);
        }
        return 1;
    }
    if (trap_data[ThisTrap]["trap level"] != "special") {
        TRO = new(trap_data[ThisTrap]["trap object"]);
        if (!objectp(TRO)) {
            tell_object(who, "There was a problem with the trap " +
                        "object.  Please bug report this.");
            remove_trap(ThisTrap);
            return 0;
        }
        TRO->set_trap_setter(trap_data[ThisTrap]["trap setter"]);
        TRO->set_my_dc(trap_data[ThisTrap]["dc"]);
        if (!trap_data[ThisTrap]["is room"]) {
            tell_room(environment(who), who->QCN + "%^BOLD%^%^BLUE%^ " +
                      "has trigged a trap on " + TOQCN + "%^BOLD%^%^BLUE%^!%^RESET%^", who);

            tell_object(who, "%^BOLD%^%^BLUE%^You have trigged a trap on " +
                        TOQCN + "%^BOLD%^%^BLUE%^!%^RESET%^");
            TRO->set_origin_object(TOQCN);
            TRO->trap_activated(who);
            remove_trap(ThisTrap);
        }else {
            tell_room(TO, who->QCN + "%^BOLD%^%^BLUE%^ has triggered a " +
                      "trap!%^RESET%^", who);
            if (member_array(MyArrs[0], TO->query_exits()) != -1) {
                TRO->set_origin_object(MyArrs[0]);
            }else {
                if (sizeof(MyArrs) > 1) {
                    TRO->set_origin_object(implode(MyArrs[1..(sizeof(MyArrs) - 1)],
                                                   " "));
                }
            }
            tell_object(who, "%^BOLD%^%^BLUE%^You have triggered a trap!" +
                        "%^RESET%^");

            TRO->trap_activated(who);

            disable_trap(ThisTrap, 1);
        }
        TRO->remove();
        return 1;
    }
    return 1;
}

void remove_trap(string str)
{
    if (!mapp(trap_data)) {
        return;
    }
    if (!trap_data[str]) {
        return;
    }
    map_delete(trap_data, str);
}

void disable_trap(string str, int DisableType)
{
    if (!mapp(trap_data)) {
        return;
    }
    if (!trap_data[str]) {
        return;
    }
    if (!intp(DisableType)) {
        return;
    }
    //set by a player - so remove instead of toggle off in rooms - Saide
    //or set by as a random trap - remove instead of toggle off in rooms
    //1 = player, 2 = random
    if (trap_data[str]["trap setter"] != 0 ||
        trap_data[str]["is room"] != 1) {
        remove_trap(str);
        return 1;
    }
    switch (DisableType) {
    case 1:
        trap_data[str]["trap state"] = 0;
        trap_data[str]["enable time"] = time() + 1200;
        trap_data[str]["failed_check"] = ([]);
        trap_data[str]["passed check"] = ({});
        break;

    case 2:
        trap_data[str]["trap state"] = -1;
        trap_data[str]["enable time"] = time() + 3600;
        trap_data[str]["failed_check"] = ([]);
        trap_data[str]["passed_check"] = ({});
        break;

    default:
        trap_data[str]["trap state"] = 0;
        trap_data[str]["enable time"] = time() + 1200;
        trap_data[str]["failed_check"] = ([]);
        trap_data[str]["passed_check"] = ({});
        break;
    }
}

varargs void set_trap_functions(string* what, string* funcs, string* trigger, int trapDC) //added argument to allow setting DC to traps in rooms - Odin 3/26/2020
{
    string* TLvls;
    int x;
    TLvls = ({});
    for (x = 0; x < sizeof(what); x++) {
        TLvls += ({ "special" });
        if (trigger[x] != what[x]) {
            what[x] = ({ trigger[x] + " " + what[x] });
        }
        continue;
    }
    //tell_object(find_player("saide"), "TLvls = "+identify(TLvls));
    return set_trapped(trigger, TLvls, funcs, 0, trapDC);
}

void query_trap_data()
{
    return trap_data;
}

int is_this_trapped(string str)
{
    if (!stringp(str)) {
        return 0;
    }
    if (!mapp(trap_data)) {
        return 0;
    }
    if (trap_data[str]) {
        return 1;
    }
    return 0;
}

void check_random_traps()
{
    //moved here from room.c reset function, with a call to this function from reset in room.c
    //attemping to make it so that random traps can appear not just on reset but when a room
    //is originally created - Saide
    int tf, tc;
    if (!objectp(TO)) {
        return;
    }
    if (TO->query_property("random traps")) {
        //changing this slightly so to provide for more frequent random traps
        //adding a functionality for an area to have set_property("random trap frequency")

        if (undefinedp(TO->query_property("random trap frequency"))) {
            tc = random(3);
        }else {
            tf = TO->query_property("random trap frequency");
            if (tf >= random(100)) {
                tc = 0;
            }
        }
        if (!tc) {
            TO->set_random_traps();
            TO->set_property("next_random_trap_time", time() + 3600);
        }
    }
}

void set_random_traps()
{
    mapping MyDoorMap;
    string* MyExits, * VDOORACTS = ({ "open", "close" });
    string* VLOCKACTS = ({ "pick", "unlock" });
    int RandNum;
    string MyDoor, MyDoorLock, * DLs, * MyDoors;
    string* MyActs = ({}), Tlvl, CurTAct, * Tlvls = ({}), * Ttypes = ({});
    if (!objectp(TO)) {
        return;
    }
    if (time() > (int)TO->query_property("next_random_trap_time")) {
        TO->clear_random_traps();
    }
    if ((int)TO->query_property("next_random_trap_time") > time()) {
        return;
    }
    if (!stringp(Tlvl = TO->query_property("random traps"))) {
        return;
    }
    RandNum = 1 + random(2);
    if (TO->is_vault()) {
        MyDoorMap = TO->query_doors_map();
        MyDoors = keys(MyDoorMap);
    }
    if (TO->is_room()) {
        MyExits = TO->query_exits();
    }
    if (!sizeof(MyExits) && !sizeof(MyDoors)) {
        return;
    }
    while (RandNum) {
        if (mapp(MyDoorMap) && sizeof(MyDoorMap)) {
            if (!random(3)) {
                MyDoor = MyDoors[random(sizeof(MyDoors))];
                DLs = TO->getLocks(MyDoor);
                if (sizeof(DLs)) {
                    MyDoorLock = DLs[random(sizeof(DLs))];
                    if (MyDoorMap[MyDoor][MyDoorLock]["locked"] == 1) {
                        if (MyDoorMap[MyDoor][MyDoorLock]["key"] != 0) {
                            CurTAct = VLOCKACTS[random(sizeof(VLOCKACTS))];
                        }else {
                            CurTAct = "unlock";
                        }
                        CurTAct += " " + MyDoor + " " + MyDoorLock;
                        if (!is_this_trapped(CurTAct)) {
                            MyActs += ({ CurTAct });
                            Tlvls += ({ Tlvl });
                            Ttypes += ({ "random" });
                        }
                        RandNum--;
                        continue;
                    }
                }
                CurTAct = VDOORACTS[random(sizeof(VDOORACTS))];
                CurTAct += " " + MyDoor;
                if (!is_this_trapped(CurTAct)) {
                    MyActs += ({ CurTAct });
                    Tlvls += ({ Tlvl });
                    Ttypes += ({ "random" });
                }
                RandNum--;
                continue;
            }
        }
        if (sizeof(MyExits) && !random(2)) {
            CurTAct = MyExits[random(sizeof(MyExits))];
            if (!is_this_trapped(CurTAct)) {
                MyActs += ({ CurTAct });
                Tlvls += ({ Tlvl });
                Ttypes += ({ "random" });
            }
            RandNum--;
            continue;
        }
        RandNum--;
        continue;
    }
    TO->set_trapped(MyActs, Tlvls, Ttypes, 2);
    return;
}

varargs int toggle_trap(string trap_loc, string trigger, string info)
{
    return 0;
}

void reactivate_traps()
{
    int x;
    string* TrapKeys;
    if (!mapp(trap_data)) {
        return;
    }
    if (!sizeof(TrapKeys = keys(trap_data))) {
        return;
    }
    for (x = 0; x < sizeof(TrapKeys); x++) {
        if (trap_data[TrapKeys[x]]["enable time"] == -1) {
            continue;
        }
        if (time() >= trap_data[TrapKeys[x]]["enable time"]) {
            trap_data[TrapKeys[x]]["trap state"] = 1;
            trap_data[TrapKeys[x]]["enable time"] = -1;
            continue;
        }
        continue;
    }
    return;
}

void clear_random_traps()
{
    int x;
    string* TrapKeys;
    if (!mapp(trap_data)) {
        return;
    }
    TrapKeys = keys(trap_data);
    if (!sizeof(TrapKeys)) {
        return;
    }
    for (x = 0; x < sizeof(TrapKeys); x++) {
        if (!trap_data[TrapKeys[x]]) {
            continue;
        }
        if (trap_data[TrapKeys[x]]["trap setter"] == 2) {
            TO->remove_trap(TrapKeys[x]);
            continue;
        }
        continue;
    }
}

void add_failed_check(string ThisTrap, string MyName, int MySkill)
{
    if (!sizeof(trap_data)) {
        return;
    }
    if (!mapp(trap_data)) {
        return;
    }
    if (!trap_data[ThisTrap]) {
        return;
    }
    if (member_array(MyName, keys(trap_data[ThisTrap]["failed_check"])) != -1) {
        if (MySkill > trap_data[ThisTrap]["failed_check"][MyName]) {
            trap_data[ThisTrap]["failed_check"][MyName] = MySkill;
        }
        return;
    }
    trap_data[ThisTrap]["failed_check"] += ([MyName:MySkill]);
    return;
}

void add_passed_check(string ThisTrap, string MyName)
{
    if (!sizeof(trap_data)) {
        return;
    }
    if (!mapp(trap_data)) {
        return;
    }
    if (!trap_data[ThisTrap]) {
        return;
    }
    if (member_array(MyName, keys(trap_data[ThisTrap]["failed_check"])) != -1) {
        map_delete(trap_data[ThisTrap]["failed_check"], MyName);
    }
    if (member_array(MyName, trap_data[ThisTrap]["passed_check"]) != -1) {
        return;
    }
    trap_data[ThisTrap]["passed_check"] += ({ MyName });
    return;
}

void set_trap_set_by(string ThisTrap, string who, int DC)
{
    if (!mapp(trap_data)) {
        return;
    }
    if (!sizeof(trap_data)) {
        return;
    }
    if (!trap_data[ThisTrap]) {
        return;
    }
    if (!trap_data[ThisTrap]["set by"]) {
        trap_data[ThisTrap]["set by"] = who;
        trap_data[ThisTrap]["dc"] = DC;
    }
    return;
}

mixed query_trap_set_by(string ThisTrap)
{
    if (!mapp(trap_data)) {
        return 0;
    }
    if (!sizeof(trap_data)) {
        return 0;
    }
    if (!stringp(ThisTrap)) {
        return 0;
    }
    if (!trap_data[ThisTrap]) {
        return 0;
    }
    if (!trap_data[ThisTrap]["set by"]) {
        return 0;
    }
    return trap_data[ThisTrap]["set by"];
}

void add_known_to(string ThisTrap, string which, mixed name)
{
    string* KT;
    if (!mapp(trap_data)) {
        return;
    }
    if (!sizeof(trap_data)) {
        return;
    }
    if (!stringp(ThisTrap)) {
        return;
    }
    if (which != "player" && which != "monster") {
        return;
    }
    if (!trap_data[ThisTrap]) {
        return;
    }
    if (!stringp(name) && !sizeof(name)) {
        return;
    }
    if (stringp(name)) {
        if (which == "player") {
            if (member_array(name, trap_data[ThisTrap]["KnownToPlayers"]) != -1) {
                return;
            }
            trap_data[ThisTrap]["KnownToPlayers"] += ({ name });
            return;
        }
        if (which == "monster") {
            if (member_array(name, trap_data[ThisTrap]["KnownToMobs"]) != -1) {
                return;
            }
            trap_data[ThisTrap]["KnownToMobs"] += ({ name });
            return;
        }
    }
    if (sizeof(name)) {
        name = distinct_array(name);
        if (which == "player") {
            KT = trap_data[ThisTrap]["KnownToPlayers"];
            name -= KT;
            KT = KT + name;
            trap_data[ThisTrap]["KnownToPlayers"] = KT;
        }
        if (which == "monster") {
            KT = trap_data[ThisTrap]["KnownToMobs"];
            name -= KT;
            KT = KT + name;
            trap_data[ThisTrap]["KnownToMobs"] = KT;
        }
        return;
    }
    return;
}

void add_failed_know(string ThisTrap, string MyName, int MySkill)
{
    if (!sizeof(trap_data)) {
        return;
    }
    if (!mapp(trap_data)) {
        return;
    }
    if (!trap_data[ThisTrap]) {
        return;
    }
    if (member_array(MyName, keys(trap_data[ThisTrap]["failedknow"])) != -1) {
        if (MySkill > trap_data[ThisTrap]["failedknow"][MyName]) {
            trap_data[ThisTrap]["failedknow"][MyName] = MySkill;
        }
        return;
    }
    trap_data[ThisTrap]["failedknow"] += ([MyName:MySkill]);
    return;
}

int query_failed_know(string ThisTrap, string MyName)
{
    if (!sizeof(trap_data)) {
        return 0;
    }
    if (!mapp(trap_data)) {
        return 0;
    }
    if (!trap_data[ThisTrap]) {
        return 0;
    }
    if (member_array(MyName, keys(trap_data[ThisTrap]["failedknow"])) == -1) {
        return 0;
    }
    return trap_data[ThisTrap]["failedknow"][MyName];
}

void remove_failed_know(string ThisTrap, string MyName)
{
    if (!sizeof(trap_data)) {
        return;
    }
    if (!mapp(trap_data)) {
        return;
    }
    if (!trap_data[ThisTrap]) {
        return;
    }
    if (member_array(MyName, keys(trap_data[ThisTrap]["failedknow"])) == -1) {
        return;
    }
    map_delete(trap_data[ThisTrap]["failedknow"], MyName);
}

void clear_all_traps()
{
    trap_data = ([]);
}
