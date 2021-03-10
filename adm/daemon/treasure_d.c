// Random treasure generator
// written by Melnmarn@ShadowGate
// Feb 1995

#include <std.h>
#include <treasure.h>

#define MAGICS  "/d/shadow/obj/magic/"
#define POTIONS "/d/shadow/obj/potion/"
#define ARMORS  "/d/shadow/obj/armor/"
#define ITEMS   "/d/shadow/obj/misc/"
#define WEAPONS "/d/shadow/obj/weapon/"

inherit DAEMON;

void get_magic(int temp, object ob);
void get_items(object ob);
void get_money(object ob);


void get_random_treasure( object ob ){
    int level;
    int type;
    int temp;

	if(!ob) return;
    if(ob->query_property("no random treasure")) return;
	temp = random(100);
	if(temp < 5){
		if(ob->query_level() < 5) return;
           if(ob->query_property("no random items")) return;
		get_magic(temp,ob);
	}
	else if(temp <= 20){
		if(ob->query_level() < 5) return;
           if(ob->query_property("no random items")) return;
		get_items(ob);
	}
	else
           if(ob->query_property("no random money")) return;
		get_money(ob);
	
	return;


}
void get_money(object ob){
    int level;
    int cp,sp,ep,gp,pp;

	level = ob->query_level();
	cp = random(100 * level);
	sp = random(10 * level);
	if(level > 4)
		ep = random(10 * level);
	if(level > 7)
		gp = random(10 * level);
	if(level > 14)
		pp = random(10 * level);
	
	if(cp) ob->add_money("copper",cp);
	if(sp) ob->add_money("silver",sp);
	if(ep) ob->add_money("electrum",ep);
	if(gp) ob->add_money("gold",gp);
	if(pp) ob->add_money("platinum",pp);

	return;
}

void get_items(object ob){
  string *items;
  int test;	
  object obj;

    test = random(100);
    if(test < 33){	
	items = get_dir(ITEMS);
        obj = new(ITEMS + items[random(sizeof(items))]);
        if(objectp(obj))
        	obj->move(ob);
    } else if(test < 66){
	items = get_dir(WEAPONS);
        obj = new(WEAPONS + items[random(sizeof(items))]);
        if(objectp(obj))
        	obj->move(ob);
    } else {
	items = get_dir(ARMORS);
        obj = new(ARMORS + items[random(sizeof(items))]);
        if(objectp(obj))
        	obj->move(ob);
    }


}

void get_magic(int temp, object ob){
  string *items;
  int test,level;	
  object item;

    test = random(100);
    level = ob->query_level();	
    
    if(test < 61){
	items = get_dir(POTIONS);
        item = new(POTIONS + items[random(sizeof(items))]);
        if(objectp(item))
			item->move(ob);
    } else if((test > 60) && (test < 76)){
		items = get_dir(ARMORS);
  		item = new(ARMORS + items[random(sizeof(items))]);
		if(objectp(item)){
			item->set_property("enchantment", random(2));
			item->move(ob);
		}
    } else {
		items = get_dir(WEAPONS);
    	item = new(WEAPONS + items[random(sizeof(items))]);
  		if(objectp(item)){
			item->set_property("enchantment",random(2));
			item->move(ob);
		}
    }


}

