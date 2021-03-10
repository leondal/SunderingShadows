//updated by Circe 1/25/04 to reflect tunnels project
#include <std.h>

inherit ROOM;

string *name_list;
int open_exit;

void create(){
	::create();
       set_terrain(STONE_BUILDING);
       set_travel(PAVED_ROAD);
       set_property("no sticks", 1);
 	 name_list = ({});
	 set_property("light",2);
	 set_property("indoors",1);
       set_short("The back room of the registry");
	set_long(
@OLI
	%^BOLD%^%^YELLOW%^The elf registration office's back room%^RESET%^
This is a minor back room for the registration office. Not much is here.
Boxes of nothing. A couple of stools and some scraps of food are just 
in front of a large, ragged tapestry hanging on the back wall.
OLI
	);
	set_exits(([
           "north":"/d/tharis/Tharis/reg"
	]));
	set_items(([
		"boxes":"The boxes contain papers and such.",
		"food":"Nothing you want ... hell if it was good do you think the rats would have left it?",
            "tapestry" : "The tapestry is old and ragged.  You can see little of the image it may have once held.  At times, it seems to be moved slightly by some unfelt wind."
		]));
      set_search("default","Taking a close look around, you see that the tapestry seems to move strangely.");
      set_search("tapestry","It looks like the tapestry isn't tacked down at the bottom.  You might be able to lift it."); 
	set_smell("default","This office carries a rancid smell.");
	set_listen("default","Shuffling papers and feet reach your ears.");
open_exit = 0;
}

void init(){
   ::init();
   add_action("lift_em","lift");
   add_action("lower_em","lower");
}

void reset(){
   int r;
	::reset();
	
        if(!present("ruffian")) {
		new("/d/tharis/monsters/ehater")->move(TO);
		new("/d/tharis/monsters/ehater")->move(TO);
		new("/d/tharis/monsters/ehater")->move(TO);
		new("/d/tharis/monsters/ehater")->move(TO);
		new("/d/tharis/monsters/ehater")->move(TO);
		new("/d/tharis/monsters/ehater")->move(TO);		
    }
   if(!present("chest")){
      r = random(2);
      if(r==0)  new("/d/hm_quest/chests/chest5")->move(TO);
      else  new("/d/hm_quest/chests/chest19")->move(TO);
   }
}

int lift_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to lift?");
      return 1;
   }
   if(str == "tapestry" || str == "corner of tapestry"){
      if(present("ruffian")){
         tell_object(TP,"The ruffian moves in your way and snarls at you.");
         tell_room(ETP,"As "+TPQCN+" steps toward the tapestry, the ruffian "+
            "gets in the way and snarls.",TP);
         tell_room(ETP,"%^RESET%^%^MAGENTA%^The ruffian says%^RESET%^: "+
            "What are you doin', sneakin' around in here?  Get lost!");
         return 1;
      }
      if(!open_exit){
         tell_object(TP,"You lift the corner of the tapestry and find "+
            "an open hole leading out back.");
         tell_room(ETP,""+TPQCN+" lifts the tapestry, revealing a hole leading "+
            "out back.",TP);
         add_item("tapestry","The tapestry has been pulled back, revealing a hole "+
            "leading out behind the building.  It could probably be lowered again.");
         add_item("hole","The hole looks to have been crudely carved through the "+
            "wall.  Much of the wood looks fairly fresh, as if it has been done "+
            "well after the building was built.");
         add_exit("/d/tharis/Tharis/slavepit","south");
         open_exit = 1;
         return 1;
      }
      tell_object(TP,"The tapestry is already lifted!");
      return 1;
   }
   tell_object(TP,"You can't lift that!");
   return 1;
}

int lower_em(string str){
      if(!str || str != "tapestry"){
         tell_object(TP,"What are you trying to lift?");
         return 1;
      }
      if(!open_exit){
         tell_object(TP,"The tapestry is already lowered!");
         return 1;
      }
      tell_object(TP,"You lower the corner of the tapestry and cover "+
         "the hole leading out back.");
      tell_room(ETP,""+TPQCN+" lowers the tapestry, covering the hole leading "+
         "out back.",TP);
      add_item("tapestry","The tapestry is old and ragged.  You can see little "+
         "of the image it may have once held.  At times, it seems to be moved "+
         "slightly by some unfelt wind.");
      remove_item("hole");
      remove_exit("south");
      open_exit = 0;
      return 1;
}
 