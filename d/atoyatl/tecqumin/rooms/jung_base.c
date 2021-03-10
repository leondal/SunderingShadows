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



inherit ROOM;

string base_desc();
string long_desc();
string plant_desc();
string insect_desc();

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
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
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

