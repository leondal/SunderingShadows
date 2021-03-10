#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Bayside Inn");
    set_short("%^BOLD%^%^WHITE%^Bayside Inn%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Bayside Inn%^RESET%^\n"
"This inn is one of the only new buildings in the remains of the city, built "
"upon the ashes of the old and abandoned inn that once stood here.  "
"%^ORANGE%^Austere %^RESET%^though the building may be, with plain wooden walls "
"and tables, it has a %^CYAN%^homey feel %^RESET%^to it, and a %^RED%^cosy "
"fireplace %^RESET%^roars across the room.  Stairs there lead to the upper "
"level of the building.  The inn is never overly busy, but it is rare that it "
"ever goes empty, with a constant stream of patrons day and night.\n");
    set_smell("default","You smell the odor of cooking food.");
    set_listen("default","You hear the sounds of plates clanging.");

    set_items( ([
        "menu" : "You could <read> it to see what meals are offered here.",
    ]) );
    set_exits( ([
        "south":TOWN"street10",
        "up":TOWN"inn2",
    ]) );
}

void reset() {
    ::reset();
    if(!present("innkeeper")) new(MON"sal")->move(TO);
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    object ob;
    int i;
    if(!str) return 0;
    if(str != "menu") return 0;
    ob = present("innkeeper");
    if(!ob) { write("There is noone here to serve you right now."); return 1; }

    message("Ninfo", "A menu is scrawled on a board upon the wall.\n\n", TP);
    message("Ninfo","%^RESET%^%^ORANGE%^-%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^- %^YELLOW%^Graez Inn %^RESET%^%^ORANGE%^-%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^-%^RESET%^\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  water\t\t\t "+(int)ob->get_price("water")+" silver\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  tea\t\t\t "+(int)ob->get_price("tea")+" silver\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  mead\t\t\t"+(int)ob->get_price("mead")+" silver\n\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  cioppino\t\t"+(int)ob->get_price("cioppino")+" silver\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  wild rabbit stew\t"+(int)ob->get_price("wild rabbit stew")+" silver\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  bangers and mash\t"+(int)ob->get_price("bangers and mash")+" silver\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  meat pie\t\t"+(int)ob->get_price("meat pie")+" silver\n", TP);
    message("Ninfo", "\t%^BOLD%^%^WHITE%^  bread pudding\t\t"+(int)ob->get_price("bread pudding")+" silver\n", TP);
    message("Ninfo","%^RESET%^%^ORANGE%^-%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^---%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^--%^GREEN%^<=>%^ORANGE%^-%^RESET%^\n\n", TP);
    message("Ninfo", "<buy dish_name> gets you a meal.\n", TP);
    return 1;
}
