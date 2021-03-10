//Coded by Lujke

#include <std.h>
#define DAY 24000
#include "../tunnel.h"
inherit OBJECT;

int searched;
int query_searched();
void query_searched(int search);

void create() {
    ::create();
    set_name("barbazu corpse");
    set_id( ({"corpse","barbazu corpse"}) );
    set_short("corpse of Barbazu");
    set_weight(100);
    set_long("%^BOLD%^%^RED%^This is the dead body of a male devil.  In"
            +" life it looked something like:\n"
            +"%^RESET%^A %^MAGENTA%^f%^GREEN%^o%^MAGENTA%^ul%^RESET%^"
            +" humanoid creature about 6 feet tall, with a long tail,"
            +" clawed hands and feet, pointed ears and a %^BOLD%^"
            +"%^GREEN%^s%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^ak%^RESET%^"
            +"%^GREEN%^e%^BOLD%^%^GREEN%^y%^RESET%^, disgusting beard."
            +" Its skin looks moist, though %^BOLD%^%^GREEN%^s%^RESET%^"
            +"%^GREEN%^c%^BOLD%^%^GREEN%^aly%^RESET%^ like a %^GREEN%^r"
            +"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^pt%^BOLD%^%^GREEN%^i"
            +"%^RESET%^%^GREEN%^le's%^RESET%^.\n%^GREEN%^The corpse has"
            +" been %^MAGENTA%^hid%^RED%^eo%^MAGENTA%^usly m%^RED%^u"
            +"%^MAGENTA%^til%^RED%^a%^MAGENTA%^ted%^GREEN%^, its entire"
            +" chest cavity cut away and drained of %^BOLD%^%^RED%^bl"
            +"%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^RESET%^%^GREEN%^.");
    searched = 0;
}

void init(){
  ::init();
}

int query_searched(){
  return searched;
}
void set_searched(int search){
  searched = search;
}
