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
void goddess();
void dumb_male();

void create()
{
	::create();
	set_name("%^BOLD%^%^BLACK%^Black velvet dress%^RESET%^");
	set_id(({"dress","nymph dress","black dress","velvet dress", "black velvet dress"}));
	set_obvious_short("%^BOLD%^%^BLACK%^Black velvet dress%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^Dress of A %^WHITE%^S%^RESET%^t%^BOLD%^"+
	"a%^RESET%^r%^BOLD%^r%^RESET%^y%^BOLD%^%^BLACK%^ Night's Rapture%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^The dress is made of black velvet that"+
		" is incredibly soft to the touch, your fingers actually "+
		"ache when you let it go.  It is exquisitely made and "+
		"you can't even find any seams on it.  The strapless "+
		"gown is tailored to fit tight against the torso, and"+
		" flows smoothly to the down.  The hem of the dress "+
		"rises up in the front in a crescent shape before "+
		"dipping back down in the back to form a small train."+
		"  The shape of the hem provides a freedom in movement."+
		"  The inside of the dress is lined in the softest silk"+
		" your fingers have ever caressed.  The dress does seem"+
		" to be a little on the small side but it would be very"+
		" flattering on anyone who actually fit into it.  Shimmering"+
		" %^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r"+
		"%^BOLD%^%^BLACK%^ sparkles dust the soft fabric, giving an "+
		"illusion of a clear star cast night.%^RESET%^\n");
	set_value(3500);
	set_weight(5);
	set_size(2);
	set_limbs(({"torso"}));
//        set_ac(1);
	set_property("lore",16);
	set_lore("The Dress of A Starry Night's Rapture was"+
		" created to honor the beauty of Midsummer Night's"+
		" Eve, a sacred and wild time for the fey.  The black"+
		" velvet of the dress represents the dark heavens during"+
		" this magical time of the year.  It is speculated that "+
		"the silver dust that shimmers on the gown is not actually"+
		" silver, but bits of starlight magically grafted onto the "+
		"gown.  The fey find Midsummer Night's Eve a scared day where"+
		" all fey come together to sing, dance, and enjoy in wild revels"+
		" that would make most human folk blush.  Midsummer Night's Eve"+
		" is seen as a time where pledges are made, friendships are "+
		"renewed and love and romance reign.  Nymphs are given the honor"+
		" of wearing one of these mystical and special fey dresses, some"+
		" say enhancing their comely allure even further.");
        set_property("enchantment",2);
	set_type("clothing");
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_heart_beat(1);
FLAG=0;
}

int wearme()
{
	if(ETO->query_level() < 10) {
		write("You are not ready for a dress this lovely.");
		return 0;
	}
  if (member_array((string)ETO->query_body_type(), ({ "plump", "well-built", "hardy" ,"stocky", "portly", "stout", "brawny", "massive", "rotund","heavy" }) ) != -1 ){
      write("Your body type simply doesn't fit into this dainty dress.");
      return 0;
   }
	if((string)ETO->query_gender() == "male") {
		tell_object(ETO,"%^BOLD%^%^RED%^You slip into the black"+
		" velvet dress.");
		tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+""+
		" akwardly works his way into the black velvet dress, getting"+
		" in touch with his feminine side.",ETO);
		set_item_bonus("charisma",-1);
		return 1;
	}
	if((string)ETO->query_gender() == "female") {
		tell_object(ETO,"%^BOLD%^%^RED%^You slip on the black"+
		" velvet dress, it feels wonderful to the touch and seems"+
		" to magically fit itself to your body, showing off"+
		" every curve.");
		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
		" slips slowly into her black velvet dress, relishing"+
		" the feel of it against her skin. The dress seems to be"+
		" made just for her, showing off every curve of her body.",ETO);
		set_item_bonus("charisma",1);
		return 1;
	}
	else {
		notify_fail("There seems to be something wrong with you,"+
		" go call for help before it's too late!");
		return 0;
	}
}

