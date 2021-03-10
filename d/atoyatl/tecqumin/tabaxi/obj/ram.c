#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;


void create() {
    ::create();
    set_name("myram");
    set_id( ({"xxramxx", "ram", "battering ram"}) );
    set_short("%^BOLD%^%^BLACK%^battering ram%^RESET%^");
    set_weight(400);
    set_long("This is a covered %^BOLD%^%^BLACK%^battering ram%^RESET%^. The ram itself is a huge"
            +" chunk of %^ORANGE%^hardwood t%^GREEN%^re%^ORANGE%^etr%^BOLD%^%^GREEN%^u"
            +"%^RESET%^%^GREEN%^n%^ORANGE%^k%^RESET%^. It sits inside a %^ORANGE%^wheeled"
            +" frame%^RESET%^, which has a sloping roof in the shape of an inverted V. The"
            +" %^ORANGE%^ram%^RESET%^ is suspended from the top of the frame by strong ropes with"
            +" enough play in them to allow the ram to swing back and forth. The %^BOLD%^%^BLACK%^roof"
            +" %^RESET%^is covered with thick, %^BOLD%^%^BLACK%^water soaked leather hides%^RESET%^"
            +" designed to offer protection to the operating crew who push the whole thing along the"
            +" ground until it is in place at its intended target. Once there, they swing the"
            +" %^ORANGE%^ram%^RESET%^ into whatever it is they want to %^BOLD%^%^BLUE%^batter%^RESET%^"
            +" down.");
    set_hidden(100000);
    reset_hidden_seen();
    set_no_clean(1);
}

void init(){
  ::init();
  add_action("enter", "enter");
    set_hidden(100000);
    reset_hidden_seen();
}

int enter(string str){
  object interior, * critters;
  int i, critts;
  if (!id(str)){
    tell_object(TP, "You can type %^BOLD%^%^BLUE%^'enter ram'%^RESET%^ to get into the"
                   +" %^BOLD%^%^BLACK%^battering ram%^RESET%^");
    return 0;
  }
  interior = find_object_or_load(TABAXOBJ + "ram_interior");
  if (!objectp(interior)){
    tell_object(TP, "There seems to be a problem with the ram interior. Please tell a Wiz. Preferably"
                   +" that silly fool %^BOLD%^%^GREEN%^Lujke%^RESET%^, who's doubtless broken it."
                   +" Failing that, make a bug report on the ram.");
    return 1;
  }
  critters = all_living(interior);
  if (sizeof(critters)>0){
    critts = 0;
    for (i=0;i<sizeof(critters);i++){
      if (!critters[i]->query_true_invis()){
        critts ++;
      }
    }
  }
  if (critts>3){
    tell_object(TP, "There doesn't appear to be enough room for you under the ram's cover");
    return 1;
  }
  tell_object(TP, "You duck under the cover of the %^BOLD%^%^BLACK%^battering ram%^RESET%^");
  tell_room(ETP, TPQCN + " %^RESET%^ ducks under the cover of the %^BOLD%^%^BLACK%^battering ram", TP);
  tell_room(interior, TPQCN + " enters");
  TP->move(interior);
  TP->force_me("look");
  return 1;
}
