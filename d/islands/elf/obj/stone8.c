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

msg = ({"Your vision blurs as you touch the stone and enter a dream-like trance.",
"Eventually it clears and you find yourself unable to control your body like you"+
" are in someone else's memories experiencing it as a spectator.",
"The elders ruling was a surprise.  You didn't think they would "+
"ever lower themselves to allow their princess to marry the "+
"king's son much less allow the land that they had cared for thousands "+
"of years to be ruled over partly by a human.",
"Times were desperate indeed.  ",
"The king's youngest son came himself came to meet the princess.  "+
"He must have made quite the impression on the council.  Yes we"+
" will have to pay tribute but it is nothing compared to this war"+
" which has already cost thousands of lives.  ",
"Or so you thought years ago. Things started out well.  "+
"The human lord signed the peace treaty and the armies were "+
"withdrawn.  The human prince and the princess even bore two "+
"children - one a son and the other a daughter.  One night though the lord "+
"was murdered in his bed.  The princess, who had grown to"+
" love him, was beside herself with grief  ",
"Demands were sent from the human king that she remarry"+
" another one of his sons.  She, of course, refused. "+
"Then the armies came back, and this time they "+
"meant to wipe out the broken elven nation.",  
"When the castle was under siege, the princess took her own life. "+
" She had the governesses take the children different "+
"directions so as to have a better chance of escape.",  
"The forests were burning. The people - your people -"+
" had been betrayed and now were being exterminated.",});
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
