#include <std.h>
#include "../juran.h"

inherit ROOM;

void create(){
    	object ob;
   	::create();
    	set_short("Archery range");
    	set_long("You are here.");
    	set_exits( ([
      	"south" : JROOMS+"arch5",
    	]) );
      ob = new("/std/obj/target");
      ob->set_difficulty(100);
     	ob->set_overall_ac(-5);
      ob->move(TO);
      
}
