#include <std.h>
inherit "/d/common/obj/armour/leather_greaves.c";

void create(){
	::create();
	set_name("moonstone greaves");
	set_obvious_short("%^RESET%^en%^BOLD%^gr%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^ed %^BOLD%^moonstone %^BLACK%^greaves%^RESET%^");
	set_id(({ "greaves", "wolf", "wolf greaves", "moonstone greaves", "moonstone","heart of the pack" }));
	set_short("%^RESET%^%^BOLD%^H%^RESET%^e%^BOLD%^%^BLACK%^a%^WHITE%^r%^RESET%^t of the %^ORANGE%^Pa%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^k%^RESET%^");
	set_long("%^RESET%^Carved from two single pieces of %^BOLD%^mo%^CYAN%^o%^WHITE%^n%^RESET%^%^CYAN%^st%^BOLD%^%^WHITE%^one%^RESET%^, these greaves should be very heavy. However, they seem "
"as light as feathers. They have been carved with a relief of a %^BOLD%^%^BLACK%^wolf%^RESET%^ leaping, it's jaws open to %^RED%^attack%^RESET%^. The detail in the carving is so lifelike you "
"swear you can see the ears twitch and the jaw move. The eyes of the wolf are spots of pure %^BOLD%^silver%^RESET%^. The greaves attach to the legs with %^ORANGE%^fine leather straps%^RESET%^ "
"and %^BOLD%^silver buckles%^RESET%^. A sense of power emanates from the greaves.");
   set_value(0);
	set_lore("%^BOLD%^%^CYAN%^The %^RESET%^%^BOLD%^H%^RESET%^e%^BOLD%^%^BLACK%^a%^WHITE%^r%^RESET%^t of the %^ORANGE%^Pa%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^k%^BOLD%^%^CYAN%^ greaves first "
"appeared in these lands being worn by Jerlekt Softstrider, known to some as the %^BLACK%^Shadowed Wolf%^CYAN%^. He was a devoted ranger of a moon goddess and battled the minions of the moon goddess's enemies "
"whenever he could, always striking from the shadows only to slide back into them after slaying them cleanly. His goddess purportedly gifted him with these greaves to assist him with his constant "
"battles. His disappearance was never recorded, so it is speculated that perhaps he has just retired, or perhaps his %^BLACK%^shadow%^CYAN%^ finally caught up to him. %^WHITE%^- 'Chronicles of "
"the %^BLACK%^Wolf%^WHITE%^', Saelmion Dukanish.");
	set_property("lore difficulty",15);
	set_size(-1);
	set_armor_prof("light");
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("dexterity",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" growls softly as "+ETO->query_subjective()+" buckles on the greaves, "+ETO->query_possessive()+" voice low and %^RESET%^%^RED%^feral%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You buckle on the greaves and feel your blood %^RED%^boil%^RESET%^.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" calms down visibly as "+ETO->query_subjective()+" removes the greaves, shaking "+ETO->query_possessive()+" head to clear some unknown sound.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You unbuckle the greaves slowly, the howls of a pack of feral wolves ringing in your head.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(!random(5)){
	tell_room(environment(query_worn()),"%^RESET%^%^BOLD%^Just as "+who->QCN+" is about to strike "+ETOQCN+", "+ETO->query_subjective()+" rushes forward, "+ETO->query_possessive()+" form becoming that of a %^BLACK%^shadowy wolf%^WHITE%^ as "+ETO->query_subjective()+" avoids the blow.",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^BOLD%^Just as "+who->QCN+" is about to strike you, there is a low snap and growl as you leap forward, avoiding the blow.%^RESET%^");
	tell_object(who,"%^RESET%^%^BOLD%^As you strike "+ETOQCN+", "+ETO->query_subjective()+" transforms into a %^BLACK%^shadowy wolf%^WHITE%^ and your blow passes right through "+ETO->query_objective()+"!%^RESET%^");
    return 0;;
    }
    return damage;
}