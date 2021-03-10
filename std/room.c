//      /std/room.c
//      from the Nightmare Mudlib
//      the room object
//      written by Descartes of Borg 17 june 1993
//      ::create() added by Pallando (93-06-18)
//      ::create() changed to container::create() with calls to
//      items::create(), exits::create(), and senses::create() added
//      by Descartes 930619
//      this_object()->setup(); removed from reset() by Pallando (93-06-20)
//      seteuid(getuid()) removed from create() by Pallando (93-06-23)
//      query_long() changed not to give error if none set by Pallando
//      Let's talk traps..........Tristan

#include <std.h>
#include <rooms.h>
#include <move.h>
#include <daemons.h>

inherit "/std/container.c";
inherit "/std/room/exits.c";
inherit "/std/battle.c";
inherit "/std/room/items";
inherit "/std/room/senses";


private int reset_number;
int already_encountered, only_on_reset, flag;
string sneakf, peer_message, mcharge_message, charge_message;
nosave int storage, storing, had_players;
nosave int test_grafitti_loaded; // This will be 1 if the grafitti has been loaded for the room from the daemon.
nosave object* dependencies = ({ });
nosave string climate;
mapping coords = ([]);
string* roomfuncs, * roomverbs;

string getSaveFileName()
{
    string fn = base_name(TO);
    return fn;
}

void restoreContents()
{
    int i;
    string * files;
    mixed ob;
    files = get_dir(getSaveFileName() + "/ob*.o");
    for (i = 0; i < sizeof(files); i++) {
        ob = "/daemon/yuck_d"->restore_files(getSaveFileName() + "/" + files[i]);
        if (objectp(ob)) {
            storing = 1;
            ob->move(TO);
            storing = 0;
        }
        if (stringp(ob)) {
            write(ob);
        }
    }
    //do nothing for now.
}

string get_name()
{
    string file_name, path, room_name;
    file_name = base_name(TO);
    path = get_path();
    room_name = file_name[strlen(path)..strlen(file_name) - 1];
    return room_name;
}

string get_path()
{
    string f_name, junk, result;
    f_name = file_name(TO);

    result = "";
    while (interact("/", f_name)) {
        sscanf(f_name, "%s/%s", junk, f_name);
        if (!interact("/", junk)) {
            result += "/";
        }
        result += junk;
    }
    result = result[1..strlen(result) - 1];
    result += "/";
    return result;
}

void create()
{
    container::create();
    exits::create();
    battle::create();
    items::create();
    senses::create();
    reset_number = 0;
    only_on_reset = 1;
    if (!random(4)) {
        set_property("used sticks", 1);
    }
    return;
}

void restore_room()
{
    if (file_exists(getSaveFileName() + ".o")) {
        restore_object(getSaveFileName());
        if (file_size(getSaveFileName()) == -2) {
            restoreContents();
        }
    }
}

void save_room_shallow()
{
    seteuid("Restore");
    save_object(getSaveFileName());
}

void save_room_deep()
{
    object* inven;
    int i;
    string* files;

    if (storing) {
        return;
    }
    save_room_shallow();

    if (file_size(getSaveFileName()) != -2) {
        mkdir(getSaveFileName());
    }else {
        files = get_dir(getSaveFileName() + "/*.o");
        for (i = 0; i < sizeof(files); i++) {
            rm(getSaveFileName() + "/" + files[i]);
            //
        }
        seteuid(getuid());
    }

    inven = all_inventory(TO);
    inven -= all_living(TO);

    for (i = 0; i < sizeof(inven); i++) {
        if (userp(inven[i])) {
            continue;
        }
        if (living(inven[i])) {
            continue;
        }
        if (inven[i]->id("phantom")) {
            continue;
        }
        inven[i]->save_me(getSaveFileName() + "/ob" + i);
    }
}

void loose_item(object ob)
{
    if (!living(ob) && storage) {
        save_room_deep();
    }
}

void gain_item(object ob)
{
    if (!living(ob) && storage) {
        save_room_deep();
    }
}

void set_storage(int i)
{
    if (TO->query("alternative world")) {
        return;                                //to prevent alternative "versions" of rooms from saving - hopefully none of the rooms that set_storage() are alternative
    }
    storage = i;
}

int query_storage()
{
    return storage;
}

int is_room()
{
    return 1;
}

void set_enter_room(string str)
{
    return;
}

void set_climate(string str)
{
    climate = str;
    WEATHER_D->set_climate(str, TO);
}

string query_climate()
{
    return climate;
}

string get_climate()
{
    return climate;
}

