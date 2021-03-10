#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit ROOM;
int pitted, trenched;


string long_desc();
string plat_desc();

void create() {
  ::create();
  pitted = 0;
  trenched = 0;
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("A jungle clearing");
  set_short("%^GREEN%^A %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
           +"%^GREEN%^ng%^RESET%^%^GREENl%^BOLD%^%^GREEN%^e%^RESET%^"
           +" %^GREEN%^clearing%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([({"platform", "wooden platform"}): (: TO, "plat_desc" :),
               ({"hatch"}) : "The hatch appears to be hinged at one end,"
          +" with a support rope securing the other end to one of the"
          +" branches above it.",
                ({"rope", "support rope"}):  "A single rope is attached to"
          +" the hatch at one end, holding it up from above"  ]));
  set_search("platform","Looking up at the platform from below, you can"
          +" make out a rectangular area that looks like a hatch of some"
          +" sort");
  set_search("wooden platform","Looking up at the platform from below, you"
          +" can make out a rectangular area that looks like a hatch of"
          +" some sort");
  set_search("rope","If you were a very good shot, it might just be"
             +" possible to hit the rope with a missile weapon");
  set_search("support rope","If you were a very good shot, it might just"
             +" be possible to hit the rope with a missile weapon");
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
  set_exits( ([ "north" : TREEHOUSE + "/rooms/" + "treetop_base01" ,
                "northeast" : ROOMS + "treetop_base02" ,
                "east" : TREEHOUSE + "/rooms/" + "treetop_base03" ,
                "southeast" : TREEHOUSE + "/rooms/" + "treetop_base04" ,
                "south" : TREEHOUSE + "/rooms/" + "treetop_base05" ,
                "southwest" : TREEHOUSE + "/rooms/" + "treetop_base06" ,
                "west" : TREEHOUSE + "/rooms/" + "treetop_base07" ,
                "northwest" : TREEHOUSE + "/rooms/" + "treetop_base08"])  );
  set_climb_exits(([
    "climb":({TREEHOUSE + "/rooms/" + "crowsnest",5,0, 30}),
  ]));
}
void init() {
   ::init();
   add_action("shoot_rope", "shoot");
   add_action("throw_rope", "throw");
   add_action("fly_platform", "fly");
   add_action("climb", "climb");
}

int climb(string str){
  object * rooms, room;
  string room_name;
  int i;
  i = random(8)+1;
  room_name = ROOMS  + "platform0" + i;
  set_climb_exits(([
    "climb":({room_name,5,0, 30}),
  ]));
  room = find_object_or_load(room_name);
  if ((int)room->query_screened() >0){
    room = 0;
    rooms = ({});
    for (i=1;i<9;i++){
      room_name = "platform0" + i;
      room = find_object_or_load(TREEHOUSE + "/rooms/" + room_name);
      if (objectp(room)){
        rooms += ({room});
      }
    }
    room = find_object_or_load(TREEHOUSE + "/rooms/"+ "crowsnest");
    if (objectp(room)){
      rooms += ({room});
    }
    rooms += ({TO});
    if (sizeof(rooms)>0){
      for (i=0;i<sizeof(rooms);i++){
        tell_room(rooms[i], TPQCN + "attempts to climb the trunk of the"
                   +" higureon"
                   +" tree, but can't get onto the platform due to the"
                   +" screens that have been positioned round the edge of"
                   +" it.", TP);
      }
    }
    tell_object(TP, "You climb partway up the trunk of the higureon tree,"
                   +" but you can't get onto the platform due to the"
                   +" screens that have been positioned round the edge of"
                   +" it.");
    return 1;
  }
  return 0;
}

string long_desc(){
  string desc;
  desc =  "You stand in a clearing dominated by an enormous"
         +" %^ORANGE%^higureon tree%^RESET%^. Its trunk is almost forty"
         +" feet in diameter and the upper canopy breaks through the mass"
         +" of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^"
         +"ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^ to"
         +" stand alone against the sky. A %^ORANGE%^wooden platform"
         +" %^RESET%^has been built, nestling among its lower branches."
         +" The rest of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
         +"%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^"
         +"teems with life here, bright coloured %^BOLD%^"
         +"%^MAGENTA%^b%^CYAN%^l%^RED%^o%^BLUE%^o%^YELLOW%^m%^MAGENTA%^s"
         +" %^RESET%^ splashing colour across the green backdrop"
         +" of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^li"
         +"%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ge%^RESET%^.\n";
  if ((string)TO->query_exits("up") != "/d/shadowgate/void"){
    desc += "%^ORANGE%^A small hatch is open in the platform, and a rope"
         +" ladder is swinging down within reach.\n";
  }
  return desc;
}
string plat_desc(){
  object plat;
  string desc, plat_name;
  int num_screens, num_stakes, i;
  num_screens = 0;
  num_stakes =1;
  desc = "The platform circles the"
          +" treetrunk, about 30 feet above the ground. It is constructed"
          +" from %^ORANGE%^living wood%^RESET%^ that appears to have been"
          +" woven together, rather than cut and hammered into shape. A"
          +" railing runs around the side of the platform, probably as a"
          +" safety measure.";
  for(i=1;i<9;i++){
    plat_name = TREEHOUSE + "/rooms/" + "platform0" + i;
    plat = find_object_or_load(plat_name);
    if (objectp(plat)){
      num_screens += plat->query_screened();
      num_stakes += plat->query_staked();
    }
  }
  switch(num_screens){
  case 0:
    return desc;
  case 1..2:
    desc += "%^RESET%^\nA few screens have been erected around different"
           +" parts of the platform.";
    break;
  case 3..5:
    desc += "%^RESET%^\nScreens have been erected around approximately"
           +" half of the platform.";
    break;
  case 6..7:
    desc += "%^RESET%^\nScreens have been erected around nearly all of the"
           +" platform.";
    break;
  case 8:
    desc += "%^RESET%^\nScreens have been erected all the way around the"
           +" platform.";
    break;
  }
  switch(num_screens - num_stakes){
  case 0:
    if (num_screens == 0){ break;}
    desc += " The screens have all been fortified with wooden stakes,"
           +" pointing outwards";
    break;
  default:
    if (num_stakes ==0){
      break;
    }
    desc += " Some of the screens have been fortified with wooden"
           +" stakes, pointing outwards";
    break;
  }
  return desc;
}

