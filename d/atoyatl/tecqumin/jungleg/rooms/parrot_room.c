#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit J_MAZE;

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("In a thick jungle, surrounded by parrots");
  set_short((:TO, "short_desc" :));
  set_long( (:TO, "long_desc":) );
  set_items (([ ({"tree", "parrots", "parrot"}): 
     "The %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s%^RESET%^ are flapping and playing happily in and around one large %^GREEN%^tree%^RESET%^ which bears some large %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d fru%^BLACK%^i%^RED%^t%^RESET%^, many of which have fallen, %^ORANGE%^over-ripe%^RESET%^, to the ground. They look very happy indeed, and not at all concerned about danger. Perhaps you could coax one over to join you.",
     ({"fruit", "red fruit", "large red fruit"}) : "It's not a %^BOLD%^%^RED%^fru%^BLACK%^i%^RED%^t%^RESET%^ you have seen before, but it looks very %^BOLD%^%^RED%^ripe%^RESET%^ indeed. Curiously, the %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s%^RESET%^ seem most interested in the ones that have fallen to the ground and look like they have been there for some time. Every now and then a %^BOLD%^%^RED%^p%^BLUE%^ar%^GREEN%^ro%^BLUE%^t%^RESET%^ will swoop down and eat a few morsels of one of the mushiest examples, then flap somewhat more unsteadily back into the branches. You could gather some for yourself, if you wanted."    ]) );
  set_search("gateway",(:TO, "gate_search":));
  set_search("carved gateway",(:TO, "gate_search":));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
  r_path = JUNG_ROOM7;
}

string short_desc(){
  ::short_desc();
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^ jungle, surrounded by %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s";
}

void on_enter(){
  update_exits();
}

void init() {
   ::init();
   add_action("get_fruit", "get");
   add_action("get_fruit", "gather");
   add_action("coax_parrot", "coax");
 
}


string long_desc(){
  string result;
  result = ::long_desc();
  result += "%^GREEN%^ A %^RESET%^%^ORANGE%^large tree"
    +" %^GREEN%^with unusual %^BOLD%^%^RED%^red"
    +" fru%^BLACK%^i%^RED%^t %^RESET%^%^GREEN%^grows in"
    +" a slight clearing here. Numerous %^BOLD%^%^BLUE%^"
    +"bri%^YELLOW%^ght%^GREEN%^ly%^CYAN%^ %^RED%^col"
    +"%^CYAN%^our%^GREEN%^ed p%^YELLOW%^arr%^BLUE%^ots"
    +"%^RESET%^%^GREEN%^ are flapping and squawking"
    +" around it.\n";
  return result;
}


int get_fruit(string str){
  object fruit;
  fruit = new(OBJ +  "fermented_fruit");
  if (!fruit->id(str)){
    fruit->remove();
    return notify_fail("Do you want to gather fruit?");
  }
  tell_object(TP, "You get a piece of %^ORANGE%^overripe"
    +" %^BOLD%^%^RED%^fr%^RESET%^%^RED%^u%^BLACK%^i%^RED%^t"
    +" from the ground");
  tell_room(TO, TPQCN + " gets a piece of %^ORANGE%^overripe"
    +" %^BOLD%^%^RED%^fr%^RESET%^%^RED%^u%^BLACK%^i%^RED%^t"
    +" from the ground", TP);
  fruit->move(TP);
  return 1;
}

