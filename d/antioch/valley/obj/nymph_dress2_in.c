//Added a short, flushed out desc and gave lore - also updated the emotes to make it easier to rp, because i know crystal wanted to rewrite them anyway - Cythera 5/05\\
// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
#include <daemons.h>
#include "../valley.h"
inherit "/std/armour";
int FLAG;

object *women;
object *men;
object targman;
object *othermen;

void gender_arrays(object room);
void low_cha();
void mid_cha();
void high_cha();
void dumb_male();

void create()
{
	::create();
	set_name("%^BOLD%^%^WHITE%^White gown%^RESET%^");
	set_id(({"nymph dress","dress","gown","white gown","white dress"}));
	set_obvious_short("%^BOLD%^%^WHITE%^White gown%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Gown of the Lunar %^RED%^"+
		"R%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^RESET%^"+
		"%^CYAN%^b%^BLUE%^o%^BOLD%^%^MAGENTA%^w%^RESET%^");
	set_long(
	"%^BOLD%^%^WHITE%^The gown is heartbreakingly beautiful."+
	" It is long and of the purest white, hemmed in %^YELLOW%^"+
	"gold%^WHITE%^. There"+
	" is a slit going from the bottom of the dress up the middle,"+
	" allowing the wearer to stay cool. The neck line falls a"+
	" tad low for modest human standards, but this is obviously"+
	" the dress of a nymph. It would fit precisely to the form of"+
	" a beautiful woman. The gown shines in the light with"+
	" %^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^"+
	"o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^ hues, adding an"+
	" unearthly magnificence to the beautiful gown.%^RESET%^"
	);
	set_size(2);
	set_property("lore",16);
	set_lore("The Gown of the Lunar Rainbow is one of the rarest"+
		" gowns in the land. Worn by nymphs, the gown was crafted"+
		" to honor the beauty of the rare celestial event, a Lunar "+
		"Rainbow.  The white cloth of the gown is speculated to have"+
		" been woven from beams of moonlight and infused with the "+
		"luster and radiance of a rainbow, giving it a prismatic "+
		"effect.  Because the gown is nymph's dress and a fey creation,"+
		" it is believed that the dress makes the wearer more charming "+
		"and alluring.  The Lunar Rainbow is seen as a joyous omen for "+
		"the fey, a time when Tymora, Selune, and Mielikki smile on the "+
		"fey races, and is the herald of an important and joyous occasion."+
		"  In fey culture, the Lunar Rainbow is also the time when romances"+
		" deepen into life long affairs.");
	set_type("clothing");
	set_limbs(({"torso"}));
	set_ac(0);
	set_property("enchantment",2);
	set_value(500);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_heart_beat(1);
FLAG=0;
}

int wearme()
{
	if(ETO->query_level() < 10) {
		write("This dress is too beautiful for you.");
		return 0;
	}
 if (member_array((string)ETO->query_body_type(), ({ "plump", "well-built", "hardy" ,"stocky", "portly", "stout", "brawny", "massive", "rotund","heavy" }) ) != -1 ){
      write("Your body type simply doesn't fit into this dainty dress.");
      return 0;
   }
	if((string)ETO->query_gender() == "male") {
		tell_object(ETO,"%^BOLD%^%^CYAN%^You put on the white"+
		" gown, it's nice and cool.");
		tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+""+
		" looks rather foolish as he puts on the white gown.",ETO);
		set_item_bonus("charisma",-1);
		return 1;
	}
	if((string)ETO->query_gender() == "female") {
		tell_object(ETO,"%^BOLD%^%^CYAN%^The white gown feels"+
		" very soft as you slip it over your head. It's a bit"+
		" tight against your skin, seeing as how it was made for"+
		" a nymph, but it looks good on you.");
		tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+""+
		" slips the white gown over her head. It fits perfectly"+
		" to her figure and she smiles, looking almost "+
		" angelic.",ETO);
		set_item_bonus("charisma",1);
		return 1;
	}
	else {
		notify_fail("Hmm, you appear to be missing some rather"+
		" vital organs. Had a run in with Bobbit lately?");
		return 0;
	}
}

