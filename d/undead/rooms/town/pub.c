#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The Rum and Monkey");
    set_short("%^RESET%^%^CYAN%^The Rum and Monkey%^RESET%^");
    set_long("%^RESET%^%^CYAN%^The Rum and Monkey%^RESET%^\n"
"%^ORANGE%^Long famous, even upon other continents, the Graez pub has been "
"recently renovated and restored to its former glory.  For all that a pub "
"could be glorious, at least, with its rough wooden tables and %^RED%^rowdy "
"%^ORANGE%^patronage.  Still, it seems one of the %^MAGENTA%^busiest "
"%^ORANGE%^locations in town, constantly filled with town visitors and the "
"soldiers that serve upon the island.  A small doorway behind the counter leads "
"to what appears to be a storeroom.%^RESET%^\n");
    set_smell("default","The thick smell of smoke and ale fills the room.");
    set_listen("default","All you can hear is the rowdy laughter and chatter of the patrons.");
    
    set_items(([
        "menu":"You could read it to see what's available."
    ]));
    set_exits(([
        "north":TOWN"street19",
        "storeroom":TOWN"thieves",
        "doorway":TOWN"thieves",
    ]));
    set_invis_exits(({"doorway","storeroom"}));
}

void reset() {
    ::reset();
    if(!present("korrene")) new(MON"korrene")->move(TO);
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    object ob;
    ob = present("korrene");
    if(!ob) {
      write("You cannot read the menu, as it is splattered with blood.");
      return 1;
    }
    message("Ninfo","The following are on offer at the bar:\n", TP);
    message("Ninfo","%^RESET%^%^CYAN%^----------------------------------------------------------------\n%^RESET%^", TP);
    message("Ninfo", "\tA glass of juice\t\t"+(int)ob->get_price("juice")+" silver\n", TP);
    message("Ninfo", "\tA glass of ale\t\t\t"+(int)ob->get_price("ale")+" silver\n", TP);
    message("Ninfo", "\tA mug of coffee\t\t\t"+(int)ob->get_price("coffee")+" silver\n", TP);
    message("Ninfo", "\tA Deathblow\t\t\t"+(int)ob->get_price("deathblow")+" silver\n", TP);
    message("Ninfo", "\tBowl of nuts\t\t\t"+(int)ob->get_price("nuts")+" silver\n", TP);
    message("Ninfo", "\tBowl of pretzels\t\t"+(int)ob->get_price("pretzels")+" silver\n", TP);
    message("Ninfo", "\tBaked potato\t\t\t"+(int)ob->get_price("potato")+" silver\n", TP);
    message("Ninfo", "\tPickled eggs\t\t\t"+(int)ob->get_price("eggs")+" silver\n", TP);
    message("Ninfo","%^RESET%^%^CYAN%^----------------------------------------------------------------\n%^RESET%^", TP);
    message("Ninfo", "<buy itemname> gets you that food/drink.\n", TP);
    return 1;
}
