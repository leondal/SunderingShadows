// Level 3 Landing in the Marble Academy, Tonovi
// tfloor3.c

#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Floor 3");
    set_short("Level 3 Landing in the Marble Academy, Tonovi");
    set_long("Generic description for the 3rd Floor Landing, Marble Academy, Tonovi.");
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","A slight scent of ozone hangs in the air.");
    set_listen("default","Voices from throughout the tower reach your ears.");
    set_items(([
/*
       ({"steps","stairs","staircase"}) : "This grand staircase has been worn "+
          "by countless feet.  It is made of deep black marble, and "+
          "it still glitters like new.",
       ({"hall","assembly hall","amphitheater"}) : "The large assembly "+
          "hall to the north takes up the entire floor.  It is filled "+
          "with benches on raised platforms, each one higher than the "+
          "one before it to allow all magi view of the central area, "+
          "which looks to be some sort of speaker's platform.  On that "+
          "dais, there are five padded chairs and a tall podium."
*/
    ]));
    
    set_exits( ([
        "north" : "tconf",
        "down"  : "tfloor2",
        "up"    : "tfloor4",
    ]) );
}
