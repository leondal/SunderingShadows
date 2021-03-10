#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;
int pulled, searched;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A private office");
  set_short( "%^ORANGE%^A %^CYAN%^grand %^ORANGE%^entrance" );
  set_long( "%^ORANGE%^This huge room has an unusual, %^BOLD%^"
    +"%^WHITE%^five-sided shape%^RESET%^%^ORANGE%^. The southern"
    +" end forms a point at the %^BOLD%^%^BLACK%^carved door"
    +"%^RESET%^%^ORANGE%^. The walls then lead outwards at a"
    +" shallow angle to their widest point toward the southern"
    +" half of the east and west sides, before tapering back,"
    +" funnelling attention to an extraordinary%^BOLD%^%^BLACK%^"
    +" throne%^RESET%^%^ORANGE%^ in the shape of a %^BOLD%^"
    +"%^YELLOW%^j%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^gu"
    +"%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^r%^RESET%^%^ORANGE%^"
    +"'s head and forequarters, which sits on a dais before the"
    +" north wall. Small square %^RESET%^windows%^ORANGE%^ are"
    +" positioned high on the east, west and south walls. To"
    +" the left of the %^BOLD%^%^BLACK%^carved door%^RESET%^"
    +"%^ORANGE%^, a staircase leads up to a balcony, and there"
    +" are doors at the eastern and western points of the room."
    +" Double doors in the northern part of the east wall lead"
    +" outside. A %^BOLD%^%^WHITE%^fresco%^RESET%^%^ORANGE%^"
    +" decorates the northern wall, behind the %^BOLD%^%^BLACK%^"
    +"throne%^RESET%^%^ORANGE%^. An arched door leads north." );
  set_items( ([ ({"unusual shape", "five sided shape", "shape",
              "five sides"}): "You realise the the shape of the"
    +" room is a stylised version of the torso of the %^BOLD%^"
    +"%^YELLOW%^j%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^ng"
    +"%^RESET%^%^ORANGE%^l%^BOLD%^%^YELLOW%^e"
    +" c%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^t%^RESET%^ that"
    +" the whole building represents",
                   "throne" : "Echoing the design of the entire"
    +" building, the %^BOLD%^%^BLACK%^mahogany%^RESET%^ throne"
    +" is carved in the shape of the head and fore quarters of"
    +" a %^BOLD%^%^YELLOW%^j%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^YELLOW%^gu%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^r"
    +" %^RESET%^clawing its way up out of the earth. The seat"
    +" itself is in the beast's open, %^BOLD%^%^WHITE%^snarling"
    +" %^RESET%^mouth and the occupant sits with their legs"
    +" over the lip and their hands resting on the forelegs",
     ({"window", "windows"}) : "The window sit too high on the"
    +" walls to look out. Their sole function seems to be to"
    +" allow %^ORANGE%^l%^BOLD%^%^YELLOW%^i%^RESET%^%^ORANGE%^"
    +"ght%^RESET%^ to stream through in dramatic slanting"
    +" shafts from above.",
                    "fresco" : "The fresco sits behind and"
    +" above the %^BOLD%^%^BLACK%^throne%^RESET%^, providing"
    +" it with a magnificent backdrop. It is an idealised"
    +" depiction of life in the %^CYAN%^Tecqumin%^RESET%^ city,"
    +" with the great pyramid, plaza and palace all clearly"
    +" visible, along with the high class housing for the"
    +" richly dressed elites of the city to the east. More"
    +" modest housing is depicted to the west, whose occupants"
    +" are mostly dressed in simple loincloths or cloaks. Two"
    +" great %^BOLD%^%^BLUE%^canals%^RESET%^ running"
    +" north-south divide the city environs into three, with"
    +" the whole area rising from the great surrounding"
    +" %^GREEN%^j%^BOLD%^u%^RESET%^%^GREEN%^ng%^BOLD%^l"
    +"%^RESET%^%^GREEN%^e%^RESET%^. The pyramid is central in"
    +" the frame, so that its summit rises behind the great"
    +" throne in the hall. The %^BOLD%^%^YELLOW%^sun%^RESET%^"
    +" is depicted behind the altar, its %^ORANGE%^r%^BOLD%^"
    +"%^YELLOW%^a%^RESET%^%^ORANGE%^ys%^RESET%^ brightly"
    +" illuminating a scene of human sacrifice, in which"
    +" a priest in a %^BOLD%^%^BLACK%^mask%^RESET%^ and a"
    +" %^BOLD%^%^BLUE%^f%^CYAN%^e%^RED%^a%^BLUE%^th%^GREEN%^e"
    +"%^BLUE%^r%^CYAN%^e%^BLUE%^d c%^CYAN%^l%^BLUE%^o"
    +"%^YELLOW%^a%^BLUE%^k %^RESET%^holds aloft a"
    +" %^RED%^h%^MAGENTA%^u%^RED%^man"
    +" %^BOLD%^h%^RESET%^%^RED%^ea%^BOLD%^rt%^RESET%^. In his"
    +" other hand, the priest holds the %^CYAN%^ceremonial"
    +" dagger%^RESET%^ which presumably opened up the chest"
    +" cavity of the stricken victim still bent backwards"
    +" over the altar. A bright river of %^RED%^red%^BOLD%^"
    +" bl%^RESET%^%^RED%^oo%^BOLD%^d%^RESET%^, much more than"
    +" could have come from this single victim, flows down"
    +" the steps of the pyramid to wet the feet of the crowd"
    +" below. "  ]) );
  set_smell("default","The air is still and humid, carrying hints of the perfumes of jungle plants");
  set_listen("default","Faint sounds of the jungle drift in from outside");
  set_exits((["south"   : CITY_ROOM + "palace_entry_hall",
              "north" : CITY_ROOM + "trophy_room",
               "east" : CITY_ROOM + "east_corridor1",
               "west" : CITY_ROOM + "west_corridor1",
             "stairs" : CITY_ROOM + "balcony",
             "garden" : CITY_ROOM + "garden_east"    ]));
  set_door("double door", CITY_ROOM + "garden_east", "garden", 0);
  set_door_description("double door", "These double doors open out"
    +" onto the palace garden. Latticed openings in the wooden doors"
    +" allow you to look out, even when they are closed.");
  set_door("carved door", CITY_ROOM + "palace_entry_hall", "south", 0);
  set_door_description("carved door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods");
  set_door("east door", CITY_ROOM + "east_corridor1", "east", 0);
  set_door_description("east door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods");
  set_door("west door", CITY_ROOM + "west_corridor1", "west", 0);
  set_door_description("west door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods");
  set_door("arched door", CITY_ROOM + "trophy_room", "north", 0);
  set_door_description("arched door", "This door is unusual for Tecqumin architecture, being arched whereas most doors of the area have a square stone lintel.");
  searched = 0;
  pulled = 0;
}

