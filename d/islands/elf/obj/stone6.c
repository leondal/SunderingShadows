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

msg = ({"You feel your mind tumbling through the distant past as you place your hand on the stone.",
"Everything around you fades and you find yourself in a large room with several other elves.",
"One elf says:  'We must do something about these humans.  They ravage the forests like orcs'",
"Another answers:  'No, they are worse than orcs.  At least the beasts are less organized.'",
"Yet another says: 'It is as the seers have been saying, the twilight of the elves is upon us.'",
"This quiets the counsil.",
"You speak up:  'I say we try to make peace with them, come to some kind of a treaty.'",
"The other elves consider this.",
"The one elf says:  'How do you propose this?  They come to our forests, axes in hands.  I don't see how we could arrange a parlay.'",
"You answer:  'I will go myself to their city unarmed and request to meet with their elders.'",
"The image fades and reforms again.",
"You are standing in a wooden longhouse with a human who wears an iron crown.",
"He says:  'Why do your people keep attacking us?  All we wish is to provide for our families'",
"You bite your lip at how absurd this is and answer:  'You are attacking our friends, the trees clear cutting them.  We have protected these forest for thousands of years.   But that is not why I came here.'",
"The crowned man raises an eyebrow:  'Why is it you have come here then?  You have the king's ear.'",
"You say: 'I've come to discuss a way to end this conflict.  Please tell me how we can stop this bloodshed.'",
"The king considers this and says, 'I have many sons, I hear elven maids are of unequal beauty.   I shall grant you lands that he and she shall rule over and they shall be the owners of that forest.'",
"You can think of some rather unpleasant answers to this but nod.",
"You say politely:  'I will take this request to the elders.'",
"The vision blurs and you find yourself looking again at the strange stone.",});
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
   TP->force_me("emote touches the stone.");
   TP->set_disable(40);
   return 1;
}
