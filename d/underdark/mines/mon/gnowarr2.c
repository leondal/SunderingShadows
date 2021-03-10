//Octothorpe (9/2/08)
//Underdark Mining Caverns, Svirfneblin Warrior

#include <std.h>
#include "../defs.h"
inherit MON+"gnowarr";

void create(){
   ::create();
   set_nogo(RMS+"gnocaverne2");
}