void init() {
   ::init();
   add_action("search_throne", "search");
   add_action("pull_lever", "pull");
} 

int search_throne(string str){
  object prince, guardroom;
  prince = present("epithon", TO);
  if (!str || (str != "throne" && str != "jaguar" 
            && str != "mahogany throne" && str != "jaguar throne")){
    return 0;
  }
  if (objectp(prince)&& TP != prince){
    tell_object(TP, "Epithon holds up a hand to stop you before you can"
     +" reach the throne.");
    tell_room(TO, TPQCN + " starts to move towards the throne, but Epithon"
                 +" holds up a hand to stop " + TP->QO 
                 +" before " + TP->QS + " gets there." ,TP);
    prince->force_me("say Do not think to approach my throne uninvited,"
      +" stranger.");
    return 1;
  }
  // Check to see if the prince is somewhere nearby
  prince = "/daemon/pathfinder_d.c"->far_present(TO, "epithon", 5);
  if (objectp(prince)){
    prince->throne_alert(TP);  // This will summon the prince back to the
                               // room, where he will take revenge against
                               // the person tampering with his throne.
  }
  tell_object (TP, "You find a small lever at the side of the jaguar"
    +" throne");   
  tell_room(ETO, TPQCN + " searches around the jaguar throne.", TP);
} 

void reset(){
  object * princes, prince;
  ::reset();
  princes = children(MOB + "epithon.c");
  if (sizeof(princes)<1||!objectp(princes[0])){
    prince = new(MOB + "epithon.c");
    prince->move(TO);
    tell_room(TO, "%^CYAN%^A light flicker above the throne and the ghost"
                 +" of the Prince of the Tecqumin appears there.");
  } else{
    princes[0]->summon_to_throne();
  }
}
int pull_lever(string str){
  object prince, guardroom;
  prince = present("epithon", TO);
  if (str != "lever" && str != "Lever"){
    return 0;
  }
  if (objectp(prince)&& TP != prince){
    tell_object(TP, "Epithon holds up a hand to stop you before you can"
     +" reach the throne.");
    tell_room(TO, TPQCN + " starts to move towards the throne, but Epithon"
                 +" holds up a hand to stop " + TP->QO 
                 +" before " + TP->QS + " gets there." ,TP);
    prince->force_me("say Do not think to approach my throne uninvited,"
      +" stranger.");
    return 1;
  }
  pull_lever2(TP);
  return 1;
}

void pull_lever2(object ob){
  // Check to see if the prince is somewhere nearby
  object prince, guardroom;
  prince = "/daemon/pathfinder_d.c"->far_present(TO, "epithon", 5);
  guardroom = find_object_or_load(ROOMS + "guardcham");
  if (objectp(prince)){
    prince->throne_alert(ob);  // This will summon the prince back to the
                               // room, where he will take revenge against
                               // the person tampering with his throne.
  }
  tell_object(ob, "%^CYAN%^reaching down between the left side of the"
                 +" throne and the carved jaguar's leg, you pull the small"
                 +" lever that is hidden in between.");
  tell_room(TO, "%^CYAN%^" + ob->QCN + "%^RESET%^%^CYAN%^ reaches down"
               +" between the left side of the throne and the jaguar's leg,"
               +" and appears to pull something that is located in"
               +" between.", ob);

  if (objectp(guardroom)){
    tell_room(TO, "%^MAGENTA%^There is a distinct click, and a grinding"
                 +" sound like ancient machinery echoing in the distance.");
    guardroom->open_chamber(); 
    pulled = 1;
  } else{
    tell_room(TO, "There seems to have been an error here in the throneroom"
                 +". Pulling the lever didn't work. Please make a bug"
                 +" report, including this message.");
  }
  return 1;
}
