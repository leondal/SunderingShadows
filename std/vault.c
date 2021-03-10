//      /std/vault.c
//      from the Nightmare mudlib
//      A room with as many doors as exits will allow
//      created by Descartes of Borg 23 february 1993
// added check for valid door back into LockDoor *Styx*  8/18/03, last change was 11/02
// added query_doors_map() for debugging trap & lock bugs *Styx* 5/8/06, last chg. 12/05

#include <std.h>
#include <daemons.h>
#define NUMBER   ({ "two", "three", "four", "five", "six", "seven", "eight", \
                    "nine", "ten", "many" })
#define TMPLONG  ({ "north", "northeast", "east", "southeast", "south", \
                    "southwest", "west", "northwest", "up", "down", "in", \
                    "out", "enter", "exit", })
#define TMPSHORT ({ "n", "ne", "e", "se", "s", "sw", "w", "nw", "u", "d", \
                    "in", "out", "enter", "exit", })

#define LOCK_DESC "This is a standard 2 tumbler door lock."
#define DOOR_DESC "This is a standard oak door, made of heavy oaken planks bound together with iron rivets."

inherit ROOM;

mapping doors, held, door_mod;

nosave mapping default_door_state; // used in clean_up so we can set doors outside to the right state -Ares

void set_hold_portal(string str1, int casterlevel);
int query_hold_portal(string str);
void set_invis_door(string id, int invis);
void set_open(string id, int open);
varargs void set_locked(string id, int locked, string lock_id);
void set_func(string id, string which, string fun);
void set_string(string id, string which, string str);
void set_door_pre_exit_function(string id, string fun);
int query_invis_door(string id);
int query_open(string id);
varargs int query_locked(string id, string lock_id);
void set_alt_doorname(string str);
void query_alt_doorname();
string alt_doorname;
int query_doors_map();  // added 5/8/06 *Styx*
void set_default_door_state(mixed map);
int get_phouse_lock_dc(string locklevel); //added by Odin 3/25/2020, helper function to standardize playerhouse lock DCs

int is_vault()
{
    return 1;
}

void init()
{
    ::init();
    add_action("OpenDoor", "open");
    add_action("CloseDoor", "close");
    add_action("UnlockDoor", "unlock");
    add_action("LockDoor", "lock");
    add_action("PickLock", "pick");
    add_action("KnockDoor", "knock");
}

void create()
{
    ::create();
    return;
}

void reset()
{
    ::reset();
    return;
}

void set_hold_portal(string str1, object spell)
{
    if (!held) {
        held = ([]);
    }
    held[str1] = spell;
}

object query_hold_portal(string str)
{
    if (!held) {
        return 0;
    }
    return held[str];
}

// going to try this again with the sync functions at the bottom -Ares
//int clean_up() { return 0; }
// was void clean_up() { return; } for some strange reason...
// - Garrett.

varargs void set_door(string id, string dest, string dir, string key, string lock_id)
{
    if (!id) {
        return;
    }
    if (!doors) {
        doors = ([]);
    }
    if (!lock_id) {
        lock_id = "lock";
    }
    doors[id] = (["destination" : dest, "direction" : dir, "invis" : 0, "description" : DOOR_DESC ]);
    add_pre_exit_function(dir, "GoThroughDoor");
//    if(!key) return;
    doors[id][lock_id] = (["key" : key, "desc" : LOCK_DESC, "locked" : 0, "mod" : 0]);
}

int query_doors_map()
{
    if (!doors) {
        doors = ([]);
    }
    return doors;
}

void add_lock(string id, string key, string lock_id, string lock_desc)
{
    if (!id) {
        return;
    }
    if (!lock_id) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id][lock_id] = (["key" : key, "desc" : lock_desc, "locked" : 1, "mod" : 0]);
}

void set_door_description(string id, string desc)
{
    if (!id) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id]["description"] = desc;
}

void set_lock_description(string door_id, string lock_id, string desc)
{
    if (!door_id) {
        return;
    }
    if (!lock_id) {
        lock_id = "lock";
    }
    if (!doors[door_id]) {
        return;
    }

    doors[door_id][lock_id]["desc"] = desc;
}

void set_invis_door(string id, int invis)
{
    if (!id) {
        return;
    }
    if (!doors) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id]["invis"] = invis;
}

