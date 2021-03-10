#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CITY_JUNG;

int swing_me(string str);
string swing_dest;
string blockdir;

void create() {
  ::create();
  add_item( ({"canopy", "branches"}), "The branches of the"
  +" trees on either side of the canal stretch out over the"
  +" %^BOLD%^%^BLACK%^black%^RESET%^ and %^GREEN%^green%^RESET%^"
  +" water. Trailing %^BOLD%^%^GREEN%^vines%^RESET%^ hang down"
  +" from them, touching the water in places.");

  add_item( "sky", "It's quite a change to see a patch of"
  +" %^BOLD%^%^CYAN%^clear sky%^RESET%^, after being beneath the"
  +" %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" canopy%^RESET%^.");

  add_item( ({"vine", "vines", "trailing vines"}), "The %^GREEN%^trailing"
  +" vines%^RESET%^ loop and curl around the %^ORANGE%^branches%^RESET%^"
  +" before dropping toward the"
  +" %^GREEN%^w%^BLUE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^er%^RESET%^."
  +" Some of them look thick enough to swing on.");

  add_item( ({"canal", "disused canal", "abandoned canal"}),"The"
  +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal%^RESET%^"
  +" looks as though it has been disused for many years."
  +" The %^BLUE%^water%^RESET%^ is thick with %^BOLD%^%^GREEN%^weeds"
  +" %^RESET%^and varies in shade from %^GREEN%^green%^RESET%^ to"
  +" %^BOLD%^%^BLACK%^black%^RESET%^. In places it looks more like"
  +" %^GREEN%^swamp%^RESET%^; only the remains of stone banks keep it"
  +" straight and confirm that it was once built for a purpose.");

}

void init(){
  ::init();
   add_action("swing_me","swing");
}

string long_desc(){
  return ::long_desc() + "A %^BLUE%^disused canal%^GREEN%^ runs"
  +" north-south through the jungle here, blocking further travel"
  +" to the " + blockdir +".  The branches of the"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" canopy stretch out above the canal but do not meet in the"
  +" middle, and a small patch of %^BOLD%^%^CYAN%^blue"
  +" sky%^RESET%^%^GREEN%^ is revealed through a ragged curtain"
  +" of trailing vines.";
}

string jung_desc(){
  return ::long_desc();
}

int swing_me(string str){
  object dest;
  if (!objectp(TP)){return 0;}
  if (!objectp(ETP)) {tell_object(TP, "There is a problem with"
    +" the room you are in. Please make a bug report!");}
  if (str == "on vine") {
    tell_object(TP, "You swing out over the canal on a"
      +" %^GREEN%^vine%^RESET%^, then return to where you were."
      +" What fun!");
    tell_room(ETP, TPQCN + "swings out over the canal on a"
      +" %^GREEN%^vine%^RESET%^, then lands back on the bank"
      +" where " + TPQS + " came from.", TP);
    return 1;
  }
  if (str != "across" && str != "over" && str != "across canal" 
   && str != "over canal" && str != "to other side" 
   && str != "to opposite bank"){
  tell_object(TP, "You can't find a way to swing " + str + ".");
    return 1;
  }
  dest=find_object_or_load(CITY_ROOM + swing_dest);
  if (!objectp(dest)){
    tell_object(TP, "There's a problem with the room you were"
     +" trying to swing to. Please tell a wiz, or make a bug report"
     +" from here.");
    return 1;
  }
  tell_object (TP, "You take a short run to gain momentum, then"
   +" swing out across the"
   +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal"
   +" %^RESET%^on a %^GREEN%^vine%^RESET%^, landing on the other"
   +" side");
  tell_room (TO, TPQCN + "takes a short run up, then swings out"
   +" across the"
   +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal"
   +" %^RESET%^on a %^GREEN%^vine%^RESET%^, landing on the other"
   +" side.", TP);
  tell_room(dest, TPQCN + " swings in on a %^GREEN%^vine%^RESET%^,"
   +" from the other side of the"
   +" %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nal.");
  TP->move(dest);
  TP->force_me("look");
  return 1;
}
