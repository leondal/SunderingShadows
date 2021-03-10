//Octothorpe (1/5/09)
//Underdark Mining Caverns, Kobold Champion

#include <std.h>
#include "../defs.h"
inherit MON+"kobchamp";

void create(){
   object ob;
   object ob1;
   ::create();
   set_nogo(RMS+"kobcavernd4");
}