int removeme()
{
	if((string)ETO->query_gender() == "male") {
		tell_object(ETO,"%^CYAN%^You slowly slip the white"+
		" gown over your head.");
		tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->query_cap_name()+""+
		" seems reluctant to part with his white gown, once"+
		" it's off you realize how feminine it makes him look.",ETO);
		return 1;
	}
	if((string)ETO->query_gender() == "female") {
		tell_object(ETO,"%^CYAN%^You slowly pull the beautiful"+
		" gown over your head, the fabric tickles you slightly"+
		" as you remove it and you can't help but giggle.");
		tell_room(environment(ETO),"%^CYAN%^"+ETO->query_cap_name()+""+
		" slowly pulls the white gown over her head, giggling"+
		" as she teases you with this impromptu strip tease.",ETO);
		return 1;
	}
	else {
		notify_fail("How did a freak like you get into this beautiful dress?? Now you're stuck in it!");
		return 0;
	}
}

void gender_arrays(object room)
{
	object ob;
	object *inv;
	int i;

	if(!TO->query_worn()) return;
	men = ({});
	women = ({});
	inv = filter_array(all_living(room),"is_non_immortal_player",FILTERS_D);
	inv -= ({query_worn()});
	for(i = 0;i<sizeof(inv);i++) {
		if(wizardp(inv[i])) continue;
        if(inv[i]->query_invis()) continue;
		if((string)inv[i]->query_gender() == "male" && interactive(inv[i])) {
			men += ({ inv[i] });
		}
		if((string)inv[i]->query_gender() == "female" && interactive(inv[i])) {
			women += ({ inv[i] });
		}
	}

	if(!sizeof(men)) {
		targman = 0;
		othermen = ({ });
		return;
	}

	targman = men[random(sizeof(men))];
	othermen = men - ({targman});

	return;
}

void heart_beat()
{
	int cha;

	if(!query_worn()) return;
	if(query_worn() != ETO) return;
	if(!interactive(query_worn())) return;
	if(!objectp(TO)) return;
	if(query_worn()->query_invis()) return;
	if(query_worn()->query_bound() || query_worn()->query_unconcious() || query_worn()->query_paralyzed() || query_worn()->query_tripped() || query_worn()->query_gagged()) return;	
	if(random(500)) return;

	gender_arrays(environment(query_worn()));

	cha = ETO->query_stats("charisma");
	
	if((string)ETO->query_gender() == "female") {
		if(sizeof(men) > 0) {
			if(cha < 10) {
				low_cha();
				return;
			}
			if(cha > 9 && cha < 17) {
				mid_cha();
				return;
			}
			else {
				high_cha();
				return;
			}
			return;
		}
		return;
	}
	
	if((string)ETO->query_gender() == "male") {
		dumb_male();
		return;
	}

	else {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" seems to have a few things missing...",ETO);
		return;
	}
}

object *query_men()
{
	return men;
}

object *query_women()
{
	return women;
}

object query_targman()
{
	return targman;
}

object *query_othermen()
{
	return othermen;
}

void low_cha()
{
	int yy;

	yy = random(5)+1;
	if(yy == 1) {
		message("info","%^BOLD%^"+ETO->QCN+" has a stain"+
			" on "+ETO->QP+" gown.",men);
		message("info","%^BOLD%^"+ETO->QCN+" has a stain"+
			" on "+ETO->QP+" gown.",women);
		tell_object(ETO,"%^BOLD%^You notice a stain on your gown.");
		return;
	}
	if(yy == 2) {
		message("info","%^BOLD%^"+ETO->QCN+"'s gown looks as"+
			" if "+ETO->QS+" slept in it.",men);
		message("info","%^BOLD%^"+ETO->QCN+"'s gown looks as"+
			" if "+ETO->QS+" slept in it.",women);
		tell_object(ETO,"%^BOLD%^Your gown is looking a little wrinkled.");
		return;
	}
	if(yy == 3) {
		tell_object(targman,"%^BOLD%^You spy a small hole"+
			" in "+ETO->QCN+"'s gown.");
		message("info","%^BOLD%^"+targman->QCN+" stares at"+
			" a hole near the hem"+
			" of "+ETO->QCN+"'s gown.",othermen);
		tell_object(ETO,"%^BOLD%^"+targman->QCN+" is staring"+
			" at the hole, near the hem, in your gown.");
		return;
	}
	if(yy == 4) {
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" scratches the back"+
			" of "+ETO->QP+" head.",ETO);
		return;
	}
	if(yy == 5) {
		tell_object(targman,"%^BOLD%^"+ETO->QCN+"'s gown looks ill fitted.");
		message("info","%^BOLD%^"+ETO->QCN+" looks ill fitted "+
			"in "+ETO->QP+" gown.",othermen);
		tell_object(ETO,"%^BOLD%^Your gown seems a little ill fitted.");
		return;
	}
	return;
}

