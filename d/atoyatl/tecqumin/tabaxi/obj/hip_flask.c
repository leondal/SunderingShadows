//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;
int draughts;


void create() {
    ::create();
    set_name("hip flask");
    set_id( ({"flask", "hip flask", "silver flask", "silver hip flask", "drink" }) );
    set_short("%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lver hip fl%^RESET%^a%^BOLD%^%^WHITE%^sk%^RESET%^");
    set_weight(2);
    set_long( "A primitive, but carefully crafted silver hip flask. It bears symbols in the"
             +" script of the Tecqumin." );

    draughts = 15;
}

void init(){
  ::init();
  add_action("drink", "drink");
}

int drink(string str){
  object swig;
  if (!objectp(ETO)||!living(ETO)){
    return 0;
  }
  if (!id(str)){
    return 0;
  }
  if (present("drink", ETO)!=TO){
    return 0;
  }
  if (objectp(EETO)){
    tell_room(EETO, (string)ETO->QCN + " takes a swig from " + (string) ETO->QP + " "+ query_short(), ETO);
  }
  tell_object(ETO, "You take a swig from your " + query_short());
  swig = new ("/std/drink");

  swig->set_type("alcoholic");
  swig->set_strength(25);
  swig->set_weight(1);
  swig->set_short("A swig of harsh liquor");
  swig->set_my_mess("Your throat burns as you take a swig of the harsh liquor");
  swig->set_your_mess("shudders briefly as they swallow some kind of liquor.");
  swig->move(ETO);
  swig->set_id(({"drink", "swig"}));
  ETO->force_me("drink drink");  
  return 1;
}