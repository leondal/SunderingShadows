#include <std.h>
#include "../elf.h"
#include <daemons.h>
inherit MONSTER;

#define VQCN vic->query_cap_name()


create() {
   ::create();
   set_name("dusk maiden");
   set_id( ({"maiden","dusk maiden","woman","monster"}) );
   set("short","%^RESET%^%^MAGENTA%^Woman in t%^CYAN%^a%^MAGENTA%^ttered r%^CYAN%^o%^MAGENTA%^bes%^RESET%^");
    set("long","%^MAGENTA%^This woman look strangely royal.  "+
	"She is wearing dark purple robes trimmed in "+
	"%^BOLD%^%^BLACK%^black%^RESET%^%^MAGENTA%^.  Her body seems limp as she floats around."+
	"  Her feet don't touch the ground rather.  "+
	"There is a giant %^BOLD%^%^BLACK%^portal of darkness%^RESET%^%^MAGENTA%^ that "+
	"swirls below her holding her aloft.  Her "+
	"head bobbles back and forth, almost like her neck is broken.");
   set_gender("female");
   set_race("half-elf");
   set_attacks_num(2);
   set_damage(3,8);
   set_hd(35,10);
   set_hp(750+random(300));
   set_max_hp( query_hp() );
   set_class("cleric");
   set_mlevel("cleric",40);
   set_guild_level("cleric",40);
   set_alignment(8);
   set_funcs( ({"touch"}) );
   set_func_chance(20);
   set_spells(({
           "dispel magic"
   }));
   set_spell_chance(10);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("spell resistance",20);
   set_property("no death",1);
   set_property("magic",1);
   set_overall_ac(-10);
   set_moving(1);
   set_speed(60);
   set_emotes(3,({
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^ Have you seen my brother?",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^ So many flowers... it's alright if I pick some, isn't it?",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^ You are not the bird I'm looking for either... oh well.",

      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^  Please don't leave me here, not all alone.",

      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^ If I were to be left all alone, I would surely perish.",

	  "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^  My family, I've been looking for them for what seems like an eternity.",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^  I have a new friend... everyone we must be nice to one another.",
      "%^MAGENTA%^Dusk Maiden says:%^CYAN%^  I can't see anything...",
     }),0);
	    set_emotes(3,({

	  "%^MAGENTA%^Dusk Maiden shouts:%^CYAN%^  Let me hear you scream!",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^  You wish to hear the devil sing?",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^  It was you!  My brother... where did you take him?",

      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^ Kill me.",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^ If I were to be left all alone, I would surely perish.",
      "%^MAGENTA%^Dusk Maiden whispers:%^CYAN%^  Everyone is dying... oh well.",

      "%^MAGENTA%^Dusk Maiden says:%^CYAN%^  I can't see anything...",
     }),1);

	 new(OBJ"duskrobe")->move(TO);
	 if(!random(2))new(OBJ"veil")->move(TO);
	 else 	 new(OBJ"tiara")->move(TO);
	 new(OBJ"sash")->move(TO);
	 new(OBJ"sandals")->move(TO);
	 new(OBJ"locket")->move(TO);

    command("wearall");
    command("message floats in.");
    command("message out floats $D, darkness trails behind her.");
    set_new_exp(31,"very high");
    set_max_level(35);
    set_base_damage_type("cold");
    set_resistance_percent("cold",50);
    set_resistance_percent("fire",-50);
    set_skill("perception",35); 

}
int touch(object vic) {
   tell_object(vic,"%^MAGENTA%^Dusk Maiden waves her hand,"+
   " and a giant claw of darkness erupts from the ground, tearing into you.");
   tell_room(ETO,"%^MAGENTA%^Dusk Maiden weakly waves her hand at "
   +VQCN+", and a giant claw of tears into "+vic->QO+".",vic);
   vic->cause_typed_damage(vic,0,roll_dice(6,10),"cold");
   return 1;
}

void heart_beat(){
  object claw;
  ::heart_beat();
  if(!objectp(TO))return;
  if(!objectp(query_current_attacker())) { return ; }
  if(query_attackers()==({ })) return;
  if(!present("claw 2", ETO)){
   tell_room(ETO,"%^BOLD%^%^BLACK%^Dusk maiden waves an arm and a claw of darkness erupts from the ground.");
    claw = new(MON"claw");
	claw->move(ETO);
	TO->add_protector(claw);
	TO->add_follower(claw);
	}
  return;
}
void die(object ob) {
    object myob;
   	object *inven;
	int lit, j,i;
	lit = 0;
	if(!objectp(ETO)) return;
	inven=filter_array(all_living(ETO),"is_non_immortal",FILTERS_D);
    j=sizeof(inven);
  for(i=0;i<j;i++) {
     if(inven[i]->query_light() > 3) lit = 1;
    }

   if(ETO->query_light() < 3 && lit == 0){
   tell_room(ETO,"%^RED%^Dusk maiden melts into a pool of darkness."+
   "  Shadows from the area fill the pool.");
   new(OBJ"pool")->move(ETO);
   TO->move("/d/shadowgate/void");
    remove();
	}
   else ::die();
}