void reset()
{
    object* ppl, persn;
    //making it so anything that requires TO to be valid occurs later in the code
    //and only is TO is a valid object - Saide
    //if(!objectp(TO)) { return; }

    container::reset();
    reset_number++;
    already_encountered = 0;
    flag = 0;
    only_on_reset = 1;

    if (objectp(TO)) {
        ppl = all_living(TO);
        if (sizeof(ppl)) {
            ppl = filter_array(ppl, "is_player_or_minion", FILTERS_D);
        }

        if (!sizeof(ppl)) {
            if (had_players > 0) {
                had_players--;
            }
        }else {
            had_players = 3;
            foreach(persn in ppl)
            {
                catch(RUMOURS_D->check_for_rumour(persn));
            }
        }
        catch("/daemon/quests"->isRoom(TO));
        "/daemon/room_d"->inhere(base_name(TO));
        "/daemon/room_d"->inhere(base_name(TO) + ".c");
        "/daemon/monster_d"->check_for_place(base_name(TO));
        "/daemon/monster_d"->check_for_place(base_name(TO) + ".c");
    }

    //Adding this to remove the study attempts -
    //hopefully on about half the resets -
    //that happen on a room or item in the room - Saide
    if (!random(2)) {
        remove_property("successful study");
        remove_property("failed study");
    }

    //reactive_traps && check_random_traps are in trap_data.c
    reactivate_traps();
    check_random_traps();
    //TO->reset_traps();
}

void init()
{
    container::init();
    exits::initiate();
    senses::initiate();
    ALT_WORLD_D->in_alt_world(TP, TO);
    roomfuncs = ({});
    roomverbs = ({});
}

void set_random_frequency(int x)
{
    only_on_reset = x;
}

int query_random_frequency()
{
    return only_on_reset;
}

void do_random_encounters(string* monsters, int percentile, int num_mons)
{
    int actual_num, x, check, number, invis;
    string mob, * temp, * hold, id;
    object me, * obj, mon;

    if ((already_encountered) && (!only_on_reset)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(previous_object())) {
        return;
    }
    me = previous_object();

    // Code added by Melnmarn. To test for existing monsters, and
    // return if they are still there. Otherwise the monsters would
    // pile up to huge amounts. :)
    // Also added the top code to test for other players, before adding
    // new monsters. Will return if someone else is in the room, and not
    // add any monsters.
    // --------------------------------------------------
    //   Check for other interactive players   //

    number = 0;
    obj = all_inventory(TO);
    number = sizeof(obj);

    while (number--) {
        if (interactive(obj[number]) && obj[number] != me) {
            return;
        }
    }

    //   Check for other monsters in the room.     //

    hold = monsters;
    check = sizeof(hold);
    while (check--) {
        if (find_object_or_load(hold[check])) {
            temp = find_object_or_load(hold[check])->query_id();
            if (pointerp(temp) && sizeof(temp)) {
                if (present(temp[0])) {
                    return;                  // is there monsters here already?
                }
            }
        }
    }

    //
    // --------------------------------------------------
    //

    if (!interactive(me)) {
        return;
    }

    //okie, lets add some mobs
    if (random(100) < percentile) {
        actual_num = random(num_mons) + 1;
        for (x = 0; x < actual_num; x++) {
            mob = monsters[random(sizeof(monsters))];
            mon = new(mob);
            mon->set("agressive", 20);
            //            TREASURE->get_random_treasure(mon);
            mon->move(environment(me));
            if (!mon->query_invis()) {
                invis = 1;
            }
        }

        only_on_reset--;

        if (actual_num > 0) {
            already_encountered = 1;
        }
    }
}

int query_only_on_reset()
{
    return only_on_reset;
}

int query_already_encountered()
{
    return already_encountered;
}

void set_short(string str)
{
    container::set_short(str);
}

void set_long(string str)
{
    container::set_long(str);
}

void set_light(int d)
{
    set_property("light", d);
}

void set_indoors(int d)
{
    set_property("indoors", d);
}

void set_no_castle(int d)
{
    set_property("no_caste", d);
}

void set_no_steal(int d)
{
    set_property("no_steal", d);
}

int has_grafitti(string which)
{
    mapping graphmap;
    if (!D_BUG_D->grafitti()) {
        return 0;
    }

    if (!test_grafitti_loaded) {
        // load grafitti from graf_d or whatever.
        graphmap = (mapping)GRAFITTI_D->load_grafitti(base_name(TO));
        if (graphmap != ([])) {
            set_property("_grafitti", graphmap);
        }else {
            graphmap = 0;
        }
        test_grafitti_loaded = 1;
    }

    if (query("_nograph") || (!mapp(graphmap = query_property("_grafitti")))) {
        return 0;
    }else {
        if (stringp(graphmap[which])) {
            return 1;
        }else {
            return 0;
        }
    }
}

int save_grafitti()
{
    return GRAFITTI_D->save_grafitti(base_name(TO), (mapping)query_property("_grafitti"));
}

int nosave_grafitti()
{
    return GRAFITTI_D->nosave_grafitti(base_name(TO));
}

int set_grafitti(string which, string to_what)
{
    GRAFITTI_D->update_grafitti(base_name(TO), which, to_what);
    return set_property("_grafitti", ([which: to_what]));
}

