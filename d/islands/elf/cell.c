#include <std.h>
#include "elf.h"
#define JAILMAIN "/d/islands/elf/guard1"
#define MAXTIME 600
#define MAXWANTED 200


#include <daemons.h>

inherit "/std/jail_cell.c";

void create()
{
    ::create();

    set_jail(JAILMAIN);
    set_jail_location("Ashta'Rathai");
    set_release_to("/d/islands/elf/gate");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A cage");
    set_short("A bronze cage");
    set_long("%^YELLOW%^A Bronze Cage%^RESET%^
   %^ORANGE%^This is a circular large metal" +
             " cage that is hanging from a tree.  It is about six" +
             " feet in diameter.  The cage appears to be made " +
             "from %^YELLOW%^bronze%^RESET%^%^ORANGE%^ and has closely cropped bars all " +
             "around.  A fog surrounds the place and a %^CYAN%^chill" +
             " wind%^ORANGE%^ blows. The floor looks to have a grate " +
             "in the bottom so the guards can lower the cage " +
             "and dump the person when then are done with them%^RESET%^.\n");
    set_listen("default", "You can hear a chill wind blow.");
    set_smell("default", "It smells of plants and water.");
    set_items(([
                   "grate" : "Perhaps you can peer through the grate to see who is in "
                   "the main jail.",

               ]));
    set_exits(([
                   "down" : JAILMAIN,
                   "grate" : JAILMAIN,

               ]));
    set_invis_exits(({ "window", "grate" }));
    set_pre_exit_functions(({ "window", "grate" }), ({
        "GoThroughDoor", "GoThroughDoor"
    }));
    set_door("cage door", JAILMAIN, "down", "Ashta'Rathai jail key");
    set_open("cage door", 0);
    set_locked("cage door", 1);
    lock_difficulty("cage door", -90);
    set_door_description("cage door", "This is a brass grate with a lock on it.  " +
                         "It is placed at the bottom of the cage.");
    set_string("cage door", "open", "The cell door creaks slightly as it "
               "swings open.");
    set_string("cage door", "close", "An ominous thud echoes off the walls "
               "as the heavy cell door shuts solidly.");
    set_trap_functions(({ "cage door" }), ({ "bind_me" }), ({ "pick" }));
}

void init()
{
    ::init();
    add_action("peer_out", "peer");
}

void do_messages()
{
    switch (random(24)) {
    case 1..3: break;

    case 4: tell_room(TO, "%^MAGENTA%^You swear you just heard voices "
                      "coming from behind you!  When you look, nobody is there.  Maybe it "
                      "was just insanity sinking in.");  break;

    case 5: tell_room(TO, "%^GREEN%^A very %^RED%^LOUD THUD %^GREEN%^"
                      "against the cage startles you!\n\n"
                      "After a few moments things seem quiet again.");     break;

    case 6: tell_room(TO, "%^CYAN%^Really, you're quite lucky" +
                      " to be here. How many people get to see the world" +
                      " from way up here?");   break;

    case 7:  tell_room(TO, "%^CYAN%^The chill from the fog "
                       "begins to drain your strength and will.");          break;

    case 8: tell_room(TO, "%^CYAN%^As the gentle sounds of nature" +
                      " drift to your ears, you begin to wonder " +
                      "where it all went wrong\n");                                   break;

    case 9: tell_room(TO, "%^ORANGE%^You hear footsteps below but it's "
                      "probably just the guard.\n");                       break;

    case 10: tell_room(TO, "%^ORANGE%^You hear yelling somewhere outside."
                       "  Might someone hear you if you yelled back?\n");   break;

    case 11: tell_room(TO, "%^CYAN%^You hear bird chirping loudly.  "
                       "Geez that is %^RED%^annoying!!\n");                       break;

    case 12: tell_room(TO, "%^GREEN%^That moss on the bars draws "
                       "your attention.  Is it moving or are you beginning to "
                       "lose your sanity?\n");                             break;

    case 13: tell_room(TO, "%^CYAN%^The realms are so pretty. How did" +
                       " you get your life so wrong as to end up in a cage\n");
        break;

    case 14: tell_room(TO, "%^RED%^One of the links in the " +
                       "chain holding your chain seems weak.  " +
                       "You wonder what splatting on the ground will feel like\n");
        break;

    case 15: tell_room(TO, "%^ORANGE%^A guard lowers the cage and peers" +
                       " in through the " +
                       "grate and seems to be checking his list.\n");      break;

    case 16: tell_room(TO, "%^CYAN%^Droplets of ice cold water "
                       "of drip from the top of the cage.\n");           break;

    case 17: tell_room(TO, "%^BLUE%^You swear you just heard voices "
                       "coming from behind you! When you look, nobody is there.\n"); break;

    case 18: tell_room(TO, "%^YELLOW%^A feathery pillow and a nice "
                       "soft blanket would be nice right about "
                       "now, wouldn't they?\n");                            break;

    case 19: tell_room(TO, "%^YELLOW%^The faint scent of warm, delicious-"
                       "smelling food wafts through the air as the jailer sits down to "
                       "enjoy a meal someone brought in.\n");                       break;

    case 20: tell_room(TO, "%^ORANGE%^You hear the jailer talking with "
                       "someone outside, and then a door shuts.\n");           break;

    case 21: tell_room(TO, "%^RED%^One of the links in the chain " +
                       "holding your cage seems weak. You wonder what splatting " +
                       "on the ground will feel like.\n");
        break;

    case 22: tell_room(TO, "%^CYAN%^You hear some singing and drunken laughter "
                       "from somewhere outside.  You can almost remember what it felt "
                       "like to be... free.\n");        break;

    default:  break;
    }
    return;
}

