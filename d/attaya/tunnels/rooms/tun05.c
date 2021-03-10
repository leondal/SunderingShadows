#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit TUNNELS + "mouthroom";

string hand;
int put_hand(string str);
void put_hand2(object ob);
int rub_bump(string str);
void rub_bump2();
int press_bump(string str);
void press_bump2();

void create() {
  ::create();
  hand="";
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "A narrow tunnel");

  set_smell("default","The air smells of damp stone");
  set_listen("default","You can hear the sound of music coming from deep"
                      +" within the tunnels.");

  set_items( ([ 
    ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black"
                        +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                        +" smooth in places, but cracked and uneven in"
                        +" others, making it hard to know whether they"
                        +" have been worked or not..",

  "ceiling" : "the ceiling is so high up as to be out of sight.", 

  "floor" : "The floor is smooth, and relatively free of dirt."
                  +" A large %^RED%^pentagram%^RESET%^ has been drawn"
                  +" here, with a strange %^ORANGE%^wax idol%^RESET%^ in"
                  +" the centre of it.",

  "pentagram" : "%^BOLD%^%^BLACK%^A %^BOLD%^%^RED%^fi%^CYAN%^v%^RED%^e"
               +" p%^CYAN%^o%^RED%^int%^CYAN%^e%^RED%^d s%^CYAN%^t"
               +"%^RED%^ar%^RESET%^ within a %^BOLD%^%^CYAN%^circle"
               +"%^BOLD%^%^BLACK%^ drawn in %^RESET%^c%^BOLD%^%^WHITE%^"
               +"h%^RESET%^alk %^BOLD%^%^BLACK%^in the middle of the"
               +" room. There are small %^RESET%^%^RED%^runes%^BOLD%^"
               +"%^BLACK%^ inscribed around the edges of the circle.",

  ({"idol","waxen idol","wax idol"}):
                 "The idol appears to be made from %^ORANGE%^wax"
                 +"%^RESET%^, in the form of a %^RED%^d%^BOLD%^%^RED%^e"
                 +"%^RESET%^%^RED%^v%^BOLD%^%^RED%^i%^RESET%^%^RED%^l"
                 +" %^RESET%^of some kind. It is squat and"
                 +" %^BOLD%^%^BLACK%^ugly%^RESET%^, rising"
                 +" barely 3 feet above the floor, with a twisted,"
                 +" misshapen face that seems to leer at you from within"
                 +" the bounds of the %^RED%^pentagram%^RESET%^."
                 +" Its eyes stare fixedly upwards toward a"
                 +" %^BOLD%^%^BLACK%^%^crack%^RESET%^"
                 +" in the wall opposite.",

  ({"cracks", "fissures"}):"the larger cracks look big enough for"
                          +" something to go into of come out of, but"
                          +" most of them are way up high in the walls."
                          +" However, one of the larger cracks, standing"
                          +" opposite the little idol, is a little low"
                          +" enough for you to reach it.",

  "crack" : "one of the larger cracks in the wall here is low enough for"
           +" you to reach it. It looks very dark inside.",
 ]) );

  set_exits( ([ "southwest" : TUNNELS + "tun04" ,
	          "south" : TUNNELS + "tun06"]) );

  set_search("walls","you find many small cracks and fissures in the"
                    +" slate. There appear to be larger cracks higher up"
                    +" on the walls, out of reach, and even one lower"
                    +" down." );

  set_search("crack","You peer into the crack, but it is too dark to see."
                    +" You will have to put your hand inside if you"
                    +" really want to find out what's in there." );

  set_search("larger crack","You peer into the crack, but it is too dark"
                           +" to see. You will have to put your hand"
                           +" inside if you really want to find out"
                           +" what's in there." );

  set_search("lower crack","You peer into the crack, but it is too dark"
                           +" to see. You will have to put your hand"
                           +" inside if you really want to find out"
                           +" what's in there." );
  set_search("reachable crack","You peer into the crack, but it is too"
                           +" dark to see. You will have to put your hand"
                           +" inside if you really want to find out"
                           +" what's in there." );

  set_search("default","The walls look quite interesting" );
}

void init(){
  ::init();
  add_action("put_hand","put");
  add_action("rub_bump","rub");
  add_action("press_bump","press");
  add_action("touch_idol","touch");
}

string long_desc(){
  return  "%^BOLD%^%^BLACK%^You have reached a sharp bend in the tunnel."
          +" The passageway widens a little as it swings round between"
          +" the south and southwesterly directions. A large pentagram"
          +" has been chalked onto the floor, and evil-looking black"
          +" c%^YELLOW%^a%^BLACK%^ndles fl%^YELLOW%^i%^BLACK%^cker and"
          +" gutter at the five points of the star. In the centre of the"
          +" pentagram is a %^ORANGE%^w%^RESET%^a%^ORANGE%^xen"
          +" %^YELLOW%^i%^RESET%^%^ORANGE%^d%^YELLOW%^ol%^BOLD%^%^BLACK%^"
          +" in the form of some ugly devil creature.%^RESET%^";
}

void reset()
{
  ::reset();
  remove_exit("northwest");
  if (sizeof(all_living(TO))== 0)
  {
    hand = "";
  }
}

