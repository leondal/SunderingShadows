#include <std.h>
inherit ROOM;

private mapping animals;
private mapping price;

void create()
{
	::create();
}

void init()
{
	::init();
	add_action("buy","buy");
	add_action("sell","sell");
}

void set_animal(string *name, string *file)
{
	int i;
	if(!name) return;
	if(!file) return;
	if(sizeof(name) != sizeof(file)) return;
	animals = ([]);
	i = sizeof(name);
	while(i--) animals[name[i]] = file[i];
}

void set_animal_price(string *name, int *prices)
{
	int i;
	if(!name) return;
	if(!prices) return;
	if(sizeof(name) != sizeof(prices)) return;
	i = sizeof(name);
	price = ([]);
	while(i--) {
		if(!animals[name[i]]) continue;
		price[name[i]] = prices[i];
	}
}

int buy(string str)
{
	string *animal;
	object ob, obj;

	obj = present("vendor");
	animal = keys(animals);

	if(!str) return 0;
	if(!obj) {
		notify_fail("There is no one here to sell you anything.\n");
		return 0;
	}
	if(member_array(str, animal) == -1) {
		notify_fail("You can't buy that here.\n");
		return 0;
	}
	if(!TP->query_funds("gold",price[str])) {
		notify_fail("You don't have the gold to pay for it.\n");
		return 0;
	}
	ob = new(animals[str]);
	obj->force_me("emote smiles and goes to get a "+str+".");
	obj->force_me("emote hands the "+str+" over to "+TP->query_cap_name()+".");
	obj->force_me("say That will be "+price[str]+" gold please.");
	obj->force_me("emote holds out "+obj->query_possessive()+" hand.");
	obj->force_me("emote smiles as "+obj->query_subjective()+" recieves the"+
	" money.");

	ob -> set_owner(TP);
	TP->add_pet(ob);
	ob->move(TO);
	TP->use_funds("gold",price[str]);
	return 1;
}

int sell(string str)
{
	string *animal, type;
	object ob, obj;
	int amt, num;

	obj = present("vendor");

	if(!str) return 0;
	if(!obj) {
		notify_fail("There is no one here to buy anything!\n");
		return 0;
	}
	if(!ob = present(str,TO)) {
		obj->force_me("say I'd want to look over it before buying it.");
		return 1;
	}
	animal = keys(animals);
	if(sscanf(str,"%s %d", type,num)) str = type;
	if(member_array(str, animal) == -1) {
		obj->force_me("say Sorry, that isn't the type we sell here.");
		return 1;
	}
	if(TP != (object)ob->query_owner()) {
		obj->force_me("say That is not yours to sell!");
		return 1;
	}
	if(ob->query_current_rider()) {
		obj->force_me("say Can you dismount? I want to inspect the"+
		" "+str+" without anyone on it.");
		return 1;
	}
	amt = price[str];
	amt = to_int(amt/4) + random(to_int(amt/2));
	obj->force_me("emote carefully looks over the "+str+" and nods"+
	" in acceptance.");
	obj->force_me("say I will give you "+amt+" gold for the "+str+".");
	obj->add_money("gold",amt);
	obj->force_me("give "+amt+" gold coins to "+TP->query_cap_name()+"");
	obj->force_me("emote takes the "+str+" to a safe spot.");
	ob->query_owner()->remove_pet(ob);
	ob->remove();
	return 1;
}
