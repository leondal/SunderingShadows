//cave01.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_property("light" , 1); //adding to the ECHOES light value as the original
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this "+
      "tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic workmanship "+
      "suggest that the dwarves who make their home here have expanded "+
      "and improved upon nature's beauty.  The %^BOLD%^%^BLUE%^vaulted "+
      "ceilings %^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every "+
      "fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along "+
      "the walls between the arches, "+
      "creating a sense of being in the open air despite the drab walls "+
      "of the tunnels.  A large "+
      "opening to the south lets in some amount of light, while "+
      "further north the light fades "+
      "into the darkness of the tunnels.  There seems to be a long, "+
      "narrow crack on the eastern wall.\n"
    );
   add_item("crack","A crack that reaches down the wall a few feet.  "+
      "You might be able to fit "+
      "inside of it but you aren't sure.");
    set_exits(([
        "south" : ROOMS"road6",
        "north" : ROOMS"cave02",
        //"crack" : "/d/shadow/guilds/angels/tmp/cave"
   	]));
}
void init(){
    ::init();
    add_action("enter","enter");
}

int enter(string str){
    if(str != "crack") return 0;
/*
    //if((string)TP->query_guild() != "Fallen Angel"){
   write("You can't seem to squeeze into the crack.");
	return 1;
    }
*/
    write("You slip into the crack.");
    TP->move("/d/shadow/guilds/angels/tmp/cave");
    TP->describe_current_room(1);
    return 1;
}

void reset(){
   ::reset();
   if(!present("area sign")) new("/d/common/obj/areas/echoes_sign")->move(TO);
}