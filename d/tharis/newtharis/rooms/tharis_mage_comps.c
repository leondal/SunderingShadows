#include <std.h>
#include "../tharis.h"
inherit ROOM;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Mage Tower - Coded in October 2005 by Circe
// Player Designed Area - Originally Player "shop" 
// Never installed into game prior to Tharis City Remodle
// Design work by Sevotharte & Nightfall, finished by Azalon
// Incorporated into the Tharis City Remodle in February 2009 by Ari

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_name("Adilah's Component Shop");    
   set_short("%^RED%^Adilah's Component Shop%^RESET%^");
   set_long("%^MAGENTA%^As you proceed east from the entrance "+
      "hall, you enter the component shop of %^BOLD%^%^RED%^Adilah,"+
      "%^RESET%^ %^RED%^the gypsy%^MAGENTA%^.  The atmosphere here "+
      "has changed radically from the cool, collected environment "+
      "of the previous room.  The walls are lined with curved "+
      "shelves from the ceiling to the floor, and are laden with "+
      "jars, boxes, and loose components.  Even the small windows "+
      "are no longer visible, covered themselves by the array of "+
      "seemingly randomly placed arcana.  As such, the room is "+
      "dark and %^YELLOW%^dimly lit%^RESET%^ %^MAGENTA%^by candles.  "+
      "There are %^ORANGE%^br%^RED%^as%^ORANGE%^s %^MAGENTA%^pots "+
      "everywhere, some long, containing %^BOLD%^%^BLUE%^pe%^GREEN%^"+
      "aco%^BLUE%^ck%^RESET%^ %^MAGENTA%^feathers, some shallow, "+
      "filled with %^RED%^pot-pouri %^MAGENTA%^and %^ORANGE%^myrtle"+
      "%^MAGENTA%^.  %^BOLD%^%^RED%^Adilah's%^RESET%^ %^MAGENTA%^"+
      "large frame is partially hidden by a counter.  Her "+
      "numerous %^ORANGE%^bangles and bracelets %^MAGENTA%^bang "+
      "together as she makes powder of some component in a large "+
      "pestle and mortar.%^RESET%^\n\n<help shop> will give you "+
      "help on how to use the shop\n");
   set_smell("default","%^RED%^It smells of crushed rose petals, "+
      "talcum powder, and incense.%^RESET%^");
   set_listen("default","%^ORANGE%^The jingling of Adilah's bracelets "+
      "seems to go well with the tune of the cord instrument.%^RESET%^");
   set_exits(([
      "west":ROOMS"tharis_mage_entrance"
   ]));
}

void reset(){
   ::reset();
   if(!present("adilah")) new(MOBS"adilah")->move(TO);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}