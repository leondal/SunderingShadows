#include <std.h>
inherit ROOM;

void create(){
    object ob;
    ::create();
    set_light(2);
//    set_property("no teleport", 1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Foyer of the Cavaliers' Guild Hall");
    set_long(
"You have entered the foyer of the hall of the Cavaliers. Your boots click along the beautifully crafted hardwood floors.  All around the room on the walls are banners of gold cloth with various coats of arms and emblems on them.  To the west great glass doors open into the courtyard, and to the northwest, a broad hallway filled with the paintings and tokens of justice, honor, and victory leads to the Great Hall."
    );
    set_exits(([
        "east":"/d/shadow/room/city/cguild/cavalier/stable",
        "northeast":"/d/shadow/room/city/cguild/cavalier/store",
        "northwest":"/d/shadow/room/city/cguild/cavalier/greathall",
        "west":"/d/shadow/room/city/cguild/cavalier/cyard",
      "out" : "/d/shadow/room/city/cguild/cavalier/enter1",
      ]));
    set_items(([
	"floors" : "These floors are made of fine wood and are kept amazingly clean and shiny.",
      ]));
    set_smell("default","The appetizing smell of food drifts to you from the bar.");
    set_listen("default", "You hear the sound of low conversation from around the room, but no noise from the barn reaches this quiet lounge.");
/*
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "riders board" }) );
    ob->set_board_id("cavalierboard");
    ob->set_max_posts(30);
    ob->set_location("/d/shadow/room/city/cguild/cavalier/guild2");
    ob->set("short", "Cavaliers' Board");
    ob->set("long", "This board is for The members of the Cavaliers "
      "Guild to post their ideas and comments.\n");
*/
}
/*
void init(){
    ::init();
    add_action("test_cava", "remove");
    add_action("test_cava", "answer");
    add_action("test_cava", "post");
    add_action("test_cava", "edit");
}

int test_cava(){
    if(avatarp(TP)) return 0;
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin")) return 0;
    tell_object(TP, "Thou ist not worthy!");
    return 1;
}
*/