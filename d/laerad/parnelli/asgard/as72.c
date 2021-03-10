
//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

//inherit ASGARD;

inherit "/std/church";

void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Asgard's Church");
    set_short("Asgard's Church");
/*
    set_long(
	"%^BOLD%^Asgard Church%^RESET%^
You have walked into a fantastic old church.  The room is enormous with rows "+
	"of oak benches lining the center of the church.  There is a shrine "+
	"at the front of the room made of ivory, marble, silver and gold.  "+
	"A few crosses decorate the shrine and a small fountain pours "+
	"holy water into a pool at the bottom of it.  The windows are stained "+
	"glass and look centuries old.  A massive chandelier lights the room "+
	"and huge pillars reach 30 feet up to the ceiling."
    );
*/
   set_long("%^BOLD%^Asgard Church%^RESET%^
%^ORANGE%^Amid the rubble of the city, the church has sustained damage, but it has not been abandoned. The enormous room is filled with rows of oak benches, some of which have been crushed beneath the weight of the southern wall, which has fallen. Despite the collapsed section of the roof, much of the area is still protected from the elements. A shrine at the front of the room is made of ivory, marble, silver, and gold and features a pool at the bottom that is filled from a fount of holy water. Many of the windows have been smashed, but the few stained glass creations that remain intact look to be centuries old. A massive chandelier in the center of the room provides illumination for those few still huddled here, helping the needy.\n");
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The church smells of incense.");
    set_listen("default","You can hear a few people sitting at the benches in prayer.");
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as67"
    ]) );
}
