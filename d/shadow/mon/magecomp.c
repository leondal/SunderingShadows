#include <std.h>
inherit "/std/comp_vend.c";
int flag;
void do_display_help();

create() {
   ::create();
    set_name("Ragus");
    set_id( ({ "ragus", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Ragus, the spell-weaver");
   set("aggressive", 0);
   set_level(19);
    set_long(
"Ragus is a tall, ancient human with long white hair and a beard. He wears "+
"some long black robes, with many different arcane symbols scattered all over"+
" it.  Ragus will sell you components needed to cast spells!  Say help and "+
"he'll help you.");
   set_gender("male");
   set_alignment(5);
   set("race", "human");
    set_class("mage");
    set_hd(25,1);
  set_level(12);
    set_body_type("human");
    set_property("no bump", 1);
      set_components(100);
    set_spell_chance(90);
    set_spells(({
"acid arrow",
"burning hands",
"color spray",
"chill touch",
"hideous laughter",
"magic missile",
"lightning bolt",
"scorcher",
"cone of cold",
}));
    set_emotes(4,({
"Ragus searches around through his pockets and glares at you 'Where's my "+
"wand?!'",
"Ragus smirks at you",
"Ragus pats you on your head and laughs",
"Ragus waves his hand and colors fill the air and swirl around him.",
"Ragus pulls out his wand and looks at you, grinning.",
"%^MAGENTA%^Ragus says%^RESET%^: So, whatta ya want kid?",
"Ragus rolls his eyes",
"%^MAGENTA%^Ragus says%^RESET%^: Do you need help? You sure look like it.. "+
"Just say so!",
}));
  set_exp(1);
   remove_std_db();
}
 
void catch_say(string message){
   if(strsrch(message,"help") != -1 && !flag){
      call_out("do_display_help",1);
      flag = 1;
      call_out("reset_flag",20);
  }
}
 
void do_display_help() {
command("say So, you think >I< should help you eh?");
   command("Well, I suppose so...");
   command("This is where you buy your spell components.");
   command("Components are ingredients used in your spells, without them, "+
"you can't cast certain spells!");

   command("say I can <list components> if you wish, or you can <buy> them.");
  command("say And don't forget, PUT YOUR COMPONENTS IN YOUR COMPONENT BAG!");
   command("say You wouldn't believe how many newbies forget that!");
   command("say Now buy something or go away! I'm a busy man!");
}
 

void reset_flag(){
   flag = 0;
}
//eof
