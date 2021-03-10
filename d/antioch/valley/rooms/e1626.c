#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
        ::create();
        set_exits( ([
        "north" : ROOMS+"e1726",
        ]) );
        set_invis_exits(({"north"}));
		set_search("room",(:TO,"search_room":)); 
}
int search_room(string str){
     if(present("stone",TO)) return 0;
     tell_object(TP,"You dig through the bush and find"+
	 " a strange stone covered with odd symbols.");
	 new("/d/islands/elf/obj/pstone")->move(TO);
      return 1;
}