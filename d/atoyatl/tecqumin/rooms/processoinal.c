#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_INT_BASE;

string long_desc();

void create() {
  
  ::create();
  set_short("grand chamber");
  set_items(([  ({"urn", "urns"}): "There is an %^ORANGE%^umber%^RESET%^"
                              +" coloured urn and a %^GREEN%^green"
                              +" %^RESET%^glazed one. They both appear to"
                              +" be decorated ",
             ({"umber urn", "umber coloured urn"}): "The %^ORANGE%^Umber"
             +" %^RESET%^coloured urn is decorated with a depiction of a"
             +" %^ORANGE%^Tecqumin%^RESET%^ marriage ceremony. It looks"
             +" like large families from both sides gathered for the"
             +" occasion. There is feasting and drinking in celebration,"
             +" and at one point it looks like a scuffle breaks out."
             +" Perhaps some things seem to be the same through the ages"
             +" and across all the Realms.",
             ({"green urn", "green glazed urn"}): "The %^GREEN%^green"
             +" %^RESET%^ coloured urn is decorated with a pastiche of"
             +" images of %^ORANGE%^Tecqumin%^RESET%^ life. There are"
             +" tantalising hints of the %^ORANGE%^Tecqumin"
             +" %^RESET%^farming, feasting, fighting and all sorts of"
             +" other things.",
                  ({"walkway", "processional walkway"}): "A broad"
             +" processional walkway marked in %^ORNAGE%^umber%^RESET%^"
             +" flagstones."
  ]) );
  set_search("plinth", "You find a small notch in the plinth under the"
    +" %^GREEN%^green%^RESET%^ urn. It looks like something could be inserted"
    +" there.");
  set_exits( ([ "south" : ROOMS + "guardcham" ,
                "down" : ROOMS + "process_start" ]) );
  set_door("double doors",ROOMS+"guardcham","south",0); 
  set_door_description("double doors","A grand set of stone double doors,"
                                     +" set beneath massive stone"
                                     +" frames.");
}

void init(){
  ::init();
  add_action("insert", "insert");
}

int insert(string str){
  string what, where;
  int num;
  object ob;
  num = sscanf(str, "%s into %s", what, where);
  if (num <2){
    num = sscanf(str, "%s in %s", what, where);
  }
  if (num<2){
    tell_object(TP, "Insert what into where?");
    return 1;
  }
  ob = present("pyramidkey", TP);
  if (!objectp(ob)){
    ob = present("keystone", TP);
    if (!objectp(ob)){
      tell_object(TP, "You don't have anything suitable for inserting anywhere here");
      return 1;
    }
  }
  if (!ob->id(what)){
    tell_object(TP, "You can't see anywhere that would be suitable to insert that around here");
    return 1;
  }
  if (where != "notch" && where != "notch in plinth" && where != "plinth"){
    tell_object(TP, "It doesn't look like that would fit in there"); 
  }
  tell_object(TP, "You insert the " + ob->query_short() + "into the notch in the plinth. It seems like an exact fit.");
  if (ob->id("pyramidkey"))
  {
    tell_object(TP, " As it goes in, a force draws it from your fingers and it disappears. It seems this will be a one-time opportunity");
    ob->move("/d/shadowgate/void");
    tell_room(TO, TPQCN + " presses something into the side of the plinth with the"
      +" %^GREEN%^green%^RESET%^ urn on top of it.", TP);
    call_out("open_door", 1);
    return;
  } 
  if (ob->id("keystone"))
  {
    call_out("open door", 1, TP); 
  }
}

varargs void open_door(object ob){
  tell_room(TO, "A panel in the east wall slides open");
  if (objectp(ob))
  { 
    tell_object(ob, "As the panel slides open, a gust of"
      +" %^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^WHITE%^stly"
      +" w%^RESET%^i%^BOLD%^%^WHITE%^nd%^RESET%^ pushes you through the opening.");
    ob->move_player(ROOMS + "hoard1");
    tell_room(TO,  "As the panel slides open, a gust of"
      +" %^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^WHITE%^stly"
      +" w%^RESET%^i%^BOLD%^%^WHITE%^nd%^RESET%^ pushes " + ob->QCN 
      + " through the opening, which closes swiftly behind " + ob->QO + ".");
    return;
  }
  add_exit(ROOMS + "hoard1", "east");
}

string long_desc(){
    return "A larger chamber, with a clearly defined processional"
          +" %^ORANGE%^walkway%^RESET%^ in the centre, leading from the"
          +" double doors to the north, along to a"
          +" %^BOLD%^%^BLACK%^stairwell%^RESET%^ disappearing down"
          +" beneath the floor. A couple of decorative urns stand on plinths to the"
          +" side of the walkway.";
}
