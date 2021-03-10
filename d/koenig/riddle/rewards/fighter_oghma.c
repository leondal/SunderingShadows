//fighter_oghma.c - Reward for the Riddle Quest.  Circe 4/13/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/longsword";

int OWNED;
string owner;

void create(){
	::create();
	set_name("singing sword");
	set_id(({ "sword", "singing sword" }));
	set_short("%^BOLD%^%^WHITE%^Singing %^BLUE%^S%^RESET%^%^MAGENTA%^w%^BOLD%^%^CYAN%^o%^BLUE%^r%^RESET%^%^MAGENTA%^d%^RESET%^");
	set_obvious_short("An ornate slender sword");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This slender sword is about as long as your typical long sword, but looks far more slender.  A slim blade made of a metal you cannot identify rises from the ornate pommel and hilt.  While it carries the same luster as silver, it seems as strong as steel.  Engraved into the metal are a set of ancient %^RESET%^%^MAGENTA%^runes%^BOLD%^%^WHITE%^ whose meaning is unclear.  The pommel and hilt of the blade has been carved from gold to look like a human male.  The short-haired man has been carved in great detail, you can make out his fine clothing, each hair on his head.  His eyes are shut and his mouth pressed closed.  His hands are cupped together at his chest causing his arms to form the crossguard of this blade.  The male figure stands on an orb made of %^BLUE%^sapphire%^RESET%^.

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
The Singing Sword is a sacred blade used by the followers of Oghma.  The Singing Sword blends together the various aspects of his church.  The blade itself and it's construction gives credit to Oghma's role as God of the Craft, and the craftsmen and builders who pray to him.  The runes on the blade stand for Oghma's role as the Binder and the Lord of All Knowledge.  While the male figure seems to be connected to Oghma's role as Patron of Bards.

AVATAR
	);
   set_property("lore difficulty",12);
      if(TO->query_property("enchantment")< 2){
         remove_property("enchantment");
         set_property("enchantment",2);
      }
  	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The sword refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the sword.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" wraps "+ETO->QP+" hand about the slender sword, and a beautiful soft clear melody issues forth from it!",ETO);
	tell_object(ETO,"%^MAGENTA%^As your hand slips about the curious hilt of the blade, the figurine's eyes open and he begins to sing a soft clear melody.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" unwraps "+ETO->QP+" hand from the sword.  That wonderful melody that you were hearing fades and comes to an end.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You unwrap your hand from the sword, the figurine's eyes close as does his mouth, ending the wonderful melody.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^A rapid tune fills the air and seems to inspire and rally "+ETOQCN+" in "+ETO->QP+" attack!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The sword beings to sing a rapid tune that fills you with inspiration and rallys your attack!");
	tell_object(targ,"%^BOLD%^%^BLUE%^A rapid tune fills the air and seems to inspire and rally "+ETOQCN+" in "+ETO->QP+" attack on you!");
		return roll_dice(3,4)+-1;	}
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}
