#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 14");
  set_short("A carved tunnel");
  set_long( 
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            (string) TO->stonedesc() +
            "  The hallway extends to the west and northeast." +
            "  There is some %^RESET%^%^RED%^damage %^RESET%^%^WHITE%^to the walls here."
          );
          
  add_item(({"scratch","damage",}),(:TO, "stonedamage":));
  
  set_search("damage",(:TO, "specialscratchsearch":));
      
  set_search("scratches",(:TO, "specialscratchsearch":));
      
  set_exits(([
            "west" : SQUIREROOMS+"room13",
            "northeast" : SQUIREROOMS+"room15"
  ]));
  
}          

void init(){
  ::init();
  add_action("enter_crack","enter");
}

int enter_crack(string str){

  if(!str){
    return 0;
  }
  if(str == "crack" || str == "wall"){
    TP->move_player( SQUIREROOMS+"hidden.c" );
    return 1;
  }

}
