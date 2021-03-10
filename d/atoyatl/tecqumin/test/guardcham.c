#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_INT_BASE;

int entered, opened;
string long_desc();

void create() {
  entered = 1; // set before the call to ::create to assist in making sure
               // that the mobs only load when the room is first entered.
  ::create();
  opened = 0;
  set_short("An empty chamber");
  set_long((:TO,"long_desc":));
  set_smell("default","The smells of the jungle compete against the musty"
                     +" scent of the dust of ages");
  set_listen("default","The sounds of the jungle sound faint and muffle"
                      +" in the distance. Inside the ziggurat, all is"
                      +" silent.");
  set_items(([({"wall", "walls"}) : "You notice that the chamber is not"
                                   +" quite square. It is slightly shorter"
                                  +" running north-south than east-west",

               ({"opening", "small opening"}): (:TO, "view_opening":)
           ]));
  set_exits( ([
                "north" : TEST + "start",
   ]) );
  set_search("opening", (: TO, "search_opening" :) );
}

string long_desc(){
  string desc;
  desc = "This small chamber inside the ziggurat is positioned"
        +" immediately beneath the ceremonial area of the zenith. A set"
        +" of steps lead upwards to the south of the room and there are"
        +" single doors to the east and south. In the"
        +" daytime, the stone walls keep out the worst of the sun's heat."
        +" At night, the chilly air is still. A processional pathway"
        +" leads from the double doors to the north to the stairs.";
  if (opened >0){
    desc += " You can see a small opening in the east wall.";   
  }
  return desc;
}

void on_enter(){
  object ghost_war = present("tecqumin ghost warrior",TO);
  if (entered==0||objectp(ghost_war))
  //if there is a ghost warrior  already present, more are summoned. This 
  // is to avoid munchkins cheating it by sending one character into the 
  // room to trigger the function then all charging in once the trigger is 
  // thrown.
  call_out("on_enter2",2);
}

void reset(){
  ::reset();
  entered = 0;
  if (opened > 0 ){
    opened --;
  }
}

void on_enter2(){
  object *critters, *players;
  int i,j;
  string num;
  players = ({});
  critters = all_living(TO);
  if(sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      if (!critters[i]->id("ghost")){
        players += ({critters[i]});
      }
    }
  }
  switch (sizeof(all_living(TO))){
    case 0:
    return;
    case 1..2:
      j=2;
      num = "two";
      break;
    case 3..4:
      j=3;
      num = "three";
      break;
    case 5..6:
      j=4;
      num = "four";
      break;
    case 7..8:
      j=6;
      num = "six";
      break;
    default:
      j= 3 * (1+sizeof(all_living(TO)))/4;
      num = "lots of";
  };
  tell_room(TO,num +" shapes %^CYAN%^fl%^RESET%^i%^CYAN%^ck%^CYAN%^er"
              +" %^RESET%^and appear in the corner of your eye.");
  tell_room(TO,"%^CYAN%^The %^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^"
              +"%^WHITE%^stly w%^RESET%^a%^BOLD%^%^WHITE%^rr%^RESET%^"
              +"%^CYAN%^i%^RESET%^o%^BOLD%^%^WHITE%^rs%^RESET%^%^CYAN%^"
              +" draw their weapons and move silently to the attack!");
  for (i=0;i<j;i++){
    new(MOB+"ghost_warrior")->move(TO);
  }
}

void search_opening(){
  object jetstone, store;
  if (opened ==0){
    tell_object(TP, "You find nothing odd.");
    return;
  }
  store = find_object_or_load(ROOMS + "storage");
  jetstone = present("jetstone", store);
  if (objectp(jetstone)){
    tell_object(TP, "Reaching into the opening, you find an interesting"
                   +" piece of %^BOLD%^%^BLACK%^jetstone%^RESET%^.");
    tell_room(TO, TPQCN + " reaches into the opening in the north wall and"
                 +" pulls out a strange %^BOLD%^%^BLACK%^black stone"
                 +"%^RESET%^.", TP);
    jetstone->move(TP);
    return;
  }
  tell_object(TP, "You reach into the opening, but it seems to be empty.");
  tell_room(TO, TPQCN + " reaches into the opening in the north wall, but"
                +" doesn't seem to find anything.", TP);

}

string view_opening(){
  if (opened == 0){
    return "You cannot see that here.";
  }
  return "The opening is too small to go through, but you could search it.";
}

int query_open(){
  return opened;
}

void open_chamber(){ //This function is triggered by the lever in the 
  opened = 3;        //throne room
}
