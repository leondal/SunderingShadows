#include "../../undead.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Within the Castle de Boquillas");
    set_short("%^BOLD%^%^WHITE%^Within the Castle de Boquillas");
    set_long("%^BOLD%^%^WHITE%^You stand within the Castle de Boquillas.\n"
"%^RESET%^%^ORANGE%^This is perhaps the %^BLUE%^darkest room %^ORANGE%^within "
"this otherwise well-lit cathedral building.  No windows brighten the room, "
"leaving its %^BOLD%^%^WHITE%^alabaster-white %^RESET%^%^ORANGE%^walls to be "
"lit only by the flickering flames of a few candles.  Instead, the walls are "
"lined with filled bookcases, aged and worn from use.  In the corner you see a "
"very plain and simple bed made of %^YELLOW%^straw%^RESET%^%^ORANGE%^.  This "
"meagre abode actually serves as the residence of the Bishop of Graez, ruler of "
"what remains of the city.\n%^RESET%^");
    set_smell("default","The faint smell of incense hangs in the air.");
    set_listen("default","It is very quiet here.");
    set_exits(([
      "south":TOWN"church1",
    ]));
    set_pre_exit_functions(({"south"}),({"go_south"}));

    set_items(([
      ({"church","cathedral","walls","castle"}): "%^ORANGE%^The pale "
"%^BOLD%^%^WHITE%^alabaster-hued %^RESET%^%^ORANGE%^walls of the Castle de "
"Boquillas lie in deep shadow, here in this dark room.%^RESET%^",
      ({"candles","flames"}): "%^ORANGE%^Only the flickering flames of a few "
"candles allows anything to be seen in this %^BLUE%^dark "
"room%^ORANGE%^.%^RESET%^", 
      ({"books","bookcases"}): "%^ORANGE%^Heavy bookcases line the walls of "
"this %^BLUE%^dark room%^ORANGE%^.  Many %^RESET%^books %^ORANGE%^line the "
"shelves of each, all aged and worn from long use.%^RESET%^",
      "bed": "%^ORANGE%^A simple bed of %^YELLOW%^straw %^RESET%^%^ORANGE%^lies "
"on the ground in the corner.%^RESET%^",
    ]));
}

void reset() {
    ::reset();
    if(!present("bishop"))
        find_object_or_load(MON"bishop")->move(TO);
}

int go_south() {
    if(present("morock")) {
      tell_object(TP,"%^BOLD%^%^RED%^Get back here "+TP->QCN+", I'm not done "
"with you yet!%^RESET%^");
      return 0;  
    }
    return 1;
}
