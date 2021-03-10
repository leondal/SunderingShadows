#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Systyquah's pub");
    set_short("Systyquah's pub");
    set_long(
	"%^BOLD%^Systyquah's pub%^RESET%^
You have walked into an extremely dank pub.  The air is filled with tobacco "+
	"smoke and the smell of alcohol.  There are tables scattered "+
	"across the room and a bar on the eastern wall.  Drunken patrons "+
	"litter the room, most of them passed out on tables.  In the corner "+
	"there are two bugbears armwrestling surrounded by cheering peers."
	"\nThere is a menu on the wall over the bar, you can try to <read> it."
    );
    set_listen("default","You can hear the cheers of a few drunken beasts in a far corner.");
    set_smell("default","The pub smells of smoke and alcohol.");
    set_property("light",2);
    set_property("indoors",1);
    set_property("no attack",1);
    set_exits( ([
	"northeast":"/d/laerad/parnelli/systyquah/sys067"
    ]) );
}
void reset(){
    ::reset();
    if(!present("dar")){
	new("/d/laerad/mon/dar")->move(this_object());
    }
}
void init(){
    ::init();
    add_action("read", "read");
}
int read(){
    object ob;
    int i;
    ob = present("dar");
    if(!ob){
	write("Someone has torn down the menu.");
	return 1;
    }
    write("The following drinks are served at Systyquah's pub");
    write("-------------------------------------------------------------------------");
    write("Systyquah special\t\t\t"+ (int)ob->get_price("systyquah special")+" gold");
    write("Fire water\t\t\t\t"+ (int)ob->get_price("fire water")+" gold");
    write("Leg of Elf\t\t\t\t"+ (int)ob->get_price("leg of elf")+" gold");
    write("Dwarf stew\t\t\t\t"+ (int)ob->get_price("dwarf stew")+" gold");
    write("Water\t\t\t\t\t"+ (int)ob->get_price("water")+" gold");
    write("---------------------------------------------------------------------");
    write("<buy item_name> gets you the item.");
    return 1;
}
