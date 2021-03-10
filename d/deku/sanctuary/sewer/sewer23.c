#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange but interesting objects. The tunnel bends"+
      " here, continuing to the south, and back toward the east. The walls"+
      " are dark and covered with human and demihuman waste from the many"+
      " decades of sewage that flowed within these dark tunnels."
    );
    set_exits(([
       "east" : SEWER+"sewer22",
       "south" : SEWER+"sewer24"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_smell("default","The smell of human and demi-human waste is becoming overwhelming.");
}
