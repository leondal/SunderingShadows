//elveninn.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	set_property("light",2);
	set_property("indoors",1);
	set("short","The main room of the elven inn");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The main room of the Elven inn%^RESET%^
This old building could be the most majestic tavern you've ever been in.
The high vaulted ceiling beams are carved perfectly, almost as if the tree
helped carve them.  The tables are worn but gleam with the shine of newly
finished wood.  The bar on the other end of the room shines with the polish.
This is where elves of the city come to have fun and enjoy themselves
and socialize.  You can see the entrance to some back room from where you 
stand.  There is a menu on the wall.
OLI
	);
	set_exits(([
		"east":"/d/tharis/Tharis/enside2",
		"west":"/d/tharis/Tharis/elveninn2"
		]));
	set_items(([
		"beams":"These finely carved beams were made by the skills of the ancient wood carvers",
		"table":"These finely carved tables shine with a marvelous patina.",
		"menu":"You may want to read it."
		]));
	set_listen("default","You hear the cheerful chatter of the elven citizens.");
	set_smell("default","The sweet smells of elven food reach your nostrils.");
}

void reset(){
   ::reset();
   if(!present("alder"))
	find_object_or_load("/d/tharis/monsters/alder")->move(TO);
}


int read(string str) {
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("alder");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    write("The following great foods are served here at the Elven Inn of Tharis.");

write("--------------------------------------------------------------------");
    write("Elven stew\t\t\t\t"+ (int)ob->get_price("elven stew") + " silver");
    write("Deer cutlet\t\t\t\t"+(int)ob->get_price("deer cutlet")+" silver");
    write("Elven biscuits\t\t\t\t"+(int)ob->get_price("elven biscuits")+" silver");
    write("Cheese\t\t\t\t\t"+ (int)ob->get_price("cheese")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}

void init(){
  ::init();
  add_action("read","read");
}
