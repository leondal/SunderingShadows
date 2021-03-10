//storage room for Taribella in Offestry.  Circe 6/6/07
#include <std.h>

inherit ROOM;

#define SCROLL "/d/magic/newbie_scroll"
#define MYSPELLS ({"magic missile","burning hands","chill touch","color spray"})
object obj;
string MYSPELL;

void create(){
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Taribella's Shop Storeroom");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : "/d/newbie/rooms/town/scrolls"]));
}

void reset(){
	::reset();
   if(!present("scroll")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 2")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 3")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 4")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 5")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 6")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 7")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 8")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 9")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
   if(!present("scroll 10")){
      obj = new(SCROLL);
      obj->move(TO);
      obj->set_spell_name(MYSPELLS[random(sizeof(MYSPELLS))]);
      obj->set_short("a scroll of "+obj->query_scroll_spell()+"");
      obj->set_value(25);
   }
}
