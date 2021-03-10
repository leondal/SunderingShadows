//steps
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^The cliff steps");
   set_short("%^RESET%^Steps carved into the cliff%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The smell of sweat, poorly kept animals and dirt mixes with the scent of the pines below.%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^Besides the noise of the wind, the occassional grunt, shout or howl echoes from somewhere around here.%^RESET%^");
   set_exits((["down":INRMS+"bledge","up":INRMS+"tcliff5"]));
}
string ldesc(string str){
   return("These steps are old but strong.  Built out of the carved rock from the"
" cliff itself, they seem as though they could endure anything.  One side of the"
" steps are right up against the sheer cliff face, while the other side drops"
" straight down to the %^GREEN%^ravine %^RESET%^below.  Looking down there, you"
" realize you would hate to be pushed off of these steps.%^RESET%^\n");
} 
