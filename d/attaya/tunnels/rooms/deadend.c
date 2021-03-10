//Coded by Lujke, with code stolen from Bane//
#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom.c";

int kneel = 1, triggered = 0, lface = 0, lring = 0;
object file1, file2, *things;

string long_desc();
void endit();
void endit2();
int face_trap(string str);
void face1();
void face2();
void face3();
int kneel_down(string str);
int look_face(string str);
int respect(string str);
int slam_door();
int slam_door2();
int face_trap(string str);




void create(){
lface = 0;
lring = 0;
    ::create();
   set("short", "%^BOLD%^%^BLACK%^A dead end");

   set_long((:TO,"long_desc":));

   set_property("indoors",1);
   set_property("light",2);

  set_smell("default","The air smells of damp stone");
  set_listen("default","You can hear the sound of music coming from deep"
                      +" within the tunnels.");

  set_exits( ([
	"north":TUNNELS+"tun06"
    ]) );
  set_door("metal door",TUNNELS"tun06","north",0); 

  set_items( ([ 
 ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black slate"
                          +". They are completely smooth other than the"
                          +" rock sculpture of the face in the far wall.",
  
  "ceiling" : "the ceiling is so high up as to be out of sight.", 
  
  "floor" : "The floor is smooth, and relatively free of dirt. There are"
           +" scuff marks on it suggesting this place is frequently"
           +" travelled. There are pairs of longer marks right in front"
           +" of the face, and you could almost imagine that people have"
           +" been kneeling there.",

   ]) );

  set_door_description("metal door","%^BOLD%^%^BLACK%^A solid door of"
                      +" %^RESET%^impenetrable-looking %^BOLD%^"
                      +"%^BLACK%^black iron%^RESET%^");
  
  set_lock_description("metal door","lock","%^MAGENTA%^A %^BOLD%^"
                      +"%^YELLOW%^complex%^RESET%^%^MAGENTA%^,"
                      +" tricksy-looking five tumbler lock arrangement");

lock_difficulty("metal door",50,"lock");

  set_search("walls","Unlike some other sections of the tunnels, the"
            +" walls here are free of cracks and fissures." );

  set_trap_functions(({"ring", "face","ring", "ring"}),({"face_trap",
 "face_trap", "face_trap","face_trap"}),({"pull", "lead", "tug",
 "yank"}));

  set_property("no teleport",1);

}

void init(){
   ::init();
   add_action("kneel_down","kneel");
   add_action("kneel_down","worship");
   add_action("kneel_down","kneel face");
   add_action("kneel_down","kneel before face");
   add_action("kneel_down","worship face");
   add_action("kneel_down","worship ahmul");
   add_action("kneel_down","kneel ahmul");
   add_action("respect","respect");
   add_action("respect","pay");


   add_action("look_face","look");
}

string long_desc(){
    return  "%^BOLD%^%^BLACK%^The tunnels come to a dead end here, with"
           +" no way to continue. In the middle of the facing wall the"
           +" rock has been sculpted into a handsome, human-like face"
           +" wearing a sardonic smile. Protruding from the nose of the"
           +" sculpture is a small %^YELLOW%^br%^RESET%^%^ORANGE%^a"
           +"%^BOLD%^%^YELLOW%^ss r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW"
           +"%^ng %^BLACK%^.%^RESET%^";
}

int slam_door()
{
call_out("slam_door2",1);
}

int slam_door2()
{
  tell_room(TO,"%^BOLD%^%^BLUE%^As you enter, the%^RESET%^ solid metal"
              +" door %^BOLD%^%^BLUE%^slams shut behind you with a loud"
              +" %^BOLD%^%^YELLOW%^CLANG%^BLUE%^, sealing you in"
              +"%^RESET%^");
  set_open("metal door",0);
  set_locked("metal door",1,"lock");
}