void reset()
{
    ::reset();
    do_messages();
    __CheckRelease();

    if (!trapped("cage door")) {
        toggle_trap("cage door");
    }
    if (query_open("cage door") && sizeof(all_living(TO)) < 1) {
        set_open("cage door", 0);
        set_locked("cage door", 1);
    }

    if (!present("jail food")) {
        new("/d/common/obj/misc/jailfood/j_food_poor.c")->move(this_object());
    }
}

int GoThroughDoor()
{
    if (query_verb() == "grate") {
        write("You wish... but you won't fit through there!");
        tell_room(ETP, TPQCN +
                  " seems to be trying to get out through the grate!", TP);
        return 0;
    }
//need to allow normal GoThroughDoor for the regular door exits
    return ::GoThroughDoor();
}

int bind_me(string str)
{
    object ob;
    if (interactive(TP)) {
        toggle_trap("cage door");
        tell_object(TP, "As you attempt to pick the lock you hear an "
                    "ominous click and suffer a paralyzing shock!");
        tell_room(ETP, TPQCN + " bends down to work at the lock but shudders "
                  "and freezes when a click sounds from it!", TP);
        TP->set_paralyzed(50, "Your muscles are frozen from the shock!");
        tell_object(TP,
                    "A guard rushes in and binds you, then takes your tools!");
        tell_room(ETP, "A guard rushes in and binds " + TPQCN + ", then takes "
                  + TP->query_possessive() + " tools.", TP);
        TP->set_bound(500);
        ob = present("thief tools", TP);
        if (objectp(ob)) {
            ob->remove();
        }
        return 1;
    }
}

int peer_out(string str)
{
    if (!str) {
        tell_object(TP, "Peer where?");
        return 1;
    }
    if (str == "grate" || str == "through grate") {
        tell_object(TP,
                    "You step up to the door and peer out into the jail.\n");
        tell_room(ETP, TPQCN + " steps up to the cell door and peers out.\n", TP);
        tell_room(JAILMAIN, "You hear a scratching "
                  "at the door and a glimpse of movement through the grate.\n", TP);
        TP->force_me("peer grate 1");
        return 1;
    }
    return 0;
}

//overwriting this to send bad crims to exicution
void __CheckRelease()
{
    int i, j, jailed, jailtime;
    string name, * wantedlist;
    object* inven;
    inven = all_living(TO);
    j = sizeof(inven);
    for (i = 0; i < j; i++) {
        if (!userp(inven[i])) {
            continue;
        }
        if (!jailed = inven[i]->query("jailed_age")) {
            continue;
        }
        jailtime = (int)inven[i]->query_age() - jailed;
        name = inven[i]->query_name();
        if (AREALISTS_D->is_wanted(inven[i], JailLoc, TO)
            && jailtime < MAXWANTED) {
            continue;
        }
        if (jailtime < MAXTIME) {
            continue;
        }
// if gets past all that, then release them
//but check if they need to die first
        if (AREALISTS_D->query_bounty_amount(inven[i]->query_name(), "Ashta'Rathai", TO) > 0) {
            inven[i]->move(ROOMS "death");
            AREALISTS_D->remove_prisoner(inven[i], JailLoc, TO);
            AREALISTS_D->remove_wanted(inven[i], JailLoc, TO);
            "/cmds/avatar/_note.c"->cmd_note("ckpt " + inven[i]->query_name() +
                                             " was TIME beheaded from the " + JailLoc + " jail.");
            continue;
        }else {
            "/cmds/avatar/_note.c"->cmd_note("ckpt " + inven[i]->query_name() +
                                             " was TIME released from the " + JailLoc + " jail.");

            AREALISTS_D->remove_prisoner(inven[i], JailLoc, TO);
            AREALISTS_D->remove_wanted(inven[i], JailLoc, TO);
            log_file("ICjails", "Prisoners - " + JailLoc + ":  "
                     + inven[i]->QCN + " was " +
                     "out of the " + JailLoc + " jail on " + ctime(time()) + ".\n");
            tell_object(inven[i], "Some rough looking guards enter and "
                        "drag you out of the cell to freedom.\n");
            tell_room(TO, "Some rough looking guards enter and drag "
                      + inven[i]->query_cap_name() + " out of the cell.\n", inven[i]);
            if (query_release_to()) {
                inven[i]->move(ReleaseLoc);
            } else {
                inven[i]->move(JailLoc);
            }
            if (inven[i]->query_bound()) {
                inven[i]->set_bound(0);
                tell_object(inven[i], "The guard removes your bonds.");
            }
        }
        inven[i]->force_me("look");
        continue;
    }
}
