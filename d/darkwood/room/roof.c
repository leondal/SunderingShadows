//Updated descriptions with color - Octothorpe 7/5/09
#include <std.h>
inherit VAULT;

void create(){
   ::create();
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_short("Rooftop above the back room");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_exits(([
      "down" : "/d/darkwood/room/backroom",
   ]));
   set_smell("default","The air smells of dewy foliage.");
   if(query_night() == 1){
      set_listen("default","You can hear the distant song of the "+
	     "nightingales.");
   }
   else{
      set_listen("default","The wind whispers through the trees and "+
	     "you can hear birdsong in the distance.");
   }
   set_items(([
      "roof" : "%^ORANGE%^You are on top of a flat roof above the back "+
	     "room of the Rhapsody Inn.  The roof is rather dirty, though "+
		 "it looks like someone does try to keep it clean.  On the "+
		 "southern section is the trap door that leads back into the "+
		 "inn.  There is a taller section of roof just north of here "+
		 "that slants down to the west and east to keep the rain and "+
		 "snow from piling up.%^RESET%^",
	  ({"blanket","blankets"}) : "%^BOLD%^%^BLUE%^A few blankets have "+
	     "been laid out in one section of the roof and are for anyone "+
		 "to use.%^RESET%^",
	  ({"woods","forest","trees","Darkwood"}) : "%^GREEN%^The woods "+
	     "surround the inn on three sides, helping to create the "+
		 "atmosphere of seclusion and privacy here.%^RESET%^",
	  "road" : "%^BOLD%^The Royal Southern Road that runs from Shadow "+
	     "to Tharis is off to the west.%^RESET%^",
   ]));
   set_door("trap door","/d/darkwood/room/backroom.c","down",0);
}
   
string long_desc(){
   if(season(time()) == "winter"){
      return("%^BOLD%^Rooftop above the back room\n "+
         "You are on the sn%^RESET%^o%^BOLD%^wy rooftop above the "
		 "back room of the Rhapsody Inn.  It is an addition that "+
		 "has been created to enjoy the pretty outdoor scenery "+
		 "in a relaxed setting.  The actual roof of the inn is to "+
		 "the north and is much higher up.  It slants down on either "+
		 "side to keep the sn%^RESET%^o%^BOLD%^w from piling up on "+
		 "travels from Shadow to Tharis.  To the east and south is "+
		 "the %^RESET%^%^GREEN%^Darkwood %^BOLD%^%^WHITE%^forest.  "+
		 "It looks rather peaceful during the day and you can hear "+
		 "some birds singing merrily in the distance.  A few %^BLUE%^"+
		 "blankets %^WHITE%^have been laid out on one section of the "+
		 "roof and are for anyone to use.%^RESET%^\n");
   }		
	  if(season(time()) == "spring" || season(time()) == "summer"){
         return("%^BOLD%^%^GREEN%^Rooftop above the back room\n "+
		    "You are on the rooftop above the back room of the Rhapsody "+
			"Inn.  It is an addition that has been created to enjoy the "+
			"pretty outdoor scenery in a relaxed setting.  The actual "+
			"roof of the inn is to the north and is much higher up.  "+
			"It slants down on either side to keep the snow from piling "+
			"up on it and collapsing the roof during the winter.  To the "+
			"west is the road that travels from Shadow to Tharis.  To "+
			"the east and south is the %^RESET%^%^GREEN%^Darkwood "+
			"%^BOLD%^%^GREEN%^forest.  It looks rather peaceful during "+
			"the day and you can hear some birds singing merrily in "+
			"the distance.  A few %^BLUE%^blankets %^GREEN%^have been "+
			"laid out on one section of the roof and are for anyone to "+
			"use.%^RESET%^\n");
	  } 		
      if(season(time()) == "autumn"){
         return("%^ORANGE%^Rooftop above the back room\n "+
		    "You are on the rooftop above the back room of the Rhapsody "+
			"Inn.  It is an addition that has been created to enjoy the "+
			"pretty outdoor scenery in a relaxed setting.  The actual "+
			"roof of the inn is to the north and is much higher up.  "+
			"It slants down on either side to keep the snow from piling "+
			"up on it and collapsing the roof during the winter.  The "+
			"roof is currently covered in a smattering of fallen "+
			"l%^BOLD%^e%^RESET%^%^GREEN%^av%^ORANGE%^es.  To the "+
			"west is the road that travels from Shadow to Tharis.  To "+
			"the east and south is the %^RESET%^%^GREEN%^Darkwood "+
			"%^ORANGE%^forest.  It looks rather peaceful during "+
			"the day and you can hear some birds singing merrily in "+
			"the distance.  A few %^BOLD%^%^BLUE%^blankets %^RESET%^"+
			"%^ORANGE%^have been laid out on one section of the roof "+
			"and are for anyone to use.%^RESET%^\n");
	  }		
   }
