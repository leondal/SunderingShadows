#include <std.h>
#include "../../newbie.h"
inherit ROOM;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

int FLAG, NOOK;

void init(){
  ::init();
    add_action("pull_back","pull");
    add_action("dive_under","dive");
}

void create(){
  ::create();
    set_property("light",3);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);

    set_short("%^BOLD%^%^BLUE%^Lake Shore%^RESET%^");
    set_long("%^RESET%^You wander down the rocky slope, following "+
"the thick, gnarled %^ORANGE%^roots %^RESET%^of the large "+
"%^GREEN%^oak tree %^RESET%^to the north.  Here, large and small "+
"%^BOLD%^%^BLACK%^rocks %^RESET%^cluster between the thick tree "+
"roots, vying for space with the living plant.  This creates "+
"numerous %^BOLD%^%^BLACK%^nooks %^RESET%^and %^ORANGE%^crannies "+
"%^RESET%^within which any number of interesting things might be "+
"found if searched.  Little, if any, %^GREEN%^grass %^RESET%^is "+
"to be seen growing amongst the boulders, though a few scraggly "+
"%^ORANGE%^cattails %^RESET%^nest between a pair of especially "+
"large roots, making a little shelter for wild animals or birds.");

    set_smell("default","\nThe water gives the air a moist, "+
"fresh smell.");
    set_listen("default","You hear the muffled sound of someone "+
"crying.");
NOOK = 1;

    set_items(([
        ({"lake","water"}):"The water looks fairly clear around the "+
"edges but you can tell it deepens quickly.  It is dark and quite "+
"murky further out from the bank.  Now and then you catch a "+
"glimpse of fish swimming around or jumping at insects.  You think "+
"you could probably %^BLUE%^dive%^RESET%^ into the lake from "+
"here.",
        ({"roots","tree","oak tree"}):"A large oak tree grows at "+
"the top of this slope.  Thick roots stretch wide over the ground "+
"before digging deep into the earth to support the large tree and "+
"its sprawling canopy.",
        ({"rocks"}):"The ground grows rocky along the shoreline.  "+
"Most appear to be small rocks and boulders dislodged by water "+
"erosion and the growth of the tree roots, though you see a few "+
"large ones off to one side where some cattails are growing.",
        ({"nooks","crannies"}):"With all the rocks and roots piled "+
"around this area, there are a number of little crevices that "+
"might have caught something interesting.  Perhaps you could "+
"%^YELLOW%^<search> %^RESET%^them.",
        ({"grass"}):"There isn't much grass here.  Just a few "+
"scraggly tufts growing up amongst the boulders and roots.",
        ({"cattails","nest","shelter"}):"You look over the "+
"cattails and notice that their stems seem woven together so that "+
"they form a sheltering canopy over the crevice between two large "+
"boulders.  You could probably %^YELLOW%^<pull>%^RESET%^ them back "+
"to see what is hiding there.",
    ]));

   set_exits(([
      "north":"/d/newbie/rooms/forest/forest9"
    ]));

    set_search("default","There look to be a few things you could "+
"search here.  What exactly did you want to search?");
    set_search("nooks",(:TO,"search_roots":));
    set_search("crannies",(:TO,"search_roots":));
    set_search("roots",(:TO,"search_roots":));
}

int search_roots(string str){
  object ob;

  if(FLAG == 1){ 
    tell_object(TP,"You search around in the roots but find nothing "+
"of interest this time.");
    return 1;
  }

  if(str == "nooks" || str == "crannies" || str == "roots"){
    if(NOOK < 1){
      tell_object(TP,"You search around in the nooks and crannies but"+
" find nothing of interest this time.");
      return 1;
    }
    tell_object(TP,"You search around in the roots and find a few "+
"%^YELLOW%^s%^WHITE%^p%^RESET%^%^ORANGE%^a%^YELLOW%^rk%^WHITE%^"+
"l%^RESET%^%^ORANGE%^i%^YELLOW%^ng %^RESET%^coins.%^RESET%^");
    ob=new("/std/obj/coins");
    ob->set_money("gold",random(10)+30);
    ob->set_money("silver",random(30)+100);
    ob->move(ETP);
    NOOK--;
    return 1;
  }

  else{
    tell_object(TP,"You search around in the roots but find nothing "+
"of interest this time.");
    return 1;
  }
}

int pull_back(string str){
  if(str == "cattails"){
    tell_object(TP,"%^GREEN%^You pull the woven cattails back and "+
"reveal a small %^BOLD%^%^MAGENTA%^a%^WHITE%^t%^RESET%^%^MAGENTA%^o"+
"%^BOLD%^m%^WHITE%^i%^MAGENTA%^e%^RESET%^%^GREEN%^.%^RESET%^");
    tell_room(TO,"%^GREEN%^"+TP->QCN+" pulls the cattails back "+
"revealing a small %^BOLD%^%^MAGENTA%^a%^WHITE%^t%^RESET%^"+
"%^MAGENTA%^o%^BOLD%^m%^WHITE%^i%^MAGENTA%^e%^RESET%^%^GREEN%^."+
"%^RESET%^",TP);
    if(!present("atomie")){
      new("/d/newbie/rooms/lake/atomie.c")->move(TO);}
  }
return 1;
}

int dive_under(string str){
  if(str == "lake" || str == "into lake" || str == "into the lake"){
    tell_object(TP,"%^BOLD%^%^BLUE%^You dive under the surface of "+
"the pond!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^BLUE%^"+TP->QCN+" dives under the "+
"surface of the pond!",TP);
  TP->move("/d/newbie/rooms/lake/lake2");
  return 1;
  }
  else{
    tell_object(TP,"You could probably dive into the lake instead.");
  }
return 1;
}