varargs void set_locked(string id, int locked, string lock_id)
{
    if (!doors) {
        return;
    }
    if (!id) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    if (!lock_id) {
        lock_id = "lock";
    }
    if (!doors[id][lock_id]) {
        return;
    }
    doors[id][lock_id]["locked"] = locked;
}

void set_open(string id, int open)
{
    if (!id) {
        return;
    }
    if (!doors) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id]["open"] = open;
}

void set_func(string id, string which, string fun)
{
    if (!which) {
        return;
    }
    if (!id) {
        return;
    }
    if (!doors) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id][which + " fun"] = fun;
}

void set_string(string id, string which, string str)
{
    if (!id) {
        return;
    }
    if (!which) {
        return;
    }
    if (!doors) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id][which + " string"] = str;
}

void set_door_pre_exit_function(string id, string fun)
{
    if (!id) {
        return;
    }
    if (!doors) {
        return;
    }
    if (!doors[id]) {
        return;
    }
    doors[id]["pre exit"] = fun;
}

int query_invis_door(string id)
{
    if (!id) {
        return 1;
    }
    if (!doors) {
        return 1;
    }
    if (!doors[id]) {
        return 1;
    }
    return doors[id]["invis"];
}

varargs int query_locked(string id, string lock_id)
{
    if (!id) {
        return 0;
    }
    if (!doors) {
        return 0;
    }
    if (!doors[id]) {
        return 0;
    }
    if (!lock_id) {
        lock_id = "lock";
    }
    if (!doors[id][lock_id]) {
        return 0;
    }
    return doors[id][lock_id]["locked"];
}

int query_open(string id)
{
    if (!id) {
        return 0;
    }
    if (!doors) {
        return 1;
    }
    if (!doors[id]) {
        return 1;
    }
    return doors[id]["open"];
}

string* getLocks(string door)
{
    int i;
    string* theKeys;
    mapping* locks = ({});

    if (!door) {
        return 0;
    }
    if (!doors) {
        return 0;
    }
    if (!doors[door]) {
        return 0;
    }
    theKeys = keys(doors[door]);
    theKeys -= ({ "knock string", "pre exit", "destination", "direction", "invis", "open", "description", "open string", "close string", "lock string", "unlock string" });
    return theKeys;
}

string* getDoors()
{
    return keys(doors);
}

int isDoorlocked(string id)
{
    int i, j;
    mapping* theLocks;
    theLocks = getLocks(id);
    for (i = 0; i < sizeof(theLocks); i++) {
        if (doors[id][theLocks[i]]["locked"]) {
            return 1;
        }
    }
    return 0;
}

int isOpenable(string doorId)
{
    return (!query_locked(doorId) && !query_hold_portal(doorId));
}

int OpenDoor(string str)
{
    if (!held) {
        held = ([]);
    }
    if (!doors) {
        return 0;
    }

    set_default_door_state(query_doors_map());

    if (!str) {
        notify_fail("Open what?\n");
        return 0;
    }
    if (!doors[str]) {
        notify_fail("What " + str + "?\n");
        return 0;
    }
    if (doors[str]["open"]) {
        notify_fail("It is already open!\n");
        return 0;
    }
    if (isDoorlocked(str)) {
        notify_fail("It is locked.\n");
        return 0;
    }
    if (query_hold_portal(str) && objectp(held[str])) {
        notify_fail("Some force is causing the door to stick\n");
        //set_property("magic item", "Alteration");
        return 0;
    }
    if (TO->is_trapped("open " + str)) {
        if (TO->execute_trap("open " + str, this_player())) {
            return 1;
        }
    }
    if (doors[str]["open fun"]) {
        if (!call_other(this_object(), doors[str]["open fun"])) {
            return 1;
        }
    }
    if (doors[str]["open string"]) {
        write(doors[str]["open string"]);
    }else {
        write("You open the " + str + ".\n");
    }

    if (doors[str]["open string"]) {
        tell_room(ETP, TPQCN + " opens the " + str + ".\n" + (doors[str]["open string"]), TP);
    }else {
        tell_room(ETP, TPQCN + " opens the " + str + ".\n", TP);
    }
    if (objectp(find_object_or_load(doors[str]["destination"]))) {
        doors[str]["destination"]->set_open(str, 1);
        if (userp(TP)) {
            doors[str]["destination"]->set_had_players();
        }
        tell_room(find_object_or_load(doors[str]["destination"]), "You notice the " + str +
                  " opens from the other side.\n");
    }
    POISON_D->is_object_poisoned(TO, TP, "open", 1, str);
    set_open(str, 1);
    return 1;
}

