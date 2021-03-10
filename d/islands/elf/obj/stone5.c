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

msg = ({"You feel your mind tumbling through the distant past as "+
"you gaze at the stone. ",
"You arent sure how far back your mind is reaching, but as the memories become clearer,"+
" it is clear that this isn't your time and place. ",
"You can hear a slight crackle coming towards you at ever increasing speeds.",
" You dive out of the way, unsure if you dove in the right direction.", 
"A crack, snap and pop can be heard as a bolt of lightning slams into the "+
"ancient oak tree that was behind you. ",
"The tall, ancient oak begins to tumble down towards the earth. You stagger "+
"to move out of the way, your leg pinned by the corpses of your fellow elven "
"scouts.",
" As death quickly approaches you, it dawns on you that no one will "+
"be left to tell the others of the impending attack.",});
 write("%^GREEN%^"+msg[cnt]);
 if (cnt == sizeof(msg)-1) return;
 call_out("play_scene",4,cnt+1); 
 return;
}
void touch_fun(string str){
   if ( !str || str !="stone" && str !="moonstone" && str !="boulder") {
      notify_fail ("Touch what?\n");
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
