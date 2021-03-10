
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";


void create() {
    ::create();
   set_id(({"sword","silver sword","lesser silver sword","githyanki sword"}));
   set_name("lesser silver sword");
   set_short("%^RESET%^%^BOLD%^%^WHITE%^le%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^"+
"%^WHITE%^ser s%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^lver s%^RESET%^"+
"%^WHITE%^w%^RESET%^%^BOLD%^%^WHITE%^ord%^RESET%^");
   set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^run%^RESET%^%^WHITE%^i%^RESET%^"+
"%^BOLD%^%^WHITE%^c s%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^lver s%^RESET%^"+
"%^WHITE%^w%^RESET%^%^BOLD%^%^WHITE%^ord%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This blade is impressive to look at, "+
"it's blade a full longsword blade made entirely from %^RESET%^%^WHITE%^silver"+
"%^RESET%^%^BOLD%^%^WHITE%^. Along the edge of the blade are several %^RESET%^"+
"%^WHITE%^lines of runes etched %^RESET%^%^BOLD%^%^WHITE%^and marked with a "+
"%^RESET%^%^BOLD%^%^BLACK%^darker metal%^RESET%^%^BOLD%^%^WHITE%^. The hilt "+
"of the blade is wrapped in a %^RESET%^%^ORANGE%^soft leather%^RESET%^%^BOLD%^"+
"%^WHITE%^, giving it a comfortable grip. The pommel of the blade is a rounded"+
" and buffed %^RESET%^%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^a%^RESET%^%^BOLD%^"+
"%^BLACK%^rk sto%^RESET%^%^RED%^n%^RESET%^%^BOLD%^%^BLACK%^e %^RESET%^%^BOLD%^"+
"%^WHITE%^with constantly swirling veins of %^RESET%^%^RED%^red%^RESET%^"+
"%^BOLD%^%^WHITE%^. %^RESET%^");
   set_property("enchantment",2);
   set_item_bonus("attack bonus",1);
   set("value", 2000);
   set_hit((:TO, "hit_func" :) );
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_property("lore difficulty",15);
   set_lore("%^BLACK%^%^BOLD%^The silver long swords of the githyanki are "+
"legendary creations, able to destroy the fragile lines that tie travellers "+
"when they wander the planes. It is said that when a githyanki loses their sword"+
", they must retreieve it, so those who take the swords of the githyanki do not "+
"tend to hold them for long without a band of hunters coming to find it again.%^RESET%^");
set_special_material_type("silver");

}

int wield_func(object targ){
        tell_room(EETO,"%^RESET%^%^BOLD%^As "+ETOQCN+" %^RESET%^%^BOLD%^wields "+
"the "+query_short()+", %^RESET%^%^BOLD%^the runes along it's blade seem to flare"+
" to life.%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^RESET%^%^BOLD%^You raise the "+query_short()+", %^RESET%^"+
"%^BOLD%^and you hear a strange voice in your head.. It seems to be calling to you."+
"%^RESET%^");
        return 1;
}

int unwield_func(object targ) {
        tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+"%^RESET%^%^RED%^ sets the blade "+
"aside, the pommel stone flashes then goes dead.%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^RESET%^%^RED%^As you set the "+query_short()+" %^RESET%^"+
"%^RED%^aside, you hear a thread snap.%^RESET%^");
        return 1;
}

int hit_func(object targ){
        if(!objectp(targ)) return 0;
        if(!objectp(ETO)) return 0;
		if(random(1000) < 100){
		      switch(random(10)){
        case 0:
			tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" %^RESET%^%^CYAN%^holds the "+
"sword out in front of "+targ->QCN+"%^RESET%^%^CYAN%^.%^RESET%^",({ETO,targ}));
			tell_object(ETO,"%^RESET%^%^CYAN%^You hold out the sword in front"+
" of "+targ->QCN+"%^RESET%^%^CYAN%^.%^RESET%^");
			tell_object(targ,"%^RESET%^%^CYAN%^"+ETOQCN+" %^RESET%^%^CYAN%^holds out"+
" the sword in front of you.%^RESET%^");
	new("/cmds/spells/d/_dispel_psionics.c")->use_spell(ETO,targ,15,100,"psion");

        break;

		default:
			tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^'s sword slashes"+
" deeply into "+targ->QCN+"%^BOLD%^%^RED%^.%^RESET%^",({ETO,targ}));
			tell_object(ETO,"%^BOLD%^%^RED%^You score a wicked slash against %^BOLD%^"+
"%^RED%^"+targ->QCN+"%^BOLD%^%^RED%^.%^RESET%^");
			tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ slashes you "+
"horribly with the sword.%^RESET%^");
			return roll_dice(3,4)+-1;

		break;

        return 0;
		}
    }
}
