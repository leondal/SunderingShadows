/*
  A daemon to clean up unused objects on a more regular basis than the
  driver level clean_up calls.  It cleans fewer objects at a time to
  avoid large lag spikes that are noticable to the player.
  BLOCK_SIZE determins how many objects are checked at one time to
  see if they are eligible for clean up.  These objects
  pass through clean_filter and if they meet the requirements
  they are then set to a call_out which calls their
  clean_up function.
  TIME_DELAY this is the duration of the call_out between calls to
  clean_up.
  created by -Ares 01/21/2010
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define BLOCK_SIZE 500  // how many objects it will check at one time
#define TIME_DELAY 20   // delay between checking if objects can be cleaned

int test_counter, cleaning;
nosave object debug_object;

void create()
{
    begin_cleaning();
    ::create();
}

int clean_filter(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    if (strsrch(base_name(obj), "/daemon") == 0) {
        return 0;
    }

    if (strsrch(base_name(obj), "/adm/daemon") == 0) {
        return 0;
    }

    if (strsrch(base_name(obj), "/d/magic") == 0) {
        return 0;
    }

    if (obj->query_noclean()) {
        return 0;
    }

    if ((clonep(obj) && !objectp(environment(obj))) && !obj->query_had_players()) {
        return 1;
    }

    if (!objectp(environment(obj)) && obj->is_monster()) {
        return 1;
    }

    if (obj->is_spell()) {
        return 1;
    }

    if (obj->is_feat()) {
        return 1;
    }

    if (!obj->is_room()) {
        return 0;
    }

    if (obj->query_had_players()) {
        return 0;
    }
    return 1;
}

// tells the program to start cleaning
void begin_cleaning()
{
    if (!cleaning) {
        object* objs;
        objs = objects();
        block_objects(objs);
        cleaning = 1;
    }
}

// breaks the huge object array of all objects on the mud down into little chunks set by BLOCK_SIZE
void block_objects(object* objs)
{
    object* obj_blocks = ({}), * tmp = ({});
    int blocks, remainder, i, j;

    if (!pointerp(objs) || !sizeof(objs)) {
        begin_cleaning();
    }


    blocks = sizeof(objs) / BLOCK_SIZE;
    remainder = sizeof(objs) % BLOCK_SIZE;

    // assigns the objects into arrays with BLOCK_SIZE objects each
    j = 0;
    for (i = 0; i < blocks; i++) {
        tmp = objs[j..(j + (BLOCK_SIZE - 1))];
        obj_blocks += ({ tmp });
        j += BLOCK_SIZE;
    }

    if (remainder) {
        if (!blocks) {
            tmp = objs[0..remainder];
        }else {
            tmp = objs[(BLOCK_SIZE * (blocks - 1))..(((BLOCK_SIZE * (blocks - 1)) + remainder) - 1)];
        }
        obj_blocks += ({ tmp });
    }

    debug_message("sizeof obj_blocks" + sizeof(obj_blocks) + "");
    for (i = 0; i < sizeof(obj_blocks); i++) {
        debug_message("sizeof obj_blocks[" + i + "]: " + sizeof(obj_blocks[i]) + "");
    }

    slow_clean(obj_blocks, 0);
    return;
}

// runs a callout on each block of objects until it's stepped through every block then it begins again
void slow_clean(object* objs, int step)
{
    object* block;
    int i;

    if (!pointerp(objs) || !sizeof(objs)) {
        return;
    }

    if (step == sizeof(objs)) {
        debug_message("Finished one cleaning series.");
        debug_message("Total objects cleaned: " + test_counter + "");
        cleaning = 0;
        begin_cleaning();
        return;
    }

    if (catch(objs[step])) {
        debug_message("invalid index.");
        return;
    }

    block = objs[step];

    block = filter_array(block, "clean_filter", TO);

    call_out("clean_block", TIME_DELAY, objs, block, step);
    return;
}

// makes the actual calls to clean_up
void clean_block(object* objs, object* block, int step)
{
    mixed error;
    int i;

    step++;

    if (!sizeof(block)) {
        debug_message("No objects to clean in block " + step + "");
        slow_clean(objs, step);
        return;
    }

    debug_message(" Cleaning block " + step + "");
    debug_message(" Block size is: " + sizeof(block) + "");
    for (i = 0; i < sizeof(block); i++) {
        if (!objectp(block[i])) {
            continue;
        }
        error = catch(block[i]->clean_up());
        if (error) {
            debug_message("Error in clean up: " + error + "");
        }
        test_counter++;
    }
    debug_message(" Total objects cleaned: " + test_counter + "");
    debug_message(" Total memory usage: " + memory_info() + "");

    slow_clean(objs, step);
    return;
}

void set_debug_object(object obj)
{
    if (!objectp(obj)) {
        debug_object = 0;
        return;
    }
    debug_object = obj;
}

void debug_message(string str)
{
    if (!objectp(debug_object)) {
        return;
    }
    tell_object(debug_object, str);
    return;
}

int clean_up()
{
    return 1;
}