int CloseDoor(string str)
{
    if (!doors) {
        return 0;
    }

    set_default_door_state(query_doors_map());

    if (!str) {
        notify_fail("Close what?\n");
        return 0;
    }
    if (!doors[str]) {
        notify_fail("What " + str + "?\n");
        return 0;
    }
    if (!doors[str]["open"]) {
        notify_fail("It is already closed!\n");
        return 0;
    }

    if (query_hold_portal(str) && objectp(held[str])) {
        notify_fail("Some force is causing the door to stick\n");
        //set_property("magic item", "Alteration");
        return 0;
    }
    if (TO->is_trapped("close " + str)) {
        if (TO->execute_trap("close " + str, this_player())) {
            return 1;
        }
    }
    if (doors[str]["close fun"]) {
        if (!call_other(this_object(), doors[str]["close fun"])) {
            return 1;
        }
    }
    if (doors[str]["close string"]) {
        write(doors[str]["close string"]);
    }else {
        write("You close the " + str + ".\n");
    }
//    say(this_player()->query_cap_name()+" closes the "+str+".\n");
    if (doors[str]["close string"]) {
        tell_room(ETP, TPQCN + " closes the " + str + ".\n" + (doors[str]["close string"]), TP);
    }else {
        tell_room(ETP, TPQCN + " closes the " + str + ".\n", TP);
    }

    if (objectp(find_object_or_load(doors[str]["destination"]))) {
        doors[str]["destination"]->set_open(str, 0);
        if (userp(TP)) {
            doors[str]["destination"]->set_had_players();
        }
        tell_room(find_object_or_load(doors[str]["destination"]), "The " + str +
                  " is closed by someone on the other side.\n");
    }
    POISON_D->is_object_poisoned(TO, TP, "close", 1, str);
    set_open(str, 0);
    return 1;
}

