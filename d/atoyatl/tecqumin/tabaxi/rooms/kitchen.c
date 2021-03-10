#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

int cauldrons;

void create() {
  ::create();
  cauldrons = 3;
  set_property("indoors", 1);
  set_property("light", 2);
  set_travel(FOOT_PATH );
  set_terrain(WOOD_BUILDING);
  set_short("A large kitchen");
  set_long("This is a large communal cooking area, with a %^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^re"
          +" %^BOLD%^%^BLACK%^p%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t %^RESET%^and an open%^ORANGE%^" 
          +" smoke hole %^RESET%^in the roof.  There are various %^BOLD%^%^BLACK%^pots%^RESET%^,"
          +" %^BOLD%^%^BLACK%^pans%^RESET%^ and %^CYAN%^utensils%^RESET%^ around the place, as well as"
          +" some prepared %^ORANGE%^food%^RESET%^ and some raw %^GREEN%^ingredients%^RESET%^. One" 
          +" partitioned section looks as though it has been separated off as cool storage for"
          +" perishables. The main food hall is to the north.");
  set_items( ([ ({ "fire", "pit", "fire pit"}): "The shallow %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^"
         +"%^RED%^re %^BOLD%^%^BLACK%^p%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t%^RESET%^ is well fuelled,"
         +" with %^RED%^f%^BOLD%^%^YELLOW%^l%^RED%^a%^RESET%^%^RED%^mes %^RESET%^dancing happily"
         +" under the various food items being prepared",
             ({"pots", "pans", "utensils"}) :  (: TO, "pot_desc" :),
          ({"cauldron", "cauldrons" }) : (:TO, "cauld_desc" :)
                   ]) );
  set_property("light", 2);
  set_exits( ([ "north" : TABAXROOM + "foodhall"
             ]) );
}


string query_granary_dir(){
  return "north";
}



void init(){
  ::init();
  add_action("take_me", "take");
  add_action("take_me", "get");
  set_had_players(3);
}

void reset(){
  int cdrns;
  cdrns = cauldrons;
  ::reset();
  if (random(10)<9){
    cauldrons = cdrns;
  } else {
    cauldrons = 3;
  }
}




int take_me(string str){
  object ob;
  if (!stringp(str)){
    return 0;
  }
  if (str != "cauldron" && str != "cauldrons"){
    return 0;
  }
  if (cauldrons ==0){
    tell_object(TP, "There are no cauldrons here");
    return 1;
  }
  if ((int)TP->query_max_internal_encumbrance() - (int)TP->query_internal_encumbrance()< 8){
    tell_object(TP, "You can't carry that!");
    return 1;
  }
  tell_object(TP, "You take a large %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                 +"%^BLACK%^ldr%^RESET%^o%^BOLD%^%^BLACK%^n from the shelves");
  tell_room(TO, TPQCN + " takes a large %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
                 +"%^BLACK%^ldr%^RESET%^o%^BOLD%^%^BLACK%^n from the shelves", TP);
  ob = new(TABAXOBJ + "cauldron");
  ob->move(TP);
  return 1;
}

string cauld_desc(){
  object ob;
  ob = present("cauldron", TP);
  if (!objectp(ob)){
    ob = present("cauldron", TO);
  } 
  if (objectp(ob)){
    return (string)ob->query_long();
  }
  switch(cauldrons){
  case 0:
    return "You don't see that here";
  case 1:
    return "The larger %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^%^BLACK%^ldr%^RESET%^o"
          +"%^BOLD%^%^BLACK%^n %^RESET%^that caught your eye is currently empty. You could probably"
          +" take it, in case you need a really big meal later, or you want to get together with a"
          +" couple of your cronies and muck about on a blasted heath, or something.";
  default:
    return "The larger %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^%^BLACK%^ldr%^RESET%^o"
          +"%^BOLD%^%^BLACK%^ns %^RESET%^that caught your eye are currently empty. You could probably"
          +" take one with you, in case you need a really big meal later, or you want to get together"
          +" with a couple of your cronies and muck about on a blasted heath, or something.";
  }
}

string pot_desc(){
  string desc;
  desc = "The %^BOLD%^%^BLACK%^p%^RESET%^o%^BOLD%^%^BLACK%^ts %^RESET%^and%^BOLD%^%^BLACK%^ pans"
        +" %^RESET%^not currently in use are tidied neatly away on shelves and in cupboards. ";
  switch (cauldrons){
  case 0:
    return desc;
  case 1:
    desc += "One particularly large %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
           +"%^BLACK%^ldr%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^ catches your eye.";
    break;
  case 2:
    desc += "Two particularly large %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
           +"%^BLACK%^ldr%^RESET%^o%^BOLD%^%^BLACK%^ns%^RESET%^ catch your eye.";
    break;
  case 3:
    desc += "Three particularly large %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^RESET%^u%^BOLD%^"
           +"%^BLACK%^ldr%^RESET%^o%^BOLD%^%^BLACK%^ns%^RESET%^ catch your eye.";
    break;
  }
  return desc;
}
