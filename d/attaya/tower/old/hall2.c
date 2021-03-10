
#include <std.h>
#define MESSAGE ({"The hallway seems wrong somehow!",\
  "You feel as though someone is watching your every move!",\
   "%^BOLD%^%^BLUE%^A shadow decends upon you, seemingly from nowhere!",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Are you still alive?",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You intrigue me...",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Surely if you have made it this far, you know of my power.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Have you asked yourself why you are doing this?",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Do you not realize that it will be well beyond your lifetime when I finally control the land you call home.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You have no reason to seek vengeance.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^The world as you know it couldn't even exist if not for the changes brought about by my reign eons ago.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^ You don't really think you can win do you?",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^It doesn't have to be this way",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You don't have to die.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You have succeeded in proving your worth to me...  I would hate to have to destroy a fellow warrior.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^I remember back to the time when I would have done the same thing to make a name for myself...",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^My patience grows thin.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^%^RED%^In the end, nobody will remember you if you die here...  All your pathetic little hopes and ambitions mean nothing...",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Your exploits will be lost amidst the sands of time.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^I have opened a treasure vault nearby...  Take what you will, and leave.  Know that you get off well only because you are a true warrior and when you are long dead, I may make use of your skills in a way that you can never imagine.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^If you must confront me, know this...",\
    "%^BOLD%^%^RED%^Intruder tells you: %^RESET%^I shall destroy your very soul and leave your worthless corpse to rot away in my tower...  A grizzly reminder to anyone who ever passes through these halls again...  ONLY THE DEAD MAY PASS THROUGH THESE GATES!  Are you ready to die?"\
  "%^BOLD%^%^BLUE%^                                                 The shadow lifts."\
					})

inherit "/d/attaya/tower/spec/tower";

int flag;

void create(){
       ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no attack",1);
   set_property("no teleport",1);
       set_short("Inside the heart of the Kinnesaruda");
        set_long("
    This is the heart of the Kinnesaruda.  The walls are covered with patterned tiles and black curtains.  Polished silver sculptures line the hallway on either side.  
    A great energy flows in the air...  You can feel it around you.  It drapes over you and makes your lungs strain slightly more than normal for each breath as if the very air seeks to suffocate you.
    The ceiling above you is carpeted like the floor.
");
       set_exits(([
       "west" : "/d/attaya/tower/hall1",
       "east" : "/d/attaya/tower/hall5",
]));
       set_items(([
    "ceiling" : "The ceiling is carpeted just as the floor is.  It is almost like looking into a mirror!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "sculptures" : "The polished silver sculptures are very tall and loom out over the hallway making partial arches above you.  They look like representations of a woman lunging forward, but the image is stretched out and very thin.",
    "walls" : "The walls are comprised of decorated tiles.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init(){
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("intruder",1,TP, 1);
        ::init();
	}
	
void intruder(object ob, int flag){
	if(flag < sizeof(MESSAGE)){
		tell_object(ob,"%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("intruder",10,ob,flag);
	}
              else return;
}
	
