//updated by Circe 5/31/04 with color, improved desc, etc.
// Scribe's Office in Tabor
// Thorn@ShadowGate
// 001013
// Tabor
// scribe.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void init(){
  ::init();
  add_action("buy_map","draw");
}

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property( "light", 2);
  set_property( "indoors", 1);
  set_name("Scribe's Office in Tabor");
  set_short("Scribe's Office in Tabor");
  set_long(
@MELNMARN
%^BOLD%^Scribe's Office in Tabor%^RESET%^
This well-kept office reflects the personality of the man who 
spends much of his life here.  The large desk against the 
eastern wall is made of exotic %^RED%^teak wood%^RESET%^ and is balanced 
by the matching, ornately carved %^RED%^chair %^RESET%^standing behind it.  
The chair has an %^BLUE%^indigo pad %^RESET%^that has become worn after 
years of use but is kept well-repaired.  A lone shelf to the right 
of the desk holds reams of %^BOLD%^paper %^RESET%^and jars of %^BOLD%^%^BLACK%^ink %^RESET%^while the 
rest of the office is rather bare.  A single picture is framed on 
the southern wall, a large portrait of %^YELLOW%^Tabor %^RESET%^with the mage 
tower prominent in the foreground.
MELNMARN
  );
  set_smell("default","You smell the odors of pen, ink, and paper.");
  set_listen("default","You hear the sounds of papers being shuffled.");
  set_exits( ([
    "west" : ROOMDIR+"math5"
  ]) );
  set_items(([
     "desk" : "%^RED%^The teak wood desk was obviously imported, "+
        "and from the layers of polish upon its surface, it's "+
        "obvious that the owner cares for it greatly.  The top of "+
        "the desk has a row of cubbies in which various quills and "+
        "inks are stored.",
     ({"shelf","paper","reams of paper","jars","jars of ink"}) : "The "+
        "reams of paper and jars of ink seem to be rotated out fairly "+
        "often, and you guess this scribe must see quite a lot of "+
        "business.",
     ({"chair","padded chair","desk chair"}) : "%^RED%^The desk "+
        "chair is made of matching teak wood and has been ornately "+
        "carved with images of unusual cranes along the back.  "+
        "The seat has been fitted with a %^BLUE%^indigo pad%^RED%^, "+
        "giving the scribe a little more comfort.",
     ({"picture","portrait"}) : "The portrait is an oil painting "+
        "of Tabor and the surrounding area.  It is a little "+
        "fantastic, with the mage tower rising high above the "+
        "forest and seeming much larger than it should."
  ]));
}

int buy_map(string str){
  int amount;
  amount = 15;
  if(!present("scribe")) return notify_fail("Nobody is here to draw you a map.\n");
  if(str == "map"){ 
      tell_object(TP,"What would you like him to draw?  He can "+
         "<draw tabor> or <draw area>.");
      return 1;
  }
  if(str != "tabor" && str != "area" && str != "text") return notify_fail("Draw what?\n");
  if((this_player()->query_money("gold") < amount))
    return notify_fail("You don't have "+amount+" gold!\n");
  if(str == "tabor"){
     tell_object(TP,"The Scribe hands you a map of Tabor.");
     tell_room(ETP,"The Scribe completes a map and hands it to "+
        ""+TPQCN+".",TP);
     new("/d/darkwood/tabor/obj/map")->move(TP);
     return 1;
  }
  if(str == "area"){
     tell_object(TP,"The Scribe hands you a map of the area "+
        "surrounding Tabor.");
     tell_room(ETP,"The Scribe completes a map and hands it to "+
        ""+TPQCN+".",TP);
     new("/d/common/obj/misc/lowbie_map")->move(TP);
     return 1;
  }
  if(str == "text"){
     tell_object(TP,"The Scribe hands you text-only version of Tabor's map.");
     tell_room(ETP,"The Scribe completes a map and hands it to "+
        ""+TPQCN+".",TP);
     new("/d/common/obj/misc/tabortextmap")->move(TP);
     return 1;
  }
}

void reset(){
  object ob;
  ::reset();
  if(!present("scribe")){
    ob = new("/d/shadow/mon/scribe");
    ob->set_name("Merrick the scribe");
    ob->set_short("Merrick, Scribe of Tabor");
    ob->set_scribe_name("merrick");
    ob->set_region("tabor");
    ob->set_id(({"scribe","merrick the scribe","tabor scribe","merrick","Merrick"}));
    ob->set_long("This aging man is well advanced in years.  He "+
       "seems rather thin and perhaps a little undernourished, but "+
       "he appears happy enough with what he does.  His long, "+
       "thinning white hair falls in waves past his shoulders and "+
       "is kept pulled back in a black clasp.  He is dressed simply, "+
       "in what appears to be a uniform - a tunic bearing the crest "+
       "of Tabor above black cotton breeches.  He spends most of "+
       "his time sitting at the desk, and whenever he stands, you "+
       "could swear you hear his bones creaking.  Still, his "+
       "eyesight and coordination are impeccable.  You could get "+
       "him to %^RESET%^<%^BOLD%^%^CYAN%^write%^RESET%^> %^CYAN%^anything you "+
       "want, in whatever languages he knows.  He will "+
	"%^RESET%^<%^BOLD%^%^CYAN%^translate [item] to [language]%^RESET%^> %^CYAN%^for you.  "+
	"He can also give you an estimate of how much it will cost to translate an "+
	"item, by using %^RESET%^<%^BOLD%^estimate [item]%^RESET%^>%^CYAN%^.  "+
	"If you are interested "+
       "in a map, you can have him %^RESET%^<%^BOLD%^%^CYAN%^draw "+
       "tabor%^RESET%^> %^CYAN%^for a map of this fair city. If you prefer a detailed map with words instead of images, have him <%^BOLD%^%^CYAN%^draw text%^RESET%^>, %^CYAN%^or have him "+
       "%^RESET%^<%^BOLD%^%^CYAN%^draw area%^RESET%^> %^CYAN%^to "+
       "get a map of adventure areas around here.");
    ob->move(TO);
  }
}
