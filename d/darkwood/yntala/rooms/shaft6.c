//shaft6
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;

void create(){
   switch(random(13)){
      case 0..2:
      break;
      case 3..10:
         set_monsters(({TMONDIR +"yuan-tip.c"}),({2}));
      break;
      case 11..12:
         set_monsters(({TMONDIR +"yuan-tih.c"}),({1}));
   }
   set_repop(70);

::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float upon the stale air.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here have been covered with gems and semi precious stones in such precise positions that they actually make a mosiac of pictures.",
   ({"pictures","gems","mosiac"}):"%^BOLD%^%^GREEN%^Gleaming emerald and jade pieces have been inset against"
" pieces of %^YELLOW%^amber %^GREEN%^at the top of this picture.  The %^YELLOW%^amber %^GREEN%^is laid out in"
" a perfect circle with many bright %^YELLOW%^rays %^GREEN%^eminating from it, showing it to be a glorious shining"
" %^YELLOW%^sun.  %^GREEN%^In front of the %^YELLOW%^sun, %^GREEN%^the emeralds and jade make a tall, staturesque"
" snake like being standing in full glory on the top of a %^RED%^blood red %^GREEN%^mountain of %^RED%^rubies."
"  %^GREEN%^Within the mountain of %^RED%^rubies, %^GREEN%^pieces of %^WHITE%^opal %^GREEN%^make up the severed"
" %^WHITE%^limbs %^GREEN%^of %^WHITE%^humanoid creatures.  %^GREEN%^The %^WHITE%^limbs %^GREEN%^stick out in all"
" sorts of strange directions, but the message this image"
" is trying to make is quite clear.  The snake creature was victorious.",
]));
   set_exits((["west":INRMS+"shaft7","east":INRMS+"shaft5"]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^This is a dark, east-west tunnel.  It opens up a little bit from the shaft, becoming"
" larger and easier to maneuver.  No slime covers the walls here, instead, they are inlaid with a mosiac of gems"
" and semi precious stones that make out various pictures and depictions.  It would appear that none of the gems"
" are loose and are a newer addition to this pyramid.%^RESET%^");
} 

