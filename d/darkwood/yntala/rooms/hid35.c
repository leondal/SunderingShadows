//hid35
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
  set_long("%^RESET%^%^ORANGE%^This is a narrow, %^BOLD%^%^BLACK%^dark, %^RESET%^%^ORANGE%^cavern that twists"
" it's way beneath the earth's surface, and appears to have been made by natural causes.  No dig marks or signs"
" of shoring can be seen on the smooth walls.  %^BLUE%^Cold water %^ORANGE%^constantly drips from the high ceilings"
" whose lowest points are the only parts visible through the %^BOLD%^%^BLACK%^dark shadows %^RESET%^%^ORANGE%^that are"
" more than abundant down here.   The stagnate air leaves no room for growth, and the lack of any signs of life leads"
" one to believe that hanging around too long might not be such a good idea.  The cavern slopes sharply upwards to the"
" south, while a %^BLUE%^cold, moist chill %^ORANGE%^rolls down from that direction.\n");
set_exits(([
"northwest":INRMS+"hid34",
"south":INRMS+"hid38"
]));
}