#include <std.h>
#include <move.h>
#include "../tecqumin.h"
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



inherit CVAULT;

string base_desc(); 
string long_desc();
string plant_desc();
string insect_desc();
string flower_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_climate("tropical");
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short( (: TO, "short_desc" :) );
  set_long( (:TO, "long_desc":) );
  set_items(([  ({"plants", "plant"}) : (plant_desc()) ,
                ({"insects", "insect"}) : (insect_desc()) ,
                 ({"flower", "flowers"}) : flower_desc() ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds.\n");
  switch(which_jungle())
  {
  case "a":
  case "g":
  case "h":
    if (!random(10))
    {
      set_monsters(({MOB +"dire_warthog"}), ({random(2) + 1})); 
      set_repop(100);
    }
    break;
  case "b":
  case "f":
    if (!random(10))
    {
      set_monsters(({MOB +"dire_warthog"}), ({random(2) + 1})); 
      set_repop(100);
    }
    if (!random(10))
    {
      set_monsters(({MOB +"ghost_warrior"}), ({1})); 
      set_repop(100);
    }
    break;
  case "c":
  case "e":
    if (!random(10))
    {
      set_monsters(({MOB +"dire_warthog"}), ({random(2) + 1})); 
      set_repop(100);
    }
    if (!random(10))
    {
      set_monsters(({MOB +"orog"}), ({1})); 
      set_repop(100);
    }
    break;
  case "d":
    if (!random(10))
    {
      set_monsters(({MOB +"dire_warthog"}), ({random(2) + 1})); 
      set_repop(100);
    }
    if (!random(10))
    {
      set_monsters(({MOB +"ghost_warrior"}), ({1})); 
      set_repop(100);
    }
    if (!random(10))
    {
      set_monsters(({MOB +"orog"}), ({1})); 
      set_repop(100);
    }
    break;
  case "i":
  case "j":
    break;
  }
}

string which_jungle(){
  string f_name, result, junk;
  int num;
  f_name = base_name(TO);
  num = sscanf(f_name, TEC + "jungle%s/rooms/%s", result, junk);
  if (num <2) return "none";
  return result;
}

string base_short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}

void reset(){
  ::reset();
}

string * query_anchor_points(){
  return ({"low hanging branch", "tree bole", "thick tree root"});
}

string base_desc(){
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
      +" plants.";
}

string long_desc(){

return base_desc() + " The plants grow quickly here, and such trails as there"
      +" are change as often as the lives and habits of the animals and"
      +" other creatures who inhabit this place.\n";
}

void clear_mobs(){
//  report ("clearing mobs");
//  if(mons)  mons = ([]);  // this clears the array
}

void report (string what){
//  "/daemon/reporter_d.c"->report("lujke", "jung_base.c %^MAGENTA%^reports: " + what);
}

void setup_mobs(){
  object * players, room;
  string * mob_names, room_name;
  int i, count, num, * mob_nos;
  report ("Setting up mobs");
  players = children("/std/user.c");
  count = sizeof(players);
  num = 0;
  if (count>0){
    for (i=0;i<count;i++){
      if (objectp(players[i]) && !players[i]->query_true_invis()){
        room = environment(players[i]);
        if (objectp(room)){
          room_name = base_name(room);
          if (interact("tecqumin", room_name)){
            num ++;
          }
        }
      }
    }
  }

  mob_names = ({MOB + "ghost_warrior", MOB + "ghost_psywarrior", MOB + "ghost_priest"});
  mob_nos = ({2,0,1});
  if (!random(3)){
    mob_nos[1] = 1;
  }
  switch(num){  
  case 0..1:
    break;
  case 2..3:
    for (i=0;i<2;i++){
      switch (random(5)){
      case 0..2:
        mob_nos[0] = mob_nos[0] + 1;
      case 3:
        mob_nos[1] = mob_nos[1] + 1;
        break;
      case 4:
        mob_nos[2] = mob_nos[2] + 1;
      }
    }
    break;
  case 4..6:
    for (i=0;i<4;i++){
      switch (random(5)){
      case 0..2:
        mob_nos[0] = mob_nos[0] + 1;
      case 3:
        mob_nos[1] = mob_nos[1] + 1;
        break;
      case 4:
        mob_nos[2] = mob_nos[2] + 1;
      }
    }
    break;
  case 7..1000: //Yeah, yeah, I know. 1000 players is fairly unlikely.
    for (i=0;i<6;i++){
      switch (random(5)){
      case 0..2:
        mob_nos[0] = mob_nos[0] + 1;
      case 3:
        mob_nos[1] = mob_nos[1] + 1;
        break;
      case 4:
        mob_nos[2] = mob_nos[2] + 1;
      }
    }
    break;
  }
  set_monsters( mob_names, mob_nos );
}

void set_monsters(string * mob_names, int * mob_nos){
  int i, count;
  count = sizeof(mob_names);
  if (count>0){
    report ("Mobs set:");
    for (i=0;i<count;i++){
      report (mob_names[i] + ": " + mob_nos[i]);
    }
  }
  ::set_monsters(mob_names, mob_nos);
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

string flower_desc(){
  string * specifics;
  string result;
  specifics = 
  ({ "a %^BOLD%^%^MAGENTA%^p%^WHITE%^i%^MAGENTA%^nk p%^RESET%^%^MAGENTA%^a%^BOLD%^ss%^WHITE%^i%^MAGENTA%^onfl%^RESET%^%^MAGENTA%^o%^BOLD%^wer%^RESET%^, with long slender %^BOLD%^%^MAGENTA%^p%^WHITE%^e%^BOLD%^%^MAGENTA%^tals%^RESET%^ and delicate %^BOLD%^%^WHITE%^white st%^RESET%^a%^BOLD%^%^WHITE%^m%^RESET%^e%^BOLD%^%^WHITE%^n%^RESET%^, with a crown of %^BOLD%^%^GREEN%^green%^RESET%^ and %^BOLD%^%^YELLOW%^yellow %^RESET%^pistil",

"a carnivorous pitcher plant, with bell shaped %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d-p%^RESET%^%^RED%^e%^BOLD%^t%^RESET%^%^RED%^a%^BOLD%^ll%^RESET%^%^RED%^e%^BOLD%^d flowers%^RESET%^, dangling innocently from %^BOLD%^%^GREEN%^long slender stems%^RESET%^, with no hint at all of the deadly purpose of the %^GREEN%^wa%^BOLD%^%^YELLOW%^x%^RESET%^%^GREEN%^y-lea%^BOLD%^%^YELLOW%^v%^RESET%^%^GREEN%^ed%^RESET%^ insect traps below.",

"the flowers of a sea poison tree, whose slender %^BOLD%^%^YELLOW%^yellow stamen sh%^RESET%^%^ORANGE%^ade i%^MAGENTA%^nto %^RED%^red ti%^BOLD%^ps%^RESET%^ as they burst like sunbeams from the centre of their bowl shaped %^ORANGE%^ri%^BOLD%^ngs of peta%^RESET%^%^ORANGE%^ls",

"a %^MAGENTA%^star shaped flower, with %^BOLD%^p%^RESET%^%^MAGENTA%^ur%^BOLD%^p%^RESET%^%^MAGENTA%^le %^BOLD%^p%^RESET%^%^MAGENTA%^eta%^BOLD%^l%^RESET%^%^MAGENTA%^s%^RESET%^ and %^BOLD%^%^YELLOW%^yellow tipped %^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^t%^RESET%^e %^BOLD%^%^WHITE%^st%^RESET%^a%^BOLD%^%^WHITE%^m%^RESET%^e%^BOLD%^%^WHITE%^n",

"what looks like a %^ORANGE%^s%^BOLD%^%^YELLOW%^p%^RESET%^%^ORANGE%^r%^RED%^a%^BOLD%^%^YELLOW%^y %^RESET%^%^ORANGE%^of %^BOLD%^fl%^RESET%^%^RED%^o%^BOLD%^%^YELLOW%^w%^RESET%^%^RED%^e%^BOLD%^%^YELLOW%^r%^RESET%^%^ORANGE%^s%^RESET%^ at first glance, but on closer examination turns out to be a field of %^ORANGE%^o%^RED%^r%^ORANGE%^an%^RED%^g%^ORANGE%^e, %^BOLD%^%^YELLOW%^c%^RESET%^%^ORANGE%^u%^BOLD%^p%^RESET%^%^ORANGE%^-sh%^RED%^a%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^d f%^RED%^u%^ORANGE%^n%^RED%^g%^ORANGE%^i%^RESET%^ with %^BOLD%^%^YELLOW%^yell%^WHITE%^o%^YELLOW%^w s%^WHITE%^t%^YELLOW%^a%^WHITE%^l%^YELLOW%^ks%^RESET%^ and %^BOLD%^%^RED%^sp%^RESET%^%^RED%^i%^BOLD%^ky r%^RESET%^%^RED%^e%^BOLD%^d h%^RESET%^%^RED%^a%^BOLD%^i%^RESET%^%^RED%^rs",

"a spray of %^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^te%^RESET%^ and %^BOLD%^%^MAGENTA%^p%^WHITE%^i%^MAGENTA%^nk p%^RESET%^%^MAGENTA%^e%^BOLD%^t%^WHITE%^a%^BOLD%^%^MAGENTA%^ll%^RESET%^%^MAGENTA%^e%^BOLD%^d %^RESET%^%^MAGENTA%^or%^BOLD%^%^WHITE%^ch%^MAGENTA%^i%^RESET%^%^MAGENTA%^d%^RESET%^-like flowers",

"a %^BOLD%^%^WHITE%^white %^RESET%^o%^BOLD%^%^WHITE%^rch%^RESET%^i%^BOLD%^%^WHITE%^d%^RESET%^ with %^BOLD%^%^YELLOW%^intr%^RED%^i%^YELLOW%^c%^RESET%^%^RED%^a%^BOLD%^%^YELLOW%^te yell%^RESET%^%^ORANGE%^o%^BOLD%^w and %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d%^RESET%^ spotted inner parts, cunningly designed to attract and catch insects",

"a %^MAGENTA%^moth%^BOLD%^%^WHITE%^ o%^YELLOW%^rch%^MAGENTA%^i%^YELLOW%^d%^RESET%^, whose extended petals mimic the shape of its namesake insect",

"a %^BOLD%^%^GREEN%^w%^RESET%^%^GREEN%^a%^BOLD%^vy-st%^RESET%^%^GREEN%^e%^BOLD%^mmed%^RESET%^ helliconia, with %^BOLD%^%^RED%^scoop-s%^YELLOW%^h%^RED%^a%^YELLOW%^p%^RED%^e%^YELLOW%^d yellow and %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d p%^YELLOW%^e%^RED%^t%^YELLOW%^a%^RED%^ls", 

"the anenomie-like %^BOLD%^%^WHITE%^w%^RED%^hite%^RESET%^%^RED%^-t%^BOLD%^ippe%^WHITE%^d %^RED%^red %^WHITE%^f%^RED%^lower%^WHITE%^s%^RESET%^ of an exotic eugenia",

"the %^ORANGE%^o%^RED%^r%^ORANGE%^an%^RED%^g%^ORANGE%^e%^RESET%^, %^ORANGE%^sl%^RED%^i%^ORANGE%^pp%^RED%^e%^ORANGE%^r-sh%^RED%^a%^ORANGE%^p%^RED%^e%^ORANGE%^d fl%^RED%^o%^ORANGE%^w%^RED%^e%^ORANGE%^rs%^RESET%^ of a Calceolaria, which require an insect to crawl right inside to collect its %^BOLD%^%^WHITE%^nectar%^RESET%^, becoming thoroughly smothered in %^BOLD%^%^YELLOW%^pollen %^RESET%^in the process",

"the delicate flowers of a milkweed plant, with %^BOLD%^%^YELLOW%^yellow inner parts%^RESET%^ sitting up like cups above a fringing doily of %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d p%^RESET%^%^RED%^e%^BOLD%^t%^RESET%^%^RED%^a%^BOLD%^ls",

"a nest of spiky %^ORANGE%^or%^RED%^a%^ORANGE%^n%^RED%^g%^ORANGE%^e%^RESET%^, %^BOLD%^%^YELLOW%^yellow %^RESET%^and%^BOLD%^%^RED%^ red br%^RESET%^%^ORANGE%^o%^BOLD%^mel%^RESET%^%^ORANGE%^i%^BOLD%^ad fl%^RESET%^%^ORANGE%^o%^BOLD%^we%^RED%^rs",

"the %^RED%^fl%^BOLD%^a%^RESET%^%^RED%^m%^BOLD%^i%^RESET%^%^RED%^ng %^ORANGE%^or%^RED%^a%^ORANGE%^n%^RED%^g%^ORANGE%^e %^RED%^fl%^ORANGE%^o%^RED%^w%^ORANGE%^e%^RED%^rs%^RESET%^ of a monkey brush plant, whose slender %^BOLD%^%^RED%^r%^YELLOW%^ed-tippe%^RED%^d%^YELLOW%^ yellow st%^RESET%^%^ORANGE%^a%^BOLD%^m%^RESET%^%^ORANGE%^e%^BOLD%^n %^RESET%^burst forth like bristles from a bed or tightly packed %^RED%^r%^BOLD%^ed pet%^RESET%^%^RED%^a%^BOLD%^ls%^RESET%^.",

"an enormous %^RED%^r%^ORANGE%^a%^RED%^ffl%^ORANGE%^e%^RED%^s%^BOLD%^%^YELLOW%^i%^RESET%^%^RED%^a fl%^ORANGE%^o%^RED%^w%^ORANGE%^e%^RED%^r%^RESET%^, over a metre wide, which invites birds and even small mammals inside to collect its precious %^BOLD%^%^WHITE%^nectar",

"a bed of %^BOLD%^%^BLUE%^bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e p%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^ll%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^d fl%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^w%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^rs%^RESET%^ nestling at the foot of a great tree",

"a near spherical flower with %^BOLD%^%^YELLOW%^w%^RESET%^%^ORANGE%^a%^BOLD%^vy y%^RESET%^%^ORANGE%^e%^BOLD%^ll%^RESET%^%^ORANGE%^o%^BOLD%^w pet%^RESET%^%^ORANGE%^a%^BOLD%^ls%^RESET%^ and %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^n %^RESET%^%^GREEN%^i%^BOLD%^nn%^RESET%^%^GREEN%^e%^BOLD%^r p%^RESET%^%^GREEN%^a%^BOLD%^rts",

"a spray of flower-like %^BOLD%^%^WHITE%^white circular m%^RESET%^u%^BOLD%^%^WHITE%^shr%^RESET%^oo%^BOLD%^%^WHITE%^m c%^RESET%^a%^BOLD%^%^WHITE%^ps%^RESET%^, growing from the delicate tip of a tree twig, where the bark is thin enough for them to gain purchase and feed from the %^GREEN%^t%^ORANGE%^re%^GREEN%^e"
});
  result = "There are many wonderful and astonishing flowers in the jungle. You gaze at " + specifics[random(sizeof(specifics))];
  return result;
}
