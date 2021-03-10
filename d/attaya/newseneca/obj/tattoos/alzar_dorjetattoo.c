#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
	set_id(({ "medium tattoo", "tattoo", " dorje tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A medium sized tattoo over the right shoulder blade%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The tattoo depicts a small village in a %^BOLD%^%^WHITE%^winter%^BLACK%^ wasteland. Villagers flee a beautiful %^WHITE%^pl%^RESET%^a%^BOLD%^%^WHITE%^ti%^RESET%^n%^BOLD%^%^WHITE%^um%^BLACK%^ haired female half-elf whirling bla%^MAGENTA%^c%^BLACK%^k barded daggers in a %^RED%^frenzy%^BLACK%^. Off to the side a man encased in %^RESET%^silver%^BOLD%^%^BLACK%^ full-plate can be seen chuckling lightly as the woman slowly slays another villager in a %^RED%^m%^WHITE%^u%^RED%^r%^WHITE%^d%^RED%^e%^WHITE%^r%^RED%^o%^WHITE%^u%^RED%^s%^BLACK%^ rage.

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "medium"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
	set_id(({ "tattoo", "winter wasteland tattoo", "winter village tattoo" }));
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
	set_id(({ "growl" }));
	set_short("medium");
	set_short("%^BOLD%^%^BLACK%^A medium sized tattoo covering the right shoulder blade");
	set_long(
@MYLONG

MYLONG
	);
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^The tattoo depicts a small village in a %^BOLD%^%^WHITE%^winter%^BLACK%^ wasteland. Villagers flee a beautiful %^WHITE%^pl%^RESET%^a%^BOLD%^%^WHITE%^ti%^RESET%^n%^BOLD%^%^WHITE%^um%^BLACK%^ haired female half-elf whirling bla%^MAGENTA%^c%^BLACK%^k barded daggers in a %^RED%^frenzy%^BLACK%^. Off to the side a man encased in %^RESET%^silver%^BOLD%^%^BLACK%^ full-plate can be seen chuckling lightly as the woman slowly slays another villager in a %^RED%^m%^WHITE%^u%^RED%^r%^WHITE%^d%^RED%^e%^WHITE%^r%^RED%^o%^WHITE%^u%^RED%^s%^BLACK%^ rage.

MYLONG
	);
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(20000);
	set_id(({ "tattoo" }));
	set_short("medium");
	set_long(
@MYLONG
blash
8*

MYLONG
	);
