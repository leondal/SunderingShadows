
#include <std.h>
#include "../elf.h"

inherit "/std/comp_vend.c";

void create(){
   ::create();
   set_name("Elendil Saralondyo");
   set_id(({"Elendil Saralondyo","clerk","shop keeper","elf","mage","shopkeeper","elendil","alchemist"}));
   set_short("Elendil Saralondyo, elven alchemist");
   set("aggressive", 0);
   set_long("Elendil Saralondyo is a young alchemist of some reputation.  "
      "His store is known for keeping rare items in stock, and he employs "
      "elves to go out and hunt for components that are in demand.  He has "
      "close cropped gold hair and clear blue eyes.  He wears a simple robe "
      "that has bright shades of silver with patterns of gold sewn around it.\n\n"
      "For a list of shop commands, type <help shop>.");
   set_gender("male");
   set_alignment(1);
   set_race("elf");
   set_class("mage");
   set_hd(30,2);
   set_level(30);
   set_guild_level("mage",30);
   set_property("no bump", 1);
   set_emotes(6,({"%^MAGENTA%^Elendil Saralondyo says%^RESET%^: You see anything you like?",
      "%^MAGENTA%^Elendil Saralondyo says:%^RESET%^ What did I do with that diamond dust?  It is expensive to replace.",
      "%^MAGENTA%^Elendil Saralondyo says:%^RESET%^ Fetch this slug, fetch that eyelash.  An elf's work is never done.",
      "%^MAGENTA%^Elendil Saralondyo whispers:%^RESET%^ Let me tell you something... most of the mages... buy from me because they hate getting their hands dirty finding it themselves.",
      "Elendil Saralondyo scratches his head thoughtfully.","Elendil Saralondyo nods and smiles."}), 0);
   set_emotes(20, ({"%^MAGENTA%^Elendil Saralondyo says:%^RESET%^ I won't stand for this. ",
                "%^MAGENTA%^Elendil Saralondyo yells:%^RESET%^ Get out of my shop ruffian!",
                "%^MAGENTA%^Elendil Saralondyo says:%^RESET%^ Guards!",
                "%^MAGENTA%^Elendil Saralondyo says:%^RESET%^ You leave and never come back."}), 1);
   set_components(100);
   set_spell_chance(100);
   set_spells(({"fireball","lightning bolt","acid arrow",
        "powerword stun", "chain lightning", "magic missile"}));
   set_property("strength","spells");
   set_base_damage_type("bludgeoning"); 
}
