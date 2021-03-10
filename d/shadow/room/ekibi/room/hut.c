//hut.c - Rosinden's home
//Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_terrain(HUT);
   set_travel(FOOT_PATH);
   set_name("A Small Hut");
   set_indoors(1);
   set_short("A Small Hut");
   set_long("This small hut has been crafted with a well-built "+
      "%^ORANGE%^wooden frame %^RESET%^stretched with cured "+
      "%^RED%^hides%^RESET%^.  The hut has an unusual shape, "+
      "being a basic oval jutting with two square wings.  In "+
      "each of these wings, %^ORANGE%^tables %^RESET%^have been "+
      "set up, supporting all manner of %^CYAN%^experiments"+
      "%^RESET%^.  There are a couple of small %^ORANGE%^wooden "+
      "stools %^RESET%^that look as though they are sized for "+
      "a gnome, and the heights of the tables seem to match.  "+
      "Near the southern end of the hut is a %^GREEN%^cot "+
      "%^RESET%^covered in %^CYAN%^blankets %^RESET%^and "+
      "various articles of %^YELLOW%^clothing%^RESET%^.\n");
   set_listen("default","The sound of bubbling experiments and "+
      "chirping insects fills the hut.");
   set_smell("default","Strange acrid odors fill the air here.");
   set_items(([
      ({"frame","wooden frame","hides","hut"}) : "The wooden "+
         "frame appears well-made, though it looks as though "+
         "the builder improvised in places.  It's quite possible "+
         "the hut was made by one person.  The tanned hides "+
         "are stretched well, but occasional marks hint that "+
         "they were not cured by a master.",
      ({"table","tables","experiments"}) : "The tables are various "+
         "shapes and sizes, but all support obvious experiements.  "+
         "Crickets chirp sadly in jars beside strange slivers of "+
         "a %^MAGENTA%^glowing stone%^RESET%^.  Similar "+
         "tests are being done with all kinds of bugs - fireflies, "+
         "cockroaches, and everything in between.  Small braziers "+
         "and bits of ice help to control the temperatures around "+
         "certain experiments as well.",
      ({"stool","stools","wooden stools"}) : "The small stools "+
         "are made with three legs and are scattered around the "+
         "room, providing whoever lives here with several seating "+
         "options.",
      ({"cot","clothing","blankets"}) : "The green cot is covered "+
         "with a messy array of clothing and blankets, indicating "+
         "that the one who sleeps here is perhaps a little "+
         "absent-minded."
   ]));
   set_exits(([
      "north" : PATHEXIT"p2"
   ]));
}

void reset(){
   ::reset();
   if(!present("rosinden")){
      new(MON"rosinden")->move(TO);
   }
}