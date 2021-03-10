//Saide changed powder to query_name rather than query_cap_name so the powder would actually hit.  Nov 2003
#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

object equipment;
void stab_em(object targ);

void create(){
   ::create();
   set_name("Cedwin");
   set_id(({"cedwin","thief","drunk","halfling"}));
   set_short("Cedwin, the Drunk");
   set_long("Cedwin is a halfling, and at the moment he looks quite drunk.  He looks in total disarray.  His "
"hair is messy, his hands are filthy and he has lots of unidentifiable stains on his clothes.  He holds a "
"mug of ale close in one hand and babbles to himself, waving his dagger about with his other hand.");
   set_race("halfling");
   set_gender("male");
   set_body_type("human");
   set_alignment(6);
   set_hd(30,5);
   set_hp(280);
   set_max_hp(280);
   set_size(1);
   set_wielding_limbs( ({ "right hand", "left hand" }) );
   set_stats("strength",14);
   set_stats("intelligence",15);
   set_stats("wisdom",8);
   set_stats("dexterity",19);
   set_stats("constitution",18);
   set_stats("charisma",10);
   set_mob_magic_resistance("average");
   set("aggressive","agg_func");
   set_class("thief");
   set_mlevel("thief",22);
   set_class("fighter");
   set_mlevel("fighter",20);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",100);
   set_thief_skill("hide in shadows",100);
   set_thief_skill("pick pockets",100);
   toggle_steal();
   set_scrambling(1);
   set_overall_ac(1);
   set_speed(60);
   set_exp(8000);
   remove_property("swarm");
   set_emotes(5, ({"Cedwin yawns.","Cedwin burps loudly.","Cedwin looks ill but thankfully just belches.","%^MAGENTA%^Cedwin says%^RESET%^: Thorby's a punk","%^MAGENTA%^Cedwin says%^RESET%^: Where's my dagger?","%^MAGENTA%^Cedwin says%^RESET%^: That's a nice purse ya got there.","%^MAGENTA%^Cedwin says%^RESET%^: Damnit! Where's my purse?","Cedwin admires your purse.","Cedwin glances at your equipment and whistles.","Cedwin gets an excited look on his face.\nCedwin searches his pouches frantically.\n\n%^MAGENTA%^Cedwin says%^RESET%^: Where's that damn gem?\n\nCedwin's eyes light up.\n%^MAGENTA%^Cedwin says%^RESET%^: Hmm, must have lost it when I was scoping that ship out.\nCedwin pouts and goes to get another drink."}),0);
   set_funcs(({"special"}));
   set_func_chance(30);
   equipment = new("/d/common/obj/armour/leather");
     equipment->set_property("enchantment",2);
     equipment->set_size(1);
     equipment->move(TO);
     command("wear leather");
   equipment = new(OBJ"woolcloak");
     if(random(2)) equipment->set_property("monsterweapon",1);
     equipment->set_size(1);
     equipment->move(TO);
     command("wear cloak");
   new(OBJ"darkring")->move(TO);
     command("wear ring");
   equipment = new("/d/shadow/virtual/mon/hdagger");
     if(random(3)) equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wield dagger");
   equipment = new(OBJ"longdagger");
     equipment->set_property("monsterweapon",1);
     equipment->set_property("enchantment",2);
     equipment->move(TO);
     command("wield dagger");
   equipment=new("/d/tharis/obj/wrist_sheath");
     equipment->set_property("no animate",1);
     equipment->move(TO);
     command("wear sheaths");
   equipment=new(OBJ"venomdagger");
     equipment->move(TO);
     command("press button");
     command("put venom in sheath");
   equipment=new("/d/tharis/obj/bpowder");
     equipment->set_property("monsterweapon",1);
     equipment->move(TO);
   add_money("gold", random(300)+300);
}

int agg_func(){
   if(sizeof(TO->query_attackers()) > 0) command("say So there be more of ye yet!");
   else command("say Ye've come ta get me gold haven't ye?!");
   stab_em(TP);
}

void stab_em(object targ){
   if (!objectp(targ)) return;
   command("stab "+targ->query_name());
   command("say Take that ya scum!");
   command("kill "+targ->query_name());
   if(random(2)) command("toss powder at "+targ->query_name());
}

void special(object targ){
   if((int)targ->query_stats("dexterity")<(roll_dice(1,25))){
     tell_object(targ,"In the midst of combat Cedwin gets under your foot and trips you!");
     tell_room(environment(targ),"Cedwin trips "+targ->QCN+"!",targ);
     targ->set_paralyzed(random(3)+2,"You are trying to get to your feet!");
   }
   else{
     tell_object(targ,"Cedwin tries to trip you, but you keep your footing!");
     tell_room(environment(targ),"Cedwin tries to trip "+targ->QCN+" but fails!",targ);
   }
}