int coax_parrot(string str){
  object parrot, fruit;
  string what;
  int num, skill, roll;
  parrot = new(OBJ + "parrot");
  num = sscanf (str, "a %s", what);
  if (num<1) {
    num = sscanf (str, "%s down from the tree", what);
    if (num<1){
      what = str;
    }
  } else {
    str = what;
    num = sscanf (str, "%s down from the tree", what);
    if (num<1){
      what = str;
    }
  }
  if (!parrot->id(what)){
    return notify_fail("Do you want to coax a parot down from the"
      +" tree?");
  }
  fruit = present("mushy fruit", TP);
  if (!objectp(fruit)){
    return notify_fail("It would help to have a piece of the fruit"
     +" the parrots seem to like, in order to coax one down from"
     +" the tree");
  }

  skill = TP->query_skill("influence") + TP->query_skill("survival");
  roll = random(30);
  if (TP->is_class("ranger") || TP->is_class("druid")){
    roll += 30;
  }
  switch (skill+ roll){
  case 0..20:
    tell_object(TP, "You run around after the %^BOLD%^%^RED%^p"
      +"%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s"
      +"%^RESET%^, but none of them seem interested in you, or"
      +" the rotten bit of fruit you are waving");
    tell_room(TO, TPQCN + "%^RESET%^ runs around after the"
      +" %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^"
      +"o%^BLUE%^t%^RED%^s%^RESET%^, but none of them seem"
      +" interested in " + TP->QO + " or the rotten bit of fruit "
      + TP->QS + " is waving", TP);
    break;
  case 21..30:
    tell_object(TP, "You stand still, hesitantly waving a bit of"
      +" fruit, but none of the %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^"
      +"r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s%^RESET%^ seem"
      +" interested");
    tell_room(TO, TPQCN + "%^RESET%^ stands still, hesitantly"
      +" waving a bit of fruit, but none of the"
      +" %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^"
      +"o%^BLUE%^t%^RED%^s%^RESET%^ seem interested", TP);
    break;
  case 31..40:
    tell_object(TP, "You crouch down and hold out a bit of fruit"
      +" toward the %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^"
      +"r%^GREEN%^o%^BLUE%^t%^RED%^s%^RESET%^, but none of them"
      +" seem sufficiently brave (or intoxicated?) to get close"
      +" enough to take it.");
    tell_room(TO, TPQCN + "%^RESET%^ crouches down and holds out"
      +" a bit of fruit toward the %^BOLD%^%^RED%^p%^BLUE%^a"
      +" %^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s%^RESET%^,"
      +" but none of them seem sufficiently brave (or intoxicated?)"
      +" to get close enough to take it.", TP);
    break;
  case 41..500000:
    tell_object(TP, "You crouch down and place a bit of fruit on"
      +" the ground in front of you, and wait patiently");
    tell_room(TO, TPQCN + "%^RESET%^ crouches down and places a"
      +" bit of fruit on the ground in front of " + TP->QO + ","
      +" and waits patiently.", TP);
    call_out("coax2", 5, TP);
    break;

  }
  return 1;
}

void coax2(object ob){
  if (!objectp(ob)||!present(ob, TO))
  {
    return;
  }
  tell_object(ob, "After a little while, one of the %^BOLD%^"
    +"%^RED%^p%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t"
    +"%^RED%^s%^RESET%^ hops unsteadily over the ground and nibbles"
    +" at your piece of fruit");
  tell_room(TO, "After a little while, one of the %^BOLD%^%^RED%^p"
    +"%^BLUE%^a%^GREEN%^r%^YELLOW%^r%^GREEN%^o%^BLUE%^t%^RED%^s"
    +"%^RESET%^ hops unsteadily over the ground and nibbles at "
    + ob->QCN +"%^RESET%^'s piece of fruit", ob);
  call_out("coax3", 3, TP);
}

void coax3(object ob){
  object parrot;
  if (!objectp(ob)||!present(ob, TO))
  {
    return;
  }
  tell_object(ob, "While the %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^ro"
    +"%^BLUE%^t%^RESET%^ is eating, you reach out and scratch it"
    +" behind the head. It freezes at first then, sensing no danger,"
    +" relaxes and actually nuzzles against your hand. You seem to"
    +" have made a friend.");
  tell_room(TO, "While the %^BOLD%^%^RED%^p%^BLUE%^a%^GREEN%^ro"
    +"%^BLUE%^t%^RESET%^ is eating, "+ob->QCN+"%^RESET%^ reaches"
    +" out and scratches it behind the head. It freezes at first"
    +" then, sensing no danger, relaxes and actually nuzzles"
    +" against "+ ob->QP +" hand. "+ capitalize(ob->QS)+ " seems"
    +" to have made a friend.", ob);
  parrot = new (MOB + "parrot");
  parrot->move(TO);
  parrot->set_owner(ob->query_name());
}
