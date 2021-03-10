#include <std.h>
#include "../tecqumin.h"

inherit ROOM;

#define PORT 1
#define STARBOARD 0
#define NORTH 2
#define SOUTH 3
#define EAST 4
#define WEST 5

mapping direction;
int croc, progress;
void new_croc();
string long_desc();

void create(){
    ::create();
      croc = 0;
      direction=([]);
      progress = 0;
      set_name("In the river");
      set_short("In the river");
	set_long((:TO,"long_desc":));

      set_items( ([ 
           "left bank" : "The %^ORANGE%^riverbank%^RESET%^"
        +" to the left is steep and tall. Obstructing"
        +" %^GREEN%^fol%^BOLD%^i%^RESET%^%^ORANGE%^a%^GREEN%^ge%^RESET%^"
        +" grows right up to the edge, and you can't see any way to"
        +" get out there.",
           "right bank": "The %^ORANGE%^riverbank%^RESET%^ to the right"
        +" appears to be a relatively gentle slope. You can see a way"
        +" to get back into the %^GREEN%^j%^BOLD%^u%^RESET%^%^GREEN%^ngle",
           ({"bank", "riverbank", "riverbanks", "banks"}) : " The left"
        +" bank is significantly steeper and taller than the right bank."
        +" It looks like it would be next to impossible to get out of the"
        +" water there."
  ]) );

    set_property("no teleport",1000);

}

void init(){
  ::init();
  add_action("wield","wield");
  add_action("head_left", "left");
  add_action("head_right", "right");
  add_action("head_left", "left");
  add_action("head_right", "right");
  add_action("swim", "swim");
}

string long_desc(){
   string result;
   result =  "%^BOLD%^%^CYAN%^You are in the water. It's not easy to"
            +" keep your head above the surface. You can make out the"
            +" banks to your right and left. It would make sense to swim"
            +" towards one of them.";
  return result;
}

int is_empty(){
  int i;
  if (sizeof(all_living(TO))==0)
  {
    return 1;
  }
  for(i=0;i<sizeof(all_living(TO));i++)
  {
    if (all_living(TO)[i]->is_player())
    {
      return 0;
    }
  }
  return 1;
}

void reset(){
  ::reset();
  if (is_empty())
  {
    progress = 0;
    direction =3;
  }
  if (random(1)<1) 
  {
    croc = 0;
  }
}


int swim(string str){
  switch (str)
  {
  case "left":
    head_left();
    break;
  case "right":
    head_right();
    break;
  default:
    return notify_fail("Do you want to swim left or right?");
    break;
  }
  return 1;
}

int wield(string str){
  if(present(str, TP)->query_size()>1) {
    tell_object(TP, "%^BOLD%^%^RED%^You fumble for your " 
                   + present(str, TP)->query_name() + "%^BOLD%^%^RED%^,"
                   +" but you won't be able to wield something that"
                   +" large in the water!");

    tell_object(TP, "You'll have to try a smaller weapon, or fight empty"
                   +" handed.");
    return 1;
  }
  return 0;
}

void enter(object ob){
  direction += (ob, PORT);
  progress += (ob, 5);
}
void exit_right()
{
  object ob;
  if (direction == PORT){
    return;
  }
  tell_object(TP, "%^BOLD%^%^CYAN%^You manage to pull yourself, dripping"
                 +" %^BLUE%^wet%^CYAN%^ onto the bank of the river");

  progress = 0;
  TP->move_player(JUNG_ROOM7 + "riverbank");
}

int head_right(string str){
  if (progress ==5){
    new_croc();
  }
  if (progress > 9){
    direction = STARBOARD;
    exit_right();
    return 1;
  }
  if (direction == PORT){
    tell_object(TP, "%^BOLD%^%^BLUE%^You turn and start swimming in"
                  +" the other direction.%^RESET%^");
  }
  tell_object(TP,"%^CYAN%^You swim toward the right hand bank%^RESET%^");
  direction = NORTH;
  call_out("head_right2",3, TP);
  return 1;
}

void head_right2(object * ob)
{
  if (!objectp(ob)){return;}
  if (!present(ob,TO)){return;}
  if (direction == SOUTH){return;}
  if (present("croc",TO)) {
    tell_room(TO, "%^MAGENTA%^The crocodile is blocking your way!\n");
    return;
  }

  progress += 1;

  if (progress > 9) {
    exit_right();
    return;
  }
  else{
    tell_object(ob, "%^BOLD%^%^BLUE%^You make some progress toward the"
                  +" right hand bank of the river%^RESET%^");
    call_out("head_right2",3,ob);
  }
  if (random(5)==3){
    new_croc();
    return;
  }
}


void exit_left(){
  if (direction == STARBOARD){
    return;
  }
  tell_object(TP, "You've reached the left bank of the%^BOLD%^%^CYAN%^"
    +" river%^RESET%^, but with the speed of the %^BOLD%^%^BLUE%^water"
    +"%^RESET%^, the height and steepness of the %^ORANGE%^bank%^RESET%^,"
    +" and the %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^li%^ORANGE%^a%^GREEN%^ge"
    +" in your way, there's no way you're going to be able to get out here.");
}


int head_left(string str){
  if (progress ==5){
    new_croc();
  }
  if (progress < 1){
    direction = PORT;
    exit_left();
    return 1;
  }
  if (direction == STARBOARD){
    tell_object(TP, "%^BOLD%^%^BLUE%^You turn and start swimming in"
                  +" the other direction.%^RESET%^");
  }
  tell_object(TP,"%^CYAN%^You swim toward the left hand bank%^RESET%^");
  direction = PORT;
  call_out("head_left2",3, TP);
  return 1;
}

void head_left2(object * ob){
  if (!objectp(ob)){return;} 
  if (!present(ob,TO)){return;}
  if (direction == NORTH){return;}
  if (present("croc",TO)){
    tell_room(TO, "%^MAGENTA%^The crocodile is blocking your way!\n");
    return;
  }
  progress -= 1;
  if (progress ==5){
    new_croc();
  }
  if (progress < 1){
    exit_left();
    return;
  }
  else{
    tell_object(ob, "%^BOLD%^%^MAGENTA%^You manage to edge a little"
                   +" further south on your stomach, heading for the"
                   +" exit.%^RESET%^");

    call_out("head_south2",3,ob);
  }
}

void new_croc(){
  if (croc ==0){
    tell_room(TO, "%^BOLD%^%^GREEN%^A huge %^RESET%^%^GREEN%^croc "
                 +"%^BOLD%^%^GREEN%^appears out of nowhere and fastens"
                 +" its %^BOLD%^%^WHITE%^teeth %^BOLD%^%^GREEN%^onto"
                 +" your leg!");
    new(MOB+"gi_croc.c")->move(TO);
  }
  croc =1;
}
