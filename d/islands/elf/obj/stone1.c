#include <std.h>
inherit OBJECT;

void create() {
  set_id( ({"stone","boulder","moonstone"}));
  set_name("Stone of remembrance");
  set_short("%^RESET%^%^CYAN%^A moonstone boulder");
  set_weight(10000000);
  set_value(0);
  set_property("no animate", 1);
  set_long("%^CYAN%^This is a very large boulder made "+
  "from moonstone.  It has some dead vines that"+
  " cover it and seem to form runes.  Perhaps"+
  " one could %^GREEN%^_touch_%^CYAN%^ it.");
}
void init(){
  ::init();
  add_action("touch_fun","touch");
  return;
}

void play_scene(int cnt){
string *msg;

msg = ({"Your vision blurs and you enter a dream-like trance.",
"In this vision you are experiencing another's memory from their point of view.",
"You find yourself in a lush forest hunting with an elf.",
"You look down at yourself and find that you are also of slender build with pointed ears with strange woodland clothing.",
"The elf wanders effortlessly through the forest following tracks of an animal he is hunting.",
"The two of you stop and listen.  Some kind of chopping sound fills the forest.",
"The elf you are with travels towards the sound and you follow.",
"You and your fellow elven companion come upon a group of human loggers.",
"Horror fills your heart as you come upon a whole grove of felled trees.",
"Humans cut up the trees and load them on a cart for beasts of burden to haul away.",
"Your companion confronts one of the humans and angrily tells them to leave saying they have no right to do this horrible thing to the trees.",
"One of the humans is holding an ax and gurgles something that you don't understand.",
"He goes back to cutting into a large tree that is already partly chopped.",
"You draw you bow and point an arrow at him telling him to stop and leave.",
"The scene continues to escalate as the group of loggers gurgle more angry words in an incomprehensible language.  They are clearly annoyed that you and your friend are getting in the way of their work.",
"Eventually it comes to blows. As the humans try to chase you and your"
" friend off, an arrow flies and strikes a human in a well-placed shot"
" through his hand.",
"The humans all attack at once injuring you and your hunter companion with axes and spears.",
"Both of you are driven off with bad wounds.  ",
"Your friend is bleeding profusely.  ",
"You have to leave him behind after a couple miles back into the forest.",
"He doesn't look like he'll make it but you must go get help.",
"By the time you get back with a healer from the camp it is too late.",
"Your fellow hunter bled out and lay there not breathing.  ",
"A feeling of mourning passes over you."});

 write("%^GREEN%^"+msg[cnt]);
 if (cnt == sizeof(msg)-1) return;
 call_out("play_scene",4,cnt+1); 
 return;
}
void touch_fun(string str){
   if ( !str || str !="stone" && str !="moonstone" && str !="boulder") {
      notify_fail ("Touch what?  The stone?\n");
      return 0;
   }
   else 
      if (find_call_out("play_scene") != -1) {
	  notify_fail("The stone is in use.");
	  return 0;
	  }
   play_scene(0);
   tell_room(ETO,""+TPQCN+" touches the stone.",TP);
   write("You touch the stone");
   TP->set_disable(40);
   return 1;
}
