#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit ROOM;

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A cellar");
    set_short("%^ORANGE%^A ruined building%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A ruined building%^RESET%^\n"
"%^GREEN%^This building seems to be mostly in %^ORANGE%^ruins%^GREEN%^.  Of the original structure, the walls are "
"partially collapsed and nearly nothing of the roof remains.  It seems that it has been been open to the elements for a "
"long time, with %^BLUE%^moss %^GREEN%^creeping its way across damp and rotted wood.  Recent attempts seem to have been "
"made, however, to reinforce the structure and make it habitable.  Mismatched planks of wood and metal, likely stolen "
"from elsewhere, are propped up by stone supports to offer shelter from the weather and the sun.  Further chunks of "
"%^RESET%^stone %^GREEN%^have been laid out as relatively flat surfaces to support what seems to be for sale here, an "
"assortment of colorful %^BOLD%^%^CYAN%^crystal fragments %^RESET%^%^GREEN%^that appear to be of questionable worth.  "
"Near the back of what remains of the structure is a %^BOLD%^%^BLACK%^hole%^RESET%^%^GREEN%^, below which a mound of "
"rubble leads down to a cellar below.\n%^RESET%^");
    set_listen("default","Aside from the wind blowing through the room upstairs it is as quiet as death here.");
    set_smell("default","The smell of decay and rotted wood fills the air.");
    set_exits(([
      "north":JROOMS+"r40",
      "down":"/d/shadow/juran/city/portal",
    ]));
}

void reset(){
    ::reset();
    if(!present("khaldar")) new("/d/shadow/juran/mons/khaldar")->move(TO);
}