//updated by Circe 11/1/04 with new desc, etc.
#include <std.h>

inherit "/std/comp_vend";

void create() {
   ::create();
   set_name("I-chou");
   set_id(({"I-chou","clerk","shop keeper","shopkeeper","alchemist","i-chou"}));
   set_short("I-chou, The Alchemist");
   set("aggressive",0);
   set_level(19);
   set_long("I-chou is an aging man with light tan skin the color "+
      "of aged parchment.  His slightly almond-shaped eyes are "+
      "surrounded with deep black lashes beneath thin graying "+
      "eyebrows.  His eyes and the slight broadening of his nose "+
      "mark him as not entirely Tharisian.  It is unclear what his "+
      "heritage might be, though some have hinted at elven blood "+
      "somewhere in his lineage.  Whatever his heritage, I-chou "+
      "conducts business in a gentle manner, never hurrying, that "+
      "suggests he has found an inner peace that often eludes most "+
      "magi seeking power.  He is dressed in a simple brown robe made "+
      "of silk that is gathered with a tan cloth belt.  His long "+
      "gray hair is tied into a topknot, keeping it out of the way and "+
      "giving him a neat appearance.\n"+
      "<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(5);
   set_race("human");
   set_hd(19,1);
   set_body_type("human");
   set_property("no bump", 1);
   set_components(100);
   set_class("mage");
   set_mlevel("mage",19);
   set_guild_level("mage",19);
   set_spell_chance(90);
   set_spells(({"fireball","lightning bolt","acid arrow",
        "powerword stun", "web", "magic missile"}));
}
