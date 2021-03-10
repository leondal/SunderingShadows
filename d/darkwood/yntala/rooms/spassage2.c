//spassage2
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;
int lit;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^A secret room");
   set_short("%^RESET%^A secret stone room%^RESET%^");
   set_listen("default","The absolute silence is unnerving.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"All of the stone walls here are bare, except for the northern wall.  Shackles, chains and manacles hang above the platform from it.",
   "floor":"The floor is cold, hard granite and not very inviting.",
   "chairs":"All of the chairs have been lined in rows along the southern end of the room, and all of them face forward, towards the platform against the northern wall.",
   "steps":"There are four steps in total, each about 7 inches tall, that lead up to the stone platform at the northern end of the room.",
   "platform":"This is a large, raised stone platform placed against the wall at the northern end of the room.  Four steps in total lead up to it, and shackles, chains and manacles hang from the wall behind it.",
   ({"shackles","chains","manacles"}):"Shackles, chains and manacles hang at varied heights from the wall directly behind the platform.  They do not appear to have been used in quite some time.",
   ({"podium","wooden podium"}):"%^RESET%^%^ORANGE%^A wooden podium sits near the northern end of the room, slightly off to the side of the platform to avoid obstruction of the view.  The podium faces out towards the chairs and has a few small shelves on the inside of it that were probably used for storing devices of torture.",
   ({"brazier","braziers","iron brazier","iron braziers"}):"%^BOLD%^%^BLACK%^These two braziers have been placed on the floor on either side of the platform.  Each one looks almost like a small cauldron, but only about a foot in diameter.  They each taper down to four clawed feet that point in each of the cardinal directions for stability.",
]));
   set_exits((["east":INRMS+"spassage"]));
   lit = 1;
}
string ldesc(string str){
   return("%^RESET%^This secret room is at the end of a long stone corridor.  Many chairs have been lined in rows"
" along the southern wall and all face the northern end of the room, where a few"
" %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^WHITE%^t%^BLACK%^e %^RESET%^steps lead"
" up to a small platform against the wall.  Shackles, chains and manacles hang from various heights on the wall"
" behind the platform.  At the base of the platform and slightly off to the side, is a %^ORANGE%^wooden podium "
"%^RESET%^that faces the chairs.  Two %^BOLD%^%^BLACK%^iron braziers %^RESET%^have been placed on either side of the"
" platform and look as though they are the only source of illumination for the room.  As a matter of fact, it"
" would appear the rest of the room would stay rather dark"
" except the platform area, leading one to wonder what sorts of strange ceremonies happened here.%^RESET%^");
} 
void reset() {
   ::reset();
   lit = 1 ;
}
void init(){
  ::init();
  add_action("light","light");
}
int light(string str){
   if(!str) notify_fail("What are you trying to light?");
   if(str == "braziers"||str=="the braziers"){
      if(lit == 1) {
         tell_object(TP,"%^RESET%^%^CYAN%^You light the first %^BOLD%^%^BLACK%^brazier %^RESET%^%^CYAN%^and then the second.  %^BOLD%^%^RED%^Fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes %^RESET%^%^CYAN%^leap up out of them, illuminating the platform between them.%^RESET%^\n %^BOLD%^Suddenly a ghost appears and attacks you!");
         tell_room(TO,"%^CYAN%^"+TPQCN+" lights the first %^BOLD%^%^BLACK%^brazier %^RESET%^%^CYAN%^and then the second.  %^BOLD%^%^RED%^Fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes %^RESET%^%^CYAN%^leap up and illuminate the platform between them.%^RESET%^\n%^BOLD%^Suddenly a ghost appears on the platform and attacks you!", TP);
         new(TMONDIR+"gyuan-ti.c")->move(TO);
         lit = 0;
         return 1;
      }
      if(lit = 0) {
         tell_object(TP,"%^RESET%^%^CYAN%^These have already been lit.%^RESET%^");

      return 1;
      }
   }
   else{
      tell_object(TP,"%^RESET%^%^CYAN%^Are you trying to light the braziers?");
      return 1;
   }
} 

