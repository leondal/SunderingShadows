#include <security.h>

/**
 * @file
 */

/**
 * Finds object by file descriptor and loads it if no object had been found
 *
 * @param str File descriptor of an object
 * @return Object's descriptor.
 */
object find_object_or_load(mixed str)
{
    object ob;
    string err;

    if (objectp(str)) {
        if (!str->is_room()) {
            return str;
        }
        if (!str->query_reset_number()) {
            str->reset();
        }
        if (!str->is_control_room()) {
            return str;
        }
        if ((int)str->query_reset_number() != (int)str->query_property("lastresetmobs")) {
            str->place_mobs();
        }
        return str;
    }
    ob = find_object(str);
    if (ob != 0) {
        if (!objectp(ob)) {
            return ob;
        }
        if (!ob->is_room()) {
            return ob;
        }
        if (!ob->query_reset_number()) {
            ob->reset();
        }
        if (!ob->is_control_room()) {
            return ob;
        }
        if ((int)ob->query_reset_number() != (int)ob->query_property("lastresetmobs")) {
            ob->place_mobs();
        }
        if (clonep(ob)) {
            return ob;
        }
        return ob;
    }
    seteuid(UID_ROOT);
    if (!file_exists(str)) {
        err = catch(call_other(str, "???"));
    }else if (!file_exists(str + ".c")) {
        err = catch(call_other(str, "???"));
    }else {
        call_other(str, "???");
    }
    if (err) {
        log_file("debug.log", "**ERROR: " + err + " -- when trying find_object_or_load(\"" + str + "\"");
    }

    ob = find_object(str);
    if (!objectp(ob)) {
        return ob;
    }
    if (!ob->is_room()) {
        return ob;
    }
    ob->reset();
    if (clonep(ob)) {
        return ob;
    }
    if (!ob->is_control_room()) {
        return ob;
    }
    ob->place_mobs();
    return ob;
}
