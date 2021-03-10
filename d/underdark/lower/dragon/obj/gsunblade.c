// intentionally mirrors the special rate of the ragnarok, as a good-align counterpart. Nienne, 07/09.
// changed to bastard sword to justify the exotic prof. N, 2/20.
#include <std.h>
inherit "/d/common/obj/weapon/bastard";

int beam_em(mapping info);
void tell_em(string str);
int OWNED, COUNTER, FLAG;
string *owners;

void create() {
    ::create();
    set_name("golden blade");
    set_id(({"sword","blade","golden blade","brilliant blade","brilliant golden blade","bastard sword","bastard","golden bastard sword","sunblade","Sunblade","greater sunblade"}));
    set_short("%^YELLOW%^Gr%^RESET%^%^ORANGE%^eat%^YELLOW%^er Sun%^RESET%^%^ORANGE%^bl%^YELLOW%^ade%^RESET%^");
    set_obvious_short("%^YELLOW%^a brilliant go%^RESET%^%^ORANGE%^ld%^YELLOW%^en blade%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This %^RESET%^%^CYAN%^br%^BOLD%^il%^WHITE%^l"
"%^CYAN%^ia%^RESET%^%^CYAN%^nt %^BOLD%^%^WHITE%^sword glitters with even the "
"faintest touch of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ght %^WHITE%^upon it.  Its "
"surface appears to be made of pure %^RESET%^%^ORANGE%^go%^YELLOW%^l%^RESET%^"
"%^ORANGE%^d%^BOLD%^%^WHITE%^, which surely is an impossibility given the "
"quality of the weapon; %^RESET%^%^GREEN%^ma%^BOLD%^gi%^RESET%^%^GREEN%^c "
"%^BOLD%^%^WHITE%^must have had a hand in its crafting.  The entire weapon is "
"more than five feet in length, nearly four of which form the blade itself.  "
"%^RESET%^%^CYAN%^Li%^GREEN%^ght%^CYAN%^er %^BOLD%^%^WHITE%^than its size would "
"suggest, the hollow-ground blade has been deliberately shaped for strength "
"without weight.  Perfectly balanced, the blade has been honed to a "
"%^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp "
"%^WHITE%^edge and tapers towards the point.  It seems to have been "
"deliberately designed with a shorter blade and longer hilt than a standard "
"longsword, allowing for a better grip and a more precise, reactive nature in "
"%^RED%^co%^RESET%^%^RED%^mb%^BOLD%^at%^WHITE%^.  Oddly, its thick blade "
"narrows abruptly to a thin neck just before the crossguard, which flares back "
"out again in several %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^WHITE%^ridges like tongues of %^RED%^f%^RESET%^%^RED%^l%^BOLD%^a%^YELLOW%^m"
"%^RED%^e%^WHITE%^.  No leather wraps the hilt, but the grip is smooth and "
"slightly ridged, intentionally shaped as a secure handhold.  At the centre of "
"the hilt, a single %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby "
"%^BOLD%^%^WHITE%^has been embedded, with spiderlike trails of %^RESET%^white "
"crys%^CYAN%^t%^RESET%^al %^BOLD%^%^WHITE%^marking the sparkling "
"%^RESET%^%^RED%^blo%^BOLD%^o%^RESET%^%^RED%^d-red %^BOLD%^%^WHITE%^surface of "
"the gem.%^RESET%^\n");
    set_lore("%^WHITE%^'Sir Clarik knew, then, as the wraiths closed in and the "
"darkness thickened, that his crusade would end here.  His injuries took their "
"toll even now, steadily draining him of what little strength he had left.  He "
"could no longer even lift his precious blade, its golden tip resting upon the "
"soil before him as his hand desperately grasped at its hilt.  As the child "
"cowered behind him, and the hissing undead raised their claws to finish him, he "
"offered a prayer to commend his soul to his Lord, that they would both soon join "
"Lathander in paradise.'\n\n"
"'As the deadly claws sank into his flesh and he raised his eyes to the heavens, "
"a single radiant sunbeam lanced down from above to strike the brilliant ruby "
"embedded in the hilt of the golden sword.  Reflections of sunlight burst forth "
"in all directions, striking through the wraiths as if they were nothing more "
"than shadows.  Shrieks rent the air as the undead dissipated into nothingness.  "
"A weak smile passed across Clarik's lips as his eyes closed for the last time, "
"and the sword's hilt fell from his fingers.'\n\n"
"'It was here, hours later, that Priestess Johanna found the child, all alone and "
"clutching the blade's hilt like a lifeline.  Of Sir Clarik, no sign was ever "
"found, but his sword was returned to the small shrine of Lathander at Orreska to "
"be honored from that day forth.'\n");
    set_property("lore difficulty",35);
    set_property("id difficulty",35);
    set_property("enchantment",5);
    while((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_item_bonus("attack bonus",3);
    set_item_bonus("damage bonus",3);
    set_item_bonus("sight bonus",3);
    set_value(17600);
    set_hit((:TO,"hit_func":));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_property("no alter",1);
    owners = ({});
    set_heart_beat(1);
    set_property("master weapon",1);
    set_property("repairtype",({"weaponsmith",}));
}

int wield_func(){
   int myflag, i;
   object *mywielded;
   if(!userp(ETO)) return 1;
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(!((int)ETO->query_true_align()%3)) {
     tell_object(ETO,"%^YELLOW%^Brilliant %^WHITE%^light %^YELLOW%^bursts forth from the ruby stone within the blade's "
"hilt as you try to wield it, and you blink, all vision gone from your eyes!%^RESET%^");
     tell_room(EETO,"%^YELLOW%^Brilliant %^WHITE%^light %^YELLOW%^bursts forth from the ruby stone within the blade's "
"hilt as "+ETO->QCN+" tries to wield it, and "+ETO->QS+" blinks, gazing around sightlessly!%^RESET%^",ETO);
     ETO->set_paralyzed(25,"%^BOLD%^%^RED%^You're still recovering from that flash of light!%^RESET%^");
     ETO->set_blind(1);
     return 0;
   }
   if(ETO->query_property("evil item")) {
     tell_object(ETO,"%^YELLOW%^There is so much evil in the items you carry that the sword simply repels your "
"hand!%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this weapon.");
     return 0;
   }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^BOLD%^%^WHITE%^You reach out to grasp the blade, and the weapon already in your hand "
"seems to radiate with denial.  You find yourself unwilling even to lift the second weapon!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" reaches out to grasps the blade, but then hesitates, and "
"stops.",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^A gentle %^RESET%^%^RED%^war%^MAGENTA%^mt%^RED%^h %^BOLD%^%^WHITE%^runs through your "
"veins as you lift the surprisingly light blade.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^Light glints off the edge of the %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^BOLD%^%^WHITE%^blade as "+ETO->QCN+" takes it up.%^RESET%^",ETO);
   ETO->set_property("good item",1);
   ETO->set_property("master weapon",1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^Disappointment wells up in you as you set aside the magnificent %^YELLOW%^go%^RESET%^"
"%^ORANGE%^ld%^YELLOW%^en %^BOLD%^%^WHITE%^blade.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" sets aside the magnificent %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^BOLD%^%^WHITE%^blade.%^RESET%^",ETO);
   ETO->set_property("good item",-1);
   ETO->set_property("master weapon",-1);
   return 1;
}

int hit_func(object targ){
    int rand;
    rand = roll_dice(1,10);
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;
    if(roll_dice(1,100) > 37) { COUNTER++; return roll_dice(1,4); }

    if(rand > 0 && rand < 5) { // between 1 and 4 or 40%
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you strike, %^YELLOW%^co%^MAGENTA%^r%^YELLOW%^u%^WHITE%^sc%^YELLOW%^a%^WHITE%^"
"ti%^CYAN%^n%^YELLOW%^g %^WHITE%^motes of light tumble from the golden blade to settle upon your skin.%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s blade sheds %^YELLOW%^co%^MAGENTA%^r%^YELLOW%^u%^WHITE%^sc%^YELLOW%^"
"a%^WHITE%^ti%^CYAN%^n%^YELLOW%^g %^WHITE%^motes of light that settle onto "+ETO->QP+" skin as "+ETO->QS+" strikes"
"!%^RESET%^",ETO);
      TO->set_property("magic",1);
      ETO->do_damage("torso",roll_dice(6,4)*(-1));
      TO->set_property("magic",-1);
      COUNTER--;
    }

    if(rand > 2 && rand < 6)  {// between 3 and 5 or 30%
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Go%^RESET%^%^ORANGE%^ld%^YELLOW%^en energy races along the blade as its %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^YELLOW%^edge bites into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^YELLOW%^Go%^RESET%^%^ORANGE%^ld%^YELLOW%^en energy races along "+ETO->QCN+"'s blade as "
"its %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^YELLOW%^edge bites into you!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^YELLOW%^Go%^RESET%^%^ORANGE%^ld%^YELLOW%^en energy races along "+ETO->QCN+"'s blade as "
"its %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^YELLOW%^edge bites into "+targ->QCN+
"!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",roll_dice(3,10));
      COUNTER--;
    }

    if(rand > 4 && rand < 7) { // between 4 and 6 or 20%
	tell_object(ETO,"%^BOLD%^%^RED%^Upon the hilt of your blade, the ruby's spiderweb cracks of %^RESET%^white crys"
"%^CYAN%^t%^RESET%^al %^BOLD%^%^RED%^disappear in a momentary pulse of viv%^MAGENTA%^i%^RED%^d s%^RESET%^%^RED%^ca%^BOLD%^"
"rlet, lending so much force to your blow that it casts "+targ->QCN+" to the ground!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^Upon the hilt of "+ETO->QCN+"'s blade, the ruby's spiderweb cracks of %^RESET%^"
"white crys%^CYAN%^t%^RESET%^al %^BOLD%^%^RED%^disappear in a momentary pulse of viv%^MAGENTA%^i%^RED%^d s%^RESET%^%^RED%^"
"ca%^BOLD%^rlet.  "+capitalize(ETO->QP)+" following blow carries so much force that it casts you to the ground!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^RED%^Upon the hilt of "+ETO->QCN+"'s blade, the ruby's spiderweb cracks of %^RESET%^white "
"crys%^CYAN%^t%^RESET%^al %^BOLD%^%^RED%^disappear in a momentary pulse of viv%^MAGENTA%^i%^RED%^d s%^RESET%^%^RED%^ca"
"%^BOLD%^rlet.  "+capitalize(ETO->QP)+" following blow carries so much force that it casts "+targ->QCN+" to the ground"
"!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(roll_dice(1,10) + 10, "%^BOLD%^%^RED%^You are struggling to stand up!%^RESET%^");
      COUNTER--;
    }

    if(rand > 6 && rand < 10) { // between 7 and 9 or 30%
	tell_object(ETO,"%^BOLD%^%^GREEN%^Your blade seems impossibly %^RESET%^%^CYAN%^li%^BOLD%^gh%^WHITE%^twe%^CYAN%^ig"
"%^RESET%^%^CYAN%^ht %^BOLD%^%^GREEN%^as you draw it back for a second blow, striking at your foes in rapid succession"
"!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" hefts "+ETO->QP+" sword with the %^RESET%^%^CYAN%^s%^BOLD%^p%^WHITE%^e"
"%^CYAN%^e%^RESET%^%^CYAN%^d %^BOLD%^%^GREEN%^of a far lighter weapon, lashing out with several blows in rapid succession"
"!%^RESET%^",ETO);
	if(sizeof(ETO->query_attackers())) ETO->execute_attack();
      COUNTER--;
    }

    if(rand == 10 && COUNTER > 999) { // 10 and counter 1000 or higher
	int i;
	object *living;
	mapping info;
	living = all_living(EETO);
	info = ([
		"living"  : living,
		"eto"     : ETO,
		"count"   : 0,
		"special" : ({}),
		"delay"   : 0,
		"targ"    : targ,
		"eeto"    : EETO,
	]);
	for(i=0;i<sizeof(living);i++) {
		living[i]->set_paralyzed(0);
		living[i]->cease_all_attacks();
	}
	call_out("beam_em",2,info);
	COUNTER = 0;
    }
    else if(rand == 10 && COUNTER <= 999) { // Blind/Stun if 10 and the counter is not 1000 or higher
	tell_object(ETO,"%^BOLD%^%^CYAN%^A burst of fire races up the sword's %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^"
"en %^CYAN%^blade as you strike, and "+targ->QCN+" becomes momentarily engulfed in a mirroring pyre of %^RED%^in%^RESET%^"
"%^RED%^ca%^MAGENTA%^n%^BOLD%^%^RED%^de%^MAGENTA%^s%^YELLOW%^ce%^RED%^nt %^CYAN%^flame!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^A burst of fire races up the sword's %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^"
"en %^CYAN%^blade as "+ETO->QCN+" strikes, and you becomes momentarily engulfed in a mirroring pyre of %^RED%^in%^RESET%^"
"%^RED%^ca%^MAGENTA%^n%^BOLD%^%^RED%^de%^MAGENTA%^s%^YELLOW%^ce%^RED%^nt %^CYAN%^flame!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^CYAN%^A burst of fire races up the sword's %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^CYAN%^blade as "+ETO->QCN+" strikes, and "+targ->QCN+" becomes momentarily engulfed in a mirroring pyre of %^RED%^in"
"%^RESET%^%^RED%^ca%^MAGENTA%^n%^BOLD%^%^RED%^de%^MAGENTA%^s%^YELLOW%^ce%^RED%^nt %^CYAN%^flame!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(roll_dice(5,5)+25,"%^BOLD%^%^WHITE%^You are overcome by the searing pain!%^RESET%^");
      if(!"daemon/saving_throw_d"->reflex_save(targ,-25)) targ->set_temporary_blinded(2);
    }
    return 0;
}

int query_counter() { return COUNTER; }
void set_counter(int num) { COUNTER = num; }

int beam_em(mapping info) {
	int i,delay,count;
	object *living,*special,eto,targ,eeto;

	living  = info["living"];
	special = info["special"];
	eto     = info["eto"];
	count   = info["count"];
	eeto    = info["eeto"];
	targ    = info["targ"];
	delay   = info["delay"];

	if(!pointerp(living)) return 0;
	if(!objectp(eto))	return 0;
	if(!objectp(eeto)) return 0;

	if(!FLAG) {
		for(i=0;i<sizeof(living);i++) {
			if(living[i]->query_property("no paralyze")) special += ({ living[i] });
		}
		if(sizeof(special)) {
			for(i=0;i<sizeof(special);i++) {
				if(!objectp(special[i])) continue;
				special[i]->remove_property("no paralyze");
			}
		}
		for(i=0;i<sizeof(living);i++) {
			if(interactive(living[i]) && !living[i]->query_true_invis()) living[i]->force_me("cls");
			living[i]->cease_all_attacks();
			living[i]->set_paralyzed(14,"%^YELLOW%^You can't tear your gaze away from the glowing golden "
				"blade!%^RESET%^");
		}
		tell_object(eto,"%^BOLD%^%^WHITE%^The air seems to %^RESET%^%^RED%^th%^BOLD%^i%^RESET%^%^RED%^cken %^BOLD%^"
"%^WHITE%^as the world around you slows, and the ground rumbles %^RESET%^%^ORANGE%^o%^RESET%^m%^RED%^i%^ORANGE%^n%^BOLD%^"
"%^BLACK%^ou%^RESET%^s%^RED%^l%^ORANGE%^y %^BOLD%^%^WHITE%^underfoot.  Your sword rises, as if of its own accord, and "
"pulls your hand up with it as it still grips the hilt, until the tip of the %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^"
"en %^WHITE%^blade points directly upwards.");
		tell_room(eeto,"%^BOLD%^%^WHITE%^The air seems to %^RESET%^%^RED%^th%^BOLD%^i%^RESET%^%^RED%^cken %^BOLD%^"
"%^WHITE%^as the world around you slows, and the ground rumbles %^RESET%^%^ORANGE%^o%^RESET%^m%^RED%^i%^ORANGE%^n%^BOLD%^"
"%^BLACK%^ou%^RESET%^s%^RED%^l%^ORANGE%^y %^BOLD%^%^WHITE%^underfoot.  "+eto->QP+"'s sword rises, as if of its own accord"
", and pulls "+eto->QP+" hand up with it as they still grip the hilt, until the tip of the %^YELLOW%^go%^RESET%^%^ORANGE%^"
"ld%^YELLOW%^en %^WHITE%^blade points directly upwards.",eto);

		info = ([
			"living"  : living,
			"eto"     : eto,
			"count"   : 1,
			"special" : special,
			"delay"   : 5,
			"targ"    : targ,
			"eeto"    : eeto,
		]);
		FLAG = 1;
		call_out("beam_em",15,info);
		return 0;
	}

	switch(count) {
	case 1:
		tell_em("%^YELLOW%^The sounds around you seem to become muted, as the sky above suddenly becomes flooded with "
"the radiant %^CYAN%^c%^RESET%^%^ORANGE%^o%^MAGENTA%^l%^BOLD%^o%^RED%^r%^RESET%^%^RED%^s %^YELLOW%^of sunrise.%^RESET%^");
		tell_room(eeto,"%^BOLD%^%^WHITE%^From the heavens above descends a single %^YELLOW%^br%^RED%^il%^MAGENTA%^l"
"%^RED%^ia%^YELLOW%^nt %^WHITE%^sunbeam, a thin and nearly blinding ray of radiance that strikes the blade and sets its "
"golden surface %^RED%^afi%^RESET%^%^RED%^r%^BOLD%^e%^WHITE%^.%^RESET%^");
		info["count"] = 2;
		call_out("beam_em",15,info);
		return 0;
	case 2:
		if(!objectp(targ)) return 0;
		tell_room(eeto,"%^BOLD%^%^WHITE%^As the sunbeam strikes the %^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^by "
"%^BOLD%^%^WHITE%^stone upon the blade's hilt, its light fractures into a thousand reflections with the sound of %^CYAN%^"
"sh%^WHITE%^a%^CYAN%^tter%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ng glass%^WHITE%^.  The spiderwebbed crystal veins cast out an "
"explosion of %^YELLOW%^d%^WHITE%^az%^YELLOW%^zl%^WHITE%^in%^YELLOW%^g %^WHITE%^rays in all directions!%^RESET%^");
		info["count"] = 3;
		call_out("beam_em",15,info);
		return 0;
	case 3:
		if(!objectp(targ)) return 0;
		//if(!ROLLSAVE(targ, PPD )) {
			tell_object(targ,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^"
"n%^WHITE%^g light plays harmlessly around you, the rays that fall upon you tear through your body, and you can't help "
"but %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^in agony.  Your body is lifted from the ground by the "
"incredible force, and is almost instantly %^RESET%^%^RED%^shr%^BOLD%^e%^RESET%^%^RED%^dded %^BOLD%^%^WHITE%^into "
"nothingness!%^RESET%^");
			tell_room(eeto,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^n"
"%^WHITE%^g light plays harmlessly around you, the rays that fall upon "+targ->QCN+" seem to tear through "+targ->QP+
" body, as "+targ->QP+" mouth opens in a jarring %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^of agony.  "
+capitalize(targ->QS)+" is lifted from the ground by the incredible force, and is almost instantly %^RESET%^%^RED%^shr"
"%^BOLD%^e%^RESET%^%^RED%^dded %^BOLD%^%^WHITE%^into nothingness!%^RESET%^",targ);
			ETO->set_property("magic",1);
			targ->do_damage("torso",roll_dice(10000,10000));
			ETO->set_property("magic",-1);
			targ->die();
		//}
		/*else {
			tell_object(targ,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^"
"n%^WHITE%^g light plays harmlessly around you, the rays that fall upon you tear through your body, and you can't help "
"but %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^in agony!%^RESET%^");
			tell_room(eeto,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^n"
"%^WHITE%^g light plays harmlessly around you, the rays that fall upon "+targ->QCN+" seem to tear through "+targ->QP+
" body, as "+targ->QP+" mouth opens in a jarring %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^of agony"
"!%^RESET%^",targ);
			targ->do_damage("torso",roll_dice(20,10));
		}*/
		info["count"] = 4;
		call_out("beam_em",15,info);
		return 0;
	case 4:
		tell_room(eto,"%^BOLD%^%^WHITE%^Just as suddenly as it happened, the %^YELLOW%^su%^RED%^n%^MAGENTA%^b%^RED%^e"
"%^YELLOW%^am %^WHITE%^winks out of existance and the radiance around you fades, as the %^RESET%^%^RED%^r%^BOLD%^u"
"%^RESET%^%^RED%^by %^BOLD%^%^WHITE%^darkens again to display its spiderwebbing of %^RESET%^clear crys%^CYAN%^t%^RESET%^al"
"%^BOLD%^.%^RESET%^");
		tell_em("%^RED%^The crimson hue fades from the air and the ground "
			"beneath you settles..you feel that something terrible has happened...%^RESET%^");
		for(i=0;i<sizeof(living);i++)	{
			if(!objectp(living[i])) { continue; }
			living[i]->set_paralyzed(0);
		}
		for(i=0;i<sizeof(special);i++) {
			if(!objectp(special[i])) continue;
			special[i]->set_property("no paralyze", 1);
		}
	}
	return 0;
}

void tell_em(string str) {
    int i;
    object *users;
    users = children("/std/user.c");
    for(i=0;i<sizeof(users);i++) {
      if(!interactive(users[i])) continue;
      tell_object(users[i],str);
    }
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}

void heart_beat()
{
    if(!objectp(ETO)) { return; }
    if(interactive(ETO) && present("greater sunblade 2",ETO)) {
        tell_object(ETO,"%^YELLOW%^The two swords tremble when brought "
            "together.  In a flash, they merge together into a single "
            "blade!");
        TO->remove();
    }
    if(interactive(ETO) && present("ragnarok",ETO)) {
        tell_room(EETO,"%^BOLD%^%^RED%^A shriek goes up in the air as "
		"the two conflicting blades are brought together.  A massive "
		"concussion pulses forth, splintering both weapons into "
		"fragments!");
        present("ragnarok",ETO)->remove();
        TO->remove();
    }
}
