#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

#define COLORS ({"%^ORANGE%^bronze%^BOLD%^%^RED%^","%^YELLOW%^brass%^RED%^","%^BOLD%^%^WHITE%^silver%^RED%^"})

string COLOR;

void create() {
   int i;
    	::create();
      i = random(sizeof(COLORS));
      COLOR = COLORS[i];
    	set_name("mechanical squirrel");
    	set_id(({"squirrel","mech squirrel","mechanical squirrel","rodent","farm_mon"}));
      set_short("a "+COLOR+" squirrel");
      set_long("This small squirrel glitters in the light, "+
         "revealing the "+COLOR+" %^RESET%^%^CYAN%^that makes up its body.  "+ 
         "It looks to be made of thin, overlapping plates of "+
         ""+COLOR+" %^RESET%^%^CYAN%^to give it as much flexibility as "+
         "possible.  The normally bushy tail of a squirrel has "+
         "been replaced by "+COLOR+" %^RESET%^%^CYAN%^in the same "+
         "plates.  The creature's maker paid attention to every "+
         "detail, right down to giving the critter a %^BOLD%^"+
         "%^MAGENTA%^rose quartz nose%^RESET%^%^CYAN%^ and a light "+
         "%^BOLD%^tin belly%^RESET%^%^CYAN%^.  Its eyes are a little "+
         "disturbing, being fashioned from tiny chips of "+
         "%^BOLD%^%^RED%^ruby %^RESET%^%^CYAN%^that seems lit from "+
         "inside somehow.  The otherwise cute little "+
         "squirrel moves fluidly, just as its natural brothers do.");
      set_gender("neuter");
    	set_hd(10,2);
      set_size(1);
    	set_class("thief");
    	set_mlevel("thief",10);
      set_race("squirrel");
      set_body_type("quadruped");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",15);  //yes, it's one strong bird :P
    	set_stats("charisma",3);
    	set_stats("dexterity",18);  //ninja chicken!
    	set_stats("constitution",13);
	set("aggressive",8);
    	set_alignment(5);
    	set_overall_ac(0);
    	set_exp(560);
    	set_max_hp((random(10)+55));
    	set_hp(query_max_hp());
    	set_achats(6,({
         "%^YELLOW%^The squirrel's %^RED%^eyes %^YELLOW%^flash as it charges!",
         "%^ORANGE%^The squirrel chitters angrily as its tail twitches!",
         "%^RED%^The squirrel leaps straight at you!"
    	}));
    	set_emotes(3,({
         "Light flashes across the squirrel's tail as it twitches.",
         "The squirrel pauses, standing on its hind legs as it looks around.",
         "The metallic squirrel rubs its front paws along its %^BOLD%^%^MAGENTA%^rose-quartz nose%^RESET%^."
    	}),0);
      set_attack_limbs(({"right forepaw","left forepaw"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(13);
      set_funcs(({"whirlwind"}));
      set_func_chance(8);
      set_property("swarm",1);
      set_scrambling(1);
      add_money("gold",random(16)+35);
}

int whirlwind(object *baddies){
   int i;
   baddies = TO->query_attackers();
   if(!baddies) return 0;
   if(!objectp(TO)) return 0;
   tell_room(ETO,"%^YELLOW%^The squirrel emits a high squeaking "+
      "sound and flies into a flurry of attacks at everything "+
      "close!");
   for(i=0;i<sizeof(baddies);i++){
      if(!objectp(baddies[i])) continue;
      if(!objectp(TO)) continue;
      tell_object(baddies[i],"%^BOLD%^%^RED%^The squirrel's "+COLOR+" "+
         "claws tear at your flesh!");
      baddies[i]->do_damage(baddies[i]->return_target_limb(),roll_dice(4,6));
   }
   return 1;
}

void die(object obj){
   tell_room(ETO,"The "+COLOR+" %^RESET%^squirrel twitches, squeaks, "+
      "and falls to the ground.");
   ::die(obj);
}