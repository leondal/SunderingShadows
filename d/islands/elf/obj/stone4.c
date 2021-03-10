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
"In this vision you take the role of an elf at the midsummer night's festival.",
"The festival takes place in an open clearing filled with healthy grass.  Trees line the valley.",
"Many of the trees are "
"decorated with things found in the forest.  There are flowers and "
"sweet-smelling plants hung about.",
"Elves line the clearing to celebrate the "
"blessings of the summer.  There is dancing, giving of gifts and romance.",
"You join the pleasantries and dance with several partners.",
"You exchange gifts with one of "
"the partners you enjoyed dancing with. ",
"In the festival gifts are given and often given again at the next year's revelries.",
"You hand your partner a green leather bracer and "
"receive a simple quartz pendant.",});
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