void mid_cha()
{
	int yy;

	yy = random(10)+1;
	if(yy == 1) {
		message("info","%^BOLD%^"+ETO->QCN+" looks elegant"+
		" in her gown.",men);
		tell_object(ETO,"%^BOLD%^You feel like a lady in this dress.");
		return;
	}
	if(yy == 2) {
		tell_object(ETO,"%^BOLD%^You feel demure in this lovely gown.");
		tell_object(targman,"%^BOLD%^"+ETO->QCN+" looks almost demure"+
			" in her gown.");
		message("info","%^BOLD%^"+ETO->QCN+" looks almost demure in"+
			" her gown.",othermen);
		message("info","%^BOLD%^"+ETO->QCN+" looks almost demure"+
			" in her gown.",women);
		return 1;
	}
	if(yy == 3) {
		message("info","%^BOLD%^Light reflects off of "+ETO->QCN+"'s gown,"+
			" making her look almost angelic.",othermen);
		message("info","%^BOLD%^"+ETO->QCN+" looks almost angelic"+
			" in her gown.",women);
		tell_object(ETO,"%^BOLD%^The soft gown makes you feel almost angelic.");
		return;
	}
	if(yy == 4) {
		message("info","%^BOLD%^The light shimmers off of"+
			" "+ETO->QCN+"'s gown accentuating her body.",men);
		message("info","%^BOLD%^The light shimmers off of "+
			""+ETO->QCN+"'s gown.",women);
		tell_object(ETO,"%^BOLD%^You feel lovely in this gown.");
		return;
	}
	if(yy == 5) {
		tell_object(targman,"%^BOLD%^The hem "+ETO->QCN+"'s gown"+
			" flutters in a breeze, giving you a glimps at her ankles.");
		message("info","%^BOLD%^"+ETO->QCN+"'s gown flutters in"+
			" the breeze, giving you a glimps of her ankles.",othermen);
		tell_object(ETO,"%^BOLD%^A slight breeze flutters the hem of your gown.");
		return;
	}
	if(yy == 6) {
		tell_object(targman,"%^BOLD%^The %^RESET%^%^RED%^p%^BOLD%^r"+
			"%^RESET%^%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^"+
			"a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
			"%^BOLD%^%^WHITE%^sheen on "+ETO->QCN+"'s gown shifts in hues.");
		message("info","%^BOLD%^The %^RESET%^%^RED%^p%^BOLD%^r%^RESET%^"+
			"%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a"+
			"%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
			"%^BOLD%^%^WHITE%^sheen on "+ETO->QCN+"'s gown shifts"+
			" in hues.",othermen);
		tell_object(ETO,"%^RESET%^%^RED%^P%^BOLD%^r%^RESET%^%^ORANGE%^"+
			"i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a%^BLUE%^t"+
			"%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ "+
			"colors dance across the surface of your gown.");
		return;
	}
	if(yy == 7) {
		message("info","%^BOLD%^"+ETO->QCN+" looks pretty"+
			" in her tight white gown.",men);
		tell_object(ETO,"%^BOLD%^This gown feels as though it were made"+
		" just for you.");
		return;
	}
	if(yy == 8) {
		message("info","%^BOLD%^"+ETO->QCN+"'s gown shines with "+
			"the colors of the %^RED%^r%^RESET%^%^ORANGE%^%^a"+
			"%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^"+
			"o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^.",men);
		message("info",""+ETO->QCN+"'s gown shines with the "+
			"colors of the %^RED%^r%^RESET%^%^ORANGE%^%^a"+
			"%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^"+
			"o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^.",women);
		tell_object(ETO,"%^BOLD%^You smile at the beauty of the world.");
		return;
	}
	if(yy == 9) {
		message("info","%^BOLD%^"+ETO->QCN+"'s gown clings to her body.",men);
		tell_object(ETO,"%^BOLD%^"+targman->QCN+" stares at you.");
		return;
	}
	if(yy == 10) {
		message("info","%^BOLD%^The slit on "+ETO->QCN+"'s gown "+
			"flutters open, offering you a quick peek at her knee.",men);
		return;
	}
	return;
}