int look_face(string str){

if (str == "face"|| str == "sculpture")
  {
    tell_object(TP, "%^ORANGE%^The handsome face has refined features and"
                   +" has a neatly trimmed goatee. It wears a smile, and"
                   +" you can make out the tips of pointed teeth between"
                   +" its lips. A pair of small horns sit on its forehead"
                   +", and you notice that the eyes, which have been"
                   +" carved with vertical slits for pupils, are looking"
                   +" down at the floor. The small %^BOLD%^%^YELLOW%^br"
                   +"%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^ss r%^RESET%^"
                   +"%^ORANGE%^i%^BOLD%^%^YELLOW%^ng%^RESET%^%^ORANGE%^"
                   +" dangling from its nose looks like some kind of"
                   +" exotic jewelry.");

    tell_room(TO,TPQCN + " looks over the face in the wall",TP);

    if (lface == 1)
	{
	  return 1;
	}
    call_out("mouthsay", 1, "Ah... so you look upon the face of Ahmul"
            +" Rhaj, Lord of the third circle of the seventh hell."
            +" %^BOLD%^%^BLACK%^Fear Him.%^RESET%^%^GREEN%^ Pay your"
            +" respects to Him and leave. I warned you. You should not"
            +" have come here.");
    lface = 1;
    return 1;
    }
  if (str !="ring")
  {
    return 0;
  }
  tell_object(TP, "the little %^BOLD%^%^YELLOW%^br%^RESET%^%^ORANGE%^a"
                 +"%^BOLD%^%^YELLOW%^ss r%^RESET%^%^ORANGE%^i%^BOLD%^"
                 +"%^YELLOW%^ng%^RESET%^ dangles from the nose of the"
                 +" sculpture, making it look like it could be lead about"
                 +" by it like a bull.");

  tell_room(TO,TPQCN + " looks over the %^BOLD%^%^YELLOW%^br%^RESET%^"
             +"%^ORANGE%^a%^BOLD%^%^YELLOW%^ss r%^RESET%^%^ORANGE%^i"
             +"%^BOLD%^%^YELLOW%^ng%^RESET%^" ,TP);

  if (lring == 1)
  {
    return 1;
  }
  call_out("mouthsay", 2, "You really shouldn't pull that, you know."
          +" Though I don't know if it is even worth telling you any"
          +" more.");
  lring = 1;
  return 1;
}

int face_trap(string str){
  if (triggered == 1)
  {
    tell_object(TP, "%^MAGENTA%^You pull on the %^BOLD%^%^YELLOW%^br"
                   +"%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^ss r%^RESET%^"
                   +"%^ORANGE%^i%^BOLD%^%^YELLOW%^ng%^RESET%^%^MAGENTA%^"
                   +" but nothing happens");

    tell_room(TO,TPQCN + "%^MAGENTA%^ seems to fiddle with the small"
               +" %^BOLD%^%^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^"
               +"%^YELLOW%^ss r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ng"
               +"%^RESET%^%^%^MAGENTA%^ again, but nothing happens.", TP);

    return 1;
    }
    else
    {
      triggered = 1;
    }
    if (query_verb()=="lead")
    {
      if (str != "face" && str != "ahmul" && str != "ahmul rhaj" 
                                                && str != "devil")
    {
      tell_object(TP, query_verb()+" what?");
      return 1;
    }
  }
  else
  {
    if (str != "ring" && str != "brass ring"  && str != "small ring"
                                         && str != "small brass ring")
    {
	tell_object(TP, query_verb()+" what?");
	return 1;
    }
  }
  tell_object(TP,"%^MAGENTA%^You hook your finger through the %^BOLD%^"
                +"%^YELLOW%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ng"
                +"%^RESET%^%^MAGENTA%^ and tug. To your slight surprise,"
                +" it gives way to your pull...and then to your greater"
                +" surprise more things begin to happen...\n");

  tell_room(TO,TPQCN + "%^MAGENTA%^ seems to fiddle with the small"
              +" %^BOLD%^%^YELLOW%^br%^RESET%^%^ORANGE%^a%^BOLD%^"
              +"%^YELLOW%^ss r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ng"
              +"%^RESET%^%^%^MAGENTA%^ set into the face of the sculpture"
              +" on the far wall.\n", TP);

  tell_room(TO,"%^MAGENTA%^%^MAGENTA%^The eyes of the sculpted face of"
              +" %^RED%^Ahmul Rhaj%^RESET%^%^MAGENTA%^ glow %^RED%^r"
              +"%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^MAGENTA%^ and the"
              +" %^BOLD%^%^BLACK%^metal door %^YELLOW%^slams%^RESET%^"
              +"%^MAGENTA%^ closed. There is a%^RESET%^ metallic grinding"
              +"%^MAGENTA%^ as the lock slides shut. The room starts" 
              +" to %^BOLD%^%^GREEN%^shake%^RESET%^%^MAGENTA%^ and"
              +" %^BOLD%^%^GREEN%^rumble%^RESET%^%^MAGENTA%^.\n");

  call_out("face1",3);
  kneel = 1;
  toggle_trap("pull");
  set_open("metal door",0);
  set_locked("metal door",1,"lock");
  return 1;
}


void face1(){
  if(!kneel) return 1;
  
  tell_room(TO,"%^MAGENTA%^The %^BOLD%^%^BLACK%^whole wall%^RESET%^"
              +"%^MAGENTA%^ begins sliding towards you as the sculpted"
              +" face of %^RED%^Ahmul Rhaj%^MAGENTA%^ seeks to"
              +" %^BOLD%^%^RED%^crush%^RESET%^%^MAGENTA%^ you against the"
              +" back wall.\n");
 
 call_out("face2",15);
  return 1;
}

