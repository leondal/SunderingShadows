#include <std.h>

inherit "/d/atoyatl/wemic/obj/connectfour.c";

string long_desc();
int check_stacks(string str);
int drop_block(string str);
void setup_blocks2(object ob);
int setup_blocks(string str);
int show_small(string str);

void create(){
  ::create();
  set_id(({"stacks","blocks", "stacks of blocks"}));

  set_name("stacks of blocks");
  set_short("Some blocks that can be arranged in stacks");
  set_long( (: TO, "long_desc" :) );
  set_read("%^BOLD%^%^YELLOW%^To play%^RED%^:%^RESET%^ \n"
         + "%^BOLD%^%^BOLD%^%^YELLOW%^*%^RESET%^ Two players choose one colour each - %^ORANGE%^orange%^RESET%^ or %^GREEN%^green%^RESET%^.\n"
         + "%^BOLD%^%^BOLD%^%^YELLOW%^*%^RESET%^ They take turns to stack one block of their own colour on one of the piles.\n"
         + "%^BOLD%^%^BOLD%^%^YELLOW%^*%^RESET%^ The aim is to get four blocks of a player's own colour stacked in a straight line.\n"
         + "%^BOLD%^%^BOLD%^%^YELLOW%^*%^RESET%^ The first player to achieve this, wins.\n"
         + "%^BOLD%^%^BOLD%^%^YELLOW%^*%^RESET%^ A winning line can be vertical, horizontal or diagonal.\n" 
         + "%^BOLD%^%^RED%^Commands%^YELLOW%^:%^RESET%^\n"
         + "To stack a block:           %^BOLD%^%^YELLOW%^<%^RESET%^stack %^ORANGE%^orange%^RESET%^|%^GREEN%^green%^RESET%^ block on pile #%^BOLD%^%^YELLOW%^>%^RESET%^\n"
         + "To get ready to play again: %^BOLD%^%^YELLOW%^<%^RESET%^arrange blocks%^BOLD%^%^YELLOW%^>%^RESET%^");
           
}

void init(){
  ::init();
  add_action("check_stacks", "check");
  add_action("drop_block", "stack");
  add_action("show_small", "display");
  add_action("setup_blocks", "arrange");
}

string long_desc(){
  string desc;
  desc = "A number of coloured blocks, which can be arranged in stacks on"
        +" top of eight markers on the floor. They can be balanced up to"
        +" six high on each stack and are clearly intended for some sort of"
        +" game play. There are some instructions written on one of the"
        +" stacks\n";
  desc += display_stacks(TP);
  return desc;
}


int check_stacks(string str){
  if (!stringp(str) || !id(str)){
    tell_object(TP, "Try 'check stacks'");
    return 1;
  }
  tell_object(TP, display_stacks(TP));
  return 1;
}

int drop_block(string str){
  object room;
  string colour;
  int stack, col, result;
  if (!stringp(str)){
    tell_object(TP, "Try 'stack %^ORANGE%^<colour>%^RESET%^ block on pile"
                   +" %^ORANGE%^<number>%^RESET%^'. Colour must be green or"
                   +" orange, and the pile number must be between 1 and"
                   +" 8.");
    return 1;
  }
  if (sscanf(str, "%s block on pile %d", colour, stack)<2){
    tell_object(TP, "Try 'stack %^ORANGE%^<colour>%^RESET%^ block on pile"
                   +" %^ORANGE%^<number>%^RESET%^'. Colour must be green or"
                   +" orange, and the pile number must be between 1 and"
                   +" 8.");
    return 1;
  }
  switch (colour){
  case "orange":
    col = -1;
    break;
  case "green":
    col = 1;
    break;
  default:
    tell_object(TP, "Colour must be '%^ORANGE%^orange%^RESET%^' or"
                   +" '%^GREEN%^green%^RESET%^'");
    return 1;
  }
  if (stack<1 ||stack >8){
    tell_object(TP, "Pile number must be between 1 and 8");
    return 1;
  }
  result = stack_block(stack, col);
  if (result ==-3) return 1;
  if (result ==-2)
  {
    tell_object(TP, "The game has already been won. There's no point adding more blocks");
    return 1;
  }
  if (result ==-1){
    tell_object(TP, "Stack"+ stack +" is already piled up to 6 blocks high."
                   +" There's no more room!");
    return 1;
  }
  switch(colour){
  case "orange": 
    tell_object(TP, "You place an %^ORANGE%^orange%^RESET%^ block on top of"
                   +" stack " + stack + ".");
    room = ETP;
    if (objectp(room)){
      tell_room(room, TPQCN + "%^RESET%^places an %^ORANGE%^orange%^RESET%^"
                    +" block on top of stack " + stack + ".", TP);
    }    
    break;
  case "green":
    tell_object(TP, "You place a %^GREEN%^green%^RESET%^ block on top of"
                   +" stack " + stack + ".");
    room = ETP;
    if (objectp(room)){
      tell_room(room, TPQCN + "%^RESET%^places a %^GREEN%^green%^RESET%^"
                    +" block on top of stack " + stack + ".", TP);
    }    
    break;
  }
  if (result ==2)
  {
    tell_object(TP, "You have lined up four in a row. You win!");
    tell_room(ETP, TPQCN + " has lined up four in a row. " + TPQS + " wins!", TP);
    winner = col;
  }

  return 1;
}

void setup_blocks2(object ob){
  object room;
  if (!objectp(ob)){
    report ("Error loading object in setup_blocks2");
    return;
  }
  room = environment(ob);
  if (!objectp(room)){
    report ("Error loading room in setup_blocks2");
    return;
  }
  tell_object(ob, "%^GREEN%^You finish clearing away the blocks, ready to"
                 +" begin a new game.");
  tell_room(room, "%^GREEN%^" + TPQCN + " %^RESET%^%^GREEN%^finishes"
                 +" clearing away the blocks, ready for a new game.", ob);
  setup();
}

int setup_blocks(string str){
  object room;
  if (str != "blocks"){
    tell_object(TP, "Try 'arrange blocks'");
    return 1;
  }
  tell_object(TP, "%^GREEN%^You begin clearing the piles of blocks, ready"
                 +" for a new game.");
  room = ETP;
  if (objectp(room)){
    tell_room(room, "%^GREEN%^" + TPQCN + "%^RESET%^%^GREEN%^ begins"
                     +" clearing the piles of blocks, ready for a new"
                     +" game.",TP);
  }
  call_out("setup_blocks2", 4, TP);
  return 1;
}

int show_small(string str){
  if (!str){
    tell_object(TP, "Try 'display small' or 'display large'");
    return 1;
  }
  switch (str){
  case "small":
    if (TP->query_property("showsmall")){
      tell_object(TP,"You are already viewing the game as a small display."
                    +" Try 'display large' if you would like to see the"
                    +" bigger picture.");
      return 1;
    }
    TP->set_property("showsmall", 1);
    tell_object(TP, "You will now view the game as a small display. Use"
                   +" 'display large' if you would like to see the bigger"
                   +" picture again.");
    return 1;
  case "large":
    if (TP->query_property("showsmall")){
      TP->remove_property("showsmall");
      tell_object(TP,"You will now view the game as a large display. Use"
                    +"'display small' if you would prefer to see the"
                    +" smaller version again.");
      return 1;
    }
    tell_object(TP, "You are already seeing the game as a large display."
                   +" Use 'display small' if you would rather see the"
                   +" smaller version.");
    return 1;
  default:
    tell_object(TP, "Use 'display small' to view the game as a small sized"
                   +" display, or 'display large' to see the bigger"
                   +" version.");
    return 1;
  }
}
