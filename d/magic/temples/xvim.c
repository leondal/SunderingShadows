#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
//   set_temple("xvim");
   set_smell("default","The air is filled dust and debris.");
   set_listen("default","All is deathly quiet here.");
   set_name("Ruined Temple of Iyactu Xvim");
   set_short("Ruined Temple of Iyactu Xvim");
   set_long(
@DESC
%^BOLD%^%^RED%^The Ruined Temple of Iyachtu Xvim%^RESET%^
This massive black stone temple was once the meeting 
of the faithful of Iyactu Xvim.  It now lies in ruins 
with crushed stones littering the floor.  The vaulted 
ceiling has been smashed from above by some unknown 
force, and even the altar has been pounded into dust.
DESC
   );
   set_exits(([
      "out" : "/d/dagger/tonovi/town/temple1.c",
   ]));
   set_items(([
      "altar" : "What little remains of the altar "+
         "is now nothing more than a pile of black "+
         "dust upon the floor.",
      "ceiling" : "The once-beautiful vaulted "+
         "ceiling was crushed when some unknown "+
         "weight was hurled down upon it from above.",
      ({"rubble","ruins"}) : "The temple is filled "+
         "with broken black stone and fine dust.  "+
         "Not a single point has been left intact."
   ]));
}

void init(){
   ::init();
//   add_action("read_charge","read");
}
/*
int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Iyachtu Xvim charges his followers with this message:%^RESET%^
%^CYAN%^
Obey or die in pain and utter destruction. Enslave or slay the weak, 
and be sure they know their suffering is in Xvim's name and by his will. 
Cause pain and obedience in others whenever prudent. Be a cruel, heartless 
tyrant and Xvim shall be pleased. Slay priests of other gods whenever you 
can without being identified. Capture tyrants and wizards and bring them 
to the church - or bring them to Xvim's senior servants so that they can 
be transformed into creatures who will do service to Xvim as guardians. 
Spread fear of Xvim over the lands. Destroy whatever and whoever bars his 
will and see that word of his power spreads but that no one survives to 
describe your deeds in detail except mortals who worship him. Destroy all 
witnesses to secret acts, but leave survivors to tell of Xvim's power when 
spreading casual destruction. There is a delight in destruction - feel 
it and indulge in it.
CHARGE
   );
   if((string)TP->query_diety() == "xvim" || avatarp(TP))
   write(
@EXTRA
============================================================================
%^BOLD%^As a follower of Xvim ...
%^RED%^  allied deities are: %^RESET%^None
%^RED%^  enemy deities are: %^RESET%^All - especially Cyric

%^BOLD%^This is information only followers of Xvim should know.
EXTRA
   );
   return 1;
}
*/