void high_cha()
{
	int yy;

	yy = random(12)+1;
	if(yy == 1) {
		message("info","%^BOLD%^"+ETO->QCN+" looks absolutely"+
		" breath-taking in her gown.",men);
		tell_object(ETO,"%^BOLD%^You feel more confident wearing a"+
		" lovely gown like this.");
		return;
	}
	if(yy == 2) {
		tell_object(ETO,"%^BOLD%^This dress fits you like a glove.");
		message("info","%^BOLD%^"+ETO->QCN+"'s gown molds to her body.",othermen);
		tell_object(targman,"%^BOLD%^"+ETO->QCN+"'s gown molds to her body in a tantalizing fashion.");
		return;
	}
	if(yy == 3) {
		message("info","The %^RESET%^%^RED%^p%^BOLD%^r%^RESET%^"+
			"%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^"+
			"a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
			"%^BOLD%^%^WHITE%^ hues of "+ETO->QCN+"'s gown "+
			"dances in a titillating pattern.",men);
		message("info","The %^RESET%^%^RED%^p%^BOLD%^r%^RESET%^"+
			"%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^"+
			"a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
			"%^BOLD%^%^WHITE%^ hues of "+ETO->QCN+"'s gown "+
			"brings out her lovely eyes.",women);
		return 1;
	}
	if(yy == 4) {
		message("info","%^BOLD%^Light shimmers off of "+ETO->QCN+"'s"+
			" gown, emphasizing her breasts.",men);
		message("info","%^BOLD%^Light shimmers off of "+ETO->QCN+"'s"+
			" gown.",women);
		tell_object(ETO,"%^BOLD%^You giggle happily as you admire your"+
			" dress.");
		return;
	}
	if(yy == 5) {
		message("info","%^BOLD%^The slit on "+ETO->QCN+"'s gown "+
			"flutters open briefly,"+
			" giving you a peak at her shapely leg.",men);
		return;
	}
	if(yy == 6) {
		message("info","%^RED%^R%^RESET%^%^ORANGE%^%^a%^YELLOW%^i"+
			"%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w"+
			"%^BOLD%^%^WHITE%^ colors shifts off of the surface"+
			" of "+ETO->QCN+"'s gown,"+
			" bringing out the luster of her hair.",men);
		return;
	}
	if(yy == 7) {
		message("info","%^BOLD%^"+ETO->QCN+" looks"+
		" stunning in her gown.",men);
		tell_object(ETO,"%^BOLD%^"+targman->QCN+" stares"+
		" at you admiringly.");
		return;
	}
	if(yy == 8) {
		message("info","%^BOLD%^The colors of the %^RED%^r"+
			"%^RESET%^%^ORANGE%^%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^"+
			"o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^ dance across the surface"+
			" of "+ETO->QCN+"'s gown in an alluring pattern.",men);
		return;
	}
	if(yy == 9) {
		message("info","%^BOLD%^"+ETO->QCN+" looks breathtaking in her beautiful gown.",men);
	}
	if(yy == 10) {
		message("info","%^BOLD%^"+ETO->QCN+" stands proudly,"+
		" the slit up the front of her dress showing off her"+
		" very lovely legs.",men);
		return;
	}
	if(yy == 11) {
		message("info","%^BOLD%^"+ETO->QCN+"'s gown is blown"+
		" by the wind, giving you a glimpse of her slender legs.",men);
		tell_object(ETO,"%^BOLD%^The wind blows the bottom of your dress"+
		" playfully.");
		return;
	}
        if(yy == 12) {
		tell_object(targman,"%^BOLD%^The %^RESET%^%^RED%^p%^BOLD%^r"+
			"%^RESET%^%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^"+
			"a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
			"%^BOLD%^%^WHITE%^sheen on "+ETO->QCN+"'s gown shifts in hues.");
		message("info","%^BOLD%^The %^RESET%^%^RED%^p%^BOLD%^r%^RESET%^"+
			"%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a"+
			"%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
			"%^BOLD%^%^WHITE%^sheen on "+ETO->QCN+"'s gown shifts"+
			" in hues.",othermen);
		tell_object(ETO,"%^RESET%^%^RED%^P%^BOLD%^r%^RESET%^%^ORANGE%^"+
			"i%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a%^BLUE%^t"+
			"%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ "+
			"colors dance across the surface of your gown.");
		return;
	}
	return;
}