int removeme()
{
	if((string)ETO->query_gender() == "male") {
		tell_object(ETO,"%^MAGENTA%^You slip out of the black"+
		" velvet dress.");
		tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+""+
		" slowly takes off his black velvet dress. You have to"+
		" wonder about the type of man who actually wears such"+
		" a thing...",ETO);
		return 1;
	}
	else {
		tell_object(ETO,"%^MAGENTA%^You slowly remove the"+
		" black velvet dress, already you miss the feel of the"+
		" crushed velvet against your skin.");
		tell_room(environment(ETO),"%^MAGENTA%^"+ETO->query_cap_name()+""+
		" very slowly slides the black velvet dress off of her"+
		" shoulders, letting it drop to the floor with a"+
		" wistful expression.",ETO);
		return 1;
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
			if(cha < 9) {
				low_cha();
				return;
			}
			if(cha > 10 && cha < 15) {
				mid_cha();
				return;
			}
			if(cha > 14 && cha < 17) {
				high_cha();
				return;
			}
			else {
				goddess();
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
		" is a freak.",ETO);
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
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" has a"+
			" stain on "+ETO->QP+" gown.",men);
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" has a"+
			" stain on "+ETO->QP+" gown.",women);
		tell_object(ETO,"%^BOLD%^%^BLACK%^You notice a stain on your gown.");
		return;
	}
	if(yy == 2) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s gown "+
			"looks as if "+ETO->QS+" slept in it.",men);
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s gown "+
			"looks as if "+ETO->QS+" slept in it.",women);
		tell_object(ETO,"%^BOLD%^%^BLACK%^Your gown is looking a little wrinkled.");
		return;
	}
	if(yy == 3) {
		tell_object(targman,"%^BOLD%^%^BLACK%^You spy a small hole"+
			" in "+ETO->QCN+"'s gown.");
		message("info","%^BOLD%^%^BLACK%^"+targman->QCN+" stares"+
			" at a hole near the hem"+
			" of "+ETO->QCN+"'s gown.",othermen);
		tell_object(ETO,"%^BOLD%^%^BLACK%^"+targman->QCN+" is "+
			"staring at the hole, near"+
			" the hem, in your gown.");
		return;
	}
	if(yy == 4) {
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" "+
			"scratches the back"+
			" of "+ETO->QP+" head.",ETO);
		return;
	}
	if(yy == 5) {
		tell_object(targman,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s gown"+
			" looks ill fitted.");
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" looks ill fitted "+
			"in "+ETO->QP+" gown.",othermen);
		tell_object(ETO,"%^BOLD%^%^BLACK%^Your gown seems a little ill fitted.");
		return;
	}
}

void mid_cha()
{
	int yy;

	yy = random(7)+1;
	if(yy == 1) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" looks"+
			" pretty in her black velvet dress.",men);
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" looks"+
			" pretty in her black velvet dress.",women);
		tell_object(ETO,"%^BOLD%^%^BLACK%^The feel of the velvety fabric"+
		" against your skin is wonderful.");
		return;
	}
	if(yy == 2) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress"+
			" twinkle like stars.",men);
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress twinkle like stars.",women);
		tell_object(ETO,"%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on your dress twinkle like stars.");
		return;
	}
	if(yy == 3) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress"+
			" twinkle in a random pattern.",men);
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress"+
			" twinkle in a random pattern.",women);
		return;
	}
	if(yy == 4) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s dress fits her"+
			" nicely.",men);
		return;
	}
	if(yy == 5) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" casually"+
		" tosses her hair over her shoulder and smiles at"+
		" you.",men);
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" tosses her"+
		" hair over her shoulder.",women);
		tell_object(ETO,"%^BOLD%^%^BLACK%^You toss your hair over your shoulder"+
		" so that it doesn't block everyone's view of this"+
		" gorgeous dress.");
		return;
	}
	if(yy == 6) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles in "+ETO->QCN+"'s dress twinkle softly.",men);
	}
	if(yy == 7) {
		message("info","%^BOLD%^%^BLACK%^The hem of "+ETO->QCN+"'s "+
			"dress flutters open, giving you a peek at her ankles.",men);
		return;
	}
}

void high_cha()
{
	int yy;
	
	yy == random(10)+1;
	if(yy == 1) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" looks"+
			" beautiful in her black velvet dress.",men);
		return;
	}
	if(yy == 2) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress twinkle like stars.",men);
		return;
	}
	if(yy == 3) {
		message("info","%^BOLD%^%^BLACK%^The hem of "+ETO->QCN+"'s dress"+
			" flutters open,"+
			" giving you a peek at her ankles.",men);
		return;
	}
	if(yy == 4) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
 			"sparkles on "+ETO->QCN+"'s dress"+
			" twinkle in a pleasing pattern.",men);
		return;
	}
	if(yy == 5) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" tosses her"+
		" beautiful hair over her shoulders.",men);
		return;
	}
	if(yy == 6) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s dress "+
			"shapes itself to her body.",men);
		return;
	}
	if(yy == 7) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s dress brings out the"+
			" luster of her hair.",men);
		return;
	}
	if(yy == 8) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress"+
			" emphasizes her slender form.",men);
		return;
	}
	if(yy == 9) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s gown twinkle"+
			" in a random pattern.",men);
		return;
	}
	if(yy == 10) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s dress"+
			" brings out her eyes.",men);
		return;
	}
}

