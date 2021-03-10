#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();
    set_long("%^ORANGE%^Strangely, rocks jut out of the desert sands on this part"+
	" of the island.  They don't look natural as if the earth itself open up and "+
"reached for the sky.  Mounds of sand pile up against the rocks and downed palm"+ 
" trees are neatly stacked up on the rocky outcropping." + 
//" trees are neatly stacked up on the rocky outcropping.  It looks like this is "+ 
//"a spot for some kind of construction project.  Odd, considering the desolate "+ 
//"location... \n \n %^BOLD%^%^BLUE%^The ocean meets the land to the north and east."); 
"\n \n %^BOLD%^%^BLUE%^The ocean meets the land to the north and east."); 
    set_exits(([
        "south" : ROOMS"room31",
        "west" : ROOMS"room24",
//"enter" : "/d/islands/common/eldebaro/element/1", 
    ]));
}

/* void reset() {
int x;
if( !present("elemental")){
 for( x=0; x <4; x++){
 new("/d/magic/mon/priest_eelemental")->move(TO);}
 }
} */
// removed suggestions at the plot area as this plot long since finished. N, 3/11
