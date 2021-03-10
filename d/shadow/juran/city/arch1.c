#include <std.h>
#include "../juran.h"

inherit ROOM;

void create(){
    	object ob;
   	::create();
    	set_short("Archery range");
    	set_long("You are here.");
    	set_exits( ([
    		"south": JROOMS+"archery",
      	"north" : JROOMS+"arch2",
    	]) );
      ob = new("/std/obj/target");
      ob->set_difficulty(10);
      ob->move(TO);
}
