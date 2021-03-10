#include <std.h>

inherit "/std/identifier";

void create(){
   ::create();
   set_name("alizaire");
   set_id(({"alizaire","Alizaire","wandering","wizard","mage","wandering wizard"}));
   set_short("Alizaire, a wandering wizard");
   set_long("Alizaire is a young wizard with a well-kept black "+
      "goatee.  His hair is worn long, flowing out of the back of "+
      "his pointed wizard's hat.  He carries a thick book warded "+
      "and covered with runes, while a leather satchel is thrown "+
      "over his shoulder.  His robes are simple but well-tended, "+
      "made of deep blue cotton that matches some of the runes on "+
      "his silvery book.  His hands sport quite a few burns and "+
      "scars upon his cheeks hint at mishaps in the lab.");
   set_race("human");
   set_stats("intelligence",18);
   set_stats("strength",12);
   set_stats("charisma",15);
   set_stats("wisdom",14);
   set_stats("dexterity",11);
   set_stats("constitution",13);
   set_hp(200+random(76));
   set_max_hp(query_hp());
   set_class("mage");
   set_mlevel("mage",15);
   set_guild_level("mage",15);
   set_spells(({"lightning bolt","burning hands","scorcher","magic missile","powerword stun"}));
   set_spell_chance(60);
   set_id_uses(3);
   set_detect_uses(4);
   set_speed(60);
   set_highmod(4);
}
