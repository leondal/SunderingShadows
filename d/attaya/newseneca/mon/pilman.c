//Pilman Shabiddle, one of the gnomish tatttoo artists
//for new Seneca ~Circe~ 12/17/07
#include <std.h>
#include "../seneca.h"

inherit NPC;

void create(){
   ::create();
   set_name("Pilman");
   set_short("Pilman Shabiddle, gnomish tattoo artist");
   set_id(({"pilman","Pilman","pilman shabiddle","Pilman Shabiddle","tattoo artist","shopkeeper"}));
   set_long("Wearing an open %^BOLD%^%^BLACK%^black "+
      "leather vest %^RESET%^%^CYAN%^atop his bare "+
      "chest, this little gnome would look quite "+
      "dangerous if it wasn't for his short stature.  "+
      "His rounded ears are lined with %^RESET%^piercings "+
      "%^CYAN%^while his head has been shaved bald and "+
      "covered in a huge tattoo of %^BOLD%^%^RED%^fl"+
      "%^YELLOW%^a%^RED%^mes %^RESET%^%^CYAN%^burning out "+
      "of control.  His %^BOLD%^%^BLACK%^leather pants "+
      "%^RESET%^%^CYAN%^fit snuggly and match both his "+
      "vest and the %^RESET%^steel-toed %^BOLD%^%^BLACK%^"+
      "boots %^RESET%^%^CYAN%^that make clicking noises "+
      "as he walks.  He has the word '%^BOLD%^%^RED%^"+
      "ekibi%^RESET%^%^CYAN%^' tattooed "+
      "in %^BOLD%^%^RED%^red %^RESET%^%^CYAN%^along the "+
      "knuckles of his left hand."
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
