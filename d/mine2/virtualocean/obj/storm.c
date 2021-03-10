#include <std.h>
inherit MONSTER;

create()
{
  ::create();

   set_name("%^BOLD%^BLUE%^A hurrican");
set_id(({"hurrican"}));
set_short("A Hurrican");
set_long("It's just a little storm!");

}
heart_beat(){
string dir, exit;
int moveme;
::heart_beat();
moveme = random(30);
switch(moveme){
case 0: dir = "north"; break;
case 1: dir = "south"; break;
case 2: dir = "west"; break;
case 3: dir = "east"; break;
case 4: dir = "none"; break;
case 5: dir = "none"; break;
case 6: dir = "none"; break;
case 7: dir = "none"; break;
case 8: dir = "none"; break;
case 9: dir = "none"; break;
case 10: dir = "none"; break;
case 11: dir = "none"; break;
case 12: dir = "none"; break;
case 13: dir = "none"; break;
case 14: dir = "none"; break;
case 15: dir = "none"; break;
case 16: dir = "none"; break;
case 17: dir = "none"; break;
case 18: dir = "none"; break;
case 19: dir = "none"; break;
case 20: dir = "none"; break;
case 21: dir = "none"; break;
case 23: dir = "none"; break;
case 24: dir = "none"; break;
case 25: dir = "none"; break;
case 26: dir = "none"; break;
case 27: dir = "none"; break;
case 28: dir = "none"; break;
case 29: dir = "none"; break;
return 1;
}
exit = environment()->query_exit(dir);
TO->force_me(dir);
}

