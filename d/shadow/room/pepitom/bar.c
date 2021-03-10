// C:\Shadowgate\Test\bar.c


#include "Pepitom.h"


inherit ROOM;


void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short(
@SHADOWGATE
The Wanderers Bar
SHADOWGATE
    );
    set_long(
@SHADOWGATE
%^BOLD%^Welcome to the Wanderers Bar!%^RESET%^ 
This is a favorite stopping place for adventurers in Shadow. 
Sometimes it gets pretty noisy, so you'll have to speak up. 
A list of drinks is on the wall. 
SHADOWGATE
    );
    set_exits(([
    "south" : ROOMS+"wroad06",
    ]));
    set_items(([
    "pub" : "The most hoppin' place in Shadow.",
    "bar" : "The Wanderers Bar",
    ]));
}

void init(){

 
    ::init(); 
    add_action("read", "read"); 
    add_action("make", "make"); 


}

void reset(){

 
  ::reset(); 
    if(!present("fionna"))  
      new(MONDIR+"fionna")->move(this_object()); 


}