int UnlockDoor(string str)
{
    string ident, lock_id, key, syntax_msg;
    string* validLocks;
    object ob;
    syntax_msg = "For door locks, try <unlock [door id] with [key id]> or,"
                 "if there are multiple locks,\n try <unlock [lock id] on [door id] "
                 "with [key id].\n";
    if (!doors) {
        return 0;
    }

    set_default_door_state(query_doors_map());

    if (!str) {
        notify_fail("Unlock what?\n");
        return 0;
    }
    if (sscanf(str, "%s on %s with %s", lock_id, ident, key) != 3) {
        if (sscanf(str, "%s with %s", ident, key) != 2) {
            if (sscanf(str, "%s on %s", lock_id, ident) != 2) {
                if (sscanf(str, "%s", ident) != 1) {
                    write(syntax_msg);  // yes I mean to have this as write now *Styx*
                    return 0;
                }
            }
        }
    }
    if (!lock_id) {
// adding so it will default to whatever the first lock is before assuming "lock"
        if (!getLocks(ident)) {
            lock_id = "lock"; // was just this *Styx*
        } else {
            lock_id = getLocks(ident)[0];
        }
    }
    if (!doors[ident]) {
        // changing to add a check for objects too so it will indicate the door id being parsed out even if there is another unlock function it falls through to *Styx* 12/26/05
        notify_fail("You don't seem to find " + ident + " to unlock.\n");
        if (!present(ident)) {
            write("You don't seem to find " + ident + " to unlock in this room.");
            notify_fail("\n");
        }
        return 0;
    }
/* rewriting this section so valid attempts with wrong objects won't as easily
 * fall through to bag logic and the bad syntax message *Styx* 12/26/05
 *    if(!doors[ident][lock_id]) {
 *        notify_fail("It has no lock.\n");
 *        return 0;
 *    }
 *    if(doors[ident]["open"]) {
 *        notify_fail("Unlock it? It is open!\n");
 *        return 0;
 *    }
 *    if(!doors[ident][lock_id]["locked"]) {
 *        notify_fail("It is already unlocked.\n");
 *        return 0;
 *    }
 *    if(doors[ident][lock_id]["key"]) {
 *        if(!key)
 *            return notify_fail("With what are you unlocking the door?\n");
 *        if(!(ob=present(key,this_player()))) {
 *            notify_fail("You do not have that!\n");
 *            return 0;
 *        }
 *        if(!ob->id(doors[ident][lock_id]["key"])) {
 *            notify_fail("You fail to unlock the "+ident+" using the "+key+".\n");
 *            return 0;
 *        }
 *    }
 ***********/
    if (!doors[ident][lock_id]) {
        write("The " + ident + " does not have a " + lock_id + ".\n");
        return 1;
    }
    if (doors[ident]["open"]) {
        write("The " + ident + " is already open so it can't be locked!\n");
        return 1;
    }
    if (!doors[ident][lock_id]["locked"]) {
        write("The " + ident + " is already unlocked.\n");
        return 1;
    }
    if (doors[ident][lock_id]["key"]) {
        if (!key) {
            write("You probably need to specify a key.");
            return 0;
        }
        if (!(ob = present(key, TP))) {
            write("You do not seem to have a " + key + "!\n");
            return 1;
        }
        if (!ob->id(doors[ident][lock_id]["key"])) {
            write("You fail to unlock the " + ident + " using the " + key + "."
                  "  Perhaps it's the wrong key.\n");
            return 1;
        }
    }
    if (TO->is_trapped("unlock " + ident + " " + lock_id)) {
        if (TO->execute_trap("unlock " + ident + " " + lock_id, this_player())) {
            return 1;
        }
    }
    /*if(trapped("unlock") && query_trapped_state(ident, lock_id, "unlock")){
        if(do_spec_trap("unlock",lock_id)) return 1;
       }*/
    /*
       if(doors[ident]["unlock fun"]) {
        if(!call_other(this_object(), doors[ident]["unlock fun"])) return 1;
       }
     */
    if (doors[ident]["unlock string"]) {
        write(doors[ident]["unlock string"]);
    }else {
        write("You unlock the " + lock_id + " on " + ident + "" + ((key) ? " with the " + key + "" : "") + ".\n");
    }
    say(this_player()->query_cap_name() + " unlocks the " + lock_id + " in the " + ident +
        "" + ((key) ? " with the " + key + "" : "") + ".\n", this_player());

    if (objectp(find_object_or_load(doors[ident]["destination"]))) {
        doors[ident]["destination"]->set_locked(ident, 0, lock_id);
        if (userp(TP)) {
            doors[ident]["destination"]->set_had_players();
        }
        tell_room(doors[ident]["destination"],
                  "You hear some scratching noises on the other side of the " + ident + ".\n");
    }
    set_locked(ident, 0, lock_id);

    return 1;
}

