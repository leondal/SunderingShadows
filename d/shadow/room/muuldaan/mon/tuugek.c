#include <std.h>
#include "../defs.h"
inherit "/std/comp_vend.c";

void create(){
   ::create();
   set_name("tuugek");
   set_id(({"tuugek","shop keeper","goblin scavenger","scavenger","shopkeeper","mage"}) );
   set_short("Tuugek, goblin scavenger");
   set_long("Tuugek is the usual spindly-legged creature of his race, with thin unkempt hair and sickly "
"yellow eyes.  His teeth nearly match the colour of his eyes, decayed to a dull hue and wickedly sharp.  He "
"seems to have gathered quite a hoard of trash to himself here, in various piles around him, which he "
"guards jealously in the hope of selling to others for money.\nTo get a list of shop commands, type%^YELLOW%^"
" help shop%^RESET%^.");
   set_gender("male");
   set_alignment(9);
   set_race("goblin");
   set_body_type("human");
   set_class("mage");
   set_hd(30,1);
   set_property("no bump", 1);
   set_emotes(6,({"%^MAGENTA%^Tuugek holds out a handful of bat dung to you, looking hopeful.","%^MAGENTA%^"
"Tuugek grins and says:%^RESET%^ You wizardy sort, you buy, yes?","Tuugek rummages through a pile of crap "
"off to one side, looking for something.","Tuugek scratches some wax from his ear with one claw, thinks for "
"a moment, and adds it to a pile beside him.","%^MAGENTA%^Tuugek screeches at you:%^RESET%^ Ya bring shineys "
"an me gets lotsa wizardy stuffs for ya!"}), 0);
   set_components(100);
   set_spell_chance(100);
   set_spells(({"fireball","lightning bolt","acid arrow","acid arrow","magic missile","magic missile","magic missile"}));
   set_spoken("undercommon");
}
