#include <std.h>
inherit ROOM;

int chest_wait;

void create()
{
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors",0);
  set_short("The Tower Courtyard");
  set_long("%^RESET%^%^GREEN%^You are standing in the northeast corner of the grounds. Looking to the west "+
"from where you stand you can see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining the fence. They are "+
"very thick. You notice a large %^BOLD%^bush%^RESET%^%^GREEN%^ behind you that has been trimmed into "+
"the form of a very large bear. It makes you think of a grizzly standing on "+
"its hind legs and looking angry, not to mention hungry. Bet you are glad it's "+
"only a bush.%^RESET%^\n");
  set_smell("default","You can smell the sweet fragrance of roses."); 
  set_listen("default","You can hear the faint keening of someone calling for help.");
  set_items( ([
     "bushes":"There are several different rose bushes. Each is a different color, but each color always seems to have a tint of red in it.",
     "bush":"This bush stands about 15 feet tall and looks very much like a "+
            "grizzly standing on its hind legs - only bigger. When the wind "+
            "blows through its leaves it looks like it is breathing, and the "+
            "rustling of its branches almost sounds like a very low, "+
            "ominous growl. There appears to be something hidden inside "+
            "it.",
]) );
  set_exits( ([
     "west":"/d/koenig/town/os3",
     "south":"/d/koenig/town/os1"
]) );
  chest_wait = 0;
}

void init()
{
  ::init();
    add_action("search","search");
}

int search(string str)
{
    object bush;
    if(str != "bush" || chest_wait != 0)
    return 0;
    if(present("chest",TP))
{
    tell_room(environment(TP),TPQCN+" searches the bush but finds nothing.");
    tell_object(TP,"You search the bush and find nothing.",TP);
    return 1;
}
    chest_wait = 1;
      new("/d/koenig/town/items/bushchest.c")->move(this_object());
    tell_room(environment(TP),TPQCN+" searches the bush and finds something.",TP);
    tell_object(TP,"You search the bush and find a hidden chest.");
    return 1;
}

void reset()
{
    if(chest_wait != 0)
       chest_wait--;
}
