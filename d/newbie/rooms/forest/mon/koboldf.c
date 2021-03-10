// koboldf.c - Kobold for the newbietown forest

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"
inherit "/std/monster";

create() {
    ::create();
       set_name("kobold");
       set_id( ({ "kobold" }) );
       set_race("kobold");
       set_gender("male");
       set_short("red-eyed, smelly kobold");
       set_long(
@STYX
This ugly little creature has beady red eyes and two small horns that protrude from the top of its head.  Almost lizardlike in appearance with large pointy ears, it has dark rusty-brown scaly hide and a long hairless tail but stands upright on two legs.  Long skinny fingers end in sharp-looking and pointy fingernails that look more like animal claws.  It smells like something between a wet dog and stagnant water.  It carries a spear pointed your direction and pokes it toward you threateningly.
STYX
   );
      set_body_type("human");
      set("aggressive",10);
      set_alignment(6);
      set_size(1);
      set_hd(2,2);
      set_hp(20);
      set_overall_ac(8);
      set_stats("intelligence",6);
      set_stats("wisdom",6);
      set_stats("strength",15);
      set_stats("charisma",5);
      set_stats("dexterity",16);
      set_stats("constitution",14);
      set_max_hp(query_hp());
      set_wielding_limbs( ({ "right hand", "left hand" }) );
      new(CWEAP"mspear")->move(TO);
        command("wield spear");
      if(random(8) == 0) {
       	new(STUFF"kobvest")->move(TO);
       	command("wear vest");
      }
     if(random(5) == 0) {
       	new(CMISC"fishing_rod")->move(TO);
       	new(CMISC"fish")->move(TO);
     }
     if(random(5) < 2) {
       	new(CMISC"sack")->move(TO);
       	new(CMISC"climb_tool")->move(TO);
       	command("put tools in sack");
     }
     if(random(5) == 0) {
       	new(CMISC"fishing_pole")->move(TO);
     }
      set_wimpy(10);
      add_money("gold",random(80));
      add_money("silver",random(80));
      add_money("copper",random(20));
      set_exp(60);
      set_property("swarm",1);
      set_achats(5, ({"%^RED%^The kobold darts back and forth.%^RESET%^", "%^RED%^The kobold's tail twitches as he dodges for position.%^RESET%^"}) );
      set_emotes(2, ({"The kobold tries to sharpen his spear on a rock.", 
	"The kobold's tail twitches as he points his spear at you.", 
	"The kobold's beady red eyes seem to be sizing you up.", 
	"The kobold darts past and tries to steal something."}), );
}
