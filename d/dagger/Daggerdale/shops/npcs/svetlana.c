#include <std.h>
inherit "/std/comp_vend.c";
string *badpeople;
void do_display_help();
void do_say(string str);

void create() {
   ::create();
set_name("svetlana");

set_id(({"svetlana", "slerk", "shop keeper", "shopkeeper"}));
set_short("Svetlana, the Magus");
   set("aggressive", 0);
   set_level(19);
    set_long(
"Svetlana is a tall, beautiful human female with long black hair. "+
"She wears long flowing red robes, etched with many arcane symbols all "+
"over the fabric. "+
"Svetlana will sell you components needed to cast spells! "+
"Say help and she'll help you.");
   set_languages( ({ "common" }) );
set_gender("female");
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
}
void init() {
  ::init();
  add_action("do_player_say","say");
}
 
int do_player_say(string str) {
  if(str=="help") {
message("talk","%^MAGENTA%^"+TPQCN+" says%^RESET%^\: help",
environment(TP),TP);
message("talk","%^MAGENTA%^You say%^RESET%^\: help",
TP);
    do_display_help();
  return 1;
  }
  return 0;
}
 
void do_display_help() {
  do_say("So, you think >I< should help you eh?");
   do_say("Well, i suppose so.. ");
  do_say("This is where you buy your spell components. ");
  do_say("Components are ingredients used in your spells, without them, "+
"you can't cast certain spells!");

  do_say("I can <list comp>onents if you wish, or you can <buy> them.");
  do_say("And don't forget, PUT YOUR COMPONENTS IN YOUR COMPONENT BAG!");
  do_say("You wouldn't believe how many newbies forget that!");
   do_say("Now buy something or go away! I'm a busy woman!");
}
 
do_say(string str) {
    TO->force_me("say "+str);
}
//eof