void goddess()
{
	int yy;

	yy = random(14)+1;
	if(yy == 1) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s gown"+
			"twinkles softly.",men);
		return;
	}
	if(yy == 2) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s gown molds to her body.",men);
		return;
	}
	if(yy == 3) {
		message("info","%^BOLD%^%^BLACK%^Light reflects off of the velvet of "+ETO->QCN+"'s gown,"+
			" highlighting her lovely figure.",men);
		return;
	}
	if(yy == 4) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s gown twinkles softly, "+
			"emphasizing her breasts.",men);
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s gown twinkles softly.",women);
		return;
	}
	if(yy == 6) {
		message("info","%^BOLD%^%^BLACK%^The hem of "+ETO->QCN+"'s rises up,"+
			" giving you a peek at her ankles.",men);
		return;
	}
	if(yy == 5) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" closes her"+
		" eyes and runs her fingers through her hair,"+
		" showing off her slender neck and her bare shoulders.",men);
		return;
	}
	if(yy == 7) {
		tell_object(targman,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s dress "+
			"twinkles in an alluring pattern.");
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s dress"+
			" twinkles in an alluring pattern.",othermen);
		return;
	}
	if(yy == 8) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+"'s eyes "+
			"twinkle in the soft light that shines off her dress.",men);
		return;
	}
	if(yy == 9) {
		message("info","%^BOLD%^%^BLACK%^The velvet clings to "+ETO->QCN+"'s"+
                        " body in a tantalizing manner.",men);
		return;
	}
	if(yy == 10) {
		tell_object(targman,"%^BOLD%^%^BLACK%^The hem of "+ETO->QCN+"'s dress rides"+
			" up a bit, giving you a glimps of her slender legs .");
		message("info","%^BOLD%^%^BLACK%^The hem of "+ETO->QCN+"'s dress rides up a bit"+
			", giving you a glimps of her slender legs.",othermen);
		return;
	}
	if(yy == 11) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i%^BOLD%^"+
			"l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^y%^BOLD%^%^BLACK%^ "+
			"twinkles on "+ETO->QCN+"'s "+
			"dress brings out the luster in her hair.",men);
		return;
	}
	if(yy == 12) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" runs her hands over"+
		" her wonderful body, caressing the soft velvet of the dress.",men);
		tell_object(ETO,"%^BOLD%^%^BLACK%^This crushed velvet is the softest"+
		" most wonderful thing you've touched in your entire"+
		" life, you can't get over how great it feels.");
		return;
	}
	if(yy == 13) {
		message("info","%^BOLD%^%^BLACK%^"+ETO->QCN+" looks simply divine"+
			" in her black velvet gown.",men);
		return;
	}
	if(yy == 14) {
		message("info","%^BOLD%^%^BLACK%^The %^WHITE%^s%^RESET%^i"+
			"%^BOLD%^l%^RESET%^v%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
			" sparkles on "+ETO->QCN+"'s gown twinkle,"+
			" drawing attention to how the dress molds to her body.",men);
		return;
	}
}

void dumb_male()
{
	int yy;

	yy = random(14)+1;
	if(yy == 1) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" grins broadly and admires his dress.",ETO);
		return;
	}
	if(yy == 2) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" dances around merrily in his pretty black velvet dress.",ETO);
		return;
	}
	if(yy == 3) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" laughs like a woman.",ETO);
		return;
	}
	if(yy == 4) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" takes out a brush and begins to meticulously brush"+
		" his hair.",ETO);
		return;
	}
	if(yy == 5) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" starts applying makeup, getting ready for a night"+
		" on the town.",ETO);
		return;
	}
	if(yy == 6) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" giggles like a little girl.",ETO);
		return;
	}
	if(yy == 7) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" starts putting on some tights and black high heels to"+
		" match his dress.",ETO);
		return;
	}
	if(yy == 8) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" has his dress tucked in to his tights at the back.",ETO);
		return;
	}
	if(yy == 9) {
		if(sizeof(men) > 0) {
			message("info",""+ETO->query_cap_name()+""+
			" winks lewdly and proceeds to hit on you.",men);
			message("info",""+ETO->query_cap_name()+" hits on"+
			" "+targman->query_cap_name()+".",women);
			return;
		}
		return;
	}
	if(yy == 10) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" sucks on his thumb.",ETO);
		return;
	}
	if(yy == 11) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+" sits"+
			" down in your lap.");
			message("info",""+ETO->query_cap_name()+" sits in"+
			" "+targman->query_cap_name()+"'s lap.",othermen);
			message("info",""+ETO->query_cap_name()+" sits in"+
			" "+targman->query_cap_name()+"'s lap.",women);
			return;
		}
		return;
	}
	if(yy == 12) {
		if(sizeof(men) > 0) {
			tell_object(targman,""+ETO->query_cap_name()+" pinches"+
			" your butt!");
			message("info",""+ETO->query_cap_name()+" pinches"+
			" "+targman->query_cap_name()+"'s butt!",othermen);
			message("info",""+ETO->query_cap_name()+" pinches"+
			" "+targman->query_cap_name()+"'s butt!",women);
			return;
		}
		return;
	}
	if(yy == 13) {
		if(sizeof(men) > 0) {
			tell_object(targman,"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+""+
			" whispers to you: %^RESET%^Do I look hot or what?");
			message("info","%^CYAN%^"+ETO->query_cap_name()+""+
			" whispers something to "+targman->query_cap_name()+".",othermen);
			message("info","%^CYAN%^"+ETO->query_cap_name()+""+
			" whispers something to "+targman->query_cap_name()+".",women);
			return;
		}
		return;
	}
	if(yy == 14) {
		tell_room(environment(ETO),""+ETO->query_cap_name()+""+
		" begins to do a horrible strip tease just for you.",ETO);
		return;
	}
}

