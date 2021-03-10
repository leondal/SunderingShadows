#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_FILE "/daemon/save/grafitti"

mapping __SaveMappings;

void save_data();

void create()
{
    ::create();
    __SaveMappings = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
    clear_data();
    save_data();
}

int has_saved_grafitti(string room_name)
{
    if (member_array(room_name, keys(__SaveMappings)) != -1) {
        return 1;
    }else {
        return 0;
    }
}

void save_grafitti(string room_name, mapping grafittimap)
{
    __SaveMappings[room_name] = grafittimap;
    save_data();
}

void nosave_grafitti(string room_name)
{
    map_delete(__SaveMappings, room_name);
    save_data();
}

void clear_grafitti(string room_name)
{
    map_delete(__SaveMappings, room_name);
    save_data();
}

void update_grafitti(string room_name, string name, string value)
{
    if (has_saved_grafitti(room_name)) {
        __SaveMappings[room_name][name] = value;
        save_data();
    }
}

mapping load_grafitti(string map_name)
{
    if (has_saved_grafitti(map_name)) {
        return __SaveMappings[map_name];
    }else {
        return 0;
    }
}

void remove_value_from_array(string map_name, string value)
{
    mapping map;
    string name;
    int index;
    if (has_saved_grafitti(map_name)) {
        index = member_array(value, values(__SaveMappings[map_name]));
        if (index == -1) {
            return;
        }
        name = keys(__SaveMappings[map_name])[index];
        map = __SaveMappings[map_name];
        map_delete(map, name);
        __SaveMappings[map_name] = map;
        save_data();
    }
}

void remove_grafitti(string map_name, string name)
{
    mapping map;
    if (has_saved_grafitti(map_name)) {
        map = __SaveMappings[map_name];
        map_delete(map, name);
        __SaveMappings[map_name] = map;
        save_data();
    }
}

void remove_name(string name)
{
    string* map_names;
    mapping map;
    int i;

    map_names = keys(__SaveMappings);

    for (i = 0; i < sizeof(map_names); i++) {
        map = __SaveMappings[map_names[i]];
        map_delete(map, name);
        __SaveMappings[map_names[i]] = map;
    }
    save_data();
}

void remove_mapping(string nme)
{
    map_delete(__SaveMappings, nme);
    save_data();
}

void clear_data()
{
    string room_file;

    foreach(room_file in keys(__SaveMappings)) {
        if (!(file_exists(room_file + ".c"))) {
            map_delete(__SaveMappings, room_file);
            continue;
        }
        if (!sizeof(__SaveMappings[room_file])) {
            map_delete(__SaveMappings, room_file);
            continue;
        }
        if (!mapp(__SaveMappings[room_file])) {
            map_delete(__SaveMappings, room_file);
            continue;
        }
    }
}

void save_data()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

int is_member(string map_name, string name)
{
    if (!__SaveMappings) {
        __SaveMappings = ([]);
    }
    if (!__SaveMappings[map_name]) {
        __SaveMappings[map_name] = ([]);
    }

    return member_array(name, keys(__SaveMappings[map_name]));
}

int fileset_grafitti(mixed parse)
{
    object where;
    string file;
    string editable;
    string load_file;
    mixed test;

    test = ETP;
    if (objectp(test)) {
        where = test;
    }else {
        return 0;
    }

    test = TP->query_edit_filename();
    if (stringp(test)) {
        file = test;
    }else {
        return 0;
    }

    if (!stringp(parse)) {
        return 0;
    }
    editable = parse;
    test = read_file(file);
    if (stringp(test)) {
        load_file = test;
    }else {
        return 0;
    }

    where->set_grafitti(editable, load_file);
    rm(file);
    return 1;
}
