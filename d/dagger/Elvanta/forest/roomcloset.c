#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("a closet");
set_long("%^GREEN%^Within the closet hang gowns of lace, satins and silks.  Capes of heavy wools line one wall, while earrings, necklaces, rings and other jewellry lies in a box upon another wall.  A slight crack appears in the back wall.  A bright sapphire catches your eye.");
if(!present(TP))
new("/d/dagger/Elvanta/forest/roomhealer")->move(TP);
}
