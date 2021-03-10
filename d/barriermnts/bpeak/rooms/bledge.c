//gledge
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;

void create(){
::create();
   set_property("light",2);
   set_travel(LEDGE);
   set_terrain(ROCKY);
   set_name("%^RESET%^The ledge of a cliff.");
   set_short("%^RESET%^A narrow ledge.");
   set_long((:TO,"ldesc":));
   set_smell("default","A bad smell floats out of the cave.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The wind howls as it races past you.");
   set_items(([
   "ledge":"%^RESET%^%^ORANGE%^The ledge is made of some sort of rock that is cracked and crumbling, but fairly stable.%^RESET%^",
   ({"rocks","rock"}):"%^BOLD%^%^BLACK%^Rocks litter the ledge and vary in size from small to very very large.%^RESET%^",
   ({"cliff","cliff face"}):"%^RESET%^The cliff face is is sheer here, with the exception of this little ledge.  It is at least fifty feet to the bottom, but so steep that it looks impossible to climb.",
   ({"opening","cave","cave opening"}):"%^BOLD%^%^BLACK%^The opening in the side of the cliff leads into a dark cave.  It is about twenty feet in height and leads into the darkness.  From here you cannot tell where it leads or what is inside.%^RESET%^",
   "path":"%^RESET%^%^ORANGE%^The path below winds its way up the side of the cliff.  The vantage point from here is very good, and you realize that nothing would be able to approach this area unnoticed.%^RESET%^",
   ({"steps","stone steps","stairs","stairway"}):"%^RESET%^The"
" %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^p%^BOLD%^%^BLACK%^s"
" %^RESET%^are made of very large slabs of %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^"
"%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^and have been made into a stairway"
" that leads to the top of the cliff above.",
   "valley":"%^RESET%^%^GREEN%^A small valley is set between the %^BLUE%^mountains."
"  %^GREEN%^The view of it from here is lovely, as a full grown forest florishes"
" there.  A %^BOLD%^%^BLUE%^river %^RESET%^%^GREEN%^winds its way through the center"
" of the valley, fed by the %^CYAN%^waterfall %^GREEN%^that falls from the cliffs"
".%^RESET%^",
   "waterfall":"%^BOLD%^%^CYAN%^A waterfall flows from an opening in the cliff face near here and falls to a deep pool below before making its way down the mountainside and into the valley.%^RESET%^",
   "pool":"%^BOLD%^%^BLUE%^The pool of water is very deep and turbulent as the water from the fall constantly pummels into it.%^RESET%^",
   ({"bridge","wooden bridge"}):"%^RESET%^%^ORANGE%^Along the path below is a wooden bridge that passes over the river fed by the waterfall.  It successfully connects the two paths on either side of it and looks to be quite sturdy.%^RESET%^",
   "river":"%^RESET%^The %^BOLD%^%^BLUE%^river %^RESET%^flows from the pool and down the mountainside before snaking its way through the %^RESET%^%^GREEN%^valley %^RESET%^below.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["cave":INRMS+"bcave4","steps":INRMS+"steps"]));
}
string ldesc(string str){
   return("%^RESET%^This ledge is quite large and overlooks a small %^ORANGE%^path"
" %^RESET%^that winds its way along the cliff edge below.  %^BOLD%^"
"%^BLACK%^S%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e "
"%^RESET%^s%^BOLD%^%^WHITE%^t%^BLACK%^e%^RESET%^p%^BOLD%^%^BLACK%^s"
" %^RESET%^composed of very large slabs of %^BOLD%^%^BLACK%^g%^WHITE%^r%^RESET%^a"
"%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^WHITE%^t%^BLACK%^e %^RESET%^lead up to the"
" cliff above.  The view of the %^GREEN%^valley %^RESET%^below the"
" %^ORANGE%^path %^RESET%^is astounding.  You can see a"
" %^CYAN%^w%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^BLUE%^e%^CYAN%^r%^BOLD%^%^BLUE%^f"
"%^CYAN%^a%^RESET%^%^BLUE%^l%^CYAN%^l %^RESET%^coming out of the cliffs that"
" %^BOLD%^%^WHITE%^spl%^CYAN%^a%^WHITE%^shes %^RESET%^down into a %^BLUE%^deep"
" pool.  %^RESET%^The pool overflows from there into a %^BOLD%^%^BLUE%^river"
" %^RESET%^that snakes its way through the mountain range to the south."
"  A %^RESET%^%^ORANGE%^wooden bridge %^RESET%^crosses the part of the ledge that"
" the %^BOLD%^%^CYAN%^waterfall %^RESET%^eroded away and connects the two"
" sides.%^RESET%^\n");
} 
void reset() {
  ::reset();
  if(!present("giant")){
     new(TMONDIR+"hillg2.c")->move(TO);
     new(TMONDIR+"hillg2.c")->move(TO);
  }
}
