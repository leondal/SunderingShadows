#include <std.h>
#include "../squires_trial.h"

inherit CHASMBASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 24");
  set_short("A carved tunnel");
  set_long( 
  
            "%^RESET%^%^BLUE%^" + 
            "The rock has changed here.  It is a brittle, sharp and " +
            "broken corridor.  A small stream flows through, probably " +
            "the reason for the vast crevasse.  Broken chips of stone " +
            "have collected over centuries and form a solid, but somewhat " +
            "crunchy bed.  This stone path leads to the west.\n" +
            "%^BOLD%^%^WHITE%^An ivory portal frame stands here."
          );
          
  set_exits(([
            "west" : SQUIREROOMS+"room23"
            
  ]));
  
  add_item(({"frame","portal"}),"%^BOLD%^%^WHITE%^This is an ornate portal " +
              "frame, which is currently lifeless.  The carvings are " +
              "delicate, and swirling.%^RESET%^%^WHITE%^"
  );
  set_search("frame","%^BOLD%^%^WHITE%^There is a perfectly round " +
  "%^BOLD%^%^BLACK%^hole %^BOLD%^%^WHITE%^at the right side of the " +
  "frame.  It looks just the right size to %^BOLD%^%^BLACK%^place " +
  "something in%^BOLD%^%^WHITE%^.");
  set_search("portal","%^BOLD%^%^WHITE%^There is a perfectly round " +
  "%^BOLD%^%^BLACK%^hole %^BOLD%^%^WHITE%^at the right side of the " +
  "frame.  It looks just the right size to %^BOLD%^%^BLACK%^place " +
  "something in%^BOLD%^%^WHITE%^.");

}   


int portal_active(){

  set_long( 
          "%^RESET%^%^BLUE%^" + 
          "The rock has changed here.  It is a brittle, sharp and " +
          "broken corridor.  A small stream flows through, probably " +
          "the reason for the vast crevasse.  Broken chips of stone " +
          "have collected over centuries and form a solid, but somewhat " +
          "crunchy bed.  This stone path leads to the west.\n" +
          "%^BOLD%^%^WHITE%^An ivory portal %^YELLOW%^glows brightly %^WHITE%^here."
        );     

  add_item(({"frame","portal"}),"%^BOLD%^%^WHITE%^This is an ornate portal " +
          "frame.  It blazes with light, showing a dark place through it's surface.%^RESET%^%^WHITE%^"
  );
  return 1;
}

int portal_inactive(){
  set_long( 
            "%^RESET%^%^BLUE%^" + 
            "The rock has changed here.  It is a brittle, sharp and " +
            "broken corridor.  A small stream flows through, probably " +
            "the reason for the vast crevasse.  Broken chips of stone " +
            "have collected over centuries and form a solid, but somewhat " +
            "crunchy bed.  This stone path leads to the west.\n" +
            "%^BOLD%^%^WHITE%^An ivory portal frame stands here."
          );

  add_item(({"frame","portal"}),"%^BOLD%^%^WHITE%^This is an ornate portal " +
              "frame, which is currently lifeless.  The carvings are " +
              "delicate, and swirling.%^RESET%^%^WHITE%^" );
  return 1;
}       

void init(){
  ::init();
  add_action("place_pearl","place");
}

int place_pearl(object str){
  object obj;
  if(!present(TP) || !str) return 0;
  if(str == "pearl in hole"){
    if( !present("black pearl",TP) ){
      tell_player(TP,"You don't have that!\n");
      return 1;
    }
    else{
      tell_object(TP, "%^BOLD%^%^WHITE%^As you place the " +
          "%^BOLD%^%^BLACK%^bl%^BLUE%^a%^BLACK%^ck " +
            "pe%^BLUE%^a%^BLACK%^rl%^BOLD%^%^WHITE%^ in the hole, the portal " +
            "flares to life!");
      tell_room(ETP, "%^BOLD%^%^WHITE%^As " + TP->QCN + " places the " +
          "%^BOLD%^%^BLACK%^bl%^BLUE%^a%^BLACK%^ck " +
            "pe%^BLUE%^a%^BLACK%^rl%^BOLD%^%^WHITE%^ in the hole, the portal " +
            "flares to life!",TP);
      portal_active();
      add_exit(SQUIREROOMS+"shadow", "portal");
      obj = present("black pearl",TP);
      if(obj) obj->move("/d/shadowgate/void");
      return 1;
    }
  }
  tell_player(TP,"What are you trying to place?\n");
  return 1;
}

void reset(){
  portal_inactive();
  remove_exit("portal");
  ::reset();
}

