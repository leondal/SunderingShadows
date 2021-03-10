//	/std/food.c
//	from the Nightmare mudlib
//	inheritable food item
//	created by Descartes of Borg October 1992
// added set_canSave by *Styx* 12/24/03 to allow special ones to save across reboots & fix in set_poison(), last change 12/11/99
//combined into one file - added the ability for spoiling and catching a disease when doing so - Saide, February 2017

#include <std.h>
#include <daemons.h>
#include <move.h>
inherit OBJECT;

int strength, poison, raw, is_drink, healing;
string my_mess, your_mess, short_desc, long_desc, name, alias, alt_id;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_strength(int x);
void set_empty_name(string str);
void clone_empty(object tp);
void set_raw(int x);
int query_raw();
int query_strength();
void set_canSave(int x);
void set_type(string str);
string query_type();

void init()
{
    ::init();
    add_action("eat","eat");
    add_action("drink", "drink");
}

void create()
{
    ::create();
    set_weight(1);
    is_drink = 0;
}

  // use this set (1, defaults 0) to make food/drinks save across reboots *Styx*
  //invalid as of February 2017 - all food/drink items save
void set_canSave(int x) { set("canSave", x); }

int save_me(string file)
{
   //if(!query("canSave"))   return 1;
   ::save_me(file);
}

void set_name(string str)
{
    if(!is_drink)
    {
        set_my_mess("Yum yum yum.\n");
        set_your_mess("eats a "+str+".\n");
    }
    else
    {
        set_my_mess("You drink some "+str+".\n");
        set_your_mess("drinks some "+str+".\n");
    }
    ::set_name(str);
}

void set_empty_name(string str) { set("empty name", str); }

void set_strength(int x)
{
    strength = x;
// also making it so weight is only set if it's 0, *Styx* 12/24/03
// I think this is moot too the way weight is handled currently but I'll leave it just in case I'm wrong.
    if(query_weight() < 1)
       set_weight(1);
}

void set_poison(int x)
{
    poison = x;
	if(x > 0)
	{
		TO->set("PoisonDoses", x);
		TO->set("PoisonType", "any");
	}
/* adding if(poison) check so it _only_ sets strength to 0 if poison is <> 0 so order doesn't matter in special cases (the reason iron rations from Antioch weren't doing any good is they have a poison set to 0 after strenght was set). *Styx* 12/24/03
*/
    if(poison)   strength = 0;
}

void set_my_mess(string str) { my_mess = str; }
void set_your_mess(string str) { your_mess = str; }
void set_raw(int x){
   if(x > 10) x = 10;
   if(x < 0) x = 0;
   raw = x;
}
//added by Circe to go with campfires and cookable meats 7/27/04

void set_type(string str)
{
    set("type", str);
    if (str == "water" || str == "alcoholic" || str == "caffeine" || str == "soft drink" || str == "blood")
        is_drink = 1;

}

string query_type() { return query("type"); }

int query_raw() { return raw; }
int query_strength() { return strength; }
//eat action
int eat(string str)
{
    if(!id(str)) return 0;
    if(is_drink) return 0;
    if(TP->query_current_attacker()) {
        tell_object(TP, "You are too busy to eat anything!\n");
        return 1;
    }
    TP->add_stuffed(strength);
    write(my_mess);
	POISON_D->is_object_poisoned(TO, TP, "eat", 1);
    say(TPQCN+" "+your_mess);
    remove();
    return 1;
}

int drink(string str)
{
    object myDisease;
    string myType;
    if(!id(str)) return 0;
    if(!is_drink) return 0;
   /* Plura 930202 */
    if(ETO != TP)
    {
        tell_object(TP,"You must get it first.\n");
        return 1;
    }
    if(query("type") == "soft drink")
        TP->add_quenched(strength*20);
    else if(query("type") == "caffeine")
    {
        if((int)TP->query_intox() < strength)
        {
            tell_object(TP,"You do not feel the need for that right now.\n");
            return 1;
        }
        TP->add_quenched(strength*10);
        TP->add_intox(-(strength/2)*10);
    }
    else if(query("type") == "alcoholic")
    {
        if(!TP->add_intox(strength*10))
        {
            tell_object(TP,"You are just about to pass out as it is.\n");
            return 1;
        }
    }
    else if(query("type") == "water")
    {
        TP->add_quenched(strength*50);
    }
    else if(query("type") == "blood")
    {
        TP->add_bloodlust(20000);
    }

    myType = query("type");
    TP->add_hp(healing);
    //changed from TP->heal(healing); to stop damage to SS Circe 1/17/05
    write(my_mess);
    say(TPQCN+" "+your_mess, TP);
    POISON_D->is_object_poisoned(TO, TP, "drink", 1);
    //clone_empty(TP); We don't really need these annoying bottles
    remove();
    return 1;
}

void clone_empty(object tp)
{
    object empty;
    string empty_name;

    if(!query("empty name")) set("empty name", "bottle");
    empty_name = query("empty name");
    empty = new("std/Object");
    empty->set_name(empty_name);
    empty->set_short("An empty "+empty_name);
    empty->set_long("A "+empty_name+" which used to hold something.\n");
    empty->set_id( ({ empty_name, query_short(), "empty container" }) );
    empty->set_value(0);
    empty->set_weight(1);  // changed to 1 from 5 while I was fixing up the save thing *Styx*
    empty->set_destroy(1);
    if(empty->move(tp) != MOVE_OK) empty->remove();
}

int is_drink()
{
    if(is_drink) return 1;
    return 0;
}
int is_food()
{
    if(!is_drink) return 1;
    return 0;
}

void set_healing(){
    int x;
    x = roll_dice(2,4)+2;
    healing = x;
}

void set_x_healing() {
  int x;
  x = roll_dice(3,8) + 3;
  healing = x;
}
