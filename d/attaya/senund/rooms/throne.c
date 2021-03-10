#include <std.h>
#include "../areadefs.h"
inherit VAULT;

void create()
{

        ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light",2);
    set_property("no teleport",1);
    set_name("Throne Room");
    set_short("Throne Room");
    set_long(
@BRUENOR
%^BOLD%^%^CYAN%^Throne Room%^RESET%^
You wander into a modest sized room. %^BOLD%^%^BLUE%^Banners%^RESET%^ adorned with unrecognized
symbols line the walls.  From the ceiling hangs a %^BOLD%^%^CYAN%^chandelier%^RESET%^ bathing 
the room in a dim light.  The floor is once again covered in %^RED%^red carpet%^RESET%^,
though this time the carpet is actually somewhat clean.  Against the
back wall is a small %^YELLOW%^throne%^RESET%^.  Atop the throne is a rough looking man
who glares at you for entering.  
BRUENOR
    );
    set_items( ([ "walls": "The wall is a sheet of solid stone.",
       "carpet": "The carpet is a rather nice red felt carpet.",
       "torches": "The torches burn dimly in the dark. They do not "+
       "seem to be burning away the wood though.",
       "chandelier": "The chandelier is an old crystal one, it "+
       "still rather sparkly though.",
       "ceiling": "The ceiling is rather low and is carved out of "+
       "the rock itself." ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_door("oak door",ROOMS+"rm34","east",0);
    set_door_description("oak door","This door is made of polished "+
                         "oak, it is rather nice especially considering "+
                         "where you are right now.");
    set_string("oak door","open","The heavy door swings open.");
    set_exits(
    ([
        "east" : ROOMS+"rm34"
    ]) );

}

void reset()
{
  ::reset();
  if(!present("gambrill")) {
  new(MON+"gambrill.c")->move(TO);
  }
}
