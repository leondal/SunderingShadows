#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("mound1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_short("%^BOLD%^%^WHITE%^Within a Tunnel%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You continue down the rather narrow tunnel. The"+
             " ground is hard packed dirt and the area is absolutely void of decoration. The"+
             " individual creating this tunnel obviously cared little for appearance and more"+
             " about utilization.");

   set_smell("default","\n%^RESET%^%^ORANGE%^The smell rich soils around you.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear nothing but your breathing.%^RESET%^");

    set_exits(([
		"west"	: MOUND"tunnel1",
		"south"	: MOUND"tunnel3",
	]));

}



