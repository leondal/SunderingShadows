//gazebo.c - updated gazebo for new Seneca
//I tried to keep the overall feel but adjust it to fit the flavor
//and level of detail.
//~Circe~ 1/13/08
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(GARDEN);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_name("Inside the Gazebo, Seneca");
   set_short("%^BOLD%^%^WHITE%^Inside the Gazebo, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Inside the Gazebo, Seneca%^RESET%^\n"+
      "%^ORANGE%^Oval in shape, this beautiful gazebo "+
      "provides a warm, inviting atmosphere while its size allows "+
      "for weddings and other joyous occasions.  A low "+
      "slatted %^YELLOW%^railing %^RESET%^"+
      "%^ORANGE%^topped by wooden archways rises all around, "+
      "flourishing %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a"+
      "%^BOLD%^%^WHITE%^s%^RESET%^m%^BOLD%^%^GREEN%^"+
      "i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e %^RESET%^v%^BOLD%^"+
      "%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e%^RESET%^s "+
      "%^RESET%^%^ORANGE%^banking their sprays of "+
      "delicate %^BOLD%^%^WHITE%^petals %^RESET%^%^ORANGE%^and glistening "+
      "%^BOLD%^%^GREEN%^leaves %^RESET%^%^ORANGE%^along the columns.  "+
      "The open %^YELLOW%^trellis %^RESET%^%^ORANGE%^roof peeks "+
      "out from the bountiful %^GREEN%^vines%^RESET%^%^ORANGE%^, letting in dappled "+
      "%^YELLOW%^s%^RESET%^%^ORANGE%^u%^YELLOW%^n%^RESET%^"+
      "%^ORANGE%^l%^YELLOW%^i%^RESET%^%^ORANGE%^g%^YELLOW%^h"+
      "%^RESET%^%^ORANGE%^t %^RESET%^%^ORANGE%^to create a warm "+
      "%^YELLOW%^glow %^RESET%^%^ORANGE%^within, "+
      "while the open sides allow fragrant %^BOLD%^%^MAGENTA%^"+
      "b%^YELLOW%^l%^WHITE%^o%^MAGENTA%^s%^YELLOW%^s%^WHITE%^o"+
      "%^MAGENTA%^m%^YELLOW%^s %^RESET%^%^ORANGE%^from the nearby "+
      "oleander trees to float daintily to the floor.  "+
      "Lining the gazebo are three rows of %^YELLOW%^benches"+
      "%^RESET%^%^ORANGE%^, all facing the raised %^YELLOW%^"+
      "platform %^RESET%^%^ORANGE%^along the northern wall "+
      "where ceremonies are often held.  Flanking the dais "+
      "on either side are beautiful marble statues of %^BOLD%^"+
      "%^WHITE%^winged angels%^RESET%^%^ORANGE%^, each one "+
      "with its slender hands gracefully pressed together in "+
      "front of its chest while its head is bowed as if in "+
      "prayer.  An opening in the railing to the south allows "+
      "admittance into the gazebo, and a small family of "+
      "s%^RESET%^p%^ORANGE%^a%^RESET%^r%^ORANGE%^r%^RESET%^o"+
      "%^ORANGE%^w%^RESET%^s %^ORANGE%^has built a %^YELLOW%^"+
      "nest %^RESET%^%^ORANGE%^in the %^BOLD%^%^GREEN%^ivy "+
      "%^RESET%^%^ORANGE%^just above the entryway.%^RESET%^\n");
   set("night long","%^BOLD%^%^WHITE%^Inside the Gazebo, Seneca%^RESET%^\n"+
      "%^BLUE%^Oval in shape, this beautiful gazebo "+
      "provides a warm, inviting atmosphere while its size allows "+
      "for weddings and other joyous occasions.  A low "+
      "slatted %^ORANGE%^railing %^RESET%^"+
      "%^BLUE%^topped by wooden archways rises all around, "+
      "flourishing %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a"+
      "%^BOLD%^%^WHITE%^s%^RESET%^m%^BOLD%^%^GREEN%^"+
      "i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e %^RESET%^v%^BOLD%^"+
      "%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e%^RESET%^s "+
      "%^RESET%^%^BLUE%^banking their sprays of "+
      "delicate %^BOLD%^%^WHITE%^petals %^RESET%^%^BLUE%^and glistening "+
      "%^BOLD%^%^GREEN%^leaves %^RESET%^%^BLUE%^along the columns.  "+
      "The open %^YELLOW%^trellis %^RESET%^%^BLUE%^roof peeks "+
      "out from the bountiful %^GREEN%^vines%^RESET%^%^BLUE%^, letting in dappled "+
      "%^RESET%^m%^BOLD%^o%^RESET%^o%^BOLD%^n"+
      "%^RESET%^l%^BOLD%^i%^RESET%^g%^BOLD%^h%^RESET%^t %^BLUE%^"+
      "to create a glistening %^BOLD%^%^WHITE%^radiance %^RESET%^%^BLUE%^within, "+
      "while the open sides allow fragrant %^BOLD%^%^MAGENTA%^"+
      "b%^YELLOW%^l%^WHITE%^o%^MAGENTA%^s%^YELLOW%^s%^WHITE%^o"+
      "%^MAGENTA%^m%^YELLOW%^s %^RESET%^%^BLUE%^from the nearby "+
      "oleander trees to float daintily to the floor.  "+
      "Lining the gazebo are three rows of %^YELLOW%^benches"+
      "%^RESET%^%^BLUE%^, all facing the raised %^YELLOW%^"+
      "platform %^RESET%^%^BLUE%^along the northern wall "+
      "where ceremonies are often held.  Flanking the dais "+
      "on either side are beautiful marble statues of %^BOLD%^"+
      "%^WHITE%^winged angels%^RESET%^%^BLUE%^, each one "+
      "casting a soft %^RESET%^moonlit glow %^BLUE%^as it stands "+
      "with its slender hands gracefully pressed together in "+
      "front of its chest while its head is bowed as if in "+
      "prayer.  An opening in the railing to the south allows "+
      "admittance into the gazebo, and a small family of %^ORANGE%^"+
      "s%^RESET%^p%^ORANGE%^a%^RESET%^r%^ORANGE%^r%^RESET%^o"+
      "%^ORANGE%^w%^RESET%^s %^BLUE%^has built a %^YELLOW%^"+
      "nest %^RESET%^%^BLUE%^in the %^BOLD%^%^GREEN%^ivy "+
      "%^RESET%^%^BLUE%^just above the entryway.%^RESET%^\n");
