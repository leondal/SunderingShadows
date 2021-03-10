/* Borrowed from the Shadow jail cell and adapted for Tonovi*/
// converted to the /std/jail_cell inheritable 9/2005 by *Styx*

#define JAILMAIN "/d/dagger/tonovi/town/jail1"

#include <std.h>

inherit "/std/jail_cell";

int company;

void create()
{
    ::create();
    set_jail(JAILMAIN);
    set_jail_location("Tonovi");
    set_release_to("/d/dagger/tonovi/road1");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no teleport", 1);
    set_indoors(1);
    set_light(1);
    set_name("jail");
    set_short("A Tonovi jail cell");
    set_long("%^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^This room was clearly not built for "
             "comfort.  The dark, stone walls are covered with %^RESET%^%^GREEN%^"
             "green mold%^BOLD%^%^BLACK%^, and the musty smell %^RESET%^pervades"
             "%^BOLD%^%^BLACK%^ your body right to the bone.  Pallets of straw "
             "cover the hard floor for prisoners to sleep on, if they don't mind "
             "sharing it with the multitude of %^RESET%^%^ORANGE%^rats%^BOLD%^"
             "%^BLACK%^ that occasionally scur%^RESET%^r%^BOLD%^%^BLACK%^y across "
             "the room.  A %^RESET%^pit%^BOLD%^%^BLACK%^ has been dug out in the "
             "corner.  %^RESET%^%^GREEN%^Flies%^BOLD%^%^BLACK%^ buzz over the hole, "
             "attracted to the %^RESET%^%^ORANGE%^p%^GREEN%^u%^ORANGE%^t%^GREEN%^"
             "r%^ORANGE%^i%^GREEN%^d%^BOLD%^%^BLACK%^ scent that rises from it.  "
             "Dim %^RESET%^li%^BOLD%^%^BLACK%^g%^RESET%^ht%^BOLD%^%^BLACK%^ manages "
             "to filter in through a small, %^RESET%^%^GREEN%^grime-covered%^BOLD%^"
             "%^BLACK%^ window.  A small, stone %^RESET%^table %^BOLD%^%^BLACK%^is "
             "in one corner with bits and pieces of food and drink scattered atop "
             "it.  The facing wall has four sets of %^RESET%^"
             "%^ORANGE%^manacles %^BOLD%^%^BLACK%^hanging loosely.  A "
             "small metal grate set within the door looks out into the main jail."
             );
    set_listen("default", "Sobbing and moans echo off the stone walls.");
    set_smell("default", "%^BOLD%^%^YELLOW%^A strong smell of urine " +
              "and rotting food fills this area.%^RESET%^");
    set_items(([
                   "grate" : "Perhaps you can peer through the grate to see who is in "
                   "the main jail.",
                   ({ "hole", "mesh" }) : "%^ORANGE%^This is a very small hole " +
                   "in a corner of the cell.  It has been covered with " +
                   "wire mesh grate.  Judging from the stains surrounding " +
                   "it and the smells emanating from it, this would be " +
                   "the toilet.%^RESET%^",
                   ({ "table", "stone table", "food" }) : "Scraps of food are " +
                   "scattered atop the stone table in the corner.  It " +
                   "looks to be very base fare, though it would keep a " +
                   "prisoner alive.  It doesn't look as though they are " +
                   "given much choice about whether or not to eat.",
                   ({ "straw", "pallets" }) : "Straw seems to be the bedding of choice.  Most of "
                   "the pallets seem to be a little narrow for humans, but would likely fit "
                   "thinner races - elves, say - quite well.",
                   "window" : "The %^BOLD%^%^BLACK%^grime-covered window%^RESET%^ has a few "
                   "spots rubbed clean enough to allow a little light in and perhaps "
                   "a limited view out.  It offers no chance of escape though as there "
                   "are %^ORANGE%^heavy iron bars%^RESET%^ protecting it."
               ]));
    set_exits(([
                   "south" : JAILMAIN,
                   "grate" : JAILMAIN,
                   "window" : "/d/dagger/tonovi/town/bazaar1"
               ]));
    set_invis_exits(({ "grate", "window" }));
    set_pre_exit_functions(({ "grate", "window" }), ({ "GoThroughDoor", "GoThroughDoor" }));
    set_door("cell door", JAILMAIN, "south", "Tonovi jail key");
    set_open("cell door", 0);
    set_locked("cell door", 1);
    lock_difficulty("cell door", -90);
    set_door_description("cell door", "This is a door made of three inch "
                         "thick oaken boards.  It has a section cut out and replaced with a "
                         "grate of inch diameter iron bars so that some air can still get to "
                         "the prisoners.");
    set_string("cell door", "open", "The cell door creaks slightly as it "
               "swings open.");
    set_string("cell door", "close", "An ominous thud echoes off the walls "
               "as the heavy cell door shuts solidly.");
    set_trap_functions(({ "cell door" }), ({ "bind_me" }), ({ "pick" }));
}

