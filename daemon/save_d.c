#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_FILE "/daemon/save/arrays"

mapping __SaveArrays;

/**
 * Avoid use of this daemon. It was used to store names for various
 * quest info. If you need to store something, store it in object you
 * need it to be stored in as this daemon loads ALL stored arrays.
 */

void save_data();

void create()
{
    ::create();
    __SaveArrays = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
}

void set_value(string array, string name)
{
    if (pointerp(array) || pointerp(name)) {
        return;
    }
    if (!__SaveArrays) {
        __SaveArrays = ([]);
    }
    if (!__SaveArrays[array]) {
        __SaveArrays[array] = ({});
    }

    __SaveArrays[array] += ({ name });
    save_data();
}

string* query_array(string array)
{
    if (!__SaveArrays) {
        __SaveArrays = ([]);
    }
    if (!__SaveArrays[array]) {
        __SaveArrays[array] = ({});
    }

    return __SaveArrays[array];
}

void remove_name_from_array(string array, string name)
{
    if (!__SaveArrays) {
        __SaveArrays = ([]);
    }
    if (!__SaveArrays[array]) {
        __SaveArrays[array] = ({});
    }

    __SaveArrays[array] -= ({ name });
    save_data();
}

void remove_name(string name)
{
    string* arrays;
    int i;

    arrays = keys(__SaveArrays);

    for (i = 0; i < sizeof(arrays); i++) {
        __SaveArrays[arrays[i]] -= ({ name });
    }

    save_data();
}

void remove_array(string nme)
{
    map_delete(__SaveArrays, nme);
    save_data();
}

void save_data()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

int is_member(string array, string name)
{
    if (!__SaveArrays) {
        __SaveArrays = ([]);
    }
    if (!__SaveArrays[array]) {
        __SaveArrays[array] = ({});
    }

    return member_array(name, __SaveArrays[array]);
}

string* show_list_arrays()
{
    string* str;
    str = keys(__SaveArrays);
    return str;
}
