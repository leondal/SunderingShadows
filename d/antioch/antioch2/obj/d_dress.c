#include <std.h>
#include "../antioch.h"

#define SHADES ({"%^BOLD%^%^WHITE%^light%^RESET%^",\
"%^BOLD%^%^BLACK%^dark%^RESET%^",\
"%^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^e%^RESET%^p",\
"%^BOLD%^%^WHITE%^p%^RESET%^a%^BOLD%^l%^RESET%^e",\
"%^BOLD%^%^WHITE%^bright%^RESET%^"})

#define COLORS ({"%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^",\
"%^RESET%^%^ORANGE%^brown%^RESET%^",\
"%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^",\
"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^lu%^BOLD%^e%^RESET%^",\
"%^YELLOW%^yellow%^RESET%^",\
"%^RESET%^%^MAGENTA%^purple%^RESET%^"})

inherit DAEMON;

int i, j, val;
string str, FABRIC, STYLE;

void create()
{
	::create();
}

void create_dress(object obj)
{
   j = random(sizeof(COLORS));
	str = COLORS[j];
   i = random(sizeof(SHADES));
	STYLE = SHADES[i];
	if(str == "black" || str == "white") {
		STYLE = "lovely";
	}

	val = random(40);
	switch(val) {
		case 0..10:
			FABRIC = "cotton";
			obj->set_long("This is a pretty summer dress that is made of a"+
			" light cotton material and reaches to just about the knee. It has"+
			" been dyed a "+STYLE+" "+str+" shade. This dress is well suited for"+
			" around the house or day to day activities.");
			break;
		case 11..20:
			FABRIC = "woolen";
			obj->set_long("This is a dress that has been hand made from fine"+
			" wool. It will keep the wearer warm during the cold months of"+
			" winter. It has been dyed a "+STYLE+" "+str+" shade and comes down"+
			" to just above the knee.");
			break;
		case 21..30:
			FABRIC = "satin";
			obj->set_long("This is a beautiful satin dress that reaches down"+
			" to the floor. It has long sleeves and has a scooping neckline."+
			" This is the type of dress that one would wear out to dinner"+
			" parties or special occassions. It has been dyed a "+STYLE+" "+str+""+
			" shade and very smooth to the touch.");
			break;
		case 31..40:
			FABRIC = "silk";
			obj->set_long("This is a gorgeous silk dress that has been cut"+
			" daringly short. It has been dyed a "+STYLE+" "+str+" shade and"+
			" has a tendency to cling to the wearer's body. It is hand made"+
			" from pure silk and is incredibly soft to the touch.");
			break;
	}
	obj->set_value(val+11);
	obj->set_name("dress");
	obj->set_id(({"dress","clothing","r_dress","mina_clothing",""+str+" dress",""+FABRIC+" dress",""+str+" "+FABRIC+" dress"}));
	obj->set_short("A "+str+" "+FABRIC+" dress");
	obj->set_type("clothing");
	obj->set_limbs(({"torso"}));
	obj->set_ac(0);
	obj->set_size(2);
	obj->set_weight(5);
}