string night_desc(){
   if(season(time()) == "winter"){
      return("%^BLUE%^Rooftop above the back room\n "+
         "You are on the %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^wy "+
			"%^RESET%^%^BLUE%^rooftop above the back room of the "+
			"Rhapsody Inn.  It is an addition that has been created "+
			"to enjoy the pretty outdoor scenery in a relaxed setting.  "+
			"The actual roof of the inn is to the north and is much "+
			"higher up.  It slants down on either side to keep the "+
			"%^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^w %^RESET%^%^BLUE%^"+
			"from piling up on it and collapsing the roof.  The forest "+
			"stretches around the inn on three sides, and looks a little "+
			"daunting at night.  %^BOLD%^%^WHITE%^Moonlight %^RESET%^"+
			"%^BLUE%^bathes it in silver, but the woods themselves "+
			"remain dark.  It is easy to see why it is called the "+
			"%^GREEN%^Darkwood %^BLUE%^Forest.  Still, it is not that "+
			"bad, and you can hear a nightingale singing in the "+
			"distance somewhere.  This is a wonderful place for gazing "+
			"up at the night sky.  It seems so peaceful out here. A "+
			"few %^BOLD%^blankets %^RESET%^%^BLUE%^have been laid out "+
			"on one section of the roof and are for anyone to "+
			"use.%^RESET%^\n");
      }
      if(season(time()) == "spring" || season(time()) == "summer"){
         return("%^BLUE%^Rooftop above the back room\n "+
		    "You are on the rooftop above the back room of the "+
			"Rhapsody Inn.  It is an addition that has been created "+
			"to enjoy the pretty outdoor scenery in a relaxed setting.  "+
			"The actual roof of the inn is to the north and is much "+
			"higher up.  It slants down on either side to keep the "+
			"snow from piling up on it and collapsing the roof during "+
			"the winter.  The forest stretches around the inn on three "+
			"sides, and looks a little daunting at night.  %^BOLD%^"+
			"%^WHITE%^Moonlight %^RESET%^%^BLUE%^bathes it in silver, "+
			"but the woods themselves remain dark.  It is easy to see "+
			"why it is called the %^GREEN%^Darkwood %^BLUE%^Forest.  "+
			"Still, it is not that bad, and you can hear a nightingale "+
			"singing in the distance somewhere.  This is a wonderful "+
			"place for gazing up at the night sky.  It seems so "+
			"peaceful out here. A few %^BOLD%^blankets %^RESET%^"+
			"%^BLUE%^have been laid out on one section of the roof "+
			"and are for anyone to use.%^RESET%^\n");
      }
	  if(season(time()) == "autumn"){
	     return("%^BLUE%^Rooftop above the back room\n "+
		    "You are on the %^RESET%^%^BLUE%^rooftop above the back "+
			"room of the Rhapsody Inn.  It is an addition that has "+
			"been created to enjoy the pretty outdoor scenery in a "+
			"relaxed setting.  The actual roof of the inn is to the "+
			"north and is much higher up.  It slants down on either side "+
			"to keep the snow from piling up on it and collapsing the "+
			"roof.  The roof is currently covered in a smattering of fallen "+
			"%^ORANGE%^l%^BOLD%^e%^RESET%^%^GREEN%^av%^ORANGE%^es%^BLUE%^. "+
			"The forest stretches around the inn on three sides, and "+
			"looks a little daunting at night.  %^BOLD%^%^WHITE%^"+
			"Moonlight %^RESET%^%^BLUE%^bathes it in silver, but the "+
			"woods themselves remain dark.  It is easy to see why it "+
			"is called the %^GREEN%^Darkwood %^BLUE%^Forest.  Still, "+
			"it is not that bad, and you can hear a nightingale singing "+
			"in the distance somewhere.  This is a wonderful place for "+
			"gazing up at the night sky.  It seems so peaceful out here. A "+
			"few %^BOLD%^blankets %^RESET%^%^BLUE%^have been laid out "+
			"on one section of the roof and are for anyone to "+
			"use.%^RESET%^\n");
	  }	
   }
   
