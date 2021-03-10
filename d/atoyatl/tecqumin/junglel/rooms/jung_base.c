#include <std.h>
#include <move.h>
#include "../../tecqumin.h"
#define INSECTS ({"a small cricket", "a %^BOLD%^%^GREEN%^green katydid%^RESET%^, perched"\
       +" on a nearby %^ORANGE%^tree%^RESET%^, its 3 inch long body cunningly shaped to resemble a"\
       +" %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^af%^RESET%^. It is moving, or you"\
       +" might not have seen it.", "a large grasshopper, crawling over a pretty %^ORANGE%^or%^BOLD%^"\
       +"%^MAGENTA%^a%^RESET%^%^ORANGE%^ng%^BOLD%^%^MAGENTA%^e %^RESET%^%^ORANGE%^fl%^BOLD%^"\
       +"%^MAGENTA%^o%^RESET%^%^ORANGE%^w%^BOLD%^%^MAGENTA%^e%^RESET%^%^ORANGE%^r%^RESET%^",\
        "a gathering of stoneflies, buzzing through the air like a miniature cloud", "a stick insect"\
       +" on a nearby tree. It is so well camoflaged it is in serious danger of being used as"\
       +" kindling", "a large earwig, some two and a half inches long, crawling over the rotting"\
       +" remains of a dead treestump", "a heavily armoured beetle forcing its way through some underbrush",\
       "a beautiful %^BOLD%^%^BLUE%^blue"\
       +" %^BOLD%^%^CYAN%^e%^BOLD%^%^BLUE%^mp%^BOLD%^%^CYAN%^o%^BOLD%^%^BLUE%^r%^BOLD%^%^CYAN%^o%^BOLD%^%^BLUE%^r"\
       +" butterfly%^RESET%^ floating through the canopy",\
        "a %^BOLD%^%^YELLOW%^pr%^BOLD%^%^BLACK%^e%^BOLD%^%^YELLOW%^dat%^BOLD%^%^BLACK%^o%^BOLD%^%^YELLOW%^ry"\
       +" w%^BOLD%^%^BLACK%^a%^BOLD%^%^YELLOW%^sp%^RESET%^ zipping through the air above your head",\
        "a mosquito nearby, your eyes drawn to it by the high pitched whine of its flight",\
        "an odd looking %^BOLD%^%^RED%^red and bl%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^ck"\
       +" s%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^i%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^e%^BOLD%^%^RED%^r%^RESET%^ on a nearby tree",\
        "a troop of %^BOLD%^%^RED%^fire ants%^RESET%^ marching across the trail ahead of you",\
        "a large, %^BOLD%^%^BLACK%^hairy-legged spider%^RESET%^ perched on a web strung between two widely spaced branches" })


string r_path, n_room, s_room, e_room, w_room, * spec_rooms;  


inherit ROOM;

string long_desc();
string plant_desc();
string insect_desc();