void init()
{
    ::init();
    add_action("peer_out", "peer");
}

void reset()
{
    ::reset();
    if (!trapped("cell door")) {
        toggle_trap("cell door");
    }
    if (query_open("cell door") && sizeof(all_living(TO)) < 1) {
        set_open("cell door", 0);
        set_locked("cell door", 1);
    }
    if (!company) { // only want to add once/reboot
        new("/d/common/mons/jail_mon")->move(TO);
        if (random(2)) {
            new("/d/common/mons/jail_mon")->move(TO);
        }
        company = 1;
        return;
    }
    if (!present("jail food")) {
        new("/d/common/obj/misc/jailfood/j_food_poor.c")->move(this_object());
    }
}

int GoThroughDoor()
{
    if (query_verb() == "grate") {
        write("%^ORANGE%^You wish... but you won't fit through there!");
        tell_room(ETP, TPQCN + " seems to be trying to get out through the
grate!", TP);
        return 0;
    }
    if (query_verb() == "window") {
        write("%^ORANGE%^You wish... but the window has heavy bars!");
        tell_room(ETP, TPQCN + " seems to be trying to get out through the window!", TP);
        return 0;
    }
//need to allow normal GoThroughDoor for the regular door exits
    return ::GoThroughDoor();
}

int bind_me(string str)
{
    object ob;
    if (interactive(TP)) {
        toggle_trap("cell door");
        tell_object(TP, "As you attempt to pick the lock you hear an "
                    "ominous click and suffer a paralyzing shock!");
        tell_room(ETP, TPQCN + " bends down to work at the lock but shudders "
                  "and freezes when a click sounds from it!", TP);
        TP->set_paralyzed(50, "Your muscles are frozen from the shock!");
        tell_object(TP, "A guard rushes in and binds you, then " +
                    "takes your tools!");
        tell_room(ETP, "A guard rushes in and binds " + TPQCN + ", then takes "
                  + TP->QP + " tools.", TP);
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
        tell_object(TP, "You step up to the door and peer " +
                    "out into the jail.\n");
        tell_room(ETP, TPQCN + " steps up to the cell door and " +
                  "peers out.\n", TP);
        tell_room("/d/dagger/tonovi/town/jail1", "You hear a scratching "
                  "at the door and a glimpse of movement through the grate.\n", TP);
        write("/d/dagger/tonovi/town/jail1"->query_long());
        TP->force_me("peer grate 1");
        return 1;
    }
    if (str == "window" || str == "through window") {
        tell_object(TP, "You step up to the window and peer " +
                    "out into the bazaar.\n");
        tell_room(ETP, TPQCN + " steps up to the window and " +
                  "peers out at the signs of freedom.\n", TP);
        tell_room("/d/dagger/tonovi/town/bazaar1", "You hear a scratching "
                  "at the jail window and catch a glimpse of movement inside.\n", TP);
        write("/d/dagger/tonovi/town/bazaar1"->query_long());
        TP->force_me("peer window 1");
        return 1;
    }
    return 0;
}
