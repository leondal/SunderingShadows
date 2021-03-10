#include "/d/attaya/newseneca/seneca.h"

inherit ROOM;

void create(){
    object ob;
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This is within the Seneca Thiefs Guild.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This is within the Seneca Thief's Guild.%^RESET%^\nYou have entered the main room of the guild. There is a board here for you to post on and to the north there is a store which will sell you thievish stuff.\n%^BOLD%^%^BLUE%^Welcome and enjoy!%^RESET%^"
    );
    set_items(([

      ]));
    set_exits(([
	"north" : THIEF "thief10",
	"out" : THIEF "thief1",
      ]));
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({"board","thieves board","posting board"}) );
    ob->set_board_id("thieves board");
    ob->set_max_posts(25);
    ob->set_location(THIEF "thief9.c");
    ob->set_short("The Board of Thievish Things");
    ob->set_long("This is the board of thievish things. Post information of particular interest to other thieves here...or just post what you want.");
    set_smell("default", "It smells of leather and Nellie's perfume here.");
    set_listen("default", "You can hear the mumblings of thieves here.");
}
void reset(){
    ::reset();
    if(!present("nellie")){
	new(THIEF "nellie.c")->move(TO);
    }
}
