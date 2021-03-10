// rogue stuck in cave in
// has key for door in room 44
#include <std.h>
inherit "/std/monster";

create() {
  object metal;
  int x;
  ::create();
  set_name("rogue");
  set_id(({"dwarf","rogue dwarf","rogue"}));
  set_gender("male");
  set_race("dwarf");
  set_short("dirty sneaky dwarf");
  set_long("This stout dwarf looks terrible. "+
   " He has been stuck down here for a while. "+
   "  His beard is stained and he is covered in mud."+
   "  He wears a simple mining cap.  He is stuck"+
   " under a rock perhaps you could _pull rock_ "+
   "to free him.");
  set_body_type("human");
  set_alignment(2);
  set_hd(6,2);
  set_stats("strength",16);
  set("aggressive",0);
  set_stats("intelligence", 6);
  set_stats("wisdom", 10);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_size(2);
  set_property("swarm",0);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(10);
  set_hp(random(50));
  set_max_level(5);
  for(x=0;x<7;x++)
    new("/d/common/obj/misc/gem")->move(TO);
  metal = new("/std/obj/metal.c");
  metal->set_metal_quality(random(6)+5);
  metal->move(TO);
  key();
  force_me("pose stuck under a rock");
}

void poof(){
  if(!TP) return;
  force_me("emote lets out a sigh of relief.");
  force_me("say Thank gods, been stuck down here,"+
    " seems like fer-ever.  Take the loot,"+
	" I'm done with dis place.");  
  force_me("emote heads out with a grunt.");
  force_me("drop all");
  force_me("west");
  TO->move("/d/shadowgate/void");
  
}
void key(){
    object ob;
    ob = new ("/std/Object");
    ob->set_name("iron key");
    ob->set_short("A small iron key");
    ob->set_id(({"key","iron key"}));
    ob->set_long("This is a small iron key. "+
	"It has an simple head. It's obviously meant"+
	" for a simple lock.");
    ob->set_weight(1);
    ob->move(TO); 
    return ;
}
 
