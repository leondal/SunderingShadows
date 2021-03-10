//Coded by Lujke//
#include <std.h>
#include "../tunnel.h"

inherit VAULT;


void create(){
  ::create();
  set_name("A dank cell");
  set_short("A dank cell");
  set_long( "%^BOLD%^%^BLACK%^A dank, grimy cell, with black s%^RESET%^l"
           +"%^BOLD%^%^BLACK%^ate walls and a solid iron door.");
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_property("indoors",1);
  set_property("light",2);

  set_smell("default","The air smells grubby, with a strong smell of"
                     +" sweat and other less pleasant odours");

  set_listen("default","You can hear a few faint whimpers");
  set_exits( ([
        "north":TUNNELS+ "office",
    ]) ); 

  set_door("iron door",TUNNELS + "office","north","rune_key");


  set_lock_description("iron door","lock","%^MAGENTA%^A %^BOLD%^"
                                         +"%^YELLOW%^complex%^RESET%^"
                                         +"%^MAGENTA%^, cruciform lock");

  lock_difficulty("iron door",-30,"lock");


 
    set_items( ([ 
     ({ "wall", "walls"}):" %^BOLD%^%^BLACK%^The walls are of black"
                         +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                         +" smooth in places, but cracked and uneven in"
                         +" others, making it hard to know whether they"
                         +" have been worked or not.."
  ]) );

  set_property("no teleport",1);

}