int LockDoor(string str)
{
    string ident, key, lock_id;
    object ob;

    if (!doors) {
        return 0;
    }

    set_default_door_state(query_doors_map());

    if (!str) {
        notify_fail("Lock what with what?\n");
        return 0;
    }
    if (sscanf(str, "%s on %s with %s", lock_id, ident, key) != 3) {
        if (sscanf(str, "%s with %s", ident, key) != 2) {
            ident = str;
            lock_id = "lock";
            if (!doors[ident]) { // adding this check here to fix bug *Styx* 8/18/03
                notify_fail(ident + " doesn't seem to be a valid door.\n");
                return 0;
            }
            if (doors[ident][lock_id]["key"]) {
                notify_fail("Lock [which door] with [what key]? Or lock [lock id] on [what door] with [what key]?\nIf lock requires no key:  lock [which door]?\n");
                return 0;
            }
        } else {
            lock_id = "lock";
        }
    }
    if (!doors[ident]) {
        notify_fail("What " + ident + "?\n");
        return 0;
    }

    if (!doors[ident][lock_id]) {
        notify_fail("It has no such lock.\n");
        return 0;
    }
    /*  // this is needed above *Styx*
       if(!doors[ident][lock_id]["key"]) {
        notify_fail("It has no lock.\n");
        return 0;
       }
     */
    if (doors[ident]["open"]) {
        notify_fail("You cannot lock it while it is open.\n");
        return 0;
    }
    if (doors[ident][lock_id]["locked"]) {
        write("The " + lock_id + " on the " + ident + " is already locked.");
        return 1;
// making this full failure since it is so specific so it doesn't fall through to "No 'str' here or bad syntax."  *Styx* 5/10/06
//        notify_fail("It is already locked!\n");
//        return 0;
    }
    if (!doors[ident]) {
        notify_fail("What " + ident + "?\n");
        return 0;
    }
    if (doors[ident][lock_id]["key"]) {
        if (!(ob = present(key, this_player()))) {
            notify_fail("You do not have that!\n");
            return 0;
        }
        if (!ob->id(doors[ident][lock_id]["key"])) {
            notify_fail("You fail to lock the " + ident + " with the " + key + ".\n");
            return 0;
        }

        if (doors[ident]["lock string"]) {
            write(doors[ident]["lock string"]);
        }else {
            write("You lock the " + lock_id + " on the " + ident + " with the " + key + ".\n");
        }

        say(this_player()->query_cap_name() + " locks the " + ident + " with the " + key +
            ".\n", this_player());
    } else {
        if (doors[ident]["lock string"]) {
            write(doors[ident]["lock string"]);
        }else {
            write("You lock the " + lock_id + " on the " + ident + ".\n");
        }

        say(this_player()->query_cap_name() + " locks the " + ident + ".\n", this_player());
    }
    /*
       if(doors[ident]["lock fun"]) {
        if(!call_other(this_object(), doors[ident]["lock fun"])) return 1;
       }
     */
    if (objectp(find_object_or_load(doors[ident]["destination"]))) {
        doors[ident]["destination"]->set_locked(ident, 1, lock_id);
        if (userp(TP)) {
            doors[ident]["destination"]->set_had_players();
        }
        tell_room(doors[ident]["destination"],
                  "You hear some scratching noises coming from the other side of the " + ident + ".\n");
    }
    set_locked(ident, 1, lock_id);
    return 1;
}

int KnockDoor(string str)
{
    if (!doors) {
        return 0;
    }

    set_default_door_state(query_doors_map());

    if (!str) {
        notify_fail("Knock what?\n");
        return 0;
    }
    if (TP->query_bound()) {
        TP->send_paralyze_message("info", TP);
    }
    if (!doors[str]) {
        notify_fail("What " + str + "?\n");
        return 0;
    }
    if (doors[str]["open"]) {
        notify_fail("Why would you knock on the open " + str + "?\n");
        return 0;
    }
    if (!doors[str]["knock string"] || doors[str]["knock string"] == "") {
        write("You knock on the " + str + ".\n");
        say(TPQCN + " knocks on the " + str + ".\n", TP);
        if (objectp(find_object_or_load(doors[str]["destination"]))) {
            tell_room(doors[str]["destination"], "Someone from the other " +
                      "side knocks on the " + str + ".");
        }
    }else {
        write("You " + doors[str]["knock string"] + " on the " + str + ".");
        say(TPQCN + " " + doors[str]["knock string"] + "s on the " + str + ".", TP);
        if (objectp(find_object_or_load(doors[str]["destination"]))) {
            tell_room(find_object_or_load(doors[str]["destination"]), "Someone from the other " +
                      "side " + doors[str]["knock string"] + "s on the " + str + ".");
        }
    }
    return 1;
}

int GoThroughDoor()
{
    string verb, id;
    string* ind;
    int i;

    if (!doors) {
        return 1;
    }
    verb = query_verb();
    ind = keys(doors);
    for (i = 0; i < sizeof(ind); i++) {
        if (doors[ind[i]]["direction"] == verb) {
            id = ind[i];
        }
    }
    if (!doors[id]["open"]) {
        write("You bump into the closed " + id + ".\n");
        say(this_player()->query_cap_name() + " bumps into the closed " + id + ".\n");
        return 0;
    }
    if (doors[id]["pre exit"]) {
        if (!call_other(this_object(), doors[id]["pre exit"])) {
            return 0;
        }
    }
    return 1;
}

varargs void lock_difficulty(string str, int mod, string lock_id) //mod is your DC.  Keep in mind that the average PC with dungeoneering as a class skill will have Level * 2 + Wisdom Modifier + 1d20 to defeat your lock.
{
    if (!door_mod) {
        door_mod = ([]);
    }
    if (!doors) {
        return 0;
    }
    if (!doors[str]) {
        return 0;
    }
    if (!lock_id) {
        lock_id = "lock";
    }
    if (!doors[str][lock_id]) {
        return 0;
    }

    doors[str][lock_id]["mod"] = mod;
}

