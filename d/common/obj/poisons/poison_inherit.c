#include <std.h>
#include <magic.h>
#include "poison.h"
#define VALID_METHODS ({"contact", "injury", "ingested", "inhaled"})

inherit OBJECT;

int PoisonDuration, PoisonDelay, AllowsSave, PoisonDC, NumberEffects;
int PoisonDoses, PoisonBaseValue;
string PoisonName, PoisonSave, PoisonDamageType, PoisonDeliveryMethod;
string PoisonInfo, PoisonTrueInfo;

string *PoisonEffectType;
int *PoisonDice, *PoisonNumDice;

void create()
{
	::create();
	set_id(({"poison_vial_object_xxx", "poison", "vial"}));
	PoisonDuration = ROUND_LENGTH * 75;
	PoisonDelay = ROUND_LENGTH * 5;
	AllowsSave = 1;
	//PoisonDC here mostly only affects players using poison
	//a monster applied poison has a DC of 10 + half it's level - Saide
	PoisonDC = 10;
	NumberEffects = 2;
	PoisonEffectType = ({"damage"});
	PoisonSave = "fort";
	PoisonName = "venom";
	PoisonDice = ({1});
	PoisonNumDice = ({2});
	PoisonBaseValue = 300;
	PoisonDamageType = "negative energy";
	PoisonDoses = 1 + random(3);
	PoisonDeliveryMethod = "injury";
	PoisonInfo = "This is a potent poison.";
	PoisonTrueInfo = "This is a potent poison.";
	set_long((:TO, "MyLong":));
}

string MyLong() 
{
	return "%^BOLD%^%^GREEN%^This vial is filled with "+TO->query_poison_name()+
	" poison. This particular poison is a "+TO->query_delivery_method() + " poison." + 
	" The liquid inside the vial bubbles rapidly and you believe the liquid might "+
	"be slightly unstable at best. The vial itself is quite durable and very thick, "+
	"it would not be easy to break. A strange and bitter odor is given off by the "+
	"vial itself, as the liquid inside is mostly odorless. "+
	"You can %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^check%^BOLD%^%^WHITE%^>"+
	"%^BOLD%^%^GREEN%^ it to see how many uses are left.%^RESET%^";
}

int query_value()
{
	return (PoisonBaseValue * PoisonDoses) + ::query_value();
}

int query_poison_base_value() { return PoisonBaseValue; }
int query_poison_doses() { return PoisonDoses; }
int query_duration() { return PoisonDuration; }
int query_delay(int WhichEffect) 
{ 
	if(WhichEffect == 1) return 0;	
	return PoisonDelay; 
}

int query_poison_damage(int which) 
{ 
	if(which < 1) which = 1;
	if(which > sizeof(PoisonNumDice)) which = sizeof(PoisonNumDice);
	return roll_dice(PoisonNumDice[which-1], PoisonDice[which-1]); 
}
int query_save_allowed(int WhichEffect) { return AllowsSave; }
int query_poison_dc(int WhichEffect) { return PoisonDC; }
int query_number_of_effects() { return NumberEffects; }
int is_poison() { return 1; }
string query_effect_type(int WhichEffect) 
{ 
	if(WhichEffect < 1) WhichEffect = 1;
	if(WhichEffect > sizeof(PoisonEffectType)) WhichEffect = sizeof(PoisonEffectType);
	return PoisonEffectType[WhichEffect-1]; 
}
string query_poison_name() { return PoisonName; }
string query_saving_throw(int WhichEffect) { return PoisonSave; }
string query_delivery_method() { return PoisonDeliveryMethod; }
string query_poison_info() { return PoisonInfo; }
string query_poison_true_info() { return PoisonTrueInfo; }
string query_poison_damage_type() { return PoisonDamageType; }
//what any player will see when they 
//review the poisons affecting them
void set_poison_info(string str) { PoisonInfo = str; }
void set_true_poison_info(string str) { PoisonTrueInfo = str; } 


void set_delivery_method(string str)
{
	if(member_array(str, VALID_METHODS) == -1) PoisonDeliveryMethod = "injury";
	PoisonDeliveryMethod = str;
}
void set_poison_doses(int x)
{
	PoisonDoses = x;
	if(!PoisonDoses) TO->remove();
}

void set_poison_dc(int x)
{
	if(x < 10) x = 10;
	if(x > 80) x = 80;
	PoisonDC = x;
}
void set_save_allowed(int x)
{
	AllowsSave = x;
}

void set_duration(int x) 
{
	PoisonDuration = x;
}

void set_delay(int x) 
{
	PoisonDelay = x;
}

void set_saving_throw(string type)
{
	PoisonSave = type;
}

void set_poison_name(string name)
{
	PoisonName = name;
	TO->set_short("%^BOLD%^%^BLACK%^A vial of %^BOLD%^%^GREEN%^"+TO->query_poison_name()+
	"%^BOLD%^%^BLACK%^ poison%^RESET%^");
	TO->set_name("a vial of "+PoisonName);
}

