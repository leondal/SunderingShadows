//Hijacked March 31, 2011 by Ergo for Squire's Trial
//Based on Sunblade by Crystal
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create()
{
	::create();
	set_name("%^BOLD%^%^BLACK%^B%^GREEN%^a%^BOLD%^%^BLACK%^n"+
		"%^GREEN%^e%^BOLD%^%^BLACK%^b%^GREEN%^l%^BOLD%^"+
		"%^BLACK%^a%^GREEN%^d%^BOLD%^%^BLACK%^e%^RESET%^");
	set_id(({"longsword","sword","bane sword","blade","baneblade","bane blade"}));
	set_short("%^BOLD%^%^BLACK%^B%^GREEN%^a%^BOLD%^%^BLACK%^n"+
		"%^GREEN%^e%^BOLD%^%^BLACK%^b%^GREEN%^l%^BOLD%^"+
		"%^BLACK%^a%^GREEN%^d%^BOLD%^%^BLACK%^e%^RESET%^");
  set_obvious_short("%^BOLD%^%^BLACK%^A black long sword%^RESET%^");
	set_long("%^CYAN%^This long sword has been forged from a strong alloy "+
	"that has a %^BOLD%^%^BLACK%^black tinge%^RESET%^%^CYAN%^ to it."+
	" The blade has been forged with such skill that the blade is quite"+
	" light but exceptionally strong and perfectly balanced. A large"+
	" %^BOLD%^%^GREEN%^emerald%^RESET%^%^CYAN%^, with a "+
	"%^BOLD%^%^BLACK%^fist%^RESET%^%^CYAN%^"+
	" engraved into its face in bass-relief, which reflects fragmented"+
	"%^BOLD%^%^WHITE%^ light%^RESET%^%^CYAN%^ with an odd pulse has "+
	"been set into the %^BOLD%^%^BLACK%^black hilt%^RESET%^%^CYAN%^. "+
	"There are four smaller %^BOLD%^%^GREEN%^emeralds%^RESET%^"+
	"%^CYAN%^ that have been set "+
	"into the %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ crosspiece"+
	" over the top of the hilt that flash brightly in the light.%^RESET%^");
   set_lore("This sword has been crafted to aid the Banites in their quest"+
	" to dominate and rule the realms.  The Baneblade is said to be a "+
	"corrupted Sunblade, filled with unholy energy to aid those with "+
	"dark twisted hearts.");
	set_property("lore difficulty",14);
	set_property("enchantment",(random(2))+2);
	set_value(1600);
	set_hit((:TO,"hitme":));
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
}

int wieldme()
{
	int align;

	align = ETO->query_alignment();
	if(ETO->query_level() < 15) {
		tell_object(ETO,"You must be of greater stature before"+
		" the blade will let you wield it.");
		return 0;
	}
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^BLACK%^The %^GREEN%^"+
				"emerald%^BOLD%^%^BLACK%^"+
				" on the hilt flashes in approval.");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The"+
				" %^GREEN%^emerald"+
				"%^BOLD%^%^BLACK%^ on the hilt of"+
				" "+ETO->QCN+"'s sword flashes briefly.",ETO);
			set_item_bonus("magic resistance",1);
         ETO->set_property("evil item",1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^%^BLACK%^The smaller "+
				"%^GREEN%^emeralds%^BOLD%^%^BLACK%^ on "+
				"the hilt glow faintly.");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+
				"The smaller %^GREEN%^emeralds%^BLACK%^ "+
				"on the hilt of "+ETO->QCN+"'s"+
				" sword glow faintly.",ETO);
			set_item_bonus("magic resistance",1);
         ETO->set_property("evil item",1);
			return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^%^BLACK%^All the "+
				"%^GREEN%^emeralds%^BLACK%^"+
				" on the hilt flash angrily as you "+
				"wield the sacred Baneblade.");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+
				"The %^GREEN%^emeralds%^BLACK%^ on the "+
				"hilt of "+ETO->QCN+"'s"+
				" sword flash briefly.",ETO);
			set_item_bonus("magic resistance",0);
         ETO->set_property("evil item",1);
			return 1;

		default:
			tell_object(ETO,"Oh yeah, you've got some major problems"+
			" here pal.");
			return 0;
	}
}

int removeme()
{
	int align;

	align = ETO->query_alignment();
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^BLACK%^You feel less "+
			"protected as you release your grip on the sword.");
        ETO->set_property("evil item",-1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^%^BLACK%^The small "+
				"%^GREEN%^emeralds%^BOLD%^%^BLACK%^"+
				" in the hilt of the sword glow faintly "+
				"as you release it.");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The "+
				"small %^GREEN%^emeralds%^BOLD%^%^BLACK%^"+
				"in the hilt of "+ETO->QCN+"'s"+
				" sword glow faintly.",ETO);
        ETO->set_property("evil item",-1);
			return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^%^BLACK%^The sword seems"+
			" very happy to be rid of you.");
        ETO->set_property("evil item",-1);
			return 1;

		default:
			tell_object(ETO,"Well, well, well, how'd you manage"+
			" to get yourself into this mess?");
			return 0;
	}
}