varargs int query_mod(string str, string lock_id)
{
    if (!doors) {
        return 0;
    }
    if (!doors[str]) {
        return 0;
    }
    if (!door_mod) {
        return 0;
    }
    if (!lock_id) {
        lock_id = "lock";
    }
    return doors[str][lock_id]["mod"];
}

string query_door(string dir)
{
    string* ind;
    int i;

    if (!doors) {
        return 0;
    }
    ind = keys(doors);
    for (i = 0; i < sizeof(ind); i++) {
        if (doors[ind[i]]["direction"] == dir) {
            return ind[i];
        }
    }
    return 0;
}

int remove_door(string id)
{
    if (!doors) {
        return 0;
    }
    if (!doors[id]) {
        return 0;
    }
    map_delete(doors, id);
    return 1;
}

int PickLock(string str)
{
    string ident, tool, lock_id;
    object ob, ob2;
    int difficulty, modifier, score, level;

    if (!doors) {
        return 0;
    }
    if (!str) {
        notify_fail("Pick what?\n");
        return 0;
    }
    if (sscanf(str, "%s on %s", lock_id, ident) != 2) {
        ident = str;
        lock_id = "lock";
    }
    if (!doors[ident]) {
        notify_fail("What " + ident + "?. ( pick <lock> on <door>\n");
        return 0;
    }
    if (!doors[ident][lock_id]) {
        notify_fail("It has no such lock.\n");
        return 0;
    }
    if (!doors[ident][lock_id]["key"]) {
        notify_fail("It has no lock.\n");
        return 0;
    }
    if (doors[ident]["open"]) {
        notify_fail("Unlock it? It is open!\n");
        return 0;
    }
    if (!doors[ident][lock_id]["locked"]) {
        notify_fail("It is already unlocked.\n");
        return 0;
    }
    if (!(ob = present("thief toolx", this_player()))) {
        notify_fail("You do not have the tools!\n");
        return 1;
    }
    if (ob = present("thief toolx", TP)) {
        if (ob->query_property("broken")) {
            write("You can't use those broken tools.\n");
            return 1;
        }
    }
    if (TO->is_trapped("pick " + ident + " " + lock_id)) {
        if (TO->execute_trap("pick " + ident + " " + lock_id, TP)) {
            return 1;
        }
    }

    /*if(trapped("pick") && query_trapped_state(ident, lock_id, "pick"))
       {
       if(do_spec_trap("pick",lock_id)) return 1;
       }*/
/*    if(!TP->is_class("thief") && !TP->is_class("assassin")) {
        notify_fail("You can't do that.\n");
        return 0;
    }*/

    score = TP->query_skill("dungeoneering") + roll_dice(1, 20); //adding in a roll 20 per TT
    modifier = query_mod(ident, lock_id); //this is the number given on the lock itself
    difficulty = abs(modifier); //Making the DC a positive number, just removing the 20 to avoid confusion and keep DCs all in one place
    if (score >= difficulty) {
        if (doors[ident]["unlock fun"]) {
            if (!call_other(this_object(), doors[ident]["unlock fun"])) {
                return 1;
            }
        }
        if (doors[ident]["unlock string"]) {
            write(doors[ident]["unlock string"]);
        }else {
            write("You unlock the " + lock_id + " on the " + ident + " with your thieves' tools.\n");
        }
        say(TPQCN + " picks the " + lock_id + " on the " + ident + " with the tools. \n", TP);
        if (objectp(find_object_or_load(doors[ident]["destination"]))) {
            doors[ident]["destination"]->set_locked(ident, 0, lock_id);
            tell_room(doors[ident]["destination"],
                      "You hear some scratching noises on the other side of the " + ident + ".\n");
        }
        set_locked(ident, 0, lock_id);
        return 1;
    }else {
        write("The lock doesn't seem to budge.\n");
        write("You worry about your tools.\n");
        tell_room(environment(TP), "You see " + TPQCN + " struggles to pick " + ident + ".", TP);
        if ((difficulty - score) > 10) {
            level = TP->query_level();
            score = random(99);
            if (score > (level + TP->query_stats("wisdom"))) {
                ob2 = present("tools", TP);
                tell_object(TP, "You break your tools!");
                ob2->break_picks();
                return 1;
            }
        }
        return 1;
    }
}