void init(){
   ::init();
   add_action("OpenDoor","open");
   add_action("CloseDoor","close");
   add_action("sit","sit");
   add_action("lay","lay");
}

void sit(string str){
   if(str == "floor" || str == "roof"){
       tell_object(TP,"You take a careful seat on the roof top.");
	   tell_room(ETP,""+TP->query_cap_name()+" takes a careful seat on the"+
	   " roof top.",TP);
	   return 1;
	}
	if(str == "blanket" || str == "blankets"){
	   tell_object(TP,"%^BOLD%^You sit down on one of the blankets.");
	   tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" sits down on one"+
	   " of the blankets.",TP);
	   return 1;
	}
}

void lay(string str){
   if(str == "floor" || str == "roof"){
   if(query_night() == 1){
      tell_object(TP,"%^BOLD%^%^BLUE%^You lay down on the roof and stare"+
	     " up at the night sky.");
      tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->query_cap_name()+" lays down"+
         " on the roof and stares up at the night sky.",TP);
		 return 1;
   }
   tell_object(TP,"You stretch out on the roof top and relax.");
   tell_room(ETP,""+TP->query_cap_name()+" stretches out on the roof top"+
      " and relaxes.",TP);
   return 1;
   }
   if(str == "blanket" || str == "blankets"){
      if(query_night() == 1) {
	     tell_object(TP,"%^BOLD%^%^CYAN%^You lay down on one of the"+
		    " blankets and gaze at the night sky.");
	     tell_room(ETP,"%^BOLD%^%^CYAN%^"+TP->query_cap_name()+" lays down"+
		    " on one of the blankets and gazes up at the night sky.",TP);
		 return 1;
	   }
      tell_object(TP,"%^YELLOW%^You lay down and get comfortable on one"+
	     " of the blankets.");
	  tell_room(ETP,"%^YELLOW%^"+TP->query_cap_name()+" lays down and"+
	     " gets comfortable on one of the blankets.",TP);
	  return 1;
   }
}

void OpenDoor(string str){
   if(!str){
      notify_fail("Open what?\n");
      return 0;
   }
   if(str == "trap door"){
      if(doors[str]["open"]) {
	     notify_fail("It is already open!\n");
		 return 0;
	  }
	  else {
	     tell_object(TP,"You carefully open the trap door.\n");
		 tell_room(ETP,""+TP->query_cap_name()+" opens the trap door.\n",TP);
		 doors[str]["destination"]->set_open(str,1);
		 set_open(str,1);
		 tell_room(doors[str]["destination"],"You notice the trap door"+
		    " suddenly open from the other side.\n");
			"/d/darkwood/room/backroom.c"->remove_invis_exit("up");
		 return 1;
	  }
   }
   return ::OpenDoor();
}

void CloseDoor(string str){
   if(!str){
      notify_fail("Close what?\n");
      return 0;
   }
   if(str == "trap door"){
      if(!doors[str]["open"]){
	     notify_fail("The trap door is already closed!\n");
		 return 0;
	  }
	  tell_object(TP,"You close the trap door.\n");
	  tell_room(ETP,""+TP->query_cap_name()+" closes the trap door.\n",TP);
	  doors[str]["destination"]->set_open(str,0);
	  set_open(str,0);
	  tell_room(doors[str]["destination"],"The trap door is closed by"+
	     " someone on the other side.\n");
	  "/d/darkwood/room/backroom.c"->set_invis_exits(({"up"}));
	  return 1;
   }
   return ::CloseDoor();
}
