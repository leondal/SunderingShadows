#include <std.h>
inherit TOWNSMAN;

void create(){
   int level;
   object ob;
   ::create();
   set_name("Gruunanghaer");
   set_short("Gruunanghaer, the bank teller");
   set_id(({"Gruunanghaer","bank teller","teller","gruunanghaer"}));
   set_long("This mostly-clean creature is quite different to almost every other creature in here.  His gaze "
"shows a sharp intelligence above the other beasts around, and he carries himself with a distinct pride.  He "
"has dull blue skin and darker hair, which falls forward around the two ivory horns upon his head.  He keeps a "
"close watch on everyone that enters the cavern.");
   set_body_type("human");
   set_race("ogre-mage");
   set_gender("male");
   set_class("fighter");
   level = random(5)+17;
   set_guild_level("fighter",level);
   set_hd(level,10);
   set_exp(300);
   set_max_hp(250+random(75));
   set_hp(query_max_hp());
   set_overall_ac(-10);
   set_property("swarm",1);
   set_alignment(3);
   set_size(3);
   set_stats("strength", random(4)+15);
   set_stats("constitution", random(9)+10);
   set_stats("wisdom", random(8)+9);
   set_stats("charisma", random(5)+9);
   set_stats("intelligence", random(7)+9);
   set_stats("dexterity", random(8)+11);
   set_spoken("undercommon");
   set_emotes(1,({
     "Gruunanghaer counts and recounts the money, glaring at anyone getting too close.",
     "Gruunanghaer scrawls down some figures on an old piece of parchment.",
     "Gruunanghaer tosses a counted bag of gold over his shoulder into the vault.",
     "Gruunanghaer watches you very carefully."}), 0);
}