void dumb_male()
{
	int yy;

	yy = random(14)+1;
	if(yy == 1) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" prances around like a little princess in his white gown.",ETO);
		return;
	}
	if(yy == 2) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" tosses his hair over his shoulder.",ETO);
		return;
	}
	if(yy == 3) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" files his nails.",ETO);
		return;
	}
	if(yy == 4) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" gets teary eyed and begins to cry like a young maiden.",ETO);
		return;
	}
	if(yy == 5) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" has smoothly shaved legs, he invites you to feel them.",ETO);
		return;
	}
	if(yy == 6) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" sprays a little perfume on himself and giggles.",ETO);
		return;
	}
	if(yy == 7) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" adjusts his dress to show off his chest more.",ETO);
		return;
	}
	if(yy == 8) {
		tell_room(environment(ETO),"%^MAGENTA%^"+ETO->query_cap_name()+""+
		" says%^RESET%^:  Don't I just look fabulous in white?",ETO);
		return;
	}
	if(yy == 9) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+" bats his"+
			" eyes at you.");
			message("info",""+ETO->query_cap_name()+" bats his eyes"+
			" at "+targman->query_cap_name()+".",othermen);
			message("info",""+ETO->query_cap_name()+" bats his eyes"+
			" at "+targman->query_cap_name()+".",women);
			return;
			}
		return;
	}
	if(yy == 10) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+" tickles"+
			" you, laughing delightedly.");
			message("info",""+ETO->query_cap_name()+" tickles"+
			" "+targman->query_cap_name()+", laughing delightedly.",othermen);
			message("info",""+ETO->query_cap_name()+" tickles"+
			" "+targman->query_cap_name()+", laughing delightedly.",women);
			return;
		}
		return;
	}
	if(yy == 11) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+" holds"+
			" hands with you.");
			message("info",""+ETO->query_cap_name()+" holds hands"+
			" with "+targman->query_cap_name()+".",othermen);
			return;
		}
	return;
	}
	if(yy == 12) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+""+
			" casually tosses his arm over your shoulder and grins.");
			message("info",""+ETO->query_cap_name()+" casually"+
			" tosses his arm over "+targman->query_cap_name()+"'s"+
			" shoulder and grins.",othermen);
			message("info",""+ETO->query_cap_name()+" casually"+
			" tosses his arm over "+targman->query_cap_name()+"'s"+
			" shoulder and grins.",women);
			return;
		}
	return;
	}
	if(yy == 13) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" shakes his thang!",ETO);
		return;
	}
	if(yy == 14) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+""+
			" frenches you deeply.");
			message("info",""+ETO->query_cap_name()+""+
			" frenches "+targman->query_cap_name()+" deeply.",othermen);
			message("info",""+ETO->query_cap_name()+" frenches"+
			" "+targman->query_cap_name()+" deeply.",women);
			return;
		}
	return;
	}
	return;
}
