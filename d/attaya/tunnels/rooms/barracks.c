//Coded by Lujke//
#include <std.h>
#include "../tunnel.h"


inherit VAULT;
string long_desc();

void create(){
  ::create();
  
  set_short("A barrack room");
  set_long( (:TO,"long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_property("indoors",1);
  set_property("light",2);

  set_smell("default","The air smells grubby, with a strong smell of"
                     +" sweat and other less pleasant odours");

  set_listen("default","It's fairly quiet here");

 set_exits( ([
         "west":TUNNELS+"office"
    ]) ); 
 
    set_items( ([ 
  ({ "locker","lockers", "foot lockers"}): "The lockers appear to be"
    +" fairly standard, but you could search them if you wanted to see"
    +" what was inside",
  ({ "bed","beds"}): "The beds are fairly basic. Each has an upper and"
                    +" lower bunk, for a total of twelve sleeping"
                    +" places.",
  ]) );
  set_search("locker", "A few bits and pieces of personal junk. Nothing"
                      +" exciting");
  set_property("no teleport",1);

}

string long_desc(){
     return "Half a dozen bunk beds are lined up against the walls of"
           +" this room, each with its own footlocker and small table. A"
           +" weapon rack at the far end of the room contains a few"
           +" swords.";
}