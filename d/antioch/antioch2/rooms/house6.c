//changed to reflect new owner, Zeal.  Gwen sold it to him
//Circe 5/2/04
#include <std.h>
#include "../antioch.h"
inherit VAULT;

#define OWNERS ({"amberly","selve","zeal"})

void create() {
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
   set_short("%^MAGENTA%^An elegant house%^RESET%^");
	set_long(
   "%^MAGENTA%^This is a small, elegant house\n%^RESET%^"+
	"You are on the first floor of an elegant house. Everything is kept neat"+
	" and tidy and all the furniture matches perfectly. The walls have been"+
	" painted a %^BOLD%^%^CYAN%^light blue%^RESET%^ shade and the carpet is a"+
	" rich %^BOLD%^%^BLUE%^sapphire%^RESET%^ color. The living room is on the"+
	" east. It is a large area with two plush couches that face eachother with"+
	" an ebony coffee table inbetween them. A cushioned chair has been placed"+
	" at the ends of the couches, facing the coffee table. A standing lamp"+
	" with a %^BLUE%^dark blue%^RESET%^ cover rests off to one side. Beyond"+
	" the living room, in the southeast corner, is a set of stairs that lead"+
	" up to the second story. On the west is the dining room. A polished"+
	" ebony table shines in the lamp light. Rectangular in shape, the table"+
	" has eight matching chairs. A sparkling silver candelabra sits in the"+
	" center of the table. A small chandelier hangs above the dining room,"+
	" splashing light everywhere. In the southwest corner is a doorway that"+
	" leads to the kitchen."
	);
	set_smell("default","The scent of vanilla fills the room.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"floor","carpet","sapphire carpet"}) : "%^BOLD%^%^BLUE%^The floor is"+
	" covered in a thick carpet.",
	"ceiling" : "The ceiling is flat, plain, and boring.",
	({"lamp","standing lamp"}) : "An oil lamp is set on a sturdy frame with a"+
	" %^BLUE%^dark blue%^RESET%^ shade covering it.",
	({"wall","walls"}) : "%^BOLD%^%^CYAN%^The walls are painted a pale blue"+
	" color.",
	({"couch","couches","plush couches"}) : "%^BOLD%^%^BLUE%^Two matching"+
	" deep blue couches sit facing eachother in the living room, seperated by"+
	" an ebony coffee table. They are large, able to easily fit three large"+
	" people, and are in very good shape.",
	({"chair","cushioned chair"}) : "%^BOLD%^%^BLUE%^A large cushioned chair"+
	" sits at the ends of the couches, facing the coffee table. It is a deep"+
	" blue color, matchingthe rest of the living room, and looks like it"+
	" would be quite easy to relax and sink into it.",
	({"chairs","ebony chairs"}) : "%^BOLD%^%^BLACK%^Eight matching ebony chairs"+
	" surround the dining room table.",
	"stairs" : "A set of stairs leads up to the second floor of the house.",
	({"table","dining table","ebony table","dining room table"}) : "%^BOLD%^%^BLACK%^A"+
	" long rectangular ebony table is in the center of the dining room. It is"+
	" highly polished, its surface gleaming in the light. A %^WHITE%^silver%^RESET%^"+
	" candelabra rests on the center of it.",
	({"candelabra","silver candelabra"}) : "%^BOLD%^A silver candelabra rests"+
	" on the center of the dining room table. It is kept highly polished and"+
	" it holds four white candles that are scented with vanilla.",
	"chandelier" : "A small chandelier hangs above the dining room table,"+
	" filling the room with light.",
	"door" : "%^BOLD%^%^CYAN%^A light blue door leads out the front of the"+
	" house.",
	]));
	set_exits(([
	"north" : ROOMS+"yard6",
	"up" : ROOMS+"upstairs2",
	"kitchen" : ROOMS+"kitchen2",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
   set_door("door",ROOMS+"yard6","north",0);
   set_locked("door",1);
}

void init()
{
   ::init();
   add_action("recite","recite");
}

void recite(string str)
{
   if(str != "poem") return 0;
   if((member_array((string)TP->query_name(),OWNERS)== -1) && (!avatarp(TP))) return 0;
   find_object_or_load("/d/antioch/antioch2/rooms/yard6");
   if(!query_locked("door")) {
      tell_object(TP,"You recite a poem and hear a gentle click as the door locks itself.");
      tell_room(ETP,""+TPQCN+" recites a poem and you hear a faint click as the door locks itself.",TP);
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/antioch/antioch2/rooms/yard6"->set_locked("door",1);
      "/d/antioch/antioch2/rooms/yard6"->set_open("door",0);
      return 1;
   }
   tell_object(TP,"You recite a poem and hear a click as the door unlocks itself.");
   tell_room(ETP,""+TPQCN+" recites a poem.",TP);
   TO->set_locked("door",0);
   "/d/antioch/antioch2/rooms/yard6"->set_locked("door",0);
   return 1;
}
