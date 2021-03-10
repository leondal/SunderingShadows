#include <std.h>

inherit "/std/temple";

void create(){
   ::create();
   set_terrain(CEMETERY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("cyric");
   set_smell("default","The air is filled with the smell of candles burning.");
   set_listen("default","You hear the faint sounds of voices...or is that in your head?");
   set_short("Temple of Cyric");
   set_long(
@DESC
%^BOLD%^%^BLACK%^The Temple of Cyric%^RESET%^
You are inside a large temple where the faithful worship Cyric, 
the Dark Sun. Few priests are found here, as they are out in the
world spreading strife and murder to make people fear and revere
Cyric. The few priests who are here eye each other warily, for each
knows that the others are waiting for a mistake to be made and an
opportunity for greater power to become available.
Cyric's charge to his followers is displayed on one of the walls.
DESC
   );
   set_exits(([
      "out":"/d/tharis/barrow/rooms/bd5"
   ]));
   set_items(([
      "priests":"They glance your way often, trying to determine your intentions.",
      "wall":"You see Cyric's charge to his followers on the wall.",
      "charge":"Maybe you should read it.",
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Cyric charges his followers with this message:%^RESET%^
%^CYAN%^
Death to traitors. Death to all who oppose Cyric. Bow down before
the supreme power of Cyric, and yield to him the blood of all who
do not believe in his supreme power. 
Fear and obey those in authority - but if they are weak or given 
to pursuing airy goals of vague goodness, slay them in the name 
of the Dark Sun. Battle against the clergy of all other faiths, 
for they are false prophets and forces who oppose the One True Way. 
Bring death to those who oppose the rightful church of Cyric and 
those who seek to make or keep peace, order, and laws. All rightful 
authority comes from Cyric, and all other authority must be 
subverted. 
Break not into open rebellion, for when hosts march, all faiths 
and gods awaken. It is better by far to fell one foe at a time 
and keep all folk afraid, uneasy, in constant strife - and under 
the spreading tyranny of Cyric.
CHARGE
   );
   if((string)TP->query_diety() == "cyric" || avatarp(TP))
   write(
@EXTRA
============================================================================
%^BOLD%^As a follower of Cyric ...
%^RED%^  allied deities are: %^RESET%^Beshaba
%^RED%^  enemy deities are: %^RESET%^Kelemvor, Mask, Mystra, Tyr, Torm, Bane

%^BOLD%^This is information only followers of Cyric should know.
EXTRA
   );
   return 1;
}
