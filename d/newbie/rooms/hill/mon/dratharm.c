// /d/newbie/rooms/hill/mon/dratharm.c Dwarven trader for tents
// changed to Charellin, halfling trader - dwarves are no longer a small race. Nienne, 04/08.
#include <std.h>
#include "../../../newbie.h"

inherit VENDOR;

create() {
	::create();
        set_items_allowed("armor");
	set_nwp("armorsmithing", 4);
    	set_name("Dratharm");
        set_id(({"charellin", "Charellin", "halfling", "trader"}));
        set_race("halfling");
        set_gender("male");
        set("short", "Charellin, a halfling trader");
        set("long","Charellin is a short and rather stocky halfling with "
           "stubby fingers and a thick beard that makes his face look "
           "even rounder than it already is.  His skin is a rugged-looking "
           "natural deep brown and he has long, dark brown hair.  He's a "
	   "trader, so of course he has a <list> of what he has for sale.");
      set_level(6);
      set_class("fighter");
      set_body_type("human");
      set_hd(6,3);
      set_alignment(1);
      set_size(1);
      set_overall_ac(8);
      set_stats("intelligence",12);
      set_stats("wisdom",12);
      set_stats("strength",18);
      set_stats("charisma",10);
      set_stats("dexterity",10);
      set_stats("constitution",17);
      set_hp(random(15)+50);
      set_property("swarm",1);
      set_wielding_limbs( ({ "right hand", "left hand" }) );
      new(CWEAP"shortsword")->move(TO);
        command("wield sword");
      new(ARMOR"sleather")->move(TO);
        command("wear leather");
      set_exp(50);
      add_money("gold",random(20)+10);
      add_money("silver",random(20)+50);
      add_money("copper",random(500));
      set_storage_room(ROOMS"special/dwarftrader_storage");
}

void init(){
    ::init();
    if(base_name(ETO) != "/d/newbie/hill/tent1")
	 force_me("tent");
}
