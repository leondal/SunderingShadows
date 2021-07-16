// room with some captive dwarfies
#include <std.h>
#include "deep_echo.h"

inherit ROOM;
int searched=0;
void create()
{       int x;
		object pap;
        ::create();
        set_property("indoors",1);
        set_property("light",-1);
        set_terrain(NAT_CAVE);
        set_travel(RUTTED_TRACK);
        set_property("no sticks",1);
        set_short("Broken Portal");
        set_long("%^BOLD%^%^CYAN%^Broken Portal%^RESET%^ \n"+
		 "The tunnel comes to an end here."+
		 "  This area seems to be a holding point of sorts."+
		 "  There is a glowing %^CYAN%^sigil%^RESET%^ in the center of the room. "+
		 " Next to the sigil there are stocks "+
		 "set up.  Several %^RED%^cages%^RESET%^ are attached to the wall.");
        set_smell("default","It smells of body odor.");
        set_listen("default","Several cracks of energy can be heard."); 
		set_items(([
      (({"portal","glowing portal","sigil","glowing sigil"})) : 
	     "The sigil is formed on top of a cracked stone.  "+
         "It appears to be broken and flickers with unstable "+
         "magic.",
 
      (({"stocks","chains","cages"})) : "This places looks "+
         "to be a holding point for transfering "+
         "captives.  Many cages, stocks chains and other"+
         " devices are here.",  
        ]));
        set_exits((["west" : ROOMS"20"]));
		for(x=0;x<5;x++)
         new(MOBS"dwarf")->move(TO);
  set_search("default",(:TO,"searchy":));
  pap = new("/d/common/obj/misc/paper");
  pap->move(TO);
  pap->set("language","wizish");
  pap->set("read","\n"+
"       x     x      x-x-x-x-x \n"+
"       |    /      /        \\ \n"+
"Y    x-x-x-x      x-x-x      x \n"+
" \\    \\    |          /      | \n"+
"  x-x-x    x     x-x-x       x \n"+
" /    |    \\      \\          /  \n"+
"x     x     x-x-x-x       x-x-x \n"+
"|             | |           \\ \n"+
"x  x-O  x-x   x x           x \n"+
" \\ /        \\ /  \\         / \n"+
"  x     x-x  x   x        x-x-x  \n"+
"       /   \\    /              \\ \n"+
"      x     x-x-x              O \n"+
"lower echoes     \\ \n"+
"map              x \n"+
"                 / \n"+
"               x");
		
    
}
void init(){
  ::init();
  add_action("free", "free");
}
int free(){
   int x;
   if(!present("slave"))
     tell_object(TP, "There is no one to free");
   else{
     TP->set_mini_quest("Deep Echoes", 1000000,
      "You freed the captive dwarves in echo mountains");
	 tell_object(TP,"You break the chains on the dwarves."+
     "  they hoot for joy and run off cheering about their"+
     " second chance at life.");	 
	 tell_room(ETP,TP->query_cap_name()+" frees the dwarves.",TP);
	 for(x=0;x<5;x++)
	 if(!objectp(present("slave"))) continue;
	 present("slave")->remove();
     }
   return 1;	 
}
int searchy(string str){
     int x,y;
	 object spider;
     if (searched) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
      tell_object(TP,"%^BLUE%^Spiders crawl out "+
	   "of the broken portal when disturbed.");
	   tell_room(ETP,""+TP->query_cap_name()+
          " disturbs the portal and spiders pour out",TP);
	  for (x=0;x<random(10)+5;x++){
	    spider = new("/d/common/mons/spider");
	    spider->move(TO);
		if(!present("slave"))
		  spider->force_me("kill "+TP->query_name());
		for(y=0;y<6;y++)
		spider->force_me("kill slave "+y);
	   
	   }
	 searched = 1;
     return 1;
}



void reset(){
   ::reset();
   searched = 0; // search once per reset
 
   switch(random(5)){

      case 0:  tell_room(TO,"energy crackles from the portal.");
               break;
      case 1:  tell_room(TO,"something smell very bad.");
               break;
      case 2:  tell_room(TO,"A loud %^RED%^--CLUNK--%^RESET%^"+
                  " sounds as "+
                  "another piece of stone falls to the ground.");
               break;
      case 3:  tell_room(TO,"The stale "+
                  "air makes your stomach "+
                  "turn.");
               break;
      case 4:  tell_room(TO,"%^RED%^A jolt of dark energy"+
               " flies from the portal.");
               break;
   }
}
