#include <std.h>
inherit "std/weapon";
int uses;
void create() {
    ::create();
    set_name("sword of rage");
    set_id(({
        "sword","two handed sword","sword of rage","rage","ragesword"
    }));
    set_short("%^RED%^%^BOLD%^Sword of rage%^RESET%^");
    set_long(
   	"%^RED%^%^BOLD%^The sword of rage glistens as blood seems "
	"to magically seep from it's long blade. As you hold it close to "
	"you, it begins to hum a scream of RAGE causing you to feel "
	"immense anger.%^RESET%^"
    );
    set_weight(75);
    set_size(3);
    set("value",750);
    set_wc(1,10);
    set_large_wc(3,18);
    set_type("two handed");
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    uses = random(50)+50;
}
int extra_hit(object ob) {
    object vic;
    int dam;
    vic = TP->query_current_attacker();
    if (uses < 1) {
        dam = random(2);	    
    } else {  
    message("my_action",
	"%^RED%^%^BOLD%^The %^YELLOW%^sword%^RED%^ screams out "
	"in %^WHITE%^RAGE%^RED%^ as it sinks into yo#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow");
    set_id(({"drow","hunter","drow hunter"}));
    set_short("%^BOLD%^%^BLACK%^Drow hunter");
    set("long",
	"%^BOLD%^%^BLACK%^This is one of the standard male hunter "
	"types of the Drow Elves of Underdark. It's blazing "
	"%^RED%^red%^BLACK%^ eyes are filled with hatred. It's jet "
	"coal skin glistens sickly, but your attention is monstly "
	"drawn to the evil grin on it's lips. Under it's garments "
	"you can make out the taunt muscles of the creature and it's "
	"stance shows that he is ready and more than willing to die "
	"in battle.%^RESET%^"
    );
    set_race("Drow");
    set_gender("male");
    set_hd(5,3);
    set_size(2);
    set_overall_ac(8);
    set_class("fighter");
    set_guild_level("fighter",5);
    set_max_hp(60);
    set_hp(60);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitut#include <std.h>
inherit ROOM;
void create() {
::create();
set_property("light",1);
set_property("indoors",1);
set_short("%^BLUE%^City street%^RESET%^");
set_long(
"%^BLUE%^The city street is made of cobblestones winding through the existing structures around you. The wind blows back your hair as you wander through the city pathways."
" The city road heads north and south here and to the north is what appears to "
"be a large %^BOLD%^%^WHITE%^bone structure%^RESET%^%^BLUE%^.%^RESET%^"
);
set_listen("default",
"The wind howls a strangled cry which causes you to feel nervous about being here."
);
set_smell("default",
"The smell of blood hangs thick in the air."
);
set_items(([
"cobblestone":"There are numerous cobblestones lining the city pathways.",
"cobblestones":"The city pathway is made up of various colored cobblestones which must have been mined in the caverns near here.",
"structure":"%^BOLD%^%^WHITE%^Your not sure but the bone structure appears to be a tower.%^RESET%^",
"street":"The street is made up of cobblestones and winds through the buildings.",
"pathway":"The pathway winds through the city and is made up of cobblestones.",
"buildings":"There are buildings lining the city streets."
]));
set_exits(([
"north":"/d/dagger/drow/rooms/city36.c",
"south":"/d/dagger/drow/rooms/city38.c"
]));
}