void set_poison_dice(mixed x)
{
	if(intp(x)) PoisonDice = ({x});
	else PoisonDice = x;
}

void set_poison_num_dice(mixed x)
{
	if(intp(x)) PoisonNumDice = ({x});
	else PoisonNumDice = x;
}

void set_number_of_effects(int x)
{
	NumberEffects = x;
}

void set_poison_effect_type(string *type)
{
	if(!type) return;
	if(stringp(type)) type = ({type});
	PoisonEffectType = type;
}

void set_poison_base_value(int x)
{
	PoisonBaseValue = x;
}

int PoisonSave(object vic, int DC, string MySave)
{
	int flag = 0;
	if(!DC) DC = PoisonDC;
	if(!objectp(vic)) return 0;
	if(!AllowsSave) return 0;
	switch(MySave)
	{
		case "fort":
			flag = vic->fort_save(DC);
			break;
		case "reflex":
			flag = vic->reflex_save(DC);
			break;
		case "will":
			flag = vic->will_save(DC);
			break;
	}
	return flag;
}

//pretty much the main poison function
//applies effects here 
//WhichEffect 1 = the primary effect, 2 = secondary, 3 and so on
//equals other ongoing effects - DC is the 
//Difficulty to beat the poison and avoid the affect
//this should return 0 for no effect 

int ProcessEffect(object vic, int WhichEffect, int DC)
{
	int dam;
	if(!objectp(TO)) return 0;
	if(!objectp(vic)) return 0;
	dam = TO->query_poison_damage(WhichEffect);
	if((int)TO->PoisonSave(vic, DC, TO->query_saving_throw(WhichEffect)))
	{
		TO->base_message(vic, 1, WhichEffect);		
		return 0;			
	}
	TO->base_message(vic, 0, WhichEffect);	
	if((string)TO->query_effect_type(WhichEffect) == "life")
	{
		vic->cause_typed_damage(vic,vic->return_target_limb(),dam,(string)TO->query_poison_damage_type());		
	}
	return dam;	
}	

//Basically the message players receive when a poison wears off - Saide
int end_effect(object vic)
{
	if(!objectp(vic)) return 0;
	if(!vic->query_invis())
	{
		if(objectp(environment(vic))) 
		{
			tell_room(environment(vic), vic->QCN+" %^BOLD%^%^GREEN%^suddenly "+
			"looks better!%^RESET%^", vic);
		}
	}
	tell_object(vic, "%^BOLD%^%^GREEN%^You "+
	"feel the effects of the "+PoisonName+
	" wear off!%^RESET%^");
	return 1;
}

void init()
{
	::init();
	add_action("check_doses", "check");
}

int check_doses(string what)
{
	object tar;
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;
	if(!objectp(TP)) return 0;
	if(!stringp(what)) what = "poison";
	if(!objectp(tar = present(what, ETO))) return 0;
	if(TO != tar) return 0;
	
	tell_object(TP, "%^BOLD%^%^GREEN%^You carefully examine the "+
	"vial and determine that there are "+tar->query_poison_doses()+" "
	"doses of "+tar->query_poison_name()+" left in it.%^RESET%^");	

	return 1;
}	

void base_message(object who, int passed, int myeffect)
{
	object EW;
	string *msg_colors = ({"%^RED%^", "%^BLUE%^", "%^YELLOW%^", "%^GREEN%^",
	"%^ORANGE%^", "%^CYAN%^", "%^MAGENTA%^", "%^WHITE%^", "%^BOLD%^%^BLACK%^"});
	string msgcolor, effectcolor;
	if(!objectp(who)) return;
	msgcolor = msg_colors[random(sizeof(msg_colors))];
	msg_colors -= ({msgcolor});
	effectcolor = msg_colors[random(sizeof(msg_colors))];
	if(random(2)) msgcolor = "%^BOLD%^"+msgcolor;
	if(random(2)) effectcolor = "%^BOLD%^"+effectcolor;
	EW = environment(who);
	switch (passed)
	{
		case 0:
			tell_object(who, msgcolor + "The "+TO->query_poison_name()+
			" eats away at your %^RESET%^"+effectcolor+
			TO->query_effect_type(myeffect)+
			"%^RESET%^"+msgcolor+"!%^RESET%^");
			if(objectp(EW)) 
			{
				if(!who->query_invis()) 
				{
					tell_room(EW, who->QCN+msgcolor+" suddenly looks "+
					"sicker!%^RESET%^", who);
				}
			}
			return;
			break;
		case 1:
			tell_object(who, msgcolor + "You resist the "+
			"effects of the "+TO->query_poison_name()+"!%^RESET%^");
			return;
			break;
	}	
	return;
}