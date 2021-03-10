//Added Lore- Cythera
#include <std.h>
#include "../valley.h"
inherit OBJECT;

mapping aggressive;
object *monsters;

void create()
{
	::create();
	set_name("reed pipes");
	set_id(({"pipes","satyr pipes","reed pipes"}));
	set_short("Reed pipes");
	set_long("%^ORANGE%^Golden reeds have been bound"+
		" together with %^GREEN%^green ivy%^ORANGE%^."+
		"  The reeds are cut in a descending fashion,"+
		" starting no bigger than a fingers length long"+
		" and ending larger than ones hand.  A series of"+
		" holes are drilled into the hollow pipes, each"+
		" reed having one.  The holes allows for one to"+
		" control the pitch and melody produced when air"+
		" is blown into the pipes.  The pipes carry a "+
		"rustic quality to them.  Only a master bard could"+
		" hope to play such a fine instrument."
	);
	set_weight(5);
	set_value(600);
	set_lore("The Satyrs Pipes are a rustic instrument that "+
		"many of the more 'civilized' folk frown upon.  "+
		"Though the instrument quite popular with the faeries"+
		" and other fey creatures.  The satyrs use the pipes to"+
		" produce their wild and chaotic songs that lead the other"+
		" fey folk into wild revels.  Given their lusty nature and "+
		"their healthy appetite for food, wine, and music, the satyr"+
		" is often idolized and looked up to by many entertainers and"+
		" bards.  There are rumors of the satyrs being able to play a "+
		"melody on these pipes that makes it hard for one to forget "+
		"the %^RED%^charm%^RESET%^ing tune.");
	set_property("lore",15);
}
void init()
{
	::init();
	add_action("charm","charm");
	add_action("play","play");
}

int charm(string str)
{
	string what;
	int save, roll;
	object *inven,*living_items;
	int i, j, who, align;
	string file;

	inven = ({});
	living_items = ({});
	monsters = ({});
	aggressive = ([]);

	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}

	if(!TP->is_class("bard")) {
		notify_fail("You must be a bard to use these pipes.");
		return 0;
	}

	if(!str) return 0;
	align = TP->query_alignment();
	if(align == 1 || align == 3 || align == 7 || align == 9) {
		notify_fail("You cannot use your bard skills unless you are of a neutral alignment\n");
		return 0;
	}

	if(sscanf(str, "with %s",what) != 1) {
		notify_fail("Usage : charm with pipes\n\n");
		return 0;
	}

	if(what != "pipes") {
		notify_fail("You need to use the pipes.\n");
		return 0;
	}

	tell_room(environment(ETO), ""+ETO->query_cap_name()+" plays"+
	" an enchanting melody on "+ETO->query_possessive()+" pipes.",ETO);
	tell_object(ETO,"You play an enchanting melody on your pipes.");

	inven = all_inventory(environment(TP));
	if(!inven) {
		notify_fail("You really should try doing that to someone.\n");
		return 0;
	}
	i = sizeof(inven);

	while(i--)
		if(living(inven[i]) == 1)
			living_items+= ({ inven[i] });

				if(!living_items) {
					notify_fail("Those rocks aren't listening.\n");
					return 0;
				}

			j = sizeof(living_items);

		while(j--) {
			file = file_name(living_items[j]);
				if(file[0..8] != "/std/user") {
					monsters += ({living_items[j]});
				}
		}

	for(i=0;i<sizeof(monsters);i++) {
		save = "daemon/saving_d"->return_throw("paralyzation_poison_death",(string)monsters[i]->query_class(),(int)monsters[i]->query_level());
		save = save + (((int)TP->query_level())/3);
		save += 3;
		roll = random(19)+1;
		if(roll < save) {
			monsters[i]->set_charmed(1);
			aggressive[monsters[i]]= monsters[i]->query("aggressive");
			monsters[i]->set_("aggressive",3);
		}
		else {
			monsters[i]->set_charmed(-1);
			aggressive[monsters[i]]= monsters[i]->query("aggressive");
			monsters[i]->set("aggressive",20);
		}
	}

	call_out("return_agg",20);
	return 1;
}

void return_agg() {
	int i;

	for(i=0;i<sizeof(monsters);i++) {
		monsters[i]->set("aggressive",aggressive[monsters[i]]);
	}
}

void play(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(str != "pipes") {
		notify_fail("Uh, what exactly are you wanting to play with?");
		return 0;
	}
	if(!TP->is_class("bard")) {
		notify_fail("You do not have the skill to play such an"+
		" instrument.");
		return 0;
	}
	if(!random(6)) {
		tell_object(ETO,"You wet your lips and put them to the pipes.\n"+
		"As you start to play you are compelled by some force to"+
		" begin a rather haunting tune.\n\n"+
		"%^BOLD%^A ghostly feminine voice accompanies your song,"+
		" her notes full of sorrow and tears unshed.\n%^RESET%^"+
		"The forest once was bright and clear in %^YELLOW%^sunny"+
		" %^GREEN%^Moonstone Vale%^RESET%^,\n"+
		"Then wings of %^BOLD%^%^BLACK%^blackness%^RESET%^ swoop-ed"+
		" down and darkness did prevail.\n"+
		"My husband and my babe they took, to death's door they"+
		" did deliver,\n"+
		"And now I sing my %^BOLD%^%^BLUE%^lonesome%^RESET%^ heart"+
		" from the bottom of the river.\n");
		tell_room(environment(ETO),""+ETO->query_cap_name()+" wets"+
		" "+ETO->query_possessive()+" lips and presses them to the"+
		" pipes.\n"+
		"%^BOLD%^A haunting melody is played through the pipes,"+
		" eerily beautiful and utterly enchanting. It almost"+
		" seems like you can hear a soft feminine voice singing"+
		" along with the tune.\n",ETO);
		return 1;
	}
	else {
		tell_object(ETO,"You wet your lips and put them to the pipes.\n"+
		"%^BOLD%^%^CYAN%^You play a gentle melody on the reed pipes.\n");
		tell_room(environment(ETO),""+ETO->query_cap_name()+" wets"+
		" "+ETO->query_possessive()+" lips and presses them to the"+
		" pipes.\n"+
		"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" plays a gentle"+
		" melody on "+ETO->query_possessive()+" reed pipes and"+
		" you feel quite relaxed.",ETO);
		return 1;
	}
}

int is_instrument(){return 1;}

string query_prof_type() { return "instrument"; }