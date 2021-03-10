#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit ROOM;

int searched, lifted;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(FOOT_PATH);
    set("short", "%^BOLD%^%^RED%^The laboratory");
    set("long", "%^BOLD%^%^RED%^The laboratory
%^RESET%^%^CYAN%^You have entered a room filled with strong choking smells, yet the %^BOLD%^%^BLUE%^w%^CYAN%^i%^BLUE%^n%^CYAN%^do%^BLUE%^w%^RESET%^%^CYAN%^ is still open. Three %^ORANGE%^lights%^CYAN%^ similar to the one in the living room brightly lighten the room. There is a large %^BOLD%^%^CYAN%^table%^RESET%^%^CYAN%^ and some %^ORANGE%^chairs%^CYAN%^ here. Numerous %^BOLD%^%^CYAN%^vi%^BLUE%^a%^CYAN%^ls, %^CYAN%^flasks%^RESET%^%^CYAN%^ and other %^BOLD%^%^CYAN%^g%^BLUE%^l%^CYAN%^ass%^BLUE%^w%^CYAN%^ares%^RESET%^%^CYAN%^ are on the table. Several %^BOLD%^%^BLACK%^burn%^RED%^e%^BLACK%^rs%^RESET%^%^CYAN%^ with black flames are there heating some flasks on some tripods. %^BOLD%^%^CYAN%^Bot%^BLUE%^t%^CYAN%^les%^RESET%^%^CYAN%^ of powders are placed in some %^ORANGE%^b%^RED%^a%^RED%^s%^ORANGE%^kets.%^CYAN%^ Some large %^ORANGE%^b%^ORANGE%^ar%^ORANGE%^r%^ORANGE%^el%^ORANGE%^s%^CYAN%^ stand against the wall. An old man is concentrating on his work and doesn't notice your presence at all, perhaps he is just ignoring you.%^RESET%^
");
    set_property("indoors", 1);
    set_property("light", 3);
    set_property("no teleport", 1);
    set_listen("default", "You hear the sound of burners.");
    set_smell("default", "You smell strong choking smells.");
    set_items((["window" : "You see the dense forest of Argentrock outside.",
                "lights" : "Three lights with seven black candles on each forming a " +
                "triangular formation are hanging from the ceiling.",
                ({ "table", "chairs" }) : "A large wooden table and some chairs. There " +
                "burn marks on the table and also on the chairs.",
                ({ "vials", "flasks", "glasswares" }) : "All of these are made of glass, " +
                "quite obviously they are used to do experiments here.",
                "burners" : "Weird burners, they burn with a black flame!",
                "tripods" : "With a circular top and three legs, they are used to " +
                "hold the flasks above the burners.",
                ({ "bottles", "powders" }) : "They are placed in the baskets. You are " +
                "certain that they are relavent for some sort of experiment.",
                "baskets" : "Simple baskets made of bamboo.",
                "barrels" : "Lots of broken glasswares and used bottles are " +
                "dumped in them. You notice a particular black barrel with a lid.",
                "black barrel" : (: TO, "barrel_desc" :),
                "wall" : "The wall is made of the same material as the house, wood."]));
    set_exits((["door" : PATH + "arghouse7"]));
    set_search("black barrel", (: TO, "search_barrel" :));
    searched = 0;
    lifted = 0;
    if (!present("batlin")) {
        new(MON + "batlin")->move(TO);
    }

    set_had_players(10);
}

void search_barrel()
{
    switch (lifted) {
    case 1:
        switch (searched) {
        case 0:
            write("You search the black barrel and find a secret " +
                  "passage leading into darkness!");
            say(TPQCN + " searches one of the barrels and finds a " +
                "secret passage leading into darkness!");
            add_exit(PATH + "arghouse10", "passage");
            searched = 1;
            break;

        case 1:
            write("It has been searched already.");
        }
        break;

    case 0:
        write("The lid prohibits you from searching the black barrel!");
    }
}

void init()
{
    ::init();
    add_action("lift_lid", "lift");
}

int lift_lid(string str)
{
    object mage;
    switch (str) {
    case "lid":
        if (!present("batlin")) {
            switch (lifted) {
            case 0:
                write("You lift up the lid and put it on the floor.");
                say(TPQCN + " lifts up the lid of a barrel and puts it on " +
                    "the floor.");
                lifted = 1;
                return 1;

                break;

            case 1:
                write("The lid is not covering the barrel!");
                return 1;
            }
        }else {
            tell_room(TO, "%^MAGENTA%^Batlin yells: %^RESET%^What " +
                      "do you think you are doing!?");
            if (mage = present("batlin", TO)) {
                mage->kill_ob(TP, 1);
            }
            return 1;
        }
        break;

    default:
        write("What do you want to lift?");
        say(TPQCN + " moves " + TP->query_possessive() + " hands in strange " +
            "motions.");
        return 1;
    }
}

string barrel_desc()
{
    switch (lifted) {
    case 0:
        return "This is a large black barrel with a lid on it. You " +
               "cannot see what is inside while the lid is covering the " +
               "barrel.";

        break;

    case 1:
        switch (searched) {
        case 0:
            return "It is very dark inside.";

            break;

        case 1:
            return "There is a secret passage that leads down to darkness.";
        }
    }
}

void reset()
{
    ::reset();
    //  if(!present("batlin"))
    //{
    //      new(MON+"batlin")->move(TO);
    //	}
    if (member_array("passage", TO->query_exits()) != -1) {
        remove_exit("passage");
    }
    if (member_array("door", TO->query_exits()) == -1) {
        add_exit(PATH + "arghouse7", "door");
    }

    searched = 0;
    lifted = 0;
}
