///std/drink.c
//from the Nightmare mudlib
//inheritable drink code
//created by Descartes of Borg October 1992
// added set_canSave by *Styx* 12/24/03 to allow some special ones to save across reboots & cleaned up to use tell_room from say & TPQN, etc., last change 3/29/00

#include <std.h>
#include <daemons.h>
#include <move.h>

inherit OBJECT;

string my_mess, your_mess;
int poison, healing;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_empty_name(string str);
void clone_empty(object tp);
void set_strength(int x);
int query_strength();
void set_type(string str);
string query_type();
void set_canSave(int x);

void init() {
    ::init();
   add_action("drink","drink");
}

void create() {
   ::create();
   set_weight(1);
}

  // use this set (1, defaults 0) to make food/drinks save across reboots *Styx*
void set_canSave(int x) {
   set("canSave", x);
}

int save_me(string file) {
   //if(!query("canSave"))   return 1;
   ::save_me(file);
}

void set_name(string str) {
   set_my_mess("You drink some "+str+".\n");
   set_your_mess("drinks some "+str+".\n");
//   set_weight(210);
// that weight thing looks really wrong but I'm thinking this function never gets used or ???*Styx*
   ::set_name(str);
}

void set_empty_name(string str) { set("empty name", str); }

void set_strength(int x) {
   set("strength", x);
}

void set_poison(int x)
{
    poison = x;
    if(x > 0)
    {
        TO->set("PoisonDoses", x);
        TO->set("PoisonType", "any");
    }
}

void set_healing(){
    int x;
    x = roll_dice(2,4)+2;
    healing = x;
}

void set_x_healing()
{
    int x;
    x = roll_dice(3, 8) + 3;
    healing = x;
}

void set_my_mess(string str)
{
    my_mess = str;
}

void set_your_mess(string str)
{
    your_mess = str;
}

int query_strength()
{
    return query("strength");
}

void set_type(string str)
{
    set("type", str);
}

string query_type()
{
    return query("type");
}

int drink(string str)
{
    object myDisease;
    string myType;
    if (!id(str)) {
        return 0;
    }

    /* Plura 930202 */
    if (ETO != TP) {
        tell_object(TP, "You must get it first.\n");
        return 1;
    }
    if (query("type") == "soft drink") {
        ETO->add_quenched(query("strength") * 20);
    }else if (query("type") == "caffeine") {
        ETO->add_quenched(query("strength") * 10);
        ETO->add_intox(-(query("strength") / 2) * 10);
    }else if (query("type") == "alcoholic") {
        if (!ETO->add_intox(query("strength") * 10)) {
            tell_object(TP, "You are just about to pass out as it is.\n");
            return 1;
        }
    }else if (query("type") == "water") {
        ETO->add_quenched(query("strength") * 50);
    }
    myType = query("type");
    TP->add_hp(healing);
    write(my_mess);
    say(TPQCN + " " + your_mess, TP);
    POISON_D->is_object_poisoned(TO, TP, "drink", 1);
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

int is_drink() { return 1; }
