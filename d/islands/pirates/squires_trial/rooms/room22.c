#include <std.h>
#include "../squires_trial.h"

inherit CHASMBASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 22");
  set_short("A carved tunnel");
  set_long( 
  
            "%^RESET%^%^BLUE%^" + 
            "The rock has changed here.  It is a brittle, sharp and " +
            "broken corridor.  A small stream flows through, probably " +
            "the reason for the vast crevasse.  Broken chips of stone " +
            "have collected over centuries and form a solid, but somewhat " +
            "crunchy bed.  There is a nasty mess of %^RESET%^%^WHITE%^g" +
            "n%^BOLD%^%^RED%^aw%^RESET%^%^WHITE%^ed " +
            "b%^BOLD%^%^RED%^o%^RESET%^%^WHITE%^n" +
            "%^BOLD%^%^RED%^e%^RESET%^%^WHITE%^s %^RESET%^%^BLUE%^of some" +
            " small creature laying here.  " +
            "This stone path leads to the east and southwest."
          );
  
  add_item("bones","%^BOLD%^%^WHITE%^These bones are mostly tossed into a single " +
                    "pile, gnawed clean by sharp teeth.  A small humanoid skull " +
                    "sits among them, shaped much like a goblin head.%^RESET%^");
  
  set_smell("default","The air stinks of rotting flesh and excrement.");
  set_exits(([
            "southwest" : SQUIREROOMS+"room21",
            "east" : SQUIREROOMS+"room23"
  ]));

}          

void reset(){
  ::reset();
  if(!present("injured goblin"))
		new(SQUIREMOBS"goblin")->move(TO);
}
