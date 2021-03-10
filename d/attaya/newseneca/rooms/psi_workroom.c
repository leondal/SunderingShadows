//workroom for the enclave in new Seneca
//Circe 12/2/07
#include <std.h>
#include "../seneca.h"

inherit "/std/psi_lab";

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("Workroom of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Workroom of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Workroom of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "The curved %^ORANGE%^tan walls %^RESET%^of this workroom "+
      "are lined with %^BOLD%^%^BLACK%^mahogany bookshelves "+
      "%^RESET%^that are stuffed with various %^ORANGE%^ancient "+
      "tomes%^RESET%^, %^BOLD%^bound books%^RESET%^, %^YELLOW%^"+
      "rolled scrolls%^RESET%^, and sheets of %^ORANGE%^aging "+
      "parchment%^RESET%^.  The eye is drawn to a beautiful "+
      "carved %^BOLD%^%^BLACK%^mahogany stand %^RESET%^in the "+
      "middle of the room that supports a flawless %^BOLD%^"+
      "%^CYAN%^crystal ball%^RESET%^.  The southern area of the "+
      "room is a bit crowded with two %^ORANGE%^wooden desks"+
      "%^RESET%^, each with a matching chair.  The northern "+
      "portion of the room has a narrow %^GREEN%^couch %^RESET%^"+
      "where psions hard at work will sometimes lounge to read "+
      "if they plan to be here awhile.  To the west is a small, "+
      "%^RED%^roped-off area %^RESET%^where you occasionally see "+
      "psions step to open a small portal in which to store their "+
      "extra %^BOLD%^crystals%^RESET%^.\n\n"+
      "The command <help workroom> will instruct you in its use.\n"
   );
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"dimensional rift","rope","rift","portal"}) : "The roped-off area "+
         "provides a safe place for people to open the rifts to store "+
         "their crystals.",
      ({"shelves","bookshelves","mahogany bookshelves"}) : "%^BOLD%^"+
         "%^BLACK%^The bookshelves are carved from thick mahogany "+
         "and have been stained to a shade just lighter than ebony.  "+
         "They are filled with knowledge on all sorts of subjects "+
         "an in all forms, from newly bound books to ancient scraps "+
         "of parchment that must be handled with extra care.%^RESET%^",
      ({"desk","desks","wooden desks","wooden desk"}) : "The two "+
         "%^ORANGE%^desks %^RESET%^in the southern portion of the "+
         "room are clearly a matched set.  They are rectangular "+
         "in shape and have been arranged back-to-back to make the "+
         "most of the available space.  Each has a series of drawers "+
         "that hold ink, paper, quills, drying sand, and other implements "+
         "one might need while studying.",
      ({"chair","chairs"}) : "The only chairs in the room are the "+
         "ones that are arranged near the desks.  Each has a short "+
         "back and is armless, probably causing it to be not as "+
         "comfortable as one might hope.",
      "couch" : "%^GREEN%^The couch in the northern portion of the "+
         "room is narrow but comfortable, upholstered in rich "+
         "green.  It seems to be a popular place for psions who "+
         "are researching, as it is close to most of the bookshelves "+
         "and certainly more comfortable than the wooden chairs.%^RESET%^"
   ]));
   set_exits(([
      "east" : ROOMS"psi_landing5",
//      "west" : "/d/av_rooms/myrkul/aryn_lab"
//Removing this exit because it causes players to teleport to Dragon Pass Road
//when Myrkul is not around. ~Circe~ 1/19/13
   ]));
   setOwner("none");
   setLabId("seneca");
   set_door("door","/d/attaya/newseneca/rooms/psi_landing5","east",0,0);
   set_door_description("door","The door in the eastern wall has a unique shape - "+
      "instead of being simply rounded, it has an onion-shaped top that perfectly "+
      "matches the archway around it.  It is crafted of thick %^ORANGE%^pale "+
      "wood %^RESET%^that perfectly matches the %^ORANGE%^tan bands %^RESET%^"+
      "of the tower.  A thick %^ORANGE%^brass ring %^RESET%^serves as the "+
      "door handle.");
}

void reset(){
   ::reset();
   if(!present("crystal ball")) new("/d/magic/obj/crystal_ball")->move(TO);
}
