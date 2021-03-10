#include "../../elfisland1.h"
inherit BCAMP;
void create() {
   ::create();
   set_exits( ([ 
      "southeast" : CAMP"croad02", 
      "west" : CAMP+"tent03", 
      "northeast" : CAMP+"croad06",
   
   ]) );
}