varargs string query_door_key(string ident, string lock_id)
{
    if (!lock_id) {
        lock_id = "lock";
    }
    return doors[ident][lock_id]["key"];
}

//recoded this function to cut down on
//some of the loops... were like 5 or 6 loops everytime someone
//typed "look" just in this function - Saide

string query_long_exits()
{
    int j;
    string id, tmp, ndstr, dstr, str;
    string* NonDoorExits = ({}), * DoorExits = ({});
    string* sorties;

    if (skip_obvious) {
        return "";
    }
    if (!sizeof(sorties = query_obvious_exits())) {
        return "There are no obvious exits.";
    }

    for (j = 0; j < sizeof(sorties); j++) {
        if (stringp(id = query_door(sorties[j]))) {
            if (query_invis_door(id)) {
                continue;
            }
            tmp = TO->get_trap_room_auto_detect(sorties[j], TP, 0);
            tmp += " (" + TO->get_trap_room_auto_detect(id, TP, 1);
            if (query_open(id)) {
                tmp += " open)";
            }else {
                tmp += " closed)";
            }
            DoorExits += ({ tmp });
            continue;
        }
        tmp = TO->get_trap_room_auto_detect(sorties[j], TP, 0);
        NonDoorExits += ({ tmp });
        continue;
    }

    j = sizeof(NonDoorExits);
    switch (j) {
    case 0:
        ndstr = "";
        break;

    case 1:
        ndstr = "The only obvious exit is: " + NonDoorExits[0] + ".\n";
        break;

    default:
        if (j >= sizeof(NUMBER)) {
            j = sizeof(NUMBER) - 1;
        }else {
            j = j - 2;
        }
        ndstr = "There are " + NUMBER[j] + " obvious exits: ";
        if (sizeof(NonDoorExits) == 2) {
            ndstr += implode(NonDoorExits, " and ");
            if (sizeof(DoorExits)) {
                ndstr += ".\n";
            }
            break;
        }
        if (sizeof(NonDoorExits) > 2) {
            ndstr += implode(NonDoorExits[0..(sizeof(NonDoorExits) - 2)], ", ");
            ndstr += ", and " + NonDoorExits[(sizeof(NonDoorExits) - 1)];
            if (sizeof(DoorExits)) {
                ndstr += ".\n";
            }
        }

        break;
    }

    j = sizeof(DoorExits);
    switch (j) {
    case 0:
        dstr = "";
        break;

    case 1:
        dstr = "The only obvious exit with a door is: " + DoorExits[0] + ".\n";
        break;

    default:
        if (j >= sizeof(NUMBER)) {
            j = sizeof(NUMBER) - 1;
        }else {
            j = j - 2;
        }
        dstr = "There are " + NUMBER[j] + " obvious exits with doors: ";
        if (sizeof(DoorExits) == 2) {
            dstr += implode(DoorExits, " and ");
            //dstr += ".\n";
            break;
        }
        if (sizeof(DoorExits) > 2) {
            dstr += implode(DoorExits[0..(sizeof(DoorExits) - 2)], ", ");
            dstr += ", and " + DoorExits[(sizeof(DoorExits) - 1)];
            break;
        }
        break;
    }
    str = "";
    if (ndstr != "") {
        str += ndstr;
    }
    if (dstr != "") {
        str += dstr;
    }

    return str;
}

string query_short_exits()
{
    int i, x, max;
    string s, id;
    string* lx, * sx;

    s = "";
    sx = allocate(max = sizeof(lx = query_obvious_exits()));
    for (x = 0; x < max; x++) {
        if ((i = member_array(lx[x], TMPLONG)) != -1) {
            sx[x] = TMPSHORT[i];
        }else {
            sx[x] = lx[x];
        }
    }
    if (!sizeof(sx)) {
        return "[no exits]";
    }
    if (max == 1) {
        id = query_door(lx[0]);
        if (id && !query_invis_door(id)) {
            if (query_open(id)) {
                return "[1: " + sx[0] + " (op)]";
            }else {
                return "[1: " + sx[0] + " (cl)]";
            }
        }else {
            return "[1: " + sx[0] + "]";
        }
    }
    s = ("[" + max + ": ");
    for (x = 0; x < max; x++) {
        if (x) {
            s += ", ";
        }
        id = query_door(lx[x]);
        if (id && !query_invis_door(id)) {
            if (query_open(id)) {
                s += sx[x] + " (op)";
            }else {
                s += sx[x] + " (cl)";
            }
        }else {
            s += sx[x];
        }
    }
    return s + "]";
}

