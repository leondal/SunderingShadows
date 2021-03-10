//tstore.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	
	set_properties((["light":2,"indoors":1,"no attack":1]));
	set("short","The Thief's guild shop");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The thief's guild shop%^RESET%^
This is the shop attached to the thief's guild. Here strange items that
benefit thieves are sold. Not everything is sold always. The guild provides
its members with what it can get. It of course makes a profit. 
There is a large shelf that contains numerous objects which are being sold here.
Type <list> to see what the store has today.
OLI
	);
	set_exits(([
		"out":"/d/tharis/Tharis/tguild1"
		]));
   set_smell("default","You smell dust and dirt, but only in small quanities.");
	set_listen("default","A rustle here an whistle there, hey these are thieves they don't make much noise.");
        set_items( ([
		({"shelf"}) : "You notice a trapdoor right next to the shelf.  Perhaps you can enter it."
	]) );
   set_property("no teleport",1);
}

void reset(){
  ::reset();
  if(!present("slump"))
	find_object_or_load("/d/tharis/monsters/slump")->move(TO);
}

void init(){
    ::init();
    add_action("enter","enter");
}
int enter(string str){
    if(!str) return 0;
/* removing to open up to everyone per current policy *Styx*  8/2002
if(!TP->is_class("thief") && !TP->is_class("assassin")){
        write("You can't seem to get in there.");
        return 1;
    }
    if(TP->is_class("fighter") || TP->is_class("mage") || TP->is_class("cleric")){
        write("You can't seem to get in there.");
        return 1;
    }
*/
    if(str != "trapdoor") return notify_fail("Enter what?\n");
    write("You slip down into the trapdoor.");
    TP->move("/d/tharis/Tharis/cguilds/thief/questroom");
    TP->describe_current_room(1);
    return 1;
}
