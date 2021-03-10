//weapon.c - weapons shop for new Seneca
//~Circe~ 1/20/08 - will include some +1 items that levels
//21 and above can buy to help reequip
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_indoors(1);
   set_light(3);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Weapon Shop, Seneca");
   set_short("%^BOLD%^Weapon Shop, Seneca%^RESET%^");
   set_long("%^BOLD%^Weapon Shop, Seneca%^RESET%^\n"+
      "Dotting the smooth floor made of %^BOLD%^%^BLACK%^slate tiles "+
      "%^RESET%^in different %^BOLD%^%^BLACK%^s%^RESET%^h"+
      "%^BOLD%^a%^BLACK%^d%^RESET%^e%^BOLD%^s %^RESET%^of "+
      "%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^a%^BLACK%^y%^RESET%^ "+
      "are several %^CYAN%^glass cases %^RESET%^lined with "+
      "soft %^BOLD%^velvet%^RESET%^ along with polished %^BOLD%^"+
      "%^BLACK%^wooden stands%^RESET%^.  %^BOLD%^Weapons %^RESET%^"+
      "in countless different shapes, sizes, and types fill this "+
      "shop, offering a wide range of choices to soldiers and "+
      "adventurers alike.  Along the western wall is a deep maroon "+
      "%^RED%^counter %^RESET%^varnished until it g%^BOLD%^l"+
      "%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^s "+
      "%^RESET%^in the light of the %^BOLD%^candles %^RESET%^"+
      "burning in %^BOLD%^%^BLACK%^iron sconces %^RESET%^along the "+
      "walls.  The smooth %^BOLD%^pale stone %^RESET%^of the "+
      "shop walls is unbroken save by the long, narrow, open "+
      "windows that run along the outer walls just below the "+
      "ceiling that help diffuse heat from the smithy.  The "+
      "finishing touch to the shop is the pair of small %^ORANGE%^"+
      "wooden steps%^RESET%^ standing near the counter.  One is "+
      "placed on each side, likely to allow smaller races to "+
      "comfortably conduct business across the %^RED%^countertop "+
      "%^RESET%^sized for a human.\n");
   set_items(([
      ({"floor","tiles","slate tiles"}) : "%^BOLD%^%^BLACK%^The "+
         "floor of this shop is tiled in rectangular pieces of "+
         "%^RESET%^slate %^BOLD%^%^BLACK%^in varying s%^RESET%^h"+
         "%^BOLD%^a%^BLACK%^d%^RESET%^e%^BOLD%^s %^RESET%^of "+
         "%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^a%^BLACK%^y.  It "+
         "is always kept neatly swept and gleaming, helping "+
         "give the shop a clean, welcoming atmosphere.%^RESET%^",
      ({"glass cases","glass case","case","cases","velvet"}) : 
         "Set atop %^ORANGE%^wooden stands %^RESET%^are the %^CYAN%^"+
         "glass display cases %^RESET%^that hold many of the "+
         "smaller weapons for sale here.  Tiny %^BOLD%^daggers "+
         "%^RESET%^are nestled into the %^BOLD%^creamy velvet "+
         "%^RESET%^alongside %^CYAN%^steel knuckles %^RESET%^"+
         "and %^BOLD%^throwing stars%^RESET%^.  Here and there, "+
         "coiled %^BOLD%^%^BLACK%^leather whips %^RESET%^have "+
         "been displayed as well.",
      ({"stands","wooden stands","stand","wooden stand"}) : "The "+
         "wooden stands spread throughout the room display weapons "+
         "placed upright into slots.  Hefty %^ORANGE%^hammers "+
         "%^RESET%^are kept heads down and stand among bristling "+
         "%^BOLD%^pikes %^RESET%^and other polearms.  Entire racks "+
         "hold %^BOLD%^swords %^RESET%^in different sizes and "+
         "styles while %^BOLD%^%^BLACK%^maces %^RESET%^and "+
         "%^YELLOW%^morningstars%^RESET%^ are gathered in other "+
         "places.",
      ({"counter","maroon counter"}) : "%^RED%^The long counter "+
         "along the western wall is carved from redwood and "+
         "varnished to a high shine.  It seems to have been made "+
         "for someone human-sized despite the dwarven owner.%^RESET%^",
      ({"sconces","sconce","iron sconces","candles"}) : "The walls "+
         "are decorated with functional %^BOLD%^%^BLACK%^iron "+
         "sconces %^RESET%^that hold slender %^BOLD%^candles"+
         "%^RESET%^ that provide illumination for the shop.",
      ({"wall","walls"}) : "The walls are smooth pale stone that "+
         "has been carefully hewn.  They are broken only by the "+
         "doorways to the east and south and the narrow windows "+
         "near the ceiling.",
      ({"window","windows"}) : "Providing additional illumination "+
         "and an escape for heat are the long, narrow windows that "+
         "run parallel to the roof near the ceiling.  They are "+
         "glassless, allowing the heat of the smithy to dissipate.",
      ({"steps","wooden steps","pair of wooden steps"}) : "Each "+
         "set of steps is about three feet wide and a food deep, "+
         "rising a couple of feet in the air.  They are light "+
         "enough to be moved when needed, and they provide a safe "+
         "place for those shorter in stature - such as the owner "+
         "himself - to conduct business over the taller counter."
   ]));
   set_exits(([
      "south" : ROOMS"viento56",
      "east" : ROOMS"smithy"
   ]));
   set_smell("default", "The acrid odor of burning metal fills the air.");
   set_listen("default", "The sound of ringing hammers and a "+
      "crackling fire floats in from the smithy.");
   set_door("weaponsmith door","/d/attaya/newseneca/rooms/viento56","south",0,0);
   set_door_description("weaponsmith door","The wide wooden door in the "+
      "the southern wall leads back to Viento Lane.  It is often left "+
      "open to keep the room cool.");
   if(query_night()==1){
      set_open("weaponsmith door",0);
      "/d/attaya/newseneca/rooms/viento56"->set_open("weaponsmith door",0);
   }else{
      set_open("weaponsmith door",1);
      "/d/attaya/newseneca/rooms/viento56"->set_open("weaponsmith door",1);
   }
}

void reset(){
   ::reset();
   if(!present("weaponsmith"))
      find_object_or_load(MON"weaponsmith")->move(TO);
}