//Coded by Lujke

#include <std.h>
#include "../tecqumin.h"
inherit OBJECT;

string start_point;

void create() {
    ::create();
    set_name("Transporter");
    set_id( ({"transporter","ooc item","strange ooc item" }) );
    set_short("");
    set_weight(0);
    set_property("no steal", 1);
    set_property("no drop", 1);
    set_long( "This is a special item to take a PC to a test area for"
      +" Lujke. Both the item and the area are OOC at the moment. Don't"
      +" be using them to get out of PK or other IC situations. You can"
      +" use it to 'transport in' to or 'transport out' of the test"
      +" area." );
}

void init(){
  ::init();
  add_action("transport_me", "transport");
}

int transport_me(string str){
  object room;
  if (!objectp(ETO) || !interactive(ETO)){
    return 0;
  }
  if (str  == "in"){
    if (objectp(EETO) && !interact("lujke", base_name(EETO))){
      start_point = file_name(EETO);
    }
    room = find_object_or_load("/realms/lujke/tecqumin/test/start");
    if (objectp(room)){
      tell_object(ETO, "You head off to the %^CYAN%^Tecqumin%^RESET%^ test area");
      tell_room(EETO, ETO->QCN + " disappears in an OOCly manner", ETO);
      tell_room(room, ETO->QCN + " appears in an OOCly manner", ETO);
      ETO->move(room);
      ETO->force_me("look");
      return 1;      
    }
  }
  if (str == "out"){
    room = find_object_or_load(start_point);
    if (objectp(room)){
      tell_object(ETO, "You go back to where you started from");
      tell_room(EETO, ETO->QCN + " disappears in an OOCly manner", ETO);
      tell_room(room, ETO->QCN + " appears in an OOCly manner", ETO);
      ETO->move(room);
      ETO->force_me("look");
      start_point = "";
      return 1;
    } else {
      tell_object(ETO, "There was a problem with the room you came from. I'm afraid you will probably need an Imm's help to get out");
      return 1;
    }
  }
  tell_object (ETO, "Try 'transport in' or 'transport out'");
  return 1;
}