int clean_grafitti()
{
    GRAFITTI_D->clear_grafitti(base_name(TO));
    return remove_property("_grafitti");
}

int remove_grafitti(string which)
{
    mapping graphmap;

    if (has_grafitti(which)) {
        graphmap = query_property("_grafitti");
        map_delete(graphmap, which);
        remove_property("_grafitti");
        set_property("_grafitti", graphmap);
        GRAFITTI_D->remove_grafitti(base_name(TO), which);
    }
    return 1;
}

string query_grafitti(string which)
{
    mapping graphmap;

    if (!has_grafitti(which)) {
        return "";
    }else {
        graphmap = query_property("_grafitti");
        return graphmap[which];
    }
}

string query_short()
{
    if (has_grafitti("short")) {
        return query_grafitti("short");
    }
    return container::query_short();
}

string query_long(string str)
{
    string ret;
    object ob;

    if (str) {
        return describe(str);
    }else {
        //    if(query_night() && query("night long")) {
        if (query_night() && (query("night long") || has_grafitti("night long"))) {
            if (has_grafitti("night long")) {
                ret = query_grafitti("night long");
            }else {
                if (functionp(query("night long"))) {
                    ret = call_other(TO, (string)(*query("night long"))(0), (str));
                }else {
                    ret = query("night long");
                }
            }
        }
        //    else if(!query_night() && query("day long")) {
        else if (!query_night() && (query("day long") || has_grafitti("day long"))) {
            if (has_grafitti("day long")) {
                ret = query_grafitti("day long");
            }else {
                ret = query("day long");
            }
        }else {
            if (has_grafitti("long")) {
                ret = query_grafitti("long");
            }else {
                ret = container::query_long();
            }
        }
    }

    if (!ret) {
        ret = "";
    }
    if (query_extra_long() != "") {
        ret += query_extra_long();
    }
    if (query_buried_long_addition() != "") {
        ret += query_buried_long_addition();
    }
    return ret;
}

string query_extra_long()
{
    object* inv;
    string ret, tmp;
    int i;

    ret = "";
    i = sizeof(inv = all_inventory(this_object()));
    while (i--) {
        if (tmp = (string)inv[i]->affect_environment()) {
            ret += tmp;
        }
    }
    return ret;
}

void reinitiate()
{
    all_inventory(TO)->move(TO);
    TO->check_random_traps();
}

int query_reset_number()
{
    return reset_number;
}

string* query_id()
{
    return items::query_id();
}

int id(string str)
{
    return items::id(str);
}

void set_sneak_func(mixed val)
{
    if (functionp(val) && geteuid(this_object()) != geteuid(val[0])) {
        return 0;
    }
    if (functionp(val)) {
        set_property("funcsneak", 1);
        sneakf = val[1];
    }else {
        sneakf = val;
    }
}

int do_sneak_func()
{
    if (!objectp(TO)) {
        return 0;
    }
    if (!stringp(sneakf)) {
        return 0;
    }
    if (!query_property("funcsneak")) {
        return 0;
    }
    return call_other(TO, sneakf);
}

int __Read(string str)
{
    if (!items::__Read(str)) {
        return container::__Read(str);
    }
    return 1;
}

void set_peer_message(string str)
{
    peer_message = str;
}

string query_peer_message()
{
    return peer_message;
}

void set_mcharge_message(string str)
{
    mcharge_message = str;
}

string query_mcharge_message()
{
    return mcharge_message;
}

void set_charge_message(string str)
{
    charge_message = str;
}

string query_charge_message()
{
    return charge_message;
}

int add_room_dependency(object ob)
{
    if (objectp(ob)) {
        dependencies += ob;
        return 1;
    }else {
        return 0;
    }
}

object* query_room_dependency()
{
    return dependencies;
}

int set_room_dependencies(object* obs)
{
    dependencies = copy(obs);
}

varargs void set_had_players(int num)
{
    if (!intp(num) || !num) {
        had_players = 3;
    }else {
        had_players = num;
    }
}

int query_had_players()
{
    return had_players;
}

void set_coords(int x, int y, int z)
{
    coords["x"] = x;
    coords["y"] = y;
    coords["z"] = z;
}

mapping query_coords()
{
    return coords;
}

// takes an array of room objects or file names and will make the cleaning daemon wait to clean them
void keep_rooms(mixed* rooms)
{
    object obj;
    int i;

    if (!pointerp(rooms) || !sizeof(rooms)) {
        return;
    }

    for (i = 0; i < sizeof(rooms); i++) {
        if (!objectp(obj = find_object_or_load(rooms[i]))) {
            continue;
        }
        obj->set_had_players(3);
    }
    return;
}

int add_action(string thisfunc, string thisaction)
{
    roomfuncs += ({ thisfunc });
    roomverbs += ({ thisaction });
    return efun::add_action(thisfunc, thisaction);
}

string* query_actions()
{
    return (roomverbs);
}
