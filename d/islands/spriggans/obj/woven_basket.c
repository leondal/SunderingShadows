#include <std.h>
#include <move.h>

inherit BAG;

void create(){
  ::create();
  set_id(({"basket","herb basket","woven basket","small woven basket"}));
  set_name("small woven basket");
  set_short("a small woven basket");
  set_weight(5);
  set_long("This simple basket has been woven from dried "+
     "vines.  It is fitted with a lid that may be held "+
     "closed with a stick thrust through a carefully crafted "+
     "flap.  You could put items inside, but it looks as "+
     "thought it would hold only small, light objects.  "+
     "It should probably be used only for the vines the "+
     "aarakocra requested and be given back to him when you "+
     "finish your task.");
  set_max_internal_encumbrance(20);
}

int item_allowed(object item) {
    if(item->is_healing_vine()){
       return 1;
    }else{
       tell_object(ETO,"This basket is meant for ayahuasca vines only!");
       return 0;
    }
}
