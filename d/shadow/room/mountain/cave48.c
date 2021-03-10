//cave48.c
#include <std.h>
#include "echoes.h"

inherit CROOM;
int to_find;
int max;

// These functions must be included in a room where mining with the
// /d/newbie/obj/mining_pick object is allowed.
int is_mind();
int query_to_find();
void set_found(int num);
object get_found_ob();

void create(){
    set_monsters( ({MOBS"ulfgar"}), ({1}) );
    ::create();
    set_repop(75);
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
   set_name("Dwarven Mine");
   set_short("Dwarven Mine");
   set_smell("default","You smell the slightly stale air of the mines.");
   set_listen("default","You hear the echo of picks ringing off the rock.");
   set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "This small %^BOLD%^%^BLUE%^mine %^RESET%^deep inside the tunnels under "+
      "Echoes Mountains seems to have been worked for years.  The %^ORANGE%^walls "+
      "%^RESET%^are pock-marked from the dwarves' picks, but they still "+
      "%^BOLD%^g%^RESET%^l%^BOLD%^i%^RESET%^t%^BOLD%^t%^RESET%^e%^BOLD%^r %^RESET%^"+
      "with %^BOLD%^%^RED%^g%^YELLOW%^e%^GREEN%^m%^CYAN%^s%^RESET%^.  Small "+
      "%^ORANGE%^handcarts %^RESET%^lie scattered around the mine, ready to "+
      "haul any findings away.  The %^BOLD%^%^BLACK%^floor %^RESET%^here in "+
      "the mine is very smooth, allowing the carts to pass relatively freely."+
      "\n"
   );
   set_items(([
   (({"wall","walls"})) : "The gray stone walls are gouged here from the many "+
      "picks of the dwarves.  Several places along the walls still seem to glitter, "+
      "though, and the presence of the dwarven miners suggest that the mine is "+
      "not yet stripped.",
   (({"cart","handcart","handcarts","carts"})) : "The wooden handcarts are bound "+
      "with iron, strengthening them and prolonging their life.  They are set "+
      "upon large wheels that allow them to be pulled easily.  Each seems to have "+
      "dust in the bottom.",
   "gems" : "The tell-tale glitter of gems on the wall show that there is still "+
      "wealth to be found in this mine.",
   (({"floor","ground"})) : "The smooth stone floor is covered with dust from the "+
      "mining activities of the dwarves."
   ]));
   set_search("walls","You take a closer look at the walls and see small
gems glittering in the dim light.");
   set_search("handcarts","You search the handcart but come up with nothing but dust.");
   set_exits(([
      "east" : ROOMS"cave47",
   ]));
}

void reset(){
   ::reset();
   if(!random(3))
       to_find = random(10);
   else
       to_find = 0;
   if( random(20) < 4 && !present("pick") ) 
                new(OBJ"mining_pick")->move(TO);
}
int is_mine(){return 1;}

int query_to_find(){return to_find;}

void set_found(int num){
    if(num <=0) return;
    if(num > to_find) num = to_find;
    to_find -= num;
}

object get_found_ob(){
    if(random(4))
        return new("/d/newbie/obj/misc/gem.c");
    else
        return new("/d/newbie/obj/misc/rock.c");
}
