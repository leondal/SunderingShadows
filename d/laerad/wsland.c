#include <std.h>

inherit ROOM;

int do_mobs;

void create() {
// Had to put this here so it would be set for the lower level rooms when the reset is called the first time.  Otherwise they got no mobs until the next reset.
    if(!random(4))  do_mobs = 1;
    ::create();
    set_name("Wasteland");
    set_short("%^ORANGE%^Wasteland%^RESET%^");
    set_terrain(SCRUB_LANDS);
    set_travel(FOOT_PATH);
    set_climate("desert");
    set_long("%^ORANGE%^You are on a barren plain.  The earth appears cracked "
	"and dead with no vegetation other than an occasional unusually large "
	"cactus.  A wicked wind bites at your face, blowing sand into your eyes. "
	"Here and there, a %^YELLOW%^sulfurous mist %^RESET%^%^ORANGE%^spews "
	"from a new fissure in the ground.  The lifeless wasteland continues "
	"for what seems like leagues in all directions.\n");
    set_smell("default","You are nearly overwhelmed by a smell that reminds you of rotten eggs.");
    set_listen("default","You hear little over the howling of the wind in your ears.");
    set_property("indoors",0);
    set_property("light",2);
    if(random(4))
	set_property("no sticks", 1);
}

/* altered this to throw in the torm outpost
string ldesc(string str) {
   return("%^ORANGE%^A sandy wasteland\n "
    "You are on a barren plain.  The earth appears cracked "
	"and dead with no vegetation other than an occasional unusually large "
	"cactus.  A wicked wind bites at your face, blowing sand into your eyes."
	"  Here and there a %^YELLOW%^sulfurous mist %^RESET%^%^ORANGE%^spews "
	"from a new fissure in the ground.  The lifeless wasteland continues "
	"for what seems like leagues in all directions.\n "
   );
}
*/
void init() {
   ::init();
   if(!random(10) && userp(TP)) {
     if(TP->query_true_invis())  return;
     if(random(10)) {
        tell_object(TP, "%^ORANGE%^A crack opens in the ground below you!\n"
	  "%^YELLOW%^An acidic, sulfurous jet of steam spews up and burns you!");
        tell_room(TO, "%^YELLOW%^An acidic, sulfurous jet of steam spews up and burns "+TPQCN+"!", TP);
        TP->do_damage(TP->return_target_limb(),roll_dice(7,6));     
        TP->add_attacker(TO);
        TP->continue_attack();
        if(objectp(TP))    TP->remove_attacker(TO);
        return;
     }
     tell_room(TO, "%^ORANGE%^A crack opens in the ground and an acidic, sulfurous jet of steam spews up!\n");
   }
}   

// if(member_array("laeradmon", victims[i]->query_id()) != -1) continue;
// oh, hmm, actually don't need this since we don't do anything if one is present
// might need it for the init ones though


void reset() {
   int i;
   object *victims;
   ::reset();
/*   switch(random(10)) {
	case 0:  do_mobs = 1;	break;
	default: do_mobs = 0;	break;
   }
*/
   if(!objectp(TO)) { return; }
   if(do_mobs && !present("laeradmon")) {
      switch(random(15)) {
	case 0:   new("/d/laerad/mon/mara")->move(TO);	
	case 1:   new("/d/laerad/mon/leucrotta")->move(TO);	break;
	case 2:   new("/d/laerad/mon/cactus")->move(TO);	
	case 3:   new("/d/laerad/mon/wrhino")->move(TO);	break;
	case 4:   new("/d/laerad/mon/gboar")->move(TO);
	case 5:   new("/d/laerad/mon/cockatrice")->move(TO);	break;
	case 6:   new("/d/laerad/mon/hyena")->move(TO);	
	case 7:   new("/d/laerad/mon/manticore")->move(TO);	break;
	case 8:   new("/d/laerad/mon/scarecrow")->move(TO);
	case 9:   new("/d/laerad/mon/thri_kreen")->move(TO);	break;
	default: break;
      }
   }
   if(random(10))  return;
   if(!present("player", TO))  return;
   if(present("laeradmon", TO)) return;

   victims = all_living(TO);
   i = sizeof(victims);

   tell_room(TO, "%^ORANGE%^A crack opens in the ground!\n"
	  "%^YELLOW%^An acidic, sulfurous jet of steam spews up and burns you!");
   while( i > 0) {
      i--;
      if(!objectp(victims[i]))
           continue;
      if(victims[i]->query_true_invis()) 
	   continue;
      victims[i]->do_damage(victims[i]->return_target_limb(),roll_dice(6,6));     
      tell_room(TO, "%^YELLOW%^An acidic, sulfurous jet of steam spews up and burns "+victims[i]->QCN+"!", victims[i]);
      victims[i]->add_attacker(TO);
      victims[i]->continue_attack();
      if(objectp(victims[i]))    victims[i]->remove_attacker(TO);
   }
}

