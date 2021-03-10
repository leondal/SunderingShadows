#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Eastern gate of Offestry");
   set_short("%^RESET%^%^GREEN%^Eastern gate of Offestry");
   set_long("%^RESET%^%^GREEN%^Eastern gate of Offestry%^RESET%^\n"
"You have come to a crossroads here, where Sunrise Way and Shale Street intersect at the eastern gate of town.  The "
"cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but steady stream of "
"%^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on the north by a "
"jumble of %^RED%^buildings%^RESET%^, the closest of which is the stable.  Its doors open onto the streets just a few "
"paces away.  A simple wooden %^ORANGE%^palisade %^RESET%^runs along the southern and eastern sides of the road, "
"separating the town from the wilderness beyond.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way."); 
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The smell of horses and grass is in the air.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Sunrise Way leads off to the north, while Shale Street heads away west.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along the northern side of the street.  Their age and vastly "
"varied styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest is a "
"stable.%^RESET%^",
     "palisade":"%^ORANGE%^A simple palisade of tree trunks runs the length of the southern side of Shale Street, and the "
"eastern side of Sunrise Way.  It rises about six feet from the ground, forming a wooden barrier against the wilderness "
"beyond.  Small gaps between the trunks offer a view of the thick Offestry forest.%^RESET%^",
   ]));
   set_exits(([
      "east":ROAD"road1",
      "north":MAINTOWN"estreet4",
      "west":MAINTOWN"eroad2"
   ]));
   set_post_exit_functions( ({"east"}), ({"ready"}) );
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
   if(!present("sign",TO)) new("/d/newbie/obj/misc/towngatesign")->move(TO);
}

void ready(string str) {
  if(!random(4))  return;
  if(!userp(TP)) return;
  if((int)TP->query_level() > 5) return;
  if( ((int)TP->query_hp()*100)/(int)TP->query_max_hp() < 90) { 
    switch(TP->query_level()) {
      case 0..2 :  tell_room(TP, "%^CYAN%^A concerned citizen points to your "
	"wounds and suggests that you should try to %^YELLOW%^<heal> "
	"%^RESET%^%^CYAN%^yourself.");
		   break;
      case 3..5 :  tell_room(TP, "%^YELLOW%^A concerned citizen points to "
	"your wounds and suggests you visit the healer for potions or training "
	"in healing.  %^CYAN%^(help skills and help healing)%^RESET%^.");
		   break;
      case 6..1000000:  return;
      return;
    }
  }
  if(sizeof(TP->query_wielded()) == 0) {
    switch(TP->query_level()) {
      case 0..3:  tell_room(TP, "%^YELLOW%^As you take note of the sign's "
	"warning and leave the protection of the city, you realize it "
	"might be wise to wield your weapons and be prepared for battle.%^RESET%^");
	 	  break;
      case 4..1000000:  return;
    }
  }
  return;
}