void face2(){
  if(!kneel) return 1;

  tell_room(TO,"%^MAGENTA%^The eyes of the sculpted face of %^RED%^Ahmul"
              +" Rhaj%^RESET%^%^MAGENTA%^ glow"
              +" %^RED%^br%^BOLD%^%^RED%^ig%^MAGENTA%^h%^RED%^tl%^RESET%^"
              +"%^RED%^y%^RESET%^%^MAGENTA%^ as everyone present is"
              +" squashed right up against the back wall of the room\n");

  call_out("face3",15);
  return 1;
}

void face3(){
  int hp, i;
  if(!kneel) return 1;
  things = all_living(TO);

  tell_room(TO,"%^MAGENTA%^You are pushed right against the back wall of"
              +" the room and the sculpted face of %^RED%^Ahmul Rhaj"
              +" %^RESET%^%^MAGENTA%^continues forwards, crushing you"
              +"!\n");

  for(i=0;i<sizeof(things);i++)
  {
    hp = (int)things[i]->query_max_hp()/5;
    things[i]->do_damage(things[i]->return_target_limb(),random(hp));
    things[i]->add_attacker(TO);
    things[i]->continue_attack();
    if(objectp(things[i]))    things[i]->remove_attacker(TO);

  }
  if(sizeof(things) != 0){
  call_out("face3",15);
  } 
  else 
  {
    call_out("endit",3);
  }
  return 1;
}

int respect(string str)
{
  switch (random(4))
  {
  case 0:
    tell_object(TP, "How are you going to pay respect?");
    break;
  case 1:
    tell_object(TP, "What are you going to do to pay respect?");
    break;   
  case 2:
    tell_object(TP, "How do you show your respect?");
    break;   
  case 3:
    tell_object(TP, "What do you do to you show your respect?\n"
                   +"Look around. There must be a clue in here"
                   +" somewhere!");
    break;   
  }
  return 1;
}

int kneel_down(string str){
  if (query_verb()=="kneel")
  {
    if(!str || (str != "face" && str != "before face" && str != 
"ahmul rhaj" && str != "before ahmul rhaj" && str != "devil" && 
str != "before devil" && str != "sculpture" && str != "before sculpture"
 && str != "ahmul" && str != "before ahmul" && str !="before the face" && str !="floor" && str != "before the sculpture" && str != "on floor" && str != "on the floor" && str !="before the devil" )) 
    {
      tell_object(TP,"kneel where?");
      return 1;
    }
  }
  if (query_verb()=="worship")
  {
    if(!str ||str != "face" && str != "ahmul rhaj"  && str != "devil" && 
 str != "sculpture" && str != "ahmul") 
    {
      tell_object(TP,"worship what?");
      return 1;
    }
  }
  tell_object(TP,"%^BOLD%^%^BLACK%^You %^RESET%^%^GREEN%^kneel%^BOLD%^"
                +"%^BLACK%^ on the floor in desperate %^RESET%^"
                +"%^GREEN%^supplication%^BOLD%^%^BLACK%^ and pay your"
                +" respects to %^RED%^Ahmul Rhaj%^BLACK%^.\n");

  tell_room(TO,TPQCN + " %^RESET%^%^GREEN%^kneels%^BOLD%^%^BLACK%^ on"
             +" the floor in depserate %^RESET%^%^GREEN%^supplication"
             +"%^BOLD%^%^BLACK%^ and pays respects to %^RED%^Ahmul Rhaj"
             +"%^BLACK%^.\n", TP);

  if(kneel == 0)
  {
    tell_object(TP,"Nothing happens.");
  } 
  else 
  {
    call_out("endit",5);
    kneel = 0;
  }
  return 1;
}

void endit(){

  if (triggered!=1)
  {
    endit2();
    return;
  }

  tell_room(TO,"%^ORANGE%^The %^RED%^red gl%^BOLD%^%^RED%^o%^RESET%^"
              +"%^RED%^w%^RESET%^%^ORANGE%^ in the eyes of the sculpture"
              +" abrubtly winks out, and the wall begins sliding back"
              +" into place\n");

  call_out("endit2",10);
  return;
}

void endit2(){

  tell_room(TO,"%^ORANGE%^There is a %^RESET%^metallic grinding%^ORANGE%^"
              +", as the metal door unlocks itself, and then swings"
              +" open\n");

  set_locked("metal door",0,"lock");
  set_open("metal door",1);
  find_object_or_load(TUNNELS+"tun06")->set_locked("metal door",0,"lock");
  find_object_or_load(TUNNELS+"tun06")->set_open("metal door",1);
  triggered = 0;
  kneel =1;
  return;
}

void reset(){
  ::reset();
  if(!trapped("pull ring"))
  toggle_trap("pull ring");
}
