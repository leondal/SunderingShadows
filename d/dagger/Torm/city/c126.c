#include "../tormdefs.h"
inherit TOWN;
  object ob;
void create(){
  ::create();
  set_short(
   "Torm Magistrate's Office"
  );
  set_property("indoors",1);
  set_long(
  "  This hall seems sparse and bare, with all emphasis on the dark desk at the far end of the room."
 "  You almost feel guilty about something you can't quite remember as you enter this room where the people of this city are judged."
  );
  set_exits(([
  "east":TCITY+"c127",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
  "desk":"This large dark desk seems made of a wood that radiates coldness.  You wouldn't want to be a criminal standing in front of it awaiting judgement.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
/*void reset(){
  ::reset();
  if(!(query_night())){
   if(!present("vizier")) new(MON+"vizir")->move(this_object());
  return 1;
  }
   if(present("vizier")){
   ob=present("vizier");
   tell_room(environment(ob),"The vizier leaves.");
  ob->move("/d/shadowgate/void");
  ob->remove();
  }
  }*/
