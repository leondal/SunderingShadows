// DO NOT USE THIS FILE now, inherit /std/drink and set_canSave(1) to make saveable
// *Styx*  12/24/03

//	/std/food.c
//	from the Nightmare mudlib
//	inheritable food item
//	created by Descartes of Borg October 1992

#include <std.h>

inherit "/std/food.c";

void create() {
   ::create();
   set_weight(1);
   set_canSave(1);
}

/* getting rid of the redundancy *Styx* 12/24/03
inherit OBJECT;

int strength, poison;
string my_mess, your_mess;
string short_desc, long_desc, name, alias, alt_id;

void set_my_mess(string mess);
void set_your_mess(string mess);
void set_strength(int x);
int query_strength();

void init() {
    ::init();
    add_action("eat","eat");
}

void create() {
   ::create();
   set_weight(1);
}

void set_name(string str) {
    set_my_mess("Yum yum yum.\n");
    set_your_mess("eats a "+str+".\n");
    ::set_name(str);
}

void set_strength(int x) {
    strength = x;
set_weight(1);
}

void set_poison(int x) {
    poison = x;
    strength = 0;
  }

void set_my_mess(string str) {
    my_mess = str;
}

void set_your_mess(string str) {
    your_mess = str;
}

int query_strength() {
    return strength;
}

int eat(string str) {
    if(!id(str)) return 0;
    if(this_player()->query_current_attacker()) {
        notify_fail("You are too busy to eat anything!\n");
        return 0;
    }
if(!this_player()->add_stuffed(strength)) {
	write("You are way too full for that!\n");
	return 1;
    }
    write(my_mess);
    this_player()->add_poisoning(poison);
    say(this_player()->query_cap_name()+" "+your_mess);
    remove();
    return 1;
}
*/
