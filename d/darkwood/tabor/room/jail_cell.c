// by Styx for Tabor 8/05 using new inheritable

#include <std.h>

#define JAILMAIN "/d/darkwood/tabor/room/jail"

inherit "/std/jail_cell.c";

void create()
{
    ::create();
    set_jail(JAILMAIN);
    set_jail_location("Tabor");
    set_release_to("/d/shadow/room/forest/road58");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no teleport", 1);
    set_indoors(1);
    set_light(1);
    set_name("jail");
    set_short("A nondescript jail cell");
    set_long("%^BOLD%^%^BLACK%^You find yourself in a %^RESET%^%^ORANGE%^d"
             "%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^mp%^BOLD%^%^BLACK%^, "
             "m%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^sty, jail cell with cold "
             "sto%^RESET%^n%^BOLD%^%^BLACK%^e walls and floor.  There is a "
             "%^RESET%^grate%^BOLD%^%^BLACK%^ in the door that leads out to "
             "the main jail and a few pallets of %^RESET%^%^ORANGE%^str"
             "%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^w%^BOLD%^%^BLACK%^ to "
             "sleep on.  One corner has a small pit with a small drain at the "
             "bottom but it doesn't appear to take enough of the %^RESET%^%^ORANGE%^"
             "excrement%^BOLD%^%^BLACK%^ away to keep it from adding to the "
             "overall %^RESET%^%^GREEN%^sten%^ORANGE%^c%^GREEN%^h%^BOLD%^%^BLACK%^ "
             "of the room.%^RESET%^"
             );
    set_listen("default", "%^GREEN%^You can hear the %^ORANGE%^rats%^RESET%^"
               "%^GREEN%^ scurrying around.%^RESET%^");
    set_smell("default", "%^GREEN%^A na%^ORANGE%^u%^GREEN%^se%^BOLD%^%^BLACK%^"
              "a%^RESET%^%^GREEN%^ting smell rises from the %^ORANGE%^filt%^RED%^"
              "h%^ORANGE%^y%^RESET%^, %^ORANGE%^da%^BOLD%^%^BLACK%^m%^RESET%^"
              "%^ORANGE%^p%^GREEN%^ floor.%^RESET%^");
    set_items(([
                   "grate" : "Perhaps you can peer through the door grate to see who is in the main jail.",
                   ({ "bars", "iron bars" }) : "Iron bars stretch from the ceiling to the floor to create rather small cells in which many people are crammed if it's busy. There are more bars that cover the windowsto prevent escape.",
               ]));
    set_exits(([
                   "up" : JAILMAIN,
                   "grate" : JAILMAIN,
                   "window" : "/d/darkwood/tabor/room/greene2",
               ]));
    set_invis_exits(({ "window", "grate" }));
    set_pre_exit_functions(({ "window", "grate" }), ({
        "GoThroughDoor", "GoThroughDoor"
    }));
    set_door("cell door", JAILMAIN, "up", "Tabor jail key");
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
//   JAILMAIN->set_open("cell door",0);
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
        //removing as it causes recursion errors
        // JAILMAIN->set_open("cell door", 0);
        // JAILMAIN->set_locked("cell door", 1);
    }
    if (!company) { // only want to add once/reboot
        new("/d/common/mons/jail_mon")->move(TO);
        if (!random(3)) {
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
    if (query_verb() == "grate" || query_verb() == "window") {
        write("%^ORANGE%^You wish... but you won't fit through there!");
        tell_room(ETP, TPQCN + " seems to be trying to get out through the
grate!", TP);
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
        tell_object(TP, "As you attempt to pick the lock you hear an ominous click and suffer a paralyzing shock!");
        tell_room(ETP, TPQCN + " bends down to work at the lock but shudders and freezes when a click sounds from it!", TP);
        TP->set_paralyzed(50, "Your muscles are frozen from the shock!");
        tell_object(TP, "A guard rushes in and binds you, then takes your tools!");
        tell_room(ETP, "A guard rushes in and binds " + TPQCN + ", then takes "+TP->query_possessive()+" tools.", TP);
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
        tell_object(TP, "You step up to the door and peer out into the jail.\n");
        tell_room(ETP, TPQCN + " steps up to the cell door and peers out.\n", TP);
        tell_room(JAILMAIN, "You hear a scratching at the door and catch a glimpse of movement through the grate.\n", TP);
        TP->force_me("peer grate 1");
        return 1;
    }
    if (str == "window" || str == "out window" || str == "out") {
        tell_object(TP, "You climb up to the window and peer outside.\n");
        tell_room(ETP, TPQCN + " climbs up to the window and peers out.\n", TP);
        TP->force_me("peer window 1");
        return 1;
    }
    return 0;
}