void create() {
  mapping map;
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_climate("tropical");
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short("%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle");
  set_long( (:TO, "long_desc":) );
  set_items(([  ({"plants", "plant"}) : (plant_desc()) ,
                ({"insects", "insect"}) : (insect_desc()) ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
//  set_property("no clean", 1);

}
void init() {
  object mazeroom;
  string path, file, eastroom, westroom, northroom, southroom, *pathfile, *spec_rooms, *exits ;
   ::init();
  if (sizeof(query_exits())<1){
    BUILDER->restore_exits(TO);
  }
/*  file = file_name(TO);
  pathfile = path_file(file);
  path = pathfile[0];
  file = path + "/j_maze0.c";
  mazeroom = find_object_or_load(file);
  if (!objectp(mazeroom)){
  file = path +"/jungle01.c";
  mazeroom = find_object_or_load(file);
  }
  if(!objectp(mazeroom)){
    tell_room(TO, "There's been an error with the maze. Please send a bug report, advising the wizzes to look in the jung_base file.");
    return;
  }
  exits = mazeroom->query_exits();
  if (sizeof(exits)<1){
    BUILDER->restore_exits(mazeroom);
    exits = mazeroom->query_exits();
    switch(path){
    case JUNG_ROOM:
      southroom = WEMIC + "path14.c";
      northroom = JUNG_ROOM + "j_link1.c";
      eastroom = JUNG_ROOM + "j_link8a.c";  
      spec_rooms = ({JUNG_ROOM + "jung_clearing.c", JUNG_ROOM + "jung_waterhole"});
      break;
    case JUNG_ROOM2:
      spec_rooms = ( ({ }) );
      southroom = JUNG_ROOM + "j_link1a.c";
      northroom = JUNG_ROOM + "j_link2.c";
      break;
    case JUNG_ROOM3:
      southroom = JUNG_ROOM + "j_link2a.c";
      eastroom = JUNG_ROOM + "j_link3.c";  
      spec_rooms = ( ({ }) );
      break;
    case JUNG_ROOM4:
      southroom = ROOMS + "step1.c";
      eastroom = JUNG_ROOM + "j_link4.c";
      westroom = JUNG_ROOM + "j_link3a.c";  
      spec_rooms = ( ({ }) );
      break;
    case JUNG_ROOM5:
      southroom = JUNG_ROOM + "j_link5.c";
      westroom = JUNG_ROOM + "j_link4a.c";  
      spec_rooms = ( ({ }) );
      break;
    case JUNG_ROOM6:
      southroom = JUNG_ROOM + "j_link6.c";
      northroom = JUNG_ROOM + "j_link5a.c";
      spec_rooms = ( ({ }) );
      break;
    case JUNG_ROOM7:
      northroom = JUNG_ROOM + "j_link6a.c";
      westroom = JUNG_ROOM + "j_link7.c";  
      spec_rooms = ( ({ }) );
      break;
    case JUNG_ROOM8:
      eastroom = JUNG_ROOM + "j_link7a.c";
      westroom = JUNG_ROOM + "j_link8.c";  
      spec_rooms = ( ({ }) );
      break;
    }
    if (sizeof(exits)<1){
      "/d/atoyatl/maze_d.c"->set_roompath(path + "j_maze");
      "/d/atoyatl/maze_d.c"->set_special_rooms( spec_rooms );
      if (stringp(southroom)){
        "/d/atoyatl/maze_d.c"->set_southroom(southroom);
      }
      if (stringp(northroom)){
        "/d/atoyatl/maze_d.c"->set_northroom(northroom);
      }
      if (stringp(eastroom)){
        "/d/atoyatl/maze_d.c"->set_eastroom(eastroom);
      }
      if (stringp(westroom)){
         "/d/atoyatl/maze_d.c"->set_westroom(westroom);
      }
      "/d/atoyatl/maze_d.c"->init_maze(5, 5, path + "/j_maze", 30);
    }    
  }
  if (sizeof(query_exits())<1){
    TP->move(path+"/j_maze0.c");
  } */
}

void make_maze(){
  if (!stringp(r_path)){ return; }
  "/d/atoyatl/maze_d.c"->set_roompath(r_path);
  if (stringp (s_room)){
    "/d/atoyatl/maze_d.c"->set_southroom(s_room);
  }
  if (stringp (n_room)){
    "/d/atoyatl/maze_d.c"->set_northroom(n_room);
  }
  if (stringp (e_room)){
    "/d/atoyatl/maze_d.c"->set_eastroom(e_room);  
  }
  if (stringp (w_room)){
    "/d/atoyatl/maze_d.c"->set_westroom(w_room);  
  }
  if (sizeof(spec_rooms)){
    "/d/atoyatl/maze_d.c"->set_special_rooms( ({ spec_rooms }) );
  } else {
    "/d/atoyatl/maze_d.c"->set_special_rooms( ({  }) );
  }
  "/d/atoyatl/maze_d.c"->init_maze(5, 5, r_path, 30);
}

void remove_maze(){
  int i, j, num, num2;
  object mazeroom;
  string * roomnames, exits;
  roomnames = spec_rooms;
  if (stringp (s_room)){
    roomnames += ({s_room});
  }
  if (stringp (n_room)){
    roomnames += ({n_room});
  }
  if (stringp (e_room)){
    roomnames += ({e_room});
  }
  if (stringp (w_room)){
    roomnames += ({w_room});
  }  
  for (i=0;i<71;i++){
    roomnames += ({r_path + i});
  }
  num = sizeof(roomnames);
  for (i=0;i<num;i++){
    mazeroom = find_object_or_load(roomnames[i]);
    if (!objectp(mazeroom)){ continue;}
    exits = mazeroom->query_exits();
    num2 = sizeof(exits);
    if (num2>0){
      for (j=0;j<num2;j++){ 
        "/d/atoyatl/maze_d.c"->remove_exit(mazeroom,exits[j]);
        if ((string)mazeroom->query_exit(exits[j]) != "/d/shadowgate/void"){
          mazeroom->remove_exit(exits[j]);
        }
      }
    }
    "/d/atoyatl/maze_d.c"->remove_maze(file_name(mazeroom)); 
  }
}


string long_desc(){
return "%^GREEN%^The jungle forms a dense %^BOLD%^%^BLACK%^tangle"
      +"%^RESET%^%^GREEN%^, barring passage in most directions. %^BOLD%^"
      +"%^GREEN%^Vibrant %^RESET%^%^GREEN%^gr%^BOLD%^%^GREEN%^ee%^RESET%^"
      +"%^GREEN%^n %^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^"
      +"%^GREEN%^nts%^RESET%^%^GREEN%^ with thick, waxy leaves gather"
      +" round the bases of %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^"
      +" growth trees with thick boles and %^RESET%^%^ORANGE%^twisted"
      +" branches%^GREEN%^. %^BOLD%^%^WHITE%^F%^MAGENTA%^l%^BOLD%^"
      +"%^WHITE%^ow%^CYAN%^e%^BOLD%^%^WHITE%^rs%^RESET%^%^GREEN%^ with"
      +" %^BOLD%^%^MAGENTA%^v%^YELLOW%^i%^MAGENTA%^v%^CYAN%^i%^MAGENTA%^"
      +"d %^BLUE%^c%^RED%^o%^YELLOW%^l%^MAGENTA%^o%^CYAN%^u%^YELLOW%^r"
      +"%^BLUE%^s%^RESET%^%^GREEN%^ spring out from %^BOLD%^%^BLACK%^dark"
      +"%^RESET%^%^GREEN%^, surprising corners and thick, %^RESET%^"
      +"%^ORANGE%^trailing vines%^GREEN%^ wrap around the trees and other"
      +" plants. The plants grow quickly here, and such trails as there"
      +" are change as often as the lives and habits of the animals and"
      +" other creatures who inhabit this place.\n";
}

string plant_desc(){
  string result, *specifics;
  int i;
  specifics = ({});
  i = random(5);
  switch (i){
  case 0:
    result = "In amongst the great %^ORANGE%^boles%^RESET%^ of ancient"
          +" trees, %^BOLD%^%^GREEN%^plants%^RESET%^ of all sizes and"
          +" shapes flourish in the fertile soil of the jungle. Your eyes"
          +" light upon ";
    break;
  case 1:
    result = "The jungle is full of all sorts of plant life. You notice ";
    break;
  case 2:
    result = "The trees all around you have massive trunks and twisted"
          +" limbs. Funghi and moss grow on every surface, but your eye is"
          +" drawn to ";
    break;
  case 3:
    result = "There is no escaping the %^BOLD%^%^GREEN%^pl%^RESET%^"
          +"%^GREEN%^a%^BOLD%^%^GREEN%^nts%^RESET%^ here. Their teeming"
          +" growth threatens to overwhelm the trail at any time. Off to"
          +" one side you spot ";
    break;
  case 4:
    result  = "From the canopy high above you to the soft undergrowth of"
             +" the forest, plants are everwhere. Your attention is caught"
             +" by ";
    break;
  }
  specifics +=({"an evergreen %^GREEN%^orc's horn plant%^RESET%^ with"
            +" long, strap-shaped leaves and rounded umbels of"
            +" %^BLUE%^deep bl%^RESET%^%^MAGENTA%^u%^RESET%^%^BLUE%^e"
            +"%^RESET%^, trumpet-shaped flowers"});
  specifics +=({"a vigorous growth of Dreth's fingers, with massive,"
            +"%^GREEN%^sh%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^ny,"
            +" %^BOLD%^%^GREEN%^lush green%^RESET%^, rounded leaves"});
  specifics +=({"an elephant ear acacia, a spectacular tree with huge"
               +" %^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^lv%^CYAN%^e%^WHITE%^"
               +"r %^BLUE%^b%^CYAN%^l%^WHITE%^u%^CYAN%^e%^RESET%^, leaf"
               +" like growths up to 14 inches long and a foot"
               +" across. Mixed in amongst the foliage are %^BOLD%^"
               +"%^YELLOW%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ch"
               +" g%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^ld%^RESET%^"
               +"%^ORANGE%^e%^BOLD%^%^YELLOW%^n fl%^RESET%^%^ORANGE%^o"
               +"%^BOLD%^%^YELLOW%^w%^RESET%^%^ORANGE%^e%^BOLD%^"
               +"%^YELLOW%^rs%^RESET%^."});
specifics +=({"an attractive %^GREEN%^shrub%^RESET%^ covered with"
             +" %^MAGENTA%^purple%^RESET%^ berries that seem to be"
             +" attracting large numbers of birds"});
specifics +=({"a slow growing succulent like plant with a swollen,"
             +" contorted base and an abundance of %^BOLD%^%^RED%^c"
             +"%^MAGENTA%^a%^RED%^rm%^WHITE%^i%^RED%^ne-r%^MAGENTA%^o"
             +"%^RED%^se%^RESET%^ flowers."});
specifics +=({"a three foot tall cycad with long, arching"
             +" %^BOLD%^%^BLUE%^bl%^GREEN%^u%^BLUE%^e-%^GREEN%^gr"
             +"%^BLUE%^ee%^GREEN%^n%^RESET%^ leaflets and attractive"
             +" %^ORANGE%^rusty brown%^RESET%^ cones."});
specifics +=({"a 'horn of plenty', a striking plant with"
             +" %^BOLD%^%^WHITE%^fragrant white%^RESET%^ trumpet shaped"
             +" flowers held upright above %^BOLD%^%^BLUE%^bl%^GREEN%^u"
             +"%^BLUE%^e-%^GREEN%^gr%^BLUE%^ee%^GREEN%^n%^RESET%^"
             +" foliage."});
specifics +=({"a very small, shrubby tree with large pendulous flowers"
             +" almost ten inches in length. The flowers are tubular, and"
             +" %^BOLD%^%^RED%^br%^RESET%^%^RED%^i%^BOLD%^%^RED%^ght"
             +" r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^at the mouth,"
             +" fading to %^BOLD%^%^YELLOW%^yellow%^RESET%^ at the base."
             +" It has long, oval shaped leaves."});
specifics +=({"small tree-like shrub, around 10 feet tall with 8 inch"
             +" long soft hairy leaves in pairs. The leaves have smooth,"
             +" unblemished margins and hanging from the branches are"
             +" sweet-musky-scented, %^BOLD%^%^WHITE%^white%^RESET%^"
             +" flowers, %^BOLD%^%^WHITE%^ve%^GREEN%^i%^WHITE%^n%^GREEN%^e"
             +"%^WHITE%^d%^RESET%^ with green. "});
specifics +=({"a colocasia with a %^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^"
             +"a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^p%^BOLD%^"
             +"%^BLACK%^u%^RESET%^%^MAGENTA%^rple%^RESET%^ stem, tending"
             +" towards black. The leaf ribs are deepest %^BLUE%^m%^BOLD%^"
             +"%^BLACK%^i%^RESET%^%^BLUE%^dn%^BOLD%^%^BLACK%^i%^RESET%^"
             +"%^BLUE%^ght bl%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^e"
             +"%^RESET%^."});
specifics +=({"a '%^BOLD%^%^BLACK%^Black Knight%^RESET%^' canna plant,"
             +" gorgeous in both bloom and foliage.  The leaves are"
             +" %^GREEN%^str%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^p%^BOLD%^"
             +"%^GREEN%^e%^RESET%^%^GREEN%^d%^RESET%^, cast very dark and"
             +" the large %^BOLD%^%^RED%^bright red fl%^RESET%^%^RED%^o"
             +"%^BOLD%^%^RED%^wers%^RESET%^ are quite stunning."});
 i = random(sizeof(specifics));
 result += specifics[i];
 return result;
}

string insect_desc(){
  string desc;
  desc = "The jungle is teeming with insect life. You spot ";
  desc += INSECTS[random(sizeof(INSECTS))];
  return desc;
}

string query_short(){
  init();
  return ::query_short();
}
