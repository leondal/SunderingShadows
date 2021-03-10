#include <std.h>

inherit ROOM;


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(BARREN);
	set_travel(FRESH_BLAZE);
       set_short("%^ORANGE%^M%^BOLD%^y%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^ORANGE%^r%^WHITE%^i%^ORANGE%^o%^WHITE%^u%^RESET%^s %^ORANGE%^P%^BOLD%^l%^WHITE%^a%^RESET%^t%^YELLOW%^e%^BLACK%^a%^RESET%^%^ORANGE%^u%^RESET%^");
        set_long("
%^ORANGE%^M%^BOLD%^y%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^ORANGE%^r%^WHITE%^i%^ORANGE%^o%^WHITE%^u%^RESET%^s %^ORANGE%^P%^BOLD%^l%^WHITE%^a%^RESET%^t%^YELLOW%^e%^BLACK%^a%^RESET%^%^ORANGE%^u%^RESET%^
%^ORANGE%^You stand upon a %^RED%^pl%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^ea%^RESET%^%^RED%^u %^ORANGE%^high in the mountains of Aramanth Island. This is most likely a volcanic island with this %^RED%^pl%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^ea%^RESET%^%^RED%^u %^ORANGE%^being the surviving part of the cone. The %^WHITE%^gr%^BOLD%^ou%^RESET%^nd %^ORANGE%^up here is a thick layer of fine %^WHITE%^ash %^ORANGE%^and twenty foot %^WHITE%^walls %^ORANGE%^surround this crater. You get the feeling that if you walk around enough up here, you could find something. There are some stone %^BOLD%^archways%^RESET%^ to the north that whistle.
");
   set_listen("default", "The waves crashing against the beach far below carriesover the plateau and echoes off the walls.");
       set_exits(([
      "south" : "/d/islands/common/aramanth/room9",
       "west" : "/d/islands/common/aramanth/room5",
       "east" : "/d/islands/common/aramanth/room11",
]));
       set_items(([
    "walls" : "They are tall formations of natural rock that surround the crater.",
    "archways" : "They are natural formations on the island.",
    "ground" : "It is coated in a thick, black, crystalized ash.",
   "ash" : "The ash is a finely granulated crystaline powder.  It glistens oddly in the light.",
    "plateau" : "It is a volcanic crater high above sea level.  Four tall obelisks are placed around the perimeter.",
]));
	
set_pre_exit_functions( ({"north"}), ({"earwig_pit"}) );
set_pre_exit_functions( ({"south"}), ({"earwig_pit"}) );
set_pre_exit_functions( ({"west"}), ({"earwig_pit"}) );
set_pre_exit_functions( ({"east"}), ({"earwig_pit"}) );
}
int earwig_pit(){
if(present("earwig scorpion")) {
write("The Earwig Scorpion has you trapped!");
return 0;
  }
else return 1;
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/lostsoul.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/necrophidius.c", "/d/islands/common/mon/drowned.c", "/d/islands/common/mon/earwig.c"}),25,1);
}
