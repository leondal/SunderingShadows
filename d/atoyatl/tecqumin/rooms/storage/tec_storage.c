//Coded by Lujke//
#include <std.h>
#include "../tecqumin.h"
inherit ROOM;

int jag_entry;
object head_obj;

void create(){
  object jetstone;
  ::create();
  set_storage(1);
  set_short("A bland storeroom");
  set_long(("Yeah, somewhere to put things"));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_property("indoors",1);
  set_property("light",2);
  
  set_smell("default","This room smells of immortal trickery");

  set_listen("default","You can hear someone plotting in the background");
  jetstone = new (OBJ + "jetstone");
  jetstone->move(TO);
  head_obj = new (OBJ + "head");
  head_obj->move(TO);
  jag_entry = -1;
  set_no_clean(1);

}

void clean_up(){
}

void reset(){
  object jetstone;
  ::reset();
  jetstone = present("jetstone", TO);
  if (!objectp(jetstone)&&random(2)>0){
    jetstone = new (OBJ + "jetstone");
    jetstone->move(TO);
  }
  if ( !objectp(head_obj) || (!head_obj->id("head") &&random(4)<1)){
    head_obj = new (OBJ + "head");
    head_obj->move(TO);
  }

}

void set_jag_entry(int i){
  jag_entry = i;
}

int query_jag_entry(){
  return jag_entry;
}

void set_head_obj(object ob){
  head_obj = ob;
}

object query_head_obj(){
  return head_obj;
}
