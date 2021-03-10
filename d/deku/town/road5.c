#include <std.h>

inherit "/std/rquestroom.c";

void create() {
    object ob;
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^");
    set_long(
"%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^
%^ORANGE%^You have come across the center of town. Main street continues towards the east and west. Broadway extends itself northward. Buildings seem to line the street in all directions. Most of the buildings along the street are constructed of wo%^GREEN%^od %^ORANGE%^with t%^RED%^h%^ORANGE%^a%^RED%^t%^ORANGE%^c%^RED%^h%^ORANGE%^e%^RED%^d %^ORANGE%^r%^RED%^o%^ORANGE%^o%^RED%^f%^ORANGE%^s and %^WHITE%^white washed %^ORANGE%^or s%^WHITE%^tu%^ORANGE%^cc%^WHITE%^oe%^ORANGE%^d wa%^WHITE%^l%^ORANGE%^ls.%^WHITE%^

%^ORANGE%^To the south a sign over the door reads: %^BOLD%^%^GREEN%^Verbobone Hotel%^RESET%^%^ORANGE%^.%^WHITE%^
"
    );
    set_exits(([
       "west" : "/d/deku/town/road4",
       "south" : "/d/deku/town/hotel",
       "north" : "/d/deku/town/road9",
       "east" : "/d/deku/town/road6"
    ] ));
    set_items(([
    ] ));
    set_quest_daemon("/daemon/quests_mid");
    if(!clonep(TO) && !present("deku board", TO))
    {
        ob= new("std/bboard");
        ob->set_name("board");
        ob->set_id(({"board","bulletin board"}));
        ob->set_board_id("union_board");
        ob->set_queue();
        ob->set_max_posts(30);
        //  ob->set_edit_ok(({"grayhawk","tristan","thorn","pegasus"}));
        ob->set_location("/d/deku/town/road5");
        ob->set_short("%^RESET%^%^GREEN%^Arcane Bulletin Board%^RESET%^");
        ob->set_long("This is an aging wooden board where adventurers sometimes leave notes "
        "related to their travels or business on this island.\n");
    }
//  set_property("no steal", 1);
//  set_property("no castle", 1);
}
