//crab.c - nuisance monster for Leilani ~Circe~ 5/27/07
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("crab");
   set_id(({"crab","small crab","scuttling crab"}));
   set_race("crab");
   if(!random(2)){
      set_gender("male");
   }else{
      set_gender("female");
   }
   set_short("A small, scuttling crab");
   set_long(
      "This small crab scuttles along the shore.  Its body is "
      "snowy white, making it difficult to see against the sandy "
      "beach.  Despite its tiny size, it has two large pincers "
      "on its front legs, giving it at least some manner of "
      "defense."
   );
   set_level(1+random(2));
   set_body_type("reptile");
   set("aggressive",6);
   set_alignment(5);
   set_size(1);
   set_hd(2,4);
   set_exp(15);
   set_max_hp(5+random(10));
   set_hp(query_max_hp());
   set_max_level(3);
   set_emotes(5,({
      "The scuttling crab flexes its pincers.",
      "The small crab scuttles into a nearby hole.",
      "The crab darts sideways across the sand."
   }),0);
   set_achats(3, ({
      "The crab brandishes its pincers menacingly.",
      "The crab's pincers scratch your flesh!"
   }) );
}

void die(mixed ob){
   if(present("seagull")){
      tell_room(ETO,"%^BOLD%^%^RED%^The seagull makes a quick meal of the crab!%^RESET%^");
      TO->remove();
   }else{
      ::die(ob);
   }
}