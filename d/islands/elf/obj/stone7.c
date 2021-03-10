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
"You were recently beaten by humans and left naked and dying by the"+
" side of the road outside Tharis.",
"Several gold elves find you, one of them a healer"+
" tending to your wounds.",
"You agree to go with them and not return to Tharis.",
"They magically transport you back to their keep "+
"and set you up with a place in a lovely grove.  "+
"Life here is nothing like the and terrible life you lived "+
"in the elven quarter where you were treated like scum. "+
" You find yourself grateful, but quite out of place.",
"The vision blurs as time fast forwards and you find "+
"yourself standing before a circle of gold elves.",
"They ask you if you have completed your training"+
" to which you reply in the affirmative.",
"They then ask you if you wish to devote the rest"+
" of your years in defense of this, one of the last elven keeps.",
"You were told before that this was a noble thing to do"+
" and agreed to train and this day was long in the waiting.",
"The gold elves saved you from a miserable life and"+
" taught you culture and how to defend the people.",
"The elven magi form a circle around you and begin "+
"to chant powerful magic that you can feel in your very soul.",
"The vision darkens and then reforms.",
"You find yourself laying in bed with a female gold elf taking "+
"care over you.  She shows you a mirror and you find yourself changed.",
"'Cousin, you've made a great sacrifice, to devote your life as a"+
" mirror warrior, Corellon bless your efforts and that of your "+
"new companions in keeping this grove forever a sanctuary', The gold elf states, making you feel proud.",});
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
