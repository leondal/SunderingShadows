#include <std.h>
#include "../juran.h"


inherit ROOM;

void create(){
   	object ob;
   	::create();
    	set_short("Archery range");
    	set_long("You are here.");
    	set_exits( ([
      	"north" : JROOMS+"arch3",
      	"south" : JROOMS+"arch1",
    	]) );
      ob = new("/std/obj/target");
      ob->set_difficulty(20);
      ob->move(TO);
}
