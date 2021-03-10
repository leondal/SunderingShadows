//tarolina.c - Souvenir shop owner for new Seneca.  Circe 10/23/07
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create(){
   ::create();
   set_name("Tarolina");
   set_short("Tarolina, Proprietor of Driftwood");
   set_id(({"tarolina","Tarolina","proprietor","shopkeeper"}));
   set_long("%^RESET%^%^CYAN%^Tarolina is a relatively young gnome "+
      "with an %^MAGENTA%^impish grin %^CYAN%^who has learned to "+
      "make a living by selling the things she loves - the vast "+
      "%^YELLOW%^treasures %^RESET%^%^CYAN%^of the %^BOLD%^sea"+
      "%^RESET%^%^CYAN%^.  She has sun-kissed woody brown skin "+
      "with animated %^BOLD%^%^BLUE%^sapphire eyes%^RESET%^"+
      "%^CYAN%^.  Her %^YELLOW%^pale blond hair%^RESET%^%^CYAN%^ "+
      "is pulled back into a short ponytail, and she wears a "+
      "brilliant %^MAGENTA%^purple kerchief %^CYAN%^to protect "+
      "her scalp from the sun.  She dresses in bright colors, "+
      "preferring loose-fitting sleeveless tops and skirts "+
      "that just graze her knees.  She will gladly help you "+
      "with any item you would like to see in the shop, but she is "+
      "quick to remind you that jewelry sales are final.%^RESET%^");
      set_items_allowed("misc");
	set_race("gnome");
	set_gender("female");
	set_hd(20,4);
	set_max_hp(150+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-12);
	set_alignment(4);
	set_class("mage");
	set_class("cleric");
	set_mlevel("mage",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
	set_spells(({
	"meteor swarm",
	"flame strike",
	"mystic bolt",
	"limb attack",
	"monster summoning vii",
	"chain lightning"
	}));
	set_spell_chance(100);
	set_exp(100);
	set("aggressive",0);
	add_money("gold",random(50));
	set_storage_room(STORAGE"driftwood.c");
	force_me("speech speaks rapidly with a smile");
}
/* For some reason this is giving an error - will sort out later. Circe 10/23/07
void reset(){
   ::reset();
   if(query_night()){
      tell_room(ETO,"%^BOLD%^%^GREEN%^Tarolina packs up her things and heads home.");
      TO->move("/d/shadowgate/void");
      destruct(TO);
   }
}
*/
