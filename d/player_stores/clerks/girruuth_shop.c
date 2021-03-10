#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>

#define GHOUSE "/d/player_houses/girruuth/"
#define MAX_ITEMS 10

inherit "/std/vendor_pstore";

create() {
  ::create();
  make_me();
   set_hd(28,2);
   set("aggressive", 0);
   set_level(29);
   set_gender("male");
   set_class("mage");
   set_mlevel("mage", 35);
   set_guild_level("mage",35);
   set_alignment(5);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
/*   set_emotes(1,({
     "%^MAGENTA%^Buemor says: %^RESET%^Come look at my armor, best in the lands!",
     "%^MAGENTA%^Buemor says: %^RESET%^Money back guarantee on this plate if you die with it on.",
     "Buemor polishes a helmet and grins to a passerby.",
     "%^MAGENTA%^Buemor says: %^RESET%^Some thief mugged me and took me diamond "
        "hammer.  Guess I'll send off and have another made again.",
   }));
*/
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",18);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_shop(GHOUSE+"shop");
}

void heart_beat() {
    object *killers;
    int i;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(query_hp() < 80) {
       command("say You'll pay for this one of these days!!");
       tell_room(ETO, TOQCN+" reaches in his robe and tosses a bag of dust to the floor.\n");
       tell_room(ETO, "%^BOLD%^There is a blinding flash and %^RED%^ear-splitting pop.\n");
       killers = query_attackers();
       for(i=0;i<sizeof(killers);i++) {
          killers[i]->cause_typed_damage(killers[i], "head", roll_dice(3, 5), "untyped");
       }
    tell_room(ETO, "%^ORANGE%^When you regain your senses, you find the clerk is gone.");
    TO->move("/d/Shadowgate/void");
    TO->remove();
    }
}

void make_me() {
   switch(random(2)) {
      case 0:
	set_name("Thrasamund");
	set_id(({ "shop clerk","shopkeeper","clerk", "thrasamund", "Thrasamund"}));
	set_short("Thrasamund, the shop clerk");
	set_long("Thrasamund is a tall lanky human male.  He stands roughly just "
	  "over 6' tall and weighs only about 125 lbs.  His %^YELLOW%^blonde hair "
	  "%^RESET%^%^CYAN%^is parted down the middle and falls to either side of "
	  "his head.  He has %^BOLD%^%^CYAN%^light blue eyes %^RESET%^%^CYAN%^and "
	  "his facial structure is quite angular, coming to a point at his chin.  "
	  "He show signs of aging under his eyes and appears middle aged.  He "
	  "speaks with a heavy accent that sounds like someone from the far west "
 	  "of the realms.  He speaks plainly and often pauses between sentences.  "
	  "He wears the robes of a magi and you can see the outline of a book "
	  "under his robes."
	);
	break;
     case 1:
	set_name("Charlimurth");
	set_id(({ "shop clerk","shopkeeper","clerk", "charlimurth", "Charlimurth", "charlie"}));
        set_short("Charlimurth, the shop clerk");
	set_long("Charlimurth is a fairly average human male in both height and "
	  "build.  He has %^BOLD%^%^BLACK%^charcoal black hair and eyes %^RESET%^"
	  "%^CYAN%^ and seems to regard the world rather indifferently.  However, "
	  "His rounded face and creases around the mouth give the impression that "
	  "he is smiling even when he isn't especially.  He wears simple mage "
	  "robes and a feathered felt hat."
        );
	break;
   }
}

	
   
