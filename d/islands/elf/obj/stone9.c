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
"It is night, and you stand looking out the "+
"window of a tower where your lab is.  You can see "+
"lines of torches that stretch as far as the eye can see.",
"  They look like burning snakes "+
"constricting the forests - elven lands. You can almost feel the flaming "+
"serpents choking the life out of your civilization.  ",
"You straighten your robe and head back inside.  You "+
"whisper a quick prayer to Corellon asking for wisdom and forgiveness.",  
"You were the last of the high magi holding out "+
"against the use of the sundering ritual to stop the humans.",
"There really was little left to save, all of the "+
"moon elven houses had already fallen beneath the"+
" relentless boot of the human armies.",  
"Your own sons and daughters had joined the call "+
"fighting alongside the moon elves to defend their "+
"homes and force out the invaders.  ",
"There hadn't been word from them in weeks.  "+
"You could only assume the worst.  ",
"As you look at yourself in the mirror you ponder the"+
" hundreds of years spent here as a high mage.  You"+
" remember when the humans first settled along the coasts.",  
"It seems like yesterday they were simply pilgrims "+
"looking for a new home.",
"You steel yourself and remind yourself yet "+
"again not to think like that.  Out loud you "+
"say to your reflection, 'I must keep focused. "+
"The others in the circle need me. In a "+
"week's time, they will ascend the mountain, and even this place will be "+
"crushed under human boots.'",
"The others were right.  The land rejects them. The coastal "
"kingdoms were places devoid of nature.",
"  Squalid cities full of pollution and rampant disease."+
"  If the humans had their way the once beautiful "+
"elven lands would end up like that too.",
"  No, for my children's sake it is better"+
" they tasted this one last justice so they"+
" would know the land rejects them.  ",
"All humans should pay with their lives"+
" for the genocide that dirties their hands. ",});
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
