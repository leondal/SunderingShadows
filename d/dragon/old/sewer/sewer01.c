#include <std.h>

inherit "/std/vault";

void create() {
  ::create();
  set_property("light", -1);
  set_property("indoors", 1);
	set_property("no teleport",1);
/*
  set_open("grate", 0);
  set_locked("grate", 1);
  set_door("grate","/d/dragon/sewer/sewer02","east","obsidian key");
*/
  set_short("Disgusting sewer");
  set_long("%^BOLD%^%^RED%^
These are the disgusting sewers under the city of %^GREEN%^Sanctuary%^RED%^.  They are
filled with many disgusting objects.  The tunnel stretches off toward
the west, and a grate is set in the east wall, near the ceiling.");
  set_items(([
     "sewers":"The disgusting tunnels of waste under Sanctuary.",
     "grate":"The grate is old and rusty.  It is set far up on the easter wall."]));
  set_exits(([
     "up":"/d/dragon/town/storage",
//     //"east":"/d/dragon/sewer/sewer02",
     "west":"/d/dragon/sewer/sewer05"]));
//  set_invis_exits(({"east"}));
//  set_pre_exit_functions(({"east"}),({"go_east"}));
  set_post_exit_functions(({"up"}),({"go_up"}));
}

void look_at_grate() {
  if(query_open("grate")) {
    write("The grate is old and rusty.  It is set far up on the eastern \n"+
          "wall.  The grate is open.");
    } else {
    write("The grate is old and rusty.  It is set far up on the easter\n"+
           "wall and looks as if it will open easily.  It is Closed.\n");
  }
}

/*
int go_east() {
  string TPQR;
  TPQR = this_player()->query_race();
  if(TPQR == "goblin" || TPQR == "gnome" || TPQR == "hobbit" || TPQR == "halfing" || TPQR == "rat") {
    if(query_open("grate")) {
      write("%^RED%^You climb the wall and squeeze through the grate.");
      say ("%^RED%^"+TP->query_cap_name()+" climbs the wall and enters through the grate.");
      return 1;
    }
    write("You climb the wall and bump your head against the grate.");
    say(TP->query_cap_name()+" climbs the wall and bumps "+TP->query_possessive()+" head on the grate.");
    return 0;
  }
  write("You try to squeeze through the small opening and get stuck!\nLuckily you manage to pull yourself out.");
  say(TP->query_cap_name()+" gets stuck in a grate. Luckily manages to pull free.");
  return 0;
}
*/

int go_up() {
  tell_room(environment(this_player()), "%^GREEN%^"+TP->query_cap_name()+" enters the room through the old wooden barrel.");
  return 1;
}
