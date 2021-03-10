#include "../tomb.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("%^BOLD%^%^BLUE%^G%^WHITE%^r%^BLUE%^ave %^WHITE%^D%^WHITE%^e%^BLUE%^al%^WHITE%^s%^WHITE%^, %^BLUE%^Trad%^BLUE%^i%^BLUE%^ng %^BLUE%^Comp%^BLUE%^a%^BLUE%^n%^BLUE%^y%^RESET%^");
    set_long(query_short()+"
%^BOLD%^%^BLACK%^This chamber is featured with multiple stone %^RESET%^%^BLUE%^sh%^WHITE%^e%^BLUE%^lv%^WHITE%^e%^WHITE%^s%^BOLD%^%^BLACK%^ on its sides filled with various %^RESET%^%^BLUE%^go%^WHITE%^o%^BLUE%^ds.%^BOLD%^%^BLACK%^ The space is scarce, several ladders lean onto shelves, and single %^RESET%^%^WHITE%^m%^WHITE%^a%^WHITE%^ge%^WHITE%^l%^WHITE%^i%^WHITE%^ght%^BOLD%^%^BLACK%^ illuminates the spot. In the middle lies a %^RESET%^%^BLUE%^s%^WHITE%^l%^WHITE%^a%^BLUE%^b%^BOLD%^%^BLACK%^ that serves as a counter, iron safe on the side of it. There is nothing else in this room.%^RESET%^
");
    set_smell("default","%^CYAN%^A smell of dry goods, old antiques.");
    set_listen("default","%^WHITE%^Humming noise of a busy night in the necropolis.");
    set_items(([
                   ({"shelves","goods"}):"%^BOLD%^%^BLUE%^The variety is staggering, but it is mostly junk and house supplies. Few items, however, can be used in your adventuring life.",
                   "magelight":"A simple light spell stuck into place with permanency enchantment.",
                   "save":"A huge steel safe with thick walls.",
                   ({"slab","counter"}):"%^BOLD%^%^BLACK%^Fine cut rectangular granite slab that serves a counter."
                   ]));
    set_exits(([
                   "west":ROOMS+"/tomb2",
                   ]));
}

void reset()
{
    ::reset();
    if(!present("kapriz"))
    {
        find_object_or_load(MONS+"/kapriz")->move(TO);
    }
}