int touch_idol(string str)
{
  int mpresent;
  mpresent  = 0;

  if (!str)
  {
    return 0;
  }
  if (str != "idol" && str != "waxen idol" && str != "wax idol")
  {
    tell_object(TP, "You touch " + str);
    tell_room(TO, TPQCN + " touches " + str, TP);
    tell_room(TO, "Nothing happens");
    return 1;
  }
  tell_object(TP, "Reaching across the pentagram, you place your hand"
                 +" gingerly on the surface of the %^YELLOW%^i%^RESET%^"
                 +"%^ORANGE%^d%^YELLOW%^ol%^RESET%^. It feels smooth and"
                 +" %^ORANGE%^waxy%^RESET%^, and as you touch it there is"
                 +" a %^GREEN%^movement%^RESET%^ behind you, making you"
                 +" wonder what you have done.");

  tell_room(TO,"Reaching across the pentagram, " + TPQCN + " places " 
              + TP->QP + " hand gingerly on the surface of the"
              +" %^YELLOW%^i%^RESET%^%^ORANGE%^d%^YELLOW%^ol%^RESET%^."
              , TP);

  if (present("magicmouth"))
  {
    mpresent = 1;
  }
  mouthsay("Boo!");
  if (mpresent)
  {
    call_out("touch2", 2);
  }
  else
  {
    call_out("touch2", 7);
  }  return 1;
}

void touch2()
{
  mouthsay("Well... you didn't take that warning very seriously, it"
          +" seems. You were told the room was dangerous, and anything"
          +" could have happened. Who knows what could happen next"
          +" time?");
}

int put_hand(string str){
  object obstruction;
  if (str!="hand in crack"&& str!="hand into crack"
       && str!="my hand in crack" && str!="my hand into crack"
       && str!="hand in large crack" && str!="hand into large crack"
       && str!="hand inside crack" && str!="hand inside large crack"
       && str!="my hand inside crack" && str!="my hand inside large crack"
       && str!="hand inside" && str!=" my hand inside"
       && str!="hand in fissure"&& str!="hand into fissure"
       && str!="my hand in fissure" && str!="my hand into fissure"
       && str!="hand in large fissure" && str!="hand into large fissure"
       && str!="hand inside fissure" && str!="hand inside large fissure"
       && str!="my hand inside fissure" 
       && str!="my hand inside large fissure"){
    tell_object(TP, "Put what where?");
    return 1;
  }
  if (hand!=""){
    obstruction = present(hand, TO);
    if (objectp(obstruction)&& interactive(obstruction)){
      tell_object(TP, obstruction->QCN + " already has "+ obstruction->QP
                  +" hand in the crack. There isn't room for both of"
                  +" you!");
      return 1;
    }
  }
  tell_object(TP, "You put your hand into the large crack, low down on"
                 +" the wall and feel around.");
  tell_room(TO, TPQCN + " puts " + TP->QP + " hand into a large crack,"
               +" low down on the wall and feels around", TP);
  hand = TPQN;
  call_out("put_hand2", 2, TP);
  return 1;
}

void put_hand2(object ob){
  if (!objectp(TO)||!objectp(ob)||!present(ob, TO)){return 0;}
  tell_object(ob, "Your questing fingers happen across a strange"
                    +" %^BOLD%^%^BLACK%^bump%^RESET%^ in the rock inside"
                    +" the fissure");    
  mouthsay("Stop! Don't do anything else. Take your hand out... slowly,"
          +" and back away. Whatever you do... don't rub that bump!");
}

int rub_bump(string str){
  if (str != "bump" && str!= "that bump"){
    tell_object(TP, "Rub what?");
    return 1;
  }
  if (hand!=(string)TPQN){
    tell_object(TP, "You don't have your hand on a bump");
    return 1;
  }
  tell_object(TP, "You rub the bump, but nothing seems to happen.");
  tell_room(TO, TPQCN + "seems to do something with " + TPQP 
               +" hand inside the large crack in the wall. Nothing"
               +" happens.", TP);
  mouthsay("I cannot believe you did that after I warned you! It is"
          +" just as well I spoke falsely to avoid risk, and did not tell"
          +" you the real warning was that you should not"
          +" %^BOLD%^%^GREEN%^press%^RESET%^%^GREEN%^ the bump.");
  call_out("rub_bump2", 2);
  return 1;
}

void rub_bump2(){
  mouthsay("Oh damn. I shouldn't have said that.");
}

int press_bump(string str){
  if (str != "bump" && str!= "the bump"){
    tell_object(TP, "Press what?");
    return 1;
  }
  if (hand!=(string)TPQN){
    tell_object(TP, "You don't have your hand on a bump");
    return 1;
  }
  tell_object(TP, "As you press the bump, there is a slight resistance"
                 +" and then it gives way under your hand.");
  tell_room(TO, TPQCN + "seems do do something with his hand inside the"
               +" large crack in the wall.", TP);
  if(member_array("northwest",query_exits()) == -1){
    call_out("press_bump2", 3);
  }
  return 1;
}

void press_bump2(){
  tell_room(TO, "There is a grinding noise behind you as the walls open"
               +" up to reveal a new exit to the northwest");
  mouthsay("You really don't listen, do you? I told you it was dangerous,"
          +" but you had to do it anyway. Oh very well then... carry on"
          +" to your doom if you must - but bad things await you up"
          +" there.");
  add_exit(TUNNELS + "tun07","northwest");
}

GoThroughDoor()
{
  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }
  find_object_or_load(TUNNELS+"tun06.c")->enter_from_north();
}

