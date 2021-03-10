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
"Things have made a turn for the worse.",
"Before you what was once an elven village is now the remains of a forest fire.",
"When they lost contact you were sent out to investigate.  It seems like the humans found it and decided it would be best to slash and burn.",
"You take a walk through the rubble in hopes to find survivors.  There are none.  ",
"Pyres set with felled trees are choked with charred flesh and bones.  It seems like the humans are not even taking captives anymore.",
"You say a mournful prayer for those that died in such an unjust way.",
"How long will all their deaths go unavenged?  ",});
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
