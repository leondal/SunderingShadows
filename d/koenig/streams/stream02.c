//stream02 - For the updated Koenig area - changed by Circe 11/21/03.  Used as inherit for the streams.
#include <std.h>
#include "../koenig.h"

inherit CROOM;

int items;
void pick_critters();
void pick_treasure();

void create() {
items = 1;
      pick_critters();
      set_repop(60);
    	::create();
      set_terrain(SHALLOW_WATER);
      set_travel(RUTTED_TRACK);
      set_property("indoors",0);
    	set_property("light",2);
    	set_short("A rapidly flowing stream");
    	set_name("A rapidly flowing stream");
    	set_long(
		"%^BOLD%^%^BLUE%^The stream is flowing rapidly "+
            "northwestward, coming down from the foothills "+
            "of the %^RESET%^%^RED%^mountains %^BOLD%^%^BLUE%^to "+
            "the southeast.  "+
            "It swirls past %^RESET%^%^ORANGE%^small rocks "+
            "%^BOLD%^%^BLUE%^and %^GREEN%^trees "+
		"%^BLUE%^jutting out into the river's path.  The water is "+
            "fairly shallow, rising "+
            "to about the knees of a typical human.  However, the "+
            "current is moving swiftly, "+
            "and the %^RESET%^%^ORANGE%^sandy bottom %^BOLD%^%^BLUE%^"+
            "seems to draw your "+
            "feet under, making it a struggle to "+
            "stand up straight.  The river would be a very pleasant "+
            "place, were it not for "+
            "the cold water coming down from the mountains chilling "+
            "you to the bone."+
            "\n"
      );
     	set_smell("default","The crisp, clear scent of water masks all other smells.");
     	set_listen("default","The burbling of the stream fills your ears.");
    	set_exits(([
    		"west" : VILSTREAM"stream09",
         	"east" : VILSTREAM"stream03",
         	//"north" : VILSTREAM"stream01",
            "south" : "/d/shadow/room/farm/room/path1"
    	] ));
    	set_items(([
         ({"bank","sandy bank","banks","sandy banks","sand"}) : "The sandy shore of the swiftly "+
            "moving river are a light tan in color.  The sand is rather coarse and glitters "+
            "iridescently in the light.",
         ({"stream","river","water"}) : "The clear water has a %^BOLD%^%^CYAN%^light blue %^RESET%^"+
            "cast to it.  Swimming against the stream are several small fish, all of whom dart away "+
            "at the first sign of you.",
         ({"village","buildings","building"}) : "The abandoned village to the north stands grim against "+
            "the backdrop of the temperate forest.",
         ({"rocks","trees"}) : "Small trees lean out over the water's edge, casting their shade "+
            "on the river and adding to its chill.  Large rocks and small boulders line the edge "+
            "of the stream in places, altering the river's course.",
         ({"bottom","sandy bottom"}) : "The water ripples around you, distorting the sandy bottom.",
         ({"mountains","mountain range","mountain"}) : "Beyond the sandy shores of the stream, you can "+
            "see the foothills that rise to a mountain range not far to the south.  Their peaks rise "+
            "reddish-brown above the blues and greens of the land here.",
    	] ));
    set_search("default", "%^ORANGE%^The sandy bottom below the river catches your eye.");
    set_search("bottom", (: TO, "search_river" :) );
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
   switch(random(10)){
      case 0..2:   break;
      case 3:   tell_room(TO,"%^BOLD%^%^CYAN%^The clear water surges around you, chilling you to the bone!");
                break;
      case 4:   tell_room(TO,"%^BOLD%^A school of tiny fish swims past your ankles, glistening irridescently.");
                break;
      case 5:   tell_room(TO,"BOLD%^%^BLACK%^The charred scent of the village rises briefly on the wind.");
                break;
      case 6:   tell_room(TO,"You hear a resounding %^BOLD%^%^CYAN%^-%^WHITE%^SPLASH%^CYAN%^- %^RESET%^"+
                "from somewhere upstream.");
                break;
      case 7:   tell_room(TO,"%^ORANGE%^A small cloud of sand rises up from the bottom, swirling "+
                "and making the water murky.");
                break;
      case 8:   tell_room(TO,"%^BLUE%^The strength of the current surges briefly.");
                break;
      case 9:   tell_room(TO,"%^CYAN%^A brisk breeze rising up over the water chills you.");
                break;
      default:  break;
   }
}

void pick_critters() {
      switch(random(9)){
         case 0:   set_monsters( ({KMON"salamander",KMON"newt"}),({random(2),random(1)}) );
                   break;
         case 1:   set_monsters( ({"/d/newbie/rooms/forest/mon/gfrog"}),({random(2)+1}) );
                   break;
         case 2:   set_monsters( ({KMON"water_elem"}),({1}) );
                   break;
         case 3:   set_monsters( ({KMON"salamander"}),({random(2)}) );
                   break;
         case 4:   set_monsters( ({KMON"newt"}),({1}) );
                   break;
         case 5:   set_monsters( ({"/d/newbie/rooms/forest/mon/gfrog",KMON"newt"}),({1,random(2)}) );
                   break;
         case 6..8: break;
      }
}

void search_river() {
  object ob;
  if(!items) {
     write("The sand is disturbed as though someone searched here recently.");
     return;
  }
  switch(random(15)){
        case 0..7:
       	  tell_object(TP,"You reach into the icy water and search the bottom, but you find nothing.");
       	  tell_room(TO,""+TPQCN+" reaches into the icy river but comes up with nothing.", TP);
       	  break;
        case 8..11:
	     tell_object(TP,"%^BOLD%^%^BLUE%^You search the sand and come up with something shining!");
	     tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" finds something lost in the sand.", TP);
           pick_treasure();
	     break;
        case 12..14:
	     tell_room(TO,"%^BOLD%^A water elemental is stirred up from the river!");
           new(KMON"water_elem")->move(TO);
	     break;
	}	
        items = 0;
        return;
}

void pick_treasure() {
      switch(random(7)){
         case 0:   new(NEWBIE"c_bracelet")->move(TO);
                   break;
         case 1:   new(NEWBIE"c_necklace")->move(TO);
                   break;
         case 2:   new(NEWBIE"c_ring")->move(TO);
                   break;
         case 3:   new(NEWBIE"c_clasp")->move(TO);
                   break;
         case 4:   new(NEWBIE"c_pendant")->move(TO);
                   break;
         case 5:   new(KOBJ"koenig_gem")->move(TO);
                   break;
         case 6:   new(KOBJ"water_earrings")->move(TO);
                   break;
      }
}
