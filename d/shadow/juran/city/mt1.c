#include <std.h>
#include "../juran.h"

inherit ROOM;

void create(){
    	::create();
    	set_short("%^BOLD%^%^BLACK%^Meeting room of the Dark Magi%^RESET%^");
     	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
   	set_long(query_short() + "\n" +
"%^MAGENTA%^You enter a large room with a few rough hewn round %^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^a%^ORANGE%^b%^BOLD%^%^BLACK%^le%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^,%^RESET%^%^MAGENTA%^ some strangely designed %^BOLD%^%^BLACK%^ch%^RESET%^%^ORANGE%^a%^ORANGE%^i%^BOLD%^%^BLACK%^rs, %^RESET%^%^WHITE%^s%^WHITE%^p%^BOLD%^%^BLACK%^ider %^BLACK%^web%^RESET%^%^WHITE%^s%^MAGENTA%^ hanging about, and various %^ORANGE%^r%^ORANGE%^e%^ORANGE%^m%^BOLD%^%^BLACK%^nan%^RESET%^%^ORANGE%^t%^ORANGE%^s%^MAGENTA%^ of used spell components on the ground. The %^ORANGE%^w%^ORANGE%^a%^BOLD%^%^BLACK%^lls%^RESET%^%^MAGENTA%^ are of the common gray stone used throughout the tower, but they are covered with mystical %^ORANGE%^p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^ings%^RESET%^%^MAGENTA%^ and tapestries depicting scenes of magic and mysticism. Many of the %^BOLD%^%^BLACK%^paint%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^g%^ORANGE%^s%^MAGENTA%^ and tapestries have burn marks as if deadly wizardry was used in this room. This room is generally used as a meeting place for all users of magic to discuss their uses and ways of manipulating spells and with the burn marks it seems they have not always agreed. A darkly shimmering portal leads out to the south, a store lies to the north and a staircase leads upward to the next floor.");
    	set_property("light",-2);
    	set_property("indoors",1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_items( ([
        	({"tables","round tables"}):"Around the room, there "+
            	"are four large rough hewn round tables with various types of "+
            	"chairs around them.  The tables don't take up more "+
            	"than half of the large room, but still are big enough "+
            	"to provide seating for any mage who wants it.  Across "+
            	"the table, there are a few burn marks from a few "+
            	"poorly planned spell demonstrations, and blood from "+
            	"others.",
        	({"chairs","strangely designed chairs","strange chairs"}):
            	"Many chairs surround the large tables.  You can judge "+
            	"that there are at least fifty of them, all from "+
            	"different origins, thus differing styles.  Some "+
            	"resemble dragons, others use flowing sweeps of wood "+
            	"to give an enchanting appearance to it.  Such a "+
            	"collection of chairs gives the room a unique and "+
            	"mystical appearance.",
        	({"spiderwebs","spider webs","cobwebs","cob webs"}):"Spider "+
            	"webs hang near the corners of the ceiling.",
        	({"remnants","spell components","ground","down","floor"}):
            	"Useless scraps of spell components coat the ground.  "+
            	"It is obvious that much spell casting goes around "+
            	"here.",
        	({"walls","wall","stone","gray stone"}):"The walls are "+
            	"made of a cold and featureless gray stone, but are "+
            	"covered with paintings, tapestries, the "+
            	"bulletin board, and more than a few burn marks.",
        	({"paintings","painting","tapestry","tapestries",
            	"mystical paintings","mystical painting"}):"Tapestries "+
            	"and paintings show various scenes of the many forms of "+
            	"magic in ShadowGate.  Many pictures are of powerful "+
            	"and feared magi casting fantastic and complex spells, "+
            	"while others show dragons, undead armies, and various "+
            	"legendary artifacts."
    	]) );
    	set_exits( ([
        	"portal" : JROOMS+"a9",
        	"store" : JROOMS+"cmp",
        	"up" : JROOMS+"mt2"
    	]) );
    	set_smell("default","You smell the charred remains of magical "+
        	"demonstrations scattered over the floor.");
    	set_listen("default","You can hear discussion of magic and "+
        	"adventure between mages.");
}
