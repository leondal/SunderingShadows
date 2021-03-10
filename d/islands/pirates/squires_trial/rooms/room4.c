#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 4");
  set_short("A carved tunnel");
  set_long( 
  
            "It is utterly " + 
            "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
            "You are crossing a two foot "+
            (string) TO->marbledstone() +
            " walkway over a dark " +
            "pit, the bottom of which cannot be seen.  Very faint " +
            "cracking sounds emanate from the stone under your feet, " +
            "this is a very unsafe place to be!"
          );
          
  set_listen("default","Faint cracking sounds reach your ears.");
  set_smell("default","A faint odor of something rotting rises from the pit.");
          
  add_item(({"walkway","pathway","bridge","stone pathway"}),"The " +
          "stone bridge crosses the chasm, about two feet wide, and " +
          "although it appears it could hold some weight, it might be best" +
          " to cross quickly."
  );
  
  set_search("default","That doesn't seem like a very good idea right now!");
  
  set_exits(([
            "east" : SQUIREROOMS+"room3",
            "west" : SQUIREROOMS+"room5"
  ]));
}          