/*
Old description below - preserving because I can :P
@DESC
A few pink petals from surrounding dogwood trees drift through 
the trellised white sides of the gazebo and land around you.  
The gazebo has been designed to allow lots of sunlight through 
and has open panels on the roof. There are several rows of 
benches and a raised platform at the far end. Two statues of 
angels stand on either side of the platform and peer into the room.  
Sprigs of flowering ivy hang down from the boards of the ceiling, 
hiding its true height when you gaze across it. A family of 
sparrows has built a nest in some of the ivy just above you.
DESC
*/
   set_smell("default","The bountiful aroma of flowers masks the "+
      "clean scent of the ocean.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_exits(([
      "south" : ROOMS"garden1"
   ]));
   set_items(([
      ({"railing","archway","archways","wooden archways"}) : 
         "%^ORANGE%^The wooden railing running around the gazebo "+
         "stands approximately three feet high.  The top of the "+
         "railing has been sanded and varnished, and it supports "+
         "the wooden slats running vertically beneath it.  Rising "+
         "from the railing at intervals are square wooden columns "+
         "covered with climbing vines.%^RESET%^",
      ({"column","columns"}) : "The square columns are mostly "+
         "hidden by the thick vines clinging to them.  They rise "+
         "from the railing to help form the curving arches that "+
         "support the trellis roof.",
      ({"vine","vines","jasmine","jasmine vines"}) : "%^GREEN%^The "+
         "flourishing vines of jasmine climb from the %^BOLD%^"+
         "gardens%^RESET%^%^GREEN%^, wrapping themselves almost "+
         "tenderly around the columns and winding among the "+
         "slats of the trellis roof overhead.  Each jasmine "+
         "blossom has six delicate %^RESET%^s%^BOLD%^i%^RESET%^l"+
         "%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^w"+
         "%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e petals %^RESET%^"+
         "%^GREEN%^nestled among the vibrant %^BOLD%^green "+
         "leaves%^RESET%^%^GREEN%^.%^RESET%^",
      ({"trellis","roof","trellis roof"}) : "High overhead, "+
         "finished boards have been turned to stand on their "+
         "narrow sides and placed several inches apart to allow "+
         "plenty of room for the jasmine to flourish.  An "+
         "added benefit is that the openings allow delicate light "+
         "to filter through, illuminating the gazebo naturally.",
      ({"blossom","oleander blossom","blossoms","oleander blossoms"}) :
         "Cascading through the gazebo are fragrant %^BOLD%^"+
         "%^MAGENTA%^o%^YELLOW%^l%^WHITE%^e%^MAGENTA%^a%^YELLOW%^n"+
         "%^WHITE%^d%^MAGENTA%^e%^YELLOW%^r %^WHITE%^b%^MAGENTA%^l"+
         "%^YELLOW%^o%^WHITE%^s%^MAGENTA%^s%^YELLOW%^o%^WHITE%^m"+
         "%^MAGENTA%^s%^RESET%^, each one a delicate creation "+
         "of five soft petals arranged around a fringed center.  "+
         "A pleasant mixture of %^YELLOW%^yellow%^RESET%^, "+
         "%^BOLD%^%^MAGENTA%^pink%^RESET%^, and %^BOLD%^white "+
         "%^RESET%^blossoms can often be found on the floor here.",
      ({"bench","benches","rows","rows of benches"}) : "Three rows "+
         "of narrow benches line all sides of the gazebo save the "+
         "north.  They stop a few feet shy of the northern "+
         "platform, giving participants in ceremonies plenty of "+
         "room.",
      ({"platform","raised platform","dais"}) : "%^ORANGE%^A "+
         "slender stair running the width of the gazebo leads "+
         "up to the low platform in the north.  The platform is "+
         "wide enough for participants to stand easily no matter "+
         "what candleabra or sprays of flowers might be added.%^RESET%^",
      ({"statues","statue","angels","winged angels","angel","marble statues"}) :
         "%^BOLD%^Carved from marble and bracing the platform "+
         "to the north are two nearly identical statues.  Each "+
         "is of a slender angel dressed in a simple, flowing robe "+
         "belted at the waist.  Feathery wings spread outward "+
         "from each angel's back, creating a sense of balance "+
         "to the statues.  Each angel stands with head bowed, "+
         "chin inches above the delicate hands pressed together "+
         "in an attitude of prayer.%^RESET%^",
      "opening" : "The opening to the south is braced with "+
         "columns that rise floor-to-ceiling and leads out onto "+
         "the sandy pathway beyond.",
      ({"sparrows","nest","family","family of sparrows"}) :
         "Just peeking out from the jasmine above the doorway "+
         "to the south is the brownish nest of a family of "+
         "sparrows.  From time to time one of the brownish "+
         "gray birds can be seen, and you can often hear the "+
         "chirping of chicks.",
      "floor" : "The floor here is made of smooth wooden planks "+
         "well-fitted together.  A light dusting of oleander "+
         "blossoms add a touch of color to the otherwise plain "+
         "wood."
   ]));
}
