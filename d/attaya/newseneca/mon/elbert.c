//Elbert Shabiddle, one of the gnomish tatttoo artists
//for new Seneca ~Circe~ 12/15/07
#include <std.h>
#include "../seneca.h"

inherit NPC;

void create(){
   ::create();
   set_name("elbert");
   set_short("Elbert Shabiddle, gnomish tattoo artist");
   set_id(({"elbert","Elbert","elbert shabiddle","Elbert Shabiddle","tattoo artist","shopkeeper"}));
   set_long("Standing at just under three feet tall, Elbert "+
      "seems the very definition of tiny.  His %^RESET%^"+
      "white hair %^CYAN%^stands straight out in all directions, "+
      "defying gravity as it lifts above the %^ORANGE%^"+
      "leather band %^CYAN%^of his %^YELLOW%^goggles"+
      "%^RESET%^%^CYAN%^.  The goggles have %^YELLOW%^"+
      "golden frames %^RESET%^%^CYAN%^and three sets "+
      "of lenses arranged in a circle around a central "+
      "point so they may be turned.  The lenses are "+
      "%^MAGENTA%^violet%^CYAN%^, %^GREEN%^green%^CYAN%^, "+
      "and %^BOLD%^%^MAGENTA%^bright pink%^RESET%^%^CYAN%^, "+
      "and their arrangement gives him the appearance of "+
      "a %^BOLD%^%^BLACK%^fly%^RESET%^%^CYAN%^.  The backs "+
      "of his arms are covered in %^BOLD%^%^BLACK%^tattoos "+
      "%^RESET%^%^CYAN%^in a wide range of designs, and a "+
      "large %^RESET%^white overcoat %^CYAN%^covers the rest "+
      "of his body."
   );
   set_race("gnome");
   set_gender("male");
   set_hd(25,4);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-12);
   set_alignment(4);
   set_class("mage");
   set_class("fighter");
   set_mlevel("mage",25);
   set_mlevel("fighter",25);
   set_level(25);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("charisma",16);
   set_stats("strength",19);
   set_stats("constitution",8);
   set_stats("dexterity",14);
   set_property("full attacks",1);
   set_spells(({
      "meteor swarm",
	"monster summoning vii",
	"chain lightning",
      "lightning bolt",
      "magic missile"
	}));
   set_spell_chance(60);
   set_exp(100);
   set("aggressive",0);
   add_money("gold",random(50));
}
