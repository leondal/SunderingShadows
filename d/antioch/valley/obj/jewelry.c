//Added color and changed over to rings instead of clothing - Cythera 4/05\\
#include <std.h>
#include "../valley.h"

#define NAMES ({"bracelet","necklace","earring","ring","brooch","crown","diadem","armband"})

inherit "/std/armour";

int i,j, val;
string str, TYPE;
int broken = 0;

void create()
{
	::create();
	val = random(500);
	switch(val) {
		case 0..100:
			TYPE = "%^ORANGE%^bronze%^RESET%^";
			break;
		case 101..200:
			TYPE = "%^BOLD%^%^WHITE%^silver%^RESET%^";
			break;
		case 201..300:
			TYPE = "%^BOLD%^%^CYAN%^jeweled%^RESET%^";
			break;
		case 301..400:
			TYPE = "%^YELLOW%^gold%^RESET%^";
			break;
		case 401..500:
			TYPE = "%^BOLD%^%^WHITE%^platinum%^RESET%^";
			break;
		}
	j=random(8);
	str= NAMES[j];
	set_name("jewelry");
	set_id(({"jewelry",str,capitalize(str)}));
	set_weight(5);
	if(val < 50) {
		set_value(50);
	}
	else {
		set_value(val);
	}
	set_short("A "+TYPE+" "+str+"");
	set_long(
	"This is a "+TYPE+" "+str+" of fine quality. It is too"+
	" delicate to wear, but would probably fetch a nice price."
	);
	set_size(random(3)+1);
	set_type("ring");
	set_wear((:TO, "wear_jewelry":));
	if(str == "necklace") {
		set_limbs(({"neck"}));
		return 1;
	}
	if(str == "crown") {
		set_limbs(({"head"}));
		return 1;
	}
	if(str == "bracelet") {
		set_limbs(({"right arm","left arm"}));
		return 1;
	}
	if(str == "ring") {
		set_limbs(({"right hand","left hand"}));
		return 1;
	}
	if(str == "diadem") {
		set_limbs(({"head"}));
		return 1;
	}
	if(str == "armband") {
		set_limbs(({"right arm","left arm"}));
		return 1;
	}
	if(str == "brooch") {
		set_limbs(({"torso"}));
		return 1;
	}
	if(str == "earring") {
		set_limbs(({"head"}));
		return 1;
	}
}

int wear_jewelry()
{
	if(broken) {
		return 1;
	}
	if(!random(8)) {
		write("As you try to put the delicate piece of jewelry"+ 		" on you accidentally break it.");
		tell_room(environment(ETO),
		"As "+ETO->query_cap_name()+" tries to wear the delicate"+
		" piece of jewelry "+ETO->query_subjective()+" breaks"+
		" it.", ETO);
		set_value(0);
		set_short("A broken "+TYPE+" "+str+"");
		set_long("This was a nice "+TYPE+" "+str+", but it is"+ 		" now broken and worthless.");
		broken = 1;
		return 1;
	}
	else {
		return 1;
	}
}
