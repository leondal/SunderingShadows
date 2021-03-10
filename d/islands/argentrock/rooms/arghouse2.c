#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit ROOM;

int in_place;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set("short","The study");
    set("long","%^RED%^The study
%^RESET%^%^CYAN%^This is obviously the study. A lot of moldy %^ORANGE%^books%^CYAN%^ are on the book %^ORANGE%^shelves%^CYAN%^. Spider webs cover the %^BOLD%^%^CYAN%^li%^BLUE%^g%^CYAN%^ht%^RESET%^%^CYAN%^ hanging in the middle of the ceiling. A %^BOLD%^%^CYAN%^pen%^RESET%^%^CYAN%^ and some %^BOLD%^%^BLACK%^ink%^RESET%^%^CYAN%^ are on the large oak wood %^BOLD%^%^BLUE%^d%^CYAN%^e%^BLUE%^s%^BLUE%^k%^CYAN%^.%^RESET%^%^CYAN%^ There is a lit black %^WHITE%^c%^WHITE%^a%^WHITE%^ndl%^WHITE%^e%^CYAN%^ with a mystic black flame. Piles of %^BOLD%^%^CYAN%^papers%^RESET%^%^CYAN%^ occupy the desktop.%^RESET%^
");
    set_property("indoors",1);
   set_property("no teleport",1);
    set_property("light",2);
      set_listen("default","You hear swinging sounds of the light hanging "+
        "from the ceiling.");
      set_smell("default","You smell mold.");
    set_items( (["dictionary": (: TO,"dictionary" :),
         "books":"Almost all the books are covered with mold.",
        "light":"A light with seven black candles is hanging in the middle "+
        "of the ceiling. It is swinging without cause.",
        ({"pen","ink"}):"Some ordinary stationary.",
        "desk":"A large oak wood desk with some drawers.",
        "candle":"You have never see a candle burning with a black flame.",
        "shelves":"The shelves are packed full of books. You notice some "+
        "small gaps between the shelves, maybe you should search around.",
        "lever":"Maybe you should try pulling it?",
        ({"papers","piles"}):"There are lots of strange drawings on the "+
        "papers."]) );
    set_exits( (["door":PATH+"arghouse3"]) );
    in_place = 1;
}

void init() {
    ::init();
    add_action("remove_book","remove");
    add_action("pull_lever","pull");
    add_action("search_books","search");
}

int remove_book(string str) {
    if(!str) {
        notify_fail("What do you want to remove?\n");
        return 0;
    }
    if(str != "book" && str != "dictionary") {
        notify_fail("You cannot remove that!\n");
        return 0;
    }
    write("You found a lever hidden behind the dictionary!");
    say(TPQCN+" found a lever hidden behind the dictionary!");
    in_place = 0;
    return 1;
}

int pull_lever(string str) {
    if(!str) {
        notify_fail("Pull what?\n");
        return 0;
    }
    if(str != "lever") {
        notify_fail("You cannot pull that!\n");
        return 0;
    }
    if(in_place == 1) {
        notify_fail("What lever?\n");
        return 0;
    }
    write("As you pull the lever, the shelf turns and reveals a dark "+
        "chamber behind it.");
    say("As "+TPQCN+" pulls the lever, the shelf turns and reveals a "+
        "chamber behind it.");
    add_exit(PATH+"arghouse1","chamber");
    add_pre_exit_function("chamber","lock_msg");
    return 1;
}

int lock_msg() {
    write("%^BOLD%^CYAN%^As you walk into the chamber, the shelf "+
        "behind you turns and shuts you in.");
     say("%^BOLD%^CYAN%^As "+TPQCN+" walks into the chamber, the shelf "+
        "behind "+TP->query_objective()+" turns and shuts "+
        TP->query_query_objective()+" in.");
    reset();
    return 1;
}

int search_books(string str) {
    if(!str) {
        notify_fail("Search what?\n");
        return 0;
    }
    if(str == "books") {
         write("You notice a dictionary that is not covered by mold.");
        say(TPQCN+" found a book particularly interesting.");
        return 1;
    }
}

string dictionary(string str) {
    switch(in_place) {
        case 0:
            return "It is left on the floor.";
            break;
        default:
            return "The dictionary evidently has been removed recently.";
    }
}

void reset() {
    ::reset();
    if(in_place != 0)
    in_place++;
    remove_exit("chamber");
    remove_post_exit_function("chamber");
}
