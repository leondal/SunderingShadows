#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "north" : ROOMS + "path6"]));
  add_item( ({"jungle", "trees", "tree"}), "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
    +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^to the south"
    +" is thick with trees, and there is no practical way through. The trees are"
    +" draped with vines and creepers, and the undergrowth is too thick to be"
    +" passable.");  
}

long_desc(){
  string desc;
  desc =  ::long_desc();
  desc += "To the south, a dense growth of %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
   +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^ blocks the"
   +" path. You can't go any further that way.";
  return desc;
}