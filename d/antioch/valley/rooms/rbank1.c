#include <std.h>
#include "../valley.h"
inherit RIVER;

void create(){
   ::create();
    	set_long(
   "%^CYAN%^A %^BLUE%^%^BOLD%^river%^RESET%^%^CYAN%^ slowly winds its "+
   "way through the vale. You are standing on"+
   " the edge of the %^ORANGE%^sandy%^CYAN%^ bank. You can see the"+
   " %^BOLD%^water%^RESET%^%^CYAN%^ rushing before you,"+
   " flowing from a %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ and disappearing"+
   " into the %^GREEN%^woods%^CYAN%^. The water looks"+
   " %^BOLD%^crystal%^RESET%^%^CYAN%^ clear and %^BOLD%^%^BLUE%^very cold"+
   "%^RESET%^%^CYAN%^. On the other side of the river you see"+
   " more %^GREEN%^grasslands%^CYAN%^ and a %^BOLD%^%^GREEN%^meadow"+
   "%^RESET%^%^CYAN%^, a few trees are also scattered about. A %^BOLD%^%^GREEN%^"+
   "moss%^RESET%^%^CYAN%^ covered bridge links the two shores together.\n"
   );
   set("night long",
   "%^CYAN%^A %^BOLD%^%^BLUE%^river%^RESET%^%^CYAN%^ winds its way through"+
   " this vale, occasionally crashing against"+
   " the bank when it makes a sharp turn. You can see the water raging"+
   " before you, spilling from the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^"+
   " to follow its own path into the"+
   " %^GREEN%^woods%^CYAN%^. The water looks almost %^BLUE%^b%^BOLD%^%^BLACK%^"+
   "l%^BLUE%^a%^RESET%^%^BLUE%^c%^BOLD%^%^BLACK%^k%^RESET%^%^CYAN%^ at night"+
   " and you get the feeling"+
   " that it's %^BOLD%^%^CYAN%^icy cold%^RESET%^%^CYAN%^. The bank you're "+
   "standing on is slightly damp, the"+
   " river must have climbed up a bit higher earlier to wash against the"+
   " %^ORANGE%^sand%^CYAN%^. On the opposite bank you can see more %^GREEN%^"+
   "grasslands %^CYAN%^and a %^BOLD%^%^GREEN%^meadow%^RESET%^%^CYAN%^,"+
   " a few trees are also scattered about over there.  A %^GREEN%^%^BOLD%^moss"+
   "%^RESET%^%^CYAN%^ covered bridge links the two shores together.\n"
   );
	add_item(({"bridge","moss bridge","wooden bridge"}),"%^BOLD%^%^GREEN%^Covered with moss, "+
		"this aged wooden bridge connects the two banks of the river together."+
		"  Though the bridge looks quite ancient, it still seems very sturdy.");  
	set_exits(([
   		"west" : ROOMS+"rbank2",
   		"east" : FRING+"f1",
   		"north" : ROOMS+"v1",
                "bridge" : "/d/antioch/valley/rooms/rb3.c",
   ]));
}
