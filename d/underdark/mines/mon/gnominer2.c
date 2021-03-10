//Octothorpe (8/25/08)
//Underdark Mining Caverns, Svirfneblin Miner

#include <std.h>
#include "../defs.h"
inherit MON+"gnominer";

void create(){
   object ob;
   ::create();
   set_nogo(RMS+"gnocaverne2");
}
