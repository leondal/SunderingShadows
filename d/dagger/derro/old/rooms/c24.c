#include <std.h>
#include "../derrodefs.h"
#include <move.h>

inherit CROOM;

int shieldx,swordx;
void create(){
  set_monsters( ({MON"derro2", MON"derro4", MON"derro1", MON"derro3"}),({1,1,1,1}));
  ::create();
  set_repop(50);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short("%^RED%^Giants main hall%^RESET%^");
  set_long(
  "%^RED%^Giants main hall%^RESET%^\n"
  "  This massive room appears to be the main meeting area for the giants, now taken over by the Derro."
  "  A huge table is set up with rows of benches and a huge chair at its head with another smaller table off to the side."
  "   A fireplace made from bricks glows against the south wall above which hangs a shield."
  "  Trophies of past victories hang on the walls."
  "  The pallets of the Derro are crowded in and around the room and it appears this is where they've all been staying."
  );
  set_smell("default", "You smell something cooking to the north." );
  set_listen("default", "You can hear nothing but the occasional chirp of a rat somewhere in the distance." );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "bricks":"One of them appears loose.  Maybe you could pry it out?",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",
  "pallets":"Filthy and infested with lice, it doesn't look like they cared much about their sleeping conditions.",
  "table":"A huge table set on scale for 18 ft tall giants.",
  "huge chair":"A massive chair, almost a throne.   It's made of wood and looks like it needs to be replaced soon with the splintering evident.",
  "fireplace":"Framed of bricks, it is 20 feet long and high it glows warmly but not with a set fire.   Lava flows from a trough in the wall through the open fireplace grate and off under the wall.",
  "trophies":"Battered arms, armor and pieces of body parts adorn the wall.  A dragon head hangs over the huge chair at the head of the table",
  "dragon head" : "A slightly moth eaten huge green dragon's head.   It looks pretty mean though and you hope you don't have to fight whatever brought it down.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling.",
  "shield":"It's a battered shield with the emblem of the order of light on it.  It hangs oddly on the wall.",
  ]));
  set_search("default","A cursory examination of the room doesn't turn up much");
  set_search("pallets","Some lice seems to have found you an acceptable new host.");
  set_search("trophies","All battered and useless.");
  set_search("bricks","Seems there's a loose brick.   Wonder if you could pry it out?");
  set_search("fireplace","The fireplace heat blasts you as you check it over and you notice that its backing is all bricks and the rest of the walls are natural undressed stone.");
  set_search("shield", (: TO, "search_shield" :) );
  set_exits(([
  "north":ROOMS"c23",
  "west":ROOMS"c19",
  "southwest":ROOMS"c20",
  "northeast":ROOMS"c26",
  ]));
}
void reset(){
  ::reset();
/* changing to use CROOM  11/26/02 *Styx*
  if(!present("savant")){
  new(MON"derro2.c")->move(TO);
  new(MON"derro4.c")->move(TO);
  new(MON"derro1.c")->move(TO);
  new(MON"derro3.c")->move(TO);
  }
*/
}

void init(){
  ::init();
  add_action("pry","pry");
//  add_action("search","search");  changed to use set_search like it should have
}

int pry(string str){
  object ob;
  if(!str)			return notify_fail("Pry what?\n");
  if(present("derro",TO))	return notify_fail("Um you're a little busy.\n");
  if((str=="brick") || (str =="bricks")){
  if(swordx)		return notify_fail("Already pried at everything you can.\n");
  if(!present("prybar",TP))	return notify_fail("You don't have anything "
	"you can use to pry at the bricks properly.\n");
  swordx=1;
  write("You pry the brick out revealing a crevasse behind it.  You reach in and grab the hilt of the sword you can make out in the darkness.");
  tell_room(ETP, TPQCN+" pries a brick out of the fireplace, reaches into the opening, and pulls out a sword!", TP);
  ob=new(OBJ"oldscimitar.c");
  if (ob->move(TP) != MOVE_OK) ob->move(ETP);
  ob->move(TP);
  return 1;
}
}

int search_shield(string str){
  if(str=="shield"){
  if(shieldx)  {
      write("You've already searched it, or at least someone has.");
      return 1;
  }
  tell_room(ETP,TPQCN+" searches behind the shield that hangs on the wall and notices another one behind it!",TP);
  write("You search behind the shield and find another shield hidden under it!");
  new(OBJ"shield.c")->move(TO);
  shieldx=1;
  return 1;
  }
}
