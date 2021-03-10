#include <std.h>
#define QUESTD "/daemon/quests.c"

inherit DAEMON;

int cmd_rquestlist(string str){
    mapping gmap;
    string type, filename, name;
    string *items, *items2;
    int i, xpval;

    if(!str) str = "all";

    switch(str){

    case "all":
	gmap = QUESTD->queryQuests();
	items = keys(gmap);
	for(i=0;i<sizeof(gmap);i++){
     if(!pointerp(gmap[items[i]])) continue;
	    type = gmap[items[i]][0];
	    filename = gmap[items[i]][1];
	    xpval = gmap[items[i]][2];
	    name = arrange_string(items[i], 30);
	    type = arrange_string(type, 10);
	    tell_object(TP, ""+i+")  %^RESET%^%^BOLD%^Item:%^RESET%^ "+name+" %^RESET%^%^BOLD%^Type:%^RESET%^ "+type+" %^RESET%^BOLD%^For:%^RESET%^ "+xpval+" XP");
	    tell_object(TP, "    %^RESET%^%^BOLD%^Filename:%^RESET%^ "+filename+"");
	}
	break;

    case "monsters":
    case "monster":
	gmap = QUESTD->queryMonsters();
	items = keys(gmap);
	gmap = QUESTD->queryRooms();
	items2 = keys(gmap);
	items = items - items2;
	gmap = QUESTD->queryMonsters();
	for(i=0;i<sizeof(items);i++){
	    filename = gmap[items[i]][1];
	    filename = arrange_string(filename, 30);
	    tell_object(TP, "  %^RESET%^"+i+")  %^BOLD%^Item:%^RESET%^ "+filename+"\n       %^RESET%^%^BOLD%^On:%^RESET%^ "+items[i]+"");
	}
	break;

    case "rooms":
    case "room":
	gmap = QUESTD->queryRooms();
	items = keys(gmap);
	for(i=0;i<sizeof(gmap);i++){
	    filename = gmap[items[i]][1];
	    filename = arrange_string(filename, 30);
	    tell_object(TP, "  %^RESET%^"+i+")  %^BOLD%^Item:%^RESET%^ "+filename+"\n       %^RESET%^%^BOLD%^On:%^RESET%^ "+items[i]+"");
	}
	break;

    default:
	tell_object(TP, "You have entered an invalid selection.");
	return 1;

    }
    return 1;
}

void help(){
    tell_object(TP,
      "Syntax: <rquestlist (rooms|monsters)>\n\n"
      "Lists vital information about existing rquests.  Default arg is all.  monsters or room will list only rquests related to that subject."
    );
}
