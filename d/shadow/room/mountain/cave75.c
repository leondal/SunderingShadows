//cave75.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"The passageway bends sharply here, "+
       "and it seems the passage leading south was once even more "+
       "grand than the rest of the tunnels, but it has fallen "+
       "into even further disrepair now.\n");
    set_exits(([
        "east" : ROOMS"cave74",
        "south" : ROOMS"cave76",
   	]));
}