mapping query_items()
{
    int i, j;
    string* drs;
    string newDesc;
    mapping* locks;
    mapping super = ::query_items();
    if (!doors) {
        return super;
    }
    drs = keys(doors);
    for (i = 0; i < sizeof(drs); i++) {
        newDesc = doors[drs[i]]["description"] + "\n";
        locks = getLocks(drs[i]);
        if (!sizeof(locks)) {
            newDesc += "There are no locks on this door.";
        } else {
            newDesc += "There " + ((sizeof(locks) == 1) ? "is" : "are") + " " + sizeof(locks) + " lock" + ((sizeof(locks) == 1) ? "" : "s") + " on this " + query_alt_doorname() + ".\n";
        }

        for (j = 0; j < sizeof(locks); j++) {
            newDesc += locks[j] + ": " + doors[drs[i]][locks[j]]["desc"] + "\n";
        }
        super[drs[i]] = newDesc;
    }

    return super;
}

void set_alt_doorname(string str)
{
    alt_doorname = str;
    if (!str) {
        str = "door";
    }
}

void query_alt_doorname()
{
    if (!alt_doorname) {
        return "door";
    }
    return alt_doorname;
}

//alt_doorname added by Circe 1/16/05 to help in making locked things
//in rooms that aren't doors (such as a locked drawer, etc) not look funny

// stuff added so we can sync doors on clean_up


void set_default_door_state(mixed map)
{
    if (!mapp(map)) {
        return;
    }

    if (!default_door_state || !sizeof(default_door_state)) {
        default_door_state = map;
    }
    return;
}

mixed query_default_door_state()
{
    if (sizeof(default_door_state)) {
        return default_door_state;
    }
    return 0;
}

void sync_outside_doors(mapping map)
{
    mapping door_map, lock_map;
    string* door_list, * locks;

    object other_room;

    int i, j, open;

    if (!mapp(map)) {
        return;
    }
    if (!sizeof(map)) {
        return;
    }

    door_list = keys(map);

    for (i = 0; i < sizeof(door_list); i++) {
        door_map = map[door_list[i]];

        // other room isn't loaded, it's alredy set to default
        if (!objectp(other_room = find_object(door_map["destination"]))) {
            continue;
        }
        other_room->set_open(door_list[i], door_map["open"]);
        locks = getLocks(door_list[i]);
        if (sizeof(locks)) {
            for (j = 0; j < sizeof(locks); j++) {
                lock_map = door_map[locks[j]];
                other_room->set_locked(door_list[i], lock_map["locked"], locks[j]);
            }
        }
    }

    return;
}

int clean_up()
{
    mapping state;

    if (!doors || !sizeof(doors)) {
        ::clean_up();
        return 1;
    }

    state = query_default_door_state();

    if (!state || !sizeof(state)) {
        ::clean_up();
        return 1;
    }

    sync_outside_doors(state);

    ::clean_up();
    return 1;
}

int get_phouse_lock_dc(string locklevel) //function to standardize lock levels across player houses, six levels available
{
    int lockdc, baselockdc;
    baselockdc = 25; //this is a poor quality lock
    lockdc = baselockdc; //probably redundant, but I'm paranoid
    if (!stringp(locklevel) || locklevel == "" || locklevel == " ") {
        locklevel = "average";
    }
    locklevel = lower_case(locklevel);
    switch (locklevel) {
    case "poor":
        lockdc += 0;
        break;

    case "common":
        lockdc += 10;
        break;

    case "good":
        lockdc += 20;
        break;

    case "rare":
        lockdc += 30;
        break;

    case "epic":
        lockdc += 40;
        break;

    case "legendary":
        lockdc += 50;
        break;

    default:
        lockdc += 0;
        break;
    }
    return lockdc;
}
