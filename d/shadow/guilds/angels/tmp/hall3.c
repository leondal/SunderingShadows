//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_name("Abandoned castle lounge");
    set_short("Abandoned castle lounge");
    set_long(
	"You stand in an abandoned old castle lounge.  A fireplace dominates "+
	"the northern wall, ashes fill the inside.  A faded old rug covers "+
	"the floor and a few broken wood frames decorate the cracked walls.  "+
	"Shattered chairs and tables are strewn across the room.  An old rusty "+
	"bar sits on the southern wall."
    );
/*    set_property("no attack",1);
    set_property("no teleport",1);
    set_property("no steal",1);
*/
    set_listen("default","A gentle wind blows through the room.");
    set_smell("default","The smell of alcohol catches your nose.");
    set_exits( ([
	"west":"/d/shadow/guilds/angels/tmp/hall5",
	"east":"/d/shadow/guilds/angels/tmp/hall1"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("pandemonium")){
	new("/d/shadow/guilds/angels/tmp/mon/pande")->move(this_object());
    }
}
void init(){
    ::init();
    if((string)TP->query_guild() == "Fallen Angel"){
    add_action("read", "read");
    add_action("sit","sit");
    set_name("Fallen Angel's lounge");
    set_short("Fallen Angel's lounge");
    set_long(
        "You stand in a nice warm lounge.  A huge fireplace dominates "+
        "the northern wall, a blazing fire heating the room.  A bright "+
        "red rug covers the floor and hundreds of old paintings "+
        "decorate the walls.  A couple tables are spread around the "+
        "room each with four chairs.  A bar sits on the southern "+
        "wall."
    );
    set_items( ([
        ({"bar"}):"There is a menu there, perhaps you can read it."
   ]) );
    } else {
    set_name("Abandoned castle lounge");
    set_short("Abandoned castle lounge");
    set_long(
	"You stand in an abandoned old castle lounge.  A fireplace dominates "+
	"the northern wall, ashes fill the inside.  A faded old rug covers "+
	"the floor and a few broken wood frames decorate the cracked walls.  "+
	"Shattered chairs and tables are strewn across the room.  An old rusty "+
	"bar sits on the southern wall."
    );
    }
}
int read(){
    object ob;
    int i;
    ob = present("pandemonium");
    if(!ob){
	write("Someone has torn down the menu.");
	return 1;
    }
    write("You may purchase the following drinks");
    write("-------------------------------------------------------------------------");
    write("demon's fire\t\t\t\t"+ (int)ob->get_price("demon's fire")+" gold");
    write("heaven's wrath\t\t\t\t"+ (int)ob->get_price("heaven's wrath")+" gold");
    write("angel ale\t\t\t\t"+ (int)ob->get_price("angel ale")+" gold");
    write("cocktail\t\t\t\t"+ (int)ob->get_price("cocktail")+" gold");
    write("---------------------------------------------------------------------");
    write("<buy drink_name> gets you the drink.");
    return 1;
}
*/
int sit(){
    tell_object(TP,"You pull up a chair and take a seat.");
    tell_room(ETO,""+TP->query_cap_name()+" pulls up a chair and sits down.",TP);
    return 1;
}
