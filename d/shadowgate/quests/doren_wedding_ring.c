//Doren Wedding Ring - Githyanki Fortress - LoKi - 12-02-2008

#include <std.h>

inherit "std/quest_ob";


void create() {
    set_name("doren wedding ring");
    set_id( ({ "doren wedding ring","Isolated the Githyanki","thin golden ring","quest_object","ring"}) );
    set_short("%^RESET%^%^YELLOW%^th%^RESET%^%^ORANGE%^i%^RESET%^%^YELLOW%^n gol"+
"de%^RESET%^%^ORANGE%^n%^RESET%^%^YELLOW%^ r%^RESET%^%^ORANGE%^i%^RESET%^%^YELLOW"+
"%^ng%^RESET%^");
    set_long("%^RESET%^%^YELLOW%^A thin band of g%^RESET%^%^ORANGE%^o%^RESET%^"+
"%^YELLOW%^ld, excellently crafted and polished to a mirror shine. On the inside"+
" of the ring is an engraving of '%^RESET%^%^WHITE%^All my Love - Shannon'%^RESET%^"+
"%^YELLOW%^. This would obviously have more sentimental value then anything a shop"+
" keeper would offer.%^RESET%^");
    set_quest_points(20);

}
