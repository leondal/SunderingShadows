#include <std.h>
#include "../tomb.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_short("%^ORANGE%^S%^BOLD%^%^ORANGE%^pellwar%^RESET%^%^ORANGE%^d%^ORANGE%^e%^BOLD%^%^ORANGE%^n%^BLACK%^ of %^RESET%^%^ORANGE%^N%^ORANGE%^u%^ORANGE%^r%^BOLD%^%^ORANGE%^v%^RESET%^%^ORANGE%^a%^BOLD%^%^ORANGE%^l%^RESET%^");
   set_long(query_short()+"
%^BOLD%^%^BLACK%^This enormous round hall can't possibly be fit into allocated space. Around you, everywhere, endless shelves with ladders attached reaching the ceiling somewhere far in the darkness. Seven huge shelves converge in the center, forming entrance space and six rooms - scriptoriums - where a dozen or so of undead magi endlessly scribe new scrolls. Each scriptorium space is filled with writing tables and stands. The room is illuminated at the ground level but ceiling is lost in the darkness. In the entrance area stands a wooden counter, full of scrolls necropolis doesn't mind to sell.%^RESET%^
");
   set_smell("default","%^CYAN%^It smells of parchment.%^RESET%^");
   set_listen("default","%^BLUE%^You hear a quiet surling of parchment and quills.%^RESET%^");
   set_exits((["south":ROOMS+"/tomb5"]));
}

void reset()
{
    ::reset();
    if(!present("shiza"))
    {
        find_object_or_load(MONS+"/shiza")->move(TO);
    }
}
