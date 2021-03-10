#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_short("%^BOLD%^%^GREEN%^A strange hole");
    set_long(query_short() + "%^RESET%^\n" +
      "%^ORANGE%^You come down to a %^CYAN%^hole%^ORANGE%^ shadowed by the giant tree.  "+
      "This area almost sparks with energy.  Several of "+
      "the %^CYAN%^roots%^ORANGE%^ are showing.  The %^CYAN%^hole%^ORANGE%^ seems to go down forever."+
      "  There is a %^CYAN%^memorial%^ORANGE%^ set against one of the roots"+
      " and the side of the hole.\n"
    );
    set_items( ([
     "roots" : "The roots of the giant oak are big enough to walk on",
      "hole" : "A powerful energy can be felt from "+
      "the hole; whatever happened here must have been epic.",
      "memorial" : "On this day Formday, 8 Autumnstime, 751 SG: \n"+
      "The four hearts of the elements combined to banish the "+
      "eternal night that had claimed our world.\n"+
      "We thank %^GREEN%^Jenna, Rheyn, Ramius and Singer%^RESET%^ for"+
      " bringing the elemental hearts together.\n"+
      "And the many who gave their lives to protect them during the ritual.",
    ]) );
    set_exits( ([
      "up" : "/d/shadow/room/city/cguild/ranger/rooms/path3",
    ]) );
    set_smell("default", "This place smells pure like the coming of dawn.");
    set_listen("default", "You can almost hear the voices of the divine here.");
}