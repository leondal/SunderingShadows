#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_INT_BASE;


string long_desc();

void create() {
  
  ::create();
  set_short("vestibule");
  // set_items used deliberately in place of add_items, due to an apparant
  // problem with add_items using a function call. Lujke 29 June 2005
  set_items(  ([ "mirror" : (:TO, "look_mirror":) ]) );
  set_exits( ([ "out": ROOMS + "process_start" ]) );
}

string long_desc(){
    return "This is a small room, with three stone benches lined up"
          +" underneath some %^YELLOW%^br%^RESET%^%^ORANGE%^on"
          +"%^YELLOW%^ze%^RESET%^ hooks. The hooks themselves hang limply"
          +" from decayed wooden railings. A large %^ORANGE%^c%^RED%^o"
          +"%^ORANGE%^pp%^RED%^e%^ORANGE%^r%^RESET%^ mirror decorates the"
          +" wall opposite the railing.";
}

string look_mirror(){
  string descrip;
  descrip = "A large polished %^ORANGE%^c%^RED%^o%^ORANGE%^pp%^RED%^e"
           +"%^ORANGE%^r%^RESET%^ mirror, about two feet high by four"
           +" feet across. ";
  switch (TP->query_base_stats("charisma")){
  case 0..6: 
    descrip += "Fortunately the reflection is not all that clear, sparing"
              +" you the need to look too closely at your own ugly face";
    break;
  case 7..8:
    descrip += "The copper mirror is not all that clear. In the faint"
              +" blurring, you don't actually look all that bad.";
    break;
  case 9..12:
    descrip += "For a moment you are struck by how attractive your"
              +" reflection appears, but then you realise it's just that"
              +" the mirror is quite blurry";
    break;
  case 13..16:
    descrip += "In the rather soft focussed, slightly blurry surface of"
              +" the mirror, your reflection takes on an extra sense of"
              +" mystery and allure";
    break;
  default:
    descrip +="Sadly, the reflection is not quite clear enough to truly"
             +" highlight your appearance. Still, at least"
             +" %^BOLD%^%^CYAN%^you%^RESET%^ know how much better you"
             +" look than everyone else.";
    break;
  }
  return descrip;
}
