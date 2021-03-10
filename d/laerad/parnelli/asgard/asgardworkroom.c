#include <std.h>

inherit "/std/psi_lab";

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
//   set_property("no teleport",1);
   set_indoors(1);
   set_name("The Sublime Cut Workroom");
   set_short("The Sublime Cut Workroom");
   set_long(
      "%^BOLD%^Workroom of the Sublime Cut, Asgard%^RESET%^\n"+
      "%^RESET%^%^ORANGE%^This is a rather small room cozily "+
      "furnished with several %^MAGENTA%^high-backed chairs "+
      "%^ORANGE%^with plush velvet cushions.  A thick "+
      "%^CYAN%^woven rug %^ORANGE%^with swirling %^MAGENTA%^"+
      "accents %^ORANGE%^in shades that complement the furniture "+
      "covers much of the wooden floor.  In the center of the room "+
      "is a flawless %^BOLD%^%^CYAN%^crystal ball %^RESET%^%^ORANGE%^"+
      "on a wooden stand.  Lining the outer walls are %^MAGENTA%^"+
      "mahogany bookshelves %^ORANGE%^filled with tomes on "+
      "subjects from history to mythology to psionic theory.  "+
      "Matching round tables are spaced out among the chairs, "+
      "each topped with several %^RESET%^beeswax candles %^ORANGE%^"+
      "provided for use by the customers who frequent here.  "+
      "Near the northwestern corner, a small area is roped off to "+
      "allow a safe space for psions to open a portal to store crystals "+
      "they have bought from Natalia.\n\n"+
      "The command <help workroom> will instruct you in its use.\n"
   );
   set_smell("default","The light fragrance of the beeswax candles mingles "+
      "with the scent of vellum and parchment.");
   set_listen("default","The sound of hammer and chisel often breaks the silence here.");
   set_items(([
       ({"wall","walls"}) : "The wooden walls here are obscured by "+
          "the many mahogany bookshelves.",
       ({"tomes","books","shelves","bookshelves"}) : "The mahogany "+
          "bookshelves are crafted in an elegant manner without "+
          "being ornate.  They support books of various disciplines "+
          "of learning, from history and mythology to subjects "+
          "purely of interest to psions such as gemcutting and "+
          "psionic theory.",
       ({"chair","chairs"}) : "The chairs are made of slender mahogany "+
          "frames and cushioned in plum velvet.  They are high-backed "+
          "and feature padded arms, allowing a comfortable place for "+
          "a psion to lounge and read.",
       ({"rug","floor","woven rug"}) : "A thickly woven rug covers "+
          "the floor, decorated with swirling designs in hues that "+
          "highlight the cushions on the chairs.",
       ({"candles","tables","beeswax candles"}) : "The small tables "+
          "are supported by spindly legs and topped with beeswax "+
          "candles of varying heights.",
       ({"portal","rope"}) : "The roped off area "+
          "provides a safe place for people to open the rifts to store "+
          "their crystals."
   ]));
   set_exits(([
        "east" : "/d/laerad/parnelli/asgard/asgardpsicomps"
   ]));
   setOwner("none");
   setLabId("asgard");
   set_door("door","/d/laerad/parnelli/asgard/asgardpsicomps","east",0);
}

void reset(){
   ::reset();
   if(!present("crystal ball")) new("/d/magic/obj/crystal_ball")->move(TO);
}
