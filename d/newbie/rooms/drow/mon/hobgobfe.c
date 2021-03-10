// /d/newbie/rooms/ruins/mon/hobgobf.c Hobgoblin female for Newbietown

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"

inherit "std/monster";

void create() {
   ::create();
   set_name("hobgoblin");
   set_id(({"hobgoblin","shaman","hobgoblin shaman","hobmonster"}));
   set_race("hobgoblin");
   set_body_type("human");
   set_gender("female");
   set_short("Hobgoblin shaman");
   set_long("This female hobgoblin is every bit as barbaric looking as the males."
	"  Her %^BOLD%^%^BLACK%^hide is a dark grey %^RESET%^%^CYAN%^and nearly "
	"as hairy as the males.  She has %^YELLOW%^yellowish eyes and teeth "
	"%^RESET%^%^CYAN%^made for tearing meat while large, pointed ears stick "
	"out from the side of her ape-like face.  She carries some sort of crude "
	"talisman that you guess may be a holy symbol.");
   set_level(5);
   set_class("cleric");
   set_guild_level("cleric", 4);
   set_mlevel("cleric", 4);
   add_search_path("/cmds/priest");
   set("aggressive", 14);
   set_hd(5,3);
   set_hp(random(10)+35);
   set_max_hp(query_hp());
   set_alignment(3);
   set_size(2);
   set_overall_ac(7);
      set_stats("intelligence",8);
      set_stats("wisdom",17);
      set_stats("strength",15);
      set_stats("charisma",5);
      set_stats("dexterity",10);
      set_stats("constitution",17);
      set_property("swarm",1);
      set_spells( ({ "call lightning", "limb attack", "hold person", "cause light wounds", "cause light wounds", "limb attack" }) );
      set_spell_chance(50);
      set_exp(140);
      new(CMISC"pouch")->move(TO);
        command("wear pouch");
      new(CWEAP"morningstar")->move(TO);
      	force_me("wield morningstar");
      new(CARMOR"buckler")->move(TO);
       	command("wear buckler");
       if(random(5) < 3) {
	 new("/d/newbie/obj/misc/gem")->move(TO);
	  command("put gem in pouch");
 	 new("/d/newbie/obj/misc/gem")->move(TO);
	  command("put gem in pouch");
	}
        add_money("gold",random(100)+90);
        add_money("silver",random(200)+70);
        add_money("copper",random(500));
        set_emotes(2, ({
	   "The female hobgoblin sneers at you.", 
	   "%^ORANGE%^The female hobgoblin holds her morningstar ready to attack.", 
	   "The female hobgoblin looks you over and mutters what might be prayers."
 	}), 0);
	set_achats(2, ({
	   "%^BOLD%^%^RED%^The female hobgoblin swings the morningstar savagely at your head!!", 
	   "%^BOLD%^%^RED%^The female hobgoblin takes a vicious swing at your knees!"
	}) );
    set_new_exp(1, "very low");
}
