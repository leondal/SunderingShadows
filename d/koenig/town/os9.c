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
  set_long("%^RESET%^%^GREEN%^You are standing in the southwest corner of the grounds. Looking to the east "+
"from where you stand you can see %^BOLD%^%^RED%^rose bushes%^RESET%^%^GREEN%^ lining most the fence and a "+
"large %^BOLD%^%^BLACK%^misshapen tree%^RESET%^%^GREEN%^ of some kind. You notice a %^BOLD%^bush%^RESET%^%^GREEN%^ behind you that has "+
"been trimmed into the form of what appears to be a Tyrannosaurus Rex. You can almost "+
"imagine it reaching down with its gaping jaws full of teeth to snatch its prey. Thank your lucky stars its only a bush.%^RESET%^\n");
  set_smell("default","You can smell the sweet fragrance of roses."); 
  set_listen("default","You can hear the faint keening of someone calling for help.");
  set_items( ([
     "bushes":"There are several different rose bushes...each a different color but each color always seems to have a tint of red in it.",
     "bush":"This bush stands at the least 20 feet tall and looks very much "+
            "like the original predatory nightmare, the Tyrannosaurus Rex. You can really "+
            "imagine it reaching down with its jaws and snatching you up for "+
            "a mid-afternoon snack. There appears to be something hidden in "+
            "its center."
]) );
  set_exits( ([
     "east":"/d/koenig/town/os10",
     "north":"/d/koenig/town/os8"
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
    tell_room(environment(TP),TPQCN+" searches the bush but finds nothing.",TP);
    tell_object(TP,"You search the bush but find nothing.");
    return 1;
}
    chest_wait = 1;
      new("/d/koenig/town/items/bushchest.c")->move(this_object());
    tell_room(environment(TP),TPQCN+" searches the bush and finds something.",TP);
    tell_object(TP,"You search the bush and find a chest.");
    return 1;
}

void reset()
{
  ::reset();
    if(chest_wait != 0)
       chest_wait--;
}