int hitme(object targ)
{
	int align, talign;

	if(!objectp(targ)) return 1;

	align = ETO->query_alignment();
	talign = targ->query_alignment();

	switch(align) {
		case 3: case 6: case 9:{
			if(!random(100)) {
				tell_object(ETO,"%^GREEN%^The %^BOLD%^emeralds%^RESET%^%^GREEN%^"+
				" on the hilt begins to glow, the green light expands"+
				" outwards to cover your body. You can almost sense"+
				" a presence, then the light is gone and"+
				" you feel rested.");
				tell_room(environment(ETO),"%^GREEN%^The %^BOLD%^emerald"+
				"%^RESET%^%^GREEN%^ on "+ETO->QCN+"'s hilt begins to"+
				" glow, the green light expands to bathe "+ETO->QO+""+
				" in it and then fades.",ETO);
				ETO->do_damage("torso",-(random(6)+10));
				return 1;
			}
			else {
			switch(talign) {
				case 3: case 6: case 9:{
					if(!random(25)) {
						tell_object(ETO,"%^BOLD%^%^BLACK%^The %^GREEN%^"+
						"emeralds%^BOLD%^%^BLACK%^ on the Baneblade "+
						"flare angrily as you hit "+targ->QCN+".");
						tell_object(targ,"%^BOLD%^%^BLACK%^The "+
						"%^GREEN%^emerald%^BOLD%^%^BLACK%^ on "+
						""+ETO->QCN+"'s sword flare angrily as "+
						""+ETO->QS+" hits you.");
						tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The"+
						" %^GREEN%^emeralds%^BOLD%^%^BLACK%^ on "+ETO->QCN+"'s"+
						" sword flare angrily as "+ETO->QS+""+
						" hits "+targ->QCN+".",({ETO,targ}));
						targ->do_damage("torso",random(5)+2);
						return 1;
					}
					break;
				}
				case 2: case 5: case 8:{
					if(!random(15)) {
						tell_object(ETO,"%^BOLD%^%^GREEN%^The edges of"+
						" the Baneblade flicker to life with a green"+
						" flame, burning "+targ->QCN+".");
						tell_object(targ,"%^BOLD%^%^GREEN%^The edges of"+
						" "+ETO->QCN+"'s sword burst"+
						" into green flames that burn you as the sword"+
						" strikes a blow.");
						tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The"+
						" edges of "+ETO->QCN+"'s sword"+
						" burst into green flames that burn "+targ->QCN+""+
						" as the blade strikes "+targ->QO+".",({ETO,targ}));
						targ->do_damage("torso",random(6)+4);
						return 1;
					}
					if(!random(25)) {
						tell_object(ETO,"%^BOLD%^%^BLACK%^The sword seems to"+
						" move even faster than you expected and you"+
						" are able to guide it between a section of"+
						" "+targ->QCN+"'s armor for a"+
						" brutal hit.");
						tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
						" sword moves faster than possible, streaking"+
						" in to score a brutal hit on a weak section"+
						" where your armor joins together.");
						tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
						" sword moves impossibly fast, striking where"+
						" two sections of armor join together for a"+
						" brutal hit.",({ETO,targ}));
						targ->do_damage("torso",random(8)+5);
						return 1;
					}
					break;
				}

				case 1: case 4: case 7:{
					if(!random(30)) {
						if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
							tell_object(ETO,"%^BOLD%^Your sword flashes"+
							" with a bright light, blinding "+targ->QCN+".");
							tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s"+
							" sword flashes with a bright light,"+
							" blinding you!");
							tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s"+
							" sword flashes with a bright light,"+
							" blinding "+targ->QCN+".",({ETO,targ}));
							targ->set_temporary_blinded(2);
							return 1;
						}
						else {
							tell_object(ETO,"%^BOLD%^Your sword"+
							" flashes with a blinding light, but"+
							" "+targ->QCN+" manages to"+
							" resist the sword's power.");
							tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s"+
							" sword flashes with a blinding light, but"+
							" you manage to resist its spell, but the light still burns your soul!");
							tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s"+
							" sword flashes with a blinding light.",({ETO,targ}));
							targ->do_damage("torso",random(8)+8);
                                                        return 1;
						}
					}
					if(!random(18)) {
						tell_object(ETO,"%^BOLD%^%^BLACK%^The Baneblade begins"+
						" to vibrate in your hands, it points towards"+
						" "+targ->QCN+" and a ray of"+
						" %^GREEN%^green%^BOLD%^%^BLACK%^ fire shoots "+
						"forth from the tip and"+
						" engulfs "+targ->QO+"!");
						tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
						" points "+ETO->QP+" blade"+
						" at you and a %^GREEN%^green "+
						"%^BOLD%^%^BLACK%^flame erupts from the"+
						" tip of the sword, shooting forth to engulf"+
						" you!\n\nThe green fire burns like nothing"+
						" you have ever felt before!");
						tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
						" points "+ETO->QP+" blade"+
						" at "+targ->QCN+" and a %^GREEN%^green%^BOLD%^%^BLACK%^"+
						" flame springs forth from the tip of the sword"+
						" to engulf "+targ->QO+".",({ETO,targ}));
						targ->do_damage("torso",random(10)+6);
						return 1;
					}
					break;
				}
			}
			break;
			}
		}

		case 2: case 5: case 8:{
			switch(talign) {
				case 3: case 6: case 9:{
					if(!random(15)) {
						tell_object(ETO,"%^BOLD%^%^GREEN%^The emeralds"+
						" flare angrily at your attack on "+targ->QCN+""+
						" and the hilt burns your hand!");
						tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The emeralds"+
						" on "+ETO->QCN+"'s sword flare"+
						" brightly and "+ETO->QS+""+
						" cries out in pain.",ETO);
						ETO->do_damage("torso",random(8)+2);
						return 1;
					}
					break;
				}

				case 2: case 5: case 8: case 1: case 4: case 7:{
					if(!random(25)) {
						tell_object(ETO,"%^GREEN%^You slice your sword deeply"+
						" into "+targ->QCN+" and the"+
						" blade glows green, burning "+targ->QO+".");
						tell_object(targ,"%^GREEN%^"+ETO->QCN+""+
						" slices "+ETO->QP+" sword into"+
						" you and the blade begins to glow green,"+
						" burning your flesh!");
						tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+""+
						" slices "+ETO->QP+" sword into"+
						" "+targ->QCN+" and the blade"+
						" glows green, burning "+targ->QO+"!",({ETO,targ}));
						targ->do_damage("torso",random(10)+3);
						return 1;
					}
					if(!random(40)) {
						tell_object(ETO,"%^BOLD%^%^GREEN%^The sword throbs"+
						" with a dominating green glow.\n"+targ->QCN+""+
						" is dazzled by the glow and you lunge"+
						" hard at "+targ->QO+", catching"+
						" "+targ->QO+" off guard.");
						tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s"+
						" blade throbs with a dominating green glow that "+
						"holds you captivated.\n"+
						"%^GREEN%^"+ETO->QCN+" lunges at you"+
						" while you're off guard, dealing you a harsh"+
						" blow!");
						tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s"+
						" blade throbs with a dominating green glow that "+
						"is enthralling.\n"+
						"%^GREEN%^"+ETO->QCN+" suddenly strikes at"+
						" "+targ->QCN+" while "+targ->QS+""+
						" is off guard!",({ETO,targ}));
						targ->do_damage("torso",random(10)+6);
						return 1;
					}
					break;
				}
			}
			break;
		}

		case 1: case 4: case 7:{
			switch(talign) {
				case 3: case 6: case 9:{
					if(!random(3)) {
						tell_object(ETO,"%^BOLD%^%^GREEN%^The Baneblade hisses"+
						" as you strike at "+targ->QCN+","+
						" the sound somehow crushes upon your soul.");
						tell_object(targ,"%^BOLD%^%^GREEN%^As "+ETO->QCN+""+
						" strikes at you, "+ETO->QP+""+
						" blade hisses and "+ETO->QS+""+
						" winces in pain.");
						tell_room(environment(ETO),"%^BOLD%^%^GREEN%^As"+
						" "+ETO->QCN+" strikes out at "+targ->QCN+""+
						" the blade hisses and"+
						" "+ETO->QS+" winces in pain.",({targ,ETO}));
						ETO->do_damage("torso",random(10)+5);
						return 1;
					}
					break;
				}

				case 2: case 5: case 8:{
					if(!random(15)) {
						tell_object(ETO,"%^GREEN%^The sword moves"+
						" reluctantly in your hands.");
						tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+"'s"+
						" sword moves slowly, almost as though it"+
						" were being swung underwater.",ETO);
						return 1;
					}
					break;
				}

				case 1: case 4: case 7:{
					if(!random(20)) {
						tell_object(ETO,"%^BOLD%^%^BLACK%^The Baneblade"+
						" begins to burn %^GREEN%^bright green"+
						" %^BOLD%^%^BLACK%^as it strikes "+targ->QCN+","+
						" the flames move along the blade to the hilt,"+
						" burning you as well.");
						tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
						" sword strikes you and bursts into angry "+
						"%^GREEN%^green%^BOLD%^%^BLACK%^"+
						" flames that burn like the nine hells! They"+
						" burn their way down the hilt and seem"+
						" to harm "+ETO->QCN+" as well.");
						tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
						" sword bursts into angry %^GREEN%^green%^BOLD%^%^BLACK%^ "+
						"flames as it strikes "+targ->QCN+","+
						" the flames spread down the hilt and burn"+
						" "+ETO->QCN+" as well.",({ETO,targ}));
						targ->do_damage("torso",random(10)+10);
						ETO->do_damage("torso",random(10)+8);
						return 1;
					}
					break;
				}
			}
		}
	}
}
