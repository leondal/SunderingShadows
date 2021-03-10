#include "../tormdefs.h"
inherit TOWN;
object ob;
void create(){
  ::create();
  set_short(
    "Master bedroom in Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This is the sitting room for the old king of Torm."
  "  A large fireplace on the east wall is always burning and a comfortable looking chair is set across from it."
  "  Richly decorated tables and end tables dot the edges of the room and a large bookcase is against the south wall by a door."
  "  The north wall is almost entirely glass and overlooks a patio that leads out to the park."
  );
  set_exits(([
  "balcony":TCITY+"c136",
  "south":TCITY+"c142",
  "west":TCITY+"c138",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
  "fireplace":"The fireplace is well stocked with logs and blazes away but seems to do little to warm this room.",
  "tables":"These small well made tables hold various little items of little interest.",
  "chair":"The comfortable chair in front of the fireplace is set up to get the best warmth out of it.",
    "bookcase":"They're full of books, but they don't appear to have been touched recently and they really need to be dusted.",
  "books":"They're all dusty and of little use to you it seems.",
  "patio":"Its behind a sliding glass door set on rollers.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
void reset(){
  ::reset();
  if(!present("servant")) new(MON+"servant")->move(this_object());
  if(query_night()){
  if(!present("vendire")) new(MON+"vendire")->move(this_object());
  if(!present("old king")) new(MON+"king")->move(this_object());
  ob=present("old king");
  ob->set_long("  The old king sits here in a comfortable chair staring into the flames occasionally dozing off.  As soon as he does though he seems to awake from a bad dream muttering and tossing till he dozes off again.");
  ob=present("vendire");
    ob->set_long("  Vendire's face looks haggard and full of deep sorrow, which mars his unearthly elven good looks.  He watches the old king toss in his sleep with the look of a friend whose long seen the suffering of an old comrade.");
  return 1;
  }
  if(present("vendire")){
  ob=present("vendire");
  tell_room(environment(ob),"%^GREEN%^Vendire leaves behind the old king out into the sunlight.");
  ob->move("/d/shadowgate/void");
  ob->remove();
  }
  if(present("old king")){
  ob=present("old king");
  ob->move("/d/shadowgate/void");
  ob->remove();
  }
}
