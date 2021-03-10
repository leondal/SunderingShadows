#include <std.h>
#include "../argabbr.h"

inherit ROOM;

void create(){
        ::create();
        set_property("light",3);
        set_name("Argentrock Shore");
        set_short("Argentrock Shore");
        set_terrain(BEACH);
        set_travel(FRESH_BLAZE);
        set_long( "%^BOLD%^%^GREEN%^Argentrock Shore%^RESET%^
%^BOLD%^%^BLACK%^You are climbing along the steep rocky shore of argentrock island. Waves crash against the jutting %^WHITE%^rocks%^BLACK%^ making the area slick and sharp. The terrain makes each step a struggle to keep your balance and avoid tumbling down into the %^BLUE%^sea%^BLACK%^. The thick argentrock %^GREEN%^forest%^BLACK%^ can be seen high up above the unforgiving rocks of the shore.");
        set_smell("default","You smell salty sea water.");
        set_listen("default","The ocean crashes against the rocks.");
        set_items( ([ 
        ({"rocks","shore"}):"The rocks are black and slick from sea water.",
        ({"sea"}):"The sea looks dark and mysterious.",
        ({"forest"}):"The thick forest looms above.",
        ]) );
}

/* int GoThroughDoor() { */
/*    if(!userp(TP)) return 1; */
/*         if(avatarp(TP) && TP->query_invis() || TP->query_property("flying")) return 1; */
/*         if(!"/daemon/saving_throw_d.c"->reflex_save(TP,-35)) { */
/*           tell_room(ETP,TPQCN+" slips and falls on a sharp rock.", TP); */
/*           tell_object(TP,"%^ORANGE%^You slip and cut yourself on a sharp rock\n"+ */
/*           "%^RED%^The rocks cut into your skin deeply."); */
/* 	 TP->cause_typed_damage(TP,0,roll_dice(1,6)+10,"piercing"); */
/* 	 } */
/* 	 if(!"/daemon/saving_throw_d.c"->reflex_save(TP,-30)) */
/*     { */
/*         tell_object(TP,"%^BLUE%^You sink quickly and disappear into the water!"); */
/*         tell_room(TO,"%^BLUE%^"+TPQCN+" sinks quickly into the water and disappears!",TP); */
/* 		TP->cause_typed_damage(TP,0,roll_dice(1,4),"piercing"); */
/*         TP->move("/d/islands/argentrock/inherit/sea"); */
/*         return 0; */
/*     } */
/*     write("%^CYAN%^You are glad you catch yourself before falling into the sea."); */
     
/*    return 1; */
/* } */
/* void init(){ */
/*   ::init(); */
/*   GoThroughDoor(); */
/*   return; */
/* } */

/* string ldesc(string str) { */
/*    return("%^BOLD%^%^BLACK%^Rocky Shore\n" */


/*      "%^BOLD%^%^BLACK%^You are climbing along the "+ */
/* 	 "steep rocky %^RESET%^shore%^BOLD%^%^BLACK%^ of argentrock island. "+ */
/* 	 " Waves crash against the jutting rocks "+ */
/* 	 "making the area slick and sharp.  The "+ */
/* 	 "terrain makes each step a struggle to keep "+ */
/* 	 "your balance and avoid tumbling down into"+ */
/* 	 " the %^RESET%^sea%^BOLD%^%^BLACK%^.  The thick argentrock %^RESET%^forest "+ */
/* 	 "%^BOLD%^%^BLACK%^can be seen high up above the unforgiving rocks of the shore."); */
/* } */
