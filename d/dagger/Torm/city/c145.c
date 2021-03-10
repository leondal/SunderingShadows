#include <std.h>
#include "../tormdefs.h"
inherit CELLAR;
object ob;
int SEARCHED;
void create(){
  ::create();
  set_short(
  "Magistrate's bedroom"
  );
  set_property("indoors",1);
  set_long(
  "  You get a chill down your back as you enter this room."
  "  A large bed stands against the south wall and a cold dark fireplace sits against the east wall."
  "  Near the door in the west wall a large desk sits with carefully stacked piles of paper on it."
  "  A large rather plain wardrobe takes up most of the north wall."
  );
  set_exits(([
  "west":TCITY+"c144",
  "trapdoor":TCITY+"c157",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "trapdoor":"It's a trapdoor in the fireplace.",
  "wardrobe":"This large mahogany wardrobe is empty oddly enough.",
    "fireplace":"A fire isn't set even though the air is chilly in here.",
    "bed":"The bed is a neatly made 4 post bed.  It doesn't look like it's been slept in in a long time.",
  "desk":"The desk is stacked with legal looking papers.",
    "papers":"You haven't an idea what they're for, the numbers seem to run on and on.",
  "floor":"The marble floor shows signs of much travel recently.  Its clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
  set_door("trapdoor","/d/dagger/Torm/city/c157","trapdoor","masterkey");
  set_open("trapdoor",0);
  set_locked("trapdoor",0);
  set_search("fireplace","You notice a trapdoor in the cold bottom of the fireplace");
   set_search("wardrobe",(:TO,"search_wardrobe":));
  set_invis_exits(({"trapdoor"}));
}
/*void reset() {
  ::reset();
  if(query_night()){
   if(!present("vizier")) new(MON+"vizir.c")->move(this_object());
  return 1;
  }
   if(present("vizier")){
   ob=present("vizier");
   tell_room(environment(ob),"The vizier leaves.");
  ob->move("/d/shadowgate/void");
  ob->remove();
  }
} */

int search_wardrobe() {
   object obj, money;

   if(SEARCHED == 1) {
      tell_object(TP,"You discover the bottom panel of the wardrobe is actually false, but someone appears to have looted it already.");
      tell_room(ETP,""+TPQCN+" frowns intensely at the wardrobe for a moment but then stands up empty handed.",TP);
      return 1;
   }
   tell_object(TP,"You discover that the bottom panel of the wardrobe is actually hollow!\n"+
   "You open the panel up and pull out a small treasure chest.");
   tell_room(ETP,""+TPQCN+" pulls a small treasure chest from somewhere out of the wardrobe.",TP);
   obj = new("/d/common/obj/misc/schest");
   obj->move(TO);
   obj->set_key("chestkey");
   money = new("/std/obj/coins");
   money->set_money("gold",random(200)+50);
   money->set_money("electrum",random(300)+50);
   money->set_money("copper",random(2000)+500);
   money->set_money("silver",random(200)+25);
   money->move(obj);
   obj->toggle_closed();
   obj->set_lock("locked");
   obj->set_lock_difficulty(75);
   SEARCHED = 1;
   return 1;
}
