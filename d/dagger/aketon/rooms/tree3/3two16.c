#include "/d/dagger/aketon/short.h"

inherit VAULT;

int SEARCHED;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "Dust covers everything in this room as well. It is a fairly simple"+
   " room with a bed in the southeast corner, and a large armor stand"+
   " that stands empty on the north wall. There is a dresser that has"+
   " most of its drawers opened on the east wall. A few items of clothing"+
   " that are also covered in dust seem to be all that is left inside it."+
   " It looks as though someone went through the drawers and packed in"+
   " a hurry. There doesn't appear to be much else here.");
   set_smell("default","The room is a little dusty and the slight"+
   " hint of mildew has creeped in.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   "bed" : "There is a bed along the southwest wall. It has green"+
   " blankets on top of it that reach down to the floor. The blankets"+
   " have begun to smell of mildew.",
   ({"stand","armor stand"}) : "There is a wooden stand for armor on"+
   " the north side of the room. It is empty and also covered in dust.",
   ({"dresser","drawers","clothes"}) : "There is a wooden dresser on the"+
   " east wall that appears fairly devoid of clothing. Most of the"+
   " drawers are still open and the few pieces of clothing that are"+
   " left are not only covered in dust and have started to mildew, but"+
   " they weren't in the best of shape to begin with.",
   ]));
   set_door("door",RPATH3+"3two11","northwest","aketon key");
   set_locked("door",1);
   set_search("bed",(:TO,"search_bed":));
   set_exits( (["northwest":RPATH3+"3two11"]) );
}

int search_bed()
{
   int obj;

   if(SEARCHED == 1) {
      tell_object(TP,"You search the bed but don't find anything.");
      tell_room(ETP,""+TPQCN+" searches the bed but doesn't find anything.",TP);
      return 1;
   }
   tell_object(TP,"You discover a chest underneath the bed and pull"+
   " it out into the light.");
   tell_room(ETP,""+TPQCN+" pulls out a chest from beneath the bed.",TP);
   SEARCHED = 1;
   obj = new("/d/shadow/obj/misc/chest");
   obj->move(TO);
   obj->set_key("chestkey");
   switch(random(3)) {
      case 0:
         new("/d/dagger/aketon/obj/elven_boots")->move(obj);
         break;
      case 1:
         new("/d/common/obj/sheath/pearled_msheath")->move(obj);
         break;
      case 2:
         new("/d/dagger/aketon/obj/cape")->move(obj);
         break;
   }
   obj->toggle_closed();
   obj->set_lock("locked");
   obj->lock_difficulty(75);
   return 1;
}
