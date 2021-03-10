#include <std.h>
#include <objects.h>

inherit ROOM;

int SEARCHED;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Trading Chamber");
    set_long("%^BOLD%^%^BLUE%^
The walls of this chamber are decorated with banners representing
townships and cities in the vicinity of %^CYAN%^Sanctuary%^BLUE%^.  The decor
is appropriate given the room's fuction:  This is where traveling
merchants come to exchange their wares.  The space is taken up by
a large oaken table and six impressive chairs.
    ");
    set_exits(([
       "south" : "/d/dragon/town/general"
    ] ));
    set_items(([
      "banners":"You notice that one of the banners represents the city of "+
      "Verbobone, and another represents the city of Shadow. You notice a slight bulge in the middle of one of the other banners.",
       "table":"The large oaken table has six impressive chairs, three positioned\n"+
               "on either side.  In the center of the table is the crest of the \n"+
               "city of Sanctuary."
    ] ));
  set_smell("default","The cigar smoke from the traveling merchants is overwhelming.");
   set_search("banners",(:TO,"search_banners":));
}

int search_banners()
{
   object obj, money;

   if(SEARCHED == 1) {
      tell_object(TP,"You search the banners and find a hidden cubby behind one, but it is empty.");
      return 1;
   }
   tell_object(TP,"You search the banners and find a hidden cubby behind one.\n"+
   "You pull a small chest out from the cubby!");
   tell_room(ETP,""+TPQCN+" pulls a small chest from out behind one of the banners.",TP);
   add_item("banners","You notice that one of the banners represents the city of "+
   "Verbobone, and another represents the city of Shadow.");
   obj = new("/d/common/obj/misc/schest");
   obj->move(TO);
   obj->set_key("chestkey");
   money = new("/std/obj/coins");
   money->set_money("gold",random(200)+50);
   money->set_money("electrum",random(230)+50);
   money->set_money("copper",random(2000)+300);
   money->set_money("silver",random(200)+25);
   money->move(obj);
   obj->toggle_closed();
   obj->set_lock("locked");
   obj->set_lock_difficulty(50);
   SEARCHED = 1;
   return 1;
}
