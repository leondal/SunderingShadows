//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;

void create(){
	::create();
	set_name("tunnel");
   set_short("tunnel");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
     	"You are in a tunnel leading south. The walls, "+
   	"ceiling, and floor are made of native stone cut, "+
   	"and mortared, to fit perfectly. The stonework is "+
   	"of such high quality it can only be dwarven construction.  "+
   	"There are no sconces, or other devices, to hold torches, or "+
   	"lanterns. A rope hangs along the wall, and if you follow the length of it up to the roof, you see that it's attached to a bell."+
   	"%^RESET%^"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","Dust tickles your nose making you almost sneeze.");
   set_listen("default","It's very quiet here, almost creepily so.");
   set_items(([
   	({"floor","walls","wall","ceiling"}) : "The entire tunnel "+
   		"is made of native stone that has been cut, and mortared, "+
   		"to fit together perfectly.  The construction has made the "+
   		"tunnel extremely stable and is of very high quality.",
	({"rope","bell"}) : "The rope is heavy, and the bell is gleaming. You're not sure if you should pull on it, or just leave it alone.",
  	]));
   set_exits(([
   	"south" : STEFANO+"tunnel1"
	]));
}

void init() {
   ::init();
   add_action("pull","pull");
}

int pull(string str) {
   if(str != "rope") return notify_fail("Pull what?\n");
   if(member_array("up",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^The chime of the bell echoes through the tunnel as you pull its rope, and the wall swings shut.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^The chime of the bell echoes through the tunnel as "+TPQCN+" tugs on the rope, and the wall swings shut.%^RESET%^",TP);
     remove_exit("up");
     "/d/guilds/consortium/hall/help.c"->remove_exit("down");
     tell_room("/d/guilds/consortium/hall/help.c","%^ORANGE%^A bell chimes before the wall swings shut.%^RESET%^");
     return 1;
   }
   else {
     tell_object(TP,"%^ORANGE%^The chime of the bell echoes through the tunnel as you pull its rope, and the wall swings open, revealing a staircase leading up.%^RESET%^%^RESET%^");
     tell_room(ETP,"%^ORANGE%^The chime of the bell echoes through the tunnel as "+TPQCN+" tugs on the rope, and the wall swings open, revealing a staircase leading up.%^RESET%^",TP);
     add_exit("/d/guilds/consortium/hall/help.c","up");
     "/d/guilds/consortium/hall/help.c"->add_exit("/realms/titania/shadowcity/secret/stefano/tunnel.c","down");
     tell_room("/d/guilds/consortium/hall/help.c","%^ORANGE%^You hear a muffled chime of a bell and suddenly the bookcase swings open.%^RESET%^");
     return 1;
   }
}