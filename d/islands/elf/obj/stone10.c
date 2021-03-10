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
"You glance around in the memories"+
" of a young scout.  You are mounted on a"+
" dire owl flying over the forests at night.",
"  The elders ordered you and the others"+
" to find and evacuate elves that were left stranded from the human army's march.  ",
"Looking down you can see camps and supply lines."+
"  Torches line the forest like lines. "+
" There are larger fires where tree villages used to stand."+
"  Now they are just forest fires that have been set ablaze.  ",
"Rumors had it that the high magi were planning "+
"something that could stop the humans.  You didn't"+
" know the details but your superior said that any "+
"survivors should be taken out of the woods and towards "+
"the mountains.  You've been at this for several days "+
"but without much luck of finding survivors.  ",
"Hopefully they didn't consider yourself a casualty "+
"for being so long over due.",
"---All of a sudden there it is, you feel it--a sudden tug"+
" in the weave.  It seems faint at first but it grew stronger"+
" and stronger.  ",
"A few minutes later you see a blue ray of light pierce "+
"through the clouds and strike down to the west not far from the coast.  ",
"The humans lived there, perhaps this was some kind of "+
"counter attack from the elven high magi.",
"Raw energy pulsed into the ground.  You hear "+
"a terrible rumbling as the earth begins to shake.  ",
"Trees crack and fall over as the ground lurches "+
"below you.  You can only imagine how terrible this "+
"must seem to anyone below still on the ground.  ",
"The pillar of light flashes brightly then dissipates"+
" off in the distance. ",
"After the spell fades there are many aftershocks. "+
" It takes a few hours but you notice the whole of the"+
" coast seems to be drifting towards the sea.  ",
"You fly towards the coast and find the sea has advanced inland for miles. ",  
"Whole human cities are now submerged into the salty depths.",
"The sinking seem to just continue and continue.  ",
"You head back to the mountains to report your findings. ", 
"You find the lower ranks of the human armies in disarray"+
" as they abandon siege equipment seeking higher ground. "+
" The ground continues to groan and thrash as it sinks further down. "+
" Roads become rivers as the sea presses in.",
"  Tips of trees can be seen as in the water as"+
" their trunks become submerged.",
"Eventually you make it back to the mountain"+
" citadel and report your findings to the sun elf elders "+
"that run the place.  ",
"The mountain seem much colder than you remember.",
"The image blurs, and you find yourself doing your rounds again "
"some time later.",
"Flying upon the owl you look around in "+
"dismay.  What once were a coast and the surrounding forest are "+
"completely gone. ",
" The whole area sunk thousands of feet and is "+
"drifting north. ",
" Snow is the norm now.",
"  Every day is colder.    ", 
"You circle around the island - yes, island. That is all that is left now, "+
"freezing rocks jutting out of the ocean. ",
"The humans were beaten, nay, exterminated.  But at this cost?  ",});
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