int hit_test(object ob){
  int thac0;
  object * wpn, target;
  if (!objectp(ob)){
    return 0;
  }
  wpn = ob->query_wielded();
  if (sizeof(wpn)<1||!objectp(wpn[0])){
    return 0;
  }
  target = new(MOB + "rope.c");
  if (!objectp(target)){
    return 0;
  }  
  thac0 = TP->Thaco(0, target, wpn[0]); 
  if(thac0 <= roll_dice(1,20)){
    return 1;
  }
  return 0;
}

int fly_platform(string str){
  object * rooms, room;
  int i;
  string where, room_name;
  if ((int)TP->query_property("flying")!=1){
    tell_object(TP, "You're not flying!"); 
    return 1;
  }
  if (sscanf(str, "to the %s", where)<1 || where != "platform"){
    tell_object(TP, "Did you want to fly to the platform?");
    return 1;
  }
  i = random(8)+1;
  room_name = TREEHOUSE + "/rooms/" + "platform0" + i;
  room = find_object_or_load(room_name);
  if (objectp(room) && (int)rooms->query_spiked() !=0){
    rooms = ({});
    for (i=1;i<9;i++){
      room_name = "platform0" + i;
      room = find_object_or_load(ROOMS + room_name);
      if (objectp(room)){
        rooms += ({room});
      }
    }
    room = find_object_or_load(ROOMS + "crowsnest");
    if (objectp(room)){
      rooms += ({room});
    }
    rooms += ({TO});
    if (sizeof(rooms)>0){
      for (i=0;i<sizeof(rooms);i++){
        tell_room(rooms[i], TPQCN + " takes flight, heading towards the"
                   +" platform, but"
                   +" is warded off by an array of spikes that have been"
                   +" set up to protect it.", TP);
      }
    }

    tell_object(TP, "You take flight, but as you approach the platform,"
                   +" you are warded off by an array of spikes sticking"
                   +" out to protect it.");
    tell_room(TO, TPQCN +" takes flight, heading towards the platform, but"
                   +" is warded off by an array of spikes that have been"
                   +" set up to protect it.", TP);
    return 1;
  }
}

void shoot_rope2(){
  object room;
  tell_room(TO, "The hatch in the bottom of the platform drops open. A"
               +" rope ladder falls down within reach.");
  room = find_object_or_load(ROOMS + "platform01");
  if (objectp(room)){
    tell_room(TO, "The hatch in the bottom of the platform drops open,"
                 +" letting the rope ladder falls down.");
  }
  if (!objectp(room)){
    tell_object(TP, "Error identifying the exit room. Please tell a WIZ");
    return 1;
  }
  add_exit(TREEHOUSE + "/rooms/" + "platform01", "up");
  room->add_exit(TREEHOUSE + "/rooms/" + "t_house_base", "down");
}

int shoot_rope(string str){
  object * wpns, room;
  string exit;
  if (!interact("rope", str)){return 0;}
  wpns = TP->query_wielded();
  if (sizeof(wpns)<1 ||!wpns[0]->is_lrweapon()>0){
    tell_object(TP, "You need to wield a missile weapon of some sort to"
                   +" shoot at things");
    return 1;
  }
  exit = TO->query_exit("up");
  if (exit != "/d/shadowgate/void"){
    tell_object(TP,"You don't need to do that, the hatch is already open");
    return 1;
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/" + "platform1");
  if (hit_test(TP)){
    tell_object(TP,"Taking careful aim with your " + wpns[0]->query_short()
                   +"%^RESET%^, you manage to put a shot right through the"
                   +" support rope above the platform, severing it!");
    tell_room(TO, "Taking careful aim with " + TP->QP + " " 
                  + wpns[0]->query_short() + ", " + TPQCN + " puts a shot"
                 +" right through a rope that is securing one end of a"
                 +" hatch in the platform surrounding the tree!", TP);
    if (objectp(room)){
      tell_room(room, "The hatch in the bottom of the platform drops open,"
                   +" letting the rope ladder falls down.");
    }
    call_out("shoot_rope2", 1);
  } else{
    tell_object(TP, "You take careful aim at the rope, but your shot goes"
                   +" wide!");
    tell_room(TO, TPQCN + " fires a shot vaguely towards the tree, but it"
                +" goes so wide, it makes it hard to tell what " + TP->QS 
                +" was aiming at.", TP);
    if (objectp(room)){
      tell_room(room,TPQCN+" fires a shot vaguely towards the tree, but it"
                +" goes so wide, it makes it hard to tell what " + TP->QS 
                +" was aiming at.");
    }
  }
  return 1;